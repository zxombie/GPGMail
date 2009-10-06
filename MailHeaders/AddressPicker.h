/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSWindowController.h"

@class ABPeoplePickerView;

@interface AddressPicker : NSWindowController
{
    ABPeoplePickerView *pickerView;
    BOOL selectionIsValid;
}

+ (void)showOrHideAddressPicker;
+ (BOOL)isAddressPickerVisible;
+ (void)saveDefaults;
+ (void)restoreFromDefaults;
- (void)showOrHideWindow;
- (BOOL)isWindowVisible;
- (void)saveDefaults;
- (void)windowIsClosing;
- (void)dealloc;
- (void)awakeFromNib;
- (id)windowNibName;
- (void)searchIndex:(id)arg1;
- (void)putSelectionInTo:(id)arg1;
- (void)putSelectionInCC:(id)arg1;
- (void)putSelectionInBCC:(id)arg1;
- (void)putSelectionInBestHeader:(id)arg1;
- (void)putSelectionInHeader:(id)arg1;
- (id)formattedAddressForRecord:(id)arg1;
- (void)_ensureSelectionIsValid:(id)arg1;
- (BOOL)selectionIsValid;
- (void)setSelectionIsValid:(BOOL)arg1;

@end

