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
ll s[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,k,ans=INT_MIN;
 	cin>>n>>k;
 	for(i=0;i<n;i++)
 	{
 		cin>>s[i];
 		ans=max(ans,s[i]);
 	}
 	ll check=n-k;
 	for(i=0;i<check;i++)
 		ans=max(ans,s[i]+s[2*check-1-i]);	
 	cout<<ans<<endl;
	return 0;
}