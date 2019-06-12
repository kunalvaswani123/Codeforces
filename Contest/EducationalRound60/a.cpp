#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
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
const ll L = 1e5 + 5;
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n;
 	cin>>n;
 	ll maxval = INT_MIN;
 	for(i=0;i<n;i++)
 	{
 		cin>>arr[i];
 		maxval = max(maxval,arr[i]);
 	}
 	ll ans = 1;
 	ll temp = 1;
 	arr[n] = -1; 
 	for(i=1;i<n + 1;i++)
 	{
 		if(arr[i] == arr[i-1] && arr[i] == maxval)
 			temp++;
 		else
 		{
 			ans=max(ans,temp);
 			temp = 1;
 		}
 	}
 	cout << ans << endl;	
	return 0;
}