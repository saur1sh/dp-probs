#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {



public:
	unordered_map<int, int> m;

	int countWays(int ind) {
		if (ind == 0 || ind == 1) return 1;
		if (m.find(ind) != m.end()) return m[ind];
		return m[ind] = (countWays(ind - 1) + countWays(ind - 2));
	}
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	cout << obj.countWays(3);
}
