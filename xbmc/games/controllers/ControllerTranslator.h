/*
 *  Copyright (C) 2015-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "ControllerTypes.h"
#include "input/joysticks/JoystickTypes.h"

#include <string>
#include <string_view>

namespace KODI
{
namespace GAME
{

/*!
 * \ingroup games
 */
class CControllerTranslator
{
public:
  static const char* TranslateFeatureType(JOYSTICK::FEATURE_TYPE type);
  static JOYSTICK::FEATURE_TYPE TranslateFeatureType(const std::string& strType);

  static const char* TranslateFeatureCategory(JOYSTICK::FEATURE_CATEGORY category);
  static JOYSTICK::FEATURE_CATEGORY TranslateFeatureCategory(const std::string& strCategory);

  static const char* TranslateInputType(JOYSTICK::INPUT_TYPE type);
  static JOYSTICK::INPUT_TYPE TranslateInputType(const std::string& strType);

  static PORT_TYPE TranslatePortType(std::string_view strPortType);
  static const char* TranslatePortType(PORT_TYPE portType);
};

} // namespace GAME
} // namespace KODI
