
#include "cinder/app/AppBasic.h"
#include "cinder/app/AppNative.h"
#include "cinder/Camera.h"

#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/params/Params.h"
#include "cinder/Utilities.h"
#include "Kinect.h"



#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/app/MouseEvent.h"
#include "cinder/Rand.h"
#include "cinder/Timeline.h"
//#include "gl.h"
 
//#include "Button.h"
//#include "boost/bind.hpp"


#include "boost/bind.hpp"

#include "Background.h"
#include "FontRenderer.h"
#include "Particle.h"
#include "CinderClip.h"
#include "ParticleA.h"
#include "TweenParticle.h"
#include "IconFactory.h"
#include "IconRenderer.h"

#include "PassiveScene1.h"
//#include "PassiveScene1.h"
//#include "PassiveScene1.h"
#include "PassiveScene5.h"


#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace KinectSdk;
using std::list;

static const bool PREMULT = false;

class TextTestApp : public AppNative {
 public:

	void prepareSettings( Settings *settings ); // TODO - whats this wheres it get called?

	void setup();
	void setupSkeletonTracker();
	void updateAnimatingParticles();

	void update();
	void updateSkeleton();

	void draw();
	void drawSkeleton();
	void drawParticle(float tx, float ty, float scale);
	void toggleAnimation();

	gl::Texture particleImg;
	gl::Texture mSimpleTexture;

	FontRenderer myFont;
 
	std::list<ParticleA>	mParticles;

	std::vector<CinderClip> repelClips;

	bool animationInProgress;
	std::vector<TweenParticle> pointsContainer;
	std::vector<TweenParticle> animatingParticles;
	
	ci::Vec2f getRandomPointOffscreen();

	SVGtoParticleParser svgParser;
	
	IconFactory iconFactory;
	std::vector<IconRenderer> iconRenderers;
	
	//mode definitions


	PassiveScene5 passiveScene5;

	int mGestureMode;
	static const int GESTUREMODE_TEXT_PROMPT_WAVE = 0;
	static const int GESTUREMODE_WAVE = 1;
	static const int GESTUREMODE_SUPERFAST = 2;
	static const int GESTUREMODE_GUITAR = 3;
	int mNextGesture;


	Timer textAnimationTimer;


private:
	// Kinect
	uint32_t							mCallbackId;
	KinectSdk::KinectRef				mKinect;
	std::vector<KinectSdk::Skeleton>	mSkeletons;
	void								onSkeletonData( std::vector<KinectSdk::Skeleton> skeletons, 
		const KinectSdk::DeviceOptions &deviceOptions );

	// Camera
	ci::CameraPersp						mCamera;

	// Save screenshot
	void								screenShot();


	bool trackingRightHand;
	bool tweeningPointsIn;

protected:
	Background mbackground;

	PassiveScene1 sceneTest;
	void onPassiveSceneComplete(void); // TODO - shared interfaces or data types so can do all scenes as one 
	// TODO also couldnt get the parameter working
	// http://onedayitwillmake.com/blog/2011/08/simple-example-using-boost-signals-with-cinder/

};



void TextTestApp::prepareSettings( Settings *settings )
{
	// TODO - turn on for the live app
	//setAlwaysOnTop();
	//setBorderless();
	//setFullScreen(true);

	settings->setWindowSize( 1280, 800 );
	//settings->setWindowSize( 1280, 800 );
	//settings->setFrameRate( 30.0f );
	//settings->setFullScreen( true );
}



void TextTestApp::onPassiveSceneComplete()
{
	std::cout << "PassiveScene1 instance is talking to me!" << std::endl;
	myFont.addLine( "CALL BACK WORKS", 2 );
}



