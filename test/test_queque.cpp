#include "queque.h"
#include <gtest.h>


TEST(Queue, can_make_queue) {
	ASSERT_NO_THROW(Queque<int> q1);
}