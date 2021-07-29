#include "Shape.h"



void Shape::MoveTo(const Vec2D& p)
{
	Vec2D center = GetCenterPoint();
	if (center == p)
		return;
	for (Vec2D& vec : mPoints)
	{
		vec.SetX(vec.GetX() + (center.GetX() - p.GetX()));
		vec.SetY(vec.GetY() + (center.GetY() - p.GetY()));
	}
}

void Shape::MoveBy(const Vec2D& deltaOffset)
{
	for (Vec2D point : mPoints)
	{
		point = point + deltaOffset;
	}
}
