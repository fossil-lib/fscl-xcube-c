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

#include <fossil/xcube/radiobox.h> // library under test

void my_callback(int arg) {
    // empty
}

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for adding a radio box to the TUI
XTEST_CASE(test_add_radiobox) {
    xui* testTui = fscl_xcube_create("TestApp");

    // Add a radio box to the TUI
    int selectedOption = 0;
    fscl_xcube_add_radiobox(testTui, 5, 5, "Option 1", my_callback);

    // Add assertions to check if the radio box is added successfully
    TEST_ASSERT_EQUAL_CSTRING("Option 1", testTui->radioboxes[0].label);

    fscl_xcube_exit(testTui);
}

// Test for selecting a radio box option
XTEST_CASE(test_select_radiobox_option) {
    xui* testTui = fscl_xcube_create("TestApp");

    // Add a radio box to the TUI
    int selectedOption = 0;
    fscl_xcube_add_radiobox(testTui, 5, 5, "Option 1", my_callback);

    // Select a radio box option
    fscl_xcube_radiobox_option_change_handler(testTui, 7, 6);

    // Add assertions to check if the selected option is updated
    TEST_ASSERT_EQUAL(1, selectedOption);

    fscl_xcube_exit(testTui);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_radiobox_group) {
    XTEST_RUN_UNIT(test_add_radiobox);
    XTEST_RUN_UNIT(test_select_radiobox_option);
} // end of fixture
