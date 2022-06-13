#ifndef SOME_FUNCTIONS_H
#define SOME_FUNCTIONS_H
#include<string>
std::string bool_to_string(bool temp_boll)
{
    if(temp_boll)
    {
        return"True";
    }
    else
    {
        return"False";
    }
}

#endif // SOME_FUNCTIONS_H
