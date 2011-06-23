#pragma once
#include <cmath>
#include "Const.h"
//TODO:Math(Namespace)
//FastSin
inline const float fastSin(const float deg){
	// this still needs to interpolate between integers to be more precise
	if (deg<360)
		return SinTable[(int)deg];
	else
		return SinTable[(int)deg%360];
}
//FastCos
inline const float fastCos(const float deg){
	//
	return fastSin(deg+90);
}
//Fast SquareRoot 
inline const float fastSqrt(float const&index){
	//
	return 0;
}
//Radians To Degrees
inline const float radToDeg(float deg){
	return deg*(180 / PI);
}
//Degrees to Radians
inline const float degToRad(float rad){
	return rad*(PI / 180);
}
//Rounding Checking equals
inline const bool equ(float lhs,float rhs){
	float delta=lhs-rhs;
	return (delta*delta)<TOLSQ;
}
//IDK
//inline void setPrecision(){}

//TODO:Core (Namespace)
//Transforms a point into world space
inline const Vector3 PointToWorldSpace(Vector3 target, Vector3 heading, Vector3 side, Vector3 position){return Vector3();}
//Transforms a point into local space
inline const Vector3 PointToLocalSpace(Vector3 target, Vector3 heading, Vector3 side, Vector3 position){return Vector3();}
//Transforms a Vector3 into world space
inline const Vector3 VectorToWorldSpace(Vector3 force, Vector3 heading, Vector3 side){return Vector3();}

//Returns Higher Value 
inline const double Max(double const&lhs, double const&rhs){return lhs>rhs?lhs:rhs;}
//Returns Lower Value
inline const double Min(double const&lhs, double const&rhs){return lhs<rhs?lhs:rhs;}

//TODO:Random (namespace)

//srand(time(NULL));
//Returns random integer between values 
inline const int RandInt(int lhs,int rhs) 
{
return lhs-rhs;//rand()%(rhs-lhs+1)+lhs;
}
//Returns random percentage
inline const double RandPercent()
{
return RandInt(0,100);//(rand())/(RAND_MAX+1.0);
}
//Returns random boolean
inline const bool RandBool()
{
if (RandInt(0,1)) 
{
return (true);
}
else 
{
return (false);
}
}
//Returns value between 0 and 1
inline const double RandomClamped()	
{
return (RandPercent() - RandPercent());
}

//TODO:Vector2 (Namespace)
//Vector2 operands (should put this in type.cpp??)

//Subtractes the two Vector2 objects
inline const Vector2 operator-(Vector2 const&lhs,Vector2 const&rhs){
	return Vector2(lhs.x-rhs.x,lhs.y-rhs.y);
}
//Adds the two Vector2 objects
inline const Vector2 operator+(Vector2 const&lhs,Vector2 const&rhs){
	return Vector2(lhs.x+rhs.x,lhs.y+rhs.y);
}
//divides the two Vector2 objects
inline const Vector2 operator/(Vector2 const&lhs,float const&rhs){
	return Vector2(lhs.x/rhs,lhs.y/rhs);
}
//Multiplies the two Vector2 objects
inline const Vector2 operator*(float lhs,Vector2 const &rhs){
	Vector2 result;
	result.x=rhs.x * lhs;
	result.y=rhs.y * lhs;
	return result;
}
//Subtractes the two Vector2 objects
inline const Vector2& operator-=(Vector2 &lhs,const Vector2 &rhs){
	lhs.x-=rhs.x;
	lhs.y-=rhs.y;
	return lhs;
}
//Adds the two Vector2 objects
inline const Vector2& operator+=(Vector2 &lhs,const Vector2 &rhs){
	lhs.x+=rhs.x;
	lhs.y+=rhs.y;
	return  lhs;
}
//Divides the two Vector2 objects
inline const Vector2& operator/=(Vector2 &lhs,const Vector2 &rhs){
	lhs.x/=rhs.x;
	lhs.y/=rhs.y;
	return  lhs;
}
//Multiplies the two Vector2 objects
inline const Vector2& operator*=(Vector2 &lhs,const Vector2 &rhs){
	lhs.x*=rhs.x;
	lhs.y*=rhs.y;
	return  lhs;
}
//Multiplies the Vector2 object by a float
inline const Vector2& operator*=(Vector2 &lhs,const float &rhs){
	lhs.x*=rhs;
	lhs.y*=rhs;
	return  lhs;
}
//Compares the two Vector2 objects and returns (true) if they are not equal
inline const bool operator!=(Vector2 const&lhs,Vector2 const&rhs){
	return (lhs.x != rhs.x) || (lhs.y != rhs.y);
 }
