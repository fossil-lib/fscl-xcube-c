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
#include "fossil/xcube/basic.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#define _GNU_SOURCE // for getline function
#include <termios.h>
#include <unistd.h>
#endif

// Global loop variable
xloop loop = XLOOP_ACTIVE;

// Clear Screen Function
void fscl_xcube_console_clear() {
#ifdef _WIN32
    int dummy = system("cls");
#else
    int dummy = system("clear");
#endif
    (void)dummy;  // Avoid unused variable warning
}

// Custom implementation of strdup
char* fscl_xcube_strdup(const char* str) {
    size_t len = strlen(str) + 1;
    char* new_str = (char *)malloc(len);
    if (new_str != NULL) {
        strcpy(new_str, str);
    }
    return new_str;
}

// Function to initialize the TUI
xui* fscl_xcube_create(const char* app_name) {
    xui* tui = (xui*)malloc(sizeof(xui));

    if (tui != NULL) {
        tui->app_name = fscl_xcube_strdup(app_name);
        tui->elements = NULL;
        tui->buttons = NULL;
        tui->labels = NULL;
        tui->textboxes = NULL;
        tui->checkboxes = NULL;
        tui->radioboxes = NULL;
        tui->num_elements = 0;
        tui->num_buttons = 0;
        tui->num_labels = 0;
        tui->num_textboxes = 0;
        tui->num_checkboxes = 0;
        tui->num_radioboxes = 0;
        fscl_xcube_console_clear();
    }

    return tui;
}

// Function to add an element to the TUI
void fscl_xcube_add_element(xui* tui, int x, int y, int width, int height, const char* content, xui_color color) {
    tui->num_elements++;
    tui->elements = realloc(tui->elements, tui->num_elements * sizeof(xui_element));
    xui_element* elem = &(tui->elements[tui->num_elements - 1]);
    elem->x = x;
    elem->y = y;
    elem->width = width;
    elem->height = height;
    elem->content = fscl_xcube_strdup(content);
    elem->color = color;
}

// Function to change the content of an element
void fscl_xcube_set_element_content(xui* tui, int element_index, const char* new_content) {
    if (element_index >= 0 && element_index < tui->num_elements) {
        free(tui->elements[element_index].content);
        tui->elements[element_index].content = fscl_xcube_strdup(new_content);
    }
}

// Function to move an element to a new position
void fscl_xcube_move_element(xui* tui, int element_index, int new_x, int new_y) {
    if (element_index >= 0 && element_index < tui->num_elements) {
        tui->elements[element_index].x = new_x;
        tui->elements[element_index].y = new_y;
    }
}

// Function to resize an element
void fscl_xcube_resize_element(xui* tui, int element_index, int new_width, int new_height) {
    if (element_index >= 0 && element_index < tui->num_elements) {
        tui->elements[element_index].width = new_width;
        tui->elements[element_index].height = new_height;
    }
}

// Function to change the color of an element
void fscl_xcube_set_element_color(xui* tui, int element_index, xui_color new_color) {
    if (element_index >= 0 && element_index < tui->num_elements) {
        tui->elements[element_index].color = new_color;
    }
}

// Function to remove an element
void fscl_xcube_remove_element(xui* tui, int element_index) {
    if (element_index >= 0 && element_index < tui->num_elements) {
        free(tui->elements[element_index].content);
        // Move the last element to the removed element's position
        tui->elements[element_index] = tui->elements[tui->num_elements - 1];
        // Decrease the number of elements
        tui->num_elements--;
        // Reallocate memory for elements
        tui->elements = realloc(tui->elements, tui->num_elements * sizeof(xui_element));
    }
}

// Function to display the TUI
void fscl_xcube_display(xui* tui) {
    // Display application name
    printf("%s\n", tui->app_name);

    // Display each element
    for (int i = 0; i < tui->num_elements; i++) {
        xui_element* elem = &(tui->elements[i]);
        // Set color based on the color attribute
        if (elem->color >= 0 && elem->color < COLOR_TOTAL) {
            printf("\033[38;5;%dm", elem->color); // Set color
        }
        // Position cursor and print content
        printf("\033[%d;%dH%s", elem->y, elem->x, elem->content);
        // Reset color
        printf("\033[0m");
    }

    // Display each button
    for (int i = 0; i < tui->num_buttons; i++) {
        xui_button* button = &(tui->buttons[i]);
        printf("\033[%d;%dH[%s]", button->y, button->x, button->label);
    }

    // Display each label
    for (int i = 0; i < tui->num_labels; i++) {
        xui_label* label = &(tui->labels[i]);
        printf("\033[%d;%dH%s", label->y, label->x, label->text);
    }

    // Display each textbox
    for (int i = 0; i < tui->num_textboxes; i++) {
        xui_textbox* textbox = &(tui->textboxes[i]);
        printf("\033[%d;%dH%s", textbox->y, textbox->x, textbox->text);
    }

    // Display each checkbox
    for (int i = 0; i < tui->num_checkboxes; i++) {
        xui_checkbox* checkbox = &(tui->checkboxes[i]);
        printf("\033[%d;%dH[%c] %s", checkbox->y, checkbox->x, checkbox->checked ? 'X' : ' ', checkbox->label);
    }

    // Display each radiobox
    for (int i = 0; i < tui->num_radioboxes; i++) {
        xui_radiobox* radiobox = &(tui->radioboxes[i]);
        printf("\033[%d;%dH(%c) %s", radiobox->y, radiobox->x, radiobox->selected ? 'O' : ' ', radiobox->label);
    }

    fflush(stdout);
}

// Function to erase the TUI
void fscl_xcube_erase(xui* tui) {
    // Clear the screen
    printf("\033[2J");
    fflush(stdout);
}

// Function to clean up and exit
void fscl_xcube_exit(xui* tui) {
    free(tui->app_name); // Free application name memory

    for (int i = 0; i < tui->num_elements; i++) {
        free(tui->elements[i].content);
    }
    free(tui->elements); // Free UI elements memory

    for (int i = 0; i < tui->num_buttons; i++) {
        free(tui->buttons[i].label);
    }
    free(tui->buttons); // Free buttons memory

    for (int i = 0; i < tui->num_labels; i++) {
        free(tui->labels[i].text);
    }
    free(tui->labels); // Free labels memory

    for (int i = 0; i < tui->num_textboxes; i++) {
        free(tui->textboxes[i].text);
    }
    free(tui->textboxes); // Free textboxes memory

    for (int i = 0; i < tui->num_checkboxes; i++) {
        free(tui->checkboxes[i].label);
    }
    free(tui->checkboxes); // Free checkboxes memory

    for (int i = 0; i < tui->num_radioboxes; i++) {
        free(tui->radioboxes[i].label);
    }
    free(tui->radioboxes); // Free radioboxes memory
    free(tui);
    fscl_xcube_console_clear();
}
