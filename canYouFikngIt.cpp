#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ll n, s, t;
    cin >> n >> s >> t;
    ll arr[n];
    ll temp;
    ll visit[n];
    map<ll, ll> ind;
    s--;t--;
    for (int i = 0; i < n; i++)
    {
        visit[i] = 0;
        cin >> temp;
        arr[i] = temp - 1;
        ind[arr[i]] = i;
    }
    ll steps = 0;
    ll index_of_ball = s;
    while (1)
    {
        if (visit[index_of_ball] == 0)
        {
            visit[index_of_ball] = 1;
            if (index_of_ball == t)
            {
                cout << steps;
                return 0;
            }
            else
            {
                steps++;
                index_of_ball = arr[index_of_ball];
            }
        }
        else
        {
            cout << "-1";
            return 0;
        }
    }
}