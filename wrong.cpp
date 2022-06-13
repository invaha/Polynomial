#include "wrong.h"
#include <iostream>

Wrong::Wrong()
{

}
void Wrong::print_term_eror()
{
    std::cout<<"\n\nthere is two terms with not equal pows\nso ,we can not do it . . .\n";
}
void Wrong::print_zero_eror()
{
   std:: cout<<"in this polynomial, we have a(or more)sentence(s)with negative \npow,and we can not do this";
}
