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
int r = 500500;
vi memo(r + 1);
void precal(){
	memo[1] = 0;
	for(int i = 2; i <= r; ++i){
		memo[i] = 1;
		for(int j = 2; j * j <= i; ++j){
			if(i % j == 0){
				memo[i] += j;
				if(j != (i / j)) memo[i] += (i / j);
			}
		}
	}
}
int main(){
	precal();
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << memo[n] << ln;
	}
	return 0;
}

