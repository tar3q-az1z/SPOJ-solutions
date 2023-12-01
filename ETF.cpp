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
#define loop(start, end, incre) for(int i = start; i < end; i += incre)
#define newline cout << ln
const int MOD = 1000000007;

#define fastios ios_base::sync_with_stdio(false); cin.tie(0)

int r = 1000001;
vi phi(r);
// Euler's totient function
void phi_1_to_n(){
	phi[0] = 0;
	phi[1] = 1;
	for(int i = 2; i < r; ++i) phi[i] = i;
	for(int i = 2; i < r; ++i){
		if(phi[i] == i){
			for(int j = i; j < r; j += i) phi[j] -= phi[j] / i;
		}
	}
}

int main(){
	fastios;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	phi_1_to_n();
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << phi[n] << ln;
	}
	return 0;
}