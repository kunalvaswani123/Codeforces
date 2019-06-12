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
const ll L = 1e5 + 5;
ll f = -1,n;
ll a[L];
ll b[L];
void rec(ll t,ll ind)
{
	if(f != -1)
		return;
	if(ind == n)
		f = t;
	ll i,j;
	if(ind == 0)
	{
		for(i=0;i<4;i++)
			rec(i,ind+1);
	}
	else
	{
		for(i=0;i<4;i++)
		{
			if((t|i)==a[ind] && (t&i)==b[ind])
			{
				rec(i,ind+1);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j;
 	cin >> n;
 	for(i=1;i<=n-1;i++)
 		cin >> a[i];
	for(i=1;i<=n-1;i++)
 		cin >> b[i];
 	rec(0,0);
 	if(f != -1)
 	{
 		cout << "YES" << endl;
 		vector<ll>ans;
 		ans.pb(f);
 		for(i=n-1;i>=1;i--)
 		{
 			for(j=0;j<4;j++)
 			{
 				if((f|j)==a[i] && (f&j)==b[i])
				{
					f = j;
					ans.pb(f);
					break;
				}
 			}
 		}
 		reverse(ans.begin(),ans.end());
 		for(i=0;i<ans.size();i++)
 			cout << ans[i] << ' ';
 		cout << endl;
 	}
 	else
 		cout << "NO" << endl;
	return 0;
}