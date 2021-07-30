#pragma once
#include "ChessPiece.h"
class Bishop : public ChessPiece
{
public:

	Bishop();

	// Inherited via ChessPiece
	virtual void Init(Vec2D offset, int pieceNum, bool isWhite = false) override;
	virtual void Update(uint32_t dt) const override;
	virtual void Draw(Screen& screen) const override;
};

