#pragma once

#include "ChessPiece.h"

class Color;
class Vec2D;
class Screen;
class ChessBoard;

class Knight : public ChessPiece
{
public:
    Knight();

    virtual void Init(Vec2D offset, int pieceNum, bool isWhite = false) override;
    virtual void Update(uint32_t dt) const override;
    virtual void Draw(Screen& screen) const override;
    virtual void MoveRules(ChessBoard& chessBoard) override;

private:
    void DrawLine(Vec2D p1, Vec2D p2, Color outline, Screen& screen) const;

};