void TextTestApp::setup()
{
	mbackground.setup();// = Background();
	particleImg = loadImage(loadAsset( "particle.png" ) );
	
	// TODO - might be used for rubrik font later.. so leave here

	// Create a custom font by loading it from a resource
	//	Font customFont( Font( loadResource( RES_CUSTOM_FONT ), 72 ) );
	//console() << "This font is called " << customFont.getFullName() << std::endl;
	//TextLayout simple;
	//simple.setFont( customFont );
	//simple.setColor( Color( 1, 1, 1 ) );
	//simple.setColor( ColorConstants::TEAL );
	//simple.addLine( "4GEE IS HERE" );
	//simple.addLine( "SIMPLE TEXT TEST 1" );
	//mSimpleTexture = gl::Texture( simple.render( true, PREMULT ) );

	myFont = FontRenderer();
	myFont.addLine( "EE APP START TEST TEXT", 2 );

	
	iconFactory.init();
	
	// Get the signal instance
	// Use boost::bind, to bind our class's function, to our (this) specific instnace
	// _1 is a typedef for boost::arg - So we're creating a spot for the first argument in the function
	sceneTest.getSignal()->connect( boost::bind(&TextTestApp::onPassiveSceneComplete, this ));
	sceneTest.setup( myFont );

	Timer textAnimationTimer = Timer();
	textAnimationTimer.start();


	passiveScene5.getSignal()->connect( boost::bind(&TextTestApp::onPassiveSceneComplete, this ));
	passiveScene5.setup( myFont, timeline(), iconFactory);



	for (int i=0; i<20; i++){
		CinderClip cinderClip = CinderClip();
		repelClips.push_back(cinderClip);
	}

	mbackground.setRepelClips( repelClips );

	// myFont.addLine( "some test", 10 ); TODO - addline increments y position by previous text height
	// TODO - text needs to centre align
	for( int i=0; i<100; i++ )
	{
			//float x = //character[i][0]+xPosition;
			//float y = //character[i][1]+yPosition;

		ParticleA particle = ParticleA();
		particle.init();

		particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );

		particle.width = randFloat(3,10);
	
		particle.x=randFloat(getWindowWidth());
		particle.y=randFloat(getWindowHeight());

		//particle.setBounce(-1);
		particle.setMaxSpeed(5);

		//particle.setEdgeBehavior("wrap");

		particle.setWander(3);
		particle.setGrav(0);
		
		for (int i=0; i<20; i++){
			particle.addRepelClip( repelClips[i],500,200 );
		}
		
		mParticles.push_back( particle );
	}

	setupSkeletonTracker();

	tweeningPointsIn = false;

	animationInProgress = false;


	std::vector<TweenParticle> airGuitarPoints = iconFactory.getPointsForIcon(IconFactory::AIR_GUITAR);
	IconRenderer airGuitarRenderer = IconRenderer(airGuitarPoints);
	airGuitarRenderer.xPos = 400;
	airGuitarRenderer.yPos = 300;
	airGuitarRenderer.xScale = airGuitarRenderer.yScale = 0.5;

	iconRenderers.push_back(airGuitarRenderer);


	toggleAnimation();
}


