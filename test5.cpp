#include<bits/stdc++.h>
using namespace std;
#define S second
const double pi=acos(-1.0);

typedef long long int ll;
int main(){
	int n;scanf("%d",&n);
	map<ll,ll> mp;
	mp[0]=0;
	while(n--){
		int r,h;scanf("%d%d",&r,&h);
		ll v=1LL*r*r*h;
		auto it=mp.lower_bound(v);--it;
		ll th=mp[v]=max(mp[v],it->S+v);
		it = mp.upper_bound(v);
		while(it!=mp.end()&&it->S<th)it=mp.erase(it);
	}
	printf("%.8f\n",pi*(mp.rbegin()->S));
}