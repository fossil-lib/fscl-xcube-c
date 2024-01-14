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
#include <math.h>

// Create and initialize a new label with enhanced functionality
xlabel fscl_label_create(int32_t x, int32_t y, const char* text, xcolor color) {
    xlabel label = {x, y, color, 12, 0, 1};
    fscl_label_set_text(&label, text);
    return label;
}

// Draw a label on the active window
void fscl_label_draw(xmanager* manager, xlabel label) {
    if (label.visible) {
        fscl_manager_draw_active(manager, label);
    }
}

// Set the text of a label
void fscl_label_set_text(xlabel* label, const char* text) {
    strncpy(label->text, text, sizeof(label->text) - 1);
    label->text[sizeof(label->text) - 1] = '\0';  // Ensure null-terminated string
}

// Set the position of a label
void fscl_label_set_position(xlabel* label, int32_t x, int32_t y) {
    label->x = x;
    label->y = y;
}

// Set the text color of a label
void fscl_label_set_text_color(xlabel* label, xcolor color) {
    label->color = color;
}

// Set the font size of a label
void fscl_label_set_font_size(xlabel* label, int font_size) {
    label->font_size = font_size;
}

// Set the text alignment of a label
void fscl_label_set_text_alignment(xlabel* label, int alignment) {
    if (alignment >= 0 && alignment <= 2) {
        label->text_alignment = alignment;
    }
}

// Set the visibility of a label
void fscl_label_set_visibility(xlabel* label, int visible) {
    label->visible = visible;
}

// Rotate the text of a label
void fscl_label_rotate_text(xlabel* label, int degrees) {
    // Rotate text by updating the text alignment
    int alignment = (label->text_alignment + (degrees / 90)) % 3;
    if (alignment < 0) {
        alignment += 3;
    }
    label->text_alignment = alignment;
}
