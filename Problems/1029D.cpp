#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll power(ll x,ll y,ll p) 
{ 
    ll res=1;  
    x=x%p;
    while (y > 0) 
    { 
        if(y&1) 
            res=(res*x)%p; 
        y=y>>1;
        x=(x*x)%p;   
    } 
    return res; 
}
const ll L=1e6;
ll arr[L];
ll lent[L];
map <pll,ll> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	ll i,j,n,k;
	cin>>n>>k;
	ll ans=0;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		ll r=arr[i]%k;
		ll temp=arr[i];
		ll len;
		for(len=0;temp!=0;len++)
			temp=temp/10;
		lent[i]=len;
		m[mp(len,r)]++;
	}
	for(i=0;i<n;i++)
	{
		ll ori=arr[i]%k;
		ll x=1;
		for(j=1;j<=10;j++)
		{
			x*=10;
			ll powr=x%k;
			ll newr=(arr[i]*powr)%k;
			ll checkr=(k-newr)%k;
			ans+=m[mp(j,checkr)];
			if(checkr==ori&&lent[i]==j)
				ans--;
		}
	}
	cout<<ans<<endl;
	return 0;
}