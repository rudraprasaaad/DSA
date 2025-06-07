#include<bits/stdc++.h>
using namespace std;

int main() {
    
  vector<int> v = {4, 5, 2, 10, 8};
  vector<int> ans;
  
  stack<int> s;
  int n = v.size();
  
  for(int i = 0; i < n; i++){
    while(!s.empty() && s.top() >= v[i]) s.pop();
    
    if(s.empty()) ans.push_back(-1);
    else ans.push_back(s.top());
    
    s.push(v[i]);
  }
  
  for(int a : ans) cout << a << " ";
  
  return 0;
}