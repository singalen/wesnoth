/*
 Copyright (C) 2014 - 2016 by Google Inc.
 Part of the Battle for Wesnoth Project https://www.wesnoth.org/

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY.

 See the COPYING file for more details.
*/

#ifdef __APPLE__

#include "desktop/apple_notification.hpp"
#include "TargetConditionals.h"

#import <Foundation/Foundation.h>

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#define HAVE_IOS_NOTIFICATION
#endif

namespace apple_notifications {

bool available() {
	Class notificationClass = NSClassFromString(@"NSUserNotificationCenter");
	if(notificationClass) {
		return true;
	}
	return false;
}

#ifdef HAVE_COCOA_NOTIFICATION
void send_cocoa_notification(const std::string& owner, const std::string& message);
#endif

#ifdef HAVE_IOS_NOTIFICATION
	void send_ios_notification(const std::string& owner, const std::string& message, const desktop::notifications::type note_type);
#endif

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-parameter"
void send_notification(const std::string& owner, const std::string& message, const desktop::notifications::type note_type) {
#ifdef HAVE_COCOA_NOTIFICATION
    @autoreleasepool {
        Class appleNotificationClass = NSClassFromString(@"NSUserNotificationCenter");
        if (appleNotificationClass) {
            send_cocoa_notification(owner, message);
        }
    }
#endif
#ifdef HAVE_IOS_NOTIFICATION
    @autoreleasepool {
        send_ios_notification(owner, message, note_type);
    }
#endif
}

#pragma clang diagnostic pop

#ifdef HAVE_COCOA_NOTIFICATION
void send_cocoa_notification(const std::string& owner, const std::string& message) {
    NSString *title = [NSString stringWithCString:owner.c_str() encoding:NSUTF8StringEncoding];
    NSString *description = [NSString stringWithCString:message.c_str() encoding:NSUTF8StringEncoding];
    NSUserNotification *notification = [[NSUserNotification alloc] init];
    notification.title = title;
    notification.informativeText = description;
    notification.deliveryDate = [NSDate date];

    [[NSUserNotificationCenter defaultUserNotificationCenter] scheduleNotification:notification];
}
#endif

#ifdef HAVE_IOS_NOTIFICATION
	void send_ios_notification(const std::string& owner, const std::string& message, const desktop::notifications::type note_type)
	{
		// TODO: rewrite, add IOS version-specific ifdefs.
		NSString *notificationName = @"";
		switch (note_type) {
			case desktop::notifications::CHAT:
				notificationName = @"Chat Message";
				break;
			case desktop::notifications::TURN_CHANGED:
				notificationName = @"Turn Changed";
				break;
			case desktop::notifications::OTHER:
				notificationName = @"Wesnoth";
				break;
		}
		NSString *title = [NSString stringWithCString:owner.c_str() encoding:NSUTF8StringEncoding];
		NSString *description = [NSString stringWithCString:message.c_str() encoding:NSUTF8StringEncoding];

		UILocalNotification *notification = [[UILocalNotification alloc]init];
		notification.repeatInterval = NSDayCalendarUnit;
		// 8.2+
		[notification setAlertTitle: title];
		[notification setAlertBody: description];
		[notification setFireDate:[NSDate dateWithTimeIntervalSinceNow:1]];
		[notification setTimeZone:[NSTimeZone  defaultTimeZone]];
		[[UIApplication sharedApplication] scheduleLocalNotification:notification];

	}
#endif

}
#endif //end __APPLE__
