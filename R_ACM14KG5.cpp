#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second
#define mod 1000000007

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

LL gcd(LL a, LL b)
{
	if (!b)
		return a;
	return gcd(b, a % b);
}

int main()
{	
	int T;
	LL n, k;
	LL ans;
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		SLL(n);
		SLL(k);
		LL c = 1;
		LL rt = sqrt(k);
		LL prev;
		for(int i=1; i<=rt; i++)
		{
			ans += c;
			ans %= mod;
			c = 
	}
	return 0;
}

