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

#include <xcube/basic.h> // all basic cube code

// Function prototypes for label-related functions
xlabel fscl_label_create(int32_t x, int32_t y, const char* text, xcolor color);
void fscl_label_draw(xmanager* manager, xlabel label);
void fscl_label_set_text(xlabel* label, const char* text);

#ifdef __cplusplus
}
#endif

#endif
