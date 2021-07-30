#include "Knight.h"

#include "../Chess.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Color.h"
#include "../../Shapes/AARectangle.h"
#include "../../Shapes/Line2D.h"
#include "../../Shapes/Triangle.h"


Knight::Knight()
{
}

void Knight::Init(Vec2D offset, int pieceNum, bool isWhite)
{
	mPosition = offset;
	mPieceNum = pieceNum;
	mIsWhite = isWhite;
	if (mIsWhite)
	{
		mCFill = Color::White();
		mCOutline = Color::Black();
	}
	else
	{
		mCFill = Color::Black();
		mCOutline = Color::White();
	}
	mIsAlive = true;
	mUnit = PieceType::ptKnight;
}

void Knight::Update(uint32_t dt) const
{
}

void Knight::Draw(Screen& screen) const
{
	float xOffset = 155 + (75.075 * mPosition.GetX());
	float yOffset = 155 + (75.075 * mPosition.GetY());
	float xChar = 37.5 * .105;
	float yChar = 50 * .105;
	float maxXOffset = xOffset + (xChar * 16);
	float maxYOffset = yOffset + (yChar * 12);

	// This is the base
	AARectangle base(Vec2D(xOffset, maxYOffset - yChar), Vec2D(maxXOffset, maxYOffset));
	screen.Draw(base, mCFill, true, mCFill);

	base.SetTopLeftPoint(Vec2D(xOffset + xChar, maxYOffset - (yChar * 2)));
	base.SetBottomRightPoint(Vec2D(maxXOffset - xChar, maxYOffset - yChar));
	screen.Draw(base, mCFill, true, mCFill);

	Triangle t1(
		Vec2D(xOffset, yOffset + (yChar * 11)),
		Vec2D(xOffset + xChar, yOffset + (yChar * 11)),
		Vec2D(xOffset + xChar, yOffset + (yChar * 10))
	);
	Triangle t2(
		Vec2D(maxXOffset - xChar, maxYOffset - yChar),
		Vec2D(maxXOffset - xChar, maxYOffset - yChar * 2),
		Vec2D(maxXOffset, maxYOffset - yChar)
	);
	screen.Draw(t1, mCFill, true, mCFill);
	screen.Draw(t2, mCFill, true, mCFill);

	base.SetTopLeftPoint(Vec2D(xOffset + (xChar * 4), maxYOffset - (yChar * 5)));
	base.SetBottomRightPoint(Vec2D(maxXOffset - (xChar * 5), maxYOffset - (yChar * 2)));
	screen.Draw(base, mCFill, true, mCFill);

	// This is the start of the body's drawing
	t1.SetP0(Vec2D(xOffset + (xChar * 4), maxYOffset - (yChar * 3)));
	t1.SetP1(Vec2D(xOffset + (xChar * 2), maxYOffset - (yChar * 5)));
	t1.SetP2(Vec2D(xOffset + (xChar * 4), maxYOffset - (yChar * 5)));
	screen.Draw(t1, mCFill, true, mCFill);

	t2.SetP0(Vec2D(maxXOffset - (xChar * 5), maxYOffset - (yChar * 3)));
	t2.SetP1(Vec2D(maxXOffset - (xChar * 5), maxYOffset - (yChar * 4)));
	t2.SetP2(Vec2D(maxXOffset - (xChar * 4), maxYOffset - (yChar * 4)));
	screen.Draw(t2, mCFill, true, mCFill);

	base.SetTopLeftPoint(Vec2D(maxXOffset - (xChar * 5), maxYOffset - (yChar * 5)));
	base.SetBottomRightPoint(Vec2D(maxXOffset - (xChar * 4), maxYOffset - (yChar * 4)));
	screen.Draw(base, mCFill, true, mCFill);

	t2.SetP0(Vec2D(maxXOffset - (xChar * 5), maxYOffset - (yChar * 3)));
	t2.SetP1(Vec2D(maxXOffset - (xChar * 5), maxYOffset - (yChar * 4)));
	t2.SetP2(Vec2D(maxXOffset - (xChar * 4), maxYOffset - (yChar * 4)));
	screen.Draw(t2, mCFill, true, mCFill);

	t2.SetP0(Vec2D(maxXOffset - (xChar * 4), maxYOffset - (yChar * 5)));
	t2.SetP1(Vec2D(maxXOffset - (xChar * 8), maxYOffset - (yChar * 8)));
	t2.SetP2(Vec2D(maxXOffset - (xChar * 8), maxYOffset - (yChar * 5)));
	screen.Draw(t2, mCFill, true, mCFill);
	
	// Start of head 
	base.SetTopLeftPoint(Vec2D(xOffset + (xChar * 2), yOffset + (yChar * 2)));
	base.SetBottomRightPoint(Vec2D(maxXOffset - (xChar * 7), maxYOffset - (yChar * 5)));
	screen.Draw(base, mCFill, true, mCFill);

	base.SetTopLeftPoint(Vec2D(maxXOffset - (xChar * 7), yOffset + (yChar * 3)));
	base.SetBottomRightPoint(Vec2D(maxXOffset - (xChar * 5), yOffset + (yChar * 4)));
	screen.Draw(base, mCFill, true, mCFill);

	t2.SetP0(Vec2D(maxXOffset - (xChar * 5), yOffset + (yChar * 4)));
	t2.SetP1(Vec2D(maxXOffset - (xChar * 3), yOffset + (yChar * 3)));
	t2.SetP2(Vec2D(maxXOffset - (xChar * 5), yOffset + (yChar * 3)));
	screen.Draw(t2, mCFill, true, mCFill);

	t2.SetP0(Vec2D(maxXOffset - (xChar * 4), yOffset + (yChar * 3)));
	t2.SetP1(Vec2D(maxXOffset - (xChar * 7), yOffset + (yChar * 2)));
	t2.SetP2(Vec2D(maxXOffset - (xChar * 7), yOffset + (yChar * 3)));
	screen.Draw(t2, mCFill, true, mCFill);

	base.SetTopLeftPoint(Vec2D(xOffset + (xChar * 3), yOffset + yChar));
	base.SetBottomRightPoint(Vec2D(maxXOffset - (xChar * 3), yOffset + (yChar * 2)));
	screen.Draw(base, mCFill, true, mCFill);

	t1.SetP0(Vec2D(xOffset + (xChar * 2), yOffset + (yChar * 2)));
	t1.SetP1(Vec2D(xOffset + (xChar * 4), yOffset));
	t1.SetP2(Vec2D(xOffset + (xChar * 4), yOffset + (yChar * 2)));
	screen.Draw(t1, mCFill, true, mCFill);

	t1.SetP0(Vec2D(xOffset + (xChar * 4), yOffset));
	t1.SetP1(Vec2D(xOffset + (xChar * 4), yOffset + yChar));
	t1.SetP2(Vec2D(xOffset + (xChar * 5), yOffset + yChar));
	screen.Draw(t1, mCFill, true, mCFill);

	t2.SetP0(Vec2D(maxXOffset - (xChar * 2), yOffset + (yChar * 2)));
	t2.SetP1(Vec2D(maxXOffset - (xChar * 3), yOffset + yChar));
	t2.SetP2(Vec2D(maxXOffset - (xChar * 3), yOffset + (yChar * 2)));
	screen.Draw(t2, mCFill, true, mCFill);

	// Draw outline
	DrawLine(
		Vec2D(xOffset + (xChar * 2), yOffset + (yChar * 2)),
		Vec2D(xOffset + (xChar * 4), yOffset),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 4), yOffset),
		Vec2D(xOffset + (xChar * 5), yOffset + yChar),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 5), yOffset + yChar),
		Vec2D(xOffset + (xChar * 13), yOffset + yChar),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 13), yOffset + yChar),
		Vec2D(xOffset + (xChar * 14), yOffset + (yChar * 2)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 14), yOffset + (yChar * 2)),
		Vec2D(xOffset + (xChar * 10), yOffset + (yChar * 2)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 10), yOffset + (yChar * 2)),
		Vec2D(xOffset + (xChar * 12), yOffset + (yChar * 3)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 12), yOffset + (yChar * 3)),
		Vec2D(xOffset + (xChar * 13), yOffset + (yChar * 3)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 13), yOffset + (yChar * 3)),
		Vec2D(xOffset + (xChar * 11), yOffset + (yChar * 4)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 11), yOffset + (yChar * 4)),
		Vec2D(xOffset + (xChar * 9), yOffset + (yChar * 4)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 9), yOffset + (yChar * 4)),
		Vec2D(xOffset + (xChar * 6), yOffset + (yChar * 5)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 9), yOffset + (yChar * 4)),
		Vec2D(xOffset + (xChar * 12), yOffset + (yChar * 7)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 12), yOffset + (yChar * 7)),
		Vec2D(xOffset + (xChar * 12), yOffset + (yChar * 8)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 12), yOffset + (yChar * 8)),
		Vec2D(xOffset + (xChar * 11), yOffset + (yChar * 9)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 11), yOffset + (yChar * 9)),
		Vec2D(xOffset + (xChar * 11), yOffset + (yChar * 10)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 11), yOffset + (yChar * 10)),
		Vec2D(xOffset + (xChar * 15), yOffset + (yChar * 10)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 15), yOffset + (yChar * 10)),
		Vec2D(xOffset + (xChar * 16), yOffset + (yChar * 11)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 16), yOffset + (yChar * 11)),
		Vec2D(xOffset + (xChar * 16), yOffset + (yChar * 12)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 16), yOffset + (yChar * 12)),
		Vec2D(xOffset + (xChar * 0), yOffset + (yChar * 12)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 0), yOffset + (yChar * 12)),
		Vec2D(xOffset + (xChar * 0), yOffset + (yChar * 11)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 0), yOffset + (yChar * 11)),
		Vec2D(xOffset + (xChar * 1), yOffset + (yChar * 10)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 1), yOffset + (yChar * 10)),
		Vec2D(xOffset + (xChar * 4), yOffset + (yChar * 10)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 4), yOffset + (yChar * 10)),
		Vec2D(xOffset + (xChar * 4), yOffset + (yChar * 9)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 4), yOffset + (yChar * 9)),
		Vec2D(xOffset + (xChar * 2), yOffset + (yChar * 7)),
		mCOutline, screen);
	DrawLine(
		Vec2D(xOffset + (xChar * 2), yOffset + (yChar * 7)),
		Vec2D(xOffset + (xChar * 2), yOffset + (yChar * 2)),
		mCOutline, screen);
}


void Knight::DrawLine(Vec2D p1, Vec2D p2, Color outline, Screen& screen) const
{
	Line2D line(p1, p2);
	screen.Draw(line, outline);
}
