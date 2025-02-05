#include "socket.h"
#include "common_test.h"

TEST(socketTest, PositiveNumbers) 
{
    print_socket();
    EXPECT_EQ(negative(3, 2), 1);
}

TEST(socketTest, NegativeNumbers) 
{
    EXPECT_EQ(add(-1, -1), -2); 
}