//This is a test file

//include test framework "googletest"
#include "gtest/gtest.h" 
//include the gs model's head file
#include "src/gs.h"

//Check if (F, k) matches of the the u and v vectors.
TEST(ModelParameters, TypeMatching) {
    ASSERT_EQ(typeid(F), typeid(u[0][0]));
    ASSERT_EQ(typeid(k), typeid(u[0][0]));
    ASSERT_EQ(typeid(F), typeid(v[0][0]));
    ASSERT_EQ(typeid(k), typeid(v[0][0]));
}

// Test the size of u and v
TEST(VectorSizes, Matching) {
    // if size of u equals size of v 
    ASSERT_EQ(u.size(), v.size());
    for (int i = 0; i < u.size(); ++i) {
        ASSERT_EQ(u[i].size(), v[i].size());
    }
}

// Check the answers while the value of u equals value of v
TEST(ZeroInitialConditions, MathematicalCorrectness) {
    // 设置u和v为0
    for (int i = 0; i < u.size(); ++i) {
        for (int j = 0; j < u[i].size(); ++j) {
            u[i][j] = 0.0;
            v[i][j] = 0.0;
        }
    }

    // run simulatestep
    simulateStep();

    //check results
    for (size_t x = 0; x < u.size(); ++x) {
        for (size_t y = 0; y < u[0].size(); ++y) {
            EXPECT_NEAR(u[x][y], 0.0, 1e-9);
            EXPECT_NEAR(v[x][y], 0.0, 1e-9);
        }
    }
}