void TextTestApp::toggleAnimation(){
	if (!animationInProgress){
		
		animationInProgress = true;
		int reassigned = 0;
		
		if (!trackingRightHand){

			trackingRightHand = true;//!trackingRightHand;
			for (int i=0; i <pointsContainer.size();i++){
				reassigned +=1;
				float destx = pointsContainer[i].xpos;
				float desty = pointsContainer[i].ypos;

				ci::Vec2f pt = getRandomPointOffscreen();
				

				//p.animateTo(ci::Vec2f(destx,desty),ci::Vec2f(p.xpos,p.ypos),3.0,getElapsedSeconds());  	
				if ( i >= animatingParticles.size() ){

					//timeline().apply( &p.xpos, xpos, destx, 3.0f, EaseOutBack(0.3) );
					//timeline().apply( &p.ypos, ypos, desty, 3.0f, EaseOutBack(0.3) );
					TweenParticle p = TweenParticle(pt.x,pt.y, pointsContainer[i].rad);
					p.color.r = pointsContainer[i].color.r;
					p.color.g = pointsContainer[i].color.g;
					p.color.b = pointsContainer[i].color.b;
					animatingParticles.push_back(p);
					animatingParticles.back().animateTo(ci::Vec2f(destx,desty),pt,3.0,getElapsedSeconds(),p.rad);
				}else{
					//timeline().apply( &animatingParticles[i].xpos, xpos, destx, 3.0f, EaseOutBack(0.3) );
					//timeline().apply( &animatingParticles[i].ypos, xpos, desty, 3.0f, EaseOutBack(0.3) );
					animatingParticles[i].color = pointsContainer[i].color;
					animatingParticles[i].animateTo(ci::Vec2f(destx,desty),pt,3.0,getElapsedSeconds(),pointsContainer[i].rad);
					//animatingParticles[i].ypos = p.ypos;
				}
			}

			//clear remaining particles

			int remaining = animatingParticles.size() - reassigned;
			for (int i = 0; i< remaining; i++){
				animatingParticles[i+reassigned].animateTo(getRandomPointOffscreen(),3.0,getElapsedSeconds(), 0.0);
			}

		}else{

			trackingRightHand = false;

			for (int i=0; i <pointsContainer.size();i++){

				
				float xpos = pointsContainer[i].xpos;
				float ypos = pointsContainer[i].ypos;



				if ( i >= animatingParticles.size() ){		
					ci::Vec2f pt = getRandomPointOffscreen();
				
					TweenParticle p = TweenParticle(xpos,ypos, pointsContainer[i].rad);
					p.color.r = pointsContainer[i].color.r;
					p.color.g = pointsContainer[i].color.g;
					p.color.b = pointsContainer[i].color.b;
					animatingParticles.push_back(p);
					animatingParticles.back().animateTo(pt,3.0,getElapsedSeconds(),p.rad);
				}else{
					animatingParticles[i].color = pointsContainer[i].color;
					animatingParticles[i].animateTo(ci::Vec2f(animatingParticles[i].xpos,animatingParticles[i].ypos),3.0,getElapsedSeconds(),pointsContainer[i].rad);
				}
			}
			
			//clear remaining particles

			int remaining = animatingParticles.size() - reassigned;
			for (int i = 0; i< remaining; i++){
				animatingParticles[i+reassigned].animateTo(getRandomPointOffscreen(),3.0,getElapsedSeconds(), 0.0);
			}

			mGestureMode = mNextGesture;
		}
	}
}

ci::Vec2f TextTestApp::getRandomPointOffscreen(){
	float x = randFloat(-2000,2000);
	float y = randFloat(-2000,2000);

	if (x > 0 && x < getWindowHeight()){
		x+=getWindowHeight();
	}

	if (y > 0 && y < getWindowWidth()){
		y+=getWindowWidth();
	}

	return ci::Vec2f(x,y);
}



void TextTestApp::setupSkeletonTracker(){
	
	// Start Kinect
	mKinect = Kinect::create();
	mKinect->start( DeviceOptions().enableDepth( false ).enableVideo( false ) );
	mKinect->removeBackground();

	// Set the skeleton smoothing to remove jitters. Better smoothing means
	// less jitters, but a slower response time.
	mKinect->setTransform( Kinect::TRANSFORM_SMOOTH );

	// Add callback to receive skeleton data
	mCallbackId = mKinect->addSkeletonTrackingCallback( &TextTestApp::onSkeletonData, this );

	// Set up camera
	mCamera.lookAt( Vec3f( 0.0f, 0.0f, 2.0f ), Vec3f::zero() );
	mCamera.setPerspective( 45.0f, getWindowAspectRatio(), 0.01f, 1000.0f );
}


