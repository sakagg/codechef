
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PI;

#define SI(x) scanf("%d", &x)
#define SLL(x) scanf("%lld", &x)
#define SORTV(v) sort(v.begin(), v.end())
#define EACH(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

LL C(int n, int r)
{
	LL a = 1;
	r = min(r, n-r);
	for(LL i=0; i<r; i++)
	{
		LL gcd = __gcd(a, i+1);
		a /= gcd;
		a *= ((n-i)/((i+1)/gcd));
	}
	return a;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, k;
		SI(n); SI(k);
		cout<<C(n-1, n-k)<<endl;
	}
	return 0;
}
