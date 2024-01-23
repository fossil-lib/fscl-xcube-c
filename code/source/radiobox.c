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
#include "fossil/xcube/radiobox.h"

extern char* fscl_xcube_strdup(const char* str);

// Function to create a radiobox and add it to the TUI
void fscl_xcube_add_radiobox(xui* tui, int x, int y, const char* label, void (*callback)(int)) {
    tui->num_radioboxes++;
    tui->radioboxes = realloc(tui->radioboxes, tui->num_radioboxes * sizeof(xui_radiobox));
    xui_radiobox* radiobox = &(tui->radioboxes[tui->num_radioboxes - 1]);
    radiobox->x = x;
    radiobox->y = y;
    radiobox->label = fscl_xcube_strdup(label);
    radiobox->selected = 0; // Initial state is unselected
    radiobox->callback = callback;
}

// Function to handle radiobox state changes
void fscl_xcube_radiobox_state_change_handler(xui* tui, int mouse_x, int mouse_y) {
    for (int i = 0; i < tui->num_radioboxes; i++) {
        xui_radiobox* radiobox = &(tui->radioboxes[i]);
        if (mouse_x >= radiobox->x && mouse_x < radiobox->x + strlen(radiobox->label) + 4 &&
            mouse_y >= radiobox->y && mouse_y < radiobox->y + 1) {
            // Set the state of the radiobox to selected
            radiobox->selected = 1;
            // Invoke the radiobox's callback function
            if (radiobox->callback != NULL) {
                radiobox->callback(radiobox->selected);
            }
            // Unselect other radioboxes in the same group
            for (int j = 0; j < tui->num_radioboxes; j++) {
                if (j != i) {
                    tui->radioboxes[j].selected = 0;
                }
            }
            break; // Exit loop after handling the first radiobox state change
        }
    }
}

// Function to set the state of a radiobox
void fscl_xcube_set_radiobox_state(xui* tui, int radiobox_index, int new_state) {
    if (radiobox_index >= 0 && radiobox_index < tui->num_radioboxes) {
        tui->radioboxes[radiobox_index].selected = new_state;
    }
}
