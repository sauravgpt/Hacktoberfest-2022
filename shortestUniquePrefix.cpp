#include<bits/stdc++.h>
using namespace std;

struct Trie {
  vector<Trie*> children;
  int count;
  Trie() {
    children.assign(26, nullptr);
    count = 0;
  }
};

Trie* root;

void insert(const string& s) {
  Trie* curr = root;
  for (char c : s) {
    int index = c - 'a';
    if (curr->children[index] == nullptr) {
      curr->children[index] = new Trie();
    }

    curr->count += 1;
    curr = curr->children[index];
  }
}

string findPrefixes(string& s) {

  string res;

  Trie* curr = root;

  res = s[0];
  curr = curr->children[s[0] - 'a'];

  for (int i = 1; i < s.length(); i++) {
    if (curr->count == 1) {
      return res;
    }

    curr = curr->children[s[i] - 'a'];
    res += s[i];
  }

  return res;
}

int main() {

  root = new Trie();

  vector<string> v = { "zebra", "dove", "dog", "duck" };

  for (auto& s : v) insert(s);

  for (auto& s : v) {
    cout << s << " " << findPrefixes(s) << endl;
  }

  return 0;
}