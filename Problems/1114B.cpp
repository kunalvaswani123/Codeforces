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
pll arr[2*L];
ll pos[2*L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,j,n,m,c,k;
	cin >> n >> m >> k;
	for(i=0;i<n;i++)
	{
		cin >> arr[i].fi;
		arr[i].se = i+1;
	}
	sort(arr,arr+n);
	i = n - 1, c = 0;
	ll ans = 0;
	while(i >= 0 && c < m*k)
	{
		pos[arr[i].se]++;
		ans += arr[i].fi;
		i--,c++;
	}
	cout << ans << endl;
	ll ch = 0;
	ll val = 1;
	for(i = 1; i <= n; i++)
	{
		if(pos[i] == 1)
			ch++;
		if(ch % m == 0 && ch / m == val)
		{
			cout << i << ' ';
			val++;
		}
		if(val == k)
			break;
	}
	cout << endl;
	return 0;
}