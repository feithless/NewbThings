#include "King.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Color.h"
#include "../../Shapes/AARectangle.h"
#include "../../Shapes/Circle.h"
#include "../../Shapes/Line2D.h"
#include "../../Shapes/Triangle.h"

void King::Init(Vec2D offset, int pieceNum, bool isWhite)
{
	mPosition = offset;
	mPieceNum = pieceNum;
	mIsAlive = true;
	mIsWhite = isWhite;
	if (mIsWhite)
	{
		mCOutline = Color::Black();
		mCFill = Color::White();
	}
	else
	{
		mCOutline = Color::White();
		mCFill = Color::Black();
	}
}

void King::Update(uint32_t dt) const
{
}

void King::Draw(Screen& screen) const
{
	float xChar = (50 * .090);
	float yChar = (47.06 * .090);
	float xOffset = 150 + xChar/2 + (GetXPosition() * 75.075f);

	float yOffset = 150 + (GetYPosition() * 75.075f);
	float midXOffset = xOffset + xChar * 8;
	float maxYOffset = yOffset + yChar * 17;



	// Base
	Circle lBase(Vec2D(midXOffset - (xChar * 7), maxYOffset - yChar), yChar);
	screen.Draw(lBase, mCOutline, true, mCFill);
	Circle rBase(Vec2D(midXOffset + (xChar * 7), maxYOffset - yChar), yChar);
	screen.Draw(rBase, mCOutline, true, mCFill);

	AARectangle base(
		Vec2D(midXOffset - (xChar * 8), maxYOffset - yChar),
		Vec2D(midXOffset + (xChar * 8), maxYOffset));
	screen.Draw(base, mCOutline, true, mCFill);
	Triangle lTriangle(
		Vec2D(midXOffset - (xChar * 8), maxYOffset - yChar),
		Vec2D(midXOffset - (xChar * 6), maxYOffset - yChar),
		Vec2D(midXOffset - (xChar * 6), maxYOffset - (yChar * 2))
	);
	Triangle rTriangle(
		Vec2D(midXOffset + (xChar * 8), maxYOffset - yChar),
		Vec2D(midXOffset + (xChar * 6), maxYOffset - yChar),
		Vec2D(midXOffset + (xChar * 6), maxYOffset - (yChar * 2))
	);
	// screen.Draw(lTriangle, mCOutline, true, mCFill);
	// screen.Draw(rTriangle, mCOutline, true, mCFill);
	base.SetTopLeftPoint(Vec2D(midXOffset - (xChar * 7), maxYOffset - (yChar * 2)));
	base.SetBottomRightPoint(Vec2D(midXOffset + (xChar * 7), maxYOffset - (yChar * 1)));
	screen.Draw(base, mCOutline, true, mCFill);


	// Head -- Drawn first for line hiding
	Circle chest(Vec2D(midXOffset, yOffset + (yChar * 7)), xChar * 3);
	screen.Draw(chest, mCOutline, true, mCFill);

	// Body part 1
	lTriangle.SetP0(Vec2D(midXOffset - (xChar * 5), maxYOffset - (yChar * 2)));
	lTriangle.SetP1(Vec2D(midXOffset - (xChar * 2), maxYOffset - (yChar * 2)));
	lTriangle.SetP2(Vec2D(midXOffset - (xChar * 2), maxYOffset - (yChar * 8)));
	screen.Draw(lTriangle, mCOutline, true, mCFill);
	rTriangle.SetP0(Vec2D(midXOffset + (xChar * 5), maxYOffset - (yChar * 2)));
	rTriangle.SetP1(Vec2D(midXOffset + (xChar * 2), maxYOffset - (yChar * 2)));
	rTriangle.SetP2(Vec2D(midXOffset + (xChar * 2), maxYOffset - (yChar * 8)));
	screen.Draw(rTriangle, mCOutline, true, mCFill);

	// Inner column
	base.SetTopLeftPoint(Vec2D(midXOffset - (xChar * 2), yOffset + (yChar * 9)));
	base.SetBottomRightPoint(Vec2D(midXOffset + (xChar * 2), maxYOffset - (yChar * 2)));
	screen.Draw(base, mCOutline, true, mCFill);

	// Cross hat
	base.SetTopLeftPoint(Vec2D(midXOffset - (xChar * 0.5), yOffset + (yChar * 0)));
	base.SetBottomRightPoint(Vec2D(midXOffset + (xChar * 0.5), yOffset + (yChar * 4)));
	screen.Draw(base, mCOutline, true, mCFill);
	base.SetTopLeftPoint(Vec2D(midXOffset - (xChar * 1.5), yOffset + (yChar * 1)));
	base.SetBottomRightPoint(Vec2D(midXOffset + (xChar * 1.5), yOffset + (yChar * 2)));
	screen.Draw(base, mCOutline, true, mCFill);


	AARectangle hidingSquare(
		Vec2D(midXOffset - (xChar * 8) + 1, maxYOffset - (yChar * 1)),
		Vec2D(midXOffset + (xChar * 8) - 1, maxYOffset - (yChar * 0) - 1)
	);
	screen.Draw(hidingSquare, mCFill, true, mCFill);

	Line2D line(
		Vec2D(midXOffset - (xChar * 7), maxYOffset - (yChar * 1)),
		Vec2D(midXOffset - (xChar * 7), maxYOffset - (yChar * 2))
	);
	screen.Draw(line, mCFill);
	line.SetP0(Vec2D(midXOffset + (xChar * 7), maxYOffset - (yChar * 1)));
	line.SetP1(Vec2D(midXOffset + (xChar * 7), maxYOffset - (yChar * 2)));
	screen.Draw(line, mCFill);
	line.SetP0(Vec2D(midXOffset - (xChar * 5), maxYOffset - (yChar * 2)));
	line.SetP1(Vec2D(midXOffset + (xChar * 5), maxYOffset - (yChar * 2)));
	screen.Draw(line, mCFill);
	line.SetP0(Vec2D(midXOffset - (xChar * 2), maxYOffset - (yChar * 2)));
	line.SetP1(Vec2D(midXOffset - (xChar * 2), maxYOffset - (yChar * 9)));
	screen.Draw(line, mCFill);
	line.SetP0(Vec2D(midXOffset + (xChar * 2), maxYOffset - (yChar * 2)));
	line.SetP1(Vec2D(midXOffset + (xChar * 2), maxYOffset - (yChar * 9)));
	screen.Draw(line, mCFill);
	Circle chestHide(Vec2D(midXOffset, yOffset + (yChar * 7)), xChar * 3 - 1);
	screen.Draw(chestHide, mCFill, true, mCFill);
}

void King::MoveRules(ChessBoard& chessBoard)
{
}
