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
ll arr[L];
ll pref[L];
ll suff[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,te;
 	cin>>n;
 	for(i=0;i<n;i++)
 		cin>>arr[i];
 	pref[0]=abs(arr[0]);
 	ll sum=-arr[0];
 	for(i=1;i<n;i++)
 	{
		sum+=(-arr[i]);
		pref[i]=max(sum,pref[i-1]+arr[i]);	
 	}
 	suff[n-1]=abs(arr[n-1]);
 	ll sum2=-arr[n-1];
 	for(i=n-2;i>=0;i--)
 	{
 		sum2+=(-arr[i]);
 		suff[i]=max(sum2,suff[i+1]+arr[i]);
 	}
 	ll ans=INT_MIN;
 	ans=max(ans,pref[n-1]);
 	ans=max(ans,suff[0]);
 	for(i=0;i<n-1;i++)
 	{
		ans=max(ans,pref[i]+suff[i+1]);
 	}
 	cout<<ans<<endl;
	return 0;
}