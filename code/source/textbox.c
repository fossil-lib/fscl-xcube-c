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
#include "fossil/xcube/textbox.h"

// Function to create a textbox and add it to the TUI
void fscl_xcube_add_textbox(xui* tui, int x, int y, int width, int height, const char* text) {
    tui->num_textboxes++;
    tui->textboxes = realloc(tui->textboxes, tui->num_textboxes * sizeof(xui_textbox));
    xui_textbox* textbox = &(tui->textboxes[tui->num_textboxes - 1]);
    textbox->x = x;
    textbox->y = y;
    textbox->width = width;
    textbox->height = height;
    textbox->text = fscl_xcube_strdup(text);
}

// Function to set the text content of a textbox
void fscl_xcube_set_textbox_text(xui* tui, int textbox_index, const char* new_text) {
    if (textbox_index >= 0 && textbox_index < tui->num_textboxes) {
        free(tui->textboxes[textbox_index].text);
        tui->textboxes[textbox_index].text = fscl_xcube_strdup(new_text);
    }
}
