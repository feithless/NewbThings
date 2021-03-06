#include "ArcadeScene.h"

#include "../Input/GameController.h"
#include <iostream>

void ArcadeScene::Init()
{
	ButtonAction action;
	action.key = GameController::ActionKey();
	action.action = [this](uint32_t dt, InputState state)
	{
		if (GameController::IsPressed(state))
		{
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
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen& theScreen)
{
}

const std::string& ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Arcade Scene";
	return sceneName;
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
