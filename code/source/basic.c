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
    xui* ui = (xui*)malloc(sizeof(xui));

    if (ui != NULL) {
        ui->app_name = fscl_xcube_strdup(app_name);
        ui->elements = NULL;
        ui->buttons = NULL;
        ui->labels = NULL;
        ui->textboxes = NULL;
        ui->checkboxes = NULL;
        ui->radioboxes = NULL;
        ui->num_elements = 0;
        ui->num_buttons = 0;
        ui->num_labels = 0;
        ui->num_textboxes = 0;
        ui->num_checkboxes = 0;
        ui->num_radioboxes = 0;
        ui->visible = yes;
        fscl_xcube_console_clear();
    }

    return ui;
}

// Function to display the TUI
void fscl_xcube_display(xui* ui) {
    // Display application name
    printf("%s\n", ui->app_name);

    // Display each element
    for (int i = 0; i < ui->num_elements; i++) {
        xui_element* elem = &(ui->elements[i]);
        // Set color based on the color attribute
        if (elem->color >= 0 && elem->color < COLOR_TOTAL) {
            printf("\033[38;5;%dm", elem->color); // Set color
        }
        // Position cursor and print content
        printf("\033[%d;%dH%s", elem->position->y, elem->position->x, elem->text->content);
        // Reset color
        printf("\033[0m");
    }

    // Display each button
    for (int i = 0; i < ui->num_buttons; i++) {
        xui_button* button = &(ui->buttons[i]);
        printf("\033[%d;%dH[%s]", button->position->y, button->position->x, button->text->content);
    }

    // Display each label with styled text
    for (int i = 0; i < ui->num_labels; i++) {
        xui_label* label = &(ui->labels[i]);
        printf("\033[%d;%dH", label->position->y, label->position->x);
        for (int j = 0; j < label->text; j++) {
            xtext* text_content = &(label->text->content[j]);
            // Set text color and style based on attributes
            printf("\033[38;5;%dm", text_content->color_front);
            if (text_content->bold) {
                printf("\033[1m"); // Set bold
            }
            if (text_content->emphasis) {
                printf("\033[3m"); // Set italic/emphasis
            }
            // Print text content
            printf("%s", text_content->content);
            // Reset text style
            printf("\033[0m");
        }
        printf("\n");
    }

    // Display each textbox
    for (int i = 0; i < ui->num_textboxes; i++) {
        xui_textbox* textbox = &(ui->textboxes[i]);
        printf("\033[%d;%dH%s", textbox->position->y, textbox->position->x, textbox->text->content);
    }

    // Display each checkbox
    for (int i = 0; i < ui->num_checkboxes; i++) {
        xui_checkbox* checkbox = &(ui->checkboxes[i]);
        printf("\033[%d;%dH[%c] %s", checkbox->position->y, checkbox->position->x, checkbox->selected ? 'X' : ' ', checkbox->text->content);
    }

    // Display each radiobox
    for (int i = 0; i < ui->num_radioboxes; i++) {
        xui_radiobox* radiobox = &(ui->radioboxes[i]);
        printf("\033[%d;%dH(%c) %s", radiobox->position->y, radiobox->position->x, radiobox->selected ? 'O' : ' ', radiobox->text->content);
    }

    fflush(stdout);
}

// Function to erase the TUI
void fscl_xcube_erase(xui* ui) {
    // Clear the screen
    printf("\033[2J");
    fflush(stdout);
}

// Function to clean up and exit
void fscl_xcube_exit(xui* ui) {
    free(ui->app_name); // Free application name memory

    for (int i = 0; i < ui->num_elements; i++) {
        free(ui->elements[i].text->content);
    }
    free(ui->elements); // Free UI elements memory

    for (int i = 0; i < ui->num_buttons; i++) {
        free(ui->buttons[i].text->content);
    }
    free(ui->buttons); // Free buttons memory

    for (int i = 0; i < ui->num_labels; i++) {
        free(ui->labels[i].text);
    }
    free(ui->labels); // Free labels memory

    for (int i = 0; i < ui->num_textboxes; i++) {
        free(ui->textboxes[i].text);
    }
    free(ui->textboxes); // Free textboxes memory

    for (int i = 0; i < ui->num_checkboxes; i++) {
        free(ui->checkboxes[i].text->content);
    }
    free(ui->checkboxes); // Free checkboxes memory

    for (int i = 0; i < ui->num_radioboxes; i++) {
        free(ui->radioboxes[i].text->content);
    }
    free(ui->radioboxes); // Free radioboxes memory
    free(ui);
    fscl_xcube_console_clear();
}
