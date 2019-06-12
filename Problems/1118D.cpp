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
bool check(ll mid, ll m, ll n)
{
	if(mid > n || mid < 1)
		return false;
	vector <ll> check1, check2;
	ll i, fac = 0;
	for(i=0;i<n;i++)
	{
		if(i != 0 && i % mid == 0)
			fac -= 1;
		check1.pb(max((ll)0, arr[i] + fac));
	}
	ll count = 0;
	fac = 0;
	for(i=n-1;i>=0;i--)
	{
		if(count!=0 && count % mid == 0)
			fac -= 1;
		check2.pb(max((ll)0, arr[i] + fac));
		count++;
	}
	ll sum1 = 0, sum2 = 0;
	for(i=0;i<check1.size();i++)
		sum1 += check1[i];
	for(i=0;i<check2.size();i++)
		sum2 += check2[i];
	if(sum1 >= m || sum2 >= m)
		return true;
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, j, n, m;
 	cin >> n >> m;
 	ll sum = 0;
 	for(i=0;i<n;i++)
 	{
 		cin >> arr[i];
 		sum += arr[i];
 	}
 	sort(arr, arr + n);
 	if(sum < m)
 	{
 		cout << -1 << endl;
 		return 0;
 	}
 	ll l = 0, r = n + 1;
 	while(l < r)
 	{
 		ll mid = (l + r) >> 1;
 		if(check(mid, m, n))
 			r = mid;
 		else
 			l = mid + 1;
 	}
 	cout << l << endl;
	return 0;
}