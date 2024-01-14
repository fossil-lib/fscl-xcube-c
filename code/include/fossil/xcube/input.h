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

// Structure for the input field with enhanced functionality
typedef struct {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    char text[100];
    char placeholder[100];
    xcolor text_color;
    int visible;  // Visibility flag (1: visible, 0: hidden)
    int enabled;  // Enabled flag (1: enabled, 0: disabled)
} xinput;

// Function prototypes for input-related functions
xinput fscl_input_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* text, xcolor color);
void fscl_input_draw(xmanager* manager, xinput input);
void fscl_input_set_text(xinput* input, const char* text);
void fscl_input_set_position(xinput* input, int32_t x, int32_t y);
void fscl_input_set_size(xinput* input, int32_t width, int32_t height);
void fscl_input_set_text_color(xinput* input, xcolor color);
void fscl_input_set_placeholder(xinput* input, const char* placeholder);
void fscl_input_set_visibility(xinput* input, int visible);
void fscl_input_set_enabled(xinput* input, int enabled);

#ifdef __cplusplus
}
#endif

#endif
