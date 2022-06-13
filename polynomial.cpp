/**************************************************
 * name: polynomial.cpp
 * project: polynomial similator
 * this is for make and use polynomials . . .
**************************************************/
#include "polynomial.h"
Polynomial::Polynomial(float zarib, int tavan )
{
    terms.push_back(Term(zarib,tavan));
}
Polynomial::Polynomial()
{

}
Polynomial::Polynomial(Term temp_term)
{
    terms.push_back(temp_term);
}
Polynomial ::Polynomial(vector<Term>temp_terms)
{
    for(unsigned int q = 0;q < temp_terms.size();q++)
    {
        terms.push_back(temp_terms.at(q));
        sort_and_complete();
    }
}
void Polynomial::sort_and_complete()
{
    for(unsigned int q = 0;q < terms.size();q++)
    {
        for(unsigned int w = q+1;w < terms.size();w++)
        {
            if(terms.at(q).get_m_pow() == terms.at(w).get_m_pow())
            {
                terms.at(q) += terms.at(w);
                terms.erase(terms.begin()+w);
            }
        }
    }
    for(unsigned int q = 0;q < terms.size();q++)
    {
        for(unsigned int w = 0;w < terms.size()-1-q;w++)
        {
            if(terms.at(w).get_m_pow() < terms.at(w+1).get_m_pow())
            {
                swap(terms.at(w),terms.at(w+1));
            }
        }
    }
    for(unsigned int q = 0;q < terms.size();q++)
    {
        if(terms.at(q).get_m_zarib() == 0)
        {
            terms.erase(terms.begin()+q);
        }
    }
    for(unsigned int q = 0;q < terms.size();q++)
    {
        for(unsigned int w = 0;w < terms.size()-1-q;w++)
        {
            if(terms.at(w).get_m_pow() < terms.at(w+1).get_m_pow())
            {
                swap(terms.at(w),terms.at(w+1));
            }
        }
    }
}
float Polynomial:: operator()(float temp_num) const
{
    try
    {
        float result = 0;
        for(unsigned int q = 0;q < terms.size();q++)
        {
            result += terms.at(q)(temp_num);
        }
        return result;
    }
    catch(Wrong wrong)
    {
        wrong.print_zero_eror();
    }
}
unsigned int Polynomial::num_of_Terms()
{
    if(terms.size() != 0)
    {
        sort_and_complete();
    }
    return terms.size();
}
int Polynomial::max_pow()
{
    int temp = terms.at(0).get_m_pow();
    for(unsigned int q = 1;q < terms.size();q++)
    {
        if(terms[q].get_m_pow() > temp)
        {
            temp = terms[q].get_m_pow();
        }
    }
    return temp;
}
const Term& Polynomial::operator [](int index)const
{
    return (terms.at(index));
}
Term& Polynomial:: operator[](int index)
{
    return (terms.at(index));
}
Polynomial& Polynomial::operator+=(const Polynomial& temp_object)
{
    for(unsigned int q = 0;q < temp_object.terms.size();q++)
    {
        terms.push_back(temp_object.terms.at(q));
        if(q == temp_object.terms.size()-1)
        {
            sort_and_complete();
        }
    }

    return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& temp_object)
{
    vector<Term>temp_vect;
    temp_vect = temp_object.terms;
    for(unsigned int q = 0;q < temp_vect.size();q++)
    {
        temp_vect.at(q).set_m_zarib(temp_vect.at(q).get_m_zarib()*(-1));
    }
    for(unsigned int q = 0;q < temp_object.terms.size();q++)
    {
        terms.push_back(temp_vect.at(q));
        if(q == temp_object.terms.size()-1)
        {
            sort_and_complete();
        }
    }
    return *this;
}
Polynomial& Polynomial::operator*=(const Polynomial& temp_object)
{
    vector<Term>temp;
    for(unsigned int q = 0;q < terms.size();q++)
    {
        for(unsigned int w = 0;w < temp_object.terms.size();w++)
        {
            temp.push_back(Term(terms[q].get_m_zarib()*temp_object.terms[w].get_m_zarib(),terms[q].get_m_pow()+temp_object.terms.at(w).get_m_pow()));
        }
    }
    terms=temp;
    if(terms.size()!=0)
    {
        sort_and_complete();
    }
    return *this;
}
Polynomial& Polynomial::operator=(const Polynomial& temp_object)
{
    if(this==&temp_object)
    {
        return *this;
    }
    terms = temp_object.terms;
    return *this;
}
Polynomial Polynomial::operator ~()
{
    vector<Term>temp;
    for(unsigned int q = 0;q < terms.size();q++)
    {
        temp.push_back(~terms[q]);
    }
    return Polynomial(temp);
}
Polynomial& Polynomial::operator++ ()
{
    terms.push_back(Term(1,0));
    sort_and_complete();
    return *this;
}
Polynomial Polynomial:: operator ++ (int)
{
    Polynomial temp = (*this);
    (*this).terms.push_back(Term(1,0));
    return temp;
}
Polynomial Polynomial:: operator -- (int)
{
    Polynomial temp = (*this);
    (*this).terms.push_back(Term(-1,0));
    return temp;
}
Polynomial& Polynomial:: operator-- ()
{
    terms.push_back(Term(-1,0));
    sort_and_complete();
    return *this;
}
