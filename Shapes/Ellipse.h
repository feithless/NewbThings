#pragma once
#include "Shape.h"

class Ellipse : public Shape
{
public:
	Ellipse();
	Ellipse(const Vec2D& center, float minorRadius, float majorRadius);

	// Inherited via Shape
	inline virtual Vec2D GetCenterPoint() const override { return mPoints[0]; }
	inline float GetMinorRadius() const { return mMinorAxis; }
	inline float GetMajorRadius() const { return mMajorAxis; }
	inline void SetMinorRadius(float minRadius) { mMinorAxis = minRadius; }
	inline void SetMajorRadius(float majRadius) { mMajorAxis = majRadius; }
	inline void MoveTo(const Vec2D& position) { mPoints[0] = position; }

	bool Intersects(const Ellipse& otherEllipse) const;
	bool ContainsPoint(const Vec2D& point) const;

	Vec2D GetFociPoint0() const;
	Vec2D GetFociPoint1() const;

	Vec2D GetIntercept(const float& xIntercept) const;
	float GetYIntercept(const float& xIntercept) const;

	Vec2D GetNormalVector(const float& xIntercept) const;

private:
	float mMinorAxis;
	float mMajorAxis;

	// Elipse points are calculated as thus:
	// (((x - center.x)^2) / minorAxis^2) + (((y - center.y) ^ 2) / majorAxis^2 ) = 1
	// cicles are x^2+y^2 = radius
};

