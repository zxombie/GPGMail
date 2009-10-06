/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSTextAttachmentCell.h"

@class AddressAttachment, NSMenu, NSMutableDictionary, NSView;

@interface AddressAttachmentCell : NSTextAttachmentCell
{
    AddressAttachment *attachment;
    struct CGRect drawingRect;
    struct CGRect hotSpot;
    struct CGRect onlineHotSpot;
    NSMenu *menu;
    unsigned int characterIndex;
    struct CGSize cellSize;
    BOOL isSpotlighted;
    BOOL shouldTestForSpotlighting;
    BOOL shouldShowComma;
    NSMutableDictionary *textAttributesRegular;
    NSMutableDictionary *textAttributesWhiteText;
    NSMutableDictionary *textAttributesTruncatedRegular;
    NSMutableDictionary *textAttributesTruncatedWhiteText;
    NSView *containingView;
    unsigned int isSelected:1;
    unsigned int leftSideHasSelection:1;
    unsigned int rightSideHasSelectedText:1;
    unsigned int rightSideHasSelectedAtom:1;
    unsigned int overrideRightSideSelection:1;
    unsigned int overrideLeftSideSelection:1;
    unsigned int hideLeftSideMargin:1;
    unsigned int subtractLeftSideMarginFromRightSide:1;
    unsigned int menuIsVisible:1;
}

+ (void)initialize;
+ (void)_initOnlineIndicator;
+ (long)sizeForCellOfType:(int)arg1 withAddress:(id)arg2;
+ (float)heightForAtomType:(int)arg1;
+ (BOOL)isOnLineAddress:(id)arg1;
+ (void)_changePresenceImage;
- (id)initImageCell:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)addressAttachment;
- (void)setAttachment:(id)arg1;
- (void)dealloc;
- (unsigned long)characterIndex;
- (struct CGRect)drawingRect;
- (struct CGRect)visibleRect;
- (struct CGRect)atomBoundsRectForCellFrame:(struct CGRect)arg1;
- (struct CGRect)atomBoundsRect;
- (id)dragImage;
- (id)textAttributesWhiteText;
- (id)textAttributesTruncatedWhiteText;
- (id)textAttributesRegular;
- (id)textAttributesTruncatedRegular;
- (id)view:(id)arg1 stringForToolTip:(long)arg2 point:(struct CGPoint)arg3 userData:(void *)arg4;
- (void)resetCursorAndToolTipRect:(struct CGRect)arg1 inView:(id)arg2;
- (id)menu;
- (BOOL)validateMenuItem:(id)arg1;
- (BOOL)isOnLine;
- (void)openChat:(id)arg1;
- (void)openNewMessage:(id)arg1;
- (void)addToAddressBook:(id)arg1;
- (void)removeRecordFromAddressBook:(id)arg1 forRecent:(id)arg2;
- (void)openInAddressBook:(id)arg1;
- (void)createSmartMailbox:(id)arg1;
- (void)removeFromAddressHistory:(id)arg1;
- (void)changeAddress:(id)arg1;
- (void)copyAddressToClipboard:(id)arg1;
- (void)searchInSpotlight:(id)arg1;
- (BOOL)isSelected;
- (void)setIsSelected:(BOOL)arg1;
- (BOOL)rightSideHasSelectedText;
- (void)setRightSideHasSelectedText:(BOOL)arg1;
- (void)setRightSideHasSelectedAtom:(BOOL)arg1;
- (BOOL)leftSideHasSelection;
- (void)setLeftSideHasSelection:(BOOL)arg1;
- (void)setOverrideRightSideSelection:(BOOL)arg1;
- (void)setOverrideLeftSideSelection:(BOOL)arg1;
- (void)testSpotlighting;
- (void)setShouldShowComma:(BOOL)arg1;
- (BOOL)shouldDrawCommaRightNow;
- (void)selectedAddressChanged;
- (void)_presenceImageChanged:(id)arg1;
- (void)fontChanged;
- (void)sizeChanged;
- (void)addressBookRecordChanged;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2 characterIndex:(unsigned long)arg3;
- (void)drawWithFrame:(struct CGRect)arg1 inView:(id)arg2 characterIndex:(unsigned long)arg3 layoutManager:(id)arg4;
- (void)_drawAtomPartsWithRect:(struct CGRect)arg1 cellFrame:(struct CGRect)arg2;
- (void)_drawAtomWithRect:(struct CGRect)arg1 cellFrame:(struct CGRect)arg2 inView:(id)arg3;
- (struct CGPoint)textDrawPointInRect:(struct CGRect)arg1 ofViewOrImage:(id)arg2;
- (struct CGSize)cellSize;
- (struct CGSize)sizeOfString:(id)arg1;
- (struct CGRect)cellFrameForTextContainer:(id)arg1 proposedLineFragment:(struct CGRect)arg2 glyphPosition:(struct CGPoint)arg3 characterIndex:(unsigned long)arg4;
- (struct CGPoint)cellBaselineOffset;
- (BOOL)trackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 atCharacterIndex:(unsigned long)arg4 untilMouseUp:(BOOL)arg5;
- (BOOL)wantsToTrackMouse;
- (BOOL)wantsToTrackMouseForEvent:(id)arg1;
- (BOOL)wantsToTrackMouseForEvent:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 atCharacterIndex:(unsigned long)arg4;
- (BOOL)shouldBeSpotlightedInView:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (void)delayedMouseEntered:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)otherAtomBecameSpotlighted:(id)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityAttributeValue:(id)arg1;
- (BOOL)accessibilityIsAttributeSettable:(id)arg1;
- (id)accessibilityActionNames;
- (id)accessibilityActionDescription:(id)arg1;
- (void)accessibilityPerformAction:(id)arg1;
- (void)showMenu;

@end

