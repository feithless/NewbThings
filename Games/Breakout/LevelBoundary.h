#pragma once
#include "Excluder.h"

class AARectangle;
class Ball;

class LevelBoundary
{
public:
	LevelBoundary() {}
	LevelBoundary(const AARectangle& boundary);

	bool HasCollided(const Ball& ball, BoundaryEdge& edge);
	inline const AARectangle& GetRectanlge() const { return mIncluder.GetRectangle(); }


private:

	bool HasCollidedWithEdge(const Ball& ball, const BoundaryEdge& edge) const; // Check to see if we collided at all.

	Excluder mIncluder;

};