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

// Function to add a label to the TUI
void fscl_xcube_add_label(xui* tui, int x, int y, const char* text) {
    tui->num_labels++;
    tui->labels = realloc(tui->labels, tui->num_labels * sizeof(xui_label));
    xui_label* label = &(tui->labels[tui->num_labels - 1]);
    label->x = x;
    label->y = y;
    label->text = fscl_xcube_strdup(text);
}