//Compares the two Vector2 objects and returns (true) if they are equal
inline const bool operator==(Vector2 const&lhs,Vector2 const&rhs){
  return (equ(lhs.x, rhs.x) && equ(lhs.y,rhs.y) );
  }

//TODO: Vector2 math (Namespace)
//Sets the Vector2 with zero values
inline void zero(Vector2 &lhs){
	lhs.x=0.0f;
	lhs.y=0.0f;
}
//Returns if the Vector2 is zero
inline const bool isZero(Vector2 const&lhs){
	return (lhs.x*lhs.x+lhs.y*lhs.y)<TOL;
}
//Returns dot product
inline const float dot(Vector2 const&lhs,Vector2 const&rhs){
	return lhs.x*rhs.x+lhs.y*rhs.y;
}
//Returns length squared
inline const float lsq(Vector2 const&rhs){
	return dot(rhs,rhs);
}
//Returns magnitude (length)
inline const float mag(Vector2 const &rhs){
	return sqrtf(dot(rhs, rhs));
}
//Returns normalized Vector2
inline Vector2 norm(Vector2 const &lhs){
	return (1.f /(mag(lhs))) * lhs;
}
//Returns cross product for Vector2
inline double cross(Vector2 const &lhs, Vector2 const &rhs){
	return (lhs.x * rhs.y - lhs.y * rhs.x);
}
//Returns Negative or Positive (value of one)
inline const int sign(const Vector2& lhs,const Vector2& rhs){
	if (lhs.y*rhs.x > lhs.x*rhs.y)
  { 
    return -1;
  }
  else 
  {
    return 1;
  }}
//Returns perpendicular Vector2
inline const Vector2 perp(Vector2 const &rhs){
	return Vector2(-rhs.y, rhs.x);
}
//Clamps Vector2 values to max 
inline void truncate(Vector2 &rhs,double max){
	if (mag(rhs) > max)
	{
		norm(rhs);
		rhs *= max;
	}
}
//Returns inverse (negative) Vector2
inline Vector2 negate(Vector2 const &rhs){
	return Vector2(-rhs.x, -rhs.y);
}
//Returns distance between the Vector2's
inline double distance(Vector2 const&lhs,Vector2 const&rhs){
  double ySeparation = rhs.y - lhs.y;
  double xSeparation = rhs.x - lhs.x;

  return sqrtf(ySeparation*ySeparation + xSeparation*xSeparation);
}
//Returns squared distance between the Vector2's
inline double distanceSquared(Vector2 const&lhs,Vector2 const&rhs){
  double ySeparation = rhs.y - lhs.y;
  double xSeparation = rhs.x - lhs.x;

  return ySeparation*ySeparation + xSeparation*xSeparation;
}
//Returns the lhs Vector2 reflected over the rhs Vector2
inline Vector2 reflect(Vector2 const&lhs,Vector2 const&rhs){
	return lhs+( 2.0 * dot(lhs,rhs) * negate(rhs));
}

