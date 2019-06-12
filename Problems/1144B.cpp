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
ll arr[2001];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n,sum;
 	cin >> n;
 	vector<ll>ev;
 	vector<ll>od;
 	sum = 0;
 	for(i=0;i<n;i++)
 	{
 		cin >> arr[i];
 		sum += arr[i];
 		if(arr[i] % 2 == 0)
 			ev.pb(arr[i]);
 		else
 			od.pb(arr[i]);
 	}
 	sort(ev.begin(), ev.end());
 	sort(od.begin(), od.end());
 	ll esize = ev.size();
 	ll osize = od.size();
 	ll mins = min(esize, osize);
 	ll evsum = 0;
 	ll odsum = 0;
 	i = esize - 1;
 	j = osize - 1;
 	for(;i >= 0 && j >= 0;i--,j--)
 	{
 		evsum += ev[i];
 		odsum += od[j];
 	}
 	if(esize > osize)
 		evsum += ev[i];
 	else if(esize < osize)
 		odsum += od[j];
 	cout << sum - evsum - odsum << endl;
	return 0;
}