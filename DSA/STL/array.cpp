// array using stl function can do much more task and have a good library support

#include <iostream>
#include <array>

using namespace std;

int main()
{

    // declaration
    array<int, 4> a;
    // assigning values
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }
    // declaration and assigning value
    array<int, 4> arr = {1, 2, 3, 4};

    // printing the array
    for (int i = 0; i < 4; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // finding the size of the array
    cout << a.size() << " " << arr.size() << endl;

    // accessing any element at given potion
    cout << a[3] << " " << a.at(3) << endl;

    // checking if the array is empty
    cout << "Is array a empty ? " << a.empty() << endl;

    // excessing first and last element
    cout << arr.front() << " " << arr.back() << endl;

    return 0;
}