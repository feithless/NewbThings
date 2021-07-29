#include "ChessBoard.h"

#include <iostream>
#include <thread>
#include <SDL.h>
#include "ChessPiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "BoardSquare.h"
#include "King.h"
#include "../../Graphics/Screen.h"


void ChessBoard::Init()
{
	// Create all the pieces and place them on the board to be drawn.
	bool white = true;
	bool isFirst = true;
	for (int i = 0; i < 8; i++)
	{
		std::vector<std::unique_ptr<BoardSquare>> temp;

		for (int j = 0; j < 8; j++)
		{
			std::unique_ptr<BoardSquare> square = std::make_unique<BoardSquare>(white);
			white = !white;
			square->SetPosition(i, j);
			if (isFirst)
			{
			}
			//std::unique_ptr<King> king = std::make_unique<King>();
			//king->Init(Vec2D(i, j), j * i);
			//square->InsertPiece(std::move(king));
			temp.push_back(std::move(square));
		}
		white = !white;
		mChessBoard.push_back(std::move(temp));
	}
	
	// Pawns at rows 1 and 6
	for (int i = 0; i < 8; i++)
	{
		std::unique_ptr<Pawn> pawn = std::make_unique<Pawn>();
		pawn->Init(Vec2D(i, 1), i, true);
		mChessBoard[i][1]->InsertPiece(std::move(pawn));
		std::unique_ptr<Pawn> pawn2 = std::make_unique<Pawn>();
		pawn2->Init(Vec2D(i, 6), i + 8, false);
		mChessBoard[i][6]->InsertPiece(std::move(pawn2));
	}

	// Rook @ 0 & 7
	for (int i = 0; i < 8; i += 7)
	{
		std::unique_ptr<Rook> rook = std::make_unique<Rook>();
		rook->Init(Vec2D(i, 0), i, true);
		mChessBoard[i][0]->InsertPiece(std::move(rook));
		std::unique_ptr<Rook> rook2 = std::make_unique<Rook>();
		rook2->Init(Vec2D(i, 7), i + 2, false);
		mChessBoard[i][7]->InsertPiece(std::move(rook2));
	}

	 //Knight @ 1 & 6
	for (int i = 1; i < 8; i += 5)
	{
		std::unique_ptr<Knight> knight = std::make_unique<Knight>();
		knight->Init(Vec2D(i, 0), i, true);
		mChessBoard[i][0]->InsertPiece(std::move(knight));
		std::unique_ptr<Knight> knight2 = std::make_unique<Knight>();
		knight2->Init(Vec2D(i, 7), i + 2, false);
		mChessBoard[i][7]->InsertPiece(std::move(knight2));
	}

	// Bishop @ 2 & 5
	for (int i = 2; i < 8; i += 3)
	{
		std::unique_ptr<Bishop> bishop = std::make_unique<Bishop>();
		bishop->Init(Vec2D(i, 0), i, true);
		mChessBoard[i][0]->InsertPiece(std::move(bishop));
		std::unique_ptr<Bishop> bishop2 = std::make_unique<Bishop>();
		bishop2->Init(Vec2D(i, 7), i + 2, false);
		mChessBoard[i][7]->InsertPiece(std::move(bishop2));
	}

	// Queen @ 4
	std::unique_ptr<Queen> whiteQueen = std::make_unique<Queen>();
	whiteQueen->Init(Vec2D(4, 0), 0, true);
	mChessBoard[4][0]->InsertPiece(std::move(whiteQueen));
	std::unique_ptr<Queen> blackQueen = std::make_unique<Queen>();
	blackQueen->Init(Vec2D(4, 7), 1, false);
	mChessBoard[4][7]->InsertPiece(std::move(blackQueen));

	// King @ 3
	std::unique_ptr<King> whiteKing = std::make_unique<King>();
	whiteKing->Init(Vec2D(3, 0), 0, true);
	mChessBoard[3][0]->InsertPiece(std::move(whiteKing));
	std::unique_ptr<King> blackKing = std::make_unique<King>();
	blackKing->Init(Vec2D(3, 7), 1, false);
	mChessBoard[3][7]->InsertPiece(std::move(blackKing));
}

void ChessBoard::Draw(Screen& screen)
{
	for (auto& i : mChessBoard)
	{
		for (auto& j : i)
		{
			j->Draw(screen);
		}
	}
}

void ChessBoard::Update(uint32_t dt)
{

	for (auto& i : mChessBoard)
	{
		for (auto& j : i)
		{
			j->Update(dt);
		}
	}
}

void ChessBoard::UnitDied(std::unique_ptr<ChessPiece> piece)
{
	mGraveYard.emplace_back(std::move(piece));
	// mGraveYard->push_back(std::move(piece));
}

void ChessBoard::AssignPiece(std::unique_ptr<ChessPiece> piece, int x, int y)
{
	// mChessBoard[x][y]->InsertPiece(std::move(piece));
}
