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
#define qq queue
#define pqq priority_queue
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
const ll L=1e5+5;
vector<ll>ad[2*L];
ll vis[2*L];
ll arr[2*L];
ll ans=0;
ll dfs(ll ind)
{
	ll i;
	vis[ind]=1;
	if(ad[ind].size()==1&&ind!=1)
	{
		if(arr[ind]==1)
			return 0;
		else
		{
			ans=max(ans,(ll)1);
			return 1;
		}
	}
	ll count=0;
	ll send=0;
	if(arr[ind]>1)
		send=1;
	for(i=0;i<ad[ind].size();i++)
	{
		if(!vis[ad[ind][i]])
		{
			ll a=dfs(ad[ind][i]);
			if(__gcd(arr[ad[ind][i]],arr[ind])>1)
			{
				if(count>=1)
				{
					ans=max(ans,a+send);
					send=max(send,1+a);
				}
				else
				{
					send=max(send,1+a);
					count++;
				}
			}
		}
	}
	ans=max(ans,send);
	return send;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin>>n;
 	for(i=1;i<=n;i++)
 		cin>>arr[i];
	ll x,y;
 	for(i=0;i<n-1;i++)
 	{
 		cin>>x>>y;
 		ad[x].pb(y);
 		ad[y].pb(x);
 	}
 	dfs(1);
 	cout<<ans<<endl;
	return 0;
}