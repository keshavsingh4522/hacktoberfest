//contributed by : Priyansh Jha
#include <bits/stdc++.h>
using namespace std;

int ImplementAtoi(char* str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    return res;
}

// Driver code
int main()
{
    char str[] = "98784227";
   cout<<ImplementAtoi(str);
    return 0;
}
