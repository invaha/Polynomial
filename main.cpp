/**************************************************
 * name: main.cpp
 * project: polynomial similator
 * this is for make polynomials ,this file is the
 * main file to combinate all classes that we need
 * for doing that . . .
**************************************************/
#include "term.h"
#include <fstream>
#include "polynomial.h"
#include "special_overload.h"
#include "some_functions.h"
using namespace std;
int main()
{
    bool show_main_menu = false;
    Polynomial curent_polynomial;
    int choice;
    do
    {
        if(show_main_menu)
        {
            choice = 1;
        }
        else
        {
            _getwch();
            system("cls");
            cout<<"Main Menu\n";
            cout<<"1- New Polynomial\n";
            cout<<"2- Load from text file";
            cout<<"\n3- Load from binary file";
            cout<<"\n4- Quit";
            cout<<"\nwhat do you want to do ?    ";
            cin>>choice;
        }
        if(choice > 4||choice < 1)
        {
            cout<<"\nwrong input";
        }
        else
        {
            int choice_;
            if(choice == 1)
            {
               do
               {
                    if(!show_main_menu)
                    {
                        _getwch();
                    }
                    show_main_menu = false;
                    system("cls");
                    cout<<"Polynomial Menu\n";
                    cout<<"\nCurrent Polynomial = ";
                    cout<<curent_polynomial;
                    cout<<"\n\n";
                    cout<<"1- Add\n";
                    cout<<"2- Subtract\n";
                    cout<<"3- Multiply\n";
                    cout<<"4- Derivative\n";
                    cout<<"5- Find Degree\n";
                    cout<<"6- Find Value for specific x\n";
                    cout<<"7- Compare\n";
                    cout<<"8- Save to a text file\n";
                    cout<<"9- Save to a binary file\n";
                    cout<<"10- Back to Main Menu\n";
                    cout<<"\nwhat do you want to do ?    ";
                    cin>>choice_;
                    if(choice_ == 1)
                    {
                        try
                        {
                            Polynomial Other_Polynomial;
                            cout<<"\nenter a Polynomial to continue  :";
                            cin>>Other_Polynomial;
                            curent_polynomial += Other_Polynomial;
                        }
                        catch(...)
                        {
                            cout<<"\nyour input is invalid ";
                        }
                    }
                    else if(choice_ == 2)
                    {
                        try
                        {
                            Polynomial Other_Polynomial;
                            cout<<"\nenter a Polynomial to continue  :";
                            cin>>Other_Polynomial;
                            curent_polynomial -= Other_Polynomial;
                        }
                        catch(...)
                        {
                            cout<<"\nyour input is invalid ";
                        }
                    }
                    else if(choice_ == 3)
                    {
                        try
                        {
                            Polynomial Other_Polynomial;
                            cout<<"\nenter a Polynomial to continue  :";
                            cin>>Other_Polynomial;
                            curent_polynomial *= Other_Polynomial;
                        }
                        catch(...)
                        {
                            cout<<"\nyour input is invalid ";
                        }
                    }
                    else if(choice_ == 4)
                    {
                        curent_polynomial = ~curent_polynomial;
                    }
                    else if(choice_ == 5)
                    {
                        cout<<"\nDegree is : ";
                        if(curent_polynomial.num_of_Terms()==0)
                        {
                            cout<<0;
                        }
                        else
                        {
                            cout<<curent_polynomial.max_pow();
                        }
                    }
                    else if(choice_ == 6)
                    {
                        float x;
                        cout<<"\nEnter a number for continue : ";
                        cin>>x;
                        cout<<"\nThe value is : "<<curent_polynomial(x)<<"\n";
                    }
                    else if(choice_ == 7)
                    {
                        Polynomial Other_Polynomial;
                        cout<<"\nenter a Polynomial to continue  :";
                        cin>>Other_Polynomial;
                        cout<<"Current_Polynomial= "<<curent_polynomial<<"\n";
                        cout<<"Other_Polynomial  = "<<Other_Polynomial<<"\n";
                        cout<<"\nComparing Current_Polynomial with Other_Polynomial\n\n";
                        cout<<"\nCurrent_Polynomial > Other_Polynomial: "<<bool_to_string(curent_polynomial > Other_Polynomial);
                        cout<<"\n\nCurrent_Polynomial >= Other_Polynomial: "<<bool_to_string(curent_polynomial >= Other_Polynomial);
                        cout<<"\n\nCurrent_Polynomial < Other_Polynomial: "<<bool_to_string(curent_polynomial < Other_Polynomial);
                        cout<<"\n\nCurrent_Polynomial <= Other_Polynomial: "<<bool_to_string(curent_polynomial <= Other_Polynomial);
                        cout<<"\n\nCurrent_Polynomial == Other_Polynomial: "<<bool_to_string(curent_polynomial == Other_Polynomial);
                    }
                    else if(choice_ == 8)
                    {
                        string file_name;
                        cout<<"\nEnter the file name to save this polynomial\nFile name : ";
                        cin>>file_name;
                        ifstream temp_file(file_name,ios::in);
                        if(temp_file)
                        {
                            temp_file.close();
                            ofstream my_file(file_name, ios::trunc);
                            my_file<<curent_polynomial;
                            cout<<"\nfinished\n";
                            my_file.close();
                        }
                        else
                        {
                            cout<<"we can not find a file with this name and format\nDo you want to "
                                <<"create it ? (if yes,enter 'y' ";
                            char temp_choice;
                            cin>>temp_choice;
                            if(temp_choice == 'y'||temp_choice == 'Y')
                            {
                                ofstream my_file(file_name, ios::trunc);
                                my_file<<curent_polynomial;
                                cout<<"\nfinished\n";
                                my_file.close();
                            }
                        }
                    }
                    else if(choice_ == 9)
                    {
                        string file_name;
                        cout<<"\nEnter the file name to save this polynomial\nFile name : ";
                        cin>>file_name;
                        ifstream temp_file(file_name, ios::in);
                        if(temp_file)
                        {
                            temp_file.close();
                            ofstream my_file(file_name, ios::trunc|ios::binary);
                            int size_of_curent_polynomial = curent_polynomial.num_of_Terms();
                            my_file.write((char*)&size_of_curent_polynomial,sizeof(int));
                            for(int q = 0;q < size_of_curent_polynomial;q++)
                            {
                                my_file.write((char*)&curent_polynomial[q],sizeof(curent_polynomial[q]));
                            }
                            cout<<"\nfinished\n";
                            my_file.close();
                        }
                        else
                        {
                            cout<<"we can not find a file with this name and format\nDo you want to "
                                <<"create it ? (if yes,enter 'y' ";
                            char temp_choice;
                            cin>>temp_choice;
                            if(temp_choice == 'y'||temp_choice == 'Y')
                            {
                                ofstream my_file(file_name, ios::trunc|ios::binary);
                                int size_of_curent_polynomial = curent_polynomial.num_of_Terms();
                                my_file.write((char*)&size_of_curent_polynomial,sizeof(int));
                                for(int q = 0;q < size_of_curent_polynomial;q++)
                                {
                                    my_file.write((char*)&curent_polynomial[q],sizeof(curent_polynomial[q]));
                                }
                                cout<<"\nfinished\n";
                                my_file.close();
                            }
                        }
                    }
               }while(choice_ != 10);
            }
            else if(choice == 2)
            {
                try
                {
                    string file_name;
                    cout<<"\nEnter file name to read from it : ";
                    cin>>file_name;
                    ifstream my_file(file_name, ios::in);
                    if(my_file)
                    {
                        my_file>>curent_polynomial;
                        my_file.close();
                        show_main_menu = true;
                    }
                    else
                    {
                        cout<<"\nwe can not find and open the file\n";
                    }
                }
                catch(...)
                {
                    cout<<"\nthere is some problems about your file,we can not read it ";
                }
            }
            else if(choice == 3)
            {
                try
                {
                    string file_name;
                    cout<<"\nEnter file name to read from it : ";
                    cin>>file_name;
                    ifstream my_file(file_name, ios::binary);
                    if(my_file)
                    {
                        ifstream my_file(file_name, ios::binary);
                        int size_of_curent_polynomial;
                        my_file.read((char*)&size_of_curent_polynomial,sizeof(int));
                        vector<Term>temp_vect;
                        temp_vect.resize(size_of_curent_polynomial);
                        for(int q = 0;q < size_of_curent_polynomial;q++)
                        {
                            my_file.read((char*)&temp_vect[q], sizeof(temp_vect[q]));
                        }
                        Polynomial temp_po(temp_vect);
                        curent_polynomial = temp_po;
                        my_file.close();
                        show_main_menu = true;
                    }
                    else
                    {
                        cout<<"\nwe can not find and open the file\n";
                    }
                }
                catch(...)
                {
                    cout<<"\nthere is some problems about your file,we can not read it ";
                }
            }
        }
    }while(choice != 4);
    system("cls");
    cout<<"Thanks for use "<<(char)1<<endl;
    return 0;
}
