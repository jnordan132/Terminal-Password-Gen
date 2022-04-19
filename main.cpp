#include <iostream>
using namespace std;

// randomly generate a integer in the range 1 to 4
int selectArray()
{
    srand(time(NULL));
    int i = rand() % 5;
    if (i == 0)
        i++;
    return i;
}

// randomly generate an integer in the range 0 to 25
int getKey()
{
    srand(time(NULL));

    int key = rand() % 26;
    return key;
}

void generate_password(int length)
{
    // Intializing result string.
    string password = "";

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string s_symbol = "!@#$%&";
    string number = "0123456789";
}