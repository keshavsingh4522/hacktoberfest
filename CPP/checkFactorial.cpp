bool checkFactorial(int n) {
    int fact=1;
    int i=1;
    while (fact <= n)
    {
        fact = fact * i;
        i++;
        if (n-fact ==0)
        return true;
    }
    return false;

}
