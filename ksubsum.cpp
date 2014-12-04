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

struct comp_opr
{
	bool operator()(LL a, LL b)
	{
		return a>b;
	}
};

priority_queue<LL, vector<LL>, comp_opr> q;

void reduce_to(int size)
{
	while(q.size() > size)
		q.pop();
}

void remove_elements(int num)
{
	for(int i=0; i<num; i++)
		q.pop();
}

int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		q = priority_queue<LL, vector<LL>, comp_opr>();
		int n, k1, k2, k3;
		SI(n); SI(k1); SI(k2); SI(k3);
		LL a[n+1];
		a[0] = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%lld", a+i);
			a[i] += a[i-1];
		}
//		print_array(a, n+1);
		for(int i=1; i<=n; i++)
		{
			for(int j=min(k3, i)-1; j>=0; j--)
				q.push(a[i]-a[j]);
			reduce_to(k3);
		}
/*		while(q.size()>0)
		{
			printf("%lld\n", q.top());
			q.pop();
		}
*/		LL ans3 = q.top();
		remove_elements(k3-k2);
		LL ans2 = q.top();
		remove_elements(k2-k1);
		LL ans1 = q.top();
		printf("%lld %lld %lld\n", ans1, ans2, ans3);
	}
	return 0;
}

