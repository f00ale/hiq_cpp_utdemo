#include <crpcut.hpp>
#include <trompeloeil.hpp>

#include "ext/funcs.h"

struct Freefun {
	MAKE_MOCK1(oldcrap, void(int*));
};

Freefun * freefun;

struct Fixture {
	Fixture() { freefun = new Freefun; }
	~Fixture() { delete freefun; }
};

// stubs
void oldcrap(int *ip) { freefun->oldcrap(ip); }
// /stubs

using trompeloeil::_;
using trompeloeil::ne;

TESTSUITE(freestanding) {
	TEST(t1, Fixture) {
		Freefun & fix = *freefun;
		REQUIRE_CALL(fix, oldcrap(_));
		oldcrap(nullptr);
	}

	TEST(t2, Fixture) {
		Freefun & fix = *freefun;
		REQUIRE_CALL(fix, oldcrap(ne(nullptr)));
		int i;
		oldcrap(&i);
	}

}
