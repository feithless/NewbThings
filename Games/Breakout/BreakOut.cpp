#include "BreakOut.h"
#include <iostream>
#include "../../Input/GameController.h"
#include "../../Shapes/Ellipse.h"
#include "../../App/App.h"
#include <cmath>


/*
* Paddle
*	- Can move side to side by user
*	- Stops at edge of screen
*	- Width and height 
*	- Color
*	- Bounce ball
*		- Bounces the ball differently based on position that was hit on the paddle
* 
* Ball
*	- Bounce off walls, paddle, bricks
*	- Width and height
*	- Velocity position
*	- Color
* 
* Bricks
*	- Width, height, Color, position (AARect)
*	- Bounces ball
*	- Health
*	- Part of level
* 
* Level 
*	- Container that holds all of the blocks
*	- Should be able to load a level from levels.txt file
*	- Handle collisions of the blocks?
*	- Contain the walls/edges of the screen?
*	- Reset level?
* 
* Game
*	- Contains all objects (paddle, ball, levels)
*	- Player which has 3 lives
*	- States - Serve, In Game, Game Over
*	- Reset game
*/

void BreakOut::Init(GameController& controller)
{
	std::cout << "Break Out Game Init()" << std::endl;
	controller.ClearAll();
	ResetGame();
	ButtonAction leftKeyAction;
	leftKeyAction.key = GameController::LeftKey();
	leftKeyAction.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			mPaddle.SetMovementDirection(PaddleDirection::LEFT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::LEFT);
		}
	};
	controller.AddInputActionForKey(leftKeyAction);

	ButtonAction rightKeyAction;
	rightKeyAction.key = GameController::RightKey();
	rightKeyAction.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			mPaddle.SetMovementDirection(PaddleDirection::RIGHT);
		}
		else
		{
			mPaddle.UnsetMovementDirection(PaddleDirection::RIGHT);
		}
	};
	controller.AddInputActionForKey(rightKeyAction);


}

void BreakOut::Update(uint32_t dt)
{
	mBall.Update(dt);
	mPaddle.Update(dt, mBall);

	BoundaryEdge edge;

	if (mPaddle.Bounce(mBall))
	{
		return;
	}

	if (mLevelBoundary.HasCollided(mBall, edge))
	{
		mBall.Bounce(edge);
		return;
	}

	GetCurrentLevel().Update(dt, mBall);
}

void BreakOut::Draw(Screen& screen)
{
	mBall.Draw(screen);
	mPaddle.Draw(screen);
	GetCurrentLevel().Draw(screen);

	screen.Draw(mLevelBoundary.GetRectanlge(), Color::Magenta());
}

const std::string& BreakOut::GetName() const
{
	static std::string sceneName = "Break Out";
	return sceneName;
}

void BreakOut::ResetGame()
{
	mLevels = BreakOutGameLevel::LoadLevelsFromFile(App::GetBasePath() + "Assets/BreakoutLevels.txt");
	mCurrentLevel = 0;

	AARectangle paddleRect = { 
		Vec2D(
			float(App::Singleton().Width() / 2 - Paddle::PADDLE_WIDTH / 2), 
			float(App::Singleton().Height() - 1.5 * Paddle::PADDLE_HEIGHT)
		),
		int(Paddle::PADDLE_WIDTH), 
		int(Paddle::PADDLE_HEIGHT)
	};
	AARectangle levelBoundary = {
		Vec2D::Zero, App::Singleton().Width(), App::Singleton().Height()
	};
	Ellipse paddleEllipse = {
		paddleRect.GetCenterPoint(),
		float(pow(paddleRect.GetHeight() + 1, 2)),
		2 * float(pow(paddleRect.GetWidth(), 2))
	};
	
	mLevelBoundary = { levelBoundary };
	mPaddle.Init(paddleRect, levelBoundary, paddleEllipse);
	mBall.MoveTo(Vec2D(App::Singleton().Width() / 2, App::Singleton().Height() * 0.75f));

	mBall.SetVelocity(INITIAL_BALL_VEL);
}

void BreakOut::SetToServeState()
{
}
