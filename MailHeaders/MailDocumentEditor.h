/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "DocumentEditor.h"

#import "NSAnimationDelegate-Protocol.h"

@class ColorBackgroundView, DeliveryFailure, NSButton, NSMutableArray, NSPopUpButton, NSProgressIndicator, NSScroller, NSTextField, NSView, NSViewAnimation, StationerySelector;

@interface MailDocumentEditor : DocumentEditor <NSAnimationDelegate>
{
    DeliveryFailure *deliveryFailure;
    ColorBackgroundView *stationeryPane;
    StationerySelector *stationerySelector;
    NSTextField *stationeryNameTextField;
    NSButton *stationeryNameSaveButton;
    ColorBackgroundView *borderView;
    NSScroller *fakeScroller;
    NSViewAnimation *stationeryPaneAnimator;
    NSView *imageStatusView;
    NSTextField *imageFileSizeLabel;
    NSTextField *imageFileSizeTextField;
    NSPopUpButton *imageSizePopup;
    NSProgressIndicator *imageResizingProgressWheel;
    NSTextField *imageResizingProgressField;
    NSMutableArray *_imageResizers;
    unsigned int _textLengthForLastEstimatedMessageSize;
    unsigned int _encryptionOverhead;
    BOOL sendWhenFinishLoading;
    BOOL hasIncludedAttachmentsFromOriginal;
    NSMutableArray *_unapprovedRecipients;
    NSMutableArray *userActionQueue;
}

