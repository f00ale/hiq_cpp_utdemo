#include "myclass.h"

void myclass::seti(int i) { m_i = i; }
int myclass::geti() const { return m_i; }

void myclass::sets(const std::string & s) { m_s = s; }
std::string myclass::gets() const { return m_s; }

