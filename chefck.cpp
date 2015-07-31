
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

inline LL fastMod(LL a, LL b)
{
	return a%b;
}

int A[10000010];
int tmp[10000010];

int main()
{
/*	
	int T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	LL n, k, q;
	SLL(n); SLL(k); SLL(q);
	LL a, b, c, d, e, f, r, s, t, m, T, start, sst;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &start);
	A[0] = tmp[0] = start;
	sst = fastMod(start*start, m);
	T = t;
	for(int i=1; i<n; i++)
	{
		T = fastMod(T*t, s);
		if(T <= r)
			start = fastMod(a*sst + b*start + c, m);
		else
			start = fastMod(d*sst + e*start + f, m);
		sst = fastMod(start*start, m);
		A[i] = tmp[i] = start;
	}
//	print_array(A, n);
	int done = 0;
	if(k&1)
	{
		k -= 1;
		done = 1;
	}
	for(int i=1; k; i++)
	{
		LL pw = 1<<(i-1);
		for(int i=0; i+pw<n; i++)
			tmp[i] = min(tmp[i], tmp[i+pw]);
		pw <<= 1;
		if(pw&k)
		{
			for(int i=0; i+done<n; i++)
				A[i] = min(A[i], tmp[i+done]);
			done += pw;
			k -= pw;
		}
	}
//	print_array(A, n);
	LL l1, la, lc, lm, d1, da, dc, dm;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &l1, &la, &lc, &lm, &d1, &da, &dc, &dm);
	LL sum = 0 ;
	LL prod = 1;
	const LL mod = 1e9 + 7;
	for(int i=0; i<q; i++)
	{
		l1 = fastMod(la*l1 + lc, lm);
		d1 = fastMod(da*d1 + dc, dm);
		LL l = l1+1;
		LL r = min(l+k+d1-1, (LL)n);
		LL tans = min(A[l-1], A[r-k]);
		sum += tans;
		prod = fastMod(prod*tans, mod);
	}
	cout<<sum<<" "<<prod<<"\n";
	return 0;
}
