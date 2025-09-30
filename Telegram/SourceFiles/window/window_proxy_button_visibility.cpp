/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "window/window_proxy_button_visibility.h"

#include "base/options.h"
#include <rpl/event_stream.h>

namespace Window {
namespace {

base::options::toggle ProxyAlwaysVisibleOption({
	.id = kOptionProxyAlwaysVisible,
	.name = "Always show proxy button",
	.description = "Keep the proxy button visible even when no proxy is enabled. Useful for quick access to proxy settings.",
});

rpl::event_stream<> ProxyAlwaysVisibleChanges;

} // namespace

const char kOptionProxyAlwaysVisible[] = "proxy-always-visible";

bool ProxyAlwaysVisible() {
	return ProxyAlwaysVisibleOption.value();
}

rpl::producer<> ProxyAlwaysVisibleValue() {
	return ProxyAlwaysVisibleChanges.events();
}

void NotifyProxyAlwaysVisibleChange() {
	ProxyAlwaysVisibleChanges.fire({});
}

} // namespace Window
