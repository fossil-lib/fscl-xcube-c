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
#include "fossil/xcube/textbox.h"

extern char* fscl_xcube_strdup(const char* str);

// Function to create a textbox and add it to the TUI
void fscl_xcube_add_textbox(xui* ui, int x, int y, int width, int height, const char* text) {
    ui->num_textboxes++;
    ui->textboxes = realloc(ui->textboxes, ui->num_textboxes * sizeof(xui_textbox));
    xui_textbox* textbox = &(ui->textboxes[ui->num_textboxes - 1]);
    textbox->position->x = x;
    textbox->position->y = y;
    textbox->dimensions->width = width;
    textbox->dimensions->height = height;

    // Set default values for the text member
    textbox->text->content = fscl_xcube_strdup(text);
    textbox->text->color_front = COLOR_BLUE;
    textbox->text->color_back = COLOR_BLACK;
    textbox->text->bold = no;
    textbox->text->emphasis = no;
}

// Function to set the text content of a textbox
void fscl_xcube_set_textbox_content(xui* ui, int textbox_index, const char* new_text) {
    if (textbox_index >= 0 && textbox_index < ui->num_textboxes) {
        free(ui->textboxes[textbox_index].text);
        ui->textboxes[textbox_index].text = fscl_xcube_strdup(new_text);
    }
}
