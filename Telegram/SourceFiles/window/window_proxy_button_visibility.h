/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <QtCore/QString>
#include "base/basic_types.h"
#include "base/options.h"
#include "rpl/rpl.h"

namespace Window {

extern const char kOptionKeepProxyButtonVisible[];

base::options::toggle &KeepProxyButtonVisibleOption();
void NotifyKeepProxyButtonVisibleChanged();
rpl::producer<bool> KeepProxyButtonVisibleChangesEvents();

} // namespace Window

