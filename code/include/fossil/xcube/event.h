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
#ifndef FSCL_EVENT_H
#define FSCL_EVENT_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

/**
 * Handles mouse events in the XCube TUI.
 *
 * @param ui The XCube UI that will handle the mouse event.
 * @param mouse_x The x-coordinate of the mouse event.
 * @param mouse_y The y-coordinate of the mouse event.
 */
void fscl_xcube_handle_mouse_event(xui* ui, int mouse_x, int mouse_y);

/**
 * Handles keyboard events in the XCube TUI.
 *
 * @param ui The XCube UI that will handle the keyboard event.
 * @param key The key pressed on the keyboard.
 */
void fscl_xcube_handle_keyboard_event(xui* ui, char key);

#ifdef __cplusplus
}
#endif

#endif
