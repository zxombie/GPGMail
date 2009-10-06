/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSTextFieldCell.h"

@class NSImage;

@interface MailboxListCell : NSTextFieldCell
{
    int rolledOverIndicator;
    BOOL isClickedOn;
    BOOL isPublicOrShared;
    BOOL shouldReverseArrowIndicator;
    BOOL preventInlineTitleEditing;
    int alertState;
    int feedInboxState;
    NSImage *icon;
    unsigned int badgeCount;
    BOOL hasProgressIndicator;
    id item;
}

- (id)badgeTextColor;
- (id)badgeColor;
- (id)indicatorColorForRollover:(BOOL)arg1;
- (void)controlTintChanged:(id)arg1;
- (id)drawIndicator:(int)arg1 withImage:(id)arg2 circled:(BOOL)arg3 cellFrame:(struct CGRect *)arg4 trackingAreaTarget:(id)arg5;
- (id)badgeTextAttributes;
- (void)drawBadgeCenteredInRect:(struct CGRect)arg1;
- (float)badgeWidth;
- (float)idealWidth;
- (id)initTextCell:(id)arg1;
- (id)initImageCell:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)retain;
- (void)release;
- (id)autorelease;
- (void)dealloc;
- (void)setTitle:(id)arg1 retainAttributes:(BOOL)arg2;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)drawInteriorWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (struct CGRect)contentsFrameForCellFrame:(struct CGRect)arg1;
- (void)selectWithFrame:(struct CGRect)arg1 inView:(id)arg2 editor:(id)arg3 delegate:(id)arg4 start:(long)arg5 length:(long)arg6;
- (unsigned long)hitTestForEvent:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (struct CGRect)expansionFrameWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)drawWithExpansionFrame:(struct CGRect)arg1 inView:(id)arg2;
- (id)menuForEvent:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3;
- (id)toolTipForPoint:(struct CGPoint)arg1 rect:(struct CGRect *)arg2 trackingAreas:(id)arg3;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
- (BOOL)accessibilityIsAttributeSettable:(id)arg1;
- (BOOL)preventInlineTitleEditing;
- (void)setPreventInlineTitleEditing:(BOOL)arg1;
- (BOOL)shouldReverseArrowIndicator;
- (void)setShouldReverseArrowIndicator:(BOOL)arg1;
- (id)item;
- (void)setItem:(id)arg1;
- (BOOL)hasProgressIndicator;
- (void)setHasProgressIndicator:(BOOL)arg1;
- (unsigned long)badgeCount;
- (void)setBadgeCount:(unsigned long)arg1;
- (id)icon;
- (void)setIcon:(id)arg1;
- (int)feedInboxState;
- (void)setFeedInboxState:(int)arg1;
- (int)alertState;
- (void)setAlertState:(int)arg1;
- (BOOL)isPublicOrShared;
- (void)setIsPublicOrShared:(BOOL)arg1;
- (BOOL)isClickedOn;
- (void)setIsClickedOn:(BOOL)arg1;
- (int)rolledOverIndicator;
- (void)setRolledOverIndicator:(int)arg1;

@end

