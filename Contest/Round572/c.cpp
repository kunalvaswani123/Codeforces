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
const ll L = 1e5 + 5;
ll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n;
 	cin >> n;
 	map<pll,pll>m;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	for(i=2;i<=n;i*=2)
 	{
 		for(j=0;j<n-i+1;j++)
 		{
 			if(i==2)
 			{
 				ll p = arr[j] + arr[j+1];
 				ll f = 0;
 				if(p >= 10)
 					f = 1;
 				m[mp(j,j+i-1)] = mp(f,p%10);
 			}
 			else
 			{
 				ll p = i / 2;
 				pll a1 = m[mp(j,j+p-1)];
 				pll a2 = m[mp(j+p,j+i-1)];
 				ll f = 0;
 				if(a1.se + a2.se >= 10)
 					f = 1;
 				m[mp(j,j+i-1)] = mp(a1.fi+a2.fi+f,(a1.se+a2.se)%10);
 			}
 		}
 	}
 	ll q,l,r;
 	cin >> q;
 	while(q--)
 	{
 		cin >> l >> r;
 		cout << m[mp(l-1,r-1)].fi << endl;
 	}
	return 0;
}