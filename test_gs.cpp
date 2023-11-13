#define TESTING
#include "acutest.h"  
#include "gs.cpp"     

void test_type_matching(void) {
    // Test (0.1): Check type matching
    TEST_CHECK(typeid(F) == typeid(u[0][0]));  
    TEST_CHECK(typeid(k) == typeid(v[0][0]));
}

void test_size_matching(void) {
    // Test (0.2): Check size matching
    TEST_CHECK(u.size() == v.size());
    for (size_t i = 0; i < u.size(); ++i) {
        TEST_CHECK(u[i].size() == v[i].size());
    }
}

void test_simulation_output(void) {
    // Initialize u and v to 0
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            u[x][y] = 0.0;
            v[x][y] = 0.0;
        }
    }

    // Run the simulation step
    simulateStep();

    // Check if the state of u has increased and v has remained unchanged
    bool u_increased = false, v_unchanged = true;
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (u[x][y] > 0.0) u_increased = true;
            if (v[x][y] != 0.0) v_unchanged = false;
        }
    }

    // Verify that u has increased and v has remained unchanged
    TEST_CHECK(u_increased && v_unchanged);
}

// List of test cases to run
TEST_LIST = {
   { "type_matching", test_type_matching },
   { "size_matching", test_size_matching },
   { "simulation_output", test_simulation_output },
   { NULL, NULL }  // Terminate the list
};

