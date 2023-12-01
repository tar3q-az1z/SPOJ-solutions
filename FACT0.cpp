#define _USE_MATH_DEFINES

#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<cstdio>
#include<set>
#include<unordered_set>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<utility>
#include<cstdlib>
using namespace std;
typedef long long int lli;
typedef size_t idx;
#define vi vector<int>
#define vl vector<lli>
#define pb(n) push_back(n)
#define ln "\n"
#define sp ends
#define IT(x) x.begin(), x.end()
#define loop(start, end, incre) for(int i = start; i < end; i += incre)
#define newline cout << ln
const int MOD = 1000000007;
#define precision(n) cout << fixed << setprecision(n) // n places after dec.point
#define fastios ios_base::sync_with_stdio(false); cin.tie(0)

void solve(lli n){
	int cnt = 0;
	while(n % 2 == 0){
		n >>= 1;
		++cnt;
	}
	if(cnt) cout << "2^" << cnt << ' ';
	for(lli d = 3; d * d <= n; d += 2){
		cnt = 0;
		while(n % d == 0){
			n /= d;
			++cnt;
		}
		if(cnt) cout << d << "^" << cnt << ' ';
	}
	if(n > 1) cout << n << "^1" << ln;
}

int main(){
	lli n;
	while(cin >> n && n){
		solve(n);
	}
	return 0;
}

