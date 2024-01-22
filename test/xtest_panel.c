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

#include <fossil/xcube/panel.h> // library under test

//
// XUNIT-CASES: list of test cases testing project features
//

// Test for creating a panel
XTEST_CASE(test_create_panel) {
    xpanel* testPanel = fscl_xcube_create_panel(XPANEL_TYPE_DEFAULT);
    TEST_ASSERT_NOT_CNULLPTR(testPanel);
    fscl_xcube_exit(testPanel->tui);
    free(testPanel);
}

// Test for switching focus to a panel
XTEST_CASE(test_switch_focus_to_panel) {
    xui* mainTui = fscl_xcube_create("TestApp");
    xpanel* testPanel = fscl_xcube_create_panel(XPANEL_TYPE_DEFAULT);

    // Switch focus to the panel
    fscl_xcube_switch_focus_to_panel(mainTui, testPanel);

    // Add assertions to check if the focus is switched successfully
    TEST_ASSERT_EQUAL_PTR(testPanel->tui, mainTui->focused_tui);

    fscl_xcube_exit(mainTui);
    free(testPanel);
}

// Test for adding an element to the focused panel
XTEST_CASE(test_add_element_to_focused_panel) {
    xui* mainTui = fscl_xcube_create("TestApp");
    xpanel* testPanel = fscl_xcube_create_panel(XPANEL_TYPE_DEFAULT);

    // Switch focus to the panel
    fscl_xcube_switch_focus_to_panel(mainTui, testPanel);

    // Add an element to the focused panel
    fscl_xcube_add_element_to_focused_panel(mainTui, "Test Element", 5, 5, 20, 3);

    // Add assertions to check if the element is added to the focused panel
    TEST_ASSERT_EQUAL_CSTRING("Test Element", mainTui->focused_tui->elements[0].content);

    fscl_xcube_exit(mainTui);
    free(testPanel);
}

//
// XUNIT-GROUP: a group of test cases from the current test file
//
XTEST_DEFINE_POOL(xui_panel_group) {
    XTEST_RUN_UNIT(test_create_panel);
    XTEST_RUN_UNIT(test_switch_focus_to_panel);
    XTEST_RUN_UNIT(test_add_element_to_focused_panel);
} // end of fixture
