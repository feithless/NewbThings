#include "Paddle.h"
#include "../../Graphics/Screen.h"
#include "../../Utils/Utils.h"
#include "BoundaryEdge.h"
#include "Ball.h"
#include <cassert>
#include <stdlib.h>

void Paddle::Init(const AARectangle& rect, const AARectangle& boundary, const Ellipse& bouncy)
{
	Excluder::Init(rect);
	mBoundary = boundary;
	mDirection = 0;
	mEllipse = bouncy;
}

void Paddle::Update(uint32_t dt, Ball& ball)
{
	if (GetRectangle().ContainsPoint(ball.GetPosition()))
	{
		Vec2D pointOnEdge;
		ball.MakeFlushWithEdge(GetEdge(BOTTOM_EDGE), pointOnEdge, true);
	}
	if (mDirection != 0)
	{
		Vec2D dir = RIGHT_DIR;
		if ((mDirection & PaddleDirection::LEFT) == PaddleDirection::LEFT && (mDirection & PaddleDirection::RIGHT) == PaddleDirection::RIGHT)
		{
			dir = Vec2D::Zero;
		}
		else if (mDirection == PaddleDirection::LEFT)
		{
			dir = LEFT_DIR;
		}

		Vec2D dx = dir * VELOCITY * MillisecondsToSeconds(dt);

		MoveBy(dx);

		const AARectangle& aaRect = GetRectangle();

		if (IsGreaterThanOrEqual(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetX()))
		{
			MoveTo(Vec2D(mBoundary.GetTopLeftPoint().GetX(), aaRect.GetTopLeftPoint().GetY()));
		}
		else if (IsGreaterThanOrEqual(aaRect.GetBottomRightPoint().GetX(), mBoundary.GetBottomRightPoint().GetX()))
		{
			MoveTo(Vec2D(mBoundary.GetBottomRightPoint().GetX() - aaRect.GetWidth(), aaRect.GetTopLeftPoint().GetY()));
		}
		mEllipse.MoveTo(mBoundary.GetCenterPoint());
	}
}

void Paddle::Draw(Screen& screen)
{
	screen.Draw(GetRectangle(), Color::Blue(), true, Color::Blue());
}

bool Paddle::Bounce(Ball& ball)
{
	BoundaryEdge edge;
	std::cout << "x: " << ball.GetVelocity().GetX() << " y: " << ball.GetVelocity().GetY();
	std::cout.seekp(0);
	if (HasCollided(ball.GetBoundingRect(), edge))
	{
		Vec2D pointOnEdge;
		ball.MakeFlushWithEdge(edge, pointOnEdge, true);

		if (edge.edge == GetEdge(TOP_EDGE).edge)
		{
			float edgeLength = edge.edge.Length();
			assert(!IsEqual(edgeLength, 0));

			float tx = (pointOnEdge.GetX() - edge.edge.GetP0().GetX()) / edgeLength;
			// float angle = (ball.GetPosition().AngleBetween(ball.GetVelocity()));// *180;
			//float ty = (sinf(2 * tx * PI - 1.59f)) / 2 - .5;		
			// '2 *' && '- 1.59f' brings the 0->1 from tx to reflect a -1 to 0 to -1 value...
			// This doesn't work... Hmm.
			//Vec2D testing = { ball.GetVelocity() };

			

			//ball.SetVelocity(ball.GetVelocity() * ty);

			if (((tx <= CORNER_BOUNCE_AMT) && ball.GetVelocity().GetX() > 0) ||
				((tx >= 1.0f - CORNER_BOUNCE_AMT) && ball.GetVelocity().GetX() < 0))
			{
				ball.SetVelocity(-ball.GetVelocity());
				return true;
			}
		}
		ball.SetVelocity(ball.GetVelocity().Reflect(edge.normal));
		return true;
	}

	return false;
}
