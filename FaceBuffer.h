#pragma once
#include "Triangle.h"
#include "TransformationMatrixes.h"
#include "Matrix.h"
class FaceBuffer
{
	//i made the valus public for cuda to work FIX LATER
private:
	Triangle * values;
	int taken; //allocated size
	int size;
	Vector3 transformation;
	Vector3 rotations;

public:
	FaceBuffer();
	FaceBuffer(int size);
	FaceBuffer(int size, int taken, Triangle * ptr);
	~FaceBuffer();

	void setValues(Triangle * ptr, int stopAt);
	void setValue(int pos, Triangle &t);
	void setSize(int size);
	void setTaken(int t);
	Triangle* getValues();
	Triangle getValue(int pos);
	int getSize();
	int getTaken();
	void increaseTaken(int t);
	void increaseSize(int s);
	bool addTriangle(Triangle &t); //return false if fails

	void createCube(float sizein, Vector3 &center, int bufferPos);
	void TransforMatrix(Matrix &m);

	inline void setRotations(float xrotate, float yrotate, float zrotate){ rotations.SetValue(0, xrotate); rotations.SetValue(1, yrotate); rotations.SetValue(2, zrotate); }
	inline void setTransformation(Vector3 &transform){ transformation = transform; }
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
};

