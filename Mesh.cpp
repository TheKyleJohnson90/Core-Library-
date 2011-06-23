#pragma once
#include "Mesh.h"

//mesh
Mesh::Mesh(Vertex const*verticies,int vertexCount,int const*indicies,int indexCount){
	clear();
	for(int i=0;i<vertexCount;i++){
		addVertex(verticies[i]);
	}
	for(int i=0;i<indexCount;i+=3){
		addPrimative(indicies[i],indicies[i+1],indicies[i+2]);
	}
}
Mesh::~Mesh(){
	//
}