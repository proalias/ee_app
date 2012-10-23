#ifndef PARTICLEA_H
#define PARTICLEA_H

#include "cinder\Cinder.h"
#include "cinder\Vector.h"
#include "cinder\gl\gl.h"
#include <stdio.h>
#include <string.h>
#include "cinder/app/App.h"
#include "cinder/app/MouseEvent.h"
#include "cinder/CinderMath.h"
#include "cinder/Rand.h"
#include "cinder/Timeline.h"

#include "CinderClip.h"
#include "RepelPoint.h"
#include "TextureGlobals.h"

using namespace ci;

class ParticleA{
public:
   
    void setVx(float nVx);
    float getVx();
    void setVy(float nVy);
    float getVy();
    void  setDamp(float nDamp);
    float  getDamp();
    void setBounce(float nBounce);
    float  getBounce();
	void setGrav(float nGrav);
    float  getGrav();
	void setMaxSpeed( float nMaxSpeed );
	float getMaxSpeed();
	void setWander( float nWander );
    float getWander();
    void setEdgeBehavior(std::string sEdgeBehavior);
    std::string getEdgeBehavior();
    void setBounds( float left, float right, float top, float bot);
	void setDraggable( bool bDrag );

	gl::Texture* particleTexture;

	void gravToMouse( bool bGrav, float force );
    void springToMouse( bool bSpring, float force );
    void repelMouse( bool bRepel, float force, float minDist );
    float addSpringPoint(float x, float y, float force);
    float addGravPoint(float x, float y, float force);
    float addRepelPoint( float x, float y, float force, float minDist );
	
	float addSpringClip(CinderClip &clip, float force);
	float addGravClip(CinderClip &clip, float force);
	int addRepelClip( CinderClip &clip, float force, float minDist );

	
	ci::Vec2f getRandomPointOnGrid();

    void removeSpringPoint( int index );
    void removeGravPoint( int index );
    void removeRepelPoint( int index );
    void removeSpringClip(int index);
    void removeGravClip(int index);
    void removeRepelClip(int index);

    void clearSpringPoints();
    void clearGravPoints();
    void clearRepelPoints();
    void clearSpringClips();
    void clearGravClips();
    void clearRepelClips();
	void init();

	std::vector<ci::Vec3f> __springPoints;
    std::vector<RepelPoint> __gravPoints;
    std::vector<RepelPoint> __repelPoints;
    
	std::vector<CinderClip*> __springClips;
    std::vector<CinderClip*> __gravClips;
	std::vector<CinderClip*> __repelClips;

	//ci::Rectf __efClip;

	void pressHandler( ci::app::MouseEvent);
    void releaseHandler( ci::app::MouseEvent);
	void outsideHandler( ci::app::MouseEvent);
    bool getDraggable();
	void setTurnToPath(bool bTurn);
    bool getTurnToPath();

	void  __efHandler( ci::app::Event );
    void  update();


	//flash properties
	float x;
	float y;
	float rotation;
	Anim <float> width;
	float height;
	float scaleX;
	float scaleY;

	float __vx;
	float __vy;
	float __oldx;
	float __oldy;

	float __mouseK;
	float mouseX;
	float mouseY;

	float __k;
	float __damp;
	float __bounce;     
	float __grav;
	float __maxSpeed;
	float __wander;

	bool __turn;
	bool __draggable;
	bool __drag;
	bool __springToMouse;
	bool __gravToMouse;
	bool __repelMouse;
	
	float __repelMouseMinDist;
	float __gravMouseForce;
	float __repelMouseK;

	std::string __edgeBehavior;
	ci::Rectf __bounds;

	//spawn & die related 
	bool decays;
	int lifeSpan;
	void die();
	void respawn();
	bool dying;
};

#endif