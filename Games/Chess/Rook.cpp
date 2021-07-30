#include "Rook.h"
#include "../Chess.h"
#include "../../Graphics/Screen.h"
#include "../../Graphics/Color.h"
#include "../../Shapes/AARectangle.h"

Rook::Rook()
{
}

void Rook::Init(Vec2D offset, int pieceNum, bool isWhite)
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
	mUnit = PieceType::ptRook;
}

void Rook::Update(uint32_t dt) const
{
	// ???? Maybe?
	// MoveRules(chessBoard);
}

void Rook::Draw(Screen& screen) const
{
	float offset = 155;
	float xOff = GetXPosition() * 75 + offset;
	float yOff = GetYPosition() * 75 + offset;
	AARectangle rect = {
		Vec2D(10.5 + xOff, 0 + yOff), 
		Vec2D(18.375 + xOff, 15.75 + yOff) };
	screen.Draw(rect, mCOutline, true, mCFill);
	rect.MoveTo(Vec2D(27.615 + xOff, 0 + yOff));
	screen.Draw(rect, mCOutline, true, mCFill);
	rect.MoveTo(Vec2D(44.625 + xOff, 0 + yOff));
	screen.Draw(rect, mCOutline, true, mCFill);
	rect.MoveTo(Vec2D(10.5 + xOff, 15.75 + yOff));
	rect.SetBottomRightPoint(Vec2D(52.5 + xOff, 26.25 + yOff));
	screen.Draw(rect, mCOutline, true, mCFill);
	rect.MoveTo(Vec2D(15.75 + xOff, 26.25 + yOff));
	rect.SetBottomRightPoint(Vec2D(47.25 + xOff, 52.5 + yOff));
	screen.Draw(rect, mCOutline, true, mCFill);
	rect.MoveTo(Vec2D(7.875 + xOff, 52.5 + yOff));
	rect.SetBottomRightPoint(Vec2D(55.125 + xOff, 57.75 + yOff));
	screen.Draw(rect, mCOutline, true, mCFill);
	rect.MoveTo(Vec2D(0 + xOff, 57.75 + yOff));
	rect.SetBottomRightPoint(Vec2D(63 + xOff, 63 + yOff));
	screen.Draw(rect, mCOutline, true, mCFill);
}

