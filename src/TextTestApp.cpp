
#include "cinder/app/AppBasic.h"
#include "cinder/app/AppNative.h"
#include "cinder/Camera.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "cinder/params/Params.h"
#include "cinder/Utilities.h"
#include "Kinect.h"

#include "FontRenderer.h"
#include "Particle.h"
#include "ParticleA.h"

#include "CinderClip.h"


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

	void update();
	void updateSkeleton();

	void draw();
	void drawSkeleton();

	gl::Texture bgImage;
	
	gl::Texture mSimpleTexture;

	FontRenderer myFont;
 
	std::list<ParticleA>	mParticles;

	std::vector<ParticleA>	gridParticles;
	void drawGrid();


	CinderClip myClip;
	
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
};



void TextTestApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 1280, 800 );
	//settings->setWindowSize( 1280, 800 );
	//settings->setFrameRate( 30.0f );
	//settings->setFullScreen( true );
}


void TextTestApp::setup()
{
	//console() << "scoopfullhd.png lives at: " << getAssetPath( "scoopfullhd.png" ) << std::endl;

	// TODO - fit to screen?...
	bgImage = loadImage( loadAsset( "scoopfullhd.png" ) );
	
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

	// draw the grid. TODO - create a class for this and just add a grid instance
	TextTestApp::drawGrid();


	myFont = FontRenderer();
	myFont.addLine( "WELCOME TO", 2 );
	myFont.addLine( "THE NEW NETWORK", 2 );
	myFont.addLine( "FOR YOUR", 2 );
	myFont.addLine( "DIGITAL LIFE", 2 );


	myClip = CinderClip();
	myClip.x = 200;
	myClip.y = 300;


	// myFont.addLine( "some test", 10 ); TODO - addline increments y position by previous text height
	// TODO - text needs to centre align
	for( int i=0; i<5000; i++ )
	{
			//float x = //character[i][0]+xPosition;
			//float y = //character[i][1]+yPosition;

		ParticleA particle = ParticleA();
		particle.init();

		particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );

		particle.width = randFloat(0.5,6);
	
		particle.x=randFloat(getWindowWidth());
		particle.y=randFloat(getWindowHeight());

		//particle.setBounce(-1);
		particle.setMaxSpeed(2);

		//particle.setEdgeBehavior("wrap");

		particle.setWander(3);
		particle.setGrav(0);

	//	particle.addRepelPoint( 200,300,100,100 );

		particle.addRepelClip( myClip, 100, 100 );


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
	updateSkeleton();
	
	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
		p->update();
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




void TextTestApp::drawGrid()
{
	int SPACING = 70;

	float COLUMNS = getWindowWidth()/SPACING;
	float ROWS = getWindowHeight()/SPACING;
	
	int LAYERS = 1;

	int totalParticles = COLUMNS*ROWS;
	int psize = mParticles.size();

	gridParticles.clear();

	for (int l = 0; l < LAYERS; l++){
		//gl::pushMatrices();

		//gl::translate(0,0,-l*mDepth);

		for( int j=0; j<ROWS; j++ ){
			for( int i=0; i<COLUMNS; i++ ){

				ParticleA particle = ParticleA();
				particle.init();
				particle.setBounds( 0,getWindowWidth(),0,getWindowHeight() );
				particle.width = 2;
	
				particle.x = i*SPACING;
				particle.y = j*SPACING;

				//particle.setBounce(-1);
				//particle.setMaxSpeed(2);
				//particle.setEdgeBehavior("wrap");

				//particle.setWander(3);
				particle.setGrav(0);

				//particle.addRepelPoint( 200,300,100,100 );

				particle.addSpringPoint( i*SPACING, j*SPACING, 100 ); // FORCES THE PARTICLE INTO POSITION

				gridParticles.push_back( particle );
			}
		}

	
//		gl::color(ColorA(1.0,1.0,1.0,1.0 - (1.0/mLayers) * l));



		//gl::popMatrices();
	}

}






void TextTestApp::draw()
{

	myClip.x += 2.0;

	//myClip.incrementX();

	// this pair of lines is the standard way to clear the screen in OpenGL
	glClearColor( 0,0,0,1 );
	glClear( GL_COLOR_BUFFER_BIT );
	
	//gl::setMatricesWindow( getWindowSize() );

	gl::draw( bgImage );
	


	//for (int l = 0; l < 3; l++){
	//	gl::pushMatrices();
	//	gl::translate(0,0,-l*20);
		// draw the grid
		for( vector<ParticleA>::iterator p = gridParticles.begin(); p != gridParticles.end(); ++p ){
			gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );
		}
	//	gl::popMatrices();
	//}



	drawSkeleton();
//	gl::enableAlphaBlending( PREMULT );

	gl::color( Color::white() );
	//gl::draw( mSimpleTexture, Vec2f( 10, getWindowHeight() - mSimpleTexture.getHeight() - 5 ) );
	//gl::draw( mSimpleTexture, Vec2f( 10, 10 ) );

	//TODO - dont think i have to keep calling this.
	// tell the font to draw?
	myFont.draw();

	gl::color( Color( 1, 1, 1 ) );

	for( list<ParticleA>::iterator p = mParticles.begin(); p != mParticles.end(); ++p ){
	//	p->mLoc+=( Rand::randFloat( 0.2f ) - Rand::randFloat( 0.2f ) );
	//	p->draw();

		gl::drawSolidCircle( Vec2f( p->x, p->y ), p->width );

	}
}


void TextTestApp::drawSkeleton(){
	// Clear window

	// We're capturing
	if ( mKinect->isCapturing() ) {

		// Set up 3D view
		gl::pushMatrices();
		gl::setMatrices( mCamera );

		// Iterate through skeletons
		uint32_t i = 0;
		for ( vector<Skeleton>::const_iterator skeletonIt = mSkeletons.cbegin(); skeletonIt != mSkeletons.cend(); ++skeletonIt, i++ ) {

			// Set color
			Colorf color = mKinect->getUserColor( i );

			// Iterate through joints
			for ( Skeleton::const_iterator boneIt = skeletonIt->cbegin(); boneIt != skeletonIt->cend(); ++boneIt ) {

				// Set user color
				gl::color( color );

				// Get position and rotation
				const Bone& bone	= boneIt->second;
				Vec3f position		= bone.getPosition();
				Matrix44f transform	= bone.getAbsoluteRotationMatrix();
				Vec3f direction		= transform.transformPoint( position ).normalized();
				direction			*= 0.05f;
				position.z			*= -1.0f;

				
				// Draw generic bone stuff here
				glLineWidth( 2.0f );
				JointName startJoint = bone.getStartJoint();
				if ( skeletonIt->find( startJoint ) != skeletonIt->end() ) {
					Vec3f destination	= skeletonIt->find( startJoint )->second.getPosition();
					destination.z		*= -1.0f;
					gl::drawLine( position, destination );
				}


				//draw bone specifif stuff here
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
				gl::drawSphere( position, 0.025f, 16 );

				// Draw joint orientation
				glLineWidth( 0.5f );
				gl::color( ColorAf::white() );
				gl::drawVector( position, position + direction, 0.05f, 0.01f );

			}

		}
		
		gl::popMatrices();
	}
}


// Receives skeleton data
void TextTestApp::onSkeletonData( vector<Skeleton> skeletons, const DeviceOptions &deviceOptions )
{
	mSkeletons = skeletons;
}


// This line tells Cinder to actually create the application
CINDER_APP_NATIVE( TextTestApp, RendererGl )