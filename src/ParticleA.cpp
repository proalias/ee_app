#include "ParticleA.h"

void ParticleA::init()
{
	__vx				= 0.0;
	__vy                = 0.0;
	__k                 = 0;//0.2;
	__damp              = 0.9;
	__bounce            = -0.5;
	__grav              = 0;
	
	__wander=0;
	

	decays = false;
	lifeSpan = 100 + randInt(200);
	dying = false;
	

	width = 1;
	height = 1;

	__bounds = ci::Rectf();
	setBounds( 0, 1280, 0, 800 ); 
	__maxSpeed = 0;
	__springPoints = std::vector<ci::Vec3f>();
	__gravPoints = std::vector<RepelPoint>();
	__repelPoints = std::vector<RepelPoint>();

	//__efClip = ci::Rectf();

	
}

void ParticleA::setVx(float nVx)
{
	__vx = nVx;
}

float ParticleA::getVx()
{
	return __vx;
}

void ParticleA::setVy(float nVy)
{
	__vy = nVy;
}

float  ParticleA::getVy()
{
	return __vy;
}

void  ParticleA::setDamp(float nDamp)
{
	__damp = nDamp;
}

float ParticleA::getDamp()
{
	return __damp;
}

void ParticleA::setBounce(float nBounce)
{
	__bounce = nBounce;
}

float  ParticleA::getBounce()
{
	return __bounce;
}

void ParticleA::setGrav(float nGrav)
{
	__grav = nGrav;
}

float  ParticleA::getGrav()
{
	return __grav;
}

void ParticleA::setMaxSpeed( float nMaxSpeed )
{
	__maxSpeed = nMaxSpeed;
}

float ParticleA::getMaxSpeed()
{
	return __maxSpeed;
}

void ParticleA::setWander( float nWander )
{
	__wander = nWander;
}

float ParticleA::getWander()
{
	return __wander;
}

void ParticleA::setEdgeBehavior(std::string sEdgeBehavior)
{
	__edgeBehavior = sEdgeBehavior;
}

std::string ParticleA::getEdgeBehavior()
{
	return __edgeBehavior;
}

void ParticleA::setBounds( float left, float right, float top, float bot)
{
	__bounds = ci::Rectf(left,top,right,bot);
}

void ParticleA::setTurnToPath( bool bTurn)
{
	__turn = bTurn;
}

bool  ParticleA::getTurnToPath()
{
	return __turn;
}

void ParticleA::__efHandler( ci::app::Event )
{
	update();
}

