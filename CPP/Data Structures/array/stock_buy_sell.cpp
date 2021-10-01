#include <bits/stdc++.h>
using namespace std;

int stock(int price[], int n)
{
    int profit = 0;
    //simple soln: buy low of low and sell at high of high :)
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
            profit += price[i] - price[i - 1];
    }
    return profit;
}
int main()
{
    int price[] = {1, 5, 3, 8, 12};
    int n = sizeof(price) / sizeof(price[0]);
    cout << stock(price, n);
}