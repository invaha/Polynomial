/**************************************************
 * name: Term.cpp
 * project: polynomial similator
 * this is for make and use polynomials using
 * making terms ,this file includes most functions
 * of the class Term . . .
**************************************************/
#include "term.h"
#include "polynomial.h"
using namespace std;

Term::Term()
{

}
Term Term::operator ~()
{
    return(Term(m_pow*m_zarib,m_pow-1));
}
Term::Term(float zarib,int tavan)
{
    m_pow = tavan;
    m_zarib = zarib;
}

Term& Term::operator+=(const Term& temp_object)
{
    m_zarib += temp_object.m_zarib;
    return *this;
}
Term& Term::operator-=(const Term& temp_object)
{
    m_zarib -= temp_object.m_zarib;
    return *this;
}
Term& Term::operator*=(const Term& temp_object)
{
    m_zarib *= temp_object.m_zarib;
    m_pow += temp_object.m_pow;
    return *this;
}
Term& Term::operator/=(const Term& temp_object)
{
    m_zarib /= temp_object.m_zarib;
    m_pow -= temp_object.m_pow;
    return *this;
}
Term& Term::operator=(const Term& temp_object)
{
    if(this==&temp_object)
    {
        return *this;
    }
    m_zarib = temp_object.m_zarib;
    m_pow = temp_object.m_pow;
    return *this;
}

Term& Term::operator++ ()
{
    if(m_pow == 0)
    {
        m_zarib++;
        return *this;
    }
    else
    {
        throw(Wrong());
    }
}
Term Term:: operator++(int )
{
    if(m_pow==0)
    {
        Term temp=(*this);     //copy old valu
        (*this).set_m_zarib((*this).get_m_zarib()+1); //increment
        return temp; //return old value
    }
    else
    {
        throw(Wrong());
    }
}
Term Term:: operator--(int )
{
    if(m_pow==0)
    {
        Term temp=(*this);
        (*this).set_m_zarib((*this).get_m_zarib()-1);
        return temp;
    }
    else
    {
        throw(Wrong());
    }
}
Term& Term::operator-- ()
{
    if(m_pow == 0)
    {
        m_zarib--;
        return *this;
    }
    else
    {
        throw(Wrong());
    }

}
float Term::operator()(float temp_num)const
{
    if(temp_num==0&&m_pow<0)
    {
        throw(Wrong());
    }
    else
    {
        if(temp_num == 0)
        {
            if((m_zarib != 0)&&(m_pow == 0))
            {
                return m_zarib;
            }
            return 0;
        }
        return m_zarib*pow(temp_num,m_pow);
    }
}
