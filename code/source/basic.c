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
#include "fossil/basic.h"

void fscl_window_create(xwindow* window, int32_t width, int32_t height, const char* name) {
#ifdef _WIN32
    window->hdc = GetDC(GetConsoleWindow());
    window->hBitmap = CreateCompatibleBitmap(window->hdc, width, height);
    SelectObject(window->hdc, window->hBitmap);
    window->hwnd = GetConsoleWindow();
#elif __APPLE__
    window->colorSpace = CGColorSpaceCreateDeviceRGB();
    window->context = CGBitmapContextCreate(NULL, width, height, 8, 0, window->colorSpace,
                                            kCGImageAlphaPremultipliedLast);
    window->nsWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, width, height)
                                                   styleMask:(NSWindowStyleMaskTitled |
                                                              NSWindowStyleMaskResizable |
                                                              NSWindowStyleMaskClosable)
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];
    [window->nsWindow setTitle:[NSString stringWithUTF8String:name]];
    [window->nsWindow makeKeyAndOrderFront:nil];
    window->windowID = [window->nsWindow windowNumber];
#else
    window->display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(window->display);
    window->window = XCreateSimpleWindow(window->display, root, 0, 0, width, height, 1, 0, 0);
    XSelectInput(window->display, window->window, StructureNotifyMask | ExposureMask);
    XMapWindow(window->display, window->window);
    window->gc = XCreateGC(window->display, window->window, 0, NULL);
    XStoreName(window->display, window->window, name);
#endif
}

void fscl_window_set_pixel(xwindow* window, xpoint point, xcolor color) {
#ifdef _WIN32
    SetPixel(window->hdc, point.x, point.y, color);
#elif __APPLE__
    CGContextSetRGBFillColor(window->context, ((color >> 16) & 0xFF) / 255.0,
                             ((color >> 8) & 0xFF) / 255.0, (color & 0xFF) / 255.0, 1.0);
    CGContextFillRect(window->context, CGRectMake(point.x, point.y, 1, 1));
    CGImageRef image = CGBitmapContextCreateImage(window->context);
    CGWindowID windowID = window->windowID;
    CGWindowLevel windowLevel = kCGNormalWindowLevel;
    CGContextRef mainContext = [[NSGraphicsContext currentContext] graphicsPort];
    CGContextDrawImage(mainContext, CGRectMake(0, 0, window->width, window->height), image);
    CGImageRelease(image);
#else
    XSetForeground(window->display, window->gc, color);
    XDrawPoint(window->display, window->window, window->gc, point.x, point.y);
    XFlush(window->display);
#endif
}

void fscl_window_clear(xwindow* window) {
#ifdef _WIN32
    BitBlt(window->hdc, 0, 0, window->width, window->height, NULL, 0, 0, WHITENESS);
#elif __APPLE__
    CGContextClearRect(window->context, CGRectMake(0, 0, window->width, window->height));
#else
    XClearWindow(window->display, window->window);
#endif
}

void fscl_window_erase(xwindow* window) {
#ifdef _WIN32
    DeleteObject(window->hBitmap);
    ReleaseDC(window->hwnd, window->hdc);
#elif __APPLE__
    CGContextRelease(window->context);
#else
    XFreeGC(window->display, window->gc);
    XDestroyWindow(window->display, window->window);
    XCloseDisplay(window->display);
#endif
}

void fscl_manager_create(xmanager* manager, int32_t num_windows, int32_t width, int32_t height) {
    manager->num_windows = num_windows;
    manager->windows = (xwindow*)malloc(num_windows * sizeof(xwindow));
    manager->active_window = 0;

    for (int32_t i = 0; i < num_windows; ++i) {
        char window_name[100];
        sprintf(window_name, "Window %d", i + 1);
        fscl_window_create(&manager->windows[i], width, height, window_name);
    }
}

void fscl_manager_draw_active(xmanager* manager, xbutton button) {
    fscl_window_clear(&manager->windows[manager->active_window]);
    fscl_window_set_pixel(&manager->windows[manager->active_window], (xpoint){button.x, button.y}, button.color);
}

void fscl_manager_switch_window(xmanager* manager, int32_t window_index) {
    if (window_index >= 0 && window_index < manager->num_windows) {
        manager->active_window = window_index;
    }
}

void fscl_manager_erase(xmanager* manager) {
    for (int32_t i = 0; i < manager->num_windows; ++i) {
        fscl_window_erase(&manager->windows[i]);
    }
    free(manager->windows);
}
