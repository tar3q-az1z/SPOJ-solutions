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

int r = 1000005;
vector<bool> prime(r, true);

void isprime(){
	prime[0] = false;
	prime[1] = false;
	for(int i = 2; i * i < r; ++i){
		if(prime[i]){
			for(int j = i * i; j < r; j += i) prime[j] = false;
		}
	}
}

int f(int a){
	if(a == 1) return a;
	if(a == 2) return a;
	if(a == 0 || prime[a]) return 0;
	int temp;
	for(int i = 2; i * i <= a; ++i){
		if(a % i == 0){
			temp = f(i) + f(a / i);
			break;
		}
	}
	return temp;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int x;
	isprime();
	cin >> x;
	if(x == 0) cout << x << ln;
	else if(x == 1) cout << x << ln;
	else if(x == 2) cout << x << ln;
	else if(prime[x]) cout << 0 << ln;
	else if(floor(log2(x)) == ceil(log2(x))){
		cout << floor(log2(x)) * 2 << ln;
	}
	else{
		for(int i = 2; i * i <= x; ++i){
			if(x % i == 0){
				cout << f(i) + f(x / i) << ln;
				break;
			}
		}
	}
	return 0;
}