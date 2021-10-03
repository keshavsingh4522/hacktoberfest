#include <iostream>
using namespace std;

int main()
{
	int arr[1000] = {}, n = 0, i, j;
	int choice;
	while (choice != 8)
	{

		cout << "MENU\n";
		cout << "1. CREATE\n";
		cout << "2. DISPLAY\n";
		cout << "3. INSERT\n";
		cout << "4. DELETE\n";
		cout << "5. SORT\n";
		cout << "6. LINEAR SEARCH\n";
		cout << "7. BINARY SEARCH\n";
		cout << "8. EXIT\n";
		cout << "Your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			cout << "Enter number of elements in array:\n";
			cin >> n;
			cout << "Enter the elements of array:\n";
			for (i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			cout << "Array Created!!!\n\n";
			break;
		}
		case 2:
		{
			cout << "Elements of array:\n";
			for (i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n\n";
			break;
		}
		case 3:
		{
			int pos, ele;
			cout << "Enter element to be inserted:\n";
			cin >> ele;
			cout << "Enter position at which element to be inserted:\n";
			cin >> pos;

			if (pos > n)
			{
				cout << "Invalid Input\n\n";
			}
			else
			{
				for (i = n; i >= pos; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[pos - 1] = ele;
				n++;
				cout << "Element " << ele << " inserted at positon " << pos << endl;
				cout << "Array after insertion is:\n";
				for (i = 0; i < n; i++)
				{
					cout << arr[i] << " ";
				}
				cout << "\n\n";
			}
			break;
		}
		case 4:
		{
			int pos;
			cout << "Enter position of element to be deleted:\n";
			cin >> pos;

			if (pos > n)
			{
				cout << "Invalid Input\n\n";
			}
			else
			{
				for (i = pos - 1; i < n - 1; i++)
				{
					arr[i] = arr[i + 1];
				}
				n--;
				cout << "Array after deletion is:\n";
				for (i = 0; i < n; i++)
				{
					cout << arr[i] << " ";
				}
				cout << "\n\n";
			}
			break;
		}
		case 5:
		{
			int min, temp;
			for (i = 0; i < n; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (arr[i] > arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			cout << "Array after sorting is:\n";
			for (i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n\n";
			break;
		}
		case 6:
		{
			int ele, pos;
			int ans = 0;
			cout << "Enter element to be searched:\n";
			cin >> ele;
			for (i = 0; i < n; i++)
			{
				if (arr[i] == ele)
				{
					ans = 1;
					pos = i + 1;
					break;
				}
			}
			if (ans == 1)
			{
				cout << "Element " << ele << " found at position " << pos << endl;
			}
			else
			{
				cout << "Element not found!!!" << endl;
			}

			break;
		}
		case 7:
		{
			int ele, pos, start = 0, end = n - 1, middle;
			int ans = 0;
			cout << "Enter element to be searched:\n";
			cin >> ele;
			int min, temp;
			for (i = 0; i < n; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (arr[i] > arr[j])
					{
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			cout << "Array after sorting is:\n";
			for (i = 0; i < n; i++)
			{
				cout << arr[i] << " ";
			}
			cout << "\n\n";
			while (start <= end)
			{
				middle = start + (end - start) / 2;
				if (arr[middle] == ele)
				{
					ans = 1;
					pos = middle + 1;
					break;
				}
				else if (arr[middle] > ele)
				{
					end = middle - 1;
				}
				else if (arr[middle] < ele)
				{
					start = middle + 1;
				}
			}
			if (ans == 1)
			{
				cout << "Element " << ele << " found at position " << pos << endl;
			}
			else
			{
				cout << "Element not found!!!" << endl;
			}
			break;
		}
		case 8:
		{
			break;
		}
		default:
		{
			cout << "Wrong Choice! Please Try Again....\n\n";
			break;
		}
		}
	}
}
