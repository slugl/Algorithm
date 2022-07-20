#include <iostream>

using namespace std;

const int MAX = 8;
int sequence[MAX+1] = {0};

void backtrack (int depth, int n, int k, int start)
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
        for (int i=start; i<=n; i++)
        {
            sequence[depth] = i;
            backtrack(depth + 1, n, k, i + 1);
        }
    }
}

void combination (int n, int k)
{
    backtrack(0, n, k, 1);
}

int main ()
{
    int N, K;
    cin >> N >> K;

    combination(N, K);

    return 0;
}
