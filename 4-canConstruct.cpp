#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution {


public:
	unordered_map <string, bool> mem;
	bool canConstruct(string target, vector<string>& wordBank) {
		if (mem.find(target) != mem.end())
			return mem[target];
		if (target == "")
			return true;
		for (auto word : wordBank) {
			int i = 0;
			while (word[i] == target[i] && i < word.length() - 1) i++;
			if (i == word.length() - 1) {
				string newTarget = target.substr(i + 1, sizeof(target));
				mem[target] = canConstruct(newTarget, wordBank);
				if (mem[target])
					return mem[target];
			}
		}
		mem[target] = false;
		return mem[target];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Solution obj;
	vector<string> a = {"ab", "abc", "cd", "def", "abcd"};
	if (obj.canConstruct("abcdef", a))
		cout << "Yes";
	else
		cout << "No";
}
