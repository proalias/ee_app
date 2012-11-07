#include "SpriteSheet.h"

using namespace std;
using namespace ci;


void SpriteSheet::init(ci::gl::Texture spriteImage, std::string xmlPath, int DataFormat){
		__spriteData = SpriteDataParser::parseSpriteData(xmlPath, DataFormat);
		__spriteImage = spriteImage;
		__currentFrame = 0;
		__totalFrames = __spriteData.size();
		__textureWidth = spriteImage.getWidth();
		__textureHeight = spriteImage.getHeight();

}

void SpriteSheet::draw(){
	SpriteData frame = __spriteData[__currentFrame];
	
	float u = frame.x;
	float v = frame.y;
   // v += frame.h;
    //v = frame.oH - v;
    float s = u + frame.w;
    float t = v + frame.h;


	bool textureRectangle = true;
	ci::Rectf rect(frame.oX,frame.oY,frame.oX+frame.w, frame.oY+frame.h);


	glEnableClientState( GL_VERTEX_ARRAY );
	GLfloat verts[8];
	glVertexPointer( 2, GL_FLOAT, 0, verts );
	glEnableClientState( GL_TEXTURE_COORD_ARRAY );
	GLfloat texCoords[8];
	glTexCoordPointer( 2, GL_FLOAT, 0, texCoords );

	__spriteImage.enableAndBind();

	//top right
	verts[0*2+0] = rect.getX2(); texCoords[0*2+0] = s/__textureWidth;;
	verts[0*2+1] = rect.getY1(); texCoords[0*2+1] = v/__textureHeight;;
	
	//top left
	verts[1*2+0] = rect.getX1(); texCoords[1*2+0] = u/__textureWidth;
	verts[1*2+1] = rect.getY1(); texCoords[1*2+1] = v/__textureHeight;
	
	//bottom right
	verts[2*2+0] = rect.getX2(); texCoords[2*2+0] = s/__textureWidth;
	verts[2*2+1] = rect.getY2(); texCoords[2*2+1] = t/__textureHeight;
	
	//bottom left
	verts[3*2+0] = rect.getX1(); texCoords[3*2+0] = u/__textureWidth;;
	verts[3*2+1] = rect.getY2(); texCoords[3*2+1] = t/__textureHeight;;

	glDrawArrays( GL_TRIANGLE_STRIP, 0, 4 );

	__spriteImage.disable();
	__spriteImage.unbind();


	glDisableClientState( GL_VERTEX_ARRAY );
	glDisableClientState( GL_TEXTURE_COORD_ARRAY );	




}

void SpriteSheet::update(){
	__currentFrame = (__currentFrame +=1) % __totalFrames;
}



void SpriteSheet::setFrame(int frame){

}

int SpriteSheet::getCurrentFrame(){
	return 0;
}