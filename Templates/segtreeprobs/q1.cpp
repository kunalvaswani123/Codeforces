#include<iostream>
using namespace std;
#include<stdio.h>
typedef long long ll;
const ll mod=1e9+7;
const ll L=1e5+5;
typedef struct node
{
	ll a11,a12,a21,a22;
}node;
node A[L];
node segtree[4*L];
void prod(node arr[],ll i1,ll i2,ll i3)
{
	arr[i3].a11=((arr[i1].a11*arr[i2].a11)+(arr[i1].a12*arr[i2].a21))%mod;
	arr[i3].a12=((arr[i1].a11*arr[i2].a12)+(arr[i1].a12*arr[i2].a22))%mod;
	arr[i3].a21=((arr[i1].a21*arr[i2].a11)+(arr[i1].a22*arr[i2].a21))%mod;
	arr[i3].a22=((arr[i1].a21*arr[i2].a12)+(arr[i1].a22*arr[i2].a22))%mod;
}
void make(ll s,ll e,ll i)
{
	if(s==e)
	{
		segtree[i].a11=A[s].a11;
		segtree[i].a12=A[s].a12;
		segtree[i].a21=A[s].a21;
		segtree[i].a22=A[s].a22;
		return;
	}
	ll mid=(s+e)>>1;
	make(s,mid,2*i+1);
	make(mid+1,e,2*i+2);
	prod(segtree,2*i+1,2*i+2,i);
}
node query(ll s,ll e,ll i,ll l,ll r)
{
	if(l<=s&&e<=r)
	{
		return segtree[i];
	}
	if(e<l||s>r)
	{
		node temp;
		temp.a11=1;
		temp.a12=0;
		temp.a21=0;
		temp.a22=1;
		return temp;	
	}
	else
	{
		ll mid=(s+e)>>1;
		node x1=query(s,mid,2*i+1,l,r);
		node x2=query(mid+1,e,2*i+2,l,r);
		node temp;
		temp.a11=((x1.a11*x2.a11)+(x1.a12*x2.a21))%mod;
		temp.a12=((x1.a11*x2.a12)+(x1.a12*x2.a22))%mod;
		temp.a21=((x1.a21*x2.a11)+(x1.a22*x2.a21))%mod;
		temp.a22=((x1.a21*x2.a12)+(x1.a22*x2.a22))%mod;
		return temp;
	}
}
void update(ll s,ll e,ll index,ll i,node values)
{
	if(s==e)
	{
		A[s].a11=values.a11;
		A[s].a12=values.a12;
		A[s].a21=values.a21;
		A[s].a22=values.a22;
		segtree[i].a11=values.a11;
		segtree[i].a12=values.a12;
		segtree[i].a21=values.a21;
		segtree[i].a22=values.a22;
		return;
	}
	ll mid=(s+e)>>1;
	if(index<=mid)
		update(s,mid,index,2*i+1,values);
	else
		update(mid+1,e,index,2*i+2,values);
	prod(segtree,2*i+1,2*i+2,i);
}
int main()
{
	ll N,q,i;
	scanf("%lld",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%lld%lld%lld%lld",&A[i].a11,&A[i].a12,&A[i].a21,&A[i].a22);
	}
	make(1,N,0);
	scanf("%lld",&q);
	while(q--)
	{
		ll check;
		scanf("%lld",&check);
		if(check==1)
		{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			node temp=query(1,N,0,l,r);
			printf("%lld %lld %lld %lld\n",temp.a11,temp.a12,temp.a21,temp.a22);	
		}
		else
		{
			ll index;
			scanf("%lld",&index);
			ll a,b,c,d;
			scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
			node temp;
			temp.a11=a;
			temp.a12=b;
			temp.a21=c;
			temp.a22=d;
			update(1,N,index,0,temp);
		}
	}
	return 0;
}