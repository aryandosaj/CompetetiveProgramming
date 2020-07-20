#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define f(a, b) for (ll i = a; i < b; i++)
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
ll n, d;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll arr[5005];
    ll brr[50];
    brr[0] = 0;
    f(1, 10)
        brr[i] = brr[i - 1] + i * pow(2, i);
    arr[1] = 0;
    f(2, 5005)
        arr[i] = arr[i - 1] + i - 1;
    while (t--)
    {
        cin >> n >> d;
        ll mx = arr[n];
        ll ii = -1;
        for (ll i = 15; i >= 0; i--)
            if (n & (1 << i))
            {
                ii = i - 1;
                break;
            }
        ll mi = brr[ii] + (n - (1 << (ii + 1)) + 1) * (ii + 1);
        // cout << " " << mx << " " << mi << "\n";
        if (d < mi || d > mx)
        {
            cout << "NO\n";
            continue;
        }
        map<ll, set<ll>> dep;
        map<ll, ll> child;
        map<ll, ll> parent;     
        f(1, n + 1)
            dep[i - 1]
                .insert(i),
            child[i] = 1, parent[i] = i - 1;
        child[n] = 0;
        ll req = mx - d;
        ll no=0;
        // f(0, 10)
        while (req > 0)
        {
            // cout << req << "\n";
            ll leaf = -1;
            ll flag = 0;

            ll de = -1;
            vll flag1;
            for (auto i : dep)
            {
                for (auto j : i.second)
                {
                    if (child[j] == 0 && i.first >= 2 && flag1[i.first - 2] == 1)
                    {
                        leaf = j;
                        de = i.first;
                        child[parent[j]]--;
                        break;
                    }
                    else if (child[j] < 2)
                        flag = 1;
                }
                if (leaf != -1)
                    break;
                flag1.pb(flag);
            }
            dep[de].erase(leaf);
            ll new_de = -1;
            for (auto i : dep)
            {
                if (i.first + 1 >= de)
                    break;
                if ((de - i.first - 1) > req)
                    continue;
                for (auto j : i.second)
                {
                    if (child[j] < 2)
                    {
                        child[j]++;
                        new_de = i.first + 1;
                        parent[leaf] = j;
                        req -= (de - i.first - 1);
                        break;
                    }
                }
                if (new_de != -1)
                    break;
            }
            if(new_de==-1)
            {
                no=1;
                break;
            }
            dep[new_de].insert(leaf);
            
            // cout << leaf << "\n";
            // f(2, n + 1) cout << parent[i] << " ";
            // cout << "\n";
        }
        if(no)
        {
            cout<<"NO\n";continue;
        }
        cout << "YES\n";
        f(2, n + 1) cout << parent[i] << " ";
        cout<<"\n";
    }
}