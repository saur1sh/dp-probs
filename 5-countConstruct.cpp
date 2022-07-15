#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {


public:
	unordered_map <string, int> mem;
	int countConstruct(string target, vector<string>& wordBank) {
		if (mem.find(target) != mem.end())
			return mem[target];
		if (target == "")
			return true;
		int total = 0;
		for (auto word : wordBank) {
			int i = 0;
			while (word[i] == target[i] && i < word.length() - 1) i++;
			if (i == word.length() - 1) {
				string newTarget = target.substr(i + 1, sizeof(target));
				int result = countConstruct(newTarget, wordBank);
				total += result;
			}
		}
		return mem[target] = total;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	vector<string> a = {"ab", "abc", "cd", "def", "abcd", "ef"};
	cout << obj.countConstruct("abcdef", a);
}
