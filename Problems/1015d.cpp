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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n, k, s;
 	cin >> n >> k >> s;
 	ll req = s / (n - 1);
 	if (s % (n - 1) != 0)
 		req++;
 	if (k < req || k > s) {
 		cout << "NO" << endl;   
 		return 0;
 	}
 	cout << "YES" << endl;
 	ll cur = 1;
 	ll end = n;
 	ll dist = 0;
 	vector <ll> ans;
 	while (1) {
 		if (k == 0)
 			break;
 		ll req = 1;
 		ll t = abs(cur - end);
 		if (cur == end) {
 			if (end == 1)
 				end = n;
 			else
 				end = 1;
 			t = 0;
 			req = 0;
 		}
 		ll t1 = s - dist - t;
 		if (t1 < 0)
 			t1 += t, req = 0;
 		ll req2 = t1 / (n - 1);
 		ll req3 = 0;
 		if (t1 >= 0 && t1 % (n - 1) != 0)
 			req3++;
 		if (t1 >= 0 && k == req2 + req + req3) {
 			if (req == 1) {
 				cur = end;
 				ans.pb(end);
 				if (end == n)
 					end = 1;
 				else
 					end = n;
 			}
 			for (ll i = 0; i < req2; i++) {
 				if (cur == n)
 					ans.pb(1), cur = 1;
 				else
 					ans.pb(n), cur = n;
 				if (cur == 1)
 					end = n;
 				else
 					end = 1;
 			}
 			if (req3 == 1) {
 				if (end == n) {
	 				ll temp = cur + t1 % (n - 1);
	 				if (temp > n) {
	 					ans.pb(n);
	 					temp -= (n - cur);
	 					ans.pb(n - temp);
	 				}
	 				else
		 				ans.pb(cur + t1 % (n - 1));
 				}
	 			else {
	 				ll temp = cur - t1 % (n - 1);
	 				if (temp <= 0) {
	 					ans.pb(1);
	 					temp -= (cur - 1);
	 					ans.pb(1 + temp);
	 				}
	 				else
		 				ans.pb(cur - t1 % (n - 1));
	 			}
 			}
 			break;
 		}
 		else {
 			if (end == 1)
	 			ans.pb(--cur);
	 		else
	 			ans.pb(++cur);
	 		k--;
	 		dist++;
 		}
 	}
 	for (ll i = 0; i < sz(ans); i++)
 		cout << ans[i] << ' ';
 	cout << endl; 
	return 0;
}