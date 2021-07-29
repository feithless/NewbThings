#pragma once

#include <stdint.h>
#include "Color.h"

struct SDL_Surface;

class ScreenBuffer
{
public:

	ScreenBuffer();
	ScreenBuffer(const ScreenBuffer& screenBuffer);
	~ScreenBuffer();

	ScreenBuffer& operator=(const ScreenBuffer& screenBuffer);

	void Init(uint32_t format, uint32_t w, uint32_t h);

	inline SDL_Surface* GetSurface() { return mSurface; }

	void Clear(const Color& c = Color::Black());

	void SetPixel(const Color& color, int x, int y);

private:

	SDL_Surface* mSurface;
	uint32_t GetIndex(int r, int c);
};

