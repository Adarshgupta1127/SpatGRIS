/*
 This file is part of SpatGRIS.

 Developers: Samuel B�land, Olivier B�langer, Nicolas Masson

 SpatGRIS is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 SpatGRIS is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with SpatGRIS.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <array>

#include "macros.h"

DISABLE_WARNINGS
#include "spat/lbap.h"
ENABLE_WARNINGS

#include "constants.hpp"

//==============================================================================
struct LbapData {
    lbap_pos pos;
    std::array<float, MAX_OUTPUTS> gains;
    std::array<float, MAX_OUTPUTS> y;
};
