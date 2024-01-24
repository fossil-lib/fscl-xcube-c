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
void fscl_xcube_add_button(xui* ui, int x, int y, int width, int height, const char* label, void (*callback)()) {
    ui->num_buttons++;
    ui->buttons = realloc(ui->buttons, ui->num_buttons * sizeof(xui_button));
    xui_button* button = &(ui->buttons[ui->num_buttons - 1]);
    button->position->x = x;
    button->position->y = y;
    button->dimensions->width = width;
    button->dimensions->height = height;
    button->callback = callback;

    // Set default values for the text member
    button->text->content = fscl_xcube_strdup(label);
    button->text->color_front = COLOR_BLUE;
    button->text->color_back = COLOR_BLACK;
    button->text->bold = no;
    button->text->emphasis = no;
}

// Function to handle button click events
void fscl_xcube_button_click_handler(xui* ui, int mouse_x, int mouse_y) {
    for (int i = 0; i < ui->num_buttons; i++) {
        xui_button* button = &(ui->buttons[i]);
        if (mouse_x >= button->position->x && mouse_x < button->position->x + button->dimensions->width &&
            mouse_y >= button->position->y && mouse_y < button->position->y + button->dimensions->height) {
            // Invoke the button's callback function
            if (button->callback != NULL) {
                button->callback();
            }
            break; // Exit loop after handling the first button click
        }
    }
}
