#include <iostream>
using namespace std;

//swap content of a and b
void swapping(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void display(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
        cout << endl;
    }
}

void merge(int *array, int l, int m, int r)
{
    int i, j, k, nl, nr;
    //size of left and right sub-arrays
    nl = m - l + 1; 
    nr = r - m;
    //temp arrays
    int larr[nl], rarr[nr];

    //Fill left and right sub-arrays
    for (i = 0; i < nl; i++)
    {
        larr[i] = array[l + i];
    }

    for (j = 0; j < nr; j++)
    {
        rarr[j] = array[m + 1 + j];
    }

    i = 0; j = 0; k = l;

    //merge temp arrays to real array
    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        {
            array[k] = larr[i];
            i++;
        }
        else
        {
            array[k] = rarr[k];
            j++;
        }
        k++;
    }

    //add element to left array
    while (i < nl)
    {
        array[k] = larr[i];
        i++;
        k++;
    }

    //add element tot right array
    while (j < nr)
    {
        array[k] = rarr[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int l, int r)
{
    int m;

    if (l < r)
    {
        int m = l + (r - l) / 2;

        //sort first and second arrays
        mergeSort(array, l, m);
        mergeSort(array, m + l, r);
        merge(array, l, m, r);
    }
}

int main()
{
    int arr[] = { 22, 47, 1, 98, 12 };
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array: \n";
    display(arr, size);
    return 0;
}