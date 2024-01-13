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
#include "fossil/button.h"

// Create and initialize a new button
xbutton fscl_button_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* label, xcolor color) {
    xbutton button = {x, y, width, height, color};
    fscl_button_set_label(&button, label);
    return button;
}

// Draw a button on the active window
void fscl_button_draw(xmanager* manager, xbutton button) {
    fscl_manager_draw_active(manager, button);
}

// Set the label of a button
void fscl_button_set_label(xbutton* button, const char* label) {
    strncpy(button->label, label, sizeof(button->label) - 1);
    button->label[sizeof(button->label) - 1] = '\0';  // Ensure null-terminated string
}
