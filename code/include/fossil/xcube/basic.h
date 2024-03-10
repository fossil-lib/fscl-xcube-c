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

// Enum representing the loop condition
typedef enum {
    XLOOP_ACTIVE = 1,
    XLOOP_INACTIVE = 0
} xloop;

// Global loop variable
extern xloop loop;

// Define color names
typedef enum {
    COLOR_DEFAULT,
    COLOR_BLACK,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_PINK,
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
    COLOR_BLUE,
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

typedef enum {
    no,
    yes,
} xbool;

typedef struct {
    char *content;
    int color_front;
    int color_back;
    int bold;
    int emphasis;
} xtext;

// Position structure for the Xcube object
typedef struct {
    int x;
    int y;
} xposition;

// Dimensions structure for the Xcube object
typedef struct {
    int width;
    int height;
} xdimensions;

// Define xui_element structure to represent UI elements
typedef struct {
    xposition* position; // Position
    xdimensions* dimensions; // Dimensions
    xtext* text; // Contents containing a message
    xui_color color; // Color attribute
} xui_element;

// Define xui_button structure to represent buttons
typedef struct {
    xposition* position; // Position
    xdimensions* dimensions; // Dimensions
    xtext* text; // Contents containing a message
    void (*callback)(); // Callback function when button is clicked
} xui_button;

// Define xui_label structure to represent labels
typedef struct {
    xposition* position; // Position
    xtext* text; // Contents containing a message
} xui_label;

// Define xui_textbox structure to represent textboxes
typedef struct {
    xposition* position; // Position
    xdimensions* dimensions; // Dimensions
    xtext* text; // Contents containing a message
} xui_textbox;

// Define xui_checkbox structure to represent checkboxes
typedef struct {
    xposition* position; // Position
    xtext* text; // Contents containing a message
    xbool selected; // General state (0 for unselected, 1 for selected)
    void (*callback)(int); // Callback function when button is clicked
} xui_checkbox;

// Define xui_radiobox structure to represent radioboxes
typedef struct {
    xposition* position; // Position
    xtext* text; // Contents containing a message
    xbool selected; // General state (0 for unselected, 1 for selected)
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
    xbool visible; // Visible state of the element
} xui;

// =================================================================
// TUI API functions for the XCube library
// =================================================================

/**
 * Creates an XCube user interface.
 *
 * @param app_name The name of the application.
 * @return A pointer to the created XCube UI.
 */
xui* fscl_xcube_create(const char* app_name);

/**
 * Displays the XCube user interface.
 *
 * @param ui The XCube UI to display.
 */
void fscl_xcube_display(xui* ui);

/**
 * Erases the XCube user interface.
 *
 * @param ui The XCube UI to erase.
 */
void fscl_xcube_erase(xui* ui);

/**
 * Exits the XCube user interface.
 *
 * @param ui The XCube UI to exit.
 */
void fscl_xcube_exit(xui* ui);


#ifdef __cplusplus
}
#endif

#endif
