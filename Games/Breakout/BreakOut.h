#pragma once
#include "../Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "LevelBoundary.h"
#include "BreakOutGameLevel.h"
#include <vector>

enum BreakOutGameState
{
	IN_PLAY = 0,
	IN_SERVE,
	IN_GAME_OVER
};

class BreakOut : public Game
{
public:

	// Inherited via Game
	virtual void Init(GameController& controller) override;
	virtual void Update(uint32_t dt) override;
	virtual void Draw(Screen& screen) override;
	virtual const std::string& GetName() const override;

private:
	void ResetGame();

	inline BreakOutGameLevel& GetCurrentLevel() { return mLevels[mCurrentLevel]; }

	void SetToServeState();

	const Vec2D INITIAL_BALL_VEL = Vec2D(100, -100);
	Paddle mPaddle;
	Ball mBall;
	LevelBoundary mLevelBoundary;
	BreakOutGameLevel mLevel;
	std::vector<BreakOutGameLevel> mLevels;
	size_t mCurrentLevel;
	BreakOutGameState mGameState;
};

