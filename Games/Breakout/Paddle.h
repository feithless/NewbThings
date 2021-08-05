#pragma once
#include "Excluder.h"
#include <stdint.h>
#include "../../Shapes/Ellipse.h"

class Screen;
class Ball;

enum PaddleDirection
{
	LEFT = 1 << 0,
	RIGHT = 1 << 1
};

class Paddle : public Excluder
{
public:
	static const uint32_t PADDLE_WIDTH = 50;
	static const uint32_t PADDLE_HEIGHT = 10;
	void Init(const AARectangle& rect, const AARectangle& boundary, const Ellipse& bouncy);

	void Update(uint32_t dt, Ball& ball);

	void Draw(Screen& screen);

	inline bool IsMovingLeft() const { return mDirection == PaddleDirection::LEFT; }
	inline bool IsMovingRight() const { return mDirection == PaddleDirection::RIGHT; }

	bool Bounce(Ball& ball);

	// I don't understand this.
	//~00 -> 11
	// 0 | 1 = 1
	// 0 & 1 = 0
	// 1 & 1 = 1
	inline void SetMovementDirection(PaddleDirection dir) { mDirection |= dir; }
	inline void UnsetMovementDirection(PaddleDirection dir) { mDirection &= ~dir; }
	inline void StopMovement() { mDirection = 0; }
	inline Ellipse GetEllipse() const { return mEllipse; }



private:
	uint32_t mDirection; // Direction of movement.
	AARectangle mBoundary; // boundary confinement
	Ellipse mEllipse;

	const float VELOCITY = 100.0f; // pixels/sec 
	const float CORNER_BOUNCE_AMT = 0.2f;
};

