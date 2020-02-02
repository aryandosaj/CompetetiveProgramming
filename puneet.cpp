
#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() { 

//        freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        double a,x;
        double b;
        cin>>x>>a>>b;
        double p = (a-x)*(a-x);
        double r = (p/b + b)*(0.5);
        cout<<(ll)(ceil(r))<<"\n";
    }
    return 0;
}