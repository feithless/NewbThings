#include "ChessScene.h"
#include "../Shapes/AARectangle.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Triangle.h"
#include "../Shapes/Line2D.h"
#include "../Graphics/Screen.h"
#include "../Input/GameController.h"
#include <iostream>
#include "../Games/Chess/ChessBoard.h"
#include "../Games/Chess/King.h"

ChessScene::ChessScene()
{
	// 
}

void ChessScene::Init()
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

void ChessScene::Update(uint32_t dt)
{	
	mChessBoard.Update(dt);
}

void ChessScene::Draw(Screen& theScreen)
{
	mChessBoard.Draw(theScreen);
}

const std::string& ChessScene::GetSceneName() const
{
	static std::string sceneName = "Chess Game";
	return sceneName;
}

void ChessScene::MoveLeft()
{
	mChessBoard.MoveHighlightLocation(false, false);
}

void ChessScene::MoveRight()
{
	mChessBoard.MoveHighlightLocation(false, true);
}

void ChessScene::MoveUp()
{
	mChessBoard.MoveHighlightLocation(true, false);
}

void ChessScene::MoveDown()
{
	mChessBoard.MoveHighlightLocation(true, true);
}

void ChessScene::Select()
{
}

void ChessScene::DrawLine(Vec2D p1, Vec2D p2, Color outline,  Screen& screen)
{
	Line2D line(p1, p2);
	screen.Draw(line, outline);
}

void ChessScene::DrawThreaded(Screen& screen)
{
}
