#include "polynomial.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// default constructor
Polynomial::Polynomial() : k(0)
{
    co = new term[defaultSize];
}

// first term given
Polynomial::Polynomial(double a0) : k(0)
{
    co = new term[defaultSize];
    co[0] = a0;
}

// copy constructor
Polynomial::Polynomial(const Polynomial& source) : k(source.k), degree(source.degree) {
    co = new term[defaultSize];
    for (sizeType i = 0; i < degree; ++i) {
        co[i] = source.co[i];
    }
}

// destructor
Polynomial::~Polynomial() {
    delete[] co;
}

Polynomial& Polynomial::operator = (const Polynomial& source) {

    term *newData;
    // self assignment check
    if(this == &source) {
        return *this;
    }

    if(this->degree != source.degree)
    {
        // allocates dyn array of diff size if needed
        newData = new term[source.degree];
        delete[] co;
        co = newData;
        degree = source.degree;
    }
    k = source.k;
    // uses copy function to copy original data from source
    copy(source.co, source.co + k, co);

    return *this;
}

Polynomial& Polynomial::operator =(double a0) {
    Polynomial *polly = new Polynomial(a0);
    return *polly;
}

void Polynomial::addToCoef(double amount, unsigned int k) {
    if (k > degree)
        degree = k; // changes degree of polynomial if entry higher than any existing entry
    co[k] = amount;
}
void Polynomial::assignCoef(double newCoefficient, unsigned int k) {
    co[k] = newCoefficient;
}
void Polynomial::clear() {
    // set all coefficients to 0
    sizeType index = 0;
    while (index < degree) {
        co[index] = 0;
        ++index;
    }
}
void Polynomial::reserve(size_t number) {
    term *biggerPolly;    // page 193
    if (number == degree)
        return; // The allocated memory is already the right size
    number = degree; // Can’t allocate less than we are using.
    biggerPolly = new term[number];
    copy(co, co + degree, biggerPolly);
    delete [ ] co;
    co = biggerPolly;
    degree = number;
}