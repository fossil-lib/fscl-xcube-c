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
#ifndef FSCL_TEXTBOX_H
#define FSCL_TEXTBOX_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

/**
 * Adds a textbox to the XCube TUI.
 *
 * @param ui The XCube UI to which the textbox will be added.
 * @param x The x-coordinate of the textbox.
 * @param y The y-coordinate of the textbox.
 * @param width The width of the textbox.
 * @param height The height of the textbox.
 * @param text The initial text content of the textbox.
 */
void fscl_xcube_add_textbox(xui* ui, int x, int y, int width, int height, const char* text);

/**
 * Sets the text content of a textbox in the XCube TUI.
 *
 * @param ui The XCube UI containing the textbox.
 * @param textbox_index The index of the textbox to be updated.
 * @param new_text The new text content for the textbox.
 */
void fscl_xcube_set_textbox_content(xui* ui, int textbox_index, const char* new_text);

#ifdef __cplusplus
}
#endif

#endif
