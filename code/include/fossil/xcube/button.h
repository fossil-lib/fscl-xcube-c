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
#ifndef FSCL_BUTTON_H
#define FSCL_BUTTON_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

/**
 * Adds a button to the XCube TUI.
 *
 * @param ui The XCube UI to which the button will be added.
 * @param x The x-coordinate of the button.
 * @param y The y-coordinate of the button.
 * @param width The width of the button.
 * @param height The height of the button.
 * @param label The label text for the button.
 * @param callback The callback function to be executed when the button is clicked.
 */
void fscl_xcube_add_button(xui* ui, int x, int y, int width, int height, const char* label, void (*callback)());

/**
 * Handles button click events in the XCube TUI.
 *
 * @param ui The XCube UI that contains the button.
 * @param mouse_x The x-coordinate of the mouse click.
 * @param mouse_y The y-coordinate of the mouse click.
 */
void fscl_xcube_button_click_handler(xui* ui, int mouse_x, int mouse_y);

#ifdef __cplusplus
}
#endif

#endif
