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
const ll L = 2005;
ll fr[L][L][4];
ll ba[L][L][4];
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
 	for (ll i = 1; i <= n; i++)
 		cin >> arr[i];
 	for (ll i = 1; i <= n; i++) {
 		for (ll j = i; j <= n; j++) {
 			if (j == i) {
 				if (arr[j] == 1) {
	 				fr[i][j][0] = 1; 
					fr[i][j][1] = 0;
					fr[i][j][2] = 0;					
 				}
 				else {
 					fr[i][j][0] = 0; 
					fr[i][j][1] = 0;
					fr[i][j][2] = 1;	
 				}
 			}
 			else {
	 			if (arr[j] == 1) {
	 				fr[i][j][0] = fr[i][j - 1][0] + 1;
	 				fr[i][j][1] = fr[i][j - 1][1];
	 				fr[i][j][2] = fr[i][j - 1][2];
	 			}
	 			else {
	 				fr[i][j][0] = fr[i][j - 1][0] ;
	 				fr[i][j][1] = max(fr[i][j - 1][0] + 1, fr[i][j - 1][1] + 1);
	 				fr[i][j][2] = fr[i][j - 1][2] + 1;	
	 			}
 			}
 		}
 	}
 	for (ll i = n; i >= 1; i--) {
 		for (ll j = i; j >= 1; j--) {
 			if (j == i) {
 				if (arr[j] == 1) {
	 				ba[j][i][0] = 1; 
					ba[j][i][1] = 0;
					ba[j][i][2] = 0;					
 				}
 				else {
 					ba[j][i][0] = 0; 
					ba[j][i][1] = 0;
					ba[j][i][2] = 1;	
 				}
 			}
 			else {
	 			if (arr[j] == 1) {
	 				ba[j][i][0] = ba[j + 1][i][0] + 1;
	 				ba[j][i][1] = ba[j + 1][i][1];
	 				ba[j][i][2] = ba[j + 1][i][2];
	 			}
	 			else {
	 				ba[j][i][0] = ba[j + 1][i][0] ;
	 				ba[j][i][1] = max(ba[j + 1][i][0] + 1, ba[j + 1][i][1] + 1);
	 				ba[j][i][2] = ba[j + 1][i][2] + 1;	
	 			}
 			}
 		}
 	}
 	ll ans = -1e18;
 	for (ll i = 1; i <= n; i++) {
 		for (ll j = i; j <= n; j++) {
 			ll temp1 = 0, temp2 = 0, temp3 = 0;
			temp1 = max(fr[1][i - 1][1], fr[1][i - 1][2]);
			temp2 = ba[i][j][2];
			temp3 = fr[j + 1][n][2];
			ans = max(ans, temp1 + temp2 + temp3);
			temp1 = temp2 = temp3 = 0;
			temp1 = fr[1][i - 1][0];
			temp2 = ba[i][j][0];
			temp3 = max(fr[j + 1][n][0], fr[j + 1][n][1]);
			temp3 = max(temp3, fr[j + 1][n][2]);
			ans = max(ans, temp1 + temp2 + temp3);
			temp1 = temp2 = temp3 = 0;
 			temp1 = fr[1][i - 1][0];
			temp2 = max(ba[i][j][1], ba[i][j][2]);
			temp3 = fr[j + 1][n][2];
			ans = max(ans, temp1 + temp2 + temp3);
 		}
 	} 
 	cout << ans << endl;
	return 0;
}