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
#include "fossil/xcube/label.h"

extern char* fscl_xcube_strdup(const char* str);

// Function to add a label to the TUI
void fscl_xcube_add_label(xui* tui, int x, int y, const char* text) {
    tui->num_labels++;
    tui->labels = realloc(tui->labels, tui->num_labels * sizeof(xui_label));
    xui_label* label = &(tui->labels[tui->num_labels - 1]);
    label->x = x;
    label->y = y;
    label->text = fscl_xcube_strdup(text);
}

void fscl_xcube_set_label_content(xui* tui, int label_index, const char* new_content) {
    if (tui == NULL || label_index < 0 || label_index >= tui->num_labels) {
        // Handle invalid input or index out of bounds
        return;
    }

    // Update the content of the specified label using strcpy
    strcpy(tui->labels[label_index].text, new_content);
}
