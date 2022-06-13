/**************************************************
 * name: Term.h
 * project: polynomial similator
 * this is for make and use polynomials using
 * making terms ,this file includes the class Term . . .
**************************************************/
#ifndef TERM_H
#define TERM_H
#include<cmath>
#include <iostream>
#include "wrong.h"
//#include "polynomial.h"
class Term
{
public:
    /*defult constructor*/
    Term();


    /*constructor*/
    Term(float zarib, int tavan = 0);


    int get_m_pow()const
    {
        return m_pow;
    }
    float get_m_zarib()const
    {
        return m_zarib;
    }
    void set_m_zarib(float temp_zarib)
    {
        m_zarib = temp_zarib;
    }
    void set_m_pow(int temp_pow)
    {
        m_pow = temp_pow;
    }


    /*all needed overlodings*/
    Term operator ~();
    Term operator++(int );
    Term operator--(int );
    Term& operator+=(const Term& temp_object);
    Term& operator-=(const Term& temp_object);
    Term& operator*=(const Term& temp_object);
    Term& operator/=(const Term& temp_object);
    Term& operator=(const Term& temp_object);
    Term& operator++ ();
    Term& operator-- ();
    float operator()(float temp_num)const;

private:
    float m_zarib;
    int m_pow;
};
#endif // TERM_H
