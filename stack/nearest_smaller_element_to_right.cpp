#include<bits/stdc++.h>
using namespace std;

int main() {
    
  vector<int> v = {4, 5, 2, 10, 8};
  vector<int> ans;
  
  stack<int> s;
  int n = v.size();
  
  for(int i = n - 1; i >= 0; i--){
    while(!s.empty() && s.top() >= v[i]) s.pop();
    
    if(s.empty()) ans.push_back(-1);
    else ans.push_back(s.top());
    
    s.push(v[i]);
  }
  
  reverse(ans.begin(), ans.end());
  
  for(int a : ans) cout << a << " ";
  
  return 0;
}