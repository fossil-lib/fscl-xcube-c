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
#ifndef FSCL_RADIOBOX_H
#define FSCL_RADIOBOX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

/**
 * Adds a radiobox to the XCube TUI.
 *
 * @param ui The XCube UI to which the radiobox will be added.
 * @param x The x-coordinate of the radiobox.
 * @param y The y-coordinate of the radiobox.
 * @param label The label text for the radiobox.
 * @param callback The callback function to be triggered on radiobox state changes.
 */
void fscl_xcube_add_radiobox(xui* ui, int x, int y, const char* label, void (*callback)(int));

/**
 * Handles radiobox state changes in the XCube TUI.
 *
 * @param ui The XCube UI containing the radiobox.
 * @param mouse_x The x-coordinate of the mouse event.
 * @param mouse_y The y-coordinate of the mouse event.
 */
void fscl_xcube_radiobox_state_change_handler(xui* ui, int mouse_x, int mouse_y);

/**
 * Sets the state of a radiobox in the XCube TUI.
 *
 * @param ui The XCube UI containing the radiobox.
 * @param radiobox_index The index of the radiobox to be updated.
 * @param new_state The new state for the radiobox.
 */
void fscl_xcube_set_radiobox_state(xui* ui, int radiobox_index, int new_state);

#ifdef __cplusplus
}
#endif

#endif
