#include "cinder/app/AppBasic.h"
#include "cinder/app/AppNative.h"
#include "cinder/Camera.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/params/Params.h"
#include "cinder/Utilities.h"
#include "cinder/gl/gl.h"
#include "cinder/Vector.h"
#include "cinder/Rand.h"
#include "cinder/Timeline.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Texture.h"

#include "boost/lambda/bind.hpp"

#include "Kinect.h"
#include "Background.h"
#include "FontRenderer.h"
#include "Particle.h"
#include "CinderClip.h"
#include "TextureGlobals.h"
#include "ParticleA.h"
#include "TweenParticle.h"
#include "IconFactory.h"
#include "IconRenderer.h"
#include "ForegroundParticles.h"
#include "SceneBase.h"
#include "PassiveScene1.h"
#include "PassiveScene2.h"
#include "PassiveScene3.h"
#include "PassiveScene4.h"
#include "ShopConfig.h"
//#include "ActiveScene1.h"
#include "OutlineParams.h"

#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/Texture.h"


#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace KinectSdk;
using std::list;

using boost::lambda::_1;
using boost::lambda::bind; 


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
	void toggleAnimation();

	gl::Texture particleImg;
	gl::Texture mSimpleTexture;

	Vec2f getMidPoint(Vec2f p0, Vec2f p1);

	FontRenderer myFont;
 
	ForegroundParticles fgParticles; // ones flying around the screen

	std::vector<CinderClip> repelClips;


	bool flipScreen;
	

	bool hideBackground;


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


	// TODO - for blur effect. if dont work remove these later.
	void render();
	void drawStrokedRect( const Rectf &rect );
	
	Timer textAnimationTimer;
	//ParticleImageContainer pTextures;

	
	std::vector<TweenParticle> userParticles;

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

	void onPassiveSceneComplete( SceneBase* sceneInstance  );
	SceneBase* currentScene;

	//
	gl::Fbo			mFboScene;
	gl::Fbo			mFboBlur1;
	gl::Fbo			mFboBlur2;
	gl::GlslProg	mShaderBlur;
	gl::GlslProg	mShaderPhong;
	
	gl::Texture		mTexture;
	Matrix44f		mTransform;


};

void TextTestApp::prepareSettings( Settings *settings )
{

	bool isDeployed = flipScreen = false;

	if (isDeployed == true){
		::ShowCursor(false);
		flipScreen = true;
		settings->setAlwaysOnTop(true);
		settings->setBorderless(true);
		settings->setFullScreen( true );
	}

	settings->setWindowSize( 1280, 800 );
	settings->setFrameRate( 30.0f );

	
}


void TextTestApp::onPassiveSceneComplete( SceneBase* sceneInstance )
{
	int sceneId = sceneInstance->getId();
	switch(sceneId){
	case 1:
		currentScene = new PassiveScene2();
		currentScene->getSignal()->connect( boost::lambda::bind(&TextTestApp::onPassiveSceneComplete, this, ::_1 ));
		currentScene->setup( myFont, iconFactory, fgParticles, mbackground.gridLayer1 );
		break;
	case 2:
		currentScene = new PassiveScene3();
		currentScene->getSignal()->connect( boost::lambda::bind(&TextTestApp::onPassiveSceneComplete, this, ::_1 ));
		currentScene->setup( myFont, iconFactory, fgParticles, mbackground.gridLayer1 );
		break;
	case 3:
		currentScene = new PassiveScene4();
		currentScene->getSignal()->connect( boost::lambda::bind(&TextTestApp::onPassiveSceneComplete, this, ::_1 ));
		currentScene->setup( myFont, iconFactory, fgParticles, mbackground.gridLayer1 );
		break;
	case 4:
		currentScene = new PassiveScene1();
		currentScene->getSignal()->connect( boost::lambda::bind(&TextTestApp::onPassiveSceneComplete, this, ::_1 ));
		currentScene->setup( myFont, iconFactory, fgParticles, mbackground.gridLayer1 );
		break;
	}

}


