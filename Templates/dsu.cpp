#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
#define pival 3.14159265359
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pqq priority_queue
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
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
const ll L = 1e5 + 5;
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
ll find(ll i, ll j)
{
    if(root(i) == root(j))
        return true;
    return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll i,n;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        arr[i] = i;
        size[i] = 1;
    }
	return 0;
}