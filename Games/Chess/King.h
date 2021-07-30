#pragma once
#include "ChessPiece.h"
class King : public ChessPiece
{

public:
	// Inherited via ChessPiece
	virtual void Init(Vec2D offset, int pieceNum, bool isWhite = false) override;
	virtual void Update(uint32_t dt) const override;
	virtual void Draw(Screen& screen) const override;
};

