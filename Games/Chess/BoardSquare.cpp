#include "BoardSquare.h"


#include "../../Graphics/Screen.h"
#include "../../Shapes/AARectangle.h"
#include "../../Graphics/Color.h"

#include "ChessBoard.h"

void BoardSquare::Draw(Screen& screen)
{
	// No longer dirty, we've cleaned it up.
	// mIsDirty = false;
	if (mIsAHighlight)
		DrawAttackHighlight(screen);
	else if (mIsMHighlight)
		DrawMoveHighlight(screen);
	else if (mIsHighlight)
		DrawLocationHighlight(screen);
	else
	{
		this;
		int offsetX = 75 * mPosition.GetX() + 150;
		int offsetY = 75 * mPosition.GetY() + 150;
		AARectangle square = { Vec2D(offsetX, offsetY), Vec2D(offsetX + 75, offsetY + 75) };
		screen.Draw(square, Color::Gray(), true, mColor);

	}

	if(mHasPiece)
		mPiece->Draw(screen);

}


void BoardSquare::Update(uint32_t dt)
{
	if(mHasPiece)
		mPiece->Update(dt);
}

void BoardSquare::InsertPiece(std::unique_ptr<ChessPiece> piece)
{
	if (!piece)
		return;
	mPiece = std::move(piece);
	mHasPiece = true;
	mIsDirty = true;
	if (mPiece->GetColor() == true)
		mOwner = 0;
	else
		mOwner = 1;
}

void BoardSquare::MovePiece(BoardSquare& dest)
{
	dest.InsertPiece(std::move(mPiece));
	mHasPiece = false;

	mIsDirty = true;
	mOwner = -1;
}

void BoardSquare::DrawMoveHighlight(Screen& screen)
{
	int offsetX = 75 * mPosition.GetX() + 150;
	int offsetY = 75 * mPosition.GetY() + 150;
	AARectangle square = { Vec2D(offsetX, offsetY), Vec2D(offsetX + 75, offsetY + 75) };
	Color color = Color::Orange();
	Color color2 = Color::Gray();

	screen.Draw(square, color2, true, color);

}

void BoardSquare::DrawAttackHighlight(Screen& screen)
{
	int offsetX = 75 * mPosition.GetX() + 150;
	int offsetY = 75 * mPosition.GetY() + 150;
	AARectangle square = { Vec2D(offsetX, offsetY), Vec2D(offsetX + 75, offsetY + 75) };
	Color color = Color::Red();
	Color color2 = Color::Gray();

	screen.Draw(square, color2, true, color);

}

void BoardSquare::DrawLocationHighlight(Screen& screen)
{
	int offsetX = 75 * mPosition.GetX() + 150;
	int offsetY = 75 * mPosition.GetY() + 150;
	AARectangle square = { Vec2D(offsetX, offsetY), Vec2D(offsetX + 75, offsetY + 75) };
	Color color = Color::Blue();
	Color color2 = Color::Gray();

	screen.Draw(square, color2, true, color);
}

void BoardSquare::KillPiece(std::unique_ptr<ChessPiece> piece)
{
	// ChessBoard::UnitDied(std::move(mPiece));
	InsertPiece(std::move(piece));
	mIsDirty = true;
}

void BoardSquare::DestroyPiece(std::unique_ptr<ChessPiece> piece, std::unique_ptr<ChessPiece> recievePiece)
{
	// This should only be called for pawns reaching other side.
	piece.reset();
	InsertPiece(std::move(recievePiece));
	mIsDirty = true;
}