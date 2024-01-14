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
#include "fossil/xcube//label.h"

// Create and initialize a new label
xlabel fscl_label_create(int32_t x, int32_t y, const char* text, xcolor color) {
    xlabel label = {x, y, color};
    fscl_label_set_text(&label, text);
    return label;
}

// Draw a label on the active window
void fscl_label_draw(xmanager* manager, xlabel label) {
    fscl_manager_draw_active(manager, label);
}

// Set the text of a label
void fscl_label_set_text(xlabel* label, const char* text) {
    strncpy(label->text, text, sizeof(label->text) - 1);
    label->text[sizeof(label->text) - 1] = '\0';  // Ensure null-terminated string
}
