#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& books, int pages) {
  int students = 1;
  int pageStudent = 0;

  for (int i = 0; i < books.size(); i++) {
    if (books[i] + pageStudent <= pages) {
      pageStudent += books[i];
    } else {
      students += 1;
      pageStudent = books[i];
    }
  }

  return students;
}

int findPages(vector<int>& books, int n, int m) { //n is the no. of books and m is the no. of students
  if (m > n) return -1;

  int low = *max_element(books.begin(), books.end());
  int high = accumulate(books.begin(), books.end(), 0);

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (countStudents(books, mid) > m) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return low;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;

    vector<int> books(n);

    for (int i = 0; i < n; i++) {
      cin >> books[i];
    }

    cout << findPages(books, n, m) << "\n";
  }

  return 0;
}