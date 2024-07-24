#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)x.size())
#define all(p) p.begin(), p.end()
#define double long double
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl;
const int mod = 10000;

int JumpSolve(int index, vector<int> &arr, vector<int> &dp)
{

    if (index == 0)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    int right = INT_MAX;
    int left = JumpSolve(index - 1, arr, dp) + abs(arr[index] - arr[index - 1]);
    if (index > 1)
    {
        right = JumpSolve(index - 2, arr, dp) + abs(arr[index] - arr[index - 2]);
    }

    return dp[index] = min(left, right);
}

void FrognJump()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    vector<int> dp(n + 1, -1);
    cout << JumpSolve(n - 1, arr, dp) << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        FrognJump();
    }
}
