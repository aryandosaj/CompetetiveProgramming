#include <bits/stdc++.h>
using namespace std;
int m, n;
int *arr = new int[100009];
vector<int> ansvec;
int ans = 0;

int findans(int i, int sum, vector<int> v, int **dp)
{
    if (i == n)
    {
        if (sum > ans && sum <= m)
        {
            ansvec.clear();
            for (int j = 0; j < v.size(); j++)
            {
                ansvec.push_back(v.at(j));
            }
            ans = sum;
        }
        else
        {
            sum = -1;
        }

        v.clear();

        return sum;
    }

    if (dp[sum][i] > -1)
    {
        return dp[sum][i];
    }

    int op1 = findans(i + 1, sum, v, dp);
    v.push_back(i);
    int op2 = findans(i + 1, sum + arr[i], v, dp);

    dp[sum][i] = max(op1, op2);

    return max(op1, op2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    int **dp = new int*[5000];
    for (int i = 0; i < 5000; i++)
    {
        dp[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> v;
    int ignore = findans(0, 0, v, dp);

    cout << ansvec.size() << "\n";
    // cout<<ans<<"\n";
    sort(ansvec.begin(), ansvec.end());
    for (int i = 0; i < ansvec.size(); i++)
    {
        cout << ansvec.at(i) << " ";
    }

    return 0;
}