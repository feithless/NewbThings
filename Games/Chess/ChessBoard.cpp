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
	HighlightLocation(0, 0);
	
	// Pawns at rows 1 and 6
	for (int i = 0; i < 8; i++)
	{
		std::unique_ptr<Pawn> pawn = std::make_unique<Pawn>();
		pawn->Init(Vec2D(i, 1+2), i, true);
		mChessBoard[i][1+2]->InsertPiece(std::move(pawn));
		std::unique_ptr<Pawn> pawn2 = std::make_unique<Pawn>();
		pawn2->Init(Vec2D(i, 6-2), i + 8, false);
		mChessBoard[i][6-2]->InsertPiece(std::move(pawn2));
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

void ChessBoard::HighlightLocation(int x, int y)
{
	mHighlight = Vec2D(x, y);
	mChessBoard[mHighlight.GetX()][mHighlight.GetY()]->SetHighlight(true);
	if (mChessBoard[mHighlight.GetX()][mHighlight.GetY()]->HasPiece())
	{
		DetectMovement(mChessBoard[mHighlight.GetX()][mHighlight.GetY()]->GetPiece());
	}
}

void ChessBoard::MoveHighlightLocation(bool vertical, bool positive)
{
	for( auto& x : mChessBoard)
		for (auto& y : x)
		{
			if (y->GetAttackHighlight())
				y->SetAttackHighlight(false);
			if (y->GetMoveHighlight())
				y->SetMoveHighlight(false);
		}
	mChessBoard[mHighlight.GetX()][mHighlight.GetY()]->SetHighlight(false);
	int x = mHighlight.GetX();
	int y = mHighlight.GetY();
	int move = 0;
	if (positive)
		move = 1;
	else
		move = -1;
	if (vertical && y + move >= 0 && y + move <= 7)
		y += move;
	else if (!vertical && x + move >= 0 && x + move <= 7)
		x += move;
	HighlightLocation(x, y);
}

bool ChessBoard::HighlightedLocationHasPiece() const
{
	return HasPiece(mHighlight.GetX(), mHighlight.GetY());
}

void ChessBoard::HighlightMove(int x, int y)
{
	mChessBoard[x][y]->SetMoveHighlight(true);
}

void ChessBoard::HighlightAttack(int x, int y)
{
	mChessBoard[x][y]->SetAttackHighlight(true);
}

void ChessBoard::DetectMovement(PieceType type)
{
	switch (type)
	{
	case ptPawn:
		MovePawn();
		break;
	case ptRook:
		MoveRook();
		break;
	case ptKnight:
		MoveKnight();
		break;
	case ptBishop:
		MoveBishop();
		break;
	case ptQueen:
		MoveQueen();
		break;
	case ptKing:
		MoveKing();
		break;
	default:
		break;
	}
}

void ChessBoard::MovePawn()
{
	int x = mHighlight.GetX();
	int y = mHighlight.GetY();
	// Need to know if white or black; this will help detect whether they can move 2 spaces or not.
	int owner = mChessBoard[x][y]->GetOwner();
	// Check to see if white.  If it is, then we can only move forward.
	if (owner == 0)
	{
		// Check if y+1 has a piece and assign the spot as available if we do.
		if (!mChessBoard[x][y + 1]->HasPiece())
			mChessBoard[x][y + 1]->SetMoveHighlight(true);
		// Check if y = 1 and if y + 2 has a spot available.  If so, draw it as a movement option.
		if (y == 1 && !mChessBoard[x][y + 2]->HasPiece())
			mChessBoard[x][y + 2]->SetMoveHighlight(true);

		// Pawns only attack diagonal forward, so check if we're able to do that.  Also, can't attack their own people.
		if (x + 1 <= 7 && mChessBoard[x + 1][y + 1]->HasPiece() && mChessBoard[x + 1][y + 1]->GetOwner() != owner)
			Attack(x + 1, y + 1);
		if (x - 1 >= 0 && mChessBoard[x - 1][y + 1]->HasPiece() && mChessBoard[x - 1][y + 1]->GetOwner() != owner)
			Attack(x - 1, y + 1);
	}
	else
	{
		// Check if y - 1 has a piece and assign the spot as available if we do.
		if (!mChessBoard[x][y - 1]->HasPiece())
			mChessBoard[x][y - 1]->SetMoveHighlight(true);
		// Check if y = 6 and if y - 2 has a spot available.  If so, draw it as a movement option.
		if (y == 6 && !mChessBoard[x][y - 2]->HasPiece())
			mChessBoard[x][y - 2]->SetMoveHighlight(true);

		// Pawns only attack diagonal forward, so check if we're able to do that.  Also, can't attack their own people.
		if (x + 1 <= 7 && mChessBoard[x + 1][y - 1]->HasPiece() && mChessBoard[x + 1][y - 1]->GetOwner() != owner)
			Attack(x + 1, y - 1);
		if (x - 1 >= 0 && mChessBoard[x - 1][y - 1]->HasPiece() && mChessBoard[x - 1][y - 1]->GetOwner() != owner)
			Attack(x - 1, y - 1);
	}
}

void ChessBoard::MoveKnight()
{
	// Knights move in a x +/- 2, y +/- 1, or x +/- 1, y +/- 2 formation.
	int x = mHighlight.GetX();
	int y = mHighlight.GetY();
	int owner = mChessBoard[x][y]->GetOwner();

	// First nest if: Check if move is valid
	// Second nest if: Check if empty, if so create move highlight, otherwise, check if owned by opponent, if so, create attack highlight
	// x +/- 2, y +/- 1
	if (x + 2 <= 7 && y + 1 <= 7)
	{
		if (!mChessBoard[x + 2][y + 1]->HasPiece())
			mChessBoard[x + 2][y + 1]->SetMoveHighlight(true);
		else if (mChessBoard[x + 2][y + 1]->GetOwner() != owner)
			Attack(x + 2, y + 1);
	}

	if (x + 2 <= 7 && y - 1 >= 0)
	{
		if (!mChessBoard[x + 2][y - 1]->HasPiece())
			mChessBoard[x + 2][y - 1]->SetMoveHighlight(true);
		else if (mChessBoard[x + 2][y - 1]->GetOwner() != owner)
			Attack(x + 2, y - 1);
	}

	if (x - 2 >= 0 && y + 1 <= 7)
	{
		if (!mChessBoard[x - 2][y + 1]->HasPiece())
			mChessBoard[x - 2][y + 1]->SetMoveHighlight(true);
		else if (mChessBoard[x - 2][y + 1]->GetOwner() != owner)
			Attack(x - 2, y + 1);
	}

	if (x - 2 >= 0 && y - 1 >= 0)
	{
		if (!mChessBoard[x - 2][y - 1]->HasPiece())
			mChessBoard[x - 2][y - 1]->SetMoveHighlight(true);
		else if (mChessBoard[x - 2][y - 1]->GetOwner() != owner)
			Attack(x - 2, y - 1);
	}

	// x +/- 1, y +/- 2
	if (x + 1 <= 7 && y + 2 <= 7)
	{
		if (!mChessBoard[x + 1][y + 2]->HasPiece())
			mChessBoard[x + 1][y + 2]->SetMoveHighlight(true);
		else if (mChessBoard[x + 1][y + 2]->GetOwner() != owner)
			Attack(x + 1, y + 2);
	}

	if (x - 1 >= 0 && y + 2 <= 7)
	{
		if (!mChessBoard[x - 1][y + 2]->HasPiece())
			mChessBoard[x - 1][y + 2]->SetMoveHighlight(true);
		else if (mChessBoard[x - 1][y + 2]->GetOwner() != owner)
			Attack(x - 1, y + 2);
	}

	if (x + 1 <= 7 && y - 2 >= 0)
	{
		if (!mChessBoard[x + 1][y - 2]->HasPiece())
			mChessBoard[x + 1][y - 2]->SetMoveHighlight(true);
		else if (mChessBoard[x + 1][y - 2]->GetOwner() != owner)
			Attack(x + 1, y - 2);
	}

	if (x - 1 >= 0 && y - 2 >= 0)
	{
		if (!mChessBoard[x - 1][y - 2]->HasPiece())
			mChessBoard[x - 1][y - 2]->SetMoveHighlight(true);
		else if (mChessBoard[x - 1][y - 2]->GetOwner() != owner)
			Attack(x - 1, y - 2);
	}
}

void ChessBoard::MoveRook()
{
	int x = mHighlight.GetX();
	int y = mHighlight.GetY();
	int owner = mChessBoard[x][y]->GetOwner();

	// Rooks move horizontal or vertical any amount of spaces until hitting a wall or enemy.
	
	// Check positive X values first
	for (int dx = x + 1; dx <= 7; dx++)
	{
		if (!mChessBoard[dx][y]->HasPiece())
			mChessBoard[dx][y]->SetMoveHighlight(true);
		else if (mChessBoard[dx][y]->GetOwner() != owner)
		{
			Attack(dx, y);
			// We can't jump units, so we're done with this loop.
			break;
		}
		else
		{
			// If we don't place an empty tile, or we don't create an attack, we're done.
			// This should only happen if we run into one of the owner's pieces.
			break;
		}
	}
	// Checking negative X values
	for (int dx = x - 1; dx >= 0; dx--)
	{
		if (!mChessBoard[dx][y]->HasPiece())
			mChessBoard[dx][y]->SetMoveHighlight(true);
		else if (mChessBoard[dx][y]->GetOwner() != owner)
		{
			Attack(dx, y);
			// We can't jump units, so we're done with this loop.
			break;
		}
		else
		{
			// If we don't place an empty tile, or we don't create an attack, we're done.
			// This should only happen if we run into one of the owner's pieces.
			break;
		}
	}

	// Check positive Y values first
	for (int dy = y + 1; dy <= 7; dy++)
	{
		if (!mChessBoard[x][dy]->HasPiece())
			mChessBoard[x][dy]->SetMoveHighlight(true);
		else if (mChessBoard[x][dy]->GetOwner() != owner)
		{
			Attack(x, dy);
			// We can't jump units, so we're done with this loop.
			break;
		}
		else
		{
			// If we don't place an empty tile, or we don't create an attack, we're done.
			// This should only happen if we run into one of the owner's pieces.
			break;
		}
	}
	// Checking negative Y values
	for (int dy = y - 1; dy >= 0; dy--)
	{
		if (!mChessBoard[x][dy]->HasPiece())
			mChessBoard[x][dy]->SetMoveHighlight(true);
		else if (mChessBoard[x][dy]->GetOwner() != owner)
		{
			Attack(x, dy);
			// We can't jump units, so we're done with this loop.
			break;
		}
		else
		{
			// If we don't place an empty tile, or we don't create an attack, we're done.
			// This should only happen if we run into one of the owner's pieces.
			break;
		}
	}
}

void ChessBoard::MoveKing()
{
	int x = mHighlight.GetX();
	int y = mHighlight.GetY();
	int owner = mChessBoard[x][y]->GetOwner();

	// There is more special things here, just need to figure out how to deal with King bullshit.
	if (x + 1 <= 7)
	{
		if (y + 1 <= 7)
		{
			if (!mChessBoard[x + 1][y + 1]->HasPiece())
				mChessBoard[x + 1][y + 1]->SetMoveHighlight(true);
			else if (mChessBoard[x + 1][y + 1]->GetOwner() != owner)
				Attack(x + 1, y + 1);
		}
		if (!mChessBoard[x + 1][y]->HasPiece())
			mChessBoard[x + 1][y]->SetMoveHighlight(true);
		else if (mChessBoard[x + 1][y]->GetOwner() != owner)
			Attack(x + 1, y);
		if (y - 1 >= 0)
		{
			if (!mChessBoard[x + 1][y - 1]->HasPiece())
				mChessBoard[x + 1][y - 1]->SetMoveHighlight(true);
			else if (mChessBoard[x + 1][y - 1]->GetOwner() != owner)
				Attack(x + 1, y - 1);
		}
	}
	if (x - 1 >= 0)
	{
		if (y + 1 <= 7)
		{
			if (!mChessBoard[x - 1][y + 1]->HasPiece())
				mChessBoard[x - 1][y + 1]->SetMoveHighlight(true);
			else if (mChessBoard[x - 1][y + 1]->GetOwner() != owner)
				Attack(x - 1, y + 1);
		}
		if (!mChessBoard[x - 1][y]->HasPiece())
			mChessBoard[x - 1][y]->SetMoveHighlight(true);
		else if (mChessBoard[x - 1][y]->GetOwner() != owner)
			Attack(x - 1, y);
		if (y - 1 >= 0)
		{
			if (!mChessBoard[x - 1][y - 1]->HasPiece())
				mChessBoard[x - 1][y - 1]->SetMoveHighlight(true);
			else if (mChessBoard[x - 1][y - 1]->GetOwner() != owner)
				Attack(x - 1, y - 1);
		}
	}
	if (y + 1 <= 7)
	{
		if (!mChessBoard[x][y + 1]->HasPiece())
			mChessBoard[x][y + 1]->SetMoveHighlight(true);
		else if (mChessBoard[x][y + 1]->GetOwner() != owner)
			Attack(x, y + 1);
	}
	if (y - 1 >= 0)
	{
		if (!mChessBoard[x][y - 1]->HasPiece())
			mChessBoard[x][y - 1]->SetMoveHighlight(true);
		else if (mChessBoard[x][y - 1]->GetOwner() != owner)
			Attack(x, y - 1);
	}

}

void ChessBoard::MoveQueen()
{
	// Queen is literally just a combination of Bishops and Rooks, so we'll just call them.
	MoveBishop();
	MoveRook();
}

void ChessBoard::MoveBishop()
{
	int x = mHighlight.GetX();
	int y = mHighlight.GetY();
	int owner = mChessBoard[x][y]->GetOwner();

	bool encounteredBlock = false;

	for (int i = 1; i <= 7; i++)
	{
		if (!(x + i > 7 || y + i > 7))
		{
			if (!mChessBoard[x + i][y + i]->HasPiece())
				mChessBoard[x + i][y + i]->SetMoveHighlight(true);
			else if (mChessBoard[x + i][y + i]->GetOwner() != owner)
			{
				Attack(x + i, y + i);
				break;
			}
			else
				break;
		}
	}
	for (int i = 1; i <= 7; i++)
	{
		if (!(x + i > 7 || y - i < 0))
		{
			if (!mChessBoard[x + i][y - i]->HasPiece())
				mChessBoard[x + i][y - i]->SetMoveHighlight(true);
			else if (mChessBoard[x + i][y - i]->GetOwner() != owner)
			{
				Attack(x + i, y - i);
				break;
			}
			else
				break;
		}
	}
	for (int i = 1; i <= 7; i++)
	{
		if (!(x - i < 0 || y + i > 7))
		{
			if (!mChessBoard[x - i][y + i]->HasPiece())
				mChessBoard[x - i][y + i]->SetMoveHighlight(true);
			else if (mChessBoard[x - i][y + i]->GetOwner() != owner)
			{
				Attack(x - i, y + i);
				break;
			}
			else
				break;
		}
	}
	for (int i = 1; i <= 7; i++)
	{
		if (!(x - i < 0 || y - i < 0))
		{
			if (!mChessBoard[x - i][y - i]->HasPiece())
				mChessBoard[x - i][y - i]->SetMoveHighlight(true);
			else if (mChessBoard[x - i][y - i]->GetOwner() != owner)
			{
				Attack(x - i, y - i);
				break;
			}
			else
				break;
		}
	}
}

void ChessBoard::Attack(int x, int y)
{
	mChessBoard[x][y]->SetAttackHighlight(true);
}

PieceType ChessBoard::HighlightedPiece()
{
	return mChessBoard[mHighlight.GetX()][mHighlight.GetY()]->GetPiece();
}
