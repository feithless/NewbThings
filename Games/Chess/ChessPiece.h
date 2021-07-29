#pragma once

#include <vector>
#include <stdint.h>
#include <string>
#include "../../Utils/Vec2D.h"
#include "../../Graphics/Color.h"

class Screen;
class Chess;
class ChessBoard;

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

	/// <summary>
	/// Figures out the move rules and draws them.
	/// Pawns can move 2 spaces forward on first move, 1 space otherwise, and can only attack diagonally forward.
	/// Rooks can move any number of unoccupied spaces horizontally and vertically, but cannot move or attack diagonal.
	/// Knights move in an L shape - 2 steps in x or y, 1 step in the other axis and can jump other units.
	/// Bishops can move any number of unoccupied spaces diagonally.
	/// Queen can move any number of unoccupied spaces horizontally, vertically, or diagonally.
	/// King can move 1 space in any unoccupied space horizontally, vertically, or diagonally from the piece that does not put the king in the threatened position.
	/// </summary>
	/// <param name="chessBoard"></param>
	virtual void MoveRules(ChessBoard& chessBoard) = 0;

	// Gives access to internal members that may need to be seen outside.
	float GetXPosition() const { return mPosition.GetX(); }
	float GetYPosition() const { return mPosition.GetY(); }
	Vec2D GetPostion() const { return mPosition; }
	void SetXPosition(float x) { mPosition.SetX(x); }
	void SetYPosition(float y) { mPosition.SetY(y); }
	void SetPosition(Vec2D pos) { mPosition = pos; }
	bool GetColor() const { return mIsWhite; }


protected:

	Color mCFill;
	Color mCOutline;
	int mPieceNum;
	bool mIsWhite;
	bool mIsAlive;
	string mUnit;
	Vec2D mPosition;
};