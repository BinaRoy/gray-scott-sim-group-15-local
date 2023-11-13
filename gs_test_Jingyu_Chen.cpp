#include "gtest/gtest.h"
#include "/home/Projects/Group15_workshop1/src/gs.h"
#include <vector>
#include <cmath>


void test_init(double Du, double Dv, double F, double k, double threshold) {

}



TEST(GSTest, ParameterTypeCheck) {
  EXPECT_TRUE((std::is_same<decltype(F), decltype(u)::value_type::value_type>::value));
  EXPECT_TRUE((std::is_same<decltype(k), decltype(v)::value_type::value_type>::value));
}



TEST(GSTest, SizeCheck) {
  test_init(0.14, 0.07, 0.03, 0.0648, 0.1); 
  EXPECT_EQ(u.size(), v.size());
  if (!u.empty()) {
    EXPECT_EQ(u[0].size(), v[0].size());
  }
}



TEST(GSTest, MathematicalCorrectness) {
  for (auto& row : u) std::fill(row.begin(), row.end(), 0.0);
  for (auto& row : v) std::fill(row.begin(), row.end(), 0.0);
  F = 0.03;
  k = 0.0648;

  simulateStep();  

  for (int x = 1; x < width - 1; ++x) {
    for (int y = 1; y < height - 1; ++y) {
      EXPECT_GT(u[x][y], 0.0) << "u should increase due to feed rate";
      EXPECT_DOUBLE_EQ(v[x][y], 0.0) << "v should remain zero";
    }
  }

}

