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

// Function prototype for the callback function
typedef void (*button_callback)(void);

// Function prototypes for button-related functions
xbutton fscl_button_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* label, xcolor color, button_callback callback);
void fscl_button_draw(xmanager* manager, xbutton button);
void fscl_button_set_label(xbutton* button, const char* label);

#ifdef __cplusplus
}
#endif

#endif
