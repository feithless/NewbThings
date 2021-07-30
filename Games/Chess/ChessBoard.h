#pragma once

#include <memory>
#include <vector>
#include <stdint.h>
#include "ChessPiece.h"
#include "BoardSquare.h"
#include "../../Utils/Vec2D.h"

class Screen;

class ChessBoard
{
public:
	void Init();
	void Draw(Screen& screen);
	void Update(uint32_t dt);
	void UnitDied(std::unique_ptr<ChessPiece> piece);
	void AssignPiece(std::unique_ptr<ChessPiece> piece, int x, int y);
	void HighlightLocation(int x, int y);
	/// <summary>
	/// Move the highlighted location one location in a direction.
	/// </summary>
	/// <param name="vertical">Pass true if moving vertically, false if moving horizontally.</param>
	/// <param name="positive">Pass true if moving positive (down/right), false if moving negative (up/left).</param>
	void MoveHighlightLocation(bool vertical, bool positive);
	bool HighlightedLocationHasPiece() const;

	inline bool HasPiece(int x, int y) const { return mChessBoard[x][y]->HasPiece(); }
	inline int GetOwner(int x, int y) const { return mChessBoard[x][y]->GetOwner(); }


private:

	void HighlightMove(int x, int y);
	void HighlightAttack(int x, int y);

	void DetectMovement(PieceType type);

	void MovePawn();
	void MoveKnight();
	void MoveRook();
	void MoveKing();
	void MoveQueen();
	void MoveBishop();

	void Attack(int x, int y);

	Vec2D mHighlight;
	PieceType HighlightedPiece();
	std::vector<std::vector<std::unique_ptr<BoardSquare>>> mChessBoard;
	std::vector<std::unique_ptr<ChessPiece>> mGraveYard;
	std::vector<std::unique_ptr<ChessPiece>> mDestroyed;
};