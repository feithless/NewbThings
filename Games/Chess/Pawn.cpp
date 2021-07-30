#include "Pawn.h"
#include "ChessBoard.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Color.h"
#include "../../Shapes/Triangle.h"
#include "../../Shapes/Circle.h"

Pawn::Pawn()
{
}

void Pawn::Init(Vec2D offset, int pieceNum, bool isWhite)
{
	SetPosition(offset);
	mIsAlive = true;
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
	mPieceNum = pieceNum;
	mHasMoved = false;
	mUnit = ptPawn;
}

void Pawn::Update(uint32_t dt) const
{
	// ????  Maybe?
	// MoveRules(chessBoard);
}


void Pawn::Draw(Screen& screen) const
{

	float offset = 147;
	float xOff = GetXPosition() * 75 + offset;
	float yOff = GetYPosition() * 75 + 5 + offset;

	Triangle triangle = {
		Vec2D(36.53333 + xOff, 13.33333 + yOff),
		Vec2D(6.66666 + xOff, 66.66666 + yOff),
		Vec2D(66.66666 + xOff, 66.66666 + yOff) };
	Circle circle = { 
		Vec2D(37.53333 + xOff, 19.33333 + yOff),
		13.33333 };										
	//// Outline hider
	Triangle trianglehide = { 
		Vec2D(37.86666 + xOff, 13.33333 + yOff),
		Vec2D(9.33333 + xOff, 65.86666 + yOff),
		Vec2D(64 + xOff, 65.86666 + yOff) };


	screen.Draw(triangle, mCOutline);
	screen.Draw(circle, mCOutline, true, mCFill);
	screen.Draw(trianglehide, mCFill, true, mCFill);
}
