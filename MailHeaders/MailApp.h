/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "NSApplication.h"

#import "MVTerminationHandler-Protocol.h"
#import "NSApplicationDelegate-Protocol.h"
#import "SyncableApp-Protocol.h"

@class ActivityViewer, ActivityViewerMailSound, DeliveryQueue, DockCountController, DynamicErrorWindowController, MailboxesController, NSMenu, NSMenuItem, NSMutableArray, NSMutableSet, NSString, NSWindow;

@interface MailApp : NSApplication <NSApplicationDelegate, SyncableApp, MVTerminationHandler>
{
    id <MVSelectionOwner> selectionOwner;
    NSMenu *_mailboxesContextMenu;
    NSMenu *_addButtonMenu;
    NSMenu *_messageViewerContextMenu;
    NSMenu *_composeAttachmentContextMenu;
    NSMenu *_viewAttachmentContextMenu;
    NSMenuItem *textEncodingMenuItem;
    MailboxesController *mailboxesController;
    NSString *_noMailSoundPath;
    NSString *_fetchErrorSoundPath;
    DockCountController *_dockCountController;
    NSMutableArray *_stationeryBundlesToInstall;
    NSWindow *_errorDiagnosisWindow;
    DynamicErrorWindowController *_errorDiagnosisWindowController;
    int *_errorDiagnosisResult;
    DeliveryQueue *_deliveryQueue;
    ActivityViewer *_activityViewer;
    ActivityViewerMailSound *_activityViewerMailSound;
    id _terminationHandlersLock;
    NSMutableArray *_terminationHandlers;
    NSMutableArray *_currentTerminationHandlers;
    unsigned int _terminateReply;
    BOOL _isTerminating;
    unsigned int _autoLaunchHidden:1;
    unsigned int _shouldPlayFetchErrorSound:1;
    unsigned int _appHasFinishedLaunching:1;
    unsigned int _synchronizingAllAccounts:1;
    unsigned int _groupingByThreadDefaultsToOn:1;
    unsigned int _updateEmailAliasesOnNextActivation:1;
    unsigned int _paused:1;
    unsigned int _isAppleInternal:1;
    unsigned int _isExceptionStackTracingDisabled:1;
    unsigned int _shouldCleanUpHTTPMailAccounts:1;
    NSMutableSet *_accountsCurrentlySynchronizing;
    unsigned int numberOfAccountsEmptyingTrash;
    int currentPasswordPanelCount;
    id <Syncer> _syncer;
    BOOL accountsAreNew;
    BOOL useAddressAtoms;
    BOOL runningEmptyTrashSheet;
    BOOL childWindowVisible;
    NSMutableArray *_appleEventDescriptorQueue;
}

