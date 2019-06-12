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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll i,n;
 	cin >> n;
 	string s;
 	cin >> s;
 	ll m = 0;
 	ll l = 0;
 	ll c = 0;
 	ll stl,stm;
 	for(i=0;i<n;i++)
 	{
 		if(s[i] == '(')
 			m++;
 		else if(s[i] == ')')
 			l++;
 		else
 			c++;
 	}
 	stl = l;
 	stm = m;
 	ll f = 0;
 	if(m > l)
 	{
 		if(c >= (m-l))
 			c -= (m-l);
 		else
 			f = 1;
 		l = m;
 	}
 	else if(l > m)
 	{
 		if(c >= (l-m))
 			c -= (l-m);
 		else
 			f = 1;
 		m = l;
 	}
 	if(f == 1)
 	{
 		cout << ":(" << endl;
 		return 0;
 	}

 	if(c%2 == 0)
 	{
 		m += c / 2;
 		l = m;
 	}
 	else
 		f = 1;

 	if(f == 1)
 	{
 		cout << ":(" << endl;
 		return 0;
 	}
 	ll p1 = 0;
 	ll all = m - stm;
 	for(i=0;i<n;i++)
 	{
 		if(s[i] == '?')
 		{
 			if(p1<all)
 			{
 				s[i] = '(';
 				p1++;
 			}
 			else 
 				s[i] = ')';
 		}
 	}
 	c = 0;
 	for(i=0;i<n;i++)
 	{
 		if(s[i] == '(')
 			c++;
 		else
 			c--;
 		if(i!=n-1 && c<=0)
 		{
 			cout << ":(" << endl;
	 		return 0;
 		}
 		if(s[i] == '?')
 		{
 			cout << ":(" << endl;
	 		return 0;	
 		}
 	}
 	if(c==0)
	 	cout << s << endl;
	else
		cout << ":(" << endl;
	return 0;
}