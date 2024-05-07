This is code for polynomials implemented using dynamic arrays as per an exercise in Data structures and Other Objects in C++ by Michael Main and Walter Savitch.

Below is an outline of the assignment for context:

A one-variable polynomial is an arithmetic expression of the form:

	akxk+...+a2x2 +a1x1 +a0x0

The highest exponent, k, is called the degree of the polynomial, and the constants a0, a1, ... are the coefficients. For example, here is a polynomial with degree 3

	0.3x3 +0.5x2 +(–0.9)x1 +1.0x0

Each individual term of a polynomial consists of a real
number as a coefficient (such as 0.3), the variable x, and a non-negative integer as an exponent. The x1 term is usually written with just an x rather than x1; the x0 term is usually written with just the coefficient (since x0 is always defined to be 1); and a negative coefficient may also be written with a subtraction sign, so another way to write the same polynomial is:

	0.3x3 + 0.5x2 – 0.9x + 1.0

For any specific value of x, a polynomial can be evaluated by plugging the value of x into the expression. For example, the value of the sample polynomial at x = 2 is:

	0.3(2)3 + 0.5(2)2 – 0.9(2) + 1.0 = 3.6

A typical algebra exercise is to plot the graph of a polyno- mial for each value of x in a given range. For example, Figure 4.15 plots the value of a polynomial for each x in the range of –2 to +2.

For this project, you should specify, design, and implement a class for poly- nomials. The coefficients are double numbers, and the exponents are non- negative integers. The coefficients should be stored in a dynamic array of double numbers, with the exponent for the xk term stored in location [k] of the array. The maximum index of the array needs to be at least as big as the degree of the polynomial, so that the largest nonzero coefficient can be stored. 

In addition, the class should have a member variable to keep track of the current size of the dynamic array and another member variable to keep track of the cur- rent degree of the polynomial. (You could manage without the degree variable, but having it around makes certain operations more efficient.)
The rest of this section lists some member functions and nonmember func- tions that you could provide to the polynomial class.

A. Constructors and destructor

polynomial( ); // Default constructor polynomial(double a0); // Set the x0 coefficient only polynomial(const polynomial& source); // Copy constructor ~polynomial( );
The default constructor creates a polynomial with all zero coefficients. The sec- ond constructor creates a polynomial with the specified parameter as the coeffi- cient of the x0 term, and all other coefficients are zero. For example:

	polynomial p(4.2); 	// p has only one nonzero term, 4.2x0, which is the 
						// same as the number 4.2 (since x0 is defined as
						// equal to 1).


B. Assignment operator

polynomial& operator = (const polynomial& source);
This is the usual overloaded assignment operator, with one change: The return type is polynomial& rather than void. This return type is similar to an ordi- nary polynomial, but the extra symbol & makes it a reference return type, similar to the return type ostream& of our output operators. The complete details of a reference return type are beyond this project. For your implementation, you should know two facts:

1. The function implementation should return the object that activated the assignment. This is accomplished with the keyword this. The syntax is: return *this; , which means “return the object that this points to.” Since this always points to the object that activates the function, the return statement has the effect that we need.
2. Using polynomial& as the return type permits a sequence of chained assignments. For example, if a, b, and c are three polynomials, we can write a = b = c, which copies the value of c to b, and then copies the new value of b to a (chained assignments work from right to left).
Remember to have your implementation check for a possible self-assignment.

C. A second assignment operator

polynomial& operator =(double a0);
For a polynomial b, this assignment can be activated in a statement such as b = 4.2 . The double number, 4.2, becomes the argument a0 for this assign- ment. The implementation will use this number as the coefficient for the x0 term, and all other coefficients are set to zero.

You might notice that this second version of the assignment operator isn’t entirely needed. Even without this assignment operator, we could write an assignment b = 4.2 ; in this case, the compiler would apply the polynomial constructor to the number 4.2 (creating the polynomial 4.2x0), and then this poly- nomial would be assigned to b. However, writing an explicit assignment operator to allow b = 4.2 is generally more efficient because we avoid the overhead of the constructor-generated conversion.

D. Modification member functions

	void add_to_coef(double amount, unsigned int k);
	void assign_coef(double new_coefficient, unsigned int k); 
	void clear( );
	void reserve(size_t number);

The add_to_coef function adds the specified amount to the coefficient of the xk term. The assign_coef function sets the xk coefficient to new_coefficient. In both cases, the parameter k is an unsigned int, which is the C++ data type that is like an int, but may never have a negative value.
The clear function sets all coefficients to zero. The reserve function works like reserve for the bag class, making sure that the underlying array has at least the requested size.

E. Constant member functions

	double coefficient(unsigned int k) const; 
	unsigned int degree( ) const;
	unsigned int next_term(unsigned int k) const;

The coefficient function returns the coefficient of the xk term.
The degree function returns the degree of the polynomial. For a polynomial where all coefficients are zero, our degree function returns 0 (although mathematicians usually use –1 for the degree of such a polynomial).

The next_term function returns the exponent of the next term with a nonzero coefficient after xk. For example, if the x3 term of p is 0 and the x4 term of p is 6x4, then p.next_term(2) returns the exponent 4 (since 4 is the next exponent after 2 with a nonzero coefficient). If there are no nonzero terms after xk, then next_term(k) should return the constant UINT_MAX from the library facility <climits>. (This constant is the largest unsigned int.)

F. Evaluation functions

	double eval(double x) const;
	double operator ( )(double x) const;

The eval function evaluates a polynomial at the given value of x. For example, if p is 0.3x3 + 0.5x2 – 0.9x + 1.0 , then p.eval(2) is 0.3(2)3 + 0.5(2)2 – 0.9(2) + 1.0 , which is 3.6.
The second function also evaluates the polynomial, but it does so with some strange syntax. The name of this second function is “operator ( ),” and it has one parameter (the double number x). To activate the operator ( ) for a poly- nomial p, you write the name p followed by the parameter in parentheses. For example: p(2). The implementation of the operator ( ) does the same work as the eval function; the two separate implementations just give the programmer a choice of syntax. You can write p.eval(2), or you can write p(2) in a program.

G. Arithmetic operators

You can overload the binary arithmetic operators of addition, subtraction, and multiplication to add, subtract, and multiply two poly- nomials in the usual manner. (Division is not possible, because it can result in fractional exponents.) For example:

	Suppose 	q = 2x3 + 4x2 + 3x + 1
	and
				r = 7x2 + 6x + 5
	Then: 		q + r = 2x3 + 11x2 + 9x + 6 
				q – r = 2x3 – 3x2 – 3x–4
				q × r = 14x5 + 40x4 + 55x3 + 45x2 +21x + 5

The product, q × r , is obtained by multiplying each separate term of q times
each separate term of r and adding the results together.