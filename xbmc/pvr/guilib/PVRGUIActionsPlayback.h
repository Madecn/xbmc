/*
 *  Copyright (C) 2016-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#pragma once

#include "pvr/IPVRComponent.h"
#include "utils/ContentUtils.h"

#include <memory>
#include <string>

class CFileItem;

namespace PVR
{
class CPVRSettings;

enum class PlaybackType
{
  TYPE_ANY,
  TYPE_TV,
  TYPE_RADIO,
};

class CPVRGUIActionsPlayback : public IPVRComponent
{
public:
  CPVRGUIActionsPlayback();
  ~CPVRGUIActionsPlayback() override;

  /*!
   * @brief Play recording.
   * @param item containing a recording or an epg tag.
   * @return true on success, false otherwise.
   */
  bool PlayRecording(const CFileItem& item) const;

  /*!
   * @brief Play EPG tag.
   * @param item containing an epg tag.
   * @param mode playback mode.
   * @return true on success, false otherwise.
   */
  bool PlayEpgTag(
      const CFileItem& item,
      ContentUtils::PlayMode mode = ContentUtils::PlayMode::CHECK_AUTO_PLAY_NEXT_ITEM) const;

  /*!
   * @brief Switch channel.
   * @param item containing a channel or an epg tag.
   * @return true on success, false otherwise.
   */
  bool SwitchToChannel(const CFileItem& item) const;

  /*!
   * @brief Playback the given file item.
   * @param item containing a channel or a recording.
   * @return True if the item could be played, false otherwise.
   */
  bool PlayMedia(const CFileItem& item) const;

  /*!
   * @brief Start playback of the last played channel, and if there is none, play first channel in
   * the current channelgroup.
   * @param type The type of playback to be started (any, radio, tv). See PlaybackType enum
   * @return True if playback was started, false otherwise.
   */
  bool SwitchToChannel(PlaybackType type) const;

  /*!
   * @brief Plays the last played channel or the first channel of TV or Radio on startup.
   * @return True if playback was started, false otherwise.
   */
  bool PlayChannelOnStartup() const;

  /*!
   * @brief Seek to the start of the next epg event in timeshift buffer, relative to the currently
   * playing event. If there is no next event, seek to the end of the currently playing event (to
   * the 'live' position).
   */
  void SeekForward() const;

  /*!
   * @brief Seek to the start of the previous epg event in timeshift buffer, relative to the
   * currently playing event or if there is no previous event or if playback time is greater than
   * given threshold, seek to the start of the playing event.
   * @param iThreshold the value in seconds to trigger seek to start of current event instead of
   * start of previous event.
   */
  void SeekBackward(unsigned int iThreshold) const;

private:
  CPVRGUIActionsPlayback(const CPVRGUIActionsPlayback&) = delete;
  CPVRGUIActionsPlayback const& operator=(CPVRGUIActionsPlayback const&) = delete;

  /*!
   * @brief Check "play minimized" settings value and switch to fullscreen if not set.
   * @param bFullscreen switch to fullscreen or set windowed playback.
   */
  void CheckAndSwitchToFullscreen(bool bFullscreen) const;

  std::unique_ptr<CPVRSettings> m_settings;
};

namespace GUI
{
// pretty scope and name
using Playback = CPVRGUIActionsPlayback;
} // namespace GUI

} // namespace PVR
