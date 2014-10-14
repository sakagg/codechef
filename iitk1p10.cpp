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
	for(int i=1; i<=size; i++)
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

vector<LL> edges[100100];
LL parent[100100] = {0}, zeros[100100]={0}, a[100100] = {0};

void bfs()
{
	queue<LL> q;
	LL num, cur;
	q.push(1);
	parent[1] = 1;
	while(!q.empty())
	{
		num = q.front();
		q.pop();
		for(LL i=edges[num].size()-1; i>-1; i--)
		{
			cur = edges[num][i];
			if(parent[cur])
				continue;
			parent[cur] = num;
			q.push(cur);
		}
	}
}

void add(LL a[], LL u, LL v, int first = 0)
{
	LL change = 0;
	if(!first && (a[u] == 0))
		change -= 1;
	a[u] += v;
	if(a[u] == 0)
		change += 1;
	if(change)
	{
		for(LL i = u; i!=parent[i]; i = parent[i])
			zeros[i] += change;
		zeros[1] += change;
	}
}

int main()
{
/*	
	LL T;
	scanf("%d", &T);
	while(T--)
	{

	}
*/
	LL n, q, u, v;
	scanf("%lld%lld", &n, &q);
	for(LL i=1; i<n; i++)
	{
		scanf("%lld%lld", &u, &v);
		edges[u].pb(v);
		edges[v].pb(u);
	}
	bfs();
	LL num;
	for(LL i=1; i<=n; i++)
	{
		scanf("%lld", &num);
		add(a, i, num, 1);
	}
	char ch[2];
//	print_array(zeros, n);
//	print_array(a, n);
	while(q--)
	{
		scanf("%s %lld", ch, &u);
		if(ch[0]=='Q')
			printf("%lld\n", zeros[u]);
		else if(ch[0] == 'U')
		{
			scanf("%lld", &v);
			add(a, u, v);
		}
	}
	return 0;
}
