#ifdef LEOPARD

#import <Cocoa/Cocoa.h>

@class OptionalView;

@interface ComposeHeaderView : NSView <NSAnimationDelegate>
{
    id _delegate;
    NSPopUpButton *_disclosureButton;
    NSMenu *_actionMenu;
    OptionalView *_toOptionalView;
    OptionalView *_ccOptionalView;
    OptionalView *_subjectOptionalView;
    OptionalView *_bccOptionalView;
    OptionalView *_replyToOptionalView;
    OptionalView *_accountOptionalView;
    OptionalView *_signatureOptionalView;
    OptionalView *_priorityOptionalView;
    OptionalView *_securityOptionalView;
    OptionalView *_deliveryOptionalView;
    NSView *_messageContentView;
    NSPopUpButton *_signaturePopUp;
    NSPopUpButton *_accountPopUp;
    NSPopUpButton *_deliveryPopUp;
    NSButton *_cancelButton;
    NSButton *_okButton;
    NSImage *borderImage;
    unsigned int _showCcView:1;
    unsigned int _showBccView:1;
    unsigned int _showReplyToView:1;
    unsigned int _showAccountView:1;
    unsigned int _showSignatureView:1;
    unsigned int _showPriorityView:1;
    unsigned int _showSecurityView:1;
    unsigned int _showDeliveryView:1;
    BOOL _tempShowDeliveryView;
    unsigned int _accountFieldEnabled:1;
    unsigned int _deliveryFieldEnabled:1;
    unsigned int _signatureFieldEnabled:1;
    unsigned int _securityFieldEnabled:1;
    unsigned int _resizingViews:1;
    unsigned int _customizing:1;
    unsigned int _changesCancelled:1;
    NSViewAnimation *_animation;
    float _nextShownFrameOrigin;
    float _nextHiddenFrameOrigin;
    float _heightDelta;
    id _lastFirstResponder;
    float _signaturePopUpMaxWidth;
    float _accountPopUpMaxWidth;
    OptionalView *_togglingOptionalView;
    BOOL _customizationShouldStick;
}

- (void)awakeFromNib;
- (void)dealloc;
- (id)delegate;
- (void)setDelegate:(id)arg1;
- (id)messageContentView;
- (void)setMessageContentView:(id)arg1;
- (BOOL)isFlipped;
- (BOOL)isOpaque;
- (void)viewWillMoveToWindow:(id)arg1;
- (BOOL)isCustomizing;
- (void)_restoreFirstResponder;
- (void)_noteCurrentFirstResponder;
- (void)_popDisclosureButtonToFront;
- (void)_readVisibleStateFromOptionCheckboxes;
- (void)beginListeningForChildFrameChangeNotifications;
- (void)_setupMenuItemWithAction:(SEL)arg1 withState:(BOOL)arg2;
- (void)_setupActionMenuItemState;
- (float)_positionView:(id)arg1 yOffset:(float)arg2;
- (BOOL)_shouldShowSecurityViewWhenNotCustomizing;
- (BOOL)_shouldShowSecurityViewWhenCustomizing;
- (BOOL)_shouldShowSecurityView;
- (BOOL)_shouldShowAccountViewWhenNotCustomizing;
- (BOOL)_shouldShowAccountViewWhenCustomizing;
- (BOOL)_shouldShowAccountView;
- (BOOL)_shouldShowSignatureViewWhenNotCustomizing;
- (BOOL)_shouldShowSignatureViewWhenCustomizing;
- (BOOL)_shouldShowSignatureView;
- (BOOL)_shouldShowDeliveryViewWhenNotCustomizing;
- (void)_deliveryViewAppearanceConditionsDidChange:(id)arg1;
- (void)_recomputeShowDeliveryView;
- (BOOL)_shouldShowDeliveryViewWhenCustomizing;
- (BOOL)_shouldShowDeliveryView;
- (BOOL)_shouldShowPriorityViewWhenNotCustomizing;
- (BOOL)_shouldShowPriorityViewWhenCustomizing;
- (BOOL)_shouldShowPriorityView;
- (struct CGRect)_calculatePriorityFrame:(struct CGRect)arg1;
- (void)_calculateAccountFrame:(struct CGRect *)arg1 deliveryFrame:(struct CGRect *)arg2 signatureFrame:(struct CGRect *)arg3;
- (void)subviewFrameDidChange:(id)arg1;
- (BOOL)isDisplayingBottomControls;
- (BOOL)isDisplayingFatBottomControls;
- (void)fixupTabRing;
- (void)tile;
- (void)_addView:(id)arg1 toList:(id)arg2 isVisible:(BOOL)arg3 adjustYOrigin:(BOOL)arg4;
- (void)_recordUserCustomization;
- (void)_customizeHeaders:(BOOL)arg1 duration:(double)arg2;
- (void)resizeWithOldSuperviewSize:(struct CGSize)arg1;
- (void)_enableActionMenu:(BOOL)arg1;
- (void)sanityCheckHiddenessOfViewsInAnimationList:(id)arg1;
- (void)animationDidEnd:(id)arg1;
- (void)drawRect:(struct CGRect)arg1;
- (void)_finishCustomizingSavingChanges:(BOOL)arg1;
- (void)done:(id)arg1;
- (void)_toggleCcOrBccOrReplyToField:(id)arg1;
- (void)toggleCcFieldVisibility:(id)arg1;
- (void)toggleBccFieldVisibility:(id)arg1;
- (void)toggleReplyToFieldVisibility:(id)arg1;
- (void)temporarilyToggleCcFieldVisibility;
- (void)temporarilyToggleBccFieldVisibility;
- (void)temporarilyToggleReplyToFieldVisibility;
- (void)_toggleAccountOrDeliveryOrSignatureOrPriorityOrSecurityField:(id)arg1;
- (void)togglePriorityFieldVisibility:(id)arg1;
- (void)temporarilyTogglePriorityFieldVisibility;
- (void)configureHeaders:(id)arg1;
- (void)configureAccountPopUpSize;
- (void)configureSignaturePopUpSize;
- (void)setCcFieldVisible:(BOOL)arg1 andSetDefault:(BOOL)arg2;
- (void)setCcFieldVisible:(BOOL)arg1;
- (void)setBccFieldVisible:(BOOL)arg1 andSetDefault:(BOOL)arg2;
- (void)setBccFieldVisible:(BOOL)arg1;
- (void)setReplyToFieldVisible:(BOOL)arg1 andSetDefault:(BOOL)arg2;
- (void)setReplyToFieldVisible:(BOOL)arg1;
- (void)setAccountFieldVisible:(BOOL)arg1;
- (void)setSignatureFieldVisible:(BOOL)arg1;
- (void)setDeliveryFieldVisible:(BOOL)arg1;
- (void)setPriorityFieldVisible:(BOOL)arg1 andSetDefault:(BOOL)arg2;
- (void)setPriorityFieldVisible:(BOOL)arg1;
- (void)setSecurityFieldVisible:(BOOL)arg1;
- (BOOL)securityFieldVisible;
- (BOOL)showCcHeader;
- (BOOL)showBccHeader;
- (BOOL)showReplyToHeader;
- (void)setAccountFieldEnabled:(BOOL)arg1;
- (void)setSignatureFieldEnabled:(BOOL)arg1;
- (void)setDeliveryFieldEnabled:(BOOL)arg1;
- (void)setSecurityFieldEnabled:(BOOL)arg1;

@end
#else
#error Missing definition of ComposeHeaderView
#endif
