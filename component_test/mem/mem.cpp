#include "mem.h"
#include "common_test.h"

// Test case cho hàm add
TEST(memTest, PositiveNumbers) 
{
    print_mem();
    EXPECT_EQ(add(1, 2), 3);  // 1 + 2 phải bằng 3
}

TEST(memTest, NegativeNumbers) 
{
    EXPECT_EQ(add(-1, -1), -2);  // -1 + -1 phải bằng -2
}
