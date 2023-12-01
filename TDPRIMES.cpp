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
const int MOD = 1000000007;

#define fastios ios_base::sync_with_stdio(false); cin.tie(0)

int r = 100000000;
vector<bool> prime(r, true);
vector<int> lt;
void sieve(){
	prime[0] = prime[1] = false;
	for(int i = 0; i * i <= r - 1; ++i){
		if(prime[i]){
			for(int j = i * i; j <= r - 1; j += i) prime[j] = false;
		}
	}
	int cnt = 1;
	int flag = 0;
	for(int i = 2; i < r; ++i){
		if(prime[i]){
			++flag;
			if(flag == cnt){
				lt.pb(i);
				cnt += 100;
			}
		}
	}
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	sieve();
	for(auto i : lt) cout << i << "\n";
	return 0;
}