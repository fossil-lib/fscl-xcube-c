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

// Create and initialize a new input field
xinput fscl_input_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* text, xcolor color) {
    xinput input = {x, y, width, height, color};
    fscl_input_set_text(&input, text);
    return input;
}

// Draw an input field on the active window
void fscl_input_draw(xmanager* manager, xinput input) {
    fscl_manager_draw_active(manager, input);
}

// Set the text of an input field
void fscl_input_set_text(xinput* input, const char* text) {
    strncpy(input->text, text, sizeof(input->text) - 1);
    input->text[sizeof(input->text) - 1] = '\0';  // Ensure null-terminated string
}
