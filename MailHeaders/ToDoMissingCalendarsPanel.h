/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSObject.h"

@class NSPopUpButton, NSString, NSTextField;

@interface ToDoMissingCalendarsPanel : NSObject
{
    int _mode;
    NSString *_calendarName;
    BOOL _allowCreateMissingCalendars;
    NSPopUpButton *_calendarMenu;
    NSTextField *_headingText;
    NSTextField *_detailsText;
}

- (id)init;
- (void)dealloc;
- (void)showWithCalendarNames:(id)arg1 accountName:(id)arg2 allowCreateMissingCalendars:(BOOL)arg3;
- (int)selectedMode;
- (id)calendarName;
- (void)confirm:(id)arg1;
- (void)cancel:(id)arg1;

@end

