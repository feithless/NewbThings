#include "InputController.h"
#include "GameController.h"
#include <SDL.h>

InputController::InputController():mQuit(nullptr), mnoptrCurrentController(nullptr)
{

}

void InputController::Init(InputAction quitAction)
{
	mQuit = quitAction;
}

void InputController::Update(uint32_t dt)
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
			case SDL_QUIT:
			{
				mQuit(dt, SDL_PRESSED);
			}
			case SDL_MOUSEMOTION:
			{
				if (mnoptrCurrentController)
				{
					if (MouseMovedAction mouseMoved = mnoptrCurrentController->GetMouseMovedAction())
					{
						MousePosition pos;
						pos.xPos = sdlEvent.motion.x;
						pos.yPos = sdlEvent.motion.y;
						mouseMoved(pos);
					}
				}
				break;
			}
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEBUTTONDOWN:
				if (mnoptrCurrentController)
				{
					MouseInputAction action = mnoptrCurrentController->GetMouseButtonActionForMouseButton(static_cast<MouseButton>(sdlEvent.button.button));

					MousePosition pos;
					pos.xPos = sdlEvent.button.x;
					pos.yPos = sdlEvent.button.y;

					action(static_cast<InputState>(sdlEvent.button.state), pos);
				}
				break;

			case SDL_KEYUP:
			case SDL_KEYDOWN:
				if (mnoptrCurrentController)
				{
					InputAction action = mnoptrCurrentController->GetActionForKey(sdlEvent.key.keysym.sym);

					action(dt, static_cast<InputState>(sdlEvent.key.state));
				}
				break;
		}
	}
}

void InputController::SetGameController(GameController* controller)
{
	mnoptrCurrentController = controller;
}
