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
ll a[52][52];
ll b[52][52];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,n,m;
 	cin >> n >> m;
 	for(i=0;i<n;i++)
 		for(j=0;j<m;j++)
 			cin >> a[i][j];
	for(i=0;i<n;i++)
 		for(j=0;j<m;j++)
 			cin >> b[i][j];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			ll temp = min(a[i][j],b[i][j]);
			b[i][j] = max(a[i][j],b[i][j]);
			a[i][j] = temp;
		}
	ll f = 1;
	for(i=0;i<n;i++)
		for(j=1;j<m;j++)
		{
			if(a[i][j] <= a[i][j-1])
				f = 0;
		}
	for(j=0;j<m;j++)
		for(i=1;i<n;i++)
		{
			if(a[i][j] <= a[i-1][j])
				f = 0;
		}
	for(i=0;i<n;i++)
		for(j=1;j<m;j++)
		{
			if(b[i][j] <= b[i][j-1])
				f = 0;
		}
	for(j=0;j<m;j++)
		for(i=1;i<n;i++)
		{
			if(b[i][j] <= b[i-1][j])
				f = 0;
		}
	if(f == 0)
		cout << "Impossible" << endl;
	else
		cout << "Possible" << endl;
	return 0;
}