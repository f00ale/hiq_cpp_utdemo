#include <crpcut.hpp>

#include "matte/issquare.h"
#include "matte/isprime.h"

TESTSUITE(test_math) {
	TEST(test_isprime) {
		ASSERT_TRUE(isprime(3));
		ASSERT_FALSE(isprime(81));
	}

	TEST(test_square) {
		ASSERT_TRUE(issquare(16));
		ASSERT_FALSE(issquare(12));
	}

	DISABLED_TEST(dont_run) {

	}
}
