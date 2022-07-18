#include <iostream>
#include <algorithm>

using namespace std;

char candy[51][51] = {0};

int get_max_adjacency(int size)
{
    int max_adjacency = 1;

    // for each row
    for (int i=0; i<size; i++)
    {
        int count = 1;
        for (int j=0; j<size; j++)
        {
            if (candy[i][j] == candy[i][j+1])
                count++;
            else
            {
                max_adjacency = max(max_adjacency, count);
                count = 1;
            }
        }
    }

    // for columns
    for (int i=0; i<size; i++)
    {
        int count = 1;
        for (int j=0; j<size; j++)
        {
            if (candy[j][i] == candy[j+1][i])
                count++;
            else
            {
                max_adjacency = max(max_adjacency, count);
                count = 1;
            }
        }
    }
    

    return max_adjacency;
}

int main ()
{
    int N;
    char temp;
    cin >> N;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            cin >> candy[i][j];
        }
    }

    int max_adjacency = 1;

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N-1; j++)
        {
            swap(candy[i][j], candy[i][j+1]);
            max_adjacency = max(max_adjacency, get_max_adjacency(N));
            swap(candy[i][j], candy[i][j+1]);

            swap(candy[j][i], candy[j+1][i]);
            max_adjacency = max(max_adjacency, get_max_adjacency(N));
            swap(candy[j][i], candy[j+1][i]); 
        }
    }

    cout << max_adjacency << endl;

    return 0;
}
