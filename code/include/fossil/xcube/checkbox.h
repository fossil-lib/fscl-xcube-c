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
#ifndef FSCL_CHECKBOX_H
#define FSCL_CHECKBOX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

// Function to create a checkbox and add it to the TUI
void fscl_xcube_add_checkbox(xui* ui, int x, int y, const char* label, void (*callback)(int));

// Function to handle checkbox state changes
void fscl_xcube_checkbox_state_change_handler(xui* ui, int mouse_x, int mouse_y);

// Function to set the state of a checkbox
void fscl_xcube_set_checkbox_state(xui* ui, int checkbox_index, int new_state);

#ifdef __cplusplus
}
#endif

#endif
