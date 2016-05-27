#pragma once

#include "ext/klass.h"

class extuser {
	extclass & mExt;
public:
	extuser(extclass & ext);

	size_t getVecSize() const;
	void seti(int);
	int geti() const;
};
