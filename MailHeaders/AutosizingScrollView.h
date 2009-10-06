/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSScrollView.h"

@interface AutosizingScrollView : NSScrollView
{
    float _maxHeight;
    unsigned int _resizingContent:1;
    unsigned int _UNUSED:31;
}

+ (struct CGSize)frameSizeForContentSize:(struct CGSize)arg1 hasHorizontalScroller:(BOOL)arg2 hasVerticalScroller:(BOOL)arg3 borderType:(unsigned long)arg4;
+ (struct CGSize)contentSizeForFrameSize:(struct CGSize)arg1 hasHorizontalScroller:(BOOL)arg2 hasVerticalScroller:(BOOL)arg3 borderType:(unsigned long)arg4;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (void)tile;
- (void)docViewFrameChanged;
- (void)setMaxHeight:(float)arg1;
- (float)maxHeight;
- (void)setTag:(long)arg1;
- (long)tag;

@end

