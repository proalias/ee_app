#include "cinder/app/AppBasic.h"
#include "cinder/app/AppNative.h"
#include "cinder/Camera.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/params/Params.h"
#include "cinder/Utilities.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "cinder/Timeline.h"

#include "boost/bind.hpp"

#include "Kinect.h"
#include "Background.h"
#include "FontRenderer.h"
#include "Particle.h"
#include "CinderClip.h"
#include "ParticleA.h"
#include "TweenParticle.h"
#include "IconFactory.h"
#include "IconRenderer.h"
//#include "ParticleImageContainer.h"


#include "SceneBase.h"
#include "PassiveScene1.h"
#include "PassiveScene2.h"
#include "PassiveScene3.h"
#include "PassiveScene4.h"

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

	int mGestureMode;
	static const int GESTUREMODE_TEXT_PROMPT_WAVE = 0;
	static const int GESTUREMODE_WAVE = 1;
	static const int GESTUREMODE_SUPERFAST = 2;
	static const int GESTUREMODE_GUITAR = 3;
	int mNextGesture;


	Timer textAnimationTimer;
	//ParticleImageContainer pTextures;

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

	//PassiveScene1 sceneTest;
	
	void onPassiveScene1Complete(void); // TODO - shared interfaces or data types so can do all scenes as one 
	void onPassiveScene2Complete(void); // TODO - shared interfaces or data types so can do all scenes as one 
	void onPassiveScene3Complete(void); // TODO - shared interfaces or data types so can do all scenes as one 
	void onPassiveScene4Complete(void); // TODO - shared interfaces or data types so can do all scenes as one 
	

	
	// TODO also couldnt get the parameter working
	// http://onedayitwillmake.com/blog/2011/08/simple-example-using-boost-signals-with-cinder/

	SceneBase* currentScene;
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


void TextTestApp::onPassiveScene1Complete()
{
	myFont.addLine( "CALL BACK WORKS", 2 );

	//  TODO - check the id of each scene or just increment by index. will sort later. for now first 2 are rotating nicely.
	currentScene = new PassiveScene2();
	currentScene->getSignal()->connect( boost::bind(&TextTestApp::onPassiveScene2Complete, this ));
	currentScene->setup( myFont, iconFactory );

}

void TextTestApp::onPassiveScene2Complete()
{

	//  TODO - check the id of each scene or just increment by index. will sort later. for now first 2 are rotating nicely.
	currentScene = new PassiveScene3();
	currentScene->getSignal()->connect( boost::bind(&TextTestApp::onPassiveScene3Complete, this ));
	currentScene->setup( myFont, iconFactory );

}

void TextTestApp::onPassiveScene3Complete()
{
	myFont.addLine( "CALL BACK WORKS", 2 );

	//  TODO - check the id of each scene or just increment by index. will sort later. for now first 2 are rotating nicely.
	currentScene = new PassiveScene4();
	currentScene->getSignal()->connect( boost::bind(&TextTestApp::onPassiveScene4Complete, this ));
	currentScene->setup( myFont, iconFactory );

}

void TextTestApp::onPassiveScene4Complete()
{

	//  TODO - check the id of each scene or just increment by index. will sort later. for now first 2 are rotating nicely.
	currentScene = new PassiveScene1();
	currentScene->getSignal()->connect( boost::bind(&TextTestApp::onPassiveScene1Complete, this ));
	currentScene->setup( myFont, iconFactory );

}


void TextTestApp::setup()
{
	mbackground.setup();

	particleImg = loadImage(loadAsset( "particle.png" ) ); // TODO - is this being used?
	
	myFont = FontRenderer();
	myFont.addLine( "FONTRENDERER CREATED", 2 );


	/* - Leave this for now, textures can be added to the particle later.
	//load particle textures
	pTextures.init();
	gl::Texture texture1 = loadImage(loadAsset( "ParticleFullON.png") );
	pTextures.addTexture(texture1);
	gl::Texture texture2 = loadImage(loadAsset( "ParticlePatial01.png") );
	pTextures.addTexture(texture2);
	gl::Texture texture3 = loadImage(loadAsset( "ParticlePatial02.png") );
	pTextures.addTexture(texture3);
	gl::Texture texture4 = loadImage(loadAsset( "ParticlePatial03.png") );
	pTextures.addTexture(texture4);
	gl::Texture texture5 = loadImage(loadAsset( "ParticlePatial04.png") );
	pTextures.addTexture(texture5);
	gl::Texture texture6 = loadImage(loadAsset( "ParticlePatial05.png") );
	pTextures.addTexture(texture6);
	*/


	// SCENE INITIALISER. FOR TESTING PUT ANY SCENE NUMBER HERE
	currentScene = new PassiveScene1();
	currentScene->getSignal()->connect( boost::bind(&TextTestApp::onPassiveScene1Complete, this ));
	currentScene->setup( myFont , iconFactory);

	iconFactory.init();
	
	Timer textAnimationTimer = Timer();
	textAnimationTimer.start();

	for (int i=0; i<20; i++){
		CinderClip cinderClip = CinderClip();
		repelClips.push_back(cinderClip);
	}

	mbackground.setRepelClips( repelClips );

	for( int i=0; i<100; i++ )
	{
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
	currentScene->update(timeline());

	mbackground.update();

	updateSkeleton();
	
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update();
	}

	
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

	myFont.draw();

	currentScene->draw();

	gl::color( Color( 1, 1, 1 ) );

	// TODO - may be passing foreground particles into scenes. but still probs drawn here
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		//gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
		
		Rectf rect = Rectf(p->x,p->y,p->x + p->width, p->y + p->width);
		gl::draw(particleImg,rect);
	}


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