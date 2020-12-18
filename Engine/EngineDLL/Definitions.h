#pragma once
#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define CUBE_VERTEX   8
#define FULL_ROTATION                      360.0f

enum  Layers
{
	player = 0,
	enemy,
	map,
	Tiles,
	count

};
enum ProjectionMatrixType 
{
	perspective =0,
	orthographic

};

enum States
{
	INSIDE = 0,
	OUTSIDE

};

enum Planes {
	TOP = 0,
	BOTTOM,
	LEFT,
	RIGHT,
	NEARP,
	FARP,
	COUNT
};
#endif 
