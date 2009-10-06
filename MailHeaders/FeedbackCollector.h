/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSObject.h"

@class NSButton, NSMutableString, NSProgressIndicator, NSTextField, NSView, NSWindow, WebView;

@interface FeedbackCollector : NSObject
{
    WebView *metricsWebView;
    NSButton *includeMetricsCheckbox;
    NSWindow *window;
    NSProgressIndicator *spinner;
    NSTextField *collectingTextField;
    NSView *statusContainerView;
    NSButton *continueButton;
    NSMutableString *feedbackHTMLString;
    BOOL sendMetricsImmediately;
    BOOL currentlyLoading;
}

+ (void)initialize;
+ (id)allocWithZone:(struct _NSZone *)arg1;
+ (id)sharedInstance;
- (id)init;
- (void)dealloc;
- (id)retain;
- (unsigned long)retainCount;
- (void)release;
- (id)autorelease;
- (void)run;
- (void)collectMetrics;
- (void)webView:(id)arg1 didFinishLoadForFrame:(id)arg2;
- (void)sendMetricsIfRequested;
- (void)cleanUpWindow;
- (void)loadStringIntoWebView;
- (BOOL)windowShouldClose:(id)arg1;
- (void)continue:(id)arg1;
- (void)cancel:(id)arg1;

@end

