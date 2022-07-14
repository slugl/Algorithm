#include <iostream>

const int MAX_N = 500;

int get_max(const int* arr, const int len)
{
    int result = arr[1];
    for (int i=2; i<=len; i++)
    {
        if (arr[i] > result)
            result = arr[i];
    }
    return result;
}

int main()
{
    int score[MAX_N+1][MAX_N+1] = {0};
    int dp[MAX_N+1][MAX_N+1] = {0};
    int N;
    std::istream::sync_with_stdio(false);
    std::cin >> N;

    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=i; j++)
        {
            std::cin >> score[i][j];
        }
    }

    dp[1][1] = score[1][1];

    for (int i=2; i<=N; i++)
    {
        dp[i][1] = dp[i-1][1] + score[i][1];
        dp[i][i] = dp[i-1][i-1] + score[i][i];

        for (int j=2; j<i; j++)
        {
            dp[i][j] = std::max(dp[i-1][j-1], dp[i-1][j]) + score[i][j];
        }
    }

    std::cout << get_max(dp[N], N);

    return 0;
}
