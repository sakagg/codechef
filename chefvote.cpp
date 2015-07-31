
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

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n; SI(n);
		pair<int, int> a[100];
		int sum = 0, poss = 1;
		for(int i=0; i<n; i++)
		{
			SI(a[i].f);
			a[i].s = i;
			sum += a[i].f;
			poss &= a[i].f<n;
		}
		if(!poss || sum!=n || n==1)
		{
			printf("-1\n");
			continue;
		}
		vector<int> vote(100, -1);
		int left = -1;
		sort(a, a+n, greater<pair<int, int> >());
		for(int i=1; i<n; i+=2)
			if(a[i].f > 0)
			{
				a[i].f--;
				a[i-1].f--;
				vote[a[i].s] = a[i-1].s;
				vote[a[i-1].s] = a[i].s;
			}
			else
			{
				if(a[i-1].f!=0)
					left = i-1;
				break;
			}
		if(left == -1 && n%2 == 1 && a[n-1].f!=0)
			left = n-1;
		if(left != -1)
		{
			int tmp = a[0].s;
			a[left].f--;
			vote[a[left].s] = vote[tmp];
			vote[tmp] = a[left].s;
		}
		sort(a, a+n, greater<pair<int, int> >());
		int j = 0;
		for(int i=0; i<n; i++)
			while(a[i].f)
			{
				if(vote[j] == -1)
				{
					vote[j] = a[i].s;
					a[i].f--;
				}
				j++;
			}
		for(int i=0; i<n; i++)
			printf("%d ", vote[i]+1);
		cout<<endl;
	}
	return 0;
}
