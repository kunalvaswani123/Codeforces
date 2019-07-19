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
const ll L = 1e6 + 5;
ll arr[L];
ll size[L];
ll root(ll i)
{
    while(arr[i] != i)
    {
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}
void union1(ll i, ll j)
{
    ll ri = root(i);
    ll rj = root(j);
    if(size[ri] <= size[rj])
    {
        arr[ri] = rj;
        size[rj] += size[ri];
    }
    else
    {
        arr[rj] = ri;
        size[ri] += size[rj];   
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll p,k;
    cin >> p >> k;
    for(ll i = 1; i <= p - 1; i++) {
        arr[i] = i;
        size[i] = 1;
    }
    ll ans = 1;
    if (k == 0) ans = power(p, p - 1, mod);
    else {
    	if (k == 1) ans = p;
    	for (ll i = 1; i <= p - 1; i++) {
    		ll a = i;
    		ll b = (k * i) % p;
    		if (root(a) != root(b))
    			union1(a, b);
    	}
	    for (ll i = 1; i <= p - 1; i++) {
	    	if (arr[i] == i)
		    	ans = (ans * p) % mod;
	    }
    }
    cout << ans << endl;
	return 0;
}