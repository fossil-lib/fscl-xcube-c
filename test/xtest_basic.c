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

#include <fossil/xcube/basic.h> // library under test
#include <fossil/xcube/label.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for creating a TUI
XTEST_CASE(test_create_tui) {
    xui* testTui = fscl_xcube_create("TestApp");
    TEST_ASSERT_NOT_CNULLPTR(testTui);
    fscl_xcube_exit(testTui);
}

// Test for adding an element to the TUI
XTEST_CASE(test_add_element) {
    // Create a TUI with the application name
    xui* ui = fscl_xcube_create("Hello World App");

    // Add a label to the TUI
    fscl_xcube_add_label(ui, 5, 5, "Hello, World!");

    // Clean up resources
    fscl_xcube_exit(ui);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_basic_group) {
    XTEST_RUN_UNIT(test_create_tui);
    XTEST_RUN_UNIT(test_add_element);
}
