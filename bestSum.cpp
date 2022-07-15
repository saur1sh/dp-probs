#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {


public:
	unordered_map <int, vector<int>> mem;
	vector<int> bestSum(int targetSum, vector<int>& nums) {
		if (mem.find(targetSum) != mem.end())
			return mem[targetSum];
		if (targetSum == 0)
			return vector <int> { -1};
		if (targetSum < 0)
			return vector <int> {};
		vector <int> shortest = {};
		for (auto i : nums) {
			const auto remainder = targetSum - i;
			auto remainderResult = bestSum(remainder, nums);
			if (!remainderResult.empty()) {
				if (remainderResult[0] == -1)
					remainderResult.erase(remainderResult.begin());
				remainderResult.push_back(i);
				if (shortest.size() == 0 || remainderResult.size() < shortest.size()) {
					shortest.clear();
					copy(remainderResult.begin(), remainderResult.end(), back_inserter(shortest));
				}
			}
		}
		mem[targetSum] = shortest;
		return mem[targetSum];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	vector<int> a = {1, 2, 5, 25};
	map<int, bool> mem;
	a = obj.bestSum(100, a);
	if (a.empty())
		cout << "Empty";
	for ( auto i : a)
		cout << i << " ";
}