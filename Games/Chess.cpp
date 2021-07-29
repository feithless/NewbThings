#include "Chess.h"

#include "..\Graphics\Color.h"
#include "..\Shapes\AARectangle.h"
#include "..\Shapes\Circle.h"
#include "..\Shapes\Triangle.h"
#include "..\Graphics\Screen.h"
#include "Chess/Pawn.h"
#include "Chess/ChessPiece.h"
#include "Chess/ChessBoard.h"


Chess::Chess(Screen& screen, ChessBoard& chessBoard)
{

}

void Chess::DrawBoard(Screen& screen, ChessBoard& chessBoard)
{
	// This will get refactored.
}

void Chess::DrawPieces(Screen& screen, ChessBoard& chessBoard)
{
	 chessBoard.Draw(screen);
}

