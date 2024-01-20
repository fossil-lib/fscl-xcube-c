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
#include "fossil/xcube/panel.h"

// Function to create a new panel of a specific type
xpanel* fscl_xcube_create_panel(xpanel_type type) {
    xpanel* panel = malloc(sizeof(xpanel));
    panel->type = type;
    panel->tui = fscl_xcube_create_tui(); // Create a new TUI for each panel

    // Customize the panel based on its type
    switch (type) {
        case XPANEL_TYPE_CLASSIC:
            // Add elements or customize as needed for the classic panel
            fscl_xcube_add_element(panel->tui, "Classic Panel", 5, 5, 20, 3);
            break;

        case XPANEL_TYPE_DIALOG:
            // Add elements or customize as needed for the dialog panel
            fscl_xcube_add_element(panel->tui, "Dialog Panel", 5, 5, 20, 3);
            break;

        // Add cases for other panel types as needed

        default:
            break;
    }

    // Initialize other panel-specific data as needed
    return panel;
}

// Function to switch focus to a specific panel
void fscl_xcube_switch_focus_to_panel(xui* tui, xpanel* panel) {
    // Switch focus to the TUI associated with the panel
    if (tui != NULL && panel != NULL && panel->tui != NULL) {
        // Hide the current TUI (if any)
        fscl_xcube_hide_tui(tui);
        // Show the TUI associated with the panel
        fscl_xcube_show_tui(panel->tui);
    }
}

// Function to add an element to the current focused panel
void fscl_xcube_add_element_to_focused_panel(xui* tui, const char* content, int x, int y, int width, int height) {
    if (tui != NULL) {
        // Add an element to the current focused panel
        fscl_xcube_add_element(tui, content, x, y, width, height);
    }
}
