/*
   Copyright (C) 2003 - 2018 the Battle for Wesnoth Project https://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#pragma once

#include <SDL2/SDL_touch.h>

namespace sdl
{

class touch_device
{
	SDL_TouchID id_;
	SDL_TouchDeviceType type_;

	float diagonal_inches_;

public:
	touch_device(SDL_TouchID id, SDL_TouchDeviceType type);

	// So far, I only need it to translate SDL_MULTIGESTURE mgesture.dDist to inches; 
	// in it, we don't know if it's vertical or horizontal.
	float get_diagonal_inches() const;

	SDL_TouchDeviceType get_type() const;
};

extern touch_device dummy_touch_device;

}
