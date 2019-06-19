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
const ll L = 5e5 + 5;
ll c[L];
vector<pll> arr;
ll ans[L];
bool cmp(const pll &a,const pll &b) 
{ 
    if(a.fi == b.fi)
        return a.se < b.se;
    else
        return a.fi < b.fi; 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ordered_set os;
    set<pll>vals;
    ll i,n,m,q,x;
    cin >> n >> m >> q;
    for(i=0;i<n;i++)
    {
        cin >> x;
        c[x]++;
    }
    for(i=0;i<q;i++)
    {
        cin >> x;
        arr.pb({x,i});
    }
    sort(all(arr), cmp);
    for(i=1;i<=m;i++)
        vals.insert({c[i],i});
    ll st = 0;
    ll p = n + 1;
    ll c = 0;
    ll maxst = -1;
    ll maxp = -1;
    while(st <= n)
    {
        auto it1 = vals.lower_bound({st,-1});
        auto it2 = vals.lower_bound({(*it1).fi+1,-1});
        ll temp = -1;
        if(it2 != vals.end())
            temp = (*it2).fi;
        for(auto it = it1; it != it2; it++)
            os.insert((*it).se), c++;
        ll e;
        if(it2 == vals.end())
            e = -1;
        else
            e = p + c * (temp - (*it1).fi) - 1;
        // cout << p << ' ' << e << endl;
        ll ind1 = lower_bound(all(arr), pll {p, -1}, cmp) - arr.begin();
        ll ind2;
        if(e != -1)
            ind2 = lower_bound(all(arr), pll {e + 1, -1}, cmp) - arr.begin();
        else
            ind2 = q;
        // cout << ind1 << ' ' << ind2 << endl;
        for(i=ind1;i<ind2;i++)
        {
            maxst = max(maxst, i);
            maxp = max(maxp, p);
            if(it2 == vals.end())
                ans[arr[i].se] = (arr[i].fi - p) % m + 1;       
            else
            {
                ll temp = (arr[i].fi - p) % c;
                ans[arr[i].se] = *os.find_by_order(temp);
            }
        }
        if(it2 == vals.end())
            break;
        else
        {
            p = e + 1;
            st = (*it2).fi;
        }
    }
    for(i=0;i<q;i++)
        cout << ans[i] << endl;
    return 0;
}