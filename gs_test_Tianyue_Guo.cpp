//This is a test file

//include test framework "googletest"
#include "third_party/googletest/googletest/include/gtest/gtest.h"
//include the gs model's head file
#include "gs.h"

// Test for problem (0.1)
TEST(SimulationTest, ParameterTypesMatch) {
    // Check the types of model parameters match the element type of u and v vectors
    EXPECT_EQ(typeid(F).name(), typeid(u[0][0]).name());
    EXPECT_EQ(typeid(k).name(), typeid(u[0][0]).name());
}

// Test for problem (0.2)
TEST(SimulationTest, VectorsSameSize) {
    // Check that u and v vectors are the same size
    EXPECT_EQ(u.size(), v.size());
    for (int i = 0; i < u.size(); ++i) {
        EXPECT_EQ(u[i].size(), v[i].size());
    }
}

// Test for problem (0.3)
TEST(GSTest, MathematicalCorrectness) {
  for (auto& row : u) std::fill(row.begin(), row.end(), 0.0);
  for (auto& row : v) std::fill(row.begin(), row.end(), 0.0);

  simulateStep();  

  for (int x = 1; x < width - 1; ++x) {
    for (int y = 1; y < height - 1; ++y) {
      EXPECT_GT(u[x][y], 0.0) ;
      EXPECT_DOUBLE_EQ(v[x][y], 0.0) ;
    }
  }
}
