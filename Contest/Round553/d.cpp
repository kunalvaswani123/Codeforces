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
const ll L = 1e5 + 5;
ll arr[2*L];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,b,a,i;
 	cin >> n >> b >> a;
 	ll cb = b;
 	ll ca = a;
 	for(i=0;i<n;i++)
 		cin >> arr[i];
 	for(i=0;i<n;i++)
 	{
 		if(arr[i] == 1)
 		{
 			if(cb > 0)
 			{
 				if(ca != a)
 					cb--,ca++;
 				else
 					ca--;
 			}
 			else if(ca > 0)
 				ca--;
 			else
 			{
 				cout << i << endl;
 				return 0;
 			}
 		}
 		else
 		{
 			if(ca > 0)
 				ca--;
 			else if(cb > 0)
 				cb--;
 			else
 			{
 				cout << i << endl;
 				return 0;
 			}
 		}
 	}
 	cout << i << endl;
	return 0;
}