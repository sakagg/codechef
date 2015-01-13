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

class node
{
	public:

	node *next[2];
	node()
	{
		next[0] = next[1] = NULL;
	}
};

void add(node *root, int num)
{
	for(int i=30; i>=0; i--)
	{
		int dig = (num>>i)&1;
		if(root->next[dig]==NULL)
			root->next[dig] = new node;
		root = root->next[dig];
	}
}

int getmax(node *root, int num)
{
	int oth = 0;
	for(int i=30; i>=0; i--)
	{
		int dig = 1-((num>>i)&1);
		if(root->next[dig] == NULL)
		{
			root = root->next[1-dig];
			oth |= ((1-dig)<<i);
		}
		else
		{
			root = root->next[dig];
			oth |= (dig<<i);
		}
	}
	return oth^num;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		node *root = new node;
		int n;
		SI(n);
		int a[100100];
		a[0] = 0;
		add(root, 0);
		int ans = 0;
		for(int i=1; i<=n; i++)
		{
			SI(a[i]);
			a[i] ^= a[i-1];
			add(root, a[i]);
		}
//		print_array(a, n+1);
		for(int i=1; i<=n; i++)
			ans = max(ans, getmax(root, a[i]));
		printf("%d\n", ans);
	}
	return 0;
}
