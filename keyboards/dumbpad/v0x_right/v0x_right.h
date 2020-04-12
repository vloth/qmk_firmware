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

#include "dumbpad.h"

#define LAYOUT( \
    k04, k03, k02, k01, \
    k14, k13, k12, k11, \
    k24, k23, k22, k21, \
    k34, k33, k32, k31, k30 \
) \
{ \
    { k04, k03, k02, k01, KC_NO }, \
    { k14, k13, k12, k11, KC_NO }, \
    { k24, k23, k22, k21, KC_NO }, \
    { k34, k33, k32, k31, k30   }, \
}
