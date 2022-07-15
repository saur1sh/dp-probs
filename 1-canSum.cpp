#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
	unordered_map<int, bool> mem;
	bool canSum(int targetSum, vector<int> &nums) {
		if (mem.find(targetSum) != mem.end())
			return mem[targetSum];
		if (targetSum == 0)
			return true;
		if (targetSum < 0)
			return false;
		for (auto i : nums) {
			if (canSum(targetSum - i, nums))
				return mem[targetSum] = true;
		}
		return mem[targetSum] = false;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	vector<int> a = {7, 14};
	if (obj.canSum(300, a))
		cout << "Yes";
	else
		cout << "No";
}
