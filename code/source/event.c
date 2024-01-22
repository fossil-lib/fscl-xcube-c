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
#include "fossil/xcube/event.h"
#include "fossil/xcube/checkbox.h"
#include "fossil/xcube/button.h"
#include "fossil/xcube/radiobox.h"

// Function to handle mouse events
void fscl_xcube_handle_mouse_event(xui* tui, int mouse_x, int mouse_y) {
    // Check if the mouse is over any button
    fscl_xcube_button_click_handler(tui, mouse_x, mouse_y);

    // Check if the mouse is over any checkbox
    fscl_xcube_checkbox_state_change_handler(tui, mouse_x, mouse_y);

    // Check if the mouse is over any radiobox
    fscl_xcube_radiobox_state_change_handler(tui, mouse_x, mouse_y);
}

// Function to handle keyboard events
void fscl_xcube_handle_keyboard_event(xui* tui, char key) {
    // Check if a specific textbox has focus (you might need a way to track the focused textbox)
    int focused_textbox_index = 0; // Assuming the first textbox has focus

    if (focused_textbox_index >= 0 && focused_textbox_index < tui->num_textboxes) {
        xui_textbox* focused_textbox = &(tui->textboxes[focused_textbox_index]);

        // Handle key events for the focused textbox
        switch (key) {
            case '\b': // Backspace
                // Remove the last character from the textbox text
                if (strlen(focused_textbox->text) > 0) {
                    focused_textbox->text[strlen(focused_textbox->text) - 1] = '\0';
                }
                break;

            case '\n': // Enter
                // Handle Enter key press if needed
                break;

            default:
                // Append the pressed key to the textbox text
                int new_length = strlen(focused_textbox->text) + 2; // +2 for the new character and null terminator
                focused_textbox->text = realloc(focused_textbox->text, new_length);
                focused_textbox->text[new_length - 2] = key;
                focused_textbox->text[new_length - 1] = '\0';
                break;
        }
    }
}
