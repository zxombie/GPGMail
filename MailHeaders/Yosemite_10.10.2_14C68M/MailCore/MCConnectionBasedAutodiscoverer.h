/*
 *     Generated by class-dump 3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2012 by Steve Nygard.
 */

#import "NSObject.h"

@interface MCConnectionBasedAutodiscoverer : NSObject
{
    BOOL _shouldCancel;
    long long _autoconfigurationStatus;
}

+ (id)userNameForEmailAddress:(id)arg1 accountSettings:(id)arg2;
+ (id)serverNameFromAccountSettings:(id)arg1;
@property BOOL shouldCancel; // @synthesize shouldCancel=_shouldCancel;
@property long long autoconfigurationStatus; // @synthesize autoconfigurationStatus=_autoconfigurationStatus;
- (void)cancel;
- (void)discoverSettingsForDomain:(id)arg1 receivingAccountSettings:(id *)arg2 sendingAccountsSettings:(id *)arg3;
- (id)init;

@end

