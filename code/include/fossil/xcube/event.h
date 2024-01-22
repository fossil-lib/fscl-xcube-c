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
#ifndef FSCL_EVENT_H
#define FSCL_EVENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <basic.h> // all basic cube code

// Function to handle mouse events
void fscl_xcube_handle_mouse_event(xui* tui, int mouse_x, int mouse_y);

// Function to handle keyboard events
void fscl_xcube_handle_keyboard_event(xui* tui, char key);

#ifdef __cplusplus
}
#endif

#endif
