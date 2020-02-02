#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
#define MAX 2000005

vector<pair<ll,ll>> factors[2000005]; 
ll dp[2000005];
ll pre[2000005];
void sieveOfEratothenese() 
{ 

    bool isPrime[MAX]; 
    memset(isPrime, true, sizeof(isPrime)); 
    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i < MAX; i++) 
    {  
        if (isPrime[i]) 
        { 
            for (int j = i; j < MAX; j += i) 
            { 
                int k, l; 
                isPrime[j] = false; 
                for (k = j, l = 0; k % i == 0; l++, k /= i) 
                    ; 
                factors[j].push_back(make_pair(i, l)); 
            } 
        } 
    } 
} 
int sumOfProperDivisors(int num) 
{ 
    if(dp[num]!=0)return dp[num];
    int mul = 1; 
    for (int i = 0; i < factors[num].size(); i++) 
        mul *= ((pow(factors[num][i].first, 
                     factors[num][i].second + 1) - 1) / 
                (factors[num][i].first - 1)); 
    return dp[num]= mul; 
} 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieveOfEratothenese();
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    long double a1 = 0, a2 = 0;
    for(ll i=1;i<=2000000;i++)
    {
        pre[i] = pre[i-1]+sumOfProperDivisors(i);
    }
    a1 = pre[r1]-pre[l1-1];
    a2 = pre[r2]-pre[l2-1];

    // for (ll i = l1; i <= r1; i++)
    // {
    //     a1 += sumOfProperDivisors(i);
    // }
    // for (ll i = l2; i <= r2; i++)
    // {
    //     a2 += sumOfProperDivisors(i);
    // }
    cout<<a1<<" "<<a2<<"\n";

    a1*=(1/((r1-l1+1)*1.0));
    a2*=(1/((r2-l2+1)*1.0));
    // cout<<a1<<" "<<a2<<"\n";
    if (a1 > a2)
        cout << "A";
    else if (a2 > a1)
        cout << "B";
    else
        cout << "Draw";
}