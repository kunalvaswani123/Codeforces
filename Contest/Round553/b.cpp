#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
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
ll arr[200];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	for(i=0;i<n;i++)
	 	cin >> arr[i];
	sort(arr,arr+n);
	ll d = arr[n-1] - arr[0];
	d /= 2;
	ll val = arr[0] + d;
	ll f = 0;
	for(i=0;i<n;i++)
	{
		if(arr[i] < val)
		{	
			if(arr[i] + d != val)
				f = 1;
		}
		else if(arr[i] > val)
		{
			if(arr[i] - d != val)
				f = 1;
		}
	}
	ll f2 = 0;
	if(f == 1)
	{
		d = arr[n-1] - arr[0];
		val = arr[0] + d;
	}
	else
	{
		cout << d << endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i] < val)
		{	
			if(arr[i] + d != val)
				f2 = 1;
		}
		else if(arr[i] > val)
		{
			if(arr[i] - d != val)
				f2 = 1;
		}
	}
	if(f2 == 1)
		cout << -1 << endl;
	else
		cout << d << endl;
	return 0;
}