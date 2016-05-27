#pragma once

#include <string>

class myclass {
public:
  int m_i;
  std::string m_s;
  void seti(int i);
  int geti() const;

  void sets(const std::string & s);
  std::string gets() const;
};
