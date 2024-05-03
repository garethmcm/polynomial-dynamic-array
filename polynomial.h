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
    Polynomial& operator =(double a0); // 3

    void addToCoef(double amount, unsigned int k);
    void assignCoef(double new_coefficient, unsigned int k);
    void clear( );
    void reserve(size_t number);

private:
    sizeType k;
    term *co;
    sizeType degree = 0;

};

#endif //POLYNOMIALS_DYNAMICARRAY_POLYNOMIAL_H
