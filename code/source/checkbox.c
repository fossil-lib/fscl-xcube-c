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
#include "fossil/xcube/checkbox.h"

extern char* fscl_xcube_strdup(const char* str);

// Function to create a checkbox and add it to the TUI
void fscl_xcube_add_checkbox(xui* tui, int x, int y, const char* label, void (*callback)(int)) {
    tui->num_checkboxes++;
    tui->checkboxes = realloc(tui->checkboxes, tui->num_checkboxes * sizeof(xui_checkbox));
    xui_checkbox* checkbox = &(tui->checkboxes[tui->num_checkboxes - 1]);
    checkbox->x = x;
    checkbox->y = y;
    checkbox->label = fscl_xcube_strdup(label);
    checkbox->checked = 0; // Initial state is unchecked
    checkbox->callback = callback;
}

// Function to handle checkbox state changes
void fscl_xcube_checkbox_state_change_handler(xui* tui, int mouse_x, int mouse_y) {
    for (int i = 0; i < tui->num_checkboxes; i++) {
        xui_checkbox* checkbox = &(tui->checkboxes[i]);
        if (mouse_x >= checkbox->x && mouse_x < checkbox->x + strlen(checkbox->label) + 4 &&
            mouse_y >= checkbox->y && mouse_y < checkbox->y + 1) {
            // Toggle the state of the checkbox
            checkbox->checked = !checkbox->checked;
            // Invoke the checkbox's callback function
            if (checkbox->callback != NULL) {
                checkbox->callback(checkbox->checked);
            }
            break; // Exit loop after handling the first checkbox state change
        }
    }
}

// Function to set the state of a checkbox
void fscl_xcube_set_checkbox_state(xui* tui, int checkbox_index, int new_state) {
    if (checkbox_index >= 0 && checkbox_index < tui->num_checkboxes) {
        tui->checkboxes[checkbox_index].checked = new_state;
    }
}