+ (BOOL)documentType;
+ (id)documentEditors;
+ (id)createEditorWithType:(int)arg1 settings:(id)arg2;
+ (void)restoreDraftMessage:(id)arg1 withSavedState:(id)arg2;
+ (void)emailAddressesApproved:(id)arg1;
+ (void)emailsRejected:(id)arg1;
+ (void)_emailAddresses:(id)arg1 approvedOrRejected:(BOOL)arg2;
+ (void)_setMessageStatus:(id)arg1 onMessageID:(id)arg2;
+ (void)handleFailedDeliveryOfMessage:(id)arg1 store:(id)arg2 error:(id)arg3;
+ (id)keyPathsForValuesAffectingDeliveryAccount;
- (id)init;
- (id)initWithBackEnd:(id)arg1;
- (id)initWithType:(int)arg1 settings:(id)arg2;
- (id)initWithType:(int)arg1 settings:(id)arg2 backEnd:(id)arg3;
- (BOOL)load;
- (void)finishLoadingEditor;
- (void)dealloc;
- (void)show;
- (int)messageType;
- (void)changeReplyMode:(id)arg1;
- (void)replyMessage:(id)arg1;
- (void)replyAllMessage:(id)arg1;
- (void)loadInitialDocument;
- (void)backEndDidLoadInitialContent:(id)arg1;
- (void)attachmentFinishedDownloading:(id)arg1;
- (id)document;
- (id)webView;
- (id)parsedMessageFromSettings:(id)arg1;
- (void)continueLoadingInitialContent;
- (double)animationDuration;
- (void)showOrHideStationery:(id)arg1;
- (void)animationDidEnd:(id)arg1;
- (BOOL)stationeryPaneIsVisible;
- (id)currentStationery;
- (void)loadStationery:(id)arg1;
- (void)saveAsStationery:(id)arg1;
- (void)continueSaveAsStationery:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)controlTextDidChange:(id)arg1;
- (void)cancelSaveAsStationery:(id)arg1;
- (void)saveSaveAsStationery:(id)arg1;
- (void)saveAsStationeryErrorSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(id)arg3;
- (BOOL)canSave;
- (void)saveMessageToDrafts:(id)arg1;
- (void)backEnd:(id)arg1 willCreateMessageWithHeaders:(id)arg2;
- (BOOL)backEnd:(id)arg1 shouldSaveMessage:(id)arg2;
- (void)backEndDidChange:(id)arg1;
- (void)backEndSenderDidChange:(id)arg1;
- (void)removeAttachments:(id)arg1;
- (void)insertOriginalAttachments:(id)arg1;
- (BOOL)_restoreOriginalAttachments;
- (void)alwaysSendWindowsFriendlyAttachments:(id)arg1;
- (void)sendWindowsFriendlyAttachments:(id)arg1;
- (void)_setSendWindowsFriendlyAttachments:(BOOL)arg1;
- (void)alwaysAttachFilesAtEnd:(id)arg1;
- (void)attachFilesAtEnd:(id)arg1;
- (void)insertFile:(id)arg1;
- (void)openPanelSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (BOOL)_sendButtonShouldBeEnabled;
- (void)_setUnapprovedRecipients:(id)arg1;
- (void)askApprovalSheetClosed:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)send:(id)arg1;
- (void)sendMessageAfterChecking:(id)arg1;
- (void)backEndDidCancelMessageDeliveryForAttachmentError:(id)arg1;
- (void)attachmentErrorSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)cancelSendingStationery:(id)arg1;
- (void)continueSendingStationery:(id)arg1;
- (void)emptyMessageSheetClosed:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)malformedAddressSheetClosed:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)noRecipientsSheetClosed:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)backEndDidAppendMessageToOutbox:(id)arg1 result:(int)arg2;
- (void)failedToAppendToOutboxSheetClosed:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (BOOL)backEnd:(id)arg1 shouldDeliverMessage:(id)arg2;
- (void)_setMessageStatusOnOriginalMessage;
- (void)backEnd:(id)arg1 didCancelMessageDeliveryForError:(id)arg2;
- (void)reportDeliveryFailure:(id)arg1;
- (void)forceClose;
- (void)backEnd:(id)arg1 didCancelMessageDeliveryForMissingCertificatesForRecipients:(id)arg2;
- (id)missingCertificatesMessageForRecipients:(id)arg1 uponDelivery:(BOOL)arg2;
- (void)backEnd:(id)arg1 didCancelMessageDeliveryForEncryptionError:(id)arg2;
- (void)shouldDeliverMessageAlertWithoutEncryptionSheetDidDismiss:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (id)deliveryAccount;
- (void)setDeliveryAccount:(id)arg1;
- (void)changeSignature:(id)arg1;
- (void)imageSizePopupChanged:(id)arg1;
- (void)messageSizeDidChange:(id)arg1;
- (void)encryptionStatusDidChange;
- (void)updateAttachmentStatus;
- (unsigned char)_isAttachmentScalable:(id)arg1;
- (unsigned char)_attachmentsContainScalableImage:(id)arg1 scalables:(id)arg2;
- (void)_updateImageSizePopup;
- (BOOL)_imageStatusHidden;
- (void)_showImageStatusView;
- (void)_hideImageStatusView;
- (struct CGSize)_imageSizeForTag:(long)arg1;
- (struct CGSize)_selectedImageSize;
- (id)_maxImageSizeAsString;
- (void)_processNextImageResizer;
- (void)_ImageResizeDidFinish:(id)arg1;
- (BOOL)_isResizingImages;
- (id)_resizerForAttachment:(id)arg1;
- (BOOL)_resizeAttachment:(id)arg1;
- (BOOL)_resizeImageAttachments:(id)arg1;
- (unsigned long)textLengthEstimate;
- (unsigned long)_signatureOverhead;
- (unsigned long)_encryptionOverhead;
- (unsigned long long)_estimateMessageSize;
- (void)_saveImageSizeToDefaults;
- (void)_setImageSizePopupToSize:(id)arg1;
- (id)attachmentStatusNeighbourView;
- (void)_mailAttachmentsDeleted;
- (void)mailAttachmentsDeleted:(id)arg1;
- (id)mailAttachmentsAdded:(id)arg1;
- (BOOL)windowShouldClose:(id)arg1;
- (void)appendMessages:(id)arg1;
- (void)appendMessageArray:(id)arg1;
- (void)_appendMessages:(id)arg1 withParsedMessages:(id)arg2;
- (void)_generateParsedMessagesToAppendForMessages:(id)arg1;
- (void)makeRichText:(id)arg1;
- (void)makePlainText:(id)arg1;
- (void)makeFontBigger:(id)arg1;
- (void)makeFontSmaller:(id)arg1;
- (void)addCcHeader:(id)arg1;
- (void)addBccHeader:(id)arg1;
- (void)addReplyToHeader:(id)arg1;
- (void)setMessagePriority:(id)arg1;

@end

