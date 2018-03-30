#import "GPGSignatureView.h"
#import "GPGMailBundle.h"

#define localized(key) [[GPGMailBundle bundle] localizedStringForKey:(key) value:(key) table:@"SignatureView"]

@interface GPGSignatureView ()
@property (strong, readwrite, nonatomic) GPGKey *gpgKey;
@property (strong, readwrite, nonatomic) GPGKey *subkey;
@end



@implementation GPGSignatureView
@synthesize keyList, signatures, gpgKey;
GPGSignatureView *_sharedInstance;

- (NSString *)unlocalizedValidityKey {
	NSString *text = nil;

	switch (signature.status) {
		case GPGErrorNoError:
			if (signature.trust > 1) {
				text = @"VALIDITY_OK";
			} else {
				text = @"VALIDITY_NO_TRUST";
			}
			break;
		case GPGErrorBadSignature:
			text = @"VALIDITY_BAD_SIGNATURE";
			break;
		case GPGErrorSignatureExpired:
			text = @"VALIDITY_SIGNATURE_EXPIRED";
			break;
		case GPGErrorKeyExpired:
			text = @"VALIDITY_KEY_EXPIRED";
			break;
		case GPGErrorCertificateRevoked:
			text = @"VALIDITY_KEY_REVOKED";
			break;
		case GPGErrorUnknownAlgorithm:
			text = @"VALIDITY_UNKNOWN_ALGORITHM";
			break;
		case GPGErrorNoPublicKey:
			text = @"VALIDITY_NO_PUBLIC_KEY";
			break;
		default:
			text = @"VALIDITY_UNKNOWN_ERROR";
			break;
	}
	return text;
}



- (NSImage *)validityImage {
	if (![signature isKindOfClass:[GPGSignature class]]) {
		return nil;
	}
	if (signature.status != 0 || signature.trust <= 1) {
		return [NSImage imageNamed:@"InvalidBadge"];
	} else {
		return [NSImage imageNamed:@"ValidBadge"];
	}
}

- (NSString *)validityDescription {
	if (!signature) return nil;

	NSString *text = [self unlocalizedValidityKey];
	if (text) {
		return localized(text);
	} else {
		return @"";
	}
}

- (NSString *)validityToolTip {
	if (!signature) return nil;

	NSString *text = [self unlocalizedValidityKey];
	text = [text stringByAppendingString:@"_TOOLTIP"];
	if (text) {
		return localized(text);
	} else {
		return @"";
	}
}

- (NSString *)keyID {
	NSString *keyID = self.gpgKey.keyID;
	if (!keyID) {
		keyID = signature.fingerprint;
	}
	return [keyID shortKeyID];
}

- (NSImage *)signatureImage {
	if (![signature isKindOfClass:[GPGSignature class]]) {
		return nil;
	}
	if (signature.status != 0 || signature.trust <= 1) {
		return [NSImage imageNamed:@"CertLargeNotTrusted"];
	} else {
		return [NSImage imageNamed:@"CertLargeStd"];
	}
}


- (void)setSignature:(GPGSignature *)value {
	if (value == signature) {
		return;
	}
	signature = value;
	
	GPGKey *key = nil;
	GPGKey *subkey = nil;

	key = signature.primaryKey;
	subkey = signature.key;
	
	if ([key isEqual:subkey]) {
		subkey = nil;
	}
	
	
	if (subkey && !subkeyView.superview) {
		[parentView addSubview:subkeyView];
		CGFloat height = 0;
		for (NSView *view in parentView.subviews) {
			height += view.frame.size.height;
		}
		[parentView.superview setFrameSize:NSMakeSize(parentView.frame.size.width, height)];
		[subkeyView setFrameOrigin:NSMakePoint(0, 0)];
	} else if (!subkey && subkeyView.superview) {
		[subkeyView removeFromSuperview];
		CGFloat height = 0;
		for (NSView *view in parentView.subviews) {
			height += view.frame.size.height;
		}
		[parentView.superview setFrameSize:NSMakeSize(parentView.frame.size.width, height)];
	}
	
	
	self.gpgKey = key;
	self.subkey = subkey;
}

- (id)valueForKeyPath:(NSString *)keyPath {
    if ([keyPath hasPrefix:@"signature."]) {
		if (signature == nil) {
			return nil;
		}
		keyPath = [keyPath substringFromIndex:10];
        if ([signature respondsToSelector:NSSelectorFromString(keyPath)]) {
			return [signature valueForKey:keyPath];
		}
	}
	return [super valueForKeyPath:keyPath];
}


- (void)prepareForShow {
	running = 1;
	[self willChangeValueForKey:@"signatureDescriptions"];
	[self didChangeValueForKey:@"signatureDescriptions"];
	
	if (self.signatures.count == 1) {
		[splitView setPosition:-splitView.dividerThickness ofDividerAtIndex:0];
	} else {
		if (splitView.subviews[0].frame.size.height < 60) {
			[splitView setPosition:60 ofDividerAtIndex:0];
		}
	}
	
}

