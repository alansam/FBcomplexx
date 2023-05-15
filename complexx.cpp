#include "complexx.hpp"

//  MARK: - Implementation
//..+....|....+....|....+....|....+....|....+....|....+....|...
//  MARK:  complexx::operator=() copy
complexx & complexx::operator=(complexx const & that) {
  if (LOG) {
    std::clog << "complexx::" << __func__
              << "() copy [@"
              << std::hex
              << this << ", @" << &that
              << std::dec
              << "]\n";
  }
  real_ += that.real_;
  ima_ += that.ima_;
  return *this;
}
//  MARK:  complexx::operator=() move
complexx & complexx::operator=(complexx && that) {
  if (LOG) {
    std::clog << "complexx::" << __func__
              << "() move [@"
              << std::hex
              << this << ", @" << &that
              << std::dec
              << "]\n";
  }
  real_ = std::move(that.real_);
  ima_ = std::move(that.ima_);
  return *this;
}

//  MARK:  complexx::rdcmplx()
void complexx::rdcmplx(void) {
  if (LOG) { std::clog << "complexx::" << __func__ << "() [@" << std::hex << this << std::dec << "]\n"; }
  std::cout << "enter real & imaginary: ";
  std::cin >> real_ >> ima_;
  std::cout << std::endl;
}

//  MARK:  complexx::wrcmplx()
void complexx::wrcmplx(void) {
  if (LOG) { std::clog << "complexx::" << __func__ << "() [@" << std::hex << this << std::dec << "]\n"; }
  std::cout << std::fixed << std::setprecision(3);
  std::cout << std::setw(9)
            << real_;
  if (ima_ < 0.0) {
    std::cout << " - i" << ::fabs(ima_) << '\n';
  }
  else {
    std::cout << " + i" << ima_ << '\n';
  }
}

//  MARK:  complexx::sum()
complexx complexx::sum(complexx x, complexx y) const {
  if (LOG) {
    std::clog << "complexx::" << __func__
              << "(complexx,complexx) [@"
              << std::hex
              << this << ", @" << &x << ", @" << &y
              << std::dec
              << "]\n";
  }
  complexx temp;
  temp.real_ = x.real_ + y.real_;
  temp.ima_ = x.ima_ + y.ima_;
  return temp;
}

//  MARK:  complexx::add()
complexx complexx::add(complexx const & that) {
  if (LOG) {
    std::clog << "complexx::" << __func__
              << "(complexx) [@"
              << std::hex
              << this << ", @" << &that
              << std::dec
              << "]\n";
  }
  complexx temp;
  temp.real_ = real_ + that.real_;
  temp.ima_ = ima_ + that.ima_;
  return temp;
}

//  MARK:  complexx::operator+=()
complexx & complexx::operator+=(complexx const & that) {
  if (LOG) {
    std::clog << "complexx::" << __func__
              << "() [@"
              << std::hex
              << this << ", @" << &that
              << std::dec
              << "]\n";
  }
  real_ += that.real_;
  ima_ += that.ima_;
  return *this;
}

//  MARK:  complexx::operator-=()
complexx & complexx::operator-=(complexx const & that) {
  if (LOG) {
    std::clog << "complexx::" << __func__
              << "() [@"
              << std::hex
              << this << ", @" << &that
              << std::dec
              << "]\n";
  }
  real_ -= that.real_;
  ima_ -= that.ima_;
  return *this;
}

//  MARK: operator+() - Friend function
complexx operator+(complexx const & lft, complexx const & rgt) {
  if (lft.LOG) {
    std::clog << "complexx::" << __func__
              << "(complexx,complexx) [@"
              << std::hex
              << &lft << ", @" << &rgt
              << std::dec
              << "]\n";
  }
  complexx temp;
  temp.real_ = lft.real_ + rgt.real_;
  temp.ima_ = lft.ima_ + rgt.ima_;
  return temp;
}

//  MARK: operator-() - Friend function
complexx operator-(complexx const & lft, complexx const & rgt) {
  if (lft.LOG) {
    std::clog << "complexx::" << __func__
              << "(complexx,complexx) [@"
              << std::hex
              << &lft << ", @" << &rgt
              << std::dec
              << "]\n";
  }
  complexx temp;
  temp.real_ = lft.real_ - rgt.real_;
  temp.ima_ = lft.ima_ - rgt.ima_;
  return temp;
}

//  MARK: operator<<() - Friend function
std::ostream & operator<<(std::ostream & os, complexx const & that) {
  if (that.LOG) {
    std::clog << "complexx::" << __func__
              << "() [@"
              << std::hex
              << &that
              << std::dec
              << "]\n";
  }
  os << std::fixed << std::setprecision(3);
  os << std::setw(9)
     << that.real_;
  if (that.ima_ < 0.0) {
    os << " - i" << ::fabs(that.ima_);
  }
  else {
    os << " + i" << that.ima_;
  }
  return os;
}

//  MARK: operator>>() - Friend function
//  TODO: this doesn't seem logical, it needs too much knlowledge of the class
//  probably safer to read data into temp vars. and insert them into the
//  via the setter methods.
std::istream & operator>>(std::istream & in, complexx & that) {
  if (that.LOG) {
    std::clog << "complexx::" << __func__
              << "() [@"
              << std::hex
              << &that
              << std::dec
              << "]\n";
  }
  std::cin >> that.real_ >> that.ima_;
  return in;
}
