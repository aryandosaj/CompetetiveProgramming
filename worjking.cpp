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
int arr[1002][1002];
int arr_11[1002][1002] = {0};
int arr_nm[1002][1002] = {0};
int arr_n1[1002][1002] = {0};
int arr_1m[1002][1002] = {0};


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    // dijkstra_11(n, m);
    // dijkstra_nm(n, m);
    // dijkstra_n1(n, m);
    // dijkstra_1m(n, m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            arr_11[i][j] = arr[i][j] + max(arr_11[i - 1][j], arr_11[i][j - 1]);
    for (int j = m; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            arr_1m[i][j] = arr[i][j] + max(arr_1m[i - 1][j], arr_1m[i][j + 1]);
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= m; ++j)
            arr_n1[i][j] = arr[i][j] + max(arr_n1[i + 1][j], arr_n1[i][j - 1]);
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j)
            arr_nm[i][j] = arr[i][j] + max(arr_nm[i][j + 1], arr_nm[i + 1][j]);
    //  for(int i = 1; i <= n; i++)
    //    {for(int j = 1; j <= m; j++)
    //        cout<<arr_1m[i][j]<<" ";
    //     cout<<"\n";}
    int mm = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 2; j <= m-1; j++)
        {
            mm = max(mm, max(arr_11[i - 1][j] + arr_1m[i][j + 1] + arr_n1[i][j - 1] + arr_nm[i + 1][j], arr_11[i][j - 1] + arr_1m[i - 1][j] + arr_n1[i + 1][j] + arr_nm[i][j + 1]));
        }
    }
    cout << mm;
}