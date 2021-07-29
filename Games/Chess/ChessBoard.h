#pragma once

#include <memory>
#include <vector>
#include <stdint.h>
#include "ChessPiece.h"
#include "BoardSquare.h"

class Screen;

class ChessBoard
{
public:
	void Init();
	void Draw(Screen& screen);
	void Update(uint32_t dt);
	void UnitDied(std::unique_ptr<ChessPiece> piece);
	void AssignPiece(std::unique_ptr<ChessPiece> piece, int x, int y);

	inline bool HasPiece(int x, int y) { return mChessBoard[x][y]->HasPiece(); }

private:
	std::vector<std::vector<std::unique_ptr<BoardSquare>>> mChessBoard;
	std::vector<std::unique_ptr<ChessPiece>> mGraveYard;
	std::vector<std::unique_ptr<ChessPiece>> mDestroyed;
};