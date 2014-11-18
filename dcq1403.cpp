#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size)
{
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

template<class T> void print_array_v(T &a)
{
	int size = a.size();
	for(int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

const LL mod = 1e9 + 7;

LL modPow(LL a, LL b)
{
	LL ret = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	LL t, n;
	SLL(t);
	while (t--)
	{
		SLL(n);
/*		LL d[100], s[100];
		d[1] = 6, s[1] = 6;
		for(int i=2; i<=15; i++)
		{
			d[i] = 2*(d[i-1]+s[i-1]);
			s[i] = d[i];
		}
		for(int i=1; i<=15; i++)
			printf("%lld\n", d[i]+s[i]);
*/		printf("%lld", (3*modPow(4, n))%mod);
	}
	return 0;
}

