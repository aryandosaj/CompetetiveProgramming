#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod){ ll c = 1; while(b>0){ if(b%2) c*=a, c%=mod; b/=2; a*=a; a%=mod; } return c; }
#define MAX 1000000007
int calculateMex(unordered_set<int> Set) 
{ 
    int Mex = 0; 
  
    while (Set.find(Mex) != Set.end()) 
        Mex++; 
  
    return (Mex); 
} 
int calculateGrundy (int n) 
{ 
    if (n == 0) 
        return (0); 
  
    unordered_set<int> Set;
  
    Set.insert(calculateGrundy(n/2)); 
    Set.insert(calculateGrundy(n/3)); 
    Set.insert(calculateGrundy(n/6)); 
    return (calculateMex(Set)); 
}
int main()
{
    
}