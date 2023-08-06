#ifndef MAC_GUI_H_
#define MAC_GUI_H_

#include "mac_view.h"
#include "mac_internals.h"
#include <stdint.h>
#include <stdbool.h>

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>

@interface NSMac_Button : NSButton

@end
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*
    This is base of the current NSButtonCell.h button styles
    NSBezelStyleRounded           = 1,
    NSBezelStyleRegularSquare     = 2,
    NSBezelStyleDisclosure        = 5,
    NSBezelStyleShadowlessSquare  = 6,
    NSBezelStyleCircular          = 7,
    NSBezelStyleTexturedSquare    = 8,
    NSBezelStyleHelpButton        = 9,
    NSBezelStyleSmallSquare       = 10,
    NSBezelStyleTexturedRounded   = 11,
    NSBezelStyleRoundRect         = 12,
    NSBezelStyleRecessed          = 13,
    NSBezelStyleRoundedDisclosure = 14,
    NSBezelStyleInline API_AVAILABLE(macos(10.7)) = 15,
*/
typedef enum 
{
    MAC_BUTTON_STYLE_NONE               = 0,
    MAC_BUTTON_STYLE_ROUNDED            = 1,
    MAC_BUTTON_STYLE_REGULAR_SQUARE     = 2,
    MAC_BUTTON_STYLE_DISCLOSURE         = 5,
    MAC_BUTTON_STYLE_SHADOWLESS_SQUARE  = 6,
    MAC_BUTTON_STYLE_CIRCULAR           = 7,
    MAC_BUTTON_STYLE_TEXTURED_SQUARE    = 8,
    MAC_BUTTON_STYLE_HELP_BUTTON        = 9,
    MAC_BUTTON_STYLE_SMALL_SQUARE       = 10,
    MAC_BUTTON_STYLE_TEXTURED_ROUNDED   = 11,
    MAC_BUTTON_STYLE_ROUND_RECT         = 12,
    MAC_BUTTON_STYLE_RECESSED           = 13,
    MAC_BUTTON_STYLE_ROUNDED_DISCLOSURE = 14,
    MAC_BUTTON_STYLE_INLINE             = 15,
} Mac_Button_Style_Flags;

/*
    This is base of the current NSButtonCell.h button types
    NSButtonTypeMomentaryLight    = 0,
    NSButtonTypePushOnPushOff     = 1,
    NSButtonTypeToggle            = 2,
    NSButtonTypeSwitch            = 3,
    NSButtonTypeRadio             = 4,
    NSButtonTypeMomentaryChange   = 5,
    NSButtonTypeOnOff             = 6,
    NSButtonTypeMomentaryPushIn   = 7,
    NSButtonTypeAccelerator API_AVAILABLE(macos(10.10.3)) = 8,
    NSButtonTypeMultiLevelAccelerator API_AVAILABLE(macos(10.10.3)) = 9,
*/
typedef enum 
{
    MAC_BUTTON_TYPE_MOMENTARY_LIGHT            = 0,
    MAC_BUTTON_TYPE_PUSH_ON_PUSH_OFF           = 1,
    MAC_BUTTON_TYPE_TOGGLE                     = 2,
    MAC_BUTTON_TYPE_SWITCH                     = 3,
    MAC_BUTTON_TYPE_RADIO                      = 4,
    MAC_BUTTON_TYPE_MOMENTARY_CHANGE           = 5,
    MAC_BUTTON_TYPE_ON_OFF                     = 6,
    MAC_BUTTON_TYPE_MOMENTARY_PUSH_IN          = 7,
    MAC_BUTTON_TYPE_ACCELERATOR                = 8,
    MAC_BUTTON_TYPE_MULTI_LEVEL_ACCELERATOR    = 9,
} Mac_Button_Type_Flags;

typedef struct Mac_Button Mac_Button;

/*
    Function pointer for the button action
    takes a pointer to the button that was clicked

*/
typedef void (*ButtonAction)(Mac_Button*);

/*
    This is the struct that holds all the information for the button
*/
struct Mac_Button {
    MDimensions dimensions;
    MTitle title;
    Mac_View* parent_view;
    ButtonAction action;
    int tag;
    MImage image;
};

/*!
    Creates a standard push button with a title and image.
    @param dimensions The dimensions of the button.
    @param title The title of the button.
    @param image The image of the button.
    @param parent_view The parent view of the button.
    @param action The action of the button.
    @return A pointer to the button.
*/
Mac_Button* mac_button_spb_tita(MDimensions dimensions, MTitle title, MImage image, Mac_View* parent_view, ButtonAction action);
/*!
    Creates a standard push button with the provided title.
    @param dimensions The dimensions of the button.
    @param title The title of the button.
    @param parent_view The parent view of the button.
    @param action The action of the button.
    @return A pointer to the button.
*/
Mac_Button* mac_button_spb_tta(MDimensions dimensions, MTitle title, Mac_View* parent_view, ButtonAction action);
/*!
    Creates a standard push button with the provided image.
    @param dimensions The dimensions of the button.
    @param image The image of the button.
    @param parent_view The parent view of the button.
    @param action The action of the button.
    @return A pointer to the button.
*/
Mac_Button* mac_button_spb_ita(MDimensions dimensions, MImage image, Mac_View* parent_view, ButtonAction action);
void destroyButton(Mac_Button* button);

#ifdef __cplusplus
}
#endif

#endif // MAC_GUI_H_