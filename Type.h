#pragma once

//
// Telegram
// (struct template)
// ----------
// + sender : int
// + reciever : int
// + msg : int
// + dispatchTime : double
// + extraInfo : void*
// ----------
//
struct Telegram{
	int sender;
	int reciever;
	int msg;
	double dispatchTime;
	void* extraInfo;
};
//
// Vector2
// (struct template)
// ----------
// + x : float
// + y : float
// + Vector2()
// + Vector2(float, float)
// ----------
//
struct Vector2{
	float x,y;
	Vector2():x(0),y(0){}
	Vector2(float const&newX,float const&newY):x(newX),y(newY){}
};
//
// Vector3
// (struct template)
// ----------
// + x : float
// + y : float
// + z : float
// + Vector3()
// + Vector3(float, float,float)
// ----------
//
struct Vector3{
	float x,y,z;
	Vector3():x(0),y(0),z(0){}
	Vector3(float const&newX,float const&newY,float const&newZ):x(newX),y(newY),z(newZ){}
	float mag(Vector3 const &rhs);
	float dot(Vector3 const &lhs, Vector3 const &rhs);
	float lsq(Vector3 const&rhs);
	Vector3 norm(Vector3 const &lhs);
	Vector3 cross(Vector3 const &lhs, Vector3 const &rhs);
	//Perp?
};
//
// Vector4
// (struct template)
// ----------
// + x : float
// + y : float
// + z : float
// + w : float
// + Vector4()
// + Vector4(float,float, float,float)
// ----------
//
struct Vector4{
	float x,y,z,w;
	Vector4():x(0),y(0),z(0),w(0){}
	Vector4(float const&newX,float const&newY,float const&newZ,float const&newW):x(newX),y(newY),z(newZ),w(newW){}
	float mag(Vector4 const &rhs);
	float dot(Vector4 const &lhs, Vector4 const &rhs);
	float lsq(Vector4 const&rhs);
	Vector4 norm(Vector4 const &lhs);
};
//
// Line
// (struct template)
// ----------
// + m : float
// + b : float
// + Line()
// + Line(float,float)
// + Line(float,float, float,float)
// ----------
// + compute : void 
// + compute : void 
// + setM : void 
// + setB : void 
// + getM : float
// + getB : float
// + getX : float
// + getY : float 
// ----------
//
struct Line{
	float M,B;
	Line();
	Line(float const&newM,float const&newB);
	Line(Vector2 const&V1,Vector2 const&V2);
	Line(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo);
	//Excess
	void compute(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo);
	void compute(Vector2 const&V1,Vector2 const&V2);
	void setM(float const&newM);
	void setB(float const&newB);
	float getY(float const&X);
	float getX(float const&Y);
	float getM();
	float getB();
};
//
// Circle
// (struct template)
// ----------
// + vec : Vector2
// + r : float
// + Circle()
// + circle(float,Vector2)
// ----------
// + set(Vector2) : void 
// + set(float) : void 
// + set(float, Vector2) : float
// + set(int, Vector2) : float
// + get(Vector2) : float
// + get(float) : float 
// + get(float,Vector2) : void 
// + get(float,float) : void 
// ----------
//
struct Circle{
	Vector2 vec;
	float r;
	Circle():r(0),vec(Vector2()){}
	Circle(float const&newR,Vector2 const&newVec):r(newR),vec(newVec){}
	//Excess
	void set(Vector2 const&newVec);
	void set(float const&newR);
	void set(float const&newR,Vector2 const&newVec);
	void set(int count,Vector2 const*vertices);
	void get(Vector2 &newVec) const;
	void get(float &newR) const;
	void get(float &newR,Vector2 &newVec) const;
	void get(float &newX,float &newY) const ;
};
//
// Sphere
// (struct template)
// ----------
// + vec : Vector3
// + r : float
// + Sphere()
// + Sphere(float,Vector3)
// ----------
// + set(Vector3) : void 
// + set(float) : void 
// + set(float, Vector3) : float
// + set(int, Vector3) : float
// + get(Vector3) : float
// + get(float) : float 
// + get(float,Vector3) : void 
// + get(float,float,float) : void 
// ----------
//
struct Sphere{
	Vector3 vec;
	float r;
	Sphere():r(0),vec(Vector3()){}
	Sphere(float const&newR,Vector3 const&newVec):r(newR),vec(newVec){}
	//Excess
	void set(Vector3 const&newVec);
	void set(float const&newR);
	void set(float const&newR,Vector3 const&newVec);
	void set(int count,Vector3 const*vertices);;
	void get(Vector3 &newVec) const;
	void get(float &newR) const;
	void get(float &newR,Vector3 &newVec) const;
	void get(float &newX,float &newY,float &newZ) const ;
};
//
// Plane
// (struct template)
// ----------
// + normal : Vector3
// + d : float
// + Plane()
// + Plane(Vector3,float)
// + Plane(Vector3, Vector3, Vector3)
// ----------
//
struct Plane{
	Vector3 normal;
	float d;
	Plane();
	Plane(Vector3 const&,float);
	Plane(Vector3 const&a,Vector3 const&b,Vector3 const&c);
};
//
// Vertex
// (struct template)
// ----------
// + normal : Vector3
// + position : Vector3
// + texcoord : Vector2
// + color : int
// + Vertex()
// + Vertex(int, Vector3, Vector3,Vector2)
// ----------
//
struct Vertex{
	Vector3 position;
	Vector2 texcoord;
	Vector3 normal;
	unsigned int color;//bits per each value of color
	//shader class as well
	Vertex();
	Vertex(unsigned int const&newColor,Vector3 const&newPosition,Vector3 const&newNormal,Vector2 const&newTex);
};
//
// Matrix2x2
// (struct template)
// ----------
// + xx : float
// + xy : float
// + yx : float
// + yy : float
// + Matrix2x2()
// + Matrix2x2(float,float,float,float)
// ----------
//
struct Matrix2x2{
	float xx,xy;
	float yx,yy;
	Matrix2x2():xx(1),xy(0),yx(0),yy(1){}
	Matrix2x2(float const&newXX,float const&newXY,float const&newYX,float const&newYY):xx(newXX),xy(newXY),yx(newYX),yy(newYY){}
};
//
// Matrix3x3
// (struct template)
// ----------
// + xx : float
// + xy : float
// + yx : float
// + yy : float
// + yz : float
// + xz : float
// + zy : float
// + zx : float
// + zz : float
// + Matrix3x3()
// + Matrix3x3(float,float,float,floatfloat,float,float,float,float)
// ----------
//
struct Matrix3x3{
	float xx,xy,xz;
	float yx,yy,yz;
	float zx,zy,zz;
	Matrix3x3():xx(1),xy(0),xz(0),yx(0),yy(1),yz(0),zx(0),zy(0),zz(1){}
	Matrix3x3(float const&newXX,float const&newXY,float const&newXZ,float const&newYX,float const&newYY,float const&newYZ,float const&newZX,float const&newZY,float const&newZZ)
		:xx(newXX),xy(newXY),xz(newXZ),yx(newYX),yy(newYY),yz(newYZ),zx(newZX),zy(newZY),zz(newZZ){}
};
//
// Matrix4x4
// (struct template)
// ----------
// + xx : float
// + xy : float
// + yx : float
// + yy : float
// + yz : float
// + xz : float
// + zy : float
// + zx : float
// + zz : float
// + wy : float
// + wx : float
// + wz : float
// + ww : float
// + zw : float
// + xw : float
// + yw : float
// + Matrix4x4()
// + Matrix4x4(float,float,float,floatfloat,float,float,float,float,float,float,float,floatfloat,float,float)
// ----------
//
struct Matrix4x4{
	float xx,xy,xz,xw;
	float yx,yy,yz,yw;
	float zx,zy,zz,zw;
	float wx,wy,wz,ww;
	Matrix4x4():xx(1),xy(0),xz(0),xw(0),yx(0),yy(1),yz(0),yw(0),zx(0),zy(0),zz(1),zw(0),wx(0),wy(0),wz(0),ww(1){}
	Matrix4x4(float const&newXX,float const&newXY,float const&newXZ,float const&newXW,float const&newYX,float const&newYY,float const&newYZ,float const&newYW,float const&newZX,float const&newZY,float const&newZZ,float const&newZW,float const&newWX,float const&newWY,float const&newWZ,float const&newWW)
		:xx(newXX),xy(newXY),xz(newXZ),xw(newXW),yx(newYX),yy(newYY),yz(newYZ),yw(newYW),zx(newZX),zy(newZY),zz(newZZ),zw(newZW),wx(newWX),wy(newWY),wz(newWZ),ww(newWW){}
};
//
// Quanterion
// (struct template)
// ----------
// + w : float
// + x : float
// + y : float
// + z : float
// + Quanterion()
// + Quanterion(float,float, float,float)
// ----------
//
struct Quanterion{
	float w,x,y,z;
	Quanterion():w(0),x(0),y(0),z(0){}
	Quanterion(float const&newW,float const&newX,float const&newY,float const&newZ):w(newW),x(newX),y(newY),z(newZ){}
	float mag(Quanterion const &rhs);
	float dot(Quanterion const &lhs, Quanterion const &rhs);
	float lsq(Quanterion const&rhs);
	Quanterion norm(Quanterion const &lhs);
	Quanterion rotate(float const&lhs,Quanterion const &rhs);
};





