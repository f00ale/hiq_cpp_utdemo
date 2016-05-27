#include "extuser.h"

extuser::extuser(extclass & ext) : mExt(ext) {}

size_t extuser::getVecSize() const {
	auto v = mExt.get_vector();
	return v.size();
}

void extuser::seti(int i) {
	mExt.set_int(i);
}

int extuser::geti() const {
	return mExt.get_int();
}

