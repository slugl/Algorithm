#include <iostream>

const int MAX_N = 1000;

int main()
{
    int dp[MAX_N+1] = {0};
    int score[MAX_N+1] = {0};
    int num;
    std::istream::sync_with_stdio(false);

    std::cin >> num;

    for (int i=1; i<=num; i++)
    {
        std::cin >> score[i];
    }

    dp[1] = score[1];
    for (int i=2; i<=num; i++)
    {
        dp[i] = score[i];
        for (int j=1; j<i; j++)
        {
            if (score[j] < score[i])
            {
                dp[i] = std::max(dp[i], dp[j] + score[i]);
            }
        }
    }

    int result = 0;
    for (int i=1; i<=num; i++)
    {
        if (dp[i] > result)
        {
            result = dp[i];
        }
    }

    std::cout << result;

    return 0;
}