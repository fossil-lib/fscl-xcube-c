/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef FSCL_BUTTON_H
#define FSCL_BUTTON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <xcube/basic.h> // all basic cube code

// Function prototype for the callback function
typedef void (*button_callback)(void);

// Structure for the button with enhanced functionality
typedef struct {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    char label[50];
    xcolor color;
    button_callback click_callback;  // Callback function pointer
    int visible;                     // Visibility flag (1: visible, 0: hidden)
    int enabled;                     // Enabled flag (1: enabled, 0: disabled)
} xbutton;

// Function prototypes for button-related functions
xbutton fscl_button_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* label, xcolor color, button_callback callback);
void fscl_button_draw(xmanager* manager, xbutton button);
void fscl_button_set_label(xbutton* button, const char* label);
void fscl_button_set_position(xbutton* button, int32_t x, int32_t y);
void fscl_button_set_size(xbutton* button, int32_t width, int32_t height);
void fscl_button_set_color(xbutton* button, xcolor color);
void fscl_button_set_click_callback(xbutton* button, button_callback callback);
void fscl_button_set_visibility(xbutton* button, int visible);
void fscl_button_set_enabled(xbutton* button, int enabled);

#ifdef __cplusplus
}
#endif

#endif
