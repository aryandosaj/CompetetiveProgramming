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
bool isprime(ll n)
{
    ll flag = 0;
    ll root = sqrt(n);
    for (ll i = 2; i <= root; i++)
    {
        if (n % i == 0)
        {
            flag = 1;
            return 0;
        }
    }
    return 1;
}
map<int, int> vis;
vector<int> graph[51];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (vis[graph[u][i]] == 0)
            dfs(graph[u][i]);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int chek[6] = {29, 31, 37, 41, 43, 47};
    int t;
    cin >> t;
    while (t--)
    {
        map<ll, ll> mp;
        int n;
        cin >> n;
        int arr[n];
        int ans = 0;
        int big = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] > 50)
                big++;
            mp[arr[i]]++;
        }
        if(n==1)
        {
            cout<<"0\n"<<arr[0]<<"\n";
            continue;
        }
        if ((mp[29] >= 1) || (mp[31] >= 1) || (mp[37] >= 1) || (mp[41] >= 1) || (mp[43] >= 1) || (mp[47] >= 1))
        {
            int flag = 0;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] != arr[i + 1])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                arr[0] = 2;
                ans++;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] > 50)
                        arr[i] = 2, ans++;
                }
            }
        }
        else
        {
            if (big > 0)
            {
                if (big != n)
                    for (int i = 0; i < n; i++)
                    {
                        if (arr[i] > 50)
                            arr[i] = 29, ans++;
                    }
                else
                {
                    arr[0] = 29;
                    for (int i = 1; i < n; i++)
                    {
                        arr[i] = 2;
                    }
                    ans = n;
                }
            }
            else
            {
                int flag = 0;
                for (int i = 0; i < n - 1; i++)
                {
                    if (arr[i] != arr[i + 1])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    arr[0] = 29;
                    ans++;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        for (int j = i + 1; j < n; j++)
                        {
                            if (__gcd(arr[i], arr[j]) == 1)
                                graph[i].push_back(j), graph[j].push_back(i);
                        }
                    }
                    int comp = 0;
                    for (int i = 0; i < n; i++)
                    {
                        if (vis[i] == 0)
                        {
                            comp++;
                            dfs(i);
                        }
                    }
                    // cout << comp << "ksubv";
                    if (comp > 1)
                        arr[0] = 29, ans++;
                }
            }
        }
        cout << ans << "\n";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < 51; i++)
        {
            graph[i].clear();
        }
        vis.clear();
    }
}