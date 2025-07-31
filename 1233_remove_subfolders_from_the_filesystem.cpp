#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> result;

    unordered_set<string> st(folder.begin(), folder.end());

    for (auto& currFolder : folder) {
      string tempFolder = currFolder;

      bool isSubfolder = false;

      while (!currFolder.empty()) {
        size_t position_of_last_slash = currFolder.find_last_of("/");

        currFolder = currFolder.substr(0, position_of_last_slash);

        if (st.find(currFolder) != st.end()) {
          isSubfolder = true;
          break;
        }
      }

      if (!isSubfolder) {
        result.push_back(tempFolder);
      }
    }

    return result;
  }
};

class Solution2 {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    vector<string> result;

    sort(folder.begin(), folder.end());

    result.push_back(folder[0]);

    for (int i = 1; i < folder.size(); i++) {
      string currFolder = folder[i];

      string lastFolder = result.back();
      lastFolder += '/';

      if (currFolder.find(lastFolder) != 0) {
        result.push_back(currFolder);
      }
    }

    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  Solution1 sol1;
  Solution2 sol2;

  int T;
  cin >> T;
  cin.ignore();

  while (T--) {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> folder;
    string line;
    getline(cin, line);

    istringstream iss(line);
    string path;
    while (iss >> path) {
      folder.push_back(path);
    }

    vector<string> result1 = sol1.removeSubfolders(folder);
    vector<string> result2 = sol2.removeSubfolders(folder);

    for (const auto& it : result1) {
      cout << it << " ";
    }
    cout << "\n";

    for (const auto& it : result2) {
      cout << it << " ";
    }
    cout << "\n";
  }

  return 0;
}