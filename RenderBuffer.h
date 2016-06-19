#pragma once
#include "VertexBuffer.h"
#include "CommonHeaders.h"
#include "TransformationMatrixes.h"

//Changed RendeBuffer into RenderHandle made to control all buffer types with templates.
class RenderBuffer : public VertexBuffer
{
private: 
	Vector3 rotations;
	Vector3 transformation; 
	
public:
	RenderBuffer(int size);
	RenderBuffer(Vector3 * ptr, int size);
	~RenderBuffer();
	
	inline void setRotations(float xrotate, float yrotate, float zrotate){ rotations.SetValue(0,xrotate); rotations.SetValue(1,yrotate); rotations.SetValue(2,zrotate); }
	inline void setTransformation(Vector3 transform){ transformation = transform; }
	inline Vector3 getRotation(){ return rotations; }
	inline Vector3 getTransformation(){ return transformation; }
	
	void moveForward(float step);
	void moveBackward(float step);
	void moveLeft(float step);
	void moveRight(float step);
	void moveUp(float step);
	void moveDown(float step);

	void rotateRight(float step);
	void rotateLeft(float step);
	void rotateDown(float step);
	void rotateUp(float step);

	RenderBuffer operator = (VertexBuffer buffer);
};