#include "thread.h"
#include "common_test.h"

TEST(threadTest, PositiveNumbers) 
{
    print_thread();
    EXPECT_EQ(multi(1, 2), 2);
}

TEST(threadTest, NegativeNumbers) 
{
    EXPECT_EQ(multi(0, 100), 0);
}