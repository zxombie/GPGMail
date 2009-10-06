/*
 *     Generated by class-dump 3.2 (32 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2009 by Steve Nygard.
 */

#import "WebViewEditor.h"

#import "DOMEventListener-Protocol.h"
#import "NSAnimationDelegate-Protocol.h"

@class NSMutableDictionary, NSString, NSUndoManager, WebHTMLView;

@interface NoteWebViewEditor : WebViewEditor <DOMEventListener, NSAnimationDelegate>
{
    WebHTMLView *_documentView;
    NSUndoManager *_undoManager;
    BOOL _ignoreToDoNotifications;
    BOOL _isReadOnly;
    NSMutableDictionary *_todoAnimations;
    NSString *_todoElementIdShowingDeleteButton;
}

+ (id)todoDateFormatter;
- (id)messageController;
- (BOOL)useDesignMode;
- (BOOL)hasContent;
- (id)contentDocument;
- (id)userContentRange;
- (void)beginDocumentEditableContext;
- (void)endDocumentEditableContext;
- (void)pauseEditing;
- (void)resumeEditing;
- (id)documentColor;
- (void)setDocumentColor:(id)arg1;
- (void)goPaperless;
- (void)makePaperbacked;
- (void)goReadOnly;
- (BOOL)thawToDos;
- (void)addTitle:(id)arg1;
- (void)addEmptyFooter;
- (void)appendText:(id)arg1;
- (void)clearSelection;
- (void)setInitialSelection;
- (BOOL)selectionContainsAnyToDos;
- (void)setUp;
- (void)removeToDosWereDeletedNotification;
- (void)close;
- (void)hideIfEmptyPaperlessNote;
- (void)minimizeContentElement;
- (void)maximizeContentElement;
- (BOOL)webView:(id)arg1 shouldChangeSelectedDOMRange:(id)arg2 toDOMRange:(id)arg3 affinity:(unsigned long)arg4 stillSelecting:(BOOL)arg5;
- (BOOL)isPaperless;
- (BOOL)isEditingPaused;
- (void)todosWereAdded:(id)arg1;
- (void)todosWereDeleted:(id)arg1;
- (void)webViewFrameChanged:(id)arg1;
- (void)webViewWillStartLiveResize:(id)arg1;
- (void)webViewDidEndLiveResize:(id)arg1;
- (void)handleEvent:(id)arg1;
- (void)hideLastShownToDoDeleteButton;
- (void)showDeleteButtonForToDo:(id)arg1;
- (void)showDeleteButtonForToDo:(id)arg1 animate:(BOOL)arg2;
- (void)animationDidStop:(id)arg1;
- (void)animationDidEnd:(id)arg1;
- (void)hideDeleteButtonForToDo:(id)arg1;
- (void)createToDo:(id)arg1;
- (void)createToDo:(id)arg1 referringMessage:(id)arg2 referringRange:(id)arg3;
- (void)appendToDoWithText:(id)arg1 referringMessage:(id)arg2 referringRange:(id)arg3;
- (void)createToDoWithContext:(id)arg1;
- (void)appendToDoWithContext:(id)arg1;
- (void)sendFakeMouseMovedEvent;
- (void)smartDeleteToDoElement:(id)arg1;
- (void)smartStripToDoElement:(id)arg1 selectDownstream:(BOOL)arg2;
- (void)stripToDoElements:(id)arg1;
- (void)deleteToDoElements:(id)arg1;
- (void)untodoToDoElements:(id)arg1;
- (void)updateToDoElements:(id)arg1;
- (void)updateToDoElement:(id)arg1 todo:(id)arg2;
- (id)fragmentFromToDos:(id)arg1;
- (void)deleteContent;
- (void)appendTodos:(id)arg1;
- (id)todos;
- (void)setTodos:(id)arg1;
- (id)webView:(id)arg1 contextMenuItemsForElement:(id)arg2 defaultMenuItems:(id)arg3;
- (id)createToDo;
- (id)createToDoWithToDo:(id)arg1;
- (id)createToDoWithToDoID:(id)arg1;
- (id)createToDoReferencingMessage:(id)arg1 range:(id)arg2;
- (id)todoInsertionTypeName:(int)arg1;
- (void)setSelectionFromToDo:(id)arg1 type:(int)arg2;
- (void)webMessageController:(id)arg1 willDisplayMenuItems:(id)arg2;
- (id)insertToDo:(id)arg1 contentArchive:(id)arg2;
- (id)insertToDo:(id)arg1 contentText:(id)arg2;
- (id)replaceSelectedTextWithNewline;
- (id)replaceSelectedListItemsWithNewline;
- (void)insertToDosWithTexts:(id)arg1;
- (void)convertLinesIntoToDos;
- (void)smartConvertListItemsIntoToDos;
- (void)smartInsertToDo:(id)arg1;
- (void)insertNewlineIfNeededAfterToDo:(id)arg1;
- (void)deleteToDosFromElements:(id)arg1;
- (id)documentView;
- (void)dealloc;
- (id)webFrameBridge;
- (void)untodoTodoNode:(id)arg1;
- (void)removeTodoNode:(id)arg1;
- (void)removeEventListenersForToDoElement:(id)arg1;
- (void)addEventListenersForToDoElement:(id)arg1;
- (void)todoView:(id)arg1 didLoadToDoID:(id)arg2;
- (void)selectDOMRange:(id)arg1 previousRange:(id)arg2;
- (void)preselectDOMRangeForDetodo:(id)arg1 previousRange:(id)arg2;
- (void)postselectDOMRangeForDetodo:(id)arg1 previousRange:(id)arg2;
- (void)toDoContentHasChanged;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)removeStyleFromMicrosoftExchangeContent;
- (id)undoManagerForWebView:(id)arg1;
- (void)removeAllFormattingFromWebView;
- (id)alertForConvertingToRichText;
- (void)webView:(id)arg1 didWriteSelectionToPasteboard:(id)arg2;
- (void)webView:(id)arg1 willPerformDragSourceAction:(int)arg2 fromPoint:(struct CGPoint)arg3 withPasteboard:(id)arg4;
- (BOOL)adjustFontStyle:(id)arg1 beforeApplyingToElementsInDOMRange:(id)arg2;
- (BOOL)webView:(id)arg1 shouldApplyStyle:(id)arg2 toElementsInDOMRange:(id)arg3;
- (void)continueShouldApplyStyle:(id)arg1 returnCode:(long)arg2 contextInfo:(id)arg3;
- (BOOL)webView:(id)arg1 shouldInsertAttachments:(id)arg2 context:(id)arg3;
- (void)continueShouldInsertAttachments:(id)arg1 returnCode:(long)arg2 contextInfo:(id)arg3;
- (id)createToDoElementWithToDo:(id)arg1 contentFragment:(id)arg2;
- (id)createToDoElementWithToDo:(id)arg1 contentArchive:(id)arg2;
- (id)createToDoElementWithToDoElement:(id)arg1 todosOnPasteboard:(id)arg2 oldToNewID:(id)arg3;
- (void)addToDos:(id)arg1;
- (BOOL)webView:(id)arg1 shouldMoveRangeAfterDelete:(id)arg2 replacingRange:(id)arg3;
- (void)webView:(id)arg1 willReplaceSelectionWithFragment:(id *)arg2 pasteboard:(id)arg3 type:(id)arg4 options:(int *)arg5;
- (BOOL)webView:(id)arg1 shouldDeleteDOMRange:(id)arg2;
- (BOOL)webView:(id)arg1 shouldInsertNode:(id)arg2 replacingDOMRange:(id)arg3 givenAction:(int)arg4;
- (BOOL)webView:(id)arg1 shouldInsertText:(id)arg2 replacingDOMRange:(id)arg3 givenAction:(int)arg4;
- (BOOL)webView:(id)arg1 shouldShowDeleteInterfaceForElement:(id)arg2;
- (BOOL)webView:(id)arg1 doCommandBySelector:(SEL)arg2;
- (BOOL)webViewShouldReplaceSelectionWithContentsOfWebpage:(id)arg1;
- (void)moveSelectionToEndOfDocument:(id)arg1;
- (void)moveSelectionToStartOfDocument:(id)arg1;
- (void)growSelection:(id)arg1;
- (void)selectToDoCheckbox:(id)arg1;
- (void)deleteAndUnToDo:(id)arg1 todoElement:(id)arg2 deleteSelector:(SEL)arg3;
- (BOOL)deleteBackward:(id)arg1;
- (BOOL)deleteForward:(id)arg1;
- (BOOL)insertNewlineIgnoringFieldEditor:(id)arg1;
- (BOOL)insertNewline:(id)arg1;
- (BOOL)isReadOnly;
- (void)setIsReadOnly:(BOOL)arg1;
- (BOOL)ignoreToDoNotifications;
- (void)setIgnoreToDoNotifications:(BOOL)arg1;
- (id)undoManager;
- (void)setUndoManager:(id)arg1;
- (id)todoElementIdShowingDeleteButton;
- (void)setTodoElementIdShowingDeleteButton:(id)arg1;

@end

