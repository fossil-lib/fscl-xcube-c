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
#ifndef FSCL_PANEL_H
#define FSCL_PANEL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <basic.h> // all basic cube code

// Enum representing the type of window
typedef enum {
    XPANEL_TYPE_DEFAULT,  // Default panel type
    XPANEL_TYPE_CLASSIC,  // Classic panel type
    XPANEL_TYPE_DIALOG    // Dialog panel type
    // Add more panel types as needed
} xpanel_type;

// Structure representing a panel
typedef struct {
    xpanel_type type; // Type of the panel
    xui* tui;         // TUI associated with the panel
} xpanel;

// Function to create a new panel of a specific type
xpanel* fscl_xcube_create_panel(xpanel_type type);

// Function to switch focus to a specific panel
void fscl_xcube_switch_focus_to_panel(xui* tui, xpanel* panel);

// Function to add an element to the current focused panel
void fscl_xcube_add_element_to_focused_panel(xui* tui, const char* content, int x, int y, int width, int height);

#ifdef __cplusplus
}
#endif

#endif
