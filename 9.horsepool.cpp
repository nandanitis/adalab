#include <string.h>
#include <time.h>
#include <iostream>
#include <Windows.h>

using namespace std;
int st[27];

int horspool(char MS[], char SS[], int n, int m)
{
    int i = m - 1, k;
    while (i <= n - 1)
    {
        k = 0;
        while (k <= m - 1 && MS[i - k] == SS[m - 1 - k])
            k++;
        if (k == m)
            return 1;
        else
        {
            int z = MS[i] - 'a';
            i = i + st[z];
        }
    }
    return 0;
}
int main()
{
    clock_t s, e, d;
    char MS[1000], SS[100];
    int n, m, result;

    cout << "Enter length of main string\n";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int r = (rand() % 26) + 97;
        MS[i] = r;
    }

    for (int i = 0; i < n; i++)
        cout << MS[i];
    cout << endl;
    cout << "Enter sub string";
    cin >> SS;
    m = strlen(SS);
    for (int i = 0; i < 27; i++)
        st[i] = m;
    int index;
    for (int i = 0; i < m - 1; i++)
    {
        index = SS[i] - 'a';
        st[index] = m - 1 - i;
    }
    s = clock();
    result = horspool(MS, SS, n, m);
    e = clock();
    if (result == 1)
        cout << "Pattern Matched\n";
    else
        cout << "Patter Not Present";
    d = (e - s) / 1000;
    cout << "Time = " << d;
}