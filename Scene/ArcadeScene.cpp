#include "ArcadeScene.h"
#include "../Shapes/AARectangle.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Line2D.h"
#include "../Graphics/Screen.h"
#include "../Input/GameController.h"
#include "../Games/Chess.h"
#include <iostream>
#include "../Games/Chess/ChessBoard.h"
#include "../Games/Chess/King.h"

ArcadeScene::ArcadeScene()
{
	// 
}

void ArcadeScene::Init()
{

	ButtonAction action;
	action.key = GameController::ActionKey();
	action.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			this->Select();
		}
	};
	mGameController.AddInputActionForKey(action);

	ButtonAction left;
	left.key = GameController::LeftKey();
	left.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Left key pressed" << std::endl;
			this->MoveLeft();
		}
	};
	mGameController.AddInputActionForKey(left);
	ButtonAction right;
	right.key = GameController::RightKey();
	right.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Right key pressed" << std::endl;
			this->MoveRight();
		}
	};
	mGameController.AddInputActionForKey(right);
	ButtonAction up;
	up.key = GameController::UpKey();
	up.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Up key pressed" << std::endl;
			this->MoveUp();
		}
	};
	mGameController.AddInputActionForKey(up);
	ButtonAction down;
	down.key = GameController::DownKey();
	down.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Down key pressed" << std::endl;
			this->MoveDown();
		}
	};
	mGameController.AddInputActionForKey(down);

	MouseButtonAction mouseAction;
	mouseAction.mouseButton = GameController::LeftMouseButton();
	mouseAction.mouseInputAction = [](InputState state, const MousePosition& pos)
	{
		if (GameController::IsPressed(state))
		{
			std::cout << "Mouse button pressed." << std::endl;
		}
	};

	mGameController.AddMouseButtonAction(mouseAction);
	mGameController.SetMouseMovedAction([](const MousePosition& mousePos) {
		// std::cout << "Mouse position x: " << mousePos.xPos << " y: " << mousePos.yPos << std::endl;
		});

	mChessBoard.Init();


}

void ArcadeScene::Update(uint32_t dt)
{
	MouseMovedAction m = mGameController.GetMouseMovedAction();
	
	mChessBoard.Update(dt);
}

void ArcadeScene::Draw(Screen& theScreen)
{
	// TODO: Figure out how to thread this shit?
	mChessBoard.Draw(theScreen);

	//King k;
	//k.Init(Vec2D(3, 0), 0, true);
	//k.Draw(theScreen);
}

const std::string& ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Arcade Scene";
	return sceneName;
}

void ArcadeScene::MoveLeft()
{
	mChessBoard.MoveHighlightLocation(false, false);
}

void ArcadeScene::MoveRight()
{
	mChessBoard.MoveHighlightLocation(false, true);
}

void ArcadeScene::MoveUp()
{
	mChessBoard.MoveHighlightLocation(true, false);
}

void ArcadeScene::MoveDown()
{
	mChessBoard.MoveHighlightLocation(true, true);
}

void ArcadeScene::Select()
{
}

void ArcadeScene::DrawLine(Vec2D p1, Vec2D p2, Color outline,  Screen& screen)
{
	Line2D line(p1, p2);
	screen.Draw(line, outline);
}

void ArcadeScene::DrawThreaded(Screen& screen)
{
}

std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
	switch (game)
	{
		case TETRIS:
		{

		}
		break;

		case BREAK_OUT:
		{

		}
		break;

		case ASTEROIDS:
		{

		}
		break;

		case PACMAN:
		{

		}
		break;

		default:
		{

		}
		break;
	}

	return nullptr;
}
