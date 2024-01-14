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
#ifndef FSCL_INPUT_H
#define FSCL_INPUT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <xcube/basic.h> // all basic cube code

// Function prototypes for input-related functions
xinput fscl_input_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* text, xcolor color);
void fscl_input_draw(xmanager* manager, xinput input);
void fscl_input_set_text(xinput* input, const char* text);

#ifdef __cplusplus
}
#endif

#endif
