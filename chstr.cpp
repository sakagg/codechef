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

template<class T> void print_array(T a[], int size) { for(int i=0; i<size; i++) cout<<a[i]+0<<" "; cout<<endl; }

template<class T> void print_array_v(T &a) { int size = a.size(); for(int i=0; i<size; i++) cout<<a[i]<<" "; cout<<endl; }

const int mod = 1e9 + 7;

struct node
{
	node* next[26];
	int cnt;
	node()
	{
		//memset(next, 0, sizeof(next));
		cnt = 0;
	}
};

void dfs(node *root, vector<int> &cnt)
{
	cnt[root->cnt]++;
	for(int i=0; i<26; i++)
		if(root->next[i])
			dfs(root->next[i], cnt);
}

int C[5005][2505];

void fillC()
{
	for(int i=0; i<5005; i++)
		C[i][0] = 1;
	for(int i=0; i<2505; i++)
		C[i][i] = 1;
	for(int i=1; i<5005; i++)
		for(int j=1; j<=(i+1)/2; j++)
		{
			LL tmp = (LL)C[i-1][j] + C[i-1][j-1];
			if(tmp >= mod)
				C[i][j] = tmp - mod;
			else
				C[i][j] = tmp;
			if(i-j<2505)
				C[i][i-j] = C[i][j];
		}
}

int main()
{
	fillC();
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, q; SI(n); SI(q);
		char s[5050]; scanf("%s", s);
		node *root = new node;
		node *it;
		for(int i=0; i<n; i++)
			s[i] -= 'a';
		for(int i=0; i<n; i++)
		{
			it = root;
			for(int j=i; j<n; j++)
			{
				if(!it->next[s[j]])
					it->next[s[j]] = new node;
				it = it->next[s[j]];
				it->cnt++;
				//printf("%d %d %c\n", j, it->cnt, s[j]+'a');
			}
		}
		vector<int> cnt(n+1, 0);
		LL ans[n+1];
		it = root;
		dfs(it, cnt);
		for(int i=1; i<=n; i++)
		{
			ans[i] = 0;
			for(int j=i; j<=n; j++)
			{
				ans[i] += LL(cnt[j])*C[j][min(i, j-i)];
				if(ans[i] <= LL(10)*mod)
					while(ans[i] >= mod)
						ans[i] -= mod;
				else
					ans[i] %= mod;
			}
		}
		int k;
		while(q--)
		{
			SI(k);
			if(k>n)
				printf("0\n");
			else
				printf("%lld\n", ans[k]);
		}
	}
	return 0;
}
