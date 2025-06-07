#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = {6, 2, 5, 4, 5, 1, 6};
	vector<int> right; // vector for finding the nearest smallest element to right
	vector<int> left; // vector for finding the nearest smallest element to left

	int n = v.size();

	vector<int> width(n); // vector for width of each element of an array
	vector<int> area(n); // vector for the array

	stack<pair<int, int>> s;

	int pseudo_index_left = -1, pseudo_index_right = n;

	for(int i = 0; i < n; i++) {
		while(!s.empty() && s.top().first >= v[i]) s.pop();

		if(s.empty()) left.push_back(pseudo_index_left);
		else left.push_back(s.top().second);

		s.push({v[i], i});
	}

	while(!s.empty()) s.pop();

	for(int i = n - 1; i >= 0; i--) {
		while(!s.empty() && s.top().first >= v[i]) s.pop();

		if(s.empty()) right.push_back(pseudo_index_right);
		else right.push_back(s.top().second);

		s.push({v[i], i});
	}

	reverse(right.begin(), right.end());

	for(int i = 0; i < n; i++) {
		width[i] = right[i] - left[i] - 1;
		area[i] = v[i] * width[i];
	}

	int ans = *max_element(area.begin(), area.end());

	cout << ans << endl;

	return 0;
}