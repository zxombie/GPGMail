/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSObject.h"

#import "QueryProgressMonitor-Protocol.h"

@interface UnreadQueryProgressMonitor : NSObject <QueryProgressMonitor>
{
    unsigned int sequenceNumber;
    int librarySequenceNumber;
}

- (id)initWithSequenceNumber:(unsigned long)arg1 librarySequenceNumber:(long)arg2;
- (BOOL)shouldCancel;

@end

