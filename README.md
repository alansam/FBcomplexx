# Class complexx

A small project to demonstrate the use of overloaded operators (`+`, `-`, `+=`, `-=`, etc.) The class also implements overloaded copy and move `=` operators and `<<`, `>>` for integration with standard I/O streams `std::ostream` and `std::istream` respectively.

The class is a simple implementation of a complex number which holds the real and imaginary parts as `double`.

## Member Data (*private*)

* `double real_`
* `double ima_`
* `bool LOG` - ***static constant*** - used to control logging.

## Member Methods and Functions (*public*)

### Constructors & Destructor

* `complexx(double, double)` ***inline method*** - default constructor.
* `complexx(complexx const &)` ***inline method*** - copy constructor.
* `complexx(complexx const &&)` ***inline method*** - move constructor.
* `~complexx()` ***inline method*** - destructor.

### Overloaded Member Methods

* `complexx & operator=(complexx const &)` copy `operator=()`.
* `complexx & operator=(complexx &&)` move `operator=()`.
* `complexx & operator+=(complexx const &)` compound assignment - sum.
* `complexx & operator-=(complexx const &)` compound assignment - difference.

### Friend Functions

* `complexx operator+(complexx const &, complexx const &)` addition.
* `complexx operator-(complexx const &, complexx const &)` subtraction.
* `std::ostream & operator<<(std::ostream &, complexx const &)` bitwise left shift - insert formatted data from an instance of the class into a `std::ostream`.
* `std::istream & operator>>(std::istream &, complexx &)` extract data from a `std::istream` and stores it in an instance the class.

### Accessors  & Mutators *(Getters & Setters)*

* `double real(void)` ***inline method*** - accessor for the real part of the complex number. Gets the contents of the `real_` member data.
* `double real(double)` ***inline method*** - mutator for the real part of the complex number. Gets the contents of the `ima_` member data.<br/>(**NOTE:** returns a copy of the member data).
* `double ima(void)` ***inline method*** - accessor for the imaginary part of the complex number. Gets the contents of the `real_` member data.
* `double ima(double)` ***inline method*** - mutator for the imaginary part of the complex number. Gets the contents of the `ima_` member data.<br/>(**NOTE:** returns a copy of the member data).

### Deprecated Member Methods

* `void rdcmplx(void)` read data from `std::cin` and stores it in an instance the class. 
* `void wrcmplx(void)` insert formatted data from an instance of the class into `std::cout`.
* `complexx sum(complexx x, complexx) const` addition.
* `complexx add(complexx const &)` compound assignment - sum.
