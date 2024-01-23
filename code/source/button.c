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

extern char* fscl_xcube_strdup(const char* str);

// Function to create a button and add it to the TUI
void fscl_xcube_add_button(xui* tui, int x, int y, int width, int height, const char* label, void (*callback)()) {
    tui->num_buttons++;
    tui->buttons = realloc(tui->buttons, tui->num_buttons * sizeof(xui_button));
    xui_button* button = &(tui->buttons[tui->num_buttons - 1]);
    button->x = x;
    button->y = y;
    button->width = width;
    button->height = height;
    button->label = fscl_xcube_strdup(label);
    button->callback = callback;
}

// Function to handle button click events
void fscl_xcube_button_click_handler(xui* tui, int mouse_x, int mouse_y) {
    for (int i = 0; i < tui->num_buttons; i++) {
        xui_button* button = &(tui->buttons[i]);
        if (mouse_x >= button->x && mouse_x < button->x + button->width &&
            mouse_y >= button->y && mouse_y < button->y + button->height) {
            // Invoke the button's callback function
            if (button->callback != NULL) {
                button->callback();
            }
            break; // Exit loop after handling the first button click
        }
    }
}
