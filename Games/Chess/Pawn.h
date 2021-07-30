#pragma once
#include "../Chess.h"
#include "ChessPiece.h"

class Pawn :
    public ChessPiece
{
public:

    Pawn();

    virtual void Init(Vec2D offset, int pieceNum, bool isWhite = false) override;
    virtual void Update(uint32_t dt) const override;
    virtual void Draw(Screen& screen) const override;

private:
    bool mHasMoved;
};

