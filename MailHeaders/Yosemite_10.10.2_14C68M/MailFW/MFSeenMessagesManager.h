/*
 *     Generated by class-dump 3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2012 by Steve Nygard.
 */

#import "NSObject.h"

@class NSManagedObjectContext;

@interface MFSeenMessagesManager : NSObject
{
    id _account;
    NSManagedObjectContext *_managedObjectContext;
}

@property(retain, nonatomic) NSManagedObjectContext *managedObjectContext; // @synthesize managedObjectContext=_managedObjectContext;
@property(retain, nonatomic) id account; // @synthesize account=_account;
- (void).cxx_destruct;
- (void)_configureManagedObjectContext;
- (void)saveChanges;
- (void)removeMessagesNotOnServer:(id)arg1;
- (void)removeServerDeletedMessages;
- (id)messagesToBeDeletedFromServer;
- (id)seenMessages;
- (void)removeMessageIDs:(id)arg1;
- (id)addMessageID:(id)arg1 dateSeen:(id)arg2;
- (unsigned long long)countOfSeenMessages;
- (id)seenMessageForMessageID:(id)arg1;
- (id)_addAccountWithID:(id)arg1;
- (id)_accountForAccountID:(id)arg1;
- (id)init;
- (id)initWithAccountID:(id)arg1 createAccount:(BOOL)arg2;

@end
