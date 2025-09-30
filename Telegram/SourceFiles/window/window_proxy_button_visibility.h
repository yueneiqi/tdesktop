/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

#include <rpl/producer.h>

namespace Window {

extern const char kOptionProxyAlwaysVisible[];
[[nodiscard]] bool ProxyAlwaysVisible();
[[nodiscard]] rpl::producer<> ProxyAlwaysVisibleValue();
void NotifyProxyAlwaysVisibleChange();

} // namespace Window
