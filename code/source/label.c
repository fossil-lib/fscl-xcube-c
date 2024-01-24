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
#include "fossil/xcube/label.h"

extern char* fscl_xcube_strdup(const char* str);

// Function to add a label to the TUI
void fscl_xcube_add_label(xui* ui, int x, int y, const char* text) {
    ui->num_labels++;
    ui->labels = realloc(ui->labels, ui->num_labels * sizeof(xui_label));
    xui_label* label = &(ui->labels[ui->num_labels - 1]);
    label->position->x = x;
    label->position->y = y;

    // Set default values for the text member
    label->text->content = fscl_xcube_strdup(text);
    label->text->color_front = COLOR_BLUE;
    label->text->color_back = COLOR_BLACK;
    label->text->bold = no;
    label->text->emphasis = no;
}

void fscl_xcube_set_label_content(xui* ui, int label_index, const char* new_content) {
    if (ui == NULL || label_index < 0 || label_index >= ui->num_labels) {
        // Handle invalid input or index out of bounds
        return;
    }

    // Update the content of the specified label using strcpy
    strcpy(ui->labels[label_index].text, new_content);
}
