#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef struct node
{
	vector<ll> list;
}node;
#define mp make_pair
#define pb push_back
ll visited[1000000];
ll levelarr[1000000];
ll larr[1000000];
ll rarr[1000000];
node segtree[1000000];
ll euler[1000000];
vector<ll> ad[1000000];
ll co;
void dfs(ll ind)
{
	visited[ind]=1;ll i;
	euler[co]=levelarr[ind];
	larr[ind]=co++;
	for(i=0;i<ad[ind].size();i++)
	{
		if(visited[ad[ind][i]]==0)
		{
			levelarr[ad[ind][i]]=levelarr[ind]+1;
			dfs(ad[ind][i]);
		}
	}
	euler[co]=levelarr[ind];
	rarr[ind]=co++;
}
void make(ll s,ll e,ll i)
{
	if(s==e)
	{
		segtree[i].list.pb(euler[s]);
		return;
	}
	ll mid=(s+e)/2;
	make(s,mid,2*i+1);
	make(mid+1,e,2*i+2);
	ll a=0,b=0;
	ll size1=segtree[2*i+1].list.size();
	ll size2=segtree[2*i+2].list.size();
	while(a<size1&&b<size2)
	{
		if(segtree[2*i+1].list[a]<=segtree[2*i+2].list[b])
			segtree[i].list.push_back(segtree[2*i+1].list[a++]);
		else
			segtree[i].list.push_back(segtree[2*i+2].list[b++]);
	}
	while(a<size1)
		segtree[i].list.push_back(segtree[2*i+1].list[a++]);
	while(b<size2)
		segtree[i].list.push_back(segtree[2*i+2].list[b++]);
}
ll query(ll s,ll e,ll i,ll l,ll r,ll x)
{	
	if(l<=s && e<=r)
	{
		std::pair<std::vector<ll>::iterator,std::vector<ll>::iterator> range;
		range=std::equal_range (segtree[i].list.begin(), segtree[i].list.end(), x);
		return ll(range.second-range.first);
	}
	else if(e<l || s>r)
		return 0;
	else
	{
		ll mid=(s+e)>>1;
		ll a1=query(s,mid,2*i+1,l,r,x);
		ll a2=query(mid+1,e,2*i+2,l,r,x);
		return (a1 + a2);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n,q,i;
	cin>>n;
	cin>>q;
	for(i=1;i<=n-1;i++)
	{
		ll a,b;
		cin>>a>>b;		
		ad[a].pb(b);
		ad[b].pb(a);
	}
	dfs(1);
	make(1,rarr[1],0);
	while(q--)
	{
		ll vertex,dist;
		cin>>vertex>>dist;
		if(dist==0)
		{
			cout<<1<<endl;
		}
		else{
		cout<<query(1,rarr[1],0,larr[vertex],rarr[vertex],levelarr[vertex]+dist)/2<<endl;
		}
	}
	return 0;
}