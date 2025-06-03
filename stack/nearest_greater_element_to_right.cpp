#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {1, 3, 2, 4};
  vector<int> ans;
  stack<int> s;
  
  int n = v.size();
  
  for(int i = n - 1; i >= 0; i--) {
    if(s.size() == 0){
      ans.push_back(-1);
    }
    else if(s.size() > 0 && s.top() > v[i]) {
      ans.push_back(s.top());
    }
    else if(s.size() > 0 && s.top() <= v[i]) {
      while(s.size() > 0 && s.top() <= v[i]) {
        s.pop();
      }
      if(s.size() == 0) ans.push_back(-1);
      if(s.top() > v[i]) ans.push_back(s.top());
    }
    
    s.push(v[i]);
  }
  
  reverse(ans.begin(), ans.end());
  
  for(int a : ans) cout << a << " ";
  
  return 0;
}