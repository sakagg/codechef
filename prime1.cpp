
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

VI p(40000, 1);
VI ps;

void setp(int n, int m)
{
	p = VI();
	if(n==1)
		n++;
	if(n>m)
		return;
	VI tmp(m-n+1, 1);
	EACH(it, ps)
	{
		for(int i=max(n+(*it-n%(*it))%(*it), *it*2); i<=m; i+=(*it))
			tmp[i-n] = 0;
//		print_array_v(tmp);
	}

	for(int i=0; i<m-n+1; i++)
		if(tmp[i])
			p.pb(i+n);
}

int main()
{
	for(int i=2; i<40000; i++)
	{
		if(p[i])
		{
			ps.pb(i);
			for(int j=2*i; j<40000; j+=i)
				p[j] = 0;
		}
	}

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m;
		SI(n); SI(m);
		setp(n, m);
		EACH(it, p)
			printf("%d\n", *it);
		printf("\n");
	}
	return 0;
}
