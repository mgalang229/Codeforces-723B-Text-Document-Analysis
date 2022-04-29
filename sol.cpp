#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int longest = 0;
	int words_inside = 0;
	bool within = false;
	auto is_letter = [](char ch) {
		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
	};
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			within = true;
		} else if (s[i] == ')') {
			within = false;
		}
		if (is_letter(s[i])) {
			int id = i;
			while (is_letter(s[id]) && id < n) {
				id++;
			}
			if (!within) {
				longest = max(longest, id - i);
			} else {
				words_inside++;
			}
			i = id - 1;
		}
	}
	cout << longest << " " << words_inside << '\n';
	return 0;
}
