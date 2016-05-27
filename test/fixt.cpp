#include <crpcut.hpp>

#include "sut/myclass.h"

struct MyFixture {
  myclass sut;
};

TESTSUITE(fixt) {
	TEST(test_integers, MyFixture) {
		sut.seti(3);
		ASSERT_EQ(3, sut.geti());
		sut.seti(7);
		ASSERT_EQ(7, sut.geti());
	}


	TEST(test_strings, MyFixture) {
		sut.sets("hej hopp");
		ASSERT_EQ("hej hopp", sut.gets());
	}
}

