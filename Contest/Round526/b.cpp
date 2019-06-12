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
 	ll i,j,n,s;
 	cin>>n>>s;
 	ll arr[1005];
 	ll sum=0;
 	ll mi=INT_MAX;
 	for(i=0;i<n;i++)
 	{
 		cin>>arr[i];
 		sum+=arr[i];
 		mi=min(mi,arr[i]);
 	}
 	if(sum<s)
 	{
 		puts("-1");
 		return 0;
 	}
 	ll check1=0;
 	for(i=0;i<n;i++)
 		check1+=abs(mi-arr[i]);
 	if(check1>=s)
 	{
 		cout<<mi<<endl;
 		return 0;
 	}
 	ll check2=s-check1;
 	if(check2%n==0)
 	{
 		ll ans=mi-(check2/n);
 		cout<<ans<<endl;
 	}
 	else
 	{
 		ll ans=mi-(check2/n);
 		cout<<ans-1<<endl;
 	}
	return 0;
}