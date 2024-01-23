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

#include <fossil/xcube/basic.h> // all basic cube code

// Function to add a button to the TUI
void fscl_xcube_add_button(xui* tui, int x, int y, int width, int height, const char* label, void (*callback)());

// Function to handle button click events
void fscl_xcube_button_click_handler(xui* tui, int mouse_x, int mouse_y);

#ifdef __cplusplus
}
#endif

#endif
