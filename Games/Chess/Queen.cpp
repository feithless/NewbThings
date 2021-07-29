#include "Queen.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Color.h"
#include "../../Shapes/AARectangle.h"
#include "../../Shapes/Circle.h"
#include "../../Shapes/Line2D.h"
#include "../../Shapes/Triangle.h"


Queen::Queen()
{
}

void Queen::Init(Vec2D offset, int pieceNum, bool isWhite)
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
}

void Queen::Update(uint32_t dt) const
{
}


void Queen::Draw(Screen& screen) const
{
	float xOffset = 155 + GetXPosition() * 75.075;
	float yOffset = 155 + GetYPosition() * 75.075;

	// Base
	Triangle base(
		Vec2D(xOffset + 5.25, yOffset + 63),
		Vec2D(xOffset + 57.75, yOffset + 63),
		Vec2D(xOffset + 31.5, yOffset + 15.75)
	);
	screen.Draw(base, mCOutline, true, mCFill);

	Circle head(Vec2D(xOffset + 31.5, yOffset + 10.5), 8.4);
	screen.Draw(head, mCOutline, true, mCFill);
	// chest
	base.SetP0(Vec2D(xOffset + 10.5, yOffset + 10.5));
	base.SetP1(Vec2D(xOffset + 52.5, yOffset + 10.5));
	base.SetP2(Vec2D(xOffset + 31.5, yOffset + 57.75));
	screen.Draw(base, mCFill, true, mCOutline);
	// Shoulders
	base.SetP0(Vec2D(xOffset + 26.25, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 36.75, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 31.5, yOffset + 10.5));
	screen.Draw(base, mCOutline, true, mCFill);
	// Hiders
	base.SetP0(Vec2D(xOffset + 15.225, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 47.775, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 31.5, yOffset + 57.75));
	screen.Draw(base, mCOutline, true, mCFill);
	base.SetP0(Vec2D(xOffset + 55, yOffset + 62.895));
	base.SetP1(Vec2D(xOffset + 56.54, yOffset + 62.895));
	base.SetP2(Vec2D(xOffset + 31.5, yOffset + 15.75));
	screen.Draw(base, mCFill, true, mCFill);
	// second
	base.SetP0(Vec2D(xOffset + 26.25, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 18.375, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 21, yOffset + 10.5));
	screen.Draw(base, mCFill, true, mCFill);
	base.SetP0(Vec2D(xOffset + 44.625, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 36.75, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 42, yOffset + 10.5));
	screen.Draw(base, mCFill, true, mCFill);
	// third
	base.SetP0(Vec2D(xOffset + 18.375, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 15.225, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 10.605, yOffset + 10.5));
	screen.Draw(base, mCFill, true, mCFill);
	base.SetP0(Vec2D(xOffset + 44.625, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 47.775, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 52.395, yOffset + 10.5));
	screen.Draw(base, mCFill, true, mCFill);
	// middle
	base.SetP0(Vec2D(xOffset + 26.25, yOffset + 21));
	base.SetP1(Vec2D(xOffset + 36.75, yOffset + 21));
	base.SetP2(Vec2D(xOffset + 31.5, yOffset + 10.5));
	screen.Draw(base, mCFill, true, mCFill);

	// Crown
	base.SetP0(Vec2D(xOffset + 31.5, yOffset));
	base.SetP1(Vec2D(xOffset + 34.125, yOffset + 4.2));
	base.SetP2(Vec2D(xOffset + 28.875, yOffset + 4.2));
	screen.Draw(base, mCFill, true, mCOutline);
	base.SetP0(Vec2D(xOffset + 26.25, yOffset + 1.05));
	base.SetP1(Vec2D(xOffset + 25.2, yOffset + 5.25));
	base.SetP2(Vec2D(xOffset + 28.875, yOffset + 4.2));
	screen.Draw(base, mCFill, true, mCOutline);
	base.SetP0(Vec2D(xOffset + 36.75, yOffset + 1.05));
	base.SetP1(Vec2D(xOffset + 37.8, yOffset + 5.25));
	base.SetP2(Vec2D(xOffset + 34.125, yOffset + 4.2));
	screen.Draw(base, mCFill, true, mCOutline);
}

void Queen::MoveRules(ChessBoard& chessBoard)
{
}
