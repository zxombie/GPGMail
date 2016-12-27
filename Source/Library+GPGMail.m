/* Library+GPGMail.m created by Lukas Pitschl (@lukele) on Wed 13-Jun-2013 */

/*
 * Copyright (c) 2000-2013, GPGTools Team <team@gpgtools.org>
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of GPGTools nor the names of GPGMail
 *       contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE GPGTools Team ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE GPGTools Team BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "CCLog.h"

#import "Library+GPGMail.h"
#import "NSObject+LPDynamicIvars.h"
#import "GPGFlaggedString.h"

#import "MFLibrary.h"
#import "MCMessage.h"
#import "MCMimeBody.h"
#import "MCMimePart.h"

#import "MCAttachment.h"
#import "MFLibraryAttachmentDataSource.h"

#import "MimePart+GPGMail.h"

#define MAIL_SELF(self) ((MFLibrary *)(self))

extern NSString *MCDescriptionForMessageFlags(int arg0);
extern const NSString *kMimeBodyMessageKey;

//@interface Library_GPGMail (NotImplemented)
//
//- (id)dataSource;
//- (id)fullBodyDataForMessage:(id)arg1 andHeaderDataIfReadilyAvailable:(BOOL)arg2 fetchIfNotAvailable:(BOOL)arg3;
//- (id)bodyDataFetchIfNotAvailable:(BOOL)arg1 allowPartial:(BOOL)arg2;
//- (id)headerDataFetchIfNotAvailable:(BOOL)arg1 allowPartial:(BOOL)arg2;
//- (id)initWithEncodedData:(id)arg1;
//- (void)setTopLevelPart:(id)arg1;
//- (void)setMimeBody:(id)arg1;
//+ (id)_messageDataAtPath:(id)arg1;
//+ (id)_dataPathForMessage:(id)arg1 type:(long long)arg2;
//
//
//@end

@implementation Library_GPGMail

/** ONLY FOR Mavericks and then on MFLibrary. */
+ (id)MAPlistDataForMessage:(id)message subject:(id)subject sender:(id)sender to:(id)to dateSent:(id)dateSent dateReceived:(id)dateReceived dateLastViewed:(id)dateLastViewed remoteID:(id)remoteID originalMailboxURLString:(id)originalMailboxURLString gmailLabels:(id)gmailLabels flags:(long long)flags mergeWithDictionary:(id)mergeWithDictionary {
    if([sender isKindOfClass:[GPGFlaggedString class]])
        sender = [(GPGFlaggedString *)sender description];
    if([to isKindOfClass:[GPGFlaggedString class]])
        to = [(GPGFlaggedString *)to description];
    
    return [self MAPlistDataForMessage:message subject:subject sender:sender to:to dateSent:dateSent dateReceived:dateReceived dateLastViewed:dateLastViewed remoteID:remoteID originalMailboxURLString:originalMailboxURLString gmailLabels:gmailLabels flags:flags mergeWithDictionary:mergeWithDictionary];
}

+ (id)MAPlistDataForMessage:(id)message subject:(id)subject sender:(id)sender to:(id)to dateSent:(id)dateSent remoteID:(id)remoteID originalMailbox:(id)originalMailbox flags:(long long)flags mergeWithDictionary:(id)mergeWithDictionary {
    if([sender isKindOfClass:[GPGFlaggedString class]])
        sender = [(GPGFlaggedString *)sender description];
    if([to isKindOfClass:[GPGFlaggedString class]])
        to = [(GPGFlaggedString *)to description];
    
    return [self MAPlistDataForMessage:message subject:subject sender:sender to:to dateSent:dateSent remoteID:remoteID originalMailbox:originalMailbox flags:flags mergeWithDictionary:mergeWithDictionary];
}

+ (NSData *)GMDataForMessage:(MCMessage *)message mimePart:(MCMimePart *)mimePart {
    MCAttachment *attachment = (MCAttachment *)[[MCAttachment alloc] initWithMimePart:mimePart];
    MFLibraryAttachmentDataSource* dataSource = [[MFLibraryAttachmentDataSource alloc] initWithMessage:message mimePartNumber:[mimePart partNumber] attachment:attachment remoteDataSource:nil];
    [attachment setDataSource:dataSource];
    
    return [attachment dataForAccessLevel:2];
}

