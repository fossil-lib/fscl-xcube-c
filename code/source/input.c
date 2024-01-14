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
#include "fossil/xcube/input.h"

// Create and initialize a new input field with enhanced functionality
xinput fscl_input_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* text, xcolor color) {
    xinput input = {x, y, width, height, color, "", XCOLOR_BLACK, 1, 1};
    fscl_input_set_text(&input, text);
    return input;
}

// Draw an input field on the active window
void fscl_input_draw(xmanager* manager, xinput input) {
    if (input.visible) {
        fscl_manager_draw_active(manager, input);
    }
}

// Set the text of an input field
void fscl_input_set_text(xinput* input, const char* text) {
    strncpy(input->text, text, sizeof(input->text) - 1);
    input->text[sizeof(input->text) - 1] = '\0';  // Ensure null-terminated string
}

// Set the position of an input field
void fscl_input_set_position(xinput* input, int32_t x, int32_t y) {
    input->x = x;
    input->y = y;
}

// Set the size of an input field
void fscl_input_set_size(xinput* input, int32_t width, int32_t height) {
    input->width = width;
    input->height = height;
}

// Set the text color of an input field
void fscl_input_set_text_color(xinput* input, xcolor color) {
    input->text_color = color;
}

// Set the placeholder text of an input field
void fscl_input_set_placeholder(xinput* input, const char* placeholder) {
    strncpy(input->placeholder, placeholder, sizeof(input->placeholder) - 1);
    input->placeholder[sizeof(input->placeholder) - 1] = '\0';  // Ensure null-terminated string
}

// Set the visibility of an input field
void fscl_input_set_visibility(xinput* input, int visible) {
    input->visible = visible;
}

// Set the enabled state of an input field
void fscl_input_set_enabled(xinput* input, int enabled) {
    input->enabled = enabled;
}