void TextTestApp::setup()
{
	hideBackground = false;
	// SET UP BLUR STUFF
	// setup our scene Fbo
	mFboScene = gl::Fbo( getWindowWidth(), getWindowHeight() );

	// setup our blur Fbo's, smaller ones will generate a bigger blur
	mFboBlur1 = gl::Fbo(getWindowWidth()/8, getWindowHeight()/8);
	mFboBlur2 = gl::Fbo(getWindowWidth()/8, getWindowHeight()/8);

	OutlineParams::getInstance()->init();

	// load and compile the shaders
	try { 
		mShaderBlur = gl::GlslProg( 
			loadFile("../data/blur_vert.glsl"),
			loadFile("../data/blur_frag.glsl")); 
	} catch(...) {
		console() << "Can't load/compile blur shader" << endl;
		quit();
	}

	try { 
		mShaderPhong = gl::GlslProg( 
			loadFile("../data/phong_vert.glsl"),
			loadFile("../data/phong_frag.glsl")); 
	} catch(...) {
		console() << "Can't load/compile phong shader" << endl;
		quit();
	}


	mTransform.setToIdentity();

	gl::Texture::Format format;
	format.enableMipmapping(true);

	mCamera.setEyePoint( Vec3f(2.5f, 5.0f, 5.0f) );
	mCamera.setCenterOfInterestPoint( Vec3f(0.0f, 2.0f, 0.0f) );
	mCamera.setPerspective( 60.0f, getWindowAspectRatio(), 1.0f, 1000.0f );

	for (int i=0; i<40; i++)
	{
		CinderClip cinderClip = CinderClip();
		cinderClip.x = -200;
		cinderClip.y = -200;
		repelClips.push_back(cinderClip);

		////
		TweenParticle userParticle = TweenParticle(cinderClip.x, cinderClip.y,10,true);
		userParticles.push_back(userParticle);

	}

	mbackground.setup();
	mbackground.setRepelClips( repelClips ); // I KNOW THEY ON SCREEN


	//load store config
	cinder::XmlTree configXml( ci::app::loadAsset( "shopconfig.xml" ) );
	ShopConfig::getInstance()->parseConfig(configXml);


	gl::Texture particleTexture0 = loadImage(loadAsset( "ParticleFullON.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture0,0);

	gl::Texture particleTexture1 = loadImage(loadAsset( "ParticlePatial01.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture1,1);

	gl::Texture particleTexture2 = loadImage(loadAsset( "ParticlePatial02.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture2,2);

	gl::Texture particleTexture3 = loadImage(loadAsset( "ParticlePatial03.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture3,3);

	gl::Texture particleTexture4 = loadImage(loadAsset( "ParticlePatial04.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture4,4);

	gl::Texture particleTexture5 = loadImage(loadAsset( "ParticlePatial05.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture5,5);

	gl::Texture particleTexture6 = loadImage(loadAsset( "background-particle.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture6,6);

	gl::Texture particleTexture7 = loadImage(loadAsset( "ParticleFullONYellow.png" ) ); 
	TextureGlobals::getInstance()->setParticleTexture(particleTexture6,7);


	myFont = FontRenderer();
	//myFont.addLine( "FONTRENDERER CREATED", 2 );

	fgParticles.setup( 100 );
	//fgParticles.init();
	fgParticles.setRepelClips(repelClips);

	fgParticles.setRepelClips( repelClips );

	// TO VIEW ACTIVE SCENE
	//currentScene = new ActiveScene1();
	//currentScene->getSignal()->connect( boost::lambda::bind(&TextTestApp::onPassiveSceneComplete, this, ::_1 ));
	//currentScene->setup( myFont, iconFactory, fgParticles );


	// SCENE INITIALISER. FOR TESTING PUT ANY SCENE NUMBER HERE
	currentScene = new PassiveScene1();
	currentScene->getSignal()->connect( boost::lambda::bind(&TextTestApp::onPassiveSceneComplete, this, ::_1 ));
	currentScene->setup( myFont, iconFactory, fgParticles, mbackground.gridLayer1 );

	iconFactory.init();
	
	//Timer textAnimationTimer = Timer();
	//textAnimationTimer.start();
	
	setupSkeletonTracker();
}




void TextTestApp::setupSkeletonTracker(){
	
	// Start Kinect
	mKinect = Kinect::create();
	mKinect->start( DeviceOptions().enableVideo( false ).setDepthResolution( ImageResolution::NUI_IMAGE_RESOLUTION_80x60 ) );
	
	mKinect->removeBackground();
	// Add callbacks

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

	fgParticles.update();


	if ( mKinect->isCapturing() ) {
		mKinect->update();
		updateSkeleton();
	}else {
		// If Kinect initialization failed, try again every 90 frames
		if ( getElapsedFrames() % 90 == 0 ) {
			mKinect->start();
		}
	}

	double time = getElapsedSeconds();
	gl::color(1.0,1.0,1.0);
}



void TextTestApp::updateSkeleton()
{
	
}


void TextTestApp::draw()
{
	// this pair of lines is the standard way to clear the screen in OpenGL
	glClearColor( 0,0,0,1 );
	glClear( GL_COLOR_BUFFER_BIT );
	
	if (flipScreen==true){
		gl::pushMatrices();
		
		gl::scale( Vec3f(-1, 1, 1) );
		gl::translate( Vec2f(-ci::app::getWindowWidth(), 0 ) );
		gl::translate( Vec3f(-1, 1, 1) );
	}

	
	drawSkeleton();
	mbackground.draw();

	// FONT NOW GETS RENDERED AFTER SCENE SO WE CAN OVERRIDE DRAW OPERATION IF REQUIRED
	currentScene->draw();
	myFont.draw();
	
	
	
	

	//fgParticles.draw();

	// kill this all and refresh
	//gl::disableAlphaBlending();
	//gl::enableAlphaBlending();
	//
	
	//gl::enableAdditiveBlending();

	//gl::color( ColorA( 1, 1, 1, 1 ) );

	// store our viewport, so we can restore it later
	Area viewport = gl::getViewport();

	// render a simple scene into mFboScene
	gl::setViewport( mFboScene.getBounds() );
	mFboScene.bindFramebuffer();
		gl::pushMatrices();
		gl::setMatricesWindow( viewport.getWidth(), viewport.getHeight(), false );
			gl::clear( ColorA( 0,0,0,1 ));
			fgParticles.draw();
			//gl::drawSolidCircle( Vec2f(50,50), 20 );
			//gl::draw( mFboScene.getTexture() );//TODO - screenshot?
		gl::popMatrices();
	mFboScene.unbindFramebuffer();

	// bind the blur shader
	mShaderBlur.bind();
	mShaderBlur.uniform("tex0", 0); // use texture unit 0
 
	// tell the shader to blur horizontally and the size of 1 pixel
	mShaderBlur.uniform("sampleOffset", Vec2f(1.0f/mFboBlur1.getWidth(), 0.0f));

	// copy a horizontally blurred version of our scene into the first blur Fbo
	
	gl::setViewport( mFboBlur1.getBounds() );
	mFboBlur1.bindFramebuffer();
		mFboScene.bindTexture(0);
		gl::pushMatrices();
			gl::setMatricesWindow( viewport.getWidth(), viewport.getHeight(), false );
			gl::clear( Color::black() );
			gl::drawSolidRect( mFboBlur1.getBounds() );
		gl::popMatrices();
		mFboScene.unbindTexture();
	mFboBlur1.unbindFramebuffer();

 
	// tell the shader to blur vertically and the size of 1 pixel
	mShaderBlur.uniform("sampleOffset", Vec2f(0.0f, 1.0f/mFboBlur2.getHeight()));

	// copy a vertically blurred version of our blurred scene into the second blur Fbo
	gl::setViewport( mFboBlur2.getBounds() );
	mFboBlur2.bindFramebuffer();
		mFboBlur1.bindTexture(0);
		gl::pushMatrices();
			gl::setMatricesWindow( viewport.getWidth(), viewport.getHeight(), false );
			gl::clear( Color::black() );
			gl::drawSolidRect( mFboBlur2.getBounds() );
		gl::popMatrices();
		mFboBlur1.unbindTexture();
	mFboBlur2.unbindFramebuffer();

	// unbind the shader
	mShaderBlur.unbind();

	// restore the viewport
	gl::setViewport( viewport );
	// because the Fbo's have their origin in the LOWER-left corner,
	// flip the Y-axis before drawing
	gl::pushModelView();
	gl::translate( Vec2f(0, 0 ) );// viewport.getHeight() ) );
	gl::scale( Vec3f(1, 1, 1) );

	// draw the 3 Fbo's 
	//gl::color( Color::white() );
	//gl::draw( mFboScene.getTexture(), Rectf(0, 0, 256, 256) );
	//gl::draw( mFboBlur1.getTexture(), Rectf(260, 0, 260 + 256, 256) );
	//gl::draw( mFboBlur2.getTexture(), Rectf(520, 0, 520 + 256, 256) );

	// draw our scene with the blurred version added as a blend
	gl::color( Color::white() );
	
	gl::enableAdditiveBlending();
	gl::draw( mFboScene.getTexture(), Rectf(0, 0, viewport.getWidth(), viewport.getHeight() ));

	gl::draw( mFboBlur2.getTexture(), Rectf(0, 0, viewport.getWidth(), viewport.getHeight() ));
	gl::disableAlphaBlending();

	// restore the modelview matrix
	gl::popModelView();

	if (flipScreen == true){
		gl::popMatrices();
	}
	
	gl::color( Color(1.0,1.0,1.0) );
	

	OutlineParams::getInstance()->draw();
}

void TextTestApp::drawSkeleton(){
	// Clear window

	// We're capturing
	if ( mKinect->isCapturing() ) {

		// Set up 3D view
		//gl::pushMatrices();
		//gl::setMatrices( mCamera );
		for(int k=0;k<repelClips.size();k++){
			repelClips[k].x = -200;
			repelClips[k].y = -200;
		}

		// Iterate through skeletons
		uint32_t i = 0;
		for ( vector<Skeleton>::const_iterator skeletonIt = mSkeletons.cbegin(); skeletonIt != mSkeletons.cend(); ++skeletonIt, i++ ) {

			// Set color
			Colorf color = mKinect->getUserColor( i );
			int boneIndex = 0;
			// Iterate through joints
			for ( Skeleton::const_iterator boneIt = skeletonIt->cbegin(); boneIt != skeletonIt->cend(); ++boneIt, boneIndex++ ) {

				// Set user color
				//gl::color( color );

				// Get position and rotation
				const Bone& bone	= boneIt->second;
				Vec3f position		= bone.getPosition();
				
				Matrix44f transform	= bone.getAbsoluteRotationMatrix();
				Vec3f direction		= transform.transformPoint( position ).normalized();
				direction			*= 0.05f;
				position.z			*= -1.0f;


				Vec3f destination		= skeletonIt->at( bone.getStartJoint() ).getPosition();
				Vec3f end		= skeletonIt->at( bone.getEndJoint() ).getPosition();
				

				Vec2f endScreen	= Vec2f( mKinect->getSkeletonVideoPos( end ) );
				
				Vec2f positionScreen	= Vec2f( mKinect->getSkeletonVideoPos( position ) );
				Vec2f destinationScreen	= Vec2f( mKinect->getSkeletonVideoPos( destination ) );


				Vec2f midPoint = getMidPoint(destinationScreen, endScreen);

				repelClips[boneIndex].x = positionScreen.x*2;
				repelClips[boneIndex].y = positionScreen.y*2;
				repelClips[boneIndex].zDist = position.z;


				//update  midpoint clip
				repelClips[boneIndex+20].x =  midPoint.x*2;
				repelClips[boneIndex+20].y =  midPoint.y*2;
				repelClips[boneIndex+20].zDist = position.z;


				//gl::color(Color(1.0,0.0,0.0));
				//gl::drawSolidCircle( Vec2f(destinationScreen.x*2, destinationScreen.y*2), 20);

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
							//repelClips[NUI_SKELETON_POSITION_HIP_CENTER].set= outlineParams.
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

			}

		}
		
	}

	
	//show the repel clip forces
	if (OutlineParams::getInstance()->showForces == true){
		for (int i = 0;i < repelClips.size(); i++){
			repelClips[i].k = OutlineParams::getInstance()->getForceForIndex(i);
			repelClips[i].minDist = OutlineParams::getInstance()->getMinDistForIndex(i);
			gl::color(ColorA(1.0,0.0,0.0,0.5));
			gl::drawSolidCircle(ci::Vec2f(repelClips[i].x, repelClips[i].y),OutlineParams::getInstance()->getForceForIndex(i) + (repelClips[i].zDist*repelClips[i].zDist));
			gl::color(ColorA(0.0,1.0,0.0,0.5));
			gl::drawSolidCircle(ci::Vec2f(repelClips[i].x, repelClips[i].y),OutlineParams::getInstance()->getMinDistForIndex(i) + (repelClips[i].zDist*repelClips[i].zDist));
		}
	}

	//draw the user in particles 
	bool drawUser = false; 
	if (drawUser==true){
		for (int i = 0;i < repelClips.size(); i++){
			userParticles[i].xpos = repelClips[i].x;
			userParticles[i].ypos = repelClips[i].y;

			userParticles[i].rad = OutlineParams::getInstance()->getMinDistForIndex(i) - (repelClips[i].zDist*repelClips[i].zDist);
			userParticles[i].update(getElapsedSeconds());
			userParticles[i].draw();
		}
	}
};


Vec2f TextTestApp::getMidPoint(Vec2f p0, Vec2f p1){
	
	float midx = (p0.x + p1.x) / 2;
	float midy = (p0.y + p1.y) / 2;
	return Vec2f(midx, midy);
}


// Receives skeleton data
void TextTestApp::onSkeletonData( vector<Skeleton> skeletons, const DeviceOptions &deviceOptions )
{
	mSkeletons = skeletons;
}


// This line tells Cinder to actually create the application
CINDER_APP_NATIVE( TextTestApp, RendererGl )