+ (MCMimeBody *)MAMimeBodyForMessage:(MCMessage *)currentMessage {
    // If the user didn't actively select this message, it doesn't matter
    // if this method returns a partial or not.
    // TODO: Check what happens for a thread. Does each message have the UserSelectedMessage flag set?
    
    if(![[currentMessage getIvar:@"UserSelectedMessage"] boolValue]) {
        return [self MAMimeBodyForMessage:currentMessage];
    }
    
    // Check if the complete data available is already available.
    if([MFLibrary _messageDataAtPath:[MFLibrary _dataPathForMessage:currentMessage type:0]] != nil) {
        MCMimeBody *mimeBody = [self MAMimeBodyForMessage:currentMessage];
        [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
        return mimeBody;
    }
    MCMimeBody *mimeBody = nil;
    NSMutableData *rawMessageData = nil;
//    BOOL fetchingBody = [currentMessage ivarExists:@"BodyFetchingInProgress"];
//    BOOL hasFullBodyData = [currentMessage ivarExists:@"FullBodyDataAvailable"];
//    if(!fetchingBody && !hasFullBodyData) {
//        // Check if the data is available in locally cached attachment files.
//        [currentMessage setIvar:@"BodyFetchingInProgress" value:@YES];
//        MCMimeBody *mimeBody = [self MAMimeBodyForMessage:currentMessage];
//        rawMessageData = [NSMutableData new];
//        NSData *NL = [@"\n" dataUsingEncoding:NSUTF8StringEncoding];
//        NSData *boundaryDelimiter = [@"--" dataUsingEncoding:NSUTF8StringEncoding];
//        __block NSString *currentBoundary = nil;
//        MCMimePart *topLevelPart = [mimeBody topLevelPart];
//        NSString *topBoundary = [topLevelPart bodyParameterForKey:@"boundary"];
//        [(MimePart_GPGMail *)topLevelPart enumerateSubpartsWithBlock:^(MCMimePart *mimePart) {
//            if([[mimePart bodyParameterKeys] containsObject:@"boundary"]) {
//                currentBoundary = [mimePart bodyParameterForKey:@"boundary"];
//            }
//            else {
//                [rawMessageData appendData:boundaryDelimiter];
//                [rawMessageData appendData:[currentBoundary dataUsingEncoding:NSUTF8StringEncoding]];
//                [rawMessageData appendData:NL];
//            }
//            [rawMessageData appendData:[mimePart headerData]];
//            [rawMessageData appendData:[[self class] GMDataForMessage:currentMessage mimePart:mimePart]];
//            [rawMessageData appendData:NL];
//        }];
//        [rawMessageData appendData:boundaryDelimiter];
//        [rawMessageData appendData:[currentBoundary dataUsingEncoding:NSUTF8StringEncoding]];
//        [rawMessageData appendData:boundaryDelimiter];
//        
//        [currentMessage setIvar:@"FullBodyDataAvailable" value:@YES];
//        [currentMessage setIvar:@"FullBodyData" value:rawMessageData];
//        [currentMessage removeIvar:@"BodyFetchingInProgress"];
//    }
//    else if(!hasFullBodyData && fetchingBody) {
//        mimeBody = [self MAMimeBodyForMessage:currentMessage];
//        [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
//        return mimeBody;
//    }
//    else {
//        rawMessageData = [currentMessage getIvar:@"FullBodyData"];
//        DebugLog(@"Full body data already available: %lu", (unsigned long)[rawMessageData length]);
//    }
//
//    NSLog(@"Fetched data: %lu", (unsigned long)[rawMessageData length]);
//    MCMimePart *mimePart = [[MCMimePart alloc] initWithEncodedData:rawMessageData];
//    mimeBody = [MCMimeBody new];
//    [mimeBody setTopLevelPart:mimePart];
//    [mimePart setMimeBody:mimeBody];
//    [mimePart parse];
//    [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
//    return mimeBody;
    
    // Fetch the entire message. This might be optimized based on some data learned from the
    // mime part structure. For example, only fetch the entire message, if a PGP/MIME structure is
    // detected.
    BOOL fetchingBody = [currentMessage ivarExists:@"BodyFetchingInProgress"];
    BOOL hasFullBodyData = [currentMessage ivarExists:@"FullBodyDataAvailable"];
    NSData *messageData = nil;
    if(!fetchingBody && !hasFullBodyData) {
        [currentMessage setIvar:@"BodyFetchingInProgress" value:@YES];
        [currentMessage setIvar:@"FakeContentNotAvailable" value:@YES];
        messageData = [currentMessage messageDataIncludingFromSpace:YES newDocumentID:nil fetchIfNotAvailable:YES];
        [currentMessage setIvar:@"FullBodyData" value:messageData];
        [currentMessage setIvar:@"FullBodyDataAvailable" value:@YES];
        [currentMessage removeIvar:@"BodyFetchingInProgress"];
    }
    else if(!hasFullBodyData && fetchingBody) {
        mimeBody = [self MAMimeBodyForMessage:currentMessage];
        [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
        return mimeBody;
    }
    else {
        messageData = [currentMessage getIvar:@"FullBodyData"];
        DebugLog(@"Full body data already available: %lu", (unsigned long)[messageData length]);
    }

    MCMimePart *mimePart = [[MCMimePart alloc] initWithEncodedData:messageData];
    mimeBody = [MCMimeBody new];
    [mimeBody setTopLevelPart:mimePart];
    [mimePart setMimeBody:mimeBody];
    [mimePart parse];
    [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
    
    return mimeBody;
    
    
//    // Check the structure. If this looks like an interesting.
//    NSMutableData *messageData = nil;
//    BOOL fetchingBody = [currentMessage ivarExists:@"BodyFetchingInProgress"];
//    BOOL hasFullBodyData = [currentMessage ivarExists:@"FullBodyDataAvailable"];
//    if(!hasFullBodyData && !fetchingBody) {
//        [currentMessage setIvar:@"BodyFetchingInProgress" value:@YES];
//        [currentMessage setIvar:@"FakeContentNotAvailable" value:@YES];
//        NSData *headerData = [currentMessage headerDataFetchIfNotAvailable:YES allowPartial:NO];
//        NSData *bodyData = [currentMessage bodyDataFetchIfNotAvailable:YES allowPartial:NO];
//        messageData = [[NSMutableData alloc] initWithData:headerData];
//        [messageData appendData:bodyData];
//        [currentMessage setIvar:@"FullBodyDataAvailable" value:@YES];
//        [currentMessage setIvar:@"FullBodyData" value:messageData];
//        [currentMessage removeIvar:@"BodyFetchingInProgress"];
//        DebugLog(@"Full body data now available: %lu", (unsigned long)[messageData length]);
//    }
//    else if(!hasFullBodyData && fetchingBody) {
//        MCMimeBody *mimeBody = [self MAMimeBodyForMessage:currentMessage];
//        [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
//        return mimeBody;
//    }
//    else {
//        messageData = [currentMessage getIvar:@"FullBodyData"];
//        DebugLog(@"Full body data already available: %lu", (unsigned long)[messageData length]);
//    }
//    
//    MCMimePart *mimePart = [[MCMimePart alloc] initWithEncodedData:messageData];
//    MCMimeBody *mimeBody = [MCMimeBody new];
//    [mimeBody setTopLevelPart:mimePart];
//    [mimePart setMimeBody:mimeBody];
//    [mimePart parse];
//    [mimeBody setIvar:kMimeBodyMessageKey value:currentMessage];
//    return mimeBody;
}

+ (id)MAParsedMessageForMessage:(id)message {
    MCMimeBody *mimeBody = [[MAIL_SELF(self) class] mimeBodyForMessage:message];
    if(!mimeBody) {
        return [self MAParsedMessageForMessage:message];
    }
    
    // Check if there's a decrypted mimeBody on the mimeBody.
    MCMimeBody *decryptedMimeBody = [[mimeBody topLevelPart] decryptedMimeBodyIsEncrypted:NULL isSigned:NULL error:nil];
    if(!decryptedMimeBody) {
        // Make sure the message is decoded.
        id parsedMessage = [mimeBody parsedMessage];
        // TODO: Might need some error checking so we don't repeatedly try to get a decrypted mime body, even though decryption fails.
        decryptedMimeBody = [[mimeBody topLevelPart] decryptedMimeBodyIsEncrypted:NULL isSigned:NULL error:nil];
    }
    
    if(decryptedMimeBody) {
        return [decryptedMimeBody parsedMessage];
    }
    
    return [self MAParsedMessageForMessage:message];
}

+ (BOOL)MAIsMessageContentLocallyAvailable:(id)arg1 {
    BOOL ret = [self MAIsMessageContentLocallyAvailable:arg1];
    if([[arg1 getIvar:@"FakeContentNotAvailable"] boolValue]) {
        [arg1 removeIvar:@"FakeContentNotAvailable"];
        return NO;
    }
    return ret;
}

@end
