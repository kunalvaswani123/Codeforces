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
ll arr[2 * L];
pll carr[2 * L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i;
 	ll n;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
	ll sume = 0, sumo = 0;
	for(i=n-1;i>=0;i--)
	{
		if(i%2 == 0)
		{
			carr[i].fi = sume;
			carr[i].se = sumo;
			sume += arr[i];
		}
		else
		{
			carr[i].fi = sume;
			carr[i].se = sumo;	
			sumo += arr[i];
		}
	}
	sume = 0, sumo = 0;
	ll count = 0;
	for(i=0;i<n;i++)
	{
		if(sume + carr[i].se == sumo + carr[i].fi)
			count++;
		if(i%2 == 0)
			sume += arr[i];
		else
			sumo += arr[i];
	}
	cout << count << endl;
	return 0;
}