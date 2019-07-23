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
ll power(ll x, ll y)
{ 
    ll res = 1;  
    x = x;
    while (y > 0) { 
        if (y & 1) res = (res * x); 
        y = y >> 1;
        x = (x * x);   
    } 
    return res; 
}
const ll L = 1e5 + 5;
ll dps[L][45];
ll dpm[L][45];
ll dpv[L][45];
ll edg[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> dpv[i][0];
	for (ll i = 0; i < n; i++)
		cin >> edg[i];
	for (ll j = 1; j <= 40; j++) {
		for (ll i = 0; i < n; i++) {
			dpv[i][j] = dpv[dpv[i][j - 1]][j - 1];
		}
	}
	for (ll i = 0; i < n; i++) {
		dps[i][0] = edg[i];
		dpm[i][0] = edg[i];
	}
	for (ll j = 1; j <= 40; j++) {
		for (ll i = 0; i < n; i++) {
			dps[i][j] = dps[i][j - 1] + dps[dpv[i][j - 1]][j - 1];
			dpm[i][j] = min(dpm[i][j - 1], dpm[dpv[i][j - 1]][j - 1]);
		}
	}
	for (ll i = 0; i < n; i++) {
		ll temp = k;
		ll st = i;
		ll s = 0;
		ll m = 1e18;
		for (ll j = 40; j >= 0; j--) {
			ll sub = temp - power(2, j);
			if (sub >= 0) {
				temp = sub;
				s += dps[st][j];
				m = min(dpm[st][j], m);
				st = dpv[st][j];
			}
		}
		cout << s << ' ' << m << endl;
	}
	return 0;
}