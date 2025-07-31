#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  int getDecimalValue(ListNode* head) {
    int result = 0;
    while (head) {
      result = (result << 1) | (head->val);
      head = head->next;
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution sol;

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;  // number of nodes in the linked list

    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      ListNode* newNode = new ListNode(x);
      if (!head) {
        head = tail = newNode;
      } else {
        tail->next = newNode;
        tail = newNode;
      }
    }

    cout << sol.getDecimalValue(head) << '\n';

    // Optional: Free memory
    while (head) {
      ListNode* temp = head;
      head = head->next;
      delete temp;
    }
  }

  return 0;
}
