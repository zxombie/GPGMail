/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "AccountSetupEnabler.h"

@interface GoogleAccountSetupEnabler : AccountSetupEnabler
{
    BOOL _isEnabling;
}

+ (BOOL)canHandleHostname:(id)arg1;
- (void)synchronouslyEnable;
- (void)connection:(id)arg1 didReceiveAuthenticationChallenge:(id)arg2;
- (void)connectionDidFinishLoading:(id)arg1;
- (void)connection:(id)arg1 didFailWithError:(id)arg2;

@end

