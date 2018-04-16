#import <Cocoa/Cocoa.h>
#import <Libmacgpg/Libmacgpg.h>

@interface GPGSignatureView : NSWindowController <NSWindowDelegate, NSTableViewDelegate, NSTableViewDataSource, NSSplitViewDelegate> {
	IBOutlet NSTableView *detailTable;
	NSSet *keyList;
	NSArray *signatures;
	BOOL running;
	NSIndexSet *signatureIndexes;
	GPGSignature *signature;
	CGFloat fullHeight;
	CGFloat listHeight;
	CGFloat subkeyHeight;

	
	
	IBOutlet NSSplitView *splitView;
	IBOutlet NSView *parentView;
	IBOutlet NSView *subkeyView;
}

//Private
@property (strong, nonatomic) NSIndexSet *signatureIndexes;
@property (strong, readonly, nonatomic) GPGKey *gpgKey;
@property (strong, readonly, nonatomic) GPGKey *subkey;

- (IBAction)close:(id)sender;




//Public
@property (strong, nonatomic) NSSet *keyList;
@property (strong, nonatomic) NSArray *signatures;

+ (id)signatureView;

- (NSInteger)runModal;
- (void)beginSheetModalForWindow:(NSWindow *)modalWindow completionHandler:(void (^)(NSInteger result))handler;
- (NSString *)keyID;
- (void)sheetDidEnd:(NSWindow *)sheet returnCode:(NSInteger)returnCode contextInfo:(void *)contextInfo;
@end


@interface GPGSignatureCertImageTransformer : NSValueTransformer {} @end
@interface GPGFlippedView : NSView {} @end
@interface GPGFlippedClipView : NSClipView {} @end
@interface TopScrollView : NSScrollView {} @end
