/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2004 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "IPrimaryScreen.h"

//
// IPrimaryScreen
//

CEvent::Type		IPrimaryScreen::s_keyDownEvent         = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_keyUpEvent           = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_keyRepeatEvent       = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_buttonDownEvent      = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_buttonUpEvent        = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_motionPrimaryEvent   = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_motionSecondaryEvent = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_wheelEvent           = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_ssActivatedEvent     = CEvent::kUnknown;
CEvent::Type		IPrimaryScreen::s_ssDeactivatedEvent   = CEvent::kUnknown;

CEvent::Type
IPrimaryScreen::getKeyDownEvent()
{
	return CEvent::registerTypeOnce(s_keyDownEvent,
							"IPrimaryScreen::keyDown");
}

CEvent::Type
IPrimaryScreen::getKeyUpEvent()
{
	return CEvent::registerTypeOnce(s_keyUpEvent,
							"IPrimaryScreen::keyUp");
}

CEvent::Type
IPrimaryScreen::getKeyRepeatEvent()
{
	return CEvent::registerTypeOnce(s_keyRepeatEvent,
							"IPrimaryScreen::keyRepeat");
}

CEvent::Type
IPrimaryScreen::getButtonDownEvent()
{
	return CEvent::registerTypeOnce(s_buttonDownEvent,
							"IPrimaryScreen::buttonDown");
}

CEvent::Type
IPrimaryScreen::getButtonUpEvent()
{
	return CEvent::registerTypeOnce(s_buttonUpEvent,
							"IPrimaryScreen::buttonUp");
}

CEvent::Type
IPrimaryScreen::getMotionOnPrimaryEvent()
{
	return CEvent::registerTypeOnce(s_motionPrimaryEvent,
							"IPrimaryScreen::motionPrimary");
}

CEvent::Type
IPrimaryScreen::getMotionOnSecondaryEvent()
{
	return CEvent::registerTypeOnce(s_motionSecondaryEvent,
							"IPrimaryScreen::motionSecondary");
}

CEvent::Type
IPrimaryScreen::getWheelEvent()
{
	return CEvent::registerTypeOnce(s_wheelEvent,
							"IPrimaryScreen::wheel");
}

CEvent::Type
IPrimaryScreen::getScreensaverActivatedEvent()
{
	return CEvent::registerTypeOnce(s_ssActivatedEvent,
							"IPrimaryScreen::screensaverActivated");
}

CEvent::Type
IPrimaryScreen::getScreensaverDeactivatedEvent()
{
	return CEvent::registerTypeOnce(s_ssDeactivatedEvent,
							"IPrimaryScreen::screensaverDeactivated");
}


//
// IPrimaryScreen::CKeyInfo
//

IPrimaryScreen::CKeyInfo*
IPrimaryScreen::CKeyInfo::alloc(KeyID id,
				KeyModifierMask mask, KeyButton button, SInt32 count)
{
	CKeyInfo* info = (CKeyInfo*)malloc(sizeof(CKeyInfo));
	info->m_key    = id;
	info->m_mask   = mask;
	info->m_button = button;
	info->m_count  = count;
	return info;
}


//
// IPrimaryScreen::CButtonInfo
//

IPrimaryScreen::CButtonInfo*
IPrimaryScreen::CButtonInfo::alloc(ButtonID id)
{
	CButtonInfo* info = (CButtonInfo*)malloc(sizeof(CButtonInfo));
	info->m_button = id;
	return info;
}


//
// IPrimaryScreen::CMotionInfo
//

IPrimaryScreen::CMotionInfo*
IPrimaryScreen::CMotionInfo::alloc(SInt32 x, SInt32 y)
{
	CMotionInfo* info = (CMotionInfo*)malloc(sizeof(CMotionInfo));
	info->m_x = x;
	info->m_y = y;
	return info;
}


//
// IPrimaryScreen::CWheelInfo
//

IPrimaryScreen::CWheelInfo*
IPrimaryScreen::CWheelInfo::alloc(SInt32 wheel)
{
	CWheelInfo* info = (CWheelInfo*)malloc(sizeof(CWheelInfo));
	info->m_wheel = wheel;
	return info;
}
