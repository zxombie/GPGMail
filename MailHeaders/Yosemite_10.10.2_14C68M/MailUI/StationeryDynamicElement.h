/*
 *     Generated by class-dump 3.4 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2012 by Steve Nygard.
 */

#import "NSObject.h"

@class NSString;

@interface StationeryDynamicElement : NSObject
{
    NSString *_dateFormat;
    unsigned long long _type;
}

+ (id)dynamicElementFromDOMElement:(id)arg1;
@property(readonly, nonatomic) unsigned long long type; // @synthesize type=_type;
- (void).cxx_destruct;
- (id)description;
- (id)fragmentToReplaceHTMLObjectBackEnd:(id)arg1;
- (void)_setDateFormat:(id)arg1;
- (id)initWithType:(unsigned long long)arg1;

@end

