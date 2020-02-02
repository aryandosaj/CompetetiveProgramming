#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long int hor,ver;
};
bool compare(node n1,node n2)
{
    //return (abs(n1.hor)+(n1.ver))<(abs(n2.hor)+(n2.ver));
    return (abs(n1.hor)+abs(n1.ver))<(abs(n2.hor)+abs(n1.ver));
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n;
    cin>>n;
    node *arr=new node[n];
    long long int cnt=0;
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i].hor>>arr[i].ver;
        if(arr[i].hor==0||arr[i].ver==0)
        {
            cnt++;
        }
    }
 
    sort(arr,arr+n,compare);
 
    cout<<((6*n)-(2*cnt))<<"\n";
 
    for(long long int i=0;i<n;i++)
    {
        if(arr[i].hor>0)
        {
            cout<<"1 "<<arr[i].hor<<" "<<"R\n";
        }
        if(arr[i].ver>0)
        {
            cout<<"1 "<<arr[i].ver<<" "<<"U\n";
        }
        if(arr[i].hor<0)
        {
            cout<<"1 "<<abs(arr[i].hor)<<" "<<"L\n";
        }
        if(arr[i].ver<0)
        {
            cout<<"1 "<<abs(arr[i].ver)<<" "<<"D\n";
        }
 
        cout<<"2\n";
 
        if(arr[i].hor>0)
        {
            cout<<"1 "<<arr[i].hor<<" "<<"L\n";
        }
        if(arr[i].ver>0)
        {
            cout<<"1 "<<arr[i].ver<<" "<<"D\n";
        }
        if(arr[i].hor<0)
        {
            cout<<"1 "<<abs(arr[i].hor)<<" "<<"R\n";
        }
        if(arr[i].ver<0)
        {
            cout<<"1 "<<abs(arr[i].ver)<<" "<<"U\n";
        }
 
        cout<<"3\n";
    }
 
    return 0;
}