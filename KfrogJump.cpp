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

int HelperKfrog(int index, int k, vector<int> &arr, vector<int> &dp)
{
    if (index == 0)
    {
        return 0;
    }

    if (dp[index] != -1)
        return dp[index];

    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (index - i >= 0)
        { // make sure index-i is not negative
            int res = HelperKfrog(index - i, k, arr, dp) + abs(arr[index] - arr[index - i]);
            ans = min(ans, res);
        }
    }
    return dp[index] = ans;
}

void kFrogJump()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr)
    {
        cin >> it;
    }
    int k;
    cin >> k;
    vector<int> dp(n + 1, -1);
    cout << HelperKfrog(n - 1, k, arr, dp);
}

int32_t main()
{
    kFrogJump();
}