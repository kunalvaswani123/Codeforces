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
const ll L = 2e5 + 5;
ll ans[L];
ll ind[L];
ll arr[L];
ll lj[L];
ll rj[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll i,j,n,k;
	cin >> n >> k;
	stack<ll>ch;
	for(i=1;i<=n;i++)
	{
		cin >> arr[i];
		ind[arr[i]] = i;
	}
	ll f = 1;
	for(i=1;i<=n;i++)
		lj[i] = i-1;
	for(i=1;i<=n;i++)
		rj[i] = i+1;
	for(i=n;i>=1;i--)
	{
		if(ans[i]!=0)
			continue;
		else
		{
			ll st = ind[i];
			ans[arr[st]] = f;
			ll l=-1,r=-1;
			for(j=1;j<=k;j++)
			{
				if(rj[st] == n+1)
				{
					r = n+1;
					break;
				}
				else
				{
					ans[arr[rj[st]]] = f;
					st = rj[st];
					if(j == k)
						r = rj[st];					
				}
			}
			if(r == -1)
				r = n+1;
			st=ind[i];
			for(j=1;j<=k;j++)
			{
				if(lj[st] == 0)
				{
					l = 0;
					break;
				}
				else
				{
					ans[arr[lj[st]]] = f;
					st = lj[st];
					if(j == k)
						l = lj[st];
				}
			}
			if(l == -1)
				l = 0;
			rj[l]=r;
			lj[r]=l;
		}
		if(f == 1)
			f = 2;
		else
			f = 1;
	}
	for(i=1;i<=n;i++)
		arr[ind[i]] = ans[i];
	for(i=1;i<=n;i++)
		cout << arr[i];
	cout << endl;
	return 0;
}