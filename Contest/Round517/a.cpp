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
 	ll w,h,k;
 	cin>>w>>h>>k;
 	ll i;
 	ll ans=0;
 	for(i=1;i<=k;i++)
 	{
 		ll b=w-4*(i-1);
 		ll l=h-4*(i-1);
 		ans+=(2*(b+l)-4);		
 	}   
 	cout<<ans<<endl;
	return 0;
}