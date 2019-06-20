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
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//K-th smallest
//cout << k << "kth smallest: " << *A.find_by_order(k-1) << endl;
//NO OF ELEMENTS < X
//cout << "No of elements less than " << X << " are " << A.order_of_key(X) << endl;
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
const ll L = 2e5 + 5;
pll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	for(i=0;i<n;i++)
 		cin >> arr[i].fi, arr[i].se = i + 1;
 	sort(arr,arr+n);
 	vector<ll>diff;
 	set<ll>ch;
 	map<ll,ll>m;
 	for(i=1;i<n;i++)
 	{
 		ll x = arr[i].fi-arr[i-1].fi;
 		diff.pb(x);
 		ch.insert(x);
 		m[x]++;
 	}
 	if(sz(ch) > 3)
 	{
 		cout << -1 << endl;
 		return 0;
 	}
 	else if(sz(ch) == 3)
 	{
 		vector<ll>v;
 		for(auto it:ch)
 			v.pb(it);
 		if(m[v[0]] == 1 && m[v[1]] == 1)
 		{
	 		for(i=1;i<n-1;i++)
	 		{
	 			if(min(diff[i-1],diff[i]) == v[0] && max(diff[i-1],diff[i]) == v[1] && v[0] + v[1] == v[2])
	 			{
	 				cout << arr[i].se << endl;
	 				return 0;
	 			}
	 		}
 		}
 	}
 	else if(sz(ch) == 2)
 	{
 		vector<ll>v;
 		for(auto it:ch)
 			v.pb(it);
 		if(m[v[0]] == 1 && (diff[0] == v[0] || diff[n-2] == v[0]))
 		{
 			if(diff[0] == v[0])
 				cout << arr[0].se << endl;
 			else
 				cout << arr[n-1].se << endl;
 			return 0;
 		}
 		else if(m[v[1]] == 1 && (diff[0] == v[1] || diff[n-2] == v[1]))
 		{
 			if(diff[0] == v[1])
 				cout << arr[0].se << endl;
 			else
 				cout << arr[n-1].se << endl;
 			return 0;
 		}
 		if(m[v[0]] == 2 || m[v[0]] == 1 || m[v[1]] == 1)
 		{
 			for(i=1;i<n-1;i++)
	 		{
	 			if(diff[i-1] == v[0] && diff[i] == v[0] && v[0] * 2 == v[1])
	 			{
	 				cout << arr[i].se << endl;
	 				return 0;
	 			}
	 			else if(min(diff[i-1],diff[i]) == v[0] && max(diff[i-1],diff[i]) == v[1])
	 			{
	 				if(diff[i-1] + diff[i] == v[1] && m[v[0]] == 1)
	 				{
		 				cout << arr[i].se << endl;
	 					return 0;
	 				}
		 			else if(diff[i-1] + diff[i] == v[0] && m[v[1]] == 1)
		 			{
		 				cout << arr[i].se << endl;
		 				return 0;
		 			}
	 			}
	 		}	
 		}
 	}
 	else if(sz(ch) == 1)
 	{
 		cout << arr[0].se << endl;
 		return 0;
 	}
	cout << -1 << endl;
	return 0;
}