void TextTestApp::update()
{

	sceneTest.update();
	passiveScene5.update();


	mbackground.update();

	updateSkeleton();
	
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update();
	}

	if (textAnimationTimer.isStopped()){
		textAnimationTimer.start();
	}


	
	//trigger the text animation
	if (textAnimationTimer.getSeconds() > 10 && textAnimationTimer.getSeconds() < 11){
		//myFont.animateOut();
		//iconRenderers.back().tweenTo(timeline(),1000.0,1000.0,10.0);
		passiveScene5.animateIn(timeline());
	}


		//trigger the text animation
	if (textAnimationTimer.getSeconds() > 20 && textAnimationTimer.getSeconds() < 22){
		//myFont.animateOut();
		//iconRenderers.back().tweenTo(timeline(),1000.0,1000.0,10.0);
		passiveScene5.animateOut(timeline());
		textAnimationTimer = Timer();
		textAnimationTimer.start();
	}
	
	

	//iconRenderers.back().xPos = iconRenderers.back().xPos + 1;
	//iconRenderers.back().xScale = iconRenderers.back().xScale + 0.1;
	//iconRenderers.back().yScale = iconRenderers.back().yScale + 0.1;


	double time = getElapsedSeconds();
	gl::color(1.0,1.0,1.0);
	
	for (int i=0;i<animatingParticles.size();i++){  
		if (animatingParticles[i].moving){
			animatingParticles[i].update(time);
			animationInProgress = true;
		}
		drawParticle(animatingParticles[i].xpos ,animatingParticles[i].ypos ,animatingParticles[i].rad * 2);
	}

	updateAnimatingParticles();

}

void TextTestApp::updateAnimatingParticles(){
	double time = getElapsedSeconds();
	
	for (int i=0;i<animatingParticles.size();i++){  
		if (animatingParticles[i].moving){
			animatingParticles[i].update(time);
			animationInProgress = true;
		}
		//gl::color(animatingParticles[i].color);
		drawParticle(animatingParticles[i].xpos,animatingParticles[i].ypos,animatingParticles[i].rad);
		//drawParticle(animatingParticles[i].xpos ,animatingParticles[i].ypos ,animatingParticles[i].rad * 2);
	}
}


void TextTestApp::updateSkeleton()
{

	if ( mKinect->isCapturing() ) {
		mKinect->update();
	} else {
		// If Kinect initialization failed, try again every 90 frames
		if ( getElapsedFrames() % 90 == 0 ) {
			mKinect->start();
		}
	}

}


void TextTestApp::draw()
{
	mbackground.draw();


	drawSkeleton();
	gl::enableAlphaBlending();

	gl::color( Color::white() );
	//gl::draw( mSimpleTexture, Vec2f( 10, getWindowHeight() - mSimpleTexture.getHeight() - 5 ) );
	//gl::draw( mSimpleTexture, Vec2f( 10, 10 ) );

	//TODO - dont think i have to keep calling this.
	// tell the font to draw?
	myFont.draw();

	gl::color( Color( 1, 1, 1 ) );

	
	passiveScene5.draw();

	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
	//	p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
	//	p->draw();

		gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );

	}

	/*
	for( vector<IconRenderer>::iterator p = iconRenderers.begin(); p != iconRenderers.end(); ++p ){
		p->draw();
	}*/


}


