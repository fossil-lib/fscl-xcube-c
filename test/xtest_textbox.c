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

#include <fossil/xcube/textbox.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for adding a textbox to the TUI
XTEST_CASE(test_add_textbox) {
    xui* testtui = fscl_xcube_create("TestApp");

    // Add a textbox to the TUI
    char textBuffer[100]; // Adjust the size based on your needs
    fscl_xcube_add_textbox(testtui, 5, 5, 20, 5, textBuffer);

    // Add assertions to check if the textbox is added successfully
    TEST_ASSERT_EQUAL_CSTRING("", testtui->textboxes[0].text->content);

    fscl_xcube_exit(testtui);
}

// Test for updating textbox content
XTEST_CASE(test_update_textbox) {
    xui* testtui = fscl_xcube_create("TestApp");

    // Add a textbox to the TUI
    char textBuffer[100]; // Adjust the size based on your needs
    fscl_xcube_add_textbox(testtui, 5, 5, 20, 5, textBuffer);

    // Update the textbox content
    fscl_xcube_set_textbox_content(testtui, 0, "Updated Text");

    // Add assertions to check if the textbox content is updated
    TEST_ASSERT_EQUAL_CSTRING("Updated Text", testtui->textboxes[0].text->content);

    fscl_xcube_exit(testtui);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_textbox_group) {
    XTEST_RUN_UNIT(test_add_textbox);
    XTEST_RUN_UNIT(test_update_textbox);
} // end of fixture
