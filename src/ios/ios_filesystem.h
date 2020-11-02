/*
 Copyright (C) 2019 by Victor Sergienko <singalen@g.com>
 Part of the Battle for Wesnoth Project https://www.wesnoth.org/
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY.
 
 See the COPYING file for more details.
 */

#ifndef ios_filesystem_h
#define ios_filesystem_h

#ifdef __cplusplus
extern "C" {
#endif

char *Wesnoth_ICloud_GetDocumentsPath();
void Wesnoth_ICloud_StartSync();
bool Wesnoth_ICloud_Delete(const char *file_name);

#ifdef __cplusplus
}
#endif

#endif /* ios_filesystem_h */
