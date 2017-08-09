//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSButton.h"

@class ConversationMember, NSTrackingArea;

@interface UnreadVIPButton : NSButton
{
    ConversationMember *_representedObject;	// 176 = 0xb0
    BOOL _showVIPButton;	// 184 = 0xb8
    NSTrackingArea *_vipButtonTrackingArea;	// 192 = 0xc0
}

@property(retain, nonatomic) NSTrackingArea *vipButtonTrackingArea; // @synthesize vipButtonTrackingArea=_vipButtonTrackingArea;
- (void).cxx_destruct;	// IMP=0x000000010030f2bf
- (void)observeValueForKeyPath:(id)arg1 ofObject:(id)arg2 change:(id)arg3 context:(void *)arg4;	// IMP=0x000000010030f1ac
- (void)_unregisterKVOForRepresentedObject:(id)arg1;	// IMP=0x000000010030f133
- (void)_registerKVOForRepresentedObject:(id)arg1;	// IMP=0x000000010030f0b4
@property(retain, nonatomic) ConversationMember *representedObject;
@property(nonatomic) BOOL showVIPButton;
- (void)resetCursorRects;	// IMP=0x000000010030eef2
- (void)mouseExited:(id)arg1;	// IMP=0x000000010030eede
- (void)mouseEntered:(id)arg1;	// IMP=0x000000010030eec7
- (void)cursorUpdate:(id)arg1;	// IMP=0x000000010030edde
- (void)updateTrackingAreas;	// IMP=0x000000010030ebf9
- (void)_updateUnreadVIPButton;	// IMP=0x000000010030e4a5

@end
