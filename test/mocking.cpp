#include <crpcut.hpp>
#include <trompeloeil.hpp>

#include "sut/extuser.h"
#include "ext/klass.h"

class mock_extclass : public extclass {
public:
	MAKE_CONST_MOCK0(get_int, int(void));
	MAKE_CONST_MOCK0(get_vector, std::vector<std::string>(void));
	MAKE_MOCK1(set_int, void(int));
};

struct myfixture {
	mock_extclass mock;
	extuser sut;
	myfixture() : mock(), sut(mock) {}
};

using trompeloeil::_;

TESTSUITE(mocking) {
	TEST(set, myfixture) {
		REQUIRE_CALL(mock, set_int(3));
		sut.seti(3);
	}

	TEST(set2, myfixture) {
		REQUIRE_CALL(mock, set_int(_));
		FORBID_CALL(mock, set_int(18));
		sut.seti(38);
	}

	TEST(fail1, myfixture) {
		ALLOW_CALL(mock, set_int(_));
		FORBID_CALL(mock, set_int(18));
		sut.seti(16);
		sut.seti(17);
		sut.seti(18);
	}

	TEST(fail2, myfixture) {
		sut.seti(18);
	}

	TEST(fail3, myfixture) {
		REQUIRE_CALL(mock, set_int(_));
	}

	TEST(getint, myfixture) {
		REQUIRE_CALL(mock, get_int()).RETURN(18);
		ASSERT_EQ(18, sut.geti());
	}

	TEST(get_vec_size, myfixture) {
		REQUIRE_CALL(mock, get_vector()).RETURN(std::vector<std::string>{"a", "bc"});
		ASSERT_EQ(2u, sut.getVecSize());
	}
}
