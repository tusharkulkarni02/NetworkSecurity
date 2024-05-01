#include <iostream>
#include <conio.h>
using namespace std;

char pin[100];

string def_user = "admin";
string def_pass = "admin";

string user;
string enter_pass;
string pass = def_pass;

void change_pass()
{
    int k = 0;
    cout << "Enter  password : ";
    while (pin[k - 1] != '\r')
    {
        pin[k] = getch();
        if (pin[k - 1] != '\r')
        {
            cout << "*";
        }
        k++;
    }
    pin[k - 1] = '\0';
    pass = pin;
    cout << "\nYou entered : " << pin << endl;
}

void view_pass()
{
    cout << "Your password: \n";
    cout << pass << endl;
}

int main()
{

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter your username: \n";
        cin >> user;
        cout << "Enter your password: \n";
        cin >> enter_pass;

        if (user == def_user && enter_pass == pass)
        {
            cout << "Login successfull!!\n";
            bool flag = true;
            while (flag)
            {
                char c;
                cout << "Enter your choice: \n";
                cout << "1. Change password \n";
                cout << "2. View password \n";
                cout << "3. Exit \n";
                cin >> c;
                cin.ignore();

                switch (c)
                {
                case '1':
                {
                    change_pass();
                    break;
                }
                case '2':
                {
                    view_pass();
                    break;
                }
                case '3':
                {
                    cout << "Exiting..." << endl;
                    flag = false;
                    break;
                }
                default:
                {
                    cout << "Invalid Choice" << endl;
                }
                }
            }
        }
        else
        {
            cout << "Wrong credentials, try again!!\n";
        }
    }
    return 0;
}