- (NSInteger)runModal {
	if (!running) {
		[self prepareForShow];
		[NSApp runModalForWindow:window];
		return NSOKButton;
	} else {
		return NSCancelButton;
	}
}
- (void)beginSheetModalForWindow:(NSWindow *)modalWindow completionHandler:(void (^)(NSInteger result))handler {
	if (!running) {
		[self prepareForShow];
		[NSApp beginSheet:window modalForWindow:modalWindow modalDelegate:self didEndSelector:@selector(sheetDidEnd:returnCode:contextInfo:) contextInfo:(__bridge void *)(handler)];
	} else {
		handler(NSCancelButton);
	}
}

- (void)sheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo {
	((__bridge void (^)(NSInteger result))contextInfo)(NSOKButton);
}



- (IBAction)close:(id)sender {
	[window orderOut:self];
	[NSApp stopModal];
	[NSApp endSheet:window];
	running = 0;
}

- (void)windowWillClose:(NSNotification *)notification {
	[NSApp stopModal];
	[NSApp endSheet:window];
	running = 0;
}

- (NSIndexSet *)signatureIndexes {
	return signatureIndexes;
}
- (void)setSignatureIndexes:(NSIndexSet *)value {
	if (value != signatureIndexes) {
		signatureIndexes = value;
		NSUInteger index;
		if ([value count] > 0 && (index = [value firstIndex]) < [signatures count]) {
			self.signature = signatures[index];
		} else {
			self.signature = nil;
		}

	}
}




- (BOOL)splitView:(__unused NSSplitView *)aSplitView shouldHideDividerAtIndex:(__unused NSInteger)dividerIndex {
	return self.signatures.count == 1;
}
- (CGFloat)splitView:(__unused NSSplitView *)aSplitView constrainMinCoordinate:( __unused CGFloat)proposedMinimumPosition ofSubviewAt:(__unused NSInteger)dividerIndex {
	if (self.signatures.count == 1) {
		return -splitView.dividerThickness;
	} else {
		return 60;
	}
}
- (CGFloat)splitView:(__unused NSSplitView *)aSplitView constrainMaxCoordinate:(CGFloat)proposedMaximumPosition ofSubviewAt:(__unused NSInteger)dividerIndex {
	return proposedMaximumPosition - 90;
}
- (void)splitView:(NSSplitView *)aSplitView resizeSubviewsWithOldSize:(__unused NSSize)oldSize {
//	if (self.signatures.count == 1) {
//		return;
//	}
	
	
	NSArray *subviews = [aSplitView subviews];
	NSView *view1 = subviews[0];
	NSView *view2 = subviews[1];
	NSSize splitViewSize = [aSplitView frame].size;
	NSSize size1 = [view1 frame].size;
	NSRect frame2 = [view2 frame];
	CGFloat dividerThickness = self.signatures.count == 1 ? 0 : aSplitView.dividerThickness;

	size1.width = splitViewSize.width;
	frame2.size.width = splitViewSize.width;

	frame2.size.height = splitViewSize.height - dividerThickness - size1.height;
	if (frame2.size.height < 60) {
		frame2.size.height = 60;
		size1.height = splitViewSize.height - 60 - dividerThickness;
	}
	frame2.origin.y = splitViewSize.height - frame2.size.height;

	
	if (self.signatures.count != 1) {
		[view1 setFrameSize:size1];
	}
	
	[view2 setFrame:frame2];
}


+ (id)signatureView {
    static dispatch_once_t pred;
    static GPGSignatureView *_sharedInstance;
    dispatch_once(&pred, ^{
        _sharedInstance = [[GPGSignatureView alloc] init];
        [NSBundle loadNibNamed:@"GPGSignatureView" owner:_sharedInstance];
    });
    return _sharedInstance;
}

- (id)init {
	return [super init];
}

@end



@implementation GPGSignatureCertImageTransformer
+ (Class)transformedValueClass { return [NSImage class]; }
+ (BOOL)allowsReverseTransformation { return NO; }
- (id)transformedValue:(GPGSignature *)signature {
	if (![signature isKindOfClass:[GPGSignature class]]) {
		return nil;
	}
	if (signature.status != 0 || signature.trust <= 1) {
		return [NSImage imageNamed:@"CertSmallStd_Invalid"];
	} else {
		return [NSImage imageNamed:@"CertSmallStd"];
	}
}
@end



@implementation GPGFlippedView
- (BOOL)isFlipped {
	return YES;
}
@end

@implementation TopScrollView
- (void)setFrameSize:(NSSize)newSize {
	NSClipView *clipView = [self contentView];
	NSRect bounds = [clipView bounds];
	[super setFrameSize:newSize];
	bounds.origin.y = bounds.origin.y - (bounds.size.height - [clipView bounds].size.height);
	[clipView setBoundsOrigin:bounds.origin];
}
@end


