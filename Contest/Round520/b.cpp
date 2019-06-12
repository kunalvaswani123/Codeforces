#include "bits/stdc++.h" 
using namespace std; 
#define MAXN 1000005 
typedef long long ll;
ll si[MAXN]; 
void sieve() 
{ 
	si[1]=1; 
	for (ll i=2; i<MAXN; i++) 
		si[i] = i; 
	for (ll i=2; i*i<MAXN; i++) 
	{ 
		if (si[i] == i) 
		{ 
			for (ll j=i*i; j<MAXN; j+=i)
			{
				if (si[j]==j) 
					si[j]=i; 
			} 
		} 
	} 
} 
vector<ll> fact(ll x) 
{ 
	vector<ll> ret; 
	while (x != 1) 
	{ 
		ret.push_back(si[x]); 
		x=x/si[x]; 
	} 
	return ret; 
} 

int main() 
{ 
	sieve(); 
	ll n,i;
	cin>>n;
	ll ans=n;
	ll store=n;
	if(n==1)
	{
		cout<<1<<' '<<0<<endl;
		return 0;
	}
	ll ans1=0;
	ll ans2=0;
	while(1)
	{
		vector<ll> p=fact(n);
		ll sz=p.size();
		ll mul=1;
		ll prev=p[0];
		ll sind=1;
		for(i=1;i<sz;i++)
		{
			if(p[i]==prev)
			{
				sind++;
			}
			else
			{
				if(sind%2==1)
					mul*=prev;
				if(i==sz-1)
					mul*=p[i];
				sind=1;
				prev=p[i];
			}
		}
		if(sz==1||p[sz-1]==p[sz-2])
		{
			if(sind%2==1)
				mul*=prev;
			sind=1;
		}
		ll temp=sqrt(n*mul);
		if(temp>=n)
		{
			ans1=n;
			break;
		}
		ans2++;
		n=temp;
	}
	while(store!=1)
	{
		if(ans1==store)
		{
			ans2--;
			break;
		}
		ll temp=sqrt(store);
		if(temp*temp!=store)
			break;
		store=temp;
	}
	cout<<ans1<<' '<<ans2+1<<endl;
	return 0; 
} 
