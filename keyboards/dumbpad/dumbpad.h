/* Copyright 2020 imchipwood
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#if defined(KEYBOARD_dumbpad_v0x)
  #include "v0x.h"
#elif defined(KEYBOARD_dumbpad_v0x_dualencoder)
  #include "v0x_dualencoder.h"
#elif defined(KEYBOARD_dumbpad_v0x_right)
  #include "v0x_right.h"
#endif // dumbpad revisions
