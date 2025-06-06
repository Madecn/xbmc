/*
 *  Copyright (C) 2023 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "settings/ISubSettings.h"
#include "settings/lib/Setting.h"

#include <vector>

class CServicesSettings : public ISubSettings
{
public:
  static void SettingOptionsChunkSizesFiller(const SettingConstPtr& setting,
                                             std::vector<IntegerSettingOption>& list,
                                             int& current);
  static void SettingOptionsBufferModesFiller(const SettingConstPtr& setting,
                                              std::vector<IntegerSettingOption>& list,
                                              int& current);
  static void SettingOptionsMemorySizesFiller(const SettingConstPtr& setting,
                                              std::vector<IntegerSettingOption>& list,
                                              int& current);
  static void SettingOptionsReadFactorsFiller(const SettingConstPtr& setting,
                                              std::vector<IntegerSettingOption>& list,
                                              int& current);
  static void SettingOptionsCacheChunkSizesFiller(const SettingConstPtr& setting,
                                                  std::vector<IntegerSettingOption>& list,
                                                  int& current);
  static void SettingOptionsSmbVersionsFiller(const SettingConstPtr& setting,
                                              std::vector<IntegerSettingOption>& list,
                                              int& current);
};
