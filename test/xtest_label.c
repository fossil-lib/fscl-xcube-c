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

#include <fossil/xcube/label.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for adding a label to the TUI
XTEST_CASE(test_add_label) {
    xui* testTui = fscl_xcube_create("TestApp");

    // Add a label to the TUI
    fscl_xcube_add_label(testTui, 5, 5, "Test Label");

    // Add assertions to check if the label is added successfully
    TEST_ASSERT_EQUAL_CSTRING("Test Label", testTui->labels[0].content);

    fscl_xcube_exit(testTui);
}

// Test for updating label content
XTEST_CASE(test_update_label) {
    xui* testTui = fscl_xcube_create("TestApp");

    // Add a label to the TUI
    fscl_xcube_add_label(testTui, 5, 5, "Test Label");

    // Update the label content
    fscl_xcube_set_label_content(testTui, 0, "Updated Label");

    // Add assertions to check if the label content is updated
    TEST_ASSERT_EQUAL_CSTRING("Updated Label", testTui->labels[0].content);

    fscl_xcube_exit(testTui);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_label_group) {
    XTEST_RUN_UNIT(test_add_label);
    XTEST_RUN_UNIT(test_update_label);
} // end of fixture
