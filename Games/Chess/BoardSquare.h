#pragma once

#include <stdint.h>
#include <memory>
#include "ChessPiece.h"
#include "../../Graphics/Color.h"

class Screen;

class BoardSquare
{
public:

	BoardSquare(bool isWhite) : mIsWhite(isWhite), mOwner(-1), mHasPiece(false), mIsAHighlight(false), mIsMHighlight(false), mIsDirty(true) 
	{
		if (mIsWhite)
			mColor = Color::White();
		else
			mColor = Color::Black();
	}

	void Draw(Screen& screen);
	void Update(uint32_t dt);
	void InsertPiece(std::unique_ptr<ChessPiece> piece);
	void MovePiece(BoardSquare& dest);
	void DrawMoveHighlight(Screen& screen);
	void DrawAttackHighlight(Screen& screen);
	void DrawLocationHighlight(Screen& screen);
	void KillPiece(std::unique_ptr<ChessPiece> piece);
	void DestroyPiece(std::unique_ptr<ChessPiece> piece, std::unique_ptr<ChessPiece> recievePiece);

	inline float GetXPosition() const { return mPosition.GetX(); }
	inline float GetYPosition() const { return mPosition.GetY(); }
	inline Vec2D GetPosition() const { return mPosition; }
	inline void SetPosition(Vec2D pos) { mPosition = pos; }
	inline void SetPosition(int x, int y) { mPosition.SetX(x); mPosition.SetY(y); }
	inline bool GetMoveHighlight() const { return mIsMHighlight; }
	inline bool GetAttackHighlight() const { return mIsAHighlight; }
	inline void SetMoveHighlight(bool highlight) { mIsMHighlight = highlight; }
	inline void SetAttackHighlight(bool highlight) { mIsAHighlight = highlight; }
	inline bool GetPieceColor() const { return mPiece->GetColor(); }
	inline int GetOwner() const { return mOwner; }
	inline bool HasPiece() const { return mHasPiece; }
	inline bool IsDirty() const { return mIsDirty; }
	inline void SetDirty() { mIsDirty = true; }

private:
	std::unique_ptr<ChessPiece> mPiece;
	bool mHasPiece;
	bool mIsDirty;
	int mOwner;
	bool mIsWhite;
	Color mColor;
	bool mIsMHighlight;
	bool mIsAHighlight;
	Vec2D mPosition;
};