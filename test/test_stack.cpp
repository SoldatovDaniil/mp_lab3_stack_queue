#include "stack.h"
#include <gtest.h>


TEST(Stack, can_make_stack)
{
	ASSERT_NO_THROW(Stack<int> s1);
}

TEST(Stack, can_copy_stack)
{
	Stack<int> s1;
	ASSERT_NO_THROW(Stack<int> s2(s1));
}

TEST(Stack, can_copy_stack_correctly)
{
	Stack<int> s1;
	for (int i = 0; i < 3; i++)
	{
		s1.push(i);
	}
	Stack<int> s2(s1);
	EXPECT_EQ(s1, s2);
}

TEST(Stack, top_work_correctly)
{
	Stack<int> s1; 
	for (int i = 0; i < 15; i++)
	{
		s1.push(i);
	}
	EXPECT_EQ(14, s1.top());
}

TEST(Stack, can_push_correctly)
{
	Stack<int> s1;
	for (int i = 0; i < 15; i++)
	{
		s1.push(i);
	}
	EXPECT_EQ(s1.top(), 14);
}

TEST(Stack, can_pop_correctly)
{
	Stack<int> s1;
	for (int i = 0; i < 15; i++)
	{
		s1.push(i);
	}
	EXPECT_EQ(15, s1.getsize());
}

TEST(Stack, can_detect_empty_stack_correctly)
{
	Stack<int> s1;
	for (int i = 0; i < 15; i++)
	{
		s1.push(i);
	}
	Stack<int> s2;
	EXPECT_EQ(false, s1.empty());
	EXPECT_EQ(true, s2.empty());
}