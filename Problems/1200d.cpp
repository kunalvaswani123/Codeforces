#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(), a.end()
#define sz(a) (ll)(a.size())
#define ordered_set tree <ll, null_type,less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k - 1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
ll power(ll x, ll y, ll p)
{ 
    ll res = 1;  
    x = x % p;
    while (y > 0) { 
        if (y & 1) res = (res * x) % p; 
        y = y >> 1;
        x = (x * x) % p;   
    } 
    return res; 
}
ll arr[2005][2005];
ll rs[2005][2005];
ll cs[2005][2005];
ll rw[2005][2005];
ll cw[2005][2005];
ll rall[2005];
ll call[2005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n, k;
	string s;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		cin >> s;
		for (ll j = 1; j <= n; j++) {
			if (s[j - 1] == 'B')
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}
	}
	for (ll i = 1; i <= n; i++) {
		ll f = 0;
		for (ll j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				f = 1;
				break;
			}
		}
		if (f == 0)
			rall[i] = rall[i - 1] + 1;
		else
			rall[i] = rall[i - 1];
	}
	for (ll j = 1; j <= n; j++) {
		ll f = 0;
		for (ll i = 1; i <= n; i++) {
			if (arr[i][j] == 1) {
				f = 1;
				break;
			}
		}
		if (f == 0)
			call[j] = call[j - 1] + 1;
		else
			call[j] = call[j - 1];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++)
			rs[i][j] = rs[i][j - 1] + arr[i][j];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++)
			cs[i][j] = cs[i - 1][j] + arr[i][j];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n - k + 1; j++) {
			ll a1 = rs[i][j - 1];
			ll a2 = rs[i][n] - rs[i][j + k - 1];
			if (a1 == 0 && a2 == 0)
				rw[i][j] = 1;
		}
	}
	for (ll i = 1; i <= n - k + 1; i++) {
		for (ll j = 1; j <= n; j++) {
			ll a1 = cs[i - 1][j];
			ll a2 = cs[n][j] - cs[i + k - 1][j];
			if (a1 == 0 && a2 == 0)
				cw[i][j] = 1;
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			rs[i][j] = 0;
			cs[i][j] = 0;
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			rs[i][j] = rs[i - 1][j] + rw[i][j];
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			cs[i][j] = cs[i][j - 1] + cw[i][j];
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= n - k + 1; i++) {	
		for (ll j = 1; j <= n - k + 1; j++) {
			ll p1 = rs[i + k - 1][j] - rs[i - 1][j];
			ll p2 = cs[i][j + k - 1] - cs[i][j - 1];
			ll add1 = rall[i - 1] + rall[n] - rall[i + k - 1];
			ll add2 = call[j - 1] + call[n] - call[j + k - 1]; 
			ans = max(ans, p1 + p2 + add1 + add2);
		}
	}
	cout << ans << endl;
	return 0;
}