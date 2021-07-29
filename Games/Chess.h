#pragma once

#include <vector>
#include <string>
#include "../Utils/Vec2D.h"
#include <memory>

class ChessBoard;
class Screen;


class Chess
{
public:
	Chess(Screen& screen, ChessBoard& chessBoard);

	void DrawBoard(Screen& screen, ChessBoard& chessBoard);
	void DrawPieces(Screen& screen, ChessBoard& chessBoard);


private:
};

