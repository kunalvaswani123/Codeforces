#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll L=1e5+5;
#define pb push_back
vector<ll>ad[L];
vector<ll>adtemp[L];
vector<ll>ad2[L];
ll selected[L];
ll wanted[L];
ll check[L];
ll indegree[L];
ll visited1[L];
ll rec[L];
ll cyclicdfs(ll ind)
{
	ll i;
	visited1[ind]=1;
	rec[ind]=1;
	for(i=0;i<ad2[ind].size();i++)
	{
		if(rec[ad2[ind][i]]==1){
			return 1;
		}
		if(visited1[ad2[ind][i]]==0&&cyclicdfs(ad2[ind][i])==1){
			return 1;
		}
	}
	rec[ind]=0;
	return 0;
}
ll visited2[L];
queue<ll>q;
void dfs2(ll ind)
{
	ll i;
	visited2[ind]=1;
	for(i=0;i<adtemp[ind].size();i++)
	{	
		ad2[ind].pb(adtemp[ind][i]);
		if(visited2[adtemp[ind][i]]==0){
			dfs2(adtemp[ind][i]);
		}
	}
	q.push(ind);
	check[ind]=1;
	wanted[ind]++;
}
ll visited3[L];
priority_queue<ll,vector<ll>,greater<ll> >vertices;
void topsort()
{
	ll i;
	while(!vertices.empty())
	{
		ll a=vertices.top();
		cout<<a<<' ';
		vertices.pop();
		for(i=0;i<ad[a].size();i++)
		{
			indegree[ad[a][i]]--;
			if(indegree[ad[a][i]]==0)
			{
				if(wanted[ad[a][i]]==1)
					vertices.push(ad[a][i]);
			}
		}
	}
}
int main()
{
	ll i,n,m,k,j;
	cin>>n>>m>>k;
	for(i=0;i<m;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		indegree[v]++;
		adtemp[v].pb(u);
	}
	ll siz=0;
	for(i=0;i<k;i++)
	{
		ll a;
		cin>>a;
		selected[siz++]=a;
		check[a]=1;
	}
	for(i=0;i<siz;i++)
	{
		if(visited2[selected[i]]==0){
			if(indegree[selected[i]]!=0)
				dfs2(selected[i]);
			else{
				q.push(selected[i]);
				wanted[selected[i]]++;
				visited2[selected[i]]=1;
			}
		}
	}
	for(i=0;i<siz;i++)
	{
		if(visited1[selected[i]]==0&&cyclicdfs(selected[i])==1){
			cout<<"GO HOME RAJAS"<<endl;
			return 0;
		}
	}
	cout<<q.size()<<endl;
	while(!q.empty())
	{
		ll x=q.front();
		if(visited3[x]==0&&wanted[x]==1&&indegree[x]==0)
			vertices.push(x);
		q.pop();
	}
	topsort();
	cout<<endl;
	return 0;
}