#include <bits/stdc++.h>

using namespace std;

void rotate90degree(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    if (n == 0) return;

    for (int i = 0; i < n; ++i)
    {
        if (matrix.size() != n)
        {
            throw invalid_argument("rotate90degree: The matrix must be square.");
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    cout << "Original Matrix:\n";
    for (const auto& row : matrix)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << "\n"; 
    }

    rotate90degree(matrix);

    cout << "Matrix after rotating 90 degree:\n";
    for (const auto& row : matrix)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << "\n";
    }

    cout << matrix.size() << endl;

    return 0;
}