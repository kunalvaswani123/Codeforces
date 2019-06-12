#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;
#define pival 3.1415926535
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
ll a[1000];
ll b[1000];
ll t[1000][1000];
ll h[1000][1000];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,j,k,n,m,p;
 	cin >> n >> m >> p;
 	for(i=0;i<m;i++)
 		cin >> a[i];
 	for(i=0;i<n;i++)
 		cin >> b[i];
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 			cin >> t[i][j];
 	}
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 		{
 			if(t[i][j] == 1)
 				h[i][j] = a[j];
 			if(h[i][j]>b[i])
 				h[i][j] = b[i];
 		}
 	}
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 			cout << h[i][j] << ' ';
 		cout << endl;
 	}
	return 0;
}