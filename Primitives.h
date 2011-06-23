#pragma once
#include "Mesh.h"
//2d
namespace triangle
{
	int const vertexCount=3;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(-1,-1,0),
		Mesh::Vertex(1,-1,0),
		Mesh::Vertex(0,1,0),
	};
	int const indexCount=3;
	int const indicies[]={0,1,2};
}
namespace quad
{
	int const vertexCount=4;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(-1,-1,0),
		Mesh::Vertex(1,-1,0),
		Mesh::Vertex(-1,1,0),
		Mesh::Vertex(1,1,0)
	};
	int const indexCount=6;
	int const indicies[]={
		0,1,2,
		3,2,1};
}
namespace circle
{
	int const vertexCount=8;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(-1,0,0),
		Mesh::Vertex(-.707,-.707,0),
		Mesh::Vertex(0,-1,0),
		Mesh::Vertex(.707,-.707,0),
		Mesh::Vertex(1,0,0),
		Mesh::Vertex(.707,.707,0),
		Mesh::Vertex(0,1,0),
		Mesh::Vertex(-.707,.707,0)
	};
	int const indexCount=18;
	int const indicies[]={
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7};
}

//3d
namespace pyramid
{
	int const vertexCount=5;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(1,1,-1),
		Mesh::Vertex(-1,1,-1),
		Mesh::Vertex(1,-1,-1),
		Mesh::Vertex(-1,-1,-1),
		Mesh::Vertex(0,0,1)
	};
	int const indexCount=18;
	int const indicies[]={
		0,1,2,
		1,2,3,
		0,1,4,
		1,3,4,
		2,3,4,
		0,2,4};
}
namespace cube
{
	int const vertexCount=8;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(1,-1,-1),
		Mesh::Vertex(1,1,-1),
		Mesh::Vertex(-1,1,-1),
		Mesh::Vertex(-1,-1,-1),
		Mesh::Vertex(1,-1,1),
		Mesh::Vertex(1,1,1),
		Mesh::Vertex(-1,1,1),
		Mesh::Vertex(-1,-1,1)
	};
	int const indexCount=36;
	int const indicies[]={
		0,3,1,
		3,2,1,
		0,4,1,
		1,4,5,
		1,5,2,
		2,5,6,
		6,3,2,
		3,6,7,
		0,3,7,
		7,4,0,
		4,7,5,
		7,6,5};
}
namespace cylinder
{
	int const vertexCount=16;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(-1,0,-1),
		Mesh::Vertex(-.707,-.707,-1),
		Mesh::Vertex(0,-1,-1),
		Mesh::Vertex(.707,-.707,-1),
		Mesh::Vertex(1,0,-1),
		Mesh::Vertex(.707,.707,-1),
		Mesh::Vertex(0,1,-1),
		Mesh::Vertex(-.707,.707,-1),
		Mesh::Vertex(-1,0,1),
		Mesh::Vertex(-.707,-.707,1),
		Mesh::Vertex(0,-1,1),
		Mesh::Vertex(.707,-.707,1),
		Mesh::Vertex(1,0,1),
		Mesh::Vertex(.707,.707,1),
		Mesh::Vertex(0,1,1),
		Mesh::Vertex(-.707,.707,1)
	};
	int const indexCount=84;
	int const indicies[]={
		//bottom
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7,
		//top
		8,9,10,
		8,10,11,
		8,11,12,
		8,12,13,
		8,13,14,
		8,14,15,
		//sides
		0,1,8,
		1,8,9,
		1,2,9,
		2,9,10,
		2,3,10,
		3,10,11,
		3,4,11,
		4,11,12,
		4,5,12,
		5,12,13,
		5,6,13,
		6,13,14,
		6,7,14,
		7,14,15,
		7,0,15,
		0,15,8};
}
namespace cone
{
	int const vertexCount=9;
	Mesh::Vertex const verticies[]={
		Mesh::Vertex(-1,0,-1),
		Mesh::Vertex(-.707,-.707,-1),
		Mesh::Vertex(0,-1,-1),
		Mesh::Vertex(.707,-.707,-1),
		Mesh::Vertex(1,0,-1),
		Mesh::Vertex(.707,.707,-1),
		Mesh::Vertex(0,1,-1),
		Mesh::Vertex(-.707,.707,-1),
		Mesh::Vertex(0,0,1)
	};
	int const indexCount=40;
	int const indicies[]={
		//bottom
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7,
		0,7,1,
		//sides
		0,1,8,
		0,2,8,
		0,3,8,
		0,4,8,
		0,5,8,
		0,6,8,
		0,7,8};
}
namespace torus
{
	int const vertexCount=32;
	Mesh::Vertex const verticies[]={
		//top
		Mesh::Vertex(0,1,0),
		Mesh::Vertex(0,1.293,-.707),
		Mesh::Vertex(0,1,2),
		Mesh::Vertex(0,2.707,-.707),
		Mesh::Vertex(0,3,0),
		Mesh::Vertex(0,2.707,.707),
		Mesh::Vertex(0,3,0),
		Mesh::Vertex(0,1.293,.707),
		//left
		Mesh::Vertex(-3,0,0),
		Mesh::Vertex(-2.707,-.707,0),
		Mesh::Vertex(-2,-1,0),
		Mesh::Vertex(-1.293,-.707,0),
		Mesh::Vertex(-1,0,0),
		Mesh::Vertex(-1.293,.707,0),
		Mesh::Vertex(-2,1,0),
		Mesh::Vertex(-2.707,.707,0),
		//bottom
		Mesh::Vertex(0,-3,0),
		Mesh::Vertex(0,-2.707,-.707),
		Mesh::Vertex(0,-2,-1),
		Mesh::Vertex(0,-1.293,-.707),
		Mesh::Vertex(0,-1,0),
		Mesh::Vertex(0,-1.293,.707),
		Mesh::Vertex(0,-2,1),
		Mesh::Vertex(0,-2.707,.707),
		//right
		Mesh::Vertex(1,0,0),
		Mesh::Vertex(1.293,-.707,0),
		Mesh::Vertex(2,-1,0),
		Mesh::Vertex(2.707,-.707,0),
		Mesh::Vertex(3,0,0),
		Mesh::Vertex(2.707,.707,0),
		Mesh::Vertex(2,1,0),
		Mesh::Vertex(1.293,.707,0)

	};
	int const indexCount=64;
	int const indicies[]={
		//top to left
		0,1,8,
		1,2,9,
		2,3,10,
		3,4,11,
		4,5,12,
		5,6,13,
		6,7,14,
		7,0,15,
		//left to top
		0,9,8,
		1,10,9,
		2,11,10,
		3,12,11,
		4,13,12,
		5,14,13,
		6,15,14,
		7,8,15,
		//left to bottom
		16,9,8,
		17,10,9,
		18,11,10,
		19,12,11,
		20,13,12,
		21,14,13,
		22,15,14,
		23,8,15,
		//bottom to left
		16,17,8,
		17,18,9,
		18,19,10,
		19,20,11,
		20,21,12,
		21,22,13,
		22,23,14,
		23,16,15,
		//bottom to right
		16,17,24,
		17,18,25,
		18,19,26,
		19,20,27,
		20,21,28,
		21,22,29,
		22,23,30,
		23,16,31,
		//right to bottom
		16,25,24,
		17,26,25,
		18,27,26,
		19,28,27,
		20,29,28,
		21,30,29,
		22,31,30,
		23,24,31,
		//right to top
		0,25,24,
		1,26,25,
		2,27,26,
		3,28,27,
		4,29,28,
		5,30,29,
		6,31,30,
		7,24,31,
		//top to right
		0,1,24,
		1,2,25,
		2,3,26,
		3,4,27,
		4,5,28,
		5,6,29,
		6,7,30,
		7,0,31};
}
namespace sphere
{
	int const vertexCount=26;
	Mesh::Vertex const verticies[]={
		//bottom
		Mesh::Vertex(0,0,-1),
		//bottom row
		Mesh::Vertex(-1,0,-.5),
		Mesh::Vertex(-.707,-.707,-.5),
		Mesh::Vertex(0,-1,-.5),
		Mesh::Vertex(.707,-.707,-.5),
		Mesh::Vertex(1,0,-.5),
		Mesh::Vertex(.707,.707,-.5),
		Mesh::Vertex(0,1,-.5),
		Mesh::Vertex(-.707,.707,-.5),
		//middle
		Mesh::Vertex(-1,0,0),
		Mesh::Vertex(-.707,-.707,0),
		Mesh::Vertex(0,-1,0),
		Mesh::Vertex(.707,-.707,0),
		Mesh::Vertex(1,0,0),
		Mesh::Vertex(.707,.707,0),
		Mesh::Vertex(0,1,0),
		Mesh::Vertex(-.707,.707,0),
		//top row
		Mesh::Vertex(-1,0,.5),
		Mesh::Vertex(-.707,-.707,.5),
		Mesh::Vertex(0,-1,.5),
		Mesh::Vertex(.707,-.707,.5),
		Mesh::Vertex(1,0,.5),
		Mesh::Vertex(.707,.707,.5),
		Mesh::Vertex(0,1,.5),
		Mesh::Vertex(-.707,.707,.5),
		//top
		Mesh::Vertex(0,0,1),
	};
	int const indexCount=96;
	int const indicies[]={
		//bottom row 1
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7,
		0,7,8,
		0,8,1,
		// bottom row 2
		9,1,2,
		10,2,3,
		11,3,4,
		12,4,5,
		13,5,6,
		14,6,7,
		15,7,8,
		16,8,9,
		// top row 2
		9,10,17,
		10,11,18,
		11,12,19,
		12,13,20,
		13,14,21,
		14,15,22,
		15,16,23,
		16,17,24,
		// top row 1
		25,16,17,
		25,17,18,
		25,18,19,
		25,19,20,
		25,20,21,
		25,21,22,
		25,22,23,
		25,23,24,
		25,24,16
		};
}
//Easy Accessors
class Primitive{
private:
	Primitive(){}
	virtual ~Primitive(){}
public:
	static Mesh Triangle(){
		return Mesh(triangle::verticies,triangle::vertexCount,triangle::indicies,triangle::indexCount);
	}
	static Mesh Quad(){
		return Mesh(quad::verticies,quad::vertexCount,quad::indicies,quad::indexCount);
	}
	static Mesh Circle(){
		return Mesh(circle::verticies,circle::vertexCount,circle::indicies,circle::indexCount);
	}
	static Mesh Cube(){
		return Mesh(cube::verticies,cube::vertexCount,cube::indicies,cube::indexCount);
	}
	static Mesh Cone(){
		return Mesh(cone::verticies,cone::vertexCount,cone::indicies,cone::indexCount);
	}
	static Mesh Pyramid(){
		return Mesh(pyramid::verticies,pyramid::vertexCount,pyramid::indicies,pyramid::indexCount);
	}
	static Mesh Sphere(){
		return Mesh(sphere::verticies,sphere::vertexCount,sphere::indicies,sphere::indexCount);
	}
	static Mesh Torus(){
		return Mesh(torus::verticies,torus::vertexCount,torus::indicies,torus::indexCount);
	}
};


