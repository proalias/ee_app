#include "SVGtoParticleParser.h"



void SVGtoParticleParser::recursiveParse(cinder::XmlTree node, std::vector<Particle> &pointsContainer){

	for( XmlTree::ConstIter item = node.begin(); item != node.end(); ++item ) {

		std::list<XmlTree> children = item->getChildren();

		for (std::list<XmlTree>::iterator iter = children.begin();iter != children.end(); iter ++){

			std::string tagName = iter->getTag();

			if (tagName == "circle"){
				std::list<XmlTree::Attr> attributes = iter->getAttributes();

				float cx, cy, rad;

				for(std::list<XmlTree::Attr>::iterator attr = attributes.begin();attr != attributes.end();attr ++){
					if (attr->getName()=="cx"){
						cx =attr->getValue<float>();
					}
					if (attr->getName()=="cy"){
						cy =attr->getValue<float>();
					}
					if (attr->getName()=="r"){
						rad =attr->getValue<float>();
					}
				}
				//circ.vx = Rand::randFloat(-2.0f, 2.0f );
				//circ.vy = Rand::randFloat(-2.0f, 2.0f);
				Particle p = Particle(cx,cy,rad);
				p.color = Color(0.0,1.0,0.0);
				pointsContainer.push_back( p );
				//Vec3f v = Vec3f(attributes.getValue( "size" ), attributes[1].getValue(), attributes["cX"]);
			}


			
			if (tagName == "path"){
				std::list<XmlTree::Attr> attributes = iter->getAttributes();

				for(std::list<XmlTree::Attr>::iterator attr = attributes.begin();attr != attributes.end();attr ++){
					if (attr->getName()=="d"){
						string str0 =attr->getValue<string>();

						std::vector<ci::Vec2f> curves;
						std::vector<ci::Vec2f> points;
				
						
						
						typedef vector< string > split_vector_type;
    
						split_vector_type SplitVecA; // #2: Search for tokens
							
						boost::split( SplitVecA, str0, boost::is_any_of("McCz") ); // SplitVec == { "hello abc","ABC","aBc goodbye" }

						std::vector<string> SplitVec;


						for (int i=0; i<SplitVecA.size(); i++){
							if (SplitVecA[i] != ""){
								SplitVec.push_back(SplitVecA[i]);
							}
						}


						ci::Vec2f prevPoint;
						for(std::vector<string>::iterator pointIter = SplitVec.begin(); pointIter != SplitVec.end(); pointIter++){

							string pathSeg = *pointIter;
							boost::replace_all(pathSeg, "-", ",-");
							
							std::vector<string> pointsVec; 
							boost::split( pointsVec, pathSeg, boost::is_any_of(",") ); // SplitVec == { "hello abc","ABC","aBc goodbye" }

							
							float prevVal;
							std::vector<float> curveSeg;
							for (int i=0;i<pointsVec.size();i++){
								if (pointsVec[i] != "" ){
									
									float temp = ::atof(pointsVec[i].c_str());

									curveSeg.push_back(temp);
								}
							}

							if (curveSeg.size() == 2){

								ci::Vec2f pt = prevPoint = ci::Vec2f(curveSeg[0],curveSeg[1]);
								points.push_back(ci::Vec2f(curveSeg[0],curveSeg[1]));

							}

							if (curveSeg.size() == 6){

								
								ci::Vec2f c0 = ci::Vec2f(curveSeg[0],curveSeg[1]);//control point
								ci::Vec2f c1 = ci::Vec2f(curveSeg[2],curveSeg[3]);//control point
							
								ci::Vec2f pt;
								//last point is defined in world space
								if ((pointIter != SplitVec.end()) && (pointIter + 1 == SplitVec.end())){
									pt = ci::Vec2f(curveSeg[4],curveSeg[5]);//actual point
								}else{
									pt = ci::Vec2f(prevPoint.x + curveSeg[4],prevPoint.y + curveSeg[5]);//actual point
									prevPoint = pt;
									points.push_back(pt);
								}

							}

						}

						int pointCount = points.size();

						ci::Vec2f p0 = points[0];
						ci::Vec2f p1 = points[pointCount/2];



						/*
						//(x-h)^2 + (y-k)^2 = r^2

						
						//(x0-h)^2 + (y0-k)^2 = r^2
						//(x1-h)^2 + (y1-k)^2 = r^2
						//(x2-h)^2 + (y2-k)^2 = r^2
						


						x0 - x2 + (y0-k)^2 - (y2-k)^2 = 0;
						

						
						(x0-h)^2 - (x2-h)^2 = -(y0-k)^2 + (y2-k)^2;

						(x1-h)^2 + (y1-k)^2 = r^2
						
						(x2-h)^2 + (y2-k)^2 = r^2
						*/



						float r = ci::math<float>::sqrt((p1.x - p0.x)*(p1.x - p0.x) + (p1.y - p0.y)*(p1.y - p0.y));

						
						Particle p = Particle( (p0.x + p1.x)/2 ,(p0.y + p1.y)/2 , r/2);
						p.color = ci::Color(1.0/100 * float(pointsContainer.size()),0.0,0.0);
						pointsContainer.push_back(p);

						

					}
				}

			}


			recursiveParse( *iter, pointsContainer);
		}
	}
}