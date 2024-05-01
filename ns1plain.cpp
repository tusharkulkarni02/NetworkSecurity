#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

string file = "pass.txt";
int key = 5;

char pin[100];

string user;
string pass;

string def_user = "admin";
string def_pass = "admin";

void change_pass()
{
    fstream fout;

    fout.open("pass.txt", fstream::out);

    int k = 0;
    cout << "Enter  password : ";
    while (pin[k - 1] != '\r')
    {
        pin[k] = getch();
        int temp = (pin[k] - key);
        ;
        fout << (char)temp;
        if (pin[k - 1] != '\r')
        {
            cout << "*";
        }
        k++;
    }
    pin[k - 1] = '\0';
    pass = pin;
    fout.close();
    cout << "\nYou entered : " << pin << endl;
    cout << "File saved\n";
}

void view_pass()
{
    fstream fin;
    char c;
    fin.open("pass.txt", fstream::in);
    while (fin >> noskipws >> c)
    {

        int temp = (c + key);
        cout << (char)temp;
    }
    cout << "Your password: \n";
    cout << pass << endl;
}

int main()
{
    cout << "Enter your username: \n";
    cin >> user;
    cout << "Enter your password: \n";
    cin >> pass;

    if (user == def_user && pass == def_pass)
    {
        cout << "Login successfull!!\n";
        for (int i = 0; i < 10; i++)
        {
            char c;
            cout << "Enter your choice: \n";
            cout << "1. Change password \n";
            cout << "2. View password \n";
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
            }
        }
    }
}

/* #include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // for getch(), assuming you're on a Windows platform
using namespace std;

string file = "pass.txt";
int key = 5;

string def_user = "admin";
string def_pass = "admin";

string encryptDecrypt(string toEncrypt) {
    char key = 5; // Any value
    string output = toEncrypt;
    for (int i = 0; i < toEncrypt.size(); i++)
        output[i] = toEncrypt[i] ^ key;
    return output;
}

void change_pass() {
    string new_pass;
    cout << "Enter new password: ";
    getline(cin, new_pass);

    // Encrypt the password before saving
    ofstream fout(file);
    fout << encryptDecrypt(new_pass);
    fout.close();
    cout << "Password changed successfully!" << endl;
}

void view_pass() {
    string password;
    ifstream fin(file);
    getline(fin, password);
    fin.close();

    // Decrypt the password before displaying
    cout << "Your password: " << encryptDecrypt(password) << endl;
}

int main() {
    string user, pass;
    cout << "Enter your username: ";
    cin >> user;
    cout << "Enter your password: ";
    cin >> pass;

    if (user == def_user && pass == def_pass) {
        cout << "Login successful!!" << endl;
        while (true) {
            char choice;
            cout << "Enter your choice: \n";
            cout << "1. Change password\n";
            cout << "2. View password\n";
            cout << "3. Exit\n";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case '1':
                    change_pass();
                    break;
                case '2':
                    view_pass();
                    break;
                case '3':
                    cout << "Exiting...";
                    return 0;
                default:
                    cout << "Invalid choice!" << endl;
            }
        }
    } else {
        cout << "Incorrect username or password. Login failed!" << endl;
    }

    return 0;
}
*/