void TextTestApp::drawSkeleton(){
	// Clear window

	// We're capturing
	if ( mKinect->isCapturing() ) {

		// Set up 3D view
		//gl::pushMatrices();
		//gl::setMatrices( mCamera );

		// Iterate through skeletons
		uint32_t i = 0;
		for ( vector<Skeleton>::const_iterator skeletonIt = mSkeletons.cbegin(); skeletonIt != mSkeletons.cend(); ++skeletonIt, i++ ) {

			// Set color
			Colorf color = mKinect->getUserColor( i );
			int boneIndex = 0;
			// Iterate through joints
			for ( Skeleton::const_iterator boneIt = skeletonIt->cbegin(); boneIt != skeletonIt->cend(); ++boneIt, boneIndex++ ) {

				// Set user color
				gl::color( color );

				// Get position and rotation
				const Bone& bone	= boneIt->second;
				Vec3f position		= bone.getPosition();
				
				Matrix44f transform	= bone.getAbsoluteRotationMatrix();
				Vec3f direction		= transform.transformPoint( position ).normalized();
				direction			*= 0.05f;
				position.z			*= -1.0f;


				Vec3f destination		= skeletonIt->at( bone.getStartJoint() ).getPosition();
				Vec2f positionScreen	= Vec2f( mKinect->getSkeletonVideoPos( position ) );
				Vec2f destinationScreen	= Vec2f( mKinect->getSkeletonVideoPos( destination ) );

				repelClips[boneIndex].x = destinationScreen.x*2;
				repelClips[boneIndex].y = destinationScreen.y*2;

				gl::color(Color(1.0,0.0,0.0));
				gl::drawSolidCircle( Vec2f(destinationScreen.x*2, destinationScreen.y*2), 20);

				/*
				// Draw generic bone stuff here
				glLineWidth( 2.0f );
				JointName startJoint = bone.getStartJoint();
				if ( skeletonIt->find( startJoint ) != skeletonIt->end() ) {
					Vec3f destination	= skeletonIt->find( startJoint )->second.getPosition();
					destination.z		*= -1.0f;
					gl::drawLine( position, destination );
				}
				*/


				//draw bone specific stuff here
				switch(boneIt->first){
						case NUI_SKELETON_POSITION_HIP_CENTER:
							//draw hip center
				 			break;
					 
						case NUI_SKELETON_POSITION_SPINE:
							//draw spine
				 			break;
						case NUI_SKELETON_POSITION_SHOULDER_CENTER:
							//draw shoulder center
				 			break;
						case NUI_SKELETON_POSITION_HEAD:
							//draw head
				 			break;
						case NUI_SKELETON_POSITION_SHOULDER_LEFT:
							//draw left shoulder
							break;				 
						case NUI_SKELETON_POSITION_ELBOW_LEFT:
							//draw left elbow
							break;				 
						case NUI_SKELETON_POSITION_WRIST_LEFT:
							//draw left wrist
							break;				 
						case NUI_SKELETON_POSITION_HAND_LEFT:
							//draw left hand
							break;				 
						case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
							//draw right shoulder
							break;				 
						case NUI_SKELETON_POSITION_ELBOW_RIGHT:
							//draw right elbow
							break;				 
						case NUI_SKELETON_POSITION_WRIST_RIGHT:
							//draw right wrist
							break;				 
						case NUI_SKELETON_POSITION_HAND_RIGHT:
							//draw right hand
							break;				 
						case NUI_SKELETON_POSITION_HIP_LEFT:
							//draw left hip
							break;
						case NUI_SKELETON_POSITION_KNEE_LEFT:
							//draw left knee
							break;				 
						case NUI_SKELETON_POSITION_ANKLE_LEFT:
							//draw left ankle
							break;
						case NUI_SKELETON_POSITION_FOOT_LEFT:
							//draw left foot
							break;
						case NUI_SKELETON_POSITION_HIP_RIGHT:
							//draw right hip
							break;
						case NUI_SKELETON_POSITION_KNEE_RIGHT:
							//draw right knee
							break;
						case NUI_SKELETON_POSITION_ANKLE_RIGHT:
							//draw right ankle
							break;
						case NUI_SKELETON_POSITION_FOOT_RIGHT:
							//draw right foot
							break;
				}


				

				// Draw joint
				//gl::drawSphere( position, 0.025f, 16 );

				// Draw joint orientation
				//glLineWidth( 0.5f );
				gl::color( ColorAf::white() );
				//gl::drawVector( position, position + direction, 0.05f, 0.01f );

			}

		}
		
		//gl::popMatrices();
	}
}




// TODO - is this being used anymore?
void TextTestApp::drawParticle(float tx, float ty, float scale){
	Rectf rect = Rectf(tx,ty,tx+scale, ty+scale);
	gl::draw(particleImg,rect);
}



// Receives skeleton data
void TextTestApp::onSkeletonData( vector<Skeleton> skeletons, const DeviceOptions &deviceOptions )
{
	mSkeletons = skeletons;
}


// This line tells Cinder to actually create the application
CINDER_APP_NATIVE( TextTestApp, RendererGl )