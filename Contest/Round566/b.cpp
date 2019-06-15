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
char arr[505][505];
ll c[505][505];  
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll h,w,i,j;
 	cin >> h >> w;
 	string s;
 	for(i=0;i<h;i++)
 	{
 		cin >> s;
 		for(j=0;j<w;j++)
 			arr[i][j] = s[j];
 	}
 	ll f = 0;
 	ll indi = 0;
 	ll indj = 0;
 	ll ch = 0;
 	for(i=0;i<h;i++)
 	{
 		for(j=0;j<w;j++)
 		{
 			if(i == 0 || j == 0)
 				continue;
 			if(i == h-1 || j == w-1)
 				continue;
 			if(arr[i][j] == '*')
 			{
 				if(arr[i+1][j] == '*' && arr[i-1][j] == '*' && arr[i][j+1] == '*' && arr[i][j-1] == '*')
	 				ch = 1, indi = i, indj = j;
 			}
 			if(ch == 1)
 				break;
 		}
 		if(ch == 1)
 			break;
 	}
    if(ch == 0)
        f = 1;
 	for(i=indi;i>=0;i--)
 	{
 		if(arr[i][indj] == '*')
 			c[i][indj] = 1;
 		else
 			break;
 	}
 	for(i=indi;i<h;i++)
 	{
 		if(arr[i][indj] == '*')
 			c[i][indj] = 1;
 		else
 			break;
 	}
 	for(i=indj;i>=0;i--)
 	{
 		if(arr[indi][i] == '*')
 			c[indi][i] = 1;
 		else
 			break;
 	}
 	for(i=indj;i<w;i++)
 	{
 		if(arr[indi][i] == '*')
 			c[indi][i] = 1;
 		else
 			break;
 	}
 	for(i=0;i<h;i++)
 		for(j=0;j<w;j++)
 			if(arr[i][j] == '*' && c[i][j] == 0)
 				f = 1;
 	if(f == 0)
 		cout << "YES" << endl;
 	else
 		cout << "NO" << endl;
	return 0;
}