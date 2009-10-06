/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSObject.h"

@class NSString, NSTimer;

@interface TemporaryItemManager : NSObject
{
    NSString *_path;
    NSTimer *_timer;
}

+ (void)cleanupAllItems;
+ (id)temporaryItemManagerWithRelativePath:(id)arg1 cleanupInterval:(double)arg2;
- (void)dealloc;
- (id)path;
- (id)expirationDate;
- (void)_setUpTimer:(id)arg1;
- (void)setExpirationDate:(id)arg1;
- (void)cleanUpDirectory;
- (BOOL)fileManager:(id)arg1 shouldProceedAfterError:(id)arg2 removingItemAtPath:(id)arg3;
- (BOOL)fileManager:(id)arg1 shouldProceedAfterError:(id)arg2 removingItemAtURL:(id)arg3;

@end

