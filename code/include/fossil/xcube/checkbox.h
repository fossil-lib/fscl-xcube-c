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
#ifndef FSCL_CHECKBOX_H
#define FSCL_CHECKBOX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

/**
 * Adds a checkbox to the XCube TUI.
 *
 * @param ui The XCube UI to which the checkbox will be added.
 * @param x The x-coordinate of the checkbox.
 * @param y The y-coordinate of the checkbox.
 * @param label The label text for the checkbox.
 * @param callback The callback function to be executed when the checkbox state changes.
 */
void fscl_xcube_add_checkbox(xui* ui, int x, int y, const char* label, void (*callback)(int));

/**
 * Handles checkbox state changes in the XCube TUI.
 *
 * @param ui The XCube UI that contains the checkbox.
 * @param mouse_x The x-coordinate of the mouse click.
 * @param mouse_y The y-coordinate of the mouse click.
 */
void fscl_xcube_checkbox_state_change_handler(xui* ui, int mouse_x, int mouse_y);

/**
 * Sets the state of a checkbox in the XCube TUI.
 *
 * @param ui The XCube UI that contains the checkbox.
 * @param checkbox_index The index of the checkbox.
 * @param new_state The new state of the checkbox (0 for unchecked, 1 for checked).
 */
void fscl_xcube_set_checkbox_state(xui* ui, int checkbox_index, int new_state);

#ifdef __cplusplus
}
#endif

#endif
