/**************************************************
 * name: polynomial.h
 * project: polynomial similator
 * this is for make and use polynomials . . .
**************************************************/
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<vector>
#include"term.h"
using namespace std;

class Polynomial
{
public:
    friend bool operator != (const Polynomial& temp_object1,const Polynomial&temp_object2);
    friend bool operator < (const Polynomial& temp_object1,const Polynomial&temp_object2);
    friend bool operator == (const Polynomial& temp_object1,const Polynomial&temp_object2);
    friend istream &operator>>(istream&in,Polynomial& obj);
    friend Polynomial operator - (const Polynomial& temp_object1,const Polynomial& temp_object2);
    friend Polynomial operator * (const Polynomial& temp_object1,const Polynomial& temp_object2);
    friend Polynomial operator + (const Polynomial& temp_object1,const Polynomial& temp_object2);
    friend ostream &operator<<(ostream& out,const Polynomial& obj);
    /*defult constructor*/
    Polynomial();

    /*constructors*/
    Polynomial(float zarib, int tavan = 0);
    Polynomial(Term temp_term);
    Polynomial(vector<Term>temp_terms);

    /*this make the vector sorted and complete the incomplete Terms */
    void sort_and_complete();


    /*all needed overloadings */
    Polynomial& operator *= (const Polynomial& temp_object);
    Polynomial& operator += (const Polynomial& temp_object);
    Polynomial& operator -= (const Polynomial& temp_object);
    Polynomial& operator = (const Polynomial& temp_object);
    Polynomial& operator ++ ();
    Polynomial operator ++ (int);
    Polynomial operator -- (int);
    Polynomial& operator -- ();
    Polynomial operator ~ ();
    Term& operator[](int index);
    const Term&operator[](int index)const;
    float operator()(float temp_num)const;


    /*function for find the degree of this polynomial*/
    int max_pow();


    /*function for find the number of terms in this polynomial*/
    unsigned int num_of_Terms();

private:
    vector<Term>terms;
};
#endif // POLYNOMIAL_H
