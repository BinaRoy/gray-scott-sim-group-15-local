#include <gtest/gtest.h>
#include "gs.cpp" 
using namespace std;


// check parameters types
TEST(GSTest, ParameterType) {
    EXPECT_TRUE((is_same<decltype(u), vector<vector<double>>>::value));
    EXPECT_TRUE((is_same<decltype(v), vector<vector<double>>>::value));
}

//  check u and v size 
TEST(GSTest, Size) {
    EXPECT_EQ(u.size(), v.size());
    for (size_t i = 0; i < u.size(); ++i) {
        EXPECT_EQ(u[i].size(), v[i].size());
    }
}

//  check when u = 0 and v = 0 is correct 
TEST(GSTest, Correctness) {
    for (auto& row : u) {
        fill(row.begin(), row.end(), 0.0);
    }
    for (auto& row : v) {
        fill(row.begin(), row.end(), 0.0);
    }
    
    simulateStep();

    for (int x = 1; x < width - 1; ++x) {
        for (int y = 1; y < height - 1; ++y) {
            EXPECT_GT(u[x][y], 0.0);
            ASSERT_DOUBLE_EQ(v[x][y], 0.0);
        }
    }
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
