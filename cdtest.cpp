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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string A;
    cin>>A;
    stack<char>st;
    stack<char>st1;
    int l = A.length();
    for(int i=0;i<l;i++)
    {
        if(A[i]=='(')
        {
            int c=0;
            while(A[i]=='(')c++,i++;
            i--;
            st.push(c);
        }
         
    }
    reverse(A.begin(),A.end());
    for(int i=0;i<l;i++)
    {
        if(A[i]==')')
        {
            int c=0;
            while(i<l&&A[i]==')')c++,i++;
            i--;
            st1.push(c);
        }

    }
    ll f=0;
    while(!st.empty())
    {
        
        int c1 = st.top();
        int c2 = st1.top();
        cout<<c1<<" "<<c2<<"\n";
        st.pop();st1.pop();
        if(min(c1,c2)>1)f= 1;
        if(c1>c2)
        {
            c1-=c2;
            st.push(c1);
        }
        else if(c2>c1)
        {
            c2-=c1;
            st1.push(c2);
        }
    }
    cout<<f;
    return 0;

}