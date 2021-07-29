#pragma once
#include "Scene.h"
#include <memory>
#include "../Games/Chess/ChessBoard.h"
#include "../Utils/Vec2D.h"

class Screen;
class Vec2D;
class Color;

enum eGame
{
	TETRIS = 0,
	BREAK_OUT,
	ASTEROIDS,
	PACMAN,
	NUM_GAMES
};

class ArcadeScene : public Scene
{
public:
	ArcadeScene();
	virtual void Init() override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& theScreen) override;
	virtual const std::string& GetSceneName() const override;

private:
	void DrawLine(Vec2D p1, Vec2D p2, Color outline, Screen& screen);
	void DrawThreaded(Screen& screen);
	Vec2D mMousePosition;
	std::unique_ptr<Scene> GetScene(eGame game);
	ChessBoard mChessBoard;
};