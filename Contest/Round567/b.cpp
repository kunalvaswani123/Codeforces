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
string findSum(string str1, string str2) 
{ 
	if(sz(str1) < sz(str2))
		swap(str1,str2);
	ll i,c = 0;
	string ans = "";
	reverse(all(str2));
	ll req = sz(str1)-sz(str2);
	for(i=1;i<=req;i++)
		str2 += '0';
	reverse(all(str2));
	assert(sz(str1)==sz(str2));
	for(i=sz(str1)-1;i>=0;i--)
	{
		ll t1 = str1[i] - '0';	
		ll t2 = str2[i] - '0';
		ll s = t1 + t2 + c;
		c = s / 10;
		char ad = s % 10 + '0';
		ans += ad;
	}
	char tp = c + '0';
	if(tp!='0')
		ans += tp;
    reverse(all(ans)); 
    return ans;
}
string findmin(string s1, string s2)
{
	if(s1.size() < s2.size())
		return s1;
	if(s2.size() < s1.size())
		return s2;
	ll i;
	for(i=0;i<sz(s1);i++)
	{
		if(s1[i] < s2[i])
			return s1;
		else if(s2[i] < s1[i])
			return s2;
	}
	return s1;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll l,i;
 	cin >> l;
 	string s;
 	cin >> s;
	ll t = (l + 1) / 2;
	string a1,a2;
	for(i=t;i<sz(s);i++)
	{
		if(s[i]!='0')
		{
			string s1 = s.substr(0,i);
			string s2 = s.substr(i,l-i);
			a1 = findSum(s1,s2);
			break;
		}
	} 	
	for(i=t-1;i>0;i--)
	{
		if(s[i]!='0')
		{
			string s1 = s.substr(0,i);
			string s2 = s.substr(i,l-i);
			a2 = findSum(s1,s2);
			break;
		}
	}
	if(a1 == "")
		cout << a2 << endl;
	else if(a2 == "")
		cout << a1 << endl;
	else
		cout << findmin(a1,a2) << endl;
	return 0;
}