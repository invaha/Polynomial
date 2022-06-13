/**************************************************
 * name: special_overload.h
 * project: polynomial similator
 * this is for make and use polynomials using cin
 * and cout and objects of fstream to stream objects
 * of Term andPolynomial . . .
**************************************************/
#ifndef SPECIAL_OVERLOAD_H
#define SPECIAL_OVERLOAD_H
#include <iostream>
#include "polynomial.h"
#include "term.h"
using namespace std;
vector<string>split(string line)
{
    string temp = "";
    vector<string> vect;
    for (unsigned i = 0;i < line.length();i++)
    {
        if ((line.at(i) == '+')||(line.at(i) == '-'))
        {
            if(line.at(i) == '+')
            {
                vect.push_back(temp);
                temp = "";
            }
            else
            {
                if(i != 0)
                {
                    if(line.at(i-1) != '^')
                    {
                        vect.push_back(temp);
                        temp = "";
                        temp += line.at(i);
                    }
                    else
                    {
                        temp += line.at(i);
                    }
                }
                else
                {
                    temp += line.at(i);
                }
            }
        }
        else
        {
            temp += line.at(i);
        }
    }
    vect.push_back(temp);
    return vect;
}
ostream &operator<<(ostream& out,const Term& obj)
{
    if(obj.get_m_zarib() != 0)
    {
        if(((obj.get_m_zarib() == 1))&&(obj.get_m_pow() != 0))
        {

        }
        else
        {
            out<<obj.get_m_zarib();
        }
        if(obj.get_m_pow() != 0)
        {
            if(obj.get_m_pow() == 1)
            {
                out<<'x';
            }
            else
            {
                out<<"x^";
            }
            if(obj.get_m_pow() < 0)
            {
                out<<obj.get_m_pow();
            }
            else
            {
                if(obj.get_m_pow() != 1)
                {
                    out<<obj.get_m_pow();
                }
            }
        }
    }
    else
    {
        out<<0;
    }
    return out;
}
istream &operator>>(istream&in,Term& obj)
{
    bool is_x = false;
    bool is_pow = false;
    string temp_in;
    in>>temp_in;
    for(unsigned int q = 0;q < temp_in.length();q++)
    {
        if(temp_in[q] == 'x')
        {
            is_x = true;
        }
        else if(temp_in[q] == '^')
        {
            is_pow = true;
        }
    }
    if((is_x)&&(is_pow))
    {
        for(unsigned int q = 0;q < temp_in.length();q++)
        {
            if(temp_in[q] == 'x')
            {
                if((temp_in[0] == '-')&&(temp_in[1] == 'x'))
                {
                    obj.set_m_zarib(-1);
                }
                else
                {
                    if(temp_in[0] == 'x')
                    {
                        obj.set_m_zarib(1);
                    }
                    else
                    {
                        string temp_zarib = temp_in.substr(0,q);
                        obj.set_m_zarib(stof(temp_zarib));
                    }
                }
            }
        }
        for(unsigned int q = 0;q < temp_in.length();q++)
        {
            if(temp_in[q] == '^')
            {
                string temp_power = temp_in.substr(q+1,temp_in.length());

                obj.set_m_pow(stoi(temp_power));
            }
        }
    }
    else if(is_x && !is_pow)
    {
        obj.set_m_pow(1);
        for(unsigned int q = 0;q < temp_in.length();q++)
        {
            if(temp_in[q] == 'x')
            {
                if((temp_in[0] == '-')&&(temp_in[1] == 'x'))
                {
                    obj.set_m_zarib(-1);
                }
                else
                {
                    if(temp_in[0] == 'x')
                    {
                        obj.set_m_zarib(1);
                    }
                    else
                    {
                        string temp_zarib = temp_in.substr(0,q);
                        obj.set_m_zarib(stof(temp_zarib));
                    }
                }
            }
        }
    }
    else if(!is_x && !is_pow)
    {
        obj.set_m_zarib(stof(temp_in.substr(0,temp_in.length()+1)));
        obj.set_m_pow(0);
    }
    return in;
}
ostream &operator<<(ostream& out,const Polynomial& obj)
{
    if(obj.terms.size()==0)
    {
        out<<0;
    }
    else
    {
        for(unsigned int q = 0;q < obj.terms.size();q++)
        {
            if(q == 0)
            {
                out<<obj.terms[q];
            }
            else if(q == obj.terms.size()-1)
            {
                if(obj.terms[q].get_m_zarib() > 0)
                {
                    out<<'+';
                    out<<obj.terms.at(q);
                }
                else
                {
                    out<<obj.terms.at(q);
                }
            }
            else
            {
                if(obj.terms[q].get_m_zarib() > 0)
                {
                    out<<'+';
                    out<<obj.terms[q];
                }
                else
                {
                    out<<obj.terms.at(q);
                }
            }
        }
    }
    return out;
}
istream &operator>>(istream&in,Polynomial& obj)
{
    string temp_in;
    in>>temp_in;
    vector<Term>temp_terms;
    vector<string>all_terms = split(temp_in);
    temp_terms.resize(all_terms.size());
    for(unsigned int r = 0;r < temp_terms.size();r++)
    {
        bool is_x = false;
        bool is_pow = false;
        string temp_in = all_terms[r];
        for(unsigned int q = 0;q < temp_in.length();q++)
        {
            if(temp_in[q] == 'x')
            {
                is_x = true;
            }
            else if(temp_in[q] == '^')
            {
                is_pow = true;
            }
        }
        if((is_x) && (is_pow))
        {
            for(unsigned int q = 0;q < temp_in.length();q++)
            {
                if(temp_in[q] == 'x')
                {
                    if((temp_in[0] == '-') && (temp_in[1] == 'x'))
                    {
                        temp_terms[r].set_m_zarib(-1);
                    }
                    else
                    {
                        if(temp_in[0] == 'x')
                        {
                            temp_terms[r].set_m_zarib(1);
                        }
                        else
                        {
                            string temp_zarib = temp_in.substr(0,q);
                            temp_terms[r].set_m_zarib(stof(temp_zarib));
                        }
                    }
                }
            }
            for(unsigned int q = 0;q < temp_in.length();q++)
            {
                if(temp_in[q] == '^')
                {
                    string temp_power = temp_in.substr(q+1,temp_in.length());
                    temp_terms[r].set_m_pow(stoi(temp_power));
                }
            }
        }
        else if(is_x&&!is_pow)
        {
            temp_terms[r].set_m_pow(1);
            for(unsigned int q = 0;q < temp_in.length();q++)
            {
                if(temp_in[q] == 'x')
                {
                    if((temp_in[0] == '-')&&(temp_in[1] == 'x'))
                    {
                        temp_terms[r].set_m_zarib(-1);
                    }
                    else
                    {
                        if(temp_in[0] == 'x')
                        {
                            temp_terms[r].set_m_zarib(1);
                        }
                        else
                        {
                            string temp_zarib = temp_in.substr(0,q);
                            temp_terms[r].set_m_zarib(stof(temp_zarib));
                        }
                    }
                }
            }
        }
        else if(!is_x && !is_pow)
        {
            temp_terms[r].set_m_zarib(stof(temp_in.substr(0,temp_in.length()+1)));
            temp_terms[r].set_m_pow(0);
        }
    }
    obj.terms = temp_terms;
    obj.sort_and_complete();
    return in;
}
Term operator + (const Term& temp_object1,const Term&temp_object2)
{
    if(temp_object1.get_m_pow() == temp_object2.get_m_pow())
    {
        return(Term(temp_object1.get_m_zarib()+temp_object2.get_m_zarib(), temp_object1.get_m_pow()));
    }
    else
    {
        throw(Wrong());
    }
}
Term operator - (const Term& temp_object1,const Term&temp_object2)
{
    if(temp_object1.get_m_pow() == temp_object2.get_m_pow())
    {
        return(Term(temp_object1.get_m_zarib()-temp_object2.get_m_zarib(), temp_object1.get_m_pow()));
    }
    else
    {
        throw(Wrong());
    }
}
Term operator * (const Term& temp_object1,const Term&temp_object2)
{
    return(Term(temp_object1.get_m_zarib() * temp_object2.get_m_zarib(),
           temp_object1.get_m_pow() + temp_object2.get_m_pow()));
}
Term operator / (const Term& temp_object1,const Term&temp_object2)
{
    return(Term(temp_object1.get_m_zarib() / temp_object2.get_m_zarib(),
           temp_object1.get_m_pow() - temp_object2.get_m_pow()));
}
bool operator == (const Term& temp_object1,const Term&temp_object2)
{
    if((temp_object1.get_m_zarib() == temp_object2.get_m_zarib()) &&
            (temp_object1.get_m_pow() == temp_object2.get_m_pow()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator != (const Term& temp_object1,const Term&temp_object2)
{
    if(temp_object1==temp_object2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool operator > (const Term& temp_object1,const Term&temp_object2)
{
    if(temp_object1.get_m_pow() > temp_object2.get_m_pow())
    {
        return true;
    }
    if((temp_object1.get_m_pow() == temp_object2.get_m_pow()) &&
            (temp_object1.get_m_zarib() > temp_object2.get_m_zarib()))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator <= (const Term& temp_object1,const Term&temp_object2)
{
    if(!(temp_object1 > temp_object2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator < (const Term& temp_object1,const Term&temp_object2)
{
    if((temp_object1 <= temp_object2)&&(temp_object1!=temp_object2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator >= (const Term& temp_object1,const Term&temp_object2)
{
    if(!(temp_object1 < temp_object2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
Polynomial operator + (const Polynomial& temp_object1,const Polynomial& temp_object2)
{
    vector<Term>temp_vect;
    temp_vect = temp_object1.terms;
    for(unsigned int q = 0;q < temp_object2.terms.size();q++)
    {
        temp_vect.push_back(temp_object2.terms[q]);

    }
    return Polynomial(temp_vect);
}
Polynomial operator - (const Polynomial& temp_object1,const Polynomial& temp_object2)
{
    vector<Term>temp_vect1;
    vector<Term>temp_vect2;
    temp_vect1 = temp_object1.terms;
    temp_vect2 = temp_object2.terms;
    for(unsigned int q = 0;q < temp_vect2.size();q++)
    {
        temp_vect2.at(q).set_m_zarib(temp_vect2.at(q).get_m_zarib()*(-1));
    }
    for(unsigned int q = 0;q < temp_vect2.size();q++)
    {
        temp_vect1.push_back(temp_vect2.at(q));
    }
    return Polynomial(temp_vect1);
}
Polynomial operator * (const Polynomial& temp_object1,const Polynomial& temp_object2)
{
    vector<Term>temp;
    for(unsigned int q = 0;q < temp_object1.terms.size();q++)
    {
        for(unsigned int w = 0;w < temp_object2.terms.size();w++)
        {
                temp.push_back(temp_object1.terms[q]*temp_object2.terms[w]);
        }
    }
    return(Polynomial(temp));
}
bool operator == (const Polynomial& temp_object1,const Polynomial&temp_object2)
{
    if(temp_object1.terms.size() != temp_object2.terms.size())
    {
        return false;
    }
    for(unsigned int q = 0;q < temp_object1.terms.size();q++)
    {
        if(temp_object1.terms.at(q).get_m_zarib() != temp_object2.terms[q].get_m_zarib())
        {
            return false;
        }
        if(temp_object1.terms.at(q).get_m_pow() != temp_object2.terms[q].get_m_pow())
        {
            return false;
        }
    }
    return true;
}
bool operator != (const Polynomial& temp_object1,const Polynomial&temp_object2)
{
    if(temp_object1==temp_object2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool operator < (const Polynomial& temp_object1,const Polynomial&temp_object2)
{
    if(temp_object1.terms.size() == temp_object2.terms.size())
    {
        for(unsigned int q = 0;q < temp_object1.terms.size();q++)
        {
            if(temp_object1.terms[q] > temp_object2.terms[q])
            {
                return false;
            }
            else if(temp_object1.terms[q] == temp_object2.terms[q])
            {
                if(q == temp_object1.terms.size() - 1)
                {
                    return false;
                }
            }
            else if(temp_object1.terms[q] < temp_object2.terms[q])
            {
                return true;
            }
        }
    }
    else
    {
        unsigned int min_size = temp_object2.terms.size();

        if(temp_object1.terms.size() < temp_object2.terms.size())
        {
            min_size = temp_object1.terms.size();
        }
        for(unsigned int q = 0;q < min_size;q++)
        {
            if(temp_object1.terms[q] > temp_object2.terms[q])
            {
                return false;
            }
            else if(temp_object1.terms[q] < temp_object2.terms[q])
            {
                return true;
            }
        }
        if(temp_object1.terms.size() > temp_object2.terms.size())
        {
            return false;
        }
        return true;
    }
}
bool operator >= (const Polynomial& temp_object1,const Polynomial&temp_object2)
{
    if(!(temp_object1 < temp_object2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator > (const Polynomial& temp_object1,const Polynomial&temp_object2)
{
    if((temp_object1 >= temp_object2)&&(temp_object1!=temp_object2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool operator <= (const Polynomial& temp_object1,const Polynomial&temp_object2)
{
    if(!(temp_object1 > temp_object2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif // SPECIAL_OVERLOAD_H
