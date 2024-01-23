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
#ifndef FSCL_LABEL_H
#define FSCL_LABEL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

// Function to add a label to the TUI
void fscl_xcube_add_label(xui* tui, int x, int y, const char* text);

// Function updates the content of the specified label.
void fscl_xcube_set_label_content(xui* tui, int label_index, const char* new_content);

#ifdef __cplusplus
}
#endif

#endif
