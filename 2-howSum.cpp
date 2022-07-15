#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
	unordered_map<int, vector<int>> mem;
	vector<int> howSum(int targetSum, vector<int>& nums) {
		if (mem.find(targetSum) != mem.end())
			return mem[targetSum];
		if (targetSum == 0) return vector<int> { -1};
		if (targetSum < 0) return vector<int> {};
		for (auto i : nums) {
			const auto remainder = targetSum - i;
			auto remainderResult = howSum(remainder, nums);
			if (!remainderResult.empty()) {
				if (remainderResult[0] == -1)
					remainderResult.erase(remainderResult.begin());
				remainderResult.push_back(i);
				mem[targetSum] = remainderResult;
				return mem[targetSum];
			}
		}
		return vector<int> {};
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	vector<int> a = {2, 3, 5};
	vector<int> res;
	map<int, bool> mem;
	res = obj.howSum(8, a);
	if (res.empty())
		cout << "No possible Combination";
	else {
		for (auto i : res)
			cout << i << " ";
	}
}
