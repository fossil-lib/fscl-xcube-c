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
#ifndef FSCL_TEXTBOX_H
#define FSCL_TEXTBOX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

// Function to create a textbox and add it to the TUI
void fscl_xcube_add_textbox(xui* ui, int x, int y, int width, int height, const char* text);

// Function to set the text content of a textbox
void fscl_xcube_set_textbox_content(xui* ui, int textbox_index, const char* new_text);

#ifdef __cplusplus
}
#endif

#endif
