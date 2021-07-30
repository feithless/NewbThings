#pragma once

#include <vector>
#include <stdint.h>
#include <string>
#include "../../Utils/Vec2D.h"
#include "../../Graphics/Color.h"

class Screen;
class Chess;
class ChessBoard;

enum PieceType
{
	ptPawn = 0,
	ptRook,
	ptKnight,
	ptBishop,
	ptQueen,
	ptKing
};

class ChessPiece
{

public:

	virtual ~ChessPiece() { }

	virtual void Init(Vec2D offset, int pieceNum, bool isWhite = false) = 0;
	// Not sure what dt is for yet, so once I figure that out, I can implement more here
	// But for the most part, update should only call MoveRules(chessBoard) because it will do things.
	virtual void Update(uint32_t dt) const = 0;
	// Calls the draw function of the piece.
	virtual void Draw(Screen& screen) const = 0;


	// Gives access to internal members that may need to be seen outside.
	float GetXPosition() const { return mPosition.GetX(); }
	float GetYPosition() const { return mPosition.GetY(); }
	Vec2D GetPostion() const { return mPosition; }
	void SetXPosition(float x) { mPosition.SetX(x); }
	void SetYPosition(float y) { mPosition.SetY(y); }
	void SetPosition(Vec2D pos) { mPosition = pos; }
	bool GetColor() const { return mIsWhite; }
	PieceType GetPieceType() const { return mUnit; }


protected:

	Color mCFill;
	Color mCOutline;
	int mPieceNum;
	bool mIsWhite;
	bool mIsAlive;
	PieceType mUnit;
	Vec2D mPosition;
};