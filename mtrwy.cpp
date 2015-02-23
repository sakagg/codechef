
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

class mset
{
	public:
	PI pars[1000][1000];
	int size[1000][1000];
	mset()
	{
		memset(size, 0, sizeof(size));
	}

	void setParent(int r, int c, PI par)
	{
		pars[r][c] = par;
		size[par.f][par.s]++;
	}

	PI getParent(PI node)
	{
		if(pars[node.f][node.s] != node)
			pars[node.f][node.s] = getParent(pars[node.f][node.s]);
		return pars[node.f][node.s];
	}

	void join(PI n1, PI n2)
	{
		PI p1 = getParent(n1);
		PI p2 = getParent(n2);
		if(p1==p2)
			return;
		if(size[p1.f][p1.s] < size[p2.f][p2.s])
			swap(p1, p2);
		pars[p2.f][p2.s] = p1;
		size[p1.f][p1.s] += size[p2.f][p2.s];
	}
};

class cmnd
{
	public:
	int type;
	int x1;
	int y1;
	int x2;
	int y2;
	cmnd() {}
	cmnd(int a, int b=0, int c=0, int d=0, int e=0)
	{
		type = a;
		x1 = b;
		y1 = c;
		x2 = d;
		y2 = e;
	}
};

mset ms;
vector<cmnd> v;
queue<pair<int, int> > q;
int done[1010][1010];
int edges[1010][1010][3];
int mxSize;

void bfs(pair<int, int> start, int n, int m)
{
	q.push(start);
	done[start.f][start.s] = 1;
	while(!q.empty())
	{
		pair<int, int> ele = q.front();
		q.pop();
		ms.setParent(ele.f, ele.s, start);
		if(ele.f > 0 and !done[ele.f-1][ele.s] and edges[ele.f-1][ele.s][2]==0)
		{
			done[ele.f-1][ele.s] = 1;
			q.push(mp(ele.f-1, ele.s));
		}
		if(ele.s > 0 and !done[ele.f][ele.s-1] and edges[ele.f][ele.s-1][1]==0)
		{
			done[ele.f][ele.s-1] = 1;
			q.push(mp(ele.f, ele.s-1));
		}
		if(ele.f < n-1 and !done[ele.f+1][ele.s] and edges[ele.f][ele.s][2]==0)
		{
			done[ele.f+1][ele.s] = 1;
			q.push(mp(ele.f+1, ele.s));
		}
		if(ele.s < m-1 and !done[ele.f][ele.s+1] and edges[ele.f][ele.s][1]==0)
		{
			done[ele.f][ele.s+1] = 1;
			q.push(mp(ele.f, ele.s+1));
		}
	}
}

void preprocess(int n, int m)
{
	for(int i=0; i<n; i++)
	{
		memset(done[i], 0, 4*m);
		memset(ms.size[i], 0, 4*m);
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if(done[i][j])
				continue;
			bfs(mp(i, j), n, m);
			mxSize = max(mxSize, ms.size[i][j]);
		}
}
	
int main()
{	
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n, m, q;
		SI(n); SI(m); SI(q);
		int type;
		v.clear();
		mxSize = 0;
		cmnd cmd;
		for(int i=0; i<q; i++)
		{
			SI(type);
			if(type == 1 || type == 2)
			{
				int x, y;
				SI(x); SI(y);
				x--; y--;
				if(edges[x][y][type] == 0)
				{
					edges[x][y][type]++;
					cmd = cmnd(type, x, y);
					v.pb(cmd);
				}
			}
			else if(type == 3)
			{
				int x1, y1, x2, y2;
				SI(x1); SI(y1); SI(x2); SI(y2);
				x1--; y1--; x2--; y2--;
				cmd = cmnd(type, x1, y1, x2, y2);
				v.pb(cmd);
			}
			else if(type == 4)
			{
				cmd = cmnd(type);
				v.pb(cmd);
			}
		}
		preprocess(n, m);
		LL ans = 0;
		for(vector<cmnd>::iterator it = v.end()-1; it>=v.begin(); it--)
		{
/*			for(int i=0; i<n; i++)
			{
				for(int j=0; j<m; j++)
				{
					PI par = ms.getParent(mp(i, j));
					cout<<par.f<<"-"<<par.s<<"-"<<ms.size[par.f][par.s]<<"\t";
				}
				cout<<endl;
			}
			cout<<endl;
*/			if(it->type == 4)
				ans += mxSize;
			else if(it->type == 3)
				ans += ms.getParent(mp(it->x1, it->y1)) == ms.getParent(mp(it->x2, it->y2));
			else
			{
				edges[it->x1][it->y1][it->type]--;
				if(edges[it->x1][it->y1][it->type] == 0)
				{
					if(it->type == 1)
						ms.join(mp(it->x1, it->y1), mp(it->x1, it->y1+1));
					else
						ms.join(mp(it->x1, it->y1), mp(it->x1+1, it->y1));

					PI par = ms.getParent(mp(it->x1, it->y1));
					mxSize = max(mxSize, ms.size[par.f][par.s]);
				}
			}
		}
/*		for(int i=0; i<n; i++)
			for(int j=0; j<m; j++)
				for(int k=0; k<3; k++)
					assert(edges[i][j][k] == 0);
*/		printf("%lld\n", ans);
	}
	return 0;
}
