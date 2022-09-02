#include <iostream>
#include <windows.h>
#include <time.h>
#include <string.h>
using namespace std;
const int MAX = 27;

char printRandomString()
{
    char alphabet[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z', ' '};
    return alphabet[rand() % MAX];
}

int patt_match(char ss[], char ms[], int m, int n)
{
    for (int i = 0; i <= n - m; i++)
    {
        Sleep(.5);
        int j = 0;
        while (j < m && ss[j] == ms[i + j])
            j++;
        if (j == m)
            return 1;
    }
    return 0;
}

int main()
{
    int len1, len2;
    int k;
    cout << "\nenter the length of string :";
    cin >> len1;
    char ms[len1];
    for (int i = 0; i < len1; i++)
    {
        ms[i] = printRandomString();
    }
    for (int i = 0; i < len1; i++)
    {
        cout << ms[i];
    }
    cout << "\n enter the length of substring:";
    cin >> len2;
    char ss[len2];
    cout << "\n enter substring :" << endl;
    for (int i = 0; i < len2; i++)
    {
        cin >> ss[i];
    }
    int s = clock();
    k = patt_match(ss, ms, len2, len1);
    int e = clock();
    if (k == 1)
        cout << "pattern found";
    else
        cout << "pattern not found";
    cout << "\nTime: " << (double)(e - s) / CLOCKS_PER_SEC << "s";
}