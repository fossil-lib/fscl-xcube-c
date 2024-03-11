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
#ifndef FSCL_LABEL_H
#define FSCL_LABEL_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <fossil/xcube/basic.h> // all basic cube code

/**
 * Adds a label to the XCube TUI.
 *
 * @param ui The XCube UI to which the label will be added.
 * @param x The x-coordinate of the label.
 * @param y The y-coordinate of the label.
 * @param text The text content of the label.
 */
void fscl_xcube_add_label(xui* ui, int x, int y, const char* text);

/**
 * Updates the content of the specified label in the XCube TUI.
 *
 * @param ui The XCube UI containing the label to be updated.
 * @param label_index The index of the label to be updated.
 * @param new_content The new content for the label.
 */
void fscl_xcube_set_label_content(xui* ui, int label_index, const char* new_content);

#ifdef __cplusplus
}
#endif

#endif
