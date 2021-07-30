#pragma once

#include "ChessPiece.h"

class Rook : public ChessPiece
{
public:
	Rook();

	virtual void Init(Vec2D offset, int pieceNum, bool isWhite = false) override;
	virtual void Update(uint32_t dt) const override;
	virtual void Draw(Screen& screen) const override;

};