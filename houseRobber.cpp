#include <bits/stdc++.h>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////

// same for house robber

int noAdjecntElemetHelper(int index, vector<int> &arr, vector<int> &dp)
{
    if (index == 0)
    {
        return arr[index];
    }
    if (index < 0)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    int pick = noAdjecntElemetHelper(index - 2, arr, dp) + arr[index];
    int notPick = noAdjecntElemetHelper(index - 1, arr, dp) + 0;

    return dp[index] = max(pick, notPick);
}

int TabulationOfNoAdjecent(int n, vector<int> &arr, vector<int> &dp)
{
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        {
            pick += dp[i - 2];
        }
        int notPick = 0 + dp[i - 1];
        dp[i] = max(pick, notPick);
    }
    return dp[n - 1];
}

//////////////
// space optimazation of noAdjecntElemet

int spaceNoadjElement(int n, vector<int> &arr, vector<int> &dp)
{
    int prev = arr[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = arr[i];
        if (i > 1)
        { // not -ve index
            pick += prev2;
        }
        int notPick = prev;

        int curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

void noAdjecntElemet()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    vector<int> dp(n, -1);
    cout << spaceNoadjElement(n, arr, dp);
}

int32_t main()
{
    noAdjecntElemet();
}
