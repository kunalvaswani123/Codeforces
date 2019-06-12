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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 	ll x1,y1,x2,y2;
 	cin>>x1>>y1>>x2>>y2;
 	ll n;
 	cin >> n;
 	string s;
 	cin >> s;
 	ll cx = 0, cy = 0;
 	ll i;
 	ll tempans = 0;
 	ll tx1 = x1, ty1 =y1;
 	for(i=0;i<n;i++)
 	{
 		if(x2 == tx1 && y2 == ty1)
 			break;
 		if(s[i]=='U')
 		{
 			if(y2 > ty1)
 			{
 				ty1 += 1;
 				if(x2<tx1)
 					tx1 -= 1;
 				else if(x2>tx1)
 					tx1 += 1;
 				else if (y2 > ty1)
 					ty1 += 1;
 			}
 		}
 		else if(s[i]=='D')
 		{
 			if(y2 < ty1)
 			{
 				ty1 -= 1;
 				if(x2<tx1)
 					tx1 -= 1;
 				else if(x2>x1)
 					tx1 += 1;
 				else if(y2 < ty1)
 					ty1 -= 1;
 			}
 		}
 		else if(s[i]=='L')
 		{
 			if(x2 < tx1)
 			{
 				tx1 -= 1;
 				if(y2<ty1)
 					ty1 -= 1;
 				else if(y2>y1)
 					ty1 += 1;
 				else if(x2 < tx1)
 					tx1 -= 1;
 			}
 		}
 		else
 		{
 			if(x2 > tx1)
 			{
 				tx1 += 1;
 				if(y2<ty1)
 					ty1 -= 1;
 				else if(y2>y1)
 					ty1 += 1;
 				else if(x2 > tx1)
 					tx1 += 1;
 			}
 		}
 		tempans++;
 	}
	if(x2 == tx1 && y2 == ty1)
	{
		cout << tempans << endl;
		return 0;
	}

 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='U')
 		{
 			if(y2 > y1)
 			{
 				cy += 1;
 				if(x2<x1)
 					cx -= 1;
 				else if(x2>x1)
 					cx += 1;
 				else
 					cy += 1;
 			}
 		}
 		else if(s[i]=='D')
 		{
 			if(y2 < y1)
 			{
 				cy -= 1;
 				if(x2<x1)
 					cx -= 1;
 				else if(x2>x1)
 					cx += 1;
 				else 
 					cy -= 1;
 			}
 		}
 		else if(s[i]=='L')
 		{
 			if(x2 < x1)
 			{
 				cx -= 1;
 				if(y2<y1)
 					cy -= 1;
 				else if(y2>y1)
 					cy += 1;
 				else
 					cx -= 1;
 			}
 		}
 		else
 		{
 			if(x2 > x1)
 			{
 				cx += 1;
 				if(y2<y1)
 					cy -= 1;
 				else if(y2>y1)
 					cy += 1;
 				else
 					cx += 1;
 			}
 		}
 	}
 	ll ch1,ch2;
 	
 	if(cx!=0)
	 	ch1 = abs(x2-x1)/abs(cx);
	else
		ch1 = 1e18;
	
	if(cy!=0)
	 	ch2 = abs(y2-y1)/abs(cy);
	else
		ch2 = 1e18;

	ll fans = 0;
	if(cx==0&&cy==0)
		fans = 0;
	else
		fans=min(ch1,ch2);

	ll sch1 = fans * cx + x1;
	ll sch2 = fans * cy + y1;
	fans *= n;
	for(i=0;i<n;i++)
	{
 		if(x2 == sch1 && y2 == sch2)
 			break;
		if(s[i]=='U')
 		{
 			if(y2 > sch2)
 			{
 				sch2 += 1;
 				if(x2<sch1)
 					sch1 -= 1;
 				else if(x2>sch1)
 					sch1 += 1;
 				else if (y2 > sch2)
 					sch2 += 1;
 			}
 		}
 		else if(s[i]=='D')
 		{
 			if(y2 < sch2)
 			{
 				sch2 -= 1;
 				if(x2<sch1)
 					sch1 -= 1;
 				else if(x2>sch1)
 					sch1 += 1;
 				else if(y2 < sch2)
 					sch2 -= 1;
 			}
 		}
 		else if(s[i]=='L')
 		{
 			if(x2 < sch1)
 			{
 				sch1 -= 1;
 				if(y2<sch2)
 					sch2 -= 1;
 				else if(y2>sch2)
 					sch2 += 1;
 				else if (x2 < sch1)
 					sch1 -= 1;
 			}
 		}
 		else
 		{
 			if(x2 > sch1)
 			{
 				sch1 += 1;
 				if(y2<sch2)
 					sch2 -= 1;
 				else if(y2>sch2)
 					sch2 += 1;
 				else if (x2 > sch1)
 					sch1 += 1;
 			}
 		}
 		fans++;
	}
	if(x2 == sch1 && y2 == sch2)
 		cout << fans << endl;
 	else
 		cout << "-1" << endl;
	return 0;
}