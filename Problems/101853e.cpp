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
const ll L = 1e6;
ll arr[20][20];
ll lmax[20];
ll ans[16][L];
ll vals[16][L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll t, n;
	cin >> t;
	vector <ll> allw;
	vector <ll> ch[20];
	ll total = (1 << 16);
	for (ll i = 0; i < total; i++) {
		vector <ll> pr;
		ll c = 0;
		ll temp = i;
		while (c < 16) {
			pr.pb(temp % 2);
			temp /= 2;
			c++;
		}
		ll f = 0;
		for (ll j = 1; j < 16; j++) {
			if (pr[j] == 1 && pr[j - 1] == 1)
				f = 1;
		}
		if (f == 0) {
			allw.pb(i);
			for (ll j = 0; j < 16; j++) {
				ll d = (1 << j);
				if (i % d == 0)
					ch[j].pb(i);
			}
		}
	}
	while (t--) {
		cin >> n;
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++)
				cin >> arr[i][j];
		}
		ll tot = (1 << n);
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < sz(allw); j++) {
				ll temp = allw[j];
				if (temp >= tot)
					break;
				ll c = 0;
				while (c < n) {
					if (temp % 2 == 1)
						vals[i][allw[j]] += arr[i][n - c - 1];
					c++;
					temp /= 2;
				}
				if (i == 0)
					ans[i][allw[j]] = vals[i][allw[j]];
			}
		}
		for (ll i = 0; i < n; i++) {
			// cout << i << endl;
			for (ll j = 0; j < sz(ch[i]); j++) {
				if (ch[i][j] >= tot)
					break;
				lmax[i] = max(lmax[i], vals[0][ch[i][j]]);
				// cout << ch[i][j] << ' ' << vals[0][ch[i][j]] << endl;
			}
		}
		for (ll i = 1; i < n; i++) {
			ll c = 1;
			ll st = 1;
			ans[i][0] = lmax[0];
			for (ll j = 0; j < n; j++)
				cout << lmax[j] << ' ';
			cout << endl;	
			// cout << allw[1] << endl;
			for (ll j = 1; j < sz(allw); j++) {
				ll temp = allw[j];
				if (temp >= st)
					c++, st *= 2;
				if (temp >= tot)
					break;
				ans[i][temp] = lmax[c] + vals[i][temp];
			}
			for (ll j = 0; j < n; j++)
				lmax[j] = 0;
			for (ll j = 0; j < n; j++) {
				for (ll k = 0; k < sz(ch[j]); k++) {
					if (ch[j][k] >= tot)
						break;
					lmax[j] = max(lmax[j], ans[i][ch[j][k]]);
				}
			}
		}	
		ll final_ans = 0;
		for (ll i = 0; i < tot; i++) 
			final_ans = max(final_ans, ans[n - 1][i]);
		cout << final_ans << endl;
	} 	
	return 0;
}