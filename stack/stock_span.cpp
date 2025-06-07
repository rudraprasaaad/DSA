#include<bits/stdc++.h>
using namespace std;

// just a variation of nearest greater element to left
int main() {
    
  vector<int> v = {100, 80, 60, 70, 60, 75, 85};
  vector<int> ans;
  
  stack<pair<int, int>> s;
  int n = v.size();
  
  for(int i = 0; i < n; i++) {
    while(!s.empty() && s.top().first <= v[i]) s.pop();
    
    if(s.empty()) ans.push_back(-1);
    else ans.push_back(s.top().second);
    
    s.push({v[i], i});
  }
  
  for(int i = 0; i < n; i++) {
	ans[i] = i - ans[i];
  }
  
  for(int a : ans) cout << a << " ";
  
  return 0;
}