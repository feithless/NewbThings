#pragma once

#include <stdint.h>
#include <vector>
#include "ScreenBuffer.h"
#include "Color.h"

class Line2D;
class Vec2D;
class Triangle;
class Circle;
class AARectangle;
struct SDL_Window;
struct SDL_Surface;

class Screen
{
public:

	Screen();
	~Screen();

	SDL_Window* Init(uint32_t w, uint32_t h, uint32_t mag);
	void SwapScreen();

	inline void SetClearColor(const Color& clearColor) { mClearColor = clearColor; }
	inline uint32_t Width() const { return mWidth; }
	inline uint32_t Height() const { return mHeight; }

	void PreDraw();
	void PostDraw();

	// Drawing methods goes here.
	
	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);
	void Draw(const Triangle& triangle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
	void Draw(const AARectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
	void Draw(const Circle& circle, const Color& color, bool fill = false, const Color& fillColor = Color::White());

private:

	Screen(const Screen& screen);
	Screen& operator=(const Screen& screen);

	void ClearScreen();
	void FillPoly(const std::vector<Vec2D>& points, const Color& color);

	uint32_t mWidth;
	uint32_t mHeight;

	bool mBackLocked;

	Color mClearColor;
	ScreenBuffer mBackBuffer;

	SDL_Window* moptrWindow;
	SDL_Surface* mnoptrWindowSurface;
};