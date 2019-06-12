#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
	ll arr[105];
	ll i,n;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> arr[i];
	ll ans = 0;
	ll f = 0;
	for(i=n-2;i>=0;i--)
	{
		if(arr[i] == 1)
		{
			if(arr[i+1] == 2)
				ans += 3;
			else if(arr[i+1] == 3)
				ans += 4;				
		}
		else if(arr[i] == 2)
		{
			if(arr[i+1] == 1)
				ans += 3;
			else if(arr[i+1] == 3)
				f = 1;				
		}
		else
		{
			if(arr[i+1] == 1)
			{
				if(i != n-2 && arr[i+2] == 2)
					ans += 3;
				else
					ans += 4;
			}
			else if(arr[i+1] == 2)
				f = 1;
		}
	}
	if(f == 1)
		cout << "Infinite" << endl;
	else
	{
		cout << "Finite" << endl;
		cout << ans << endl;
	}
	return 0;
}