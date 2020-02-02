#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pll pair<ll, ll>
#define pb push_back
#define F first
#define S second
#define I insert
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int dp[201][201][201][2];
int arr[201][201];
int row[201][201];
int col[201][201];
int row1[201][201];
int col1[201][201];
int rec(int i, int j, int d, int t)
{
    if (dp[i][j][d][t] != -1)
        return dp[i][j][d][t];
    if (d == 0)
    {
        int temp = 0;

        if (t == 1)
        {
            if (((i + j)& 1) == 0)
                temp = 1 ^ arr[i][j];
            else
                temp = 0 ^ arr[i][j];
        }
        else
        {
            if (((i + j) & 1) == 0)
                temp = 0 ^ arr[i][j];
            else
                temp = 1 ^ arr[i][j];
        }
        return dp[i][j][d][t] = temp;
    }
    else
    {
        int temp = rec(i, j, d - 1, t);
        if (t == 1)
        {
            if (((i + j) & 1) == 0)
                temp += 1 ^ arr[i + d][j + d];
            else
                temp += 0 ^ arr[i + d][j + d];
            if (j == 0)
                temp += row1[i + d][j + d - 1];
            else
                temp += row1[i + d][j + d - 1] - row1[i + d][j - 1];
            if (i == 0)
                temp += col1[i + d - 1][j + d];
            else
                temp += col1[i + d - 1][j + d] - col1[i - 1][j + d];
            // temp+=row1[i+d][j+d-1]-row1[i+d][j-1]+col1[i+d-1][j+d]-col1[i-1][j+d];
        }
        else
        {
            if (((i + j) & 1) == 0)
                temp += 0 ^ arr[i + d][j + d];
            else
                temp += 1 ^ arr[i + d][j + d];
            if (j == 0)
                temp += row[i + d][j + d - 1];
            else
                temp += row[i + d][j + d - 1] - row[i + d][j - 1];
            if (i == 0)
                temp += col[i + d - 1][j + d];
            else
                temp += col[i + d - 1][j + d] - col[i - 1][j + d];
            // temp+=row[i+d][j+d-1]-row[i+d][j-1]+col[i+d-1][j+d]-col[i-1][j+d];
        }
        return dp[i][j][d][t] = temp;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 201; i++)
    {
        for (int j = 0; j < 201; j++)
        {
            for (int k = 0; k < 201; k++)
            {
                dp[i][j][k][0] = -1;
                dp[i][j][k][1] = -1;
            }
        }
    }

    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    int sum = 0;
    int x = 0, y = 0;
    ;
    for (int i = 0; i < n; i++)
    {
        x = y;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[i][j] - 48;
            sum += arr[i][j] ^ x;
            row[i][j] = sum;
            x ^= 1;
        }
        y = y ^ 1;
        sum = 0;
    }
    sum = 0;
    x = 0, y = 0;
    for (int i = 0; i < m; i++)
    {
        x = y;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j][i] ^ x;
            col[j][i] = sum;
            x ^= 1;
        }
        sum = 0;
        y = y ^ 1;
    }
    x = 1, y = 1;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        x = y;
        for (int j = 0; j < m; j++)
        {

            sum += arr[i][j] ^ x;
            row1[i][j] = sum;
            x ^= 1;
        }
        y = y ^ 1;
        sum = 0;
    }
    sum = 0;
    x = 1, y = 1;
    for (int i = 0; i < m; i++)
    {
        x = y;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j][i] ^ x;
            col1[j][i] = sum;
            x ^= 1;
        }
        y = y ^ 1;
        sum = 0;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {

    //         cout<<col[i][j]<<" ";

    //     }
    //     cout<<"\n";

    // }
    // int ans[201];
    int aaa[40002];
    for (int i = 0; i < 40002; i++)
    {
        aaa[i] = 0;
    }

    for (int d = 0; d < min(n, m); d++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i + d < n) && (j + d < m))
                { // ans[d] = min(ans[d],min(rec(i,j,d,1),rec(i,j,d,0)));
                    int r = min(rec(i, j, d, 1), rec(i, j, d, 0));
                    aaa[r] = max(aaa[r], d + 1);
                }
            }
        }
    }
    // cout<<rec(2,0,5,1)<<" ";
    // sum = 0;
    int last = 0;
    for (int i = 0; i < n * m; i++)
    {
        last = max(last, aaa[i]);
        aaa[i] = last;
        // cout << aaa[i] << " ";
    }
    int q;
    cin >> q;
    while (q--)
    {
        int dd;
        cin >> dd;
        if (dd >= (n * m))
            cout << min(n, m) << "\n";
        else
            cout << aaa[dd] << "\n";
    }
}