#import "MView.h"
#include "MDefs.h"
#import "MError.h"
#import "MWindow.h"

void MCreateContentView(MWindow *window, MColor backgroundColor)
{
    // check if the window is not null
    if (!window) {
        NSLog(@"Failed to set the window View! The window is null!\n");
        return;
    }
    // set the window main View
    // allocate memory for the window View and check if the allocation was
    // successful
    MView *view = (MView *)malloc(sizeof(MView));
    if (!view) {
        NSLog(@"Failed to allocate memory for the window View!\n");
        return;
    }
    // set the window View properties
    view->width = window->width;
    view->height = window->height;
    view->x = 0;
    view->y = 0;
    view->cornerRadius = 0;
    view->backgroundColor = backgroundColor;
    // create the ns window View
    NSWindow *nsWindow = (__bridge NSWindow *)window->_this;
    NSColor *nsColor = [NSColor colorWithSRGBRed:backgroundColor.r
                                            green:backgroundColor.g
                                            blue:backgroundColor.b
                                            alpha:backgroundColor.a];
    NSRect frame = NSMakeRect(0, 0, window->width, window->height);
    NSView *nsView = [[NSView alloc] initWithFrame:frame];
    if (!nsView) {
        NSLog(@"Failed to create NSView!\n");
        free(view);
        return;
    }
    // set the ns view properties
    [nsView setWantsLayer:YES]; // set the view to use a layer so we can set the
    [nsView.layer setBackgroundColor: nsColor.CGColor]; // set the background color
    [nsWindow setContentView:nsView]; // set the ns view as the ns window content view
    // set ns view
    view->_this = (__bridge void *)nsView;

    window->contentView = view;

    return;
}

MView *MCreateSubView(MView *parent, int x, int y, int width, int height, MColor backgroundColor, MBool resizable, float cornerRadius)
{
    // check if the parent View is not null
    if (!parent) {
        NSLog(@"Failed to create sub View! The parent View is null!\n");
        return NULL;
    }
    // allocate memory for the sub View and check if the allocation was successful
    MView *subView = (MView *)malloc(sizeof(MView));

    if (!subView) {
        NSLog(@"Failed to allocate memory for the sub View!\n");
        return NULL;
    }
    // set the sub View properties
    subView->width = width;
    subView->height = height;
    subView->x = x;
    subView->y = y;
    subView->cornerRadius = 0;
    subView->backgroundColor = backgroundColor;
    subView->resizable = resizable;
    // create the ns sub View
    NSView *nsParentView = (__bridge NSView *)parent->_this;
    NSColor *nsColor = [NSColor colorWithSRGBRed:backgroundColor.r
                                            green:backgroundColor.g
                                            blue:backgroundColor.b
                                            alpha:backgroundColor.a];
    NSRect frame = NSMakeRect(x, y, width, height);
    NSView *nsView = [[NSView alloc] initWithFrame:frame];
    // set the ns sub View properties
    [nsView setWantsLayer:YES]; // set the sub View to use a layer so we can set
    // set corner radius
    [nsView.layer setCornerRadius:cornerRadius];
    [nsView.layer setBackgroundColor:nsColor.CGColor]; // set the background color
    if (resizable) {
        [nsView setAutoresizingMask:NSViewWidthSizable | NSViewHeightSizable];
    }

    [nsParentView addSubview:nsView]; // add the ns sub View to the ns parent View
    // set ns sub View
    subView->_this = (__bridge void *)nsView;

    return subView;
}

void MHideView(MView *View)
{
    // check if the View is not null
    if (!View) {
        NSLog(@"Failed to hide the View! The View is null!\n");
        return;
    }
    // get the ns view
    NSView *view = (__bridge NSView *)View->_this;
    // hide the view
    [view setHidden:YES];
}

void MShowView(MView *View)
{
    // check if the View is not null
    if (!View) {
        NSLog(@"Failed to show the View! The View is null!\n");
        return;
    }
    // get the ns view
    NSView *view = (__bridge NSView *)View->_this;
    // show the view
    [view setHidden:NO];
}

void MDestroyView(MView *View)
{
    // check if the View is not null
    if (!View) {
        NSLog(@"Failed to destroy the View! The View is null!\n");
        return;
    }
    // get the ns view
    NSView *view = (__bridge NSView *)View->_this;
    // remove the view from its superview
    [view removeFromSuperview];
    // free the View
    free(View);
}