#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string encrypt(string plaintext, string key)
{
  int row = key.length();
  int col = plaintext.length() / row;
  if (plaintext.length() % row != 0)
    col++;

  vector<vector<char>> matrix(row, vector<char>(col, '*'));

  int k = 0;
  for (int i = 0; i < col; i++)
  {
    for (int j = 0; j < row; j++)
    {
      if (k < plaintext.length())
        matrix[j][i] = plaintext[k++];
    }
  }

  vector<int> order(row);
  for (int i = 0; i < row; i++)
    order[i] = i;

  sort(order.begin(), order.end(), [&key](int a, int b)
       { return key[a] < key[b]; });

  string ciphertext;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (matrix[order[i]][j] != '*')
        ciphertext += matrix[order[i]][j];
    }
  }

  return ciphertext;
}

string decrypt(string ciphertext, string key)
{
  int row = key.length();
  int col = ciphertext.length() / row;

  vector<vector<char>> matrix(row, vector<char>(col, '*'));

  vector<int> order(row);
  for (int i = 0; i < row; i++)
    order[i] = i;

  sort(order.begin(), order.end(), [&key](int a, int b)
       { return key[a] < key[b]; });

  int k = 0;
  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < col; j++)
    {
      if (k < ciphertext.length())
        matrix[order[i]][j] = ciphertext[k++];
    }
  }

  string plaintext;
  for (int i = 0; i < col; i++)
  {
    for (int j = 0; j < row; j++)
    {
      if (matrix[j][i] != '*')
        plaintext += matrix[j][i];
    }
  }

  return plaintext;
}

int main()
{
  string plaintext, key;

  cout << "Enter the plaintext: ";
  getline(cin, plaintext);

  cout << "Enter the key: ";
  getline(cin, key);

  string ciphertext = encrypt(plaintext, key);
  cout << "Ciphertext: " << ciphertext << endl;

  string decryptedtext = decrypt(ciphertext, key);
  cout << "Decrypted text: " << decryptedtext << endl;

  return 0;
}