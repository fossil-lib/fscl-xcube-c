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
#include "fossil/xcube/button.h"

// Create and initialize a new button with enhanced functionality
xbutton fscl_button_create(int32_t x, int32_t y, int32_t width, int32_t height, const char* label, xcolor color, button_callback callback) {
    xbutton button = {x, y, width, height, color, callback, 1, 1};
    fscl_button_set_label(&button, label);
    return button;
}

// Draw a button on the active window and invoke the callback if present
void fscl_button_draw(xmanager* manager, xbutton button) {
    if (button.visible) {
        fscl_manager_draw_active(manager, button);

        // Check if the button is enabled and has a callback, then invoke it
        if (button.enabled && button.click_callback != NULL) {
            button.click_callback();
        }
    }
}

// Set the label of a button
void fscl_button_set_label(xbutton* button, const char* label) {
    strncpy(button->label, label, sizeof(button->label) - 1);
    button->label[sizeof(button->label) - 1] = '\0';  // Ensure null-terminated string
}

// Set the position of a button
void fscl_button_set_position(xbutton* button, int32_t x, int32_t y) {
    button->x = x;
    button->y = y;
}

// Set the size of a button
void fscl_button_set_size(xbutton* button, int32_t width, int32_t height) {
    button->width = width;
    button->height = height;
}

// Set the color of a button
void fscl_button_set_color(xbutton* button, xcolor color) {
    button->color = color;
}

// Set the click callback of a button
void fscl_button_set_click_callback(xbutton* button, button_callback callback) {
    button->click_callback = callback;
}

// Set the visibility of a button
void fscl_button_set_visibility(xbutton* button, int visible) {
    button->visible = visible;
}

// Set the enabled state of a button
void fscl_button_set_enabled(xbutton* button, int enabled) {
    button->enabled = enabled;
}
