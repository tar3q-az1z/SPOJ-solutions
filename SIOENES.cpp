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

const int r = 1000002;
vector<bool> prime(r, true);
vector<int> pp(r - 1);
int cnt = 0;

void sieve_prime(){
	prime[0] = false;
	prime[1] = false;
	for(int i = 2; i * i <= r - 1; ++i){
		if(prime[i]){
			++cnt;
			pp[i] = cnt;
			for(int j = i * i; j <= r - 1; j += i){
				prime[j] = false;
				pp[j] = cnt;
			}
		}else pp[i] = cnt;
	}
	for(int i = sqrt(r); i < r - 1; ++i){
		if(prime[i]){
			++cnt;
			pp[i] = cnt;
		}else pp[i] = cnt;
	}
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	sieve_prime();
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << pp[n] << ln;
	}

	return 0;
}