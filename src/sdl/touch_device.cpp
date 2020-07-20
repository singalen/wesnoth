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

#include "touch_device.hpp"

#ifdef __IPHONEOS__
#include "ios/iOS_device_info.hpp"
#include <cmath>
#endif

namespace sdl {

// The value supposedly used by iOS SDL implementation.
const int directTouchId = 1;
touch_device dummy_touch_device(directTouchId, SDL_TOUCH_DEVICE_DIRECT);

static const int DUMMY_DISPLAY_SIZE_INCHES = 15;

touch_device::touch_device(SDL_TouchID id, SDL_TouchDeviceType type) :
	id_(id), type_(type)
{
#ifndef __IPHONEOS__
	diagonal_inches_ = DUMMY_DISPLAY_SIZE_INCHES;
#else

	const int width_px = iOS_device_info::get_device_screen_physical_width_px();
	const int height_px = iOS_device_info::get_device_screen_physical_height_px();
	const int dpi = iOS_device_info::get_device_screen_dpi();
	
	diagonal_inches_ = (dpi != 0 && width_px != 0) 
		? static_cast<float>(std::hypot(width_px, height_px)) / dpi 
		: DUMMY_DISPLAY_SIZE_INCHES;
#endif
}

float touch_device::get_diagonal_inches() const
{
	return diagonal_inches_;
}

SDL_TouchDeviceType touch_device::get_type() const
{
	return type_;
}

}
