#include <bits/stdc++.h>
using namespace std;
 
int main() {
  map<string, int> score;  // 名前→成績
  vector<int> a{1,2,3};
  score["Alice"] = 100;
  score["Bob"] = 89;
  score["Charlie"] = 95;
 
  cout << score.at("Alice") << endl;   // Aliceの成績
  cout << score.at("Bob") << endl;     // Bobの成績
  cout << score.at("Charlie") << endl; // Daveの成績
}