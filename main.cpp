//  compiler options: -Wall -Wpedantic -fsanitize=address -std=gnu++XX
//  where XX is 11, 14, 17, 20, etc. but 11 at a minimum
#include <iostream>
#include <iomanip>
#include <cmath>

#include "complexx.hpp"

#define INTERACTIVE

//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: - Constants
static constexpr bool KLOG { true };

//  MARK: - Implementation
//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: main()
int main(int argc, char const * argv[]) {
  //  Create test data
  std::string dlm = "A: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  complexx p1(1.0, 1.0);
  complexx p2(-33.0, -11.0);
  complexx p3;
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n";

  //  Test sum() method
  dlm = "B: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "sum(p1, p2)\n";
  p3 = p3.sum(p1, p2);
  std::cout << ":::\n";
  p3.wrcmplx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n";

  //  Test add() method
  dlm = "C: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "p1.add(p2)\n";
  p3 = complexx();
  p3 = p1.add(p2);
  std::cout << ":::\n";
  p3.wrcmplx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n";

  //  Test operator+() method
  dlm = "D: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "(p3 = p1 + p2)\n";
  std::cout << ":::\n";
  p3 = complexx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n"
            << "}}} p3 " << (p3 = p1 + p2) << ";\n";

  //  Test operator+=() method
  dlm = "E: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "(p3 += p2)\n";
  std::cout << ":::\n";
  p3 = complexx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n"
            << "}}} p3 " << (p3 += p2) << ";\n";

   //  Test operator-() method
 dlm = "F: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "(p3 = p1 - p2)\n";
  std::cout << ":::\n";
  p3 = complexx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n"
            << "}}} p3 " << (p3 = p1 - p2) << ";\n";

   //  Test operator+=() method
 dlm = "G: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "(p3 -= p2)\n";
  std::cout << ":::\n";
  p3 = complexx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n"
            << "}}} p3 " << (p3 -= p2) << ";\n";

  //  Test operator+() & operator-() methods
  dlm = "H: ....+....|....+....|....+....|....+....|....+....|";
  std::cout << dlm << '\n';
  if (KLOG) { std::clog << dlm << '\n'; }
  std::cout << "(p3 = p1 + p2 - p3)\n";
  std::cout << ":::\n";
  p3 = complexx();
  std::cout << "}}} p1 " << p1 << ";\n"
            << "}}} p2 " << p2 << ";\n"
            << "}}} p3 " << p3 << ";\n"
            << "}}} p3 " << (p3 = p1 + p2 - p3) << ";\n";

  #ifdef INTERACTIVE
  {
    //  Test real() & ima() methods
    dlm = "I: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (KLOG) { std::clog << dlm << '\n'; }
    std::cout << "std::cin >> t1 >> t2\n";
    std::cout << ":::\n";
    p3 = p1;
    double r_;
    double i_;
    std::cout << "enter real & imaginary: ";
    std::cin >> r_ >> i_;
    std::cout << '\n';
    p3.real(r_);
    p3.ima(i_);
    std::cout << "}}} p3 " << p3 << ";\n";
  }
#endif

#ifdef INTERACTIVE
  {
    //  Test operator>>() method
    dlm = "J: ....+....|....+....|....+....|....+....|....+....|";
    std::cout << dlm << '\n';
    if (KLOG) { std::clog << dlm << '\n'; }
    std::cout << "std::cin >> p3\n";
    std::cout << ":::\n";
    std::cout << "enter real & imaginary: ";
    std::cin >> p3;
    std::cout << '\n';
    std::cout << "}}} p3 " << p3 << ";\n";
  }
#endif

  std::cout << "Done ...\n";
  if (KLOG) { std::clog << "Done ...\n"; }

  return 0;
}
