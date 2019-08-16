#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
typedef long long ll;
ll A[100005];
node segtree[400005];
typedef struct node
{
	vector<ll> list;
}node;
node make(ll s,ll e,ll i)
{
	if(s==e)
	{
		segtree[i].list.push_back(A[s]);
		return segtree[i];
	}
	ll mid=(s+e)>>1;
	node temp1=make(s,mid,2*i+1);
	node temp2=make(mid+1,e,2*i+2);
	ll a=0,b=0;
	ll size1=temp1.list.size();
	ll size2=temp2.list.size();
	while(a<size1&&b<size2)
	{
		if(temp1.list[a]<=temp2.list[b])
			segtree[i].list.push_back(temp1.list[a++]);
		else
			segtree[i].list.push_back(temp2.list[b++]);
	}
	while(a<size1)
		segtree[i].list.push_back(temp1.list[a++]);
	while(b<size2)
		segtree[i].list.push_back(temp2.list[b++]);
	return segtree[i];
}
ll query(ll s,ll e,ll i,ll l,ll r,ll x)
{	
	if(l<=s && e<=r)
	{
		return upper_bound(segtree[i].list.begin(),segtree[i].list.end(),x)-segtree[i].list.begin();
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
	ll i,N;
	scanf("%lld",&N);
	for(i=1;i<=N;i++)
		scanf("%lld",&A[i]);
	ll q;
	scanf("%lld",&q);
	make(1,N,0);
	while(q--)
	{
		ll l,r,x;
		scanf("%lld%lld%lld",&l,&r,&x);
		printf("%lld\n",query(1,N,0,l,r,x));
	}
	return 0;
}