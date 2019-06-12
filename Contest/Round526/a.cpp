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
    ll i,j,n;
    cin>>n;
    ll arr[105];
    for(i=1;i<=n;i++)
    	cin>>arr[i];
    ll ans=INT_MAX;
    ll pr=1;
    for(i=1;i<=n;i++)
    {
    	ll x=0;
    	for(j=1;j<=n;j++)
    	{
	    	ll temp=0;
    		temp+=abs(j-i);
    		temp+=abs(j-1);
    		temp+=abs(i-1);
    		temp+=abs(i-1);
    		temp+=abs(j-1);
    		temp+=abs(j-i);	
    		x+=(arr[j]*temp);
    	}
    	ans=min(ans,x);
    }
    cout<<ans<<endl;
	return 0;
}