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

    // initializing local variables
    int key, count_alphabet = 0, count_ALPHABET = 0, count_number = 0, count_s_symbol = 0;

    // Count will store the length of the password being created,
    // initially this will be zero(0)
    int count = 0;
    while (count < length)
    {

        int k = selectArray();

        if (count == 0)
        {
            k = k % 3;
            if (k == 0)
                k++;
        }
        switch (k)
        {
        case 1:
            if ((count_alphabet == 2) && (count_number == 0 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_s_symbol == 0))
                break;

            key = getKey();
            password = password + alphabet[key];
            count_alphabet++;
            count++;
            break;

        case 2:
            if ((count_ALPHABET == 2) && (count_number == 0 || count_alphabet == 0 || count_alphabet == 1 || count_s_symbol == 0))
                break;
            key = getKey();
            password = password + ALPHABET[key];
            count_ALPHABET++;
            count++;
            break;

        case 3:
            if ((count_number == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 1 || count_ALPHABET == 0 || count_s_symbol == 0))
                break;

            key = getKey();
            key = key % 10;
            password = password + number[key];
            count_number++;
            count++;
            break;

        case 4:
            if ((count_s_symbol == 1) && (count_alphabet == 0 || count_alphabet == 1 || count_ALPHABET == 0 || count_ALPHABET == 1 || count_number == 0))
                break;

            key = getKey();
            key = key % 6;
            password = password + s_symbol[key];
            count_s_symbol++;
            count++;
            break;
        }
    }

    cout << "\n-----------------------------\n";
    cout << "         PASSWORD             \n";
    cout << "------------------------------\n\n";
    cout << " " << password;
    cout << "\n\nPress any key continue \n";
    getchar();
}