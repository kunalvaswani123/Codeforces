#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll L=1e5+5;
#define pb push_back
ll power[L];
vector<ll>ad[L];
ll ans=0;
ll visited1[L];
ll visited2[L];
ll global[L];
ll global1[L];
void dfs1(ll ind)
{
	visited1[ind]=1;
	ll i;
	for(i=0;i<ad[ind].size();i++)
	{
		if(visited1[ad[ind][i]]==0)
		{
			dfs1(ad[ind][i]);
			ll x=global[ad[ind][i]];
			if(x>0)
				global[ind]+=x;
		}
	}
	if(ans<=abs(global[ind]))
		ans=abs(global[ind]);
}
void dfs2(ll ind)
{
	visited2[ind]=1;
	ll i;
	for(i=0;i<ad[ind].size();i++)
	{
		if(visited2[ad[ind][i]]==0)
		{
			dfs2(ad[ind][i]);
			ll x=global1[ad[ind][i]];
			if(x<0)
				global1[ind]+=x;
		}
	}
	if(ans<=abs(global1[ind]))
		ans=abs(global1[ind]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>power[i];
		if(power[i]==0)
		{	
			global[i]=-1;
			global1[i]=-1;
		}
		else
		{
			global[i]=1;
			global1[i]=1;
		}
	}
	for(i=0;i<n-1;i++)
	{
		ll u,v;
		cin>>u>>v;
		ad[u].pb(v);
		ad[v].pb(u);
	}
	dfs1(1);
	dfs2(1);
	cout<<ans<<endl;
	return 0;
}
