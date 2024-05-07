#ifndef POLYNOMIALS_DYNAMICARRAY_POLYNOMIAL_H
#define POLYNOMIALS_DYNAMICARRAY_POLYNOMIAL_H
#include <cstdlib>

using namespace std;

class Polynomial
{
public:
    // Typedefs and member constants
    typedef double term;
    typedef size_t sizeType;
    // default size for dyn array
    sizeType defaultSize = 9;

    // Constructors & destructor
    Polynomial();
    Polynomial(double a0);
    Polynomial(const Polynomial& source);
    ~Polynomial();

    Polynomial& operator = (const Polynomial& source); // 2
    Polynomial& operator = (double a0); // 3

    void addToCoef(double amount, unsigned int k);
    void assignCoef(double new_coefficient, unsigned int k);
    void clear( );
    void reserve(size_t number);

    double coefficient(unsigned int k) const;
    unsigned int getDegree() const;
    unsigned int nextTerm(unsigned int k) const;

    double eval(double x) const;
    double operator () (double x) const;

    Polynomial operator+(const Polynomial& b) const;

    Polynomial operator-(const Polynomial& b) const;

    Polynomial operator*(const Polynomial& b) const;

//    Polynomial& merge (Polynomial a, Polynomial b) const;

private:
    sizeType k;
    term *co;
    unsigned int degree = 0;

};

#endif //POLYNOMIALS_DYNAMICARRAY_POLYNOMIAL_H
