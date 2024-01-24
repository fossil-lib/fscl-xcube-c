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

#include <fossil/xcube/checkbox.h> // library under test

void my_on_check_callback(int arg) {
    // empty
}

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for adding a checkbox to the TUI
XTEST_CASE(test_add_checkbox) {
    xui* testtui = fscl_xcube_create("TestApp");

    // Add a checkbox to the TUI
    fscl_xcube_add_checkbox(testtui, 5, 5, "Checkbox", my_on_check_callback);

    // Add assertions to check if the checkbox is added successfully
    TEST_ASSERT_EQUAL_CSTRING("Checkbox", testui->checkboxes[0].text->content);

    fscl_xcube_exit(testtui);
}

// Test for toggling checkbox state
XTEST_CASE(test_toggle_checkbox) {
    xui* testtui = fscl_xcube_create("TestApp");

    // Add a checkbox to the TUI
    fscl_xcube_add_checkbox(testtui, 5, 5, "Checkbox", my_on_check_callback);

    // Toggle the checkbox state
    fscl_xcube_checkbox_state_change_handler(testtui, 7, 6);

    // Add assertions to check if the checkbox is added successfully
    TEST_ASSERT_EQUAL_CSTRING("Checkbox", testui->checkboxes[0].text->content);

    fscl_xcube_exit(testtui);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_checkbox_group) {
    XTEST_RUN_UNIT(test_add_checkbox);
    XTEST_RUN_UNIT(test_toggle_checkbox);
} // end of fixture
