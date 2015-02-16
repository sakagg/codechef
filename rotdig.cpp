
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

int tot(LL a)
{
	int cnt = 0;
	while(a)
	{
		cnt++;
		a/=10;
	}
	return cnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL a;
		SLL(a);
		LL b = a;
		LL mx = -1;
		for(int i=0; i<15; i++)
		{
			int digs = tot(a)-1;
			a = a/10 + (a%10)*pow(10, digs);
			mx = max(a, mx);
		}
		for(int i=0; i<15; i++)
		{
			int digs = tot(b);
			LL pw = pow(10, digs);
			b *= 10;
			b = b%pw + b/pw;
			mx = max(b, mx);
		}
		cout<<mx<<endl;
	}
	return 0;
}
