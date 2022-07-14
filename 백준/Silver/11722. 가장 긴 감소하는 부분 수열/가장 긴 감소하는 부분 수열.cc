#include <iostream>

const int MAX_N = 1000;

int get_max_length(const int* arr, const int len)
{
    int max_length = arr[1];
    for (int i=2; i<=len; i++)
    {
        if (arr[i] > max_length)
        {
            max_length = arr[i];
        }
    }

    return max_length;
}

int main()
{
    int num;
    std::cin >> num;

    int arr[MAX_N+1] = {0};
    int lds[MAX_N+1];

    for (int i=1; i<=num; i++)
    {
        std::cin >> arr[i];
    }

    for (int i=1; i<=num; i++)
    {
        lds[i] = 1;

        for (int j=1; j<i; j++)
        {
            if (arr[j] > arr[i])
            {
                lds[i] = std::max(lds[i], lds[j]+1);
            }
        }
    }

    std::cout << get_max_length(lds, num);
    
    return 0;
}