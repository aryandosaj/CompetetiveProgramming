#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
string b[20];
queue<vector<int> >q;
map<vector<int>,int>mp;
bool u[20][20];
void dfs(int x,int y)
{
	if(x<0 || x>=n || y<0 || y>=m || b[x][y]=='#' || u[x][y])
	{
		return;
	}
	u[x][y]=true;
	for(int i=0;i<4;i++)
	{
		dfs(x+dx[i],y+dy[i]);
	}
}
int main()
{
	cin>>n>>m;
	int k;
	vector<int>it;
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	for(k=0;;k++)
	{
		bool f=false;
		char c='1'+k;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(b[i][j]==c)
				{
					f=true;
					it.push_back(i);
					it.push_back(j); 
				}
			}
		}
		if(!f)
		{
			break;
		}
	}
	cnt=k;
	dfs(it[0],it[1]);
	bool can=false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(b[i][j]=='@' && u[i][j])
			{
				can=true;
			}
		}
	}
	if(!can)
	{
		cout<<-1<<endl;
		return 0;
	}
	q.push(it);
	mp[it]=0;
	while(!q.empty())
	{
		vector<int>v=q.front();
		q.pop();
		int d=mp[v];
		for(int i=0;i<4;i++)
		{
			int x=v[0]+dx[i],y=v[1]+dy[i];
			if(x<0 || x>=n || y<0 || y>=m || b[x][y]=='#')
			{
				continue;
			}
			bool bd=false;
			for(int i=0;i<cnt-1;i++)
			{
				if(x==v[2*i] && y==v[2*i+1])
				{
					bd=true;
				}
			}
			if(bd)
			{
				continue;
			}
			if(b[x][y]=='@')
			{
				cout<<d+1<<endl;
				return 0;
			}
			vector<int>w(2*cnt);
			w[0]=x;
			w[1]=y;
			for(int i=0;i<2*cnt-2;i++)
			{
				w[2+i]=v[i];
			}
			if(mp.find(w)==mp.end())
			{
				mp[w]=d+1;
				q.push(w);
			}
		}
	}
	// cout<<-1<<endl;
	return 0;
}