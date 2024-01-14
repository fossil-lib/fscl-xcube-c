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
#ifndef FSCL_BASIC_H
#define FSCL_BASIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif

#ifdef __APPLE__
#include <CoreGraphics/CoreGraphics.h>
#endif

enum {
    XTEXT_MAX_SIZE = 100,
    XLABEL_MAX_SIZE = 50,
    XCUBE_LOOP = 1
};

typedef enum {
    XCOLOR_RED = 0xFF0000,
    XCOLOR_GREEN = 0x00FF00,
    XCOLOR_BLUE = 0x0000FF,
    XCOLOR_YELLOW = 0xFFFF00,
    XCOLOR_CYAN = 0x00FFFF,
    XCOLOR_MAGENTA = 0xFF00FF,
    XCOLOR_BLACK = 0x000000,
    XCOLOR_WHITE = 0xFFFFFF,
    XCOLOR_ORANGE = 0xFFA500,
    XCOLOR_PURPLE = 0x800080,
    XCOLOR_PINK = 0xFFC0CB,
    XCOLOR_BROWN = 0xA52A2A,
    XCOLOR_LIME = 0x00FF00,
    XCOLOR_GRAY = 0x808080,
    XCOLOR_GOLD = 0xFFD700,
    XCOLOR_TEAL = 0x008080,
    XCOLOR_SILVER = 0xC0C0C0,
    XCOLOR_INDIGO = 0x4B0082,
    XCOLOR_MAROON = 0x800000
} xcolor;

typedef struct {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    xcolor color;
} xpoint;

typedef struct {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    char label[XLABEL_MAX_SIZE]; // Adjust the size as needed
    xcolor color;
} xbutton;

typedef struct {
    int32_t x;
    int32_t y;
    char text[XTEXT_MAX_SIZE]; // Adjust the size as needed
    xcolor color;
} xlabel;

typedef struct {
    int32_t x;
    int32_t y;
    int32_t width;
    int32_t height;
    char text[XTEXT_MAX_SIZE]; // Adjust the size as needed
    xcolor color;
} xinput;

typedef struct {
    int32_t width;
    int32_t height;
    char name[100];
#ifdef _WIN32
    HDC hdc;
    HBITMAP hBitmap;
    HWND hwnd;
#elif __APPLE__
    CGColorSpaceRef colorSpace;
    CGContextRef context;
    CGWindowID windowID;
    NSWindow *nsWindow;
#else
    Display* display;
    Window window;
    GC gc;
#endif
} xwindow;

typedef struct {
    xwindow* windows;
    int32_t num_windows;
    int32_t active_window; // Index of the active window
} manager;

void fscl_window_create(xwindow* window, int32_t width, int32_t height, const char* name);
void fscl_window_set_pixel(xwindow* window, xpoint point, xcolor color);
void fscl_window_clear(xwindow* window);
void fscl_window_erase(xwindow* window);
void fscl_manager_create(xmanager* manager, int32_t num_windows, int32_t width, int32_t height);
void fscl_manager_draw_active(xmanager* manager, xbutton button);
void fscl_manager_switch_window(xmanager* manager, int32_t window_index);
void fscl_manager_erase(xmanager* manager);

#ifdef __cplusplus
}
#endif

#endif
