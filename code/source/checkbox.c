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
void fscl_xcube_add_checkbox(xui* ui, int x, int y, const char* label, void (*callback)(int)) {
    ui->num_checkboxes++;
    ui->checkboxes = realloc(ui->checkboxes, ui->num_checkboxes * sizeof(xui_checkbox));
    xui_checkbox* checkbox = &(ui->checkboxes[ui->num_checkboxes - 1]);
    checkbox->position->x = x;
    checkbox->position->y = y;
    checkbox->selected = 0; // Initial state is unchecked
    checkbox->callback = callback;

    // Set default values for the text member
    checkbox->text->content = fscl_xcube_strdup(label);
    checkbox->text->color_front = COLOR_BLUE;
    checkbox->text->color_back = COLOR_BLACK;
    checkbox->text->bold = no;
    checkbox->text->emphasis = no;
}

// Function to handle checkbox state changes
void fscl_xcube_checkbox_state_change_handler(xui* ui, int mouse_x, int mouse_y) {
    for (int i = 0; i < ui->num_checkboxes; i++) {
        xui_checkbox* checkbox = &(ui->checkboxes[i]);
        if (mouse_x >= checkbox->position->x && mouse_x < checkbox->position->x + strlen(checkbox->text->content) + 4 &&
            mouse_y >= checkbox->position->y && mouse_y < checkbox->position->y + 1) {
            // Toggle the state of the checkbox
            checkbox->selected = !checkbox->selected;
            // Invoke the checkbox's callback function
            if (checkbox->callback != NULL) {
                checkbox->callback(checkbox->selected);
            }
            break; // Exit loop after handling the first checkbox state change
        }
    }
}

// Function to set the state of a checkbox
void fscl_xcube_set_checkbox_state(xui* ui, int checkbox_index, int new_state) {
    if (checkbox_index >= 0 && checkbox_index < ui->num_checkboxes) {
        ui->checkboxes[checkbox_index].selected = new_state;
    }
}