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
#include<utility>
#include<cstdlib>
using namespace std;
typedef long long int lli;
typedef size_t idx;
#define vi vector<int>
#define pb(n) push_back(n)
#define ln "\n"
#define sp ends
#define newline cout << ln
#define fastios ios_base::sync_with_stdio(false); cin.tie(0)

int r = sqrt(1000000000) + 1;
vector<bool> prime(r, true);
vi pl;

void sieve(){
	prime[0] = prime[1] = false;
	for(int i = 2; i * i <= r - 1; ++i){
		if(prime[i]){
			for(int j = i * i; j <= r - 1; j += i) prime[j] = false;
		}
	}
	for(int i = 2; i < r; ++i){
		if(prime[i]) pl.pb(i);
	}
}

int main(){
	int t, m, n;
	sieve();
	cin >> t;
	while(t--){
		cin >> m >> n;
		vector<bool> seg(n - m + 1, true);
		if(m == 1) seg[0] = false;
		for(int i = 0; i < pl.size(); ++i){
			if(pl[i] * pl[i] <= n){
				int d = (m / pl[i]) * pl[i];
				if(d < m) d += pl[i];
				if(d > 0 && d < r){
					if(prime[d]) d += pl[i];
				}
//				if(prime[d]) d += pl[i];
				while(d <= n){
					seg[d - m] = false;
					d += pl[i];
				}
			}else break;
			
		}
		for(int i = 0; i < seg.size(); ++i){
			if(seg[i]) cout << i + m << "\n";
		}
		cout << "\n";
	}
	return 0;
}
