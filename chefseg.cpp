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

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		LL k;
		double x;
		scanf("%lf %lld", &x, &k);
		LL level;
		for(int i=60; i>=0; i--)
			if(k & (1ULL<<i))
			{
				level = i;
				k -= 1ULL<<i;
				break;
			}
//		printf("%lf %lld %lld\n", x, k, level);
	 	printf("%.9lf\n", x/(1ULL<<(level+1)) + k*(x/(1ULL<<level)));
	}
	return 0;
}