void ParticleA::update()
{
	float dx;
	float dy;
	float distSQ;
	float dist;
	float force;
	float tx;
	float ty;
	ci::Vec3f point;
	CinderClip clip;
	int k;
	float minDist;



	if (decays){
		lifeSpan -= 1;

		if (lifeSpan == 0){
			dying = true;
		}	
	}
		for ( int sp=0; sp < __springPoints.size(); sp++ )
		{
			point = __springPoints[sp];
			__vx += (point.x - x) * point.z;
			__vy += (point.y - y) * point.z;
		}

		for ( int gp = 0; gp < __gravPoints.size(); gp++ )
		{
			RepelPoint point = __gravPoints[gp];

			dx = point.x - x;
			dy = point.y - y;

			distSQ = dx * dx + dy * dy;
			dist = ci::math<float>::sqrt( distSQ );
			force = point.k / distSQ;//z = force
			__vx += force * dx / dist;
			__vy += force * dy / dist;
		}

		for ( int rp = 0; rp < __repelPoints.size(); rp++ )
		{
			RepelPoint point = __repelPoints[rp];
			dx = point.x - x;
			dy = point.y - y;

			dist = ci::math<float>::sqrt( dx * dx + dy * dy );
			if (dist < point.minDist)
			{
				tx = point.x - point.minDist * dx / dist;
				ty = point.y - point.minDist * dy / dist;

				__vx += (tx - x) * point.k;//k == z
				__vy += (ty - y) * point.k;//k == z

			}
		}

		for ( int sc = 0; sc < __springClips.size(); sc++ )
		{
			CinderClip clip = *__springClips[sc];
			k = clip.k;
			__vx += (clip.getCenter().x - x) * k;
			__vy += (clip.getCenter().y - y) * k;

		}

		for ( int gc = 0; gc < __gravClips.size(); gc++ )
		{

			CinderClip clip = *__gravClips[gc];
			dx = clip.x - x;
			dy = clip.y - y;

			distSQ = dx * dx + dy * dy;
			dist = ci::math<float>::sqrt( distSQ );
			force = clip.k / distSQ;
			__vx += force * dx / dist;
			__vy += force * dy / dist;
		}

		for ( int rc= 0; rc < __repelClips.size(); rc++ )
		{
			
			CinderClip clip = *__repelClips[rc];
			if (	clip.x < 0 || clip.y < 0){
				continue;
			}
			minDist = clip.minDist;//*__repelClips[rc].minDist;
			k = clip.k;//__repelClips[rc].k;
			dx = clip.x - x;
			dy = clip.y - y;

			dist = ci::math<float>::sqrt(dx * dx + dy * dy);
			if (dist < minDist)
			{
				tx = clip.x - minDist * dx / dist;
				ty = clip.y - minDist * dy / dist;
				__vx += (tx - x) * k;
				__vy += (ty - y) * k;

			}
		}
		__vx += ci::randFloat(1.0) * __wander - __wander / 2;
		__vy += ci::randFloat(1.0) * __wander - __wander / 2;
		__vy += __grav;
		__vx *= getDamp();
		__vy *= getDamp();

		float speed = ci::math<float>::sqrt(__vx * __vx + __vy * __vy);
		if (speed > __maxSpeed) {
			__vx = __maxSpeed * __vx / speed;
			__vy = __maxSpeed * __vy / speed;
		}
		if (__turn)
		{
			rotation = ci::math<float>::atan2(__vy, __vx) * 180 / M_PI;
		}

		x += __vx;
		y += __vy;


		// TODO - override this class , create one for field particle and stick this in
		// can also change its blur/ altho may get different bitmaps for state
		scaleX = scaleY = 1 + (speed/10);

		if(__edgeBehavior == "wrap")
		{
			if ( x > __bounds.getUpperRight().x + width/2 )
			{
				x = __bounds.getUpperLeft().x - width/2;
			} else if ( x < __bounds.getUpperLeft().x - width/2)
			{
				x = __bounds.getUpperRight().x + width/2;
			}
			if( y > __bounds.getLowerLeft().y + height/2)
			{
				y = __bounds.getUpperLeft().y - height/2;
			} else if (y < __bounds.getUpperLeft().y - height/2)
			{
				y = __bounds.getLowerLeft().y + height/2;
			}

		} else if(__edgeBehavior == "bounce")
		{
			if ( x > __bounds.getUpperRight().x - width/2)
			{
				x = __bounds.getUpperRight().x - width/2;
				__vx *= __bounce;
			} else if (x < __bounds.getUpperLeft().x + width/2){
				x = __bounds.getUpperLeft().x + width/2;
				__vx *= __bounce;
			}
			if( y > __bounds.getLowerLeft().y - height/2){
				y = __bounds.getLowerLeft().y - height/2;
				__vy *= __bounce;
			} else if ( y < __bounds.getUpperLeft().y + height/2){
				y = __bounds.getUpperLeft().y + height/2;
				__vy *= __bounce;
			}

		} else if(__edgeBehavior == "remove")
		{
			if( x > __bounds.getUpperRight().x + width/2 || x < __bounds.getUpperLeft().x - width/2 ||
				y > __bounds.getLowerLeft().y + height/2 || y < __bounds.getUpperLeft().y - height/2){
					//removeChild( this );//<--look into this
			}
		}
		//if( stage != null )
		//    stage.invalidate();

		int textureType = randInt(4)+1;
	
		particleTexture = TextureGlobals::getInstance()->getParticleTexture(textureType);
	
		if (dying==true){
			width = width * 0.8;
		}

		if (width < 0.0001){
			respawn();
		}
};

void ParticleA::gravToMouse( bool bGrav, float force )
{
	if (bGrav) {
		if (!force) {
			float force = 1000.0;
		}
		__gravMouseForce = force;
		__gravToMouse = true;
	}
	else {
		__gravToMouse = false;
	}
}

