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
 	ll n,x;
 	cin >> n;
 	deque<ll>ans;
 	vector<ll>in;
 	for(ll i=0;i<n;i++)
 	{
 		cin >> x;
 		in.pb(x);
 	}
 	sort(all(in));
 	ans.pb(in[n-1]);
 	for(ll i=n-2;i>=0;i-=2)
 	{
 		ans.push_front(in[i]);
 		ans.push_back(in[i-1]);
 	}
 	if(n%2 == 0)
 		ans.pb(in[0]);
 	vector<ll>ch;
 	while(!ans.empty())
 	{
 		ch.pb(ans.front());
 		ans.pop_front(); 
 	}
 	ll f = 0;
	if(ch[n-1]+ch[1]<=ch[0])
		f=1;
	if(ch[0]+ch[n-2]<=ch[n-1])
		f=1;
 	for(ll i=1;i<n-1;i++)
 	{
 		if(ch[i-1]+ch[i+1]<=ch[i])
 			f=1;
 	}
 	if(f==1)
 		cout << "NO" << endl;
 	else
 	{
 		cout << "YES" << endl;
 		for(ll i=0;i<n;i++)
 			cout << ch[i] << ' ';
 		cout << endl;
 	}
	return 0;
}