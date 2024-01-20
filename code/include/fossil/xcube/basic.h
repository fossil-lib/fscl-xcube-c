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
#ifndef FSCL_BASIC_H
#define FSCL_BASIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom implementation of strdup
inline char* fscl_xcube_strdup(const char* str) {
    size_t len = strlen(str) + 1;
    char* new_str = (char *)malloc(len);
    if (new_str != NULL) {
        strcpy(new_str, str);
    }
    return new_str;
}

// Enum representing the loop condition
typedef enum {
    XLOOP_ACTIVE = 1,
    XLOOP_INACTIVE = 0
} xloop;

// Global loop variable
xloop loop = XLOOP_ACTIVE;

// Define color names
typedef enum {
    COLOR_DEFAULT,
    COLOR_BLACK,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE,
    COLOR_GRAY,
    COLOR_LIGHT_RED,
    COLOR_LIGHT_GREEN,
    COLOR_LIGHT_YELLOW,
    COLOR_LIGHT_BLUE,
    COLOR_LIGHT_MAGENTA,
    COLOR_LIGHT_CYAN,
    COLOR_BRIGHT_WHITE,
    COLOR_ORANGE,
    COLOR_PURPLE,
    COLOR_BROWN,
    COLOR_PINK,
    COLOR_OLIVE,
    COLOR_NAVY,
    COLOR_TEAL,
    COLOR_MAROON,
    COLOR_SILVER,
    COLOR_GOLD,
    COLOR_INDIGO,
    COLOR_DARK_GREEN,
    COLOR_SKY_BLUE,
    COLOR_PALE_GREEN,
    COLOR_TOTAL // Total number of colors
} xui_color;

// Define xui_element structure to represent UI elements
typedef struct {
    int x, y; // Position
    int width, height; // Dimensions
    char* content; // Content
    xui_color color; // Color attribute
} xui_element;

// Define xui_button structure to represent buttons
typedef struct {
    int x, y; // Position
    int width, height; // Dimensions
    char* label; // Button label
    void (*callback)(); // Callback function when button is clicked
} xui_button;

// Define xui_label structure to represent labels
typedef struct {
    int x, y; // Position
    char* text; // Label text
} xui_label;

// Define xui_textbox structure to represent textboxes
typedef struct {
    int x, y; // Position
    int width, height; // Dimensions
    char* text; // Text content
} xui_textbox;

// Define xui_checkbox structure to represent checkboxes
typedef struct {
    int x, y; // Position
    char* label; // Checkbox label
    int checked; // Checkbox state (0 for unchecked, 1 for checked)
    void (*callback)(int); // Callback function when button is clicked
} xui_checkbox;

// Define xui_radiobox structure to represent radioboxes
typedef struct {
    int x, y; // Position
    char* label; // Radiobox label
    int selected; // Radiobox state (0 for unselected, 1 for selected)
    void (*callback)(int); // Callback function when button is clicked
} xui_radiobox;

// Define xui structure to represent the TUI
typedef struct {
    char* app_name; // Application name
    xui_element* elements; // Array of UI elements
    xui_button* buttons; // Array of buttons
    xui_label* labels; // Array of labels
    xui_textbox* textboxes; // Array of textboxes
    xui_checkbox* checkboxes; // Array of checkboxes
    xui_radiobox* radioboxes; // Array of radioboxes
    int num_elements; // Number of UI elements
    int num_buttons; // Number of buttons
    int num_labels; // Number of labels
    int num_textboxes; // Number of textboxes
    int num_checkboxes; // Number of checkboxes
    int num_radioboxes; // Number of radioboxes
} xui;

// =================================================================
// TUI API functions for the XCube library
// =================================================================
xui fscl_xcube_create(const char* app_name);
void fscl_xcube_add_element(xui* tui, int x, int y, int width, int height, const char* content, xui_color color);
void fscl_xcube_set_element_content(xui* tui, int element_index, const char* new_content);
void fscl_xcube_move_element(xui* tui, int element_index, int new_x, int new_y);
void fscl_xcube_resize_element(xui* tui, int element_index, int new_width, int new_height);
void fscl_xcube_set_element_color(xui* tui, int element_index, xui_color new_color);
void fscl_xcube_remove_element(xui* tui, int element_index);
void fscl_xcube_display(xui* tui);
void fscl_xcube_erase(xui* tui);
void fscl_xcube_exit(xui* tui);

#ifdef __cplusplus
}
#endif

#endif
