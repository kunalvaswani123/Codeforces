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
ll cost[12][12][12][12];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	string s;
 	cin >> s;
 	for (ll i = 0; i < 10; i++) {
 		for (ll j = 0; j < 10; j++) {
 			for (ll k1 = 0; k1 < 10; k1++) {
	 			for (ll k = 0; k < 10; k++) {
	 				ll f = 0;
	 				ll co = 1e18;
	 				ll to_m = (k + 10 - k1) % 10;
	 				for (ll a = 0; a <= 10; a++) {
	 					for (ll b = 0; b <= 10; b++) {
	 						if (a == 0 && b == 0)
	 							continue;
	 						ll temp = a * i + b * j;
	 						if (temp % 10 == to_m) {
	 							f = 1;
	 							co = min(co, a + b);
	 						}
	 					}
	 				}
	 				if (f == 1) {
	 					cost[i][j][k1][k] = co;
	 				}
	 				else
	 					cost[i][j][k1][k] = -1;
	 			}
 			}
 		}
 	}   
 	for (ll i = 0; i < 10; i++) {
 		for (ll j = 0; j < 10; j++) {
 			ll ans = 0;
 			ll f = 0;
 			for (ll k = 1; k < sz(s); k++) {
 				ll v2 = s[k] - '0';
 				ll v1 = s[k - 1] - '0';
 				if (cost[i][j][v1][v2] == -1) {
 					f = 1;
 					break;
 				}
 				else
 					ans += (cost[i][j][v1][v2] - 1);
 			}
 			if (f == 1)
 				cout << -1 << ' ';
 			else
				cout << ans << ' ';
 		}
 		cout << endl;
 	}
	return 0;
}