#pragma once

#include <string>
#include <vector>

class extclass {
public:
	virtual void set_int(int) = 0;
	virtual int get_int() const = 0;

	virtual std::vector<std::string> get_vector() const = 0;
};
