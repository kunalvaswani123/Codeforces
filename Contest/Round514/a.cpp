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
 	ll n,l,a;
 	cin>>n>>l>>a;
 	ll i;
 	ll ans=0;
 	ll last=0;
 	if(n!=0)
 	{
	 	ll a1,b1;
	 	cin>>a1>>b1;
	 	ans+=(a1-0)/a;
	 	last=a1+b1;
 	}
 	for(i=0;i<n-1;i++)
 	{
 		ll t1,t2;
 		cin>>t1>>t2;
 		ans+=(t1-last)/a;
 		last=t1+t2;
 	}
 	ans+=(l-last)/a;
 	cout<<ans<<endl;   
	return 0;
}