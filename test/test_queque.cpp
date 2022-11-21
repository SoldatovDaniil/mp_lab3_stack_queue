#include "queque.h"
#include <gtest.h>


TEST(Queque, can_make_queue) 
{
	ASSERT_NO_THROW(Queque<int> q1);
}

TEST(Queque, can_copy_queque) 
{
	Queque<int> q1;
	ASSERT_NO_THROW(Queque<int> q2(q1));
}

TEST(Queque, can_get_size_work_correctly) 
{
	Queque<int> q1;
	for (int i = 0; i < 5; i++)
	{
		q1.push(i);
	}
	EXPECT_EQ(5, q1.getsize());
}

TEST(Queque, cant_pop_empty)
{
	Queque<int> q1;
	ASSERT_ANY_THROW(q1.pop());
}

TEST(Queque, can_pop_no_empty)
{
	Queque<int> q1;
	q1.push(4);
	ASSERT_NO_THROW(q1.pop());
}

TEST(Queque, can_top_correctly)
{
	Queque<int> q1;
	q1.push(1);
	EXPECT_EQ(1, q1.top());
}

TEST(Queque, can_push_correctly)
{
	Queque<int> q1;
	q1.push(2);
	EXPECT_EQ(q1.top(), 2);
}

TEST(Queque, can_copy_queuqe_correctly) 
{
	Queque<int> q1;
	for (int i = 0; i < 5; i++)
	{
		q1.push(i);
	}
	Queque<int> q2(q1);
	EXPECT_EQ(q2.top(), q1.top());
	EXPECT_EQ(q1.getsize(), q2.getsize());

	q1.pop(), q2.pop();
	EXPECT_EQ(q2.top(), q1.top());
}