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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,k;
 	cin>>n>>k;
 	ll i;
 	ll val1;
 	ll val2;
 	ll ans=INT_MAX;
 	for(i=k-1;i>=1;i--)
	{
		if(n%i==0)
		{
			val1=n/i;
			val2=i;
			ll tempans=k*(val1)+val2;
			ans=min(tempans,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}