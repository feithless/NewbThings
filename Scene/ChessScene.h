#pragma once
#include "Scene.h"
#include <memory>
#include "../Games/Chess/ChessBoard.h"
#include "../Utils/Vec2D.h"

class Screen;
class Vec2D;
class Color;


class ChessScene : public Scene
{
public:
	ChessScene();
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

	// Internal use only
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	void Select();

private:
	void DrawLine(Vec2D p1, Vec2D p2, Color outline, Screen& screen);
	void DrawThreaded(Screen& screen);
	Vec2D mMousePosition;
	int mCurrentPlayer;
	ChessBoard mChessBoard;
};