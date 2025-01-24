#include<iostream>
#include<cstring>
int dfs(int a, int b, int n);
int dp[20][20];
using namespace std;
int main() {
	memset(dp, -1, sizeof(dp));
	int n = 0;
	cin >> n;
	int ans = dfs(0, 0, n);
	cout << ans;
}
int dfs(int a, int b, int n) {
	int result = 0;
	if (dp[a][b] != -1) {
		return dp[a][b];
	}
	if (a+b==n) {
		return 1;
	}
	else if (a == 0 && b != 0) {
		result += dfs(1, b - 1, n);
		result += dfs(0, b + 1, n);
	}
	else if (b == 0) {
		result += dfs(a, 1, n);
	}
	else {
		result += dfs(a, b + 1, n);
		result += dfs(a + 1, b - 1, n);
	}
	dp[a][b] = result;
	return result;
}