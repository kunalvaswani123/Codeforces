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
ll a[501][501];
ll b[501][501];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll n,m,i,j;
 	cin >> n >> m;
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 			cin >> a[i][j];
 	}
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<m;j++)
 			cin >> b[i][j];
 	}
 	ll count1;
    ll flag1 = 0;
    for(i=0;i<n;i++)
 	{
        count1 = 0;
 		for(j=0;j<m;j++)
 		{
 			if(a[i][j] != b[i][j])
 				count1++;
 		}
        if(count1 % 2 == 1)
            flag1 = 1;
 	}
    ll count2;
    ll flag2 = 0;
    for(i=0;i<m;i++)
    {
        count2 = 0;
        for(j=0;j<n;j++)
        {
            if(a[j][i] != b[j][i])
                count2++;
        }
        if(count2 % 2 == 1)
            flag2 = 1;
    }
 	if(flag1 == 0 && flag2 == 0)
 		cout << "Yes" << endl;
 	else
 		cout << "No" << endl;
	return 0;
}