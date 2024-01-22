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
#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

#include <fossil/xcube/button.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for adding a button to the TUI
XTEST_CASE(test_add_button) {
    xui* testTui = fscl_xcube_create("TestApp");

    // Add a button to the TUI
    fscl_xcube_add_button(testTui, 5, 5, 10, 3, "Click Me", NULL);

    // Add assertions to check if the button is added successfully
    TEST_ASSERT_EQUAL_CSTRING("Click Me", testTui->buttons[0].label);

    fscl_xcube_exit(testTui);
}

// Test for clicking a button
XTEST_CASE(test_button_click) {
    xui* testTui = fscl_xcube_create("TestApp");

    // Add a button to the TUI
    int clickCount = 0;
    fscl_xcube_add_button(testTui, 5, 5, 10, 3, "Click Me", &clickCount);

    // Simulate a button click
    fscl_xcube_button_click_handler(testTui, 7, 6);

    // Add assertions to check if the click handler is called
    TEST_ASSERT_EQUAL(1, clickCount);

    fscl_xcube_exit(testTui);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_button_group) {
    XTEST_RUN_UNIT(test_add_button);
    XTEST_RUN_UNIT(test_button_click);
}
