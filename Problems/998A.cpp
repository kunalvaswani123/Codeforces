#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define american_pie 3.1415926535
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define qq queue
#define pqq priority_queue
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
const ll L = 12;
pll arr[L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i, n;
 	cin >> n;
 	for(i=0;i<n;i++)
 	{
 		cin >> arr[i].fi;
 		arr[i].se = i;
 	}
 	sort(arr, arr + n);
 	if(n == 1 || n == 2 && arr[0].fi == arr[1].fi)
 		cout << -1 << endl;
 	else
 	{
 		cout << 1 << endl;
 		cout << arr[0].se + 1 << endl;
 	}
	return 0;
}