void ParticleA::springToMouse( bool bSpring, float force )
{
	if (bSpring)
	{
		if (!force) {
			float force = .1;
		}
		__mouseK = force;
		__springToMouse = true;

	} else
	{
		__springToMouse = false;
	}
}

void ParticleA::repelMouse( bool bRepel, float force, float minDist )
{
	if (bRepel)
	{
		if (!force)
		{
			float force = .1;
		}
		if (!minDist)
		{
			float minDist = 100;
		}
		__repelMouseK = force;
		__repelMouseMinDist = minDist;
		__repelMouse = true;

	} else
	{
		__repelMouse = false;
	}
}

float ParticleA::addSpringPoint(float x, float y, float force)
{
	if (!force)
	{
		float force = .1;
	}
	__springPoints.push_back( Vec3f(x, y,force) );
	return __springPoints.size() - 1;
}

float ParticleA::addGravPoint(float x, float y, float force)
{
	if (!force)
	{
		float force = 1000;
	}
	__gravPoints.push_back( RepelPoint(x, y, force,0) );
	return __gravPoints.size() - 1;
}

float ParticleA::addRepelPoint( float x, float y, float force, float minDist)
{
	if (!force) {
		float force = .1;
	}
	if (!minDist) {
		float minDist = 100;
	}
	__repelPoints.push_back(RepelPoint(x, y, force, minDist));
	return __repelPoints.size() - 1;
}

float ParticleA::addSpringClip(CinderClip &clip, float force)
{
	if (!force)
	{
		float force = .1;
	}
	clip.k = force;
	__springClips.push_back( &clip );
	return __springClips.size() - 1;
}

float ParticleA::addGravClip(CinderClip &clip, float force)
{
	if (!force)
	{
		float force = 1000;
	}
	clip.k = force;
	__gravClips.push_back(&clip);
	return __gravClips.size() - 1;
}

int ParticleA::addRepelClip( CinderClip &clip, float force, float minDist )
{
	if ( !force )
	{
		float force = 0.1;
	}
	if ( !minDist )
	{
		float minDist = 100.0;
	}

	clip.k = force;
	clip.minDist;
	__repelClips.push_back( &clip );
	return __repelClips.size() - 1;
}


void ParticleA::die(){
	dying = true;
}

void ParticleA::respawn(){

	width = randFloat(3,10);
	Vec2f p  = getRandomPointOnGrid();

	x=randFloat(app::getWindowWidth());
	y=randFloat(app::getWindowHeight());

	lifeSpan = 100 + randInt(200);

	dying = false;
}


ci::Vec2f ParticleA::getRandomPointOnGrid(){
	
	int SPACING = 38;

	float COLUMNS = cinder::app::getWindowWidth()/SPACING;
	float ROWS = cinder::app::getWindowHeight()/SPACING;
	
	float pX = randInt(-COLUMNS, COLUMNS)*SPACING;
	float pY = randInt(-ROWS, ROWS)*SPACING;
	return ci::Vec2f(pX,pY);	
}



void  ParticleA::removeSpringPoint( int index )
{
	__springPoints.erase(__springPoints.begin()+index);
}

void  ParticleA::removeGravPoint( int index )
{
	__gravPoints.erase(__gravPoints.begin()+index);
}

void  ParticleA::removeRepelPoint( int index ) {
	__repelPoints.erase(__repelPoints.begin()+index);
}

void  ParticleA::removeSpringClip(int index)
{
	__springClips.erase(__springClips.begin()+index);
}

void  ParticleA::removeGravClip(int index)
{
	__gravClips.erase(__gravClips.begin()+index);
}

void  ParticleA::removeRepelClip(int index)
{
	__repelClips.erase(__repelClips.begin()+index);
}

void  ParticleA::clearSpringPoints()
{
	__springPoints.clear();
}

void  ParticleA::clearGravPoints()
{
	__gravPoints.clear();
}

void  ParticleA::clearRepelPoints()
{
	__repelPoints.clear();
}

void  ParticleA::clearSpringClips()
{
	__springClips.clear();
}

void  ParticleA::clearGravClips()
{
	__gravClips.clear();
}

void  ParticleA::clearRepelClips()
{
	__repelClips.clear();
}