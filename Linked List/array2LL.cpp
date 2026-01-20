#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
  int data;
  Node* next;

public:
  Node(int data1, Node* next1) {
    data = data1;
    next = next1;
  }

public:
  Node(int data1) {
    data = data1;
    next = nullptr;
  }
};

Node* convertarr2LL(vector<int>& arr) {
  Node* head = new Node(arr[0]);
  Node* mover = head;

  for (int i = 1; i < arr.size(); i++) {
    Node* temp = new Node(arr[i]);
    mover->next = temp;
    mover = temp;
  }

  return head;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  vector<int> arr = {2, 5, 8, 7};
  Node* head = convertarr2LL(arr);
  cout << head->data;

  return 0;
}