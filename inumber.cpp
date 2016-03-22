#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <deque>
#include <string>
#include <set>
#include <limits.h>

#define inp(x) scanf("%d",&x)
#define inp_l(x) scanf("%lld",&x)
#define inp_d(x) scanf("%lf",&x)
#define MOD 1000000007

using namespace std;

typedef long long int ll;
typedef vector <int> VI;
typedef vector <long long int> VLL;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;


pair < ll,PLL> visited[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll t,n,x,y,x1,y1,i,j,diff;
	string ans;
	PLL tmp,tmp1;
	
	cin >> t;
	queue < PLL > Q;
	while ( t-- )
	{
		//visited.clear();
		cin >> n;
		while(!Q.empty())
		{
			Q.pop();
		}
		for(i=0;i<=1000;i++)
		{
			for(j=0;j<=1000;j++)
			{
				visited[i][j].first = -1;
			}
		}
		tmp = make_pair(0ll,0ll);
		Q.push(tmp);
		visited[0][0] = make_pair(0,tmp);

		while(!Q.empty())
		{
			tmp = Q.front();
			Q.pop();
			x = tmp.first;
			y = tmp.second;

			if( x == n && y == 0 )
			{
				ans = "";
				while(true)
				{
					x1 = tmp.first;
					y1 = tmp.second;

					if(visited[x1][y1].first == 0)
						break;

					tmp1 = visited[x1][y1].second;

					diff = x1 - tmp1.first;
					ans = (char)('0' + diff ) + ans;

					tmp = tmp1;
				}
				break;
			}

			for ( i = 0; i < 10; i++)
			{
				x1 = x + i;
				y1 = (y * 10 + i) % n;
				if(x1>n)
					continue;
				tmp1 = make_pair(x1,y1);
				if(visited[x1][y1].first == -1 )
				{
					visited[x1][y1] = make_pair( visited[x][y].first + 1, tmp);
					Q.push(tmp1);
				}
			}
		}

		cout << ans << endl;

	}
	return 0;
}
