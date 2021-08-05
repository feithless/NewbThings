#include "Ellipse.h"
#include "../Utils/Vec2D.h"
#include <cmath>


Ellipse::Ellipse() : Ellipse(Vec2D::Zero, 0, 0)
{
}

Ellipse::Ellipse(const Vec2D& center, float minorRadius, float majorRadius) : mMinorAxis(minorRadius), mMajorAxis(majorRadius)
{
	mPoints.push_back(center);
}

bool Ellipse::Intersects(const Ellipse& otherEllipse) const
{
	//NYI
	return false;
}

bool Ellipse::ContainsPoint(const Vec2D& point) const
{
	// NYI
	return false;
}

Vec2D Ellipse::GetFociPoint0() const
{
	return Vec2D();
}

Vec2D Ellipse::GetFociPoint1() const
{
	return Vec2D();
}

Vec2D Ellipse::GetIntercept(const float& xIntercept) const
{
	return Vec2D( xIntercept, GetYIntercept(xIntercept));
}

float Ellipse::GetYIntercept(const float& xIntercept) const
{
	float outbound = (mMinorAxis * sqrt(pow(mMajorAxis, 2))) / mMajorAxis;
	return outbound;
}

Vec2D Ellipse::GetNormalVector(const float& xIntercept) const
{
	Vec2D interceptVector(GetIntercept(xIntercept));

	Vec2D normalVector = { Vec2D::Zero };

	normalVector.SetX(
		interceptVector.GetY() + ((pow(mMajorAxis, 2) * interceptVector.GetX()) / (pow(mMinorAxis, 2) * interceptVector.GetY())) * (mPoints[0].GetX() - interceptVector.GetX())
	);
	normalVector.SetY(
		interceptVector.GetX() + ((pow(double(mMajorAxis), 2.0) * interceptVector.GetY()) / (pow(mMinorAxis, 2) * interceptVector.GetX())) * (mPoints[0].GetY() - interceptVector.GetY())
	);

	return normalVector;
}
