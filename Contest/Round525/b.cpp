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
const ll L=1e5;
ll arr[L+5];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,k;
 	cin>>n>>k;
 	for(i=0;i<n;i++)
 		cin>>arr[i];
 	ll start=0;
 	sort(arr,arr+n);
 	for(i=start;i<n;i++)
 	{
 		if(arr[start]!=0)
 			break;
 	}
 	ll count=0;
 	while(k--)
 	{
 		if(start==n)
 			cout<<0<<endl;
 		else
	 		cout<<arr[start]-count<<endl;
 		count+=(arr[start]-count);
 		while(arr[start]==count&&start<n)
 			start++;
 	}
	return 0;
}