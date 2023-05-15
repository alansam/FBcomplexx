#include <iostream>
#include <iomanip>
#include <cmath>

//..+....|....+....|....+....|....+....|....+....|....+....|....+....|
//  MARK: - Definitions
//  MARK: Class complexx
class complexx {
private:
  double real_;
  double ima_;

  static constexpr bool LOG { true };

public:
  //  constructors - inline
  complexx(double a = 2.0, double b = 3.0)
  : real_ { a }, ima_ { b } {
    if (LOG) {
      std::clog << "complexx::" << __func__
                << "() default c'tor [@"
                << std::hex << this << std::dec
                << "]\n";
    }
  }

  // implement copy & move c'tors to prevent automatic generation.
  complexx(complexx const & that)
  : real_ { that.real_ }, ima_ { that.ima_ } {
    if (LOG) {
      std::clog << "complexx::" << __func__
                << "() copy c'tor [@"
                << std::hex
                << this << ", @" << &that
                << std::dec
                << "]\n"; }
  }
  complexx(complexx const && that)
  : real_ { std::move(that.real_) }, ima_ { std::move(that.ima_) } {
    if (LOG) {
      std::clog << "complexx::" << __func__
                << "() move c'tor [@"
                << std::hex
                << this << ", @" << &that
                << std::dec
                << "]\n";
    }
  }

// implement copy & move operator=() to prevent automatic generation.
  complexx & operator=(complexx const & that);
  complexx & operator=(complexx && that);

//  destructor - default
#ifdef VIRT_DTOR  /* lest we forget */
  virtual
#endif
  ~complexx() {
    if (LOG) { std::clog << "complexx::" << __func__ << "() d'tor [@" << std::hex << this << std::dec << "]\n"; }
  }

  [[deprecated("use operator>>() instead")]]
  void rdcmplx(void);
  [[deprecated("use operator<<() instead")]]
  void wrcmplx(void);

  [[deprecated("use operator+() instead")]]
  complexx sum(complexx x, complexx y) const;
  [[deprecated("use operator+=() instead")]]
  complexx add(complexx const & that);

  complexx & operator+=(complexx const & that);
  complexx & operator-=(complexx const & that);

  //  etc.

  //  accessors (getters) & mutators (setters) - inline
  double real(void) const {
    return real_;
  }

  double real(double rl) {
    return (real_ = rl);
  }

  double ima(void) const {
    return ima_;
  }

  double ima(double im) {
    return (ima_ = im);
  }

  //  MARK: operator<<() - Friend function
  friend
  std::ostream & operator<<(std::ostream & os, complexx const & that);

  //  MARK: operator>>() - Friend function
  friend
  std::istream & operator>>(std::istream & in, complexx & that);

  //  MARK: operator+() - Friend function
  friend
  complexx operator+(complexx const & lft, complexx const & rgt);
  //  MARK: operator-() - Friend function
  friend
  complexx operator-(complexx const & lft, complexx const & rgt);
};
