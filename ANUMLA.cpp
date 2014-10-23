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
	int n;
	pair<LL, int> a[33000];
	vector<LL> sums;
	pair<LL, int> *it;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int num = 1<<n;
		sums.resize(0);
		for(int i=0; i<num; i++)
		{
			scanf("%lld", &a[i].f);
			a[i].s = 1;
		}
		sort(a, a+num);
		int count = 0;
		a[0].s = 0;
		for(int i=0; i<num; i++)
		{
			if(a[i].s == 1)
			{
				printf("%lld ", a[i].f);
				a[i].s = 0;
				count++;
				int size = sums.size();
				for(int j=0; j<size; j++)
				{
					LL sm = sums[j]+a[i].f;
					sums.pb(sm);
					it = lower_bound(a, a+num, mp(sm, 1));
						it->s = 0;
				}
				sums.pb(a[i].f);
			}
			if(count == n)
				break;
		}
		printf("\n");
		
	}
	return 0;
}

