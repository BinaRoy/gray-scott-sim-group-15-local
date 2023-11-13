#include <gtest/gtest.h>
#include "gs.cpp" 

// Test 0.1: Type Check for Model Parameters
TEST(GrayScottTest, ParameterTypeCheck) {
    EXPECT_TRUE((std::is_same<decltype(u), std::vector<std::vector<double>>>::value));
    EXPECT_TRUE((std::is_same<decltype(v), std::vector<std::vector<double>>>::value));
}

// Test 0.2: Size Check for u and v
TEST(GrayScottTest, SizeCheck) {
    EXPECT_EQ(u.size(), v.size());
    for (size_t i = 0; i < u.size(); ++i) {
        EXPECT_EQ(u[i].size(), v[i].size());
    }
}

// Test 0.3: Mathematical Correctness when u = 0 and v = 0
TEST(GrayScottTest, MathematicalCorrectness) {
    // Initialize u and v to 0
    for (auto& row : u) {
        std::fill(row.begin(), row.end(), 0.0);
    }
    for (auto& row : v) {
        std::fill(row.begin(), row.end(), 0.0);
    }
    
    // Call the simulation step function
    simulateStep();

    // Check the outcome against expected values
    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            // Check that u and v have been updated correctly
            EXPECT_GT(u[x][y], 0.0);
            ASSERT_DOUBLE_EQ(v[x][y], 0.0);
        }
    }
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
