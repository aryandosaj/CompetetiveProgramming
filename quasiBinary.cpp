#include <bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
using namespace std;
struct ind
{
    ll val;
    ll in;
};
bool mycomparator(ind a,ind b)
{
    return a.val<b.val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //code start here
    ind arr[7];
    ll n;
    cin>>n;
    ll m=0;
    ll num;
    ll i=0;
    while(n>0)
    {

        num=n%10;
        arr[i].val=num;
        arr[i].in=i++;
        m= max(m,num);
        n=n/10;
    }
    sort(arr,arr+n,mycomparator);
    
    cout<<m;
    

}