//TODO:Vector3 (Namespace)
//Vector3 operands
//Subtracts the two Vector3 objects
inline Vector3 operator-(Vector3 const&lhs,Vector3 const&rhs){
	return Vector3(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z);
}
//Adds the two Vector3 objects
inline Vector3 operator+(Vector3 const&lhs,Vector3 const&rhs){
	return Vector3(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z);
}
//Divides the two Vector3 objects
inline Vector3 operator/(Vector3 const&lhs,float const&rhs){
	return Vector3(lhs.x/rhs,lhs.y/rhs,lhs.z/rhs);
}
//Multiplies the two Vector3 objects
inline Vector3 operator*(Vector3 const &lhs, float rhs){
	Vector3 result;
	result.x=lhs.x * rhs;
	result.y=lhs.y * rhs;
	result.z=lhs.z * rhs;
	return result;
}
//Multiplies the Vector3 object by a float 
inline Vector3 operator*(float lhs,Vector3 const &rhs){
	Vector3 result;
	result.x=rhs.x * lhs;
	result.y=rhs.y * lhs;
	result.z=rhs.z * lhs;
	return result;
}
//Subtracts the two Vector3 objects
inline Vector3& operator-=(Vector3 &lhs,const Vector3 &rhs){
	lhs.x-=rhs.x;
	lhs.y-=rhs.y;
	lhs.z-=rhs.z;
	return lhs;
}
//Adds the two Vector3 objects
inline const Vector3& operator+=(Vector3 &lhs,const Vector3 &rhs){
	lhs.x+=rhs.x;
	lhs.y+=rhs.y;
	lhs.z+=rhs.z;
	return  lhs;
}
//Divides the two Vector3 objects
inline const Vector3& operator/=(Vector3 &lhs,const Vector3 &rhs){
	lhs.x/=rhs.x;
	lhs.y/=rhs.y;
	lhs.z/=rhs.z;
	return  lhs;
}
//Multiplies the two Vector3 objects
inline const Vector3& operator*=(Vector3 &lhs,const Vector3 &rhs){
	lhs.x*=rhs.x;
	lhs.y*=rhs.y;
	lhs.z*=rhs.z;
	return  lhs;
}
//Multiplies the Vector3 object by a float
inline const Vector3& operator*=(Vector3 &lhs,const float &rhs){
	lhs.x*=rhs;
	lhs.y*=rhs;
	lhs.z*=rhs;
	return  lhs;
}
//Returns (true) if the two Vector3 objects are not equal
inline const bool operator!=(Vector3 const&lhs,Vector3 const&rhs){
	return (lhs.x != rhs.x) || (lhs.y != rhs.y)|| (lhs.z != rhs.z);
 }
//Returns (true) if the two Vector3 objects are equal
inline const bool operator==(Vector3 const&lhs,Vector3 const&rhs){
  return (equ(lhs.x, rhs.x) && equ(lhs.y,rhs.y)&& equ(lhs.z,rhs.z) );
  }
//TODO: Vector3 math (Namespace)
//Returns dot product of the two Vector3 objects
inline float dot(Vector3 const&lhs,Vector3 const&rhs){
	return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z;
}
//Returns length squared of the Vector3 object
inline float lsq(Vector3 const&rhs){
	return dot(rhs,rhs);
}
//Returns magnitude (length) of the Vector3 object
inline float mag(Vector3 const &rhs){
	return sqrtf(dot(rhs, rhs));
}
//Returns a normalized Vector3 of the Vector3 object
inline Vector3 norm(Vector3 const &lhs){
	return lhs * (1.f /(mag(lhs)));
}
//Returns cross product of the Vector3 objects
inline Vector3 cross(Vector3 const &lhs, Vector3 const &rhs){
	return Vector3(
		lhs.y * rhs.z-rhs.y * lhs.z,
		-(lhs.x * rhs.z - rhs.x * lhs.z),
		lhs.x * rhs.y -rhs.x * lhs.y);
}
//Returns a perpendcular Vector3 of the Vector3 object
inline const Vector3 perp(Vector3 const &rhs){
	return Vector3(-rhs.z,rhs.x,-rhs.y);//right
}
//Returns distance between the two Vector3 objects
inline double distance(Vector3 const&lhs,Vector3 const&rhs){
  double ySeparation = rhs.y - lhs.y;
  double xSeparation = rhs.x - lhs.x;
  double zSeparation = rhs.z - lhs.z;
  return sqrtf(ySeparation*ySeparation + xSeparation*xSeparation+ zSeparation*zSeparation);
}
//Clamps values of the Vector3 object to max
inline void truncate(Vector3 &rhs,double const& max){
	if (mag(rhs) > max)
	{
		norm(rhs);
		rhs *= max;
	}
}
//Sets values of the Vector3 object to zero
inline void zero(Vector3 &lhs){
	lhs.x=0.0f;
	lhs.y=0.0f;
	lhs.z=0.0f;
}
//Returns (true) if the Vector3 object is zero
inline const bool isZero(Vector3 const&lhs){
	return (lhs.x*lhs.x+lhs.y*lhs.y+lhs.z*lhs.z)<TOL;
}
//Returns negative or positive (value of one)
inline const int sign(const Vector3& lhs,const Vector3& rhs){
	if (lhs.y*rhs.x > lhs.x*rhs.y)
  { 
    return -1;
  }
  else 
  {
    return 1;
  }}
//Returns inverse (negative) of the Vector3 object
inline Vector3 negate(Vector3 const &rhs){
	return Vector3(-rhs.x, -rhs.y,-rhs.z);
}
//Returns distance squared between the two Vector3 objects
inline double distanceSquared(Vector3 const&lhs,Vector3 const&rhs){
  double ySeparation = rhs.y - lhs.y;
  double xSeparation = rhs.x - lhs.x;
  double zSeparation = rhs.z - lhs.z;
  return ySeparation*ySeparation + xSeparation*xSeparation+ zSeparation*zSeparation;
}
//Returns lhs Vector3 reflected over the rhs Vector3 object
inline Vector3 reflect(Vector3 const&lhs,Vector3 const&rhs){
	return lhs+( 2.0 * dot(lhs,rhs) * negate(rhs));
}

//TODO: Vector4 (Namespace)
//Vector4 operands
//Subtracts the Vector4 objects
inline Vector4 operator-(Vector4 const&lhs,Vector4 const&rhs){
	return Vector4(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z,lhs.w-rhs.w);
}
//Adds the Vector4 objects
inline Vector4 operator+(Vector4 const&lhs,Vector4 const&rhs){
	return Vector4(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z,lhs.w+rhs.w);
}
//Divides the Vector4 objects
inline Vector4 operator/(Vector4 const&lhs,float const&rhs){
	return Vector4(lhs.x/rhs,lhs.y/rhs,lhs.z/rhs,lhs.w/rhs);
}
//Multiplies the Vector4 objects
inline Vector4 operator*(Vector4 const &lhs,float rhs){
	Vector4 result;
	result.x=lhs.x * rhs;
	result.y=lhs.y * rhs;
	result.z=lhs.z * rhs;
	return result;
}
//Multiplies the Vector4 object by float
inline Vector4 operator*(float lhs,Vector4 const &rhs){
	Vector4 result;
	result.x=rhs.x * lhs;
	result.y=rhs.y * lhs;
	result.z=rhs.z * lhs;
	return result;
}
//Returns dot product of the Vector4 objects
inline float dot(Vector4 const&lhs,Vector4 const&rhs){
	//return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z;
	return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z+rhs.w*rhs.w;
}
//Returns length squared of the Vector4 object
inline float lsq(Vector4 const&rhs){
	return dot(rhs,rhs);
}
//Returns magnitude (length) of the Vector4 object
inline float mag(Vector4 const &rhs){
	return sqrtf(dot(rhs, rhs));
}
//Returns nomalized Vector4 of the Vector4 object
inline Vector4 norm(Vector4 const &lhs){
	return lhs * (1.f /(mag(lhs)));
}


