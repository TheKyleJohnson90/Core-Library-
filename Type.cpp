#pragma once
//#include <string.h>
#include "Type.h"
#include "math.h"
#include "Const.h"

//Line
inline void Line::compute(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo){
	M=(yOne-yTwo)/(xOne-xTwo);
	B=yOne-(M*xOne);
}
inline void Line::compute(Vector2 const&V1,Vector2 const&V2){
	compute(V1.x,V1.y,V2.x,V2.y);
}
inline void Line::setM(float const&newM){
	M=newM;
}
inline void Line::setB(float const&newB){
	B=newB;
}
inline float Line::getY(float const&X){
	return (M*X)+B;
}
inline float Line::getX(float const&Y){
	//y=M*x+B
	return 0;
}
inline float Line::getM(){
	return M;
}
inline float Line::getB(){
	return B;
}

//Circle
inline void Circle::set(Vector2 const&newVec){
	vec=newVec;
}
inline void Circle::set(float const&newR){
	r=newR;
}
inline void Circle::set(float const&newR,Vector2 const&newVec){
	set(newR);
	set(newVec);
}
inline void Circle::set(int count,Vector2 const *vertices){
	for(int index=0;index<count;index++){
		vec=vec+vertices[index];
	}
	vec=vec/count;
	for(int index=0;index<count;index++){
		r=Max(r,lsq(vec));
	}
	r=sqrt(r);
}
inline void Circle::get(Vector2 &newVec)const{
	newVec=vec;
}
inline void Circle::get(float &newR) const{
	newR=r;
}
inline void Circle::get(float &newR,Vector2 &newVec) const{
	get(newR);
	get(newVec);
}
inline void Circle::get(float &newX,float &newY) const{
	newX=vec.x;
	newY=vec.y;
}

//Sphere
inline void Sphere::set(Vector3 const&newVec){
	vec=newVec;
}
inline void Sphere::set(float const&newR){
	r=newR;
}
inline void Sphere::set(float const&newR,Vector3 const&newVec){
	set(newR);
	set(newVec);
}
inline void Sphere::set(int count,Vector3 const *vertices){
	for(int index=0;index<count;index++){
		vec=vec+vertices[index];
	}
	vec=vec/count;
	for(int index=0;index<count;index++){
		r=Max(r,lsq(vec));
	}
	r=sqrt(r);
}
inline void Sphere::get(Vector3 &newVec)const{
	newVec=vec;
}
inline void Sphere::get(float &newR) const{
	newR=r;
}
inline void Sphere::get(float &newR,Vector3 &newVec) const{
	get(newR);
	get(newVec);
}
inline void Sphere::get(float &newX,float &newY,float &newZ) const{
	newX=vec.x;
	newY=vec.y;
	newZ=vec.z;
}

//Plane Constructors
inline Plane::Plane(){
	normal=Vector3();
	d=0;
}
inline Plane::Plane(Vector3 const&newNormal,float newD){
	//
	normal=newNormal;
	d=newD;

}
inline Plane::Plane(Vector3 const&a,Vector3 const&b,Vector3 const&c){
	//cross product of(b-a) and (c-a)
	normal=cross((b-a),(c-a));
	normal=norm(normal);
	d=dot(normal,a);
}
//line
inline Line::Line(){
	M=0;
	B=0;
}
inline Line::Line(float const& newM,float const&newB){
	M=newM;
	B=newB;
}
inline Line::Line(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo){
	//compute(xOne,yOne,xTwo,yTwo);
	M=(yOne-yTwo)/(xOne-xTwo);
	B=yOne-(M*xOne);
}
inline Line::Line(Vector2 const&V1,Vector2 const&V2){
	//compute(V1,V2);
	M=(V1.y-V2.y)/(V1.x-V2.x);
	B=V1.y-(M*V1.x);
}
//Vertex
inline Vertex::Vertex(){
	position=Vector3();
	texcoord=Vector2();
	normal=Vector3();
	color=0;
}
inline Vertex::Vertex(unsigned int const&newColor,Vector3 const&newPosition,Vector3 const&newNormal,Vector2 const&newTex){
	position=newPosition;
	texcoord=newTex;
	normal=newNormal;
	color=newColor;
}


