#include <iostream>

using namespace std;

const int MAX = 8;
int sequence[MAX+1] = {0};
int used[MAX+1] = {0};

void backtrack (int depth, int n, int k)
{
    if (depth == k)
    {
        for (int i=0; i<depth; i++)
        {
            cout << sequence[i] << " ";
        }
        cout << '\n';
        return;
    }
    else
    {
        for (int i=1; i<=n; i++)
        {
            if (!used[i])
            {
                used[i] = 1;
                sequence[depth] = i;
                backtrack(depth + 1, n, k);
                used[i] = 0;
            }
        }
    }
}

void permutation (int n, int k)
{
    backtrack(0, n, k);
}

int main ()
{
    int N, K;
    cin >> N >> K;

    permutation(N, K);

    return 0;
}