//TODO: Matrix (Namespace)
//Matrix2x2 operands
//Adds the Matrix2x2 objects
inline Matrix2x2 operator+(Matrix2x2 const&lhs,Matrix2x2 const&rhs){
	return Matrix2x2(lhs.xx+rhs.xx,lhs.xy+rhs.xy,lhs.yx+rhs.yx,lhs.yy+rhs.yy);
}
//Subtracts the Matrix2x2 objects
inline Matrix2x2 operator-(Matrix2x2 const&lhs,Matrix2x2 const&rhs){
	return Matrix2x2(lhs.xx-rhs.xx,lhs.xy-rhs.xy,lhs.yx-rhs.yx,lhs.yy-rhs.yy);
}
//Multiplies the Matrix2x2 objects
inline Matrix2x2 operator*(Matrix2x2 const&lhs,Matrix2x2 const&rhs){
	return Matrix2x2(
		(lhs.xx*rhs.xx)+(lhs.xy*rhs.yx),(lhs.xx*rhs.xy)+(lhs.xy*rhs.yy),
		(lhs.yx*rhs.xx)+(lhs.yy*rhs.yx),(lhs.yx*rhs.xy)+(lhs.yy*rhs.yy));
}
//excess math for matrix2x2
//Returns a rotation Matrix2x2  for theta (degrees)
inline Matrix2x2 rotation2d(float theta){
	float C=cosf(theta);
	float S=sinf(theta);
	return Matrix2x2(C,-S,S,C);
}
//Returns Vector2 multiplied by the Matrix2x2 object
inline Vector2 operator*(Matrix2x2 const&lhs,Vector2 const&rhs){
	//
	return Vector2((lhs.xx*rhs.x)+(lhs.xy*rhs.y),(lhs.yx*rhs.x)+(lhs.yy*rhs.y));
}

//Matric3x3 operands
//Adds the Matrix3x3 objects
inline Matrix3x3 operator+(Matrix3x3 const&lhs,Matrix3x3 const&rhs){
	return Matrix3x3(
		lhs.xx+rhs.xx,lhs.xy+rhs.xy,lhs.xz+rhs.xz,
		lhs.yx+rhs.yx,lhs.yy+rhs.yy,lhs.yz+rhs.yz,
		lhs.zx+rhs.zx,lhs.zy+rhs.zy,lhs.zz+rhs.zz);
}
//Subtracts the Matrix3x3 objects
inline Matrix3x3 operator-(Matrix3x3 const&lhs,Matrix3x3 const&rhs){
	return Matrix3x3(
		lhs.xx-rhs.xx,lhs.xy-rhs.xy,lhs.xz-rhs.xz,
		lhs.yx-rhs.yx,lhs.yy-rhs.yy,lhs.yz-rhs.yz,
		lhs.zx-rhs.zx,lhs.zy-rhs.zy,lhs.zz-rhs.zz);
}
//Multiplies the Matrix3x3 objects
inline Matrix3x3 operator*(Matrix3x3 const&lhs,Matrix3x3 const&rhs){
	return Matrix3x3(
		(lhs.xx*rhs.xx)+(lhs.xy*rhs.yx)+(lhs.xz*rhs.zx),(lhs.xx*rhs.xy)+(lhs.xy*rhs.yy)+(lhs.xz*rhs.zy),(lhs.xx*rhs.xz)+(lhs.xy*rhs.yz)+(lhs.xz*rhs.zz),
		(lhs.yx*rhs.xx)+(lhs.yy*rhs.yx)+(lhs.yz*rhs.zx),(lhs.yx*rhs.xy)+(lhs.yy*rhs.yy)+(lhs.yz*rhs.zy),(lhs.yx*rhs.xz)+(lhs.xy*rhs.yz)+(lhs.yz*rhs.zz),
		(lhs.zx*rhs.xx)+(lhs.zy*rhs.yx)+(lhs.zz*rhs.zx),(lhs.zx*rhs.xy)+(lhs.zy*rhs.yy)+(lhs.zz*rhs.zy),(lhs.zx*rhs.xz)+(lhs.zy*rhs.yz)+(lhs.zz*rhs.zz));
}

//Matric4x4 operands
//Adds the Matrix4x4 objects
inline Matrix4x4 operator+(Matrix4x4 const&lhs,Matrix4x4 const&rhs){
	return Matrix4x4(
		lhs.xx+rhs.xx,lhs.xy+rhs.xy,lhs.xz+rhs.xz,lhs.xw+rhs.xw,
		lhs.yx+rhs.yx,lhs.yy+rhs.yy,lhs.yz+rhs.yz,lhs.yw+rhs.yw,
		lhs.zx+rhs.zx,lhs.zy+rhs.zy,lhs.zz+rhs.zz,lhs.zw+rhs.zw,
		lhs.wx+rhs.wx,lhs.wy+rhs.wy,lhs.wz+rhs.wz,lhs.ww+rhs.ww);
}
//Subtracts the Matrix4x4 objects
inline Matrix4x4 operator-(Matrix4x4 const&lhs,Matrix4x4 const&rhs){
	return Matrix4x4(
		lhs.xx-rhs.xx,lhs.xy-rhs.xy,lhs.xz-rhs.xz,lhs.xw-rhs.xw,
		lhs.yx-rhs.yx,lhs.yy-rhs.yy,lhs.yz-rhs.yz,lhs.yw-rhs.yw,
		lhs.zx-rhs.zx,lhs.zy-rhs.zy,lhs.zz-rhs.zz,lhs.zw-rhs.zw,
		lhs.wx-rhs.wx,lhs.wy-rhs.wy,lhs.wz-rhs.wz,lhs.ww-rhs.ww);
}
//Multiplies the Matrix4x4 objects
inline Matrix4x4 operator*(Matrix4x4 const&lhs,Matrix4x4 const&rhs){
	return Matrix4x4(
		(lhs.xx*rhs.xx)+(lhs.xy*rhs.yx)+(lhs.xz*rhs.zx)+(lhs.xw*rhs.wx),
		(lhs.xx*rhs.xy)+(lhs.xy*rhs.yy)+(lhs.xz*rhs.zy)+(lhs.xw*rhs.wy),
		(lhs.xx*rhs.xz)+(lhs.xy*rhs.yz)+(lhs.xz*rhs.zz)+(lhs.xw*rhs.wz),
		(lhs.xx*rhs.xw)+(lhs.xy*rhs.yw)+(lhs.xz*rhs.zw)+(lhs.xw*rhs.ww),

		(lhs.yx*rhs.xx)+(lhs.yy*rhs.yx)+(lhs.yz*rhs.zx)+(lhs.yw*rhs.wx),
		(lhs.yx*rhs.xy)+(lhs.yy*rhs.yy)+(lhs.yz*rhs.zy)+(lhs.yw*rhs.wy),
		(lhs.yx*rhs.xz)+(lhs.yy*rhs.yz)+(lhs.yz*rhs.zz)+(lhs.yw*rhs.wz),
		(lhs.yx*rhs.xw)+(lhs.yy*rhs.yw)+(lhs.yz*rhs.zw)+(lhs.yw*rhs.ww),

		(lhs.zx*rhs.xx)+(lhs.zy*rhs.yx)+(lhs.zz*rhs.zx)+(lhs.zw*rhs.wx),
		(lhs.zx*rhs.xy)+(lhs.zy*rhs.yy)+(lhs.zz*rhs.zy)+(lhs.zw*rhs.wy),
		(lhs.zx*rhs.xz)+(lhs.zy*rhs.yz)+(lhs.zz*rhs.zz)+(lhs.zw*rhs.wz),
		(lhs.zx*rhs.xw)+(lhs.zy*rhs.yw)+(lhs.zz*rhs.zw)+(lhs.zw*rhs.ww),

		(lhs.wx*rhs.xx)+(lhs.wy*rhs.yx)+(lhs.wz*rhs.zx)+(lhs.ww*rhs.wx),
		(lhs.wx*rhs.xy)+(lhs.wy*rhs.yy)+(lhs.wz*rhs.zy)+(lhs.ww*rhs.wy),
		(lhs.wx*rhs.xz)+(lhs.wy*rhs.yz)+(lhs.wz*rhs.zz)+(lhs.ww*rhs.wz),
		(lhs.wx*rhs.xw)+(lhs.wy*rhs.yw)+(lhs.wz*rhs.zw)+(lhs.ww*rhs.ww));
}
//excess math for matrix4x4
//Calculates the Matrix4x4 "look" from position and orientation
inline Matrix4x4 look(Vector3 const&eye,Vector3 const&target,Vector3 const&up){
	//
	Vector3 zAxis=norm(eye-target);
	Vector3 xAxis=norm(cross(up,zAxis));
	Vector3 yAxis=cross(zAxis,xAxis);
	return Matrix4x4(
		xAxis.x,yAxis.x,zAxis.x,0,
		xAxis.y,yAxis.y,zAxis.y,0,
		xAxis.z,yAxis.z,zAxis.z,0,
		-dot(xAxis,eye),-dot(yAxis,eye),-dot(zAxis,eye),1);
}
//Calculates the Matrix4x4 "perspective" from feild of view, aspect ratio, close, far
inline Matrix4x4 perspective(float fov,float aspect,float znear,float zfar){
	float yScale=::atan(.5*fov);
	float xScale=yScale/aspect;
	return Matrix4x4(
		xScale,0,0,0,
		0,yScale,0,0,
		0,0,zfar/(znear-zfar),-1,
		0,0,znear*zfar/(znear-zfar),0);
}
//Calculates the Matrix4x4 translated by Vector3
inline Matrix4x4 translate(Vector3 const&vec){
	return Matrix4x4(
		1,0,0,0,
		0,1,0,0,
		0,0,1,0,
		vec.x,vec.y,vec.z,1);
}
//Calculates the Matrix4x4 scaled by Vector3
inline Matrix4x4 scale(Vector3 const&vec){
	return Matrix4x4(
		vec.x,0,0,0,
		0,vec.y,0,0,
		0,0,vec.z,0,
		0,0,0,1);
}
//Calculates a rotation Matrix4x4 on X-Axis by theta (degrees)
inline Matrix4x4 rotateX(float thetaX){
	float C=cosf(thetaX);
	float S=sinf(thetaX);
	return Matrix4x4(
		1,0,0,0,
		0,C,-S,0,
		0,S,C,0,
		0,0,0,1);
}
//Calculates a rotation Matrix4x4 on Y-Axis by theta (degrees)
inline Matrix4x4 rotateY(float thetaY){
	float C=cosf(thetaY);
	float S=sinf(thetaY);
	return Matrix4x4(
		C,0,-S,0,
		0,1,0,0,
		S,0,C,0,
		0,0,0,1);
}
//Calculates a rotation Matrix4x4 on Z-Axis by theta (degrees)
inline Matrix4x4 rotateZ(float thetaZ){
	float C=cosf(thetaZ);
	float S=sinf(thetaZ);
	return Matrix4x4(
		C,-S,0,0,
		S,C,0,0,
		0,0,1,0,
		0,0,0,1);
}
//Calculates a rotation Matrix4x4 on all Axis; First Y, Second X, Thrid Z (degrees)
inline Matrix4x4 rotateYXZ(float pitch,float roll, float yaw){
	//x=roll
	//y=pitch
	//z=yaw
	Matrix4x4 temp;
	if(!equ(pitch,0)){
		temp=rotateY(pitch);
	}
	if(!equ(roll,0)){
		temp=temp*rotateX(roll);
	}	
	if(!equ(yaw,0)){
		temp=temp*rotateZ(yaw);
	}
	return temp;
}
//Returns Vector4 of Matrix4x4 multiplied by Vector4
inline Vector4 operator*(Vector4 const& lhs,Matrix4x4 const&rhs){
	return Vector4(
		(lhs.x*rhs.xx)+(lhs.y*rhs.yx)+(lhs.z*rhs.zx)+(lhs.w*rhs.wx),
		(lhs.x*rhs.xy)+(lhs.y*rhs.yy)+(lhs.z*rhs.zy)+(lhs.w*rhs.wy),
		(lhs.x*rhs.xz)+(lhs.y*rhs.yz)+(lhs.z*rhs.zz)+(lhs.w*rhs.wz),
		(lhs.x*rhs.xw)+(lhs.y*rhs.yw)+(lhs.z*rhs.zw)+(lhs.w*rhs.ww));
}
//Returns Vector3 transformed from Matrix4x4 (Vertex)
inline Vector3 transform(Vector3 const&lhs,Matrix4x4 const&rhs){
	Vector4 result=Vector4(lhs.x,lhs.y,lhs.z,1)*rhs;
	float coeff=1/result.w;
	return Vector3(result.x,result.y,result.z)*coeff;
}

//TODO: Quanternion (Namespace)
//Quanterns (still in testing of functionality)
inline Quanterion operator-(Quanterion const&lhs,Quanterion const&rhs){
	return Quanterion(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z,lhs.w-rhs.w);
}
inline Quanterion operator+(Quanterion const&lhs,Quanterion const&rhs){
	return Quanterion(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z,lhs.w+rhs.w);
}
inline Quanterion operator/(Quanterion const&lhs,float const&rhs){
	return Quanterion(lhs.x/rhs,lhs.y/rhs,lhs.z/rhs,lhs.w/rhs);
}
inline Quanterion operator*(Quanterion const &lhs,float rhs){
	Quanterion result;
	result.x=lhs.x * rhs;
	result.y=lhs.y * rhs;
	result.z=lhs.z * rhs;
	return result;
}
inline Quanterion operator*(float lhs,Quanterion const &rhs){
	Quanterion result;
	result.x=rhs.x * lhs;
	result.y=rhs.y * lhs;
	result.z=rhs.z * lhs;
	return result;
}
inline Quanterion operator*(Quanterion const&lhs,Quanterion const&rhs){
	return Quanterion(
		//---
		(lhs.w*rhs.w)-(lhs.x*rhs.x)-(lhs.y*rhs.y)-(lhs.z*rhs.z),
		//++-
		(lhs.w*rhs.w)+(lhs.x*rhs.x)+(lhs.y*rhs.y)-(lhs.z*rhs.z),
		//-++
		(lhs.w*rhs.w)-(lhs.x*rhs.x)+(lhs.y*rhs.y)+(lhs.z*rhs.z),
		//+-+
		(lhs.w*rhs.w)+(lhs.x*rhs.x)-(lhs.y*rhs.y)+(lhs.z*rhs.z));
}
inline float dot(Quanterion const&lhs,Quanterion const&rhs){
	return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z+rhs.w*rhs.w;
}
inline float lsq(Quanterion const&rhs){
	return dot(rhs,rhs);
}
inline float mag(Quanterion const &rhs){
	return sqrtf(dot(rhs, rhs));
}
inline Quanterion norm(Quanterion const &lhs){
	return lhs * (1.0f /(mag(lhs)));
}
inline Quanterion rotate(float const &lhs,Quanterion const &rhs){
	//rotation 
	Quanterion temp(
		cosf( lhs/2),
		rhs.x * sinf( lhs/2 ),
		rhs.y * sinf( lhs/2 ),
		rhs.z * sinf( lhs/2 ));
	//use the overide multiplication
	return temp * rhs;
}



