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

// Structure for the label with enhanced functionality
typedef struct {
    int32_t x;
    int32_t y;
    char text[100];
    xcolor color;
    int font_size;
    int text_alignment;  // 0: left, 1: center, 2: right
    int visible;         // Visibility flag (1: visible, 0: hidden)
} xlabel;

// Function prototypes for label-related functions
xlabel fscl_label_create(int32_t x, int32_t y, const char* text, xcolor color);
void fscl_label_draw(xmanager* manager, xlabel label);
void fscl_label_set_text(xlabel* label, const char* text);
void fscl_label_set_position(xlabel* label, int32_t x, int32_t y);
void fscl_label_set_text_color(xlabel* label, xcolor color);
void fscl_label_set_font_size(xlabel* label, int font_size);
void fscl_label_set_text_alignment(xlabel* label, int alignment);
void fscl_label_set_visibility(xlabel* label, int visible);
void fscl_label_rotate_text(xlabel* label, int degrees);

#ifdef __cplusplus
}
#endif

#endif
