#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
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

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,i,p = 63ll,ans;
	
	cin >> n;
	VLL arr(n),tmp;
	for( i = 0 ; i < n ; i ++ )
	{
		cin >> arr[i];
	}

	while ( true )
	{
		ll mx = -1, pos = -1;
		for ( i = 0 ; i < n ; i++ )
		{
			if( arr[i]> mx)
			{
				mx = arr[i];
				pos = i;
			}
		}

		if(mx == -1 || mx == 0 || pos == -1)
			break;

		arr[pos] = -1;

		p = 63ll;

		while(p>=0 && (mx >> p)==0)
		{
			p--;
		}
		//cout << mx << " " << p << endl;
		if(p<0)
			break;

		for( i = 0 ; i < n ; i++ )
		{
			if(arr[i]!=-1 && (arr[i] >> p) > 0 )
			{
				//cout << arr[i] << " ";
				arr[i] = arr[i] ^ mx;
			}
		}
		//cout << endl ;
		tmp.push_back(mx);
	}
	ans = 0ll;

	for( i = 0; i < tmp.size(); i++ )
	{
		if((ans ^ tmp[i]) > ans)
			ans = ans ^ tmp[i];
	}

	cout << ans << endl;
	return 0;
}
