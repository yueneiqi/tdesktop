/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "window/window_proxy_button_visibility.h"

namespace Window {

const char kOptionKeepProxyButtonVisible[] = "keep-proxy-button-visible";

namespace {

base::options::toggle KeepProxyButtonVisibleToggle({
	.id = kOptionKeepProxyButtonVisible,
	.name = "Always show proxy button",
	.description = "Show the proxy shortcut in the main window even when no proxy is enabled.",
});

rpl::event_stream<bool> &ChangesStream() {
	static auto stream = rpl::event_stream<bool>();
	return stream;
}

} // namespace

base::options::toggle &KeepProxyButtonVisibleOption() {
	return KeepProxyButtonVisibleToggle;
}

void NotifyKeepProxyButtonVisibleChanged() {
	ChangesStream().fire(KeepProxyButtonVisibleOption().value());
}

rpl::producer<bool> KeepProxyButtonVisibleChangesEvents() {
	return ChangesStream().events();
}

} // namespace Window
