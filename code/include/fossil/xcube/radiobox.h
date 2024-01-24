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
#ifndef FSCL_RADIOBOX_H
#define FSCL_RADIOBOX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

// Function to create a radiobox and add it to the TUI
void fscl_xcube_add_radiobox(xui* ui, int x, int y, const char* label, void (*callback)(int));

// Function to handle radiobox state changes
void fscl_xcube_radiobox_state_change_handler(xui* ui, int mouse_x, int mouse_y);

// Function to set the state of a radiobox
void fscl_xcube_set_radiobox_state(xui* ui, int radiobox_index, int new_state);

#ifdef __cplusplus
}
#endif

#endif
