#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i, j, k;
    string s, t;
    int key = 3;

    cout << "Enter the encrypted message\n";
    cin >> s;

    for (i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            t += (char)(((c - base + 26 - key) % 26) + base);
        }
        else
        {
            t += c; // Non-alphabetic character, leave unchanged
        }
    }

    cout << "\n\nDecrypted message is " << t << '\n';

    return 0;
}