+ (BOOL)checkMessageFrameworkCompatibility;
- (id)init;
- (BOOL)appHasFinishedLaunching;
- (BOOL)isChildWindowVisible;
- (void)setChildWindowVisible:(BOOL)arg1;
- (BOOL)isAppleInternal;
- (void)setIsAppleInternal:(BOOL)arg1;
- (BOOL)isExceptionStackTracingDisabled;
- (void)setIsExceptionStackTracingDisabled:(BOOL)arg1;
- (void)sendEvent:(id)arg1;
- (void)presencePreferenceChanged:(id)arg1;
- (void)_accountInfoDidChange:(id)arg1;
- (void)showViewerWindow:(id)arg1;
- (BOOL)_showViewerWindow:(id)arg1;
- (BOOL)applicationOpenUntitledFile:(id)arg1;
- (void)configurePerformanceLoggingDefaults;
- (void)_systemTimeChanged;
- (void)_midnightPassed;
- (void)_setupMidnightTimer;
- (void)_checkTimerAndFireDate:(id)arg1;
- (void)checkTimersAfterSleeping;
- (void)_updateEmailAliases;
- (void)_updateRSSUnreadCountsAndFetchNewFeeds;
- (void)performDelayedInitialization;
- (void)_tellSyncServicesToRegisterAndSync;
- (void)applicationDidFinishLaunching:(id)arg1;
- (void)_initializeAddressBookSources;
- (BOOL)_needToCreateLibrary;
- (void)reportException:(id)arg1;
- (void)reportException:(id)arg1 invocation:(id)arg2;
- (BOOL)accountsAreNew;
- (void)_restoreMessagesFromDefaults;
- (void)_setupInitialState;
- (void)_loadBundles;
- (void)_loadBundlesFromPath:(id)arg1 failedBundleInfos:(id)arg2;
- (id)_failureInfoForBundle:(id)arg1 path:(id)arg2;
- (id)_mailboxBeingViewed;
- (BOOL)_isMailboxBeingViewedSpecial;
- (id)_accountBeingViewed;
- (void)runPageLayout:(id)arg1;
- (BOOL)validateToolbarItem:(id)arg1;
- (BOOL)validateMenuItem:(id)arg1;
- (BOOL)moreThanOneAccountCanGoOffline;
- (void)disconnectAllAccounts:(id)arg1;
- (void)connectAllAccounts:(id)arg1;
- (void)connectThisAccount:(id)arg1;
- (void)disconnectThisAccount:(id)arg1;
- (void)disconnectAllAccountsFromContextMenu:(id)arg1;
- (void)connectAllAccountsFromContextMenu:(id)arg1;
- (void)connectThisAccountFromContextMenu:(id)arg1;
- (void)disconnectThisAccountFromContextMenu:(id)arg1;
- (void)toggleAccountOnlineStatus:(id)arg1;
- (void)addToAccountsCurrentlySynchronizing:(id)arg1;
- (void)removeFromAccountsCurrentlySynchronizing:(id)arg1;
- (BOOL)isAccountCurrentlySynchronizing:(id)arg1;
- (void)clearAccountsCurrentlySynchronizing;
- (void)performSynchronizationForAccounts:(id)arg1;
- (void)synchronizeAccount:(id)arg1;
- (void)_networkConfigurationChanged:(id)arg1;
- (void)handleNetworkConfigurationChange;
- (void)_emailAddressesApproved:(id)arg1;
- (void)_emailsRejected:(id)arg1;
- (void)showConnectionDoctor:(id)arg1;
- (void)showInfoPanel:(id)arg1;
- (void)showComposeWindow:(id)arg1;
- (void)showNoteEditor:(id)arg1;
- (void)orderFrontStylesPanel:(id)arg1;
- (void)addFontTrait:(id)arg1;
- (void)newViewerWindow:(id)arg1;
- (void)selectMailbox:(id)arg1;
- (void)showMediaBrowser:(id)arg1;
- (void)showAddressPanel:(id)arg1;
- (void)showAddressHistoryPanel:(id)arg1;
- (void)showSearchPanel:(id)arg1;
- (void)findNext:(id)arg1;
- (void)findPrevious:(id)arg1;
- (void)showActivityViewer:(id)arg1;
- (void)showPreferencesPanel:(id)arg1;
- (void)collectFeedback:(id)arg1;
- (void)addAccount:(id)arg1;
- (void)importMailboxes:(id)arg1;
- (void)showReleaseNotes:(id)arg1;
- (void)showAccountInfo:(id)arg1;
- (void)alwaysSendWindowsFriendlyAttachments:(id)arg1;
- (void)sendWindowsFriendlyAttachments:(id)arg1;
- (void)alwaysAttachFilesAtEnd:(id)arg1;
- (void)attachFilesAtEnd:(id)arg1;
- (void)insertOriginalAttachments:(id)arg1;
- (void)_resetMenuItemWithTag:(long)arg1;
- (id)_mailboxMenu;
- (id)_getMenuItemInMessageMenuWithTag:(long)arg1;
- (void)_getActiveAccountsThatCanGoOffline:(id)arg1 fetch:(id)arg2 sync:(id)arg3 deleteToTrash:(id)arg4 doesNotDeleteToTrash:(id)arg5;
- (void)_synchronizeAccountListMenuWithTagIfNeeded:(long)arg1;
- (void)bringUpOnlineOfflineMenu:(id)arg1;
- (void)bringUpSynchronizeAccountMenu:(id)arg1;
- (void)bringUpEmptyTrashMenu:(id)arg1;
- (void)bringUpGetNewMailMenu:(id)arg1;
- (void)_removeExtraSeparatorsInMailboxMenu;
- (void)_removeAllItemsInAccountMenuWithTag:(long)arg1;
- (void)_setupAccountMenuItems;
- (void)_setupCheckSpellingSubMenu;
- (void)accountsChanged:(id)arg1;
- (void)_accountsChangedExternally:(id)arg1;
- (void)editAccount:(id)arg1;
- (void)_emptyTrashAndCompact:(id)arg1;
- (void)_confirmEmptyTrashSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)_emptyTrashInAccounts:(id)arg1 storeToCompact:(id)arg2;
- (id)_accountsToEmptyTrashIn:(id)arg1;
- (void)emptyTrashInAccount:(id)arg1;
- (void)compactSelectedMailboxes:(id)arg1;
- (void)toggleSmallIconsInDrawer:(id)arg1;
- (void)_evaluateUsersJunkMailNeeds;
- (void)showToolbarItemForJunkMail:(BOOL)arg1;
- (void)eraseJunkMail:(id)arg1;
- (void)_eraseJunkMailSheetDidEnd:(id)arg1 returnCode:(long)arg2 contextInfo:(void *)arg3;
- (void)toggleThreadedMode:(id)arg1;
- (BOOL)groupingByThreadDefaultsToOn;
- (void)setGroupingByThreadDefaultsToOn:(BOOL)arg1;
- (BOOL)shouldAutoFetchForMessageType:(BOOL)arg1;
- (void)_setShouldAutoFetch:(BOOL)arg1 forMessageType:(BOOL)arg2;
- (long)autoFetchFrequencyForMessageType:(BOOL)arg1;
- (void)setAutoFetchFrequency:(long)arg1 forMessageType:(BOOL)arg2;
- (void)_checkNewMail:(BOOL)arg1;
- (void)doBackgroundFetch:(BOOL)arg1;
- (void)checkNewMailInAccount:(id)arg1;
- (void)checkNewMail:(id)arg1;
- (void)_checkNewMailInAccountRepresentedByMailbox:(id)arg1;
- (void)checkNewMailInSelectedAccounts:(id)arg1;
- (void)updateAllFeeds:(id)arg1;
- (void)autoFetchMail:(id)arg1;
- (void)backgroundFetchCompleted:(id)arg1;
- (void)resetAutoFetchTimer;
- (void)fetchErrorHasOccurred;
- (BOOL)application:(id)arg1 openFile:(id)arg2;
- (BOOL)handleOpenMessage:(id)arg1;
- (void)handleStationeryBundles;
- (void)application:(id)arg1 openFiles:(id)arg2;
- (void)applicationDidUnhide:(id)arg1;
- (void)updateEmailAliasesOnNextActivation;
- (void)applicationDidBecomeActive:(id)arg1;
- (id)openStoreWithMailboxUid:(id)arg1;
- (id)openStoreWithMailboxUid:(id)arg1 andMakeKey:(BOOL)arg2;
- (id)openMessageEditorWithParsedMessage:(id)arg1 headers:(id)arg2;
- (id)_messageEditorWithSettings:(id)arg1;
- (void)addressManagerLoaded;
- (id)activityViewer;
- (id)textEncodingMenuItem;
- (void)loadMailboxesContextMenuNib;
- (id)addButtonMenu;
- (id)mailboxesContextMenu;
- (id)messageViewerContextMenu;
- (id)viewAttachmentContextMenu;
- (id)composeAttachmentContextMenu;
- (BOOL)useAddressAtoms;
- (id)mailboxesController;
- (void)preferencesChanged:(id)arg1;
- (BOOL)handleMailToURL:(id)arg1;
- (void)_handleToDo:(id)arg1 withAction:(id)arg2;
- (void)_handleNote:(id)arg1 withAction:(id)arg2;
- (void)_handleMsg:(id)arg1 withAction:(id)arg2;
- (BOOL)handleMailItemURI:(id)arg1;
- (BOOL)handleMessageURL:(id)arg1;
- (BOOL)handleClickOnURL:(id)arg1 visibleText:(id)arg2 message:(id)arg3 window:(id)arg4 dontSwitch:(BOOL)arg5;
- (id)applicationVersion;
- (id)frameworkVersion;
- (void)mailDocuments:(id)arg1;
- (id)messageEditor;
- (void)makeNoteFromSelection:(id)arg1 userData:(id)arg2 error:(id *)arg3;
- (void)mailSelection:(id)arg1 userData:(id)arg2 error:(id *)arg3;
- (void)mailDocument:(id)arg1 userData:(id)arg2 error:(id *)arg3;
- (void)mailTo:(id)arg1 userData:(id)arg2 error:(id *)arg3;
- (id)deliveryQueue;
- (void)setSelectionFrom:(id)arg1;
- (void)resignSelectionFor:(id)arg1;
- (id)selection;
- (id)selectionOwner;
- (id)preferredAccountBasedOnSelection;
- (id)preferredReplyAddressBasedOnCurrentSelection;
- (BOOL)applicationShouldHandleReopen:(id)arg1 hasVisibleWindows:(BOOL)arg2;
- (id)mailSyncBundle;
- (Class)notesSyncClass;
- (id)syncer;
- (id)syncerForDataType:(long)arg1;
- (id)interestedPartiesForDataType:(long)arg1;
- (BOOL)tellInterestedPartiesDataWillBeSyncedForDataType:(long)arg1;
- (void)tellInterestedPartiesDataWasSyncedForDataType:(long)arg1;
- (id)ownerForDataType:(long)arg1;
- (void)client:(id)arg1 mightWantToSyncEntityNames:(id)arg2;
- (void)quitNoMatterWhat;
- (void)_terminateNoConfirm;
- (void)_approveQuitIfFinished;
- (void)_cleanupFinished;
- (void)cleanUpAccount:(id)arg1;
- (void)_cleanOldDatabases:(id)arg1;
- (id)_currentTerminationHandler;
- (unsigned long)applicationShouldTerminate:(id)arg1;
- (void)nowWouldBeAGoodTimeToTerminate:(id)arg1;
- (void)applicationWillTerminate:(id)arg1;
- (void)addTerminationHandler:(id)arg1;
- (void)removeTerminationHandler:(id)arg1;
- (void)handler:(id)arg1 approvedQuit:(BOOL)arg2;
- (void)replyToApplicationShouldTerminate:(BOOL)arg1;
- (BOOL)isCurrentlyTerminating;
- (void)setIsCurrentlyTerminating:(BOOL)arg1;

@end

