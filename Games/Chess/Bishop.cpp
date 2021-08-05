#include "Bishop.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Color.h"
#include "../../Shapes/AARectangle.h"
#include "../../Shapes/Circle.h"
#include "../../Shapes/Line2D.h"
#include "../../Shapes/Triangle.h"

Bishop::Bishop()
{
}

void Bishop::Init(Vec2D offset, int pieceNum, bool isWhite)
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
	mUnit = PieceType::ptBishop;
}

void Bishop::Update(uint32_t dt) const
{
}

void Bishop::Draw(Screen& screen) const
{
	float xOffset = 155 + 75.075 * GetXPosition();
	float yOffset = 155 + 75.075 * GetYPosition();
	// float mag = .105;
	// Divide values by .105 to figure out originals -- values used here were 100/500/300/600/200/300/50/205/105/410/350/205
	Triangle base(
		Vec2D(xOffset + 10.5, yOffset + 63),
		Vec2D(xOffset + 52.5, yOffset + 63),
		Vec2D(xOffset + 31.5, yOffset + 21)
	); // Base of triangle
	Circle c1(Vec2D(xOffset + 31.5, yOffset + 5.25), 5.25); // Smaller top circle
	Circle c2(Vec2D(xOffset + 31.5, yOffset + 21.525), 15.75); // Large circle
	Line2D line(Vec2D(xOffset + 43.05, yOffset + 11.025), Vec2D(xOffset + 36.75, yOffset + 21.525)); // Slit for 'nose'

	screen.Draw(base, mCOutline, true, mCFill);
	screen.Draw(c1, mCOutline, true, mCFill);
	screen.Draw(c2, mCOutline, true, mCFill);
	screen.Draw(line, mCOutline);
}