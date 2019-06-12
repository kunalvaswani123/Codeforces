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
const ll L = 3e5 + 5;
ll arr[L];
ll pref[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n,k;
 	cin >> n >> k;
 	for(i=1;i<=n;i++)
 	{
 		cin >> arr[i];
 		pref[i] = arr[i] + pref[i-1];
 	}
 	pqq<ll>vals;
 	ll x, ans = pref[n];
 	for(i=1;i<=n-1;i++)
 		vals.push(pref[n] - pref[i]);
 	k--;
 	while(k--)
 		ans += vals.top(), vals.pop();
 	cout << ans << endl;
	return 0;
}