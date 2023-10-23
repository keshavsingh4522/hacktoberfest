#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX 100

int arr[MAX];
int size = -1;

void create(int val)
{
    if (size < MAX)
    {
        size++;
        arr[size] = val;
    }
    else
    {
        printf("Array is full.\n");
    }
}

void delete(int pos)
{
    int index = pos - 1;
    if (index < 0 || index > size)
    {
        printf("Invalid Position.\n");
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void insert(int inspos, int insval)
{
    if (inspos > size + 1)
    {
        printf("Invalid Position.\n");
    }
    else
    {
        size++;
        for (int i = size; i >= inspos; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[inspos] = insval;
    }
}

void replace(int repos, int repval)
{
    if (repos >= 0 && repos <= size)
    {
        arr[repos] = repval;
    }
    else
    {
        printf("Invalid Position.\n");
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertion_sort()
{
    int key, j;
    for (int i = 1; i <= size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubble_sort()
{
    bool swapped;
    for (int i = 0; i <= size; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

void selection_sort()
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j <= size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Quick Sort Starts
int partition(int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quick_sort(low, pi - 1);
        quick_sort(pi + 1, high);
    }
}
// Quick Sort Ends

// Merge Sort Starts
void merge(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        merge_sort(l, m);
        merge_sort(m + 1, r);
        merge(l, m, r);
    }
}
// Merge Sort Ends

// Heap Sort Starts
void heapify(int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(N, largest);
    }
}

void heap_sort(int N)
{
    for (int i = N / 2 - 1; i >= 0; i++)
    {
        heapify(N, i);
    }
    for (int i = N - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}

// Heap Sort Ends

void randomize()
{
    srand(time(NULL));

    for (int i = 0; i <= size; i++)
    {
        int randomIndex = rand() % (size + 1);
        swap(&arr[i], &arr[randomIndex]);
    }
}

void display()
{
    if (size == -1)
    {
        printf("Array is Empty.\n");
    }
    else
    {
        printf("\n|");
        for (int i = 0; i <= size; i++)
        {
            printf(" %d |", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    while (true)
    {
        int choice;
        printf("\n\n**Array Menu For Operations**\n\n");
        printf("1.  Insert\n");
        printf("2.  Delete value from a Specific Position\n");
        printf("3.  Display the Array\n");
        printf("4.  Insert a Value at a Specified Position\n");
        printf("5.  Replace a Value from a specified position in the array\n");
        printf("6.  Sorting\n");
        printf("7.  Randomize the Array\n");
        printf("0.  Exit the Program\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int value, nos;
            printf("Enter Number of Elements: ");
            scanf("%d", &nos);
            for (int i = 0; i < nos; i++)
            {
                printf("Enter the Value: ");
                scanf("%d", &value);
                create(value);
            }
            display();
            break;

        case 2:
            if (size == -1)
            {
                printf("\nArray is Empty\n");
            }
            else
            {
                int delpos;
                display();
                printf("\nEnter the Position of the Value You want to delete: ");
                scanf("%d", &delpos);
                delete (delpos);
                display();
            }
            break;

        case 3:
            display();
            break;

        case 4:
            int inspos;
            printf("\nEnter the Position you would like the value to be inserted: ");
            scanf("%d", &inspos);
            printf("Enter the Value: ");
            scanf("%d", &value);
            insert(inspos, value);
            display();
            break;

        case 5:
            int repos;
            printf("\nEnter the Position of the Value You want to replace: ");
            scanf("%d", &repos);
            printf("Enter the New Value: ");
            scanf("%d", &value);
            replace(repos, value);
            display();
            break;

        case 6: // Sorting submenu
            int sortChoice;
            printf("\n**Sorting Menu**\n\n");
            printf("1. Insertion Sort\n");
            printf("2. Bubble Sort\n");
            printf("3. Selection Sort\n");
            printf("4. Quick Sort\n");
            printf("5. Merge Sort\n");
            printf("6. Heap Sort\n");
            printf("0. Back to Main Menu\n");
            printf("\nEnter Your Sorting Choice: ");
            scanf("%d", &sortChoice);

            switch (sortChoice)
            {
            case 1:
                display();
                insertion_sort();
                printf("\nThe Sorted Array in Ascending Order: \n");
                display();
                break;

            case 2:
                display();
                bubble_sort();
                printf("\nThe Sorted Array in Ascending Order: \n");
                display();
                break;

            case 3:
                display();
                selection_sort();
                printf("\nThe Sorted Array in Ascending Order: \n");
                display();
                break;

            case 4:
                display();
                quick_sort(0, size);
                printf("\nThe Sorted Array in Ascending Order: \n");
                display();
                break;

            case 5:
                display();
                merge_sort(0, size);
                printf("\nThe Sorted Array in Ascending Order: \n");
                display();
                break;

            case 6:
                display();
                heap_sort(size + 1);
                printf("\nThe Sorted Array in Ascending Order: \n");
                display();
                break;

            case 0:
                break;

            default:
                printf("Invalid Sorting Choice. Try Again\n");
            }
            break;

        case 7:
            randomize();
            printf("\nRandomized array:\n");
            display();
            break;

        case 0:
            exit(0);

        default:
            printf("Invalid Choice. Try Again\n");
            break;
        }
    }
    return 0;
}
