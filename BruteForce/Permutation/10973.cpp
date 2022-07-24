#include <iostream>

using namespace std;

const int MAX = 10000;

void swap (int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool prev_permutation (int* arr, int n)
{
    int i = n - 1;
    while (i > 0 && arr[i-1] < arr[i]) i--;

    if (i <= 0) return false;

    int j = n - 1;
    while (j >= i)
    {
        if (arr[j] < arr[i-1]) break;
        j--;
    }

    swap(arr[i-1], arr[j]);

    j = i;
    i = n - 1;
    while (j < i)
    {
        swap(arr[i], arr[j]);
        j++;
        i--;
    }

    return true;
}

int main ()
{
    int sequence[MAX + 1];
    int N;

    cin >> N;
    for (int i=0; i<N; i++)
    {
        cin >> sequence[i];
    }

    if (prev_permutation(sequence, N))
    {
        for (int i=0; i<N; i++)
        {
            cout << sequence[i] << ' ';
        }
    }
    else
    {
        cout << - 1;
    }

    return 0;
}
