#import <Cocoa/Cocoa.h>
#import <Libmacgpg/Libmacgpg.h>

@interface GPGSignatureView : NSObject <NSWindowDelegate, NSTableViewDelegate, NSTableViewDataSource, NSSplitViewDelegate> {
	IBOutlet NSWindow *window;
	IBOutlet NSTableView *detailTable;
	NSSet *keyList;
	NSArray *signatures;
	BOOL running;
	NSIndexSet *signatureIndexes;
	GPGSignature *signature;
	
	IBOutlet NSView *scrollContentView;
	IBOutlet NSView *infoView;
	IBOutlet NSView *detailView;
	IBOutlet NSScrollView *scrollView;
	IBOutlet NSSplitView *splitView;
}

//Private
@property (strong, nonatomic) NSIndexSet *signatureIndexes;
@property (strong, readonly, nonatomic) GPGKey *gpgKey;

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
