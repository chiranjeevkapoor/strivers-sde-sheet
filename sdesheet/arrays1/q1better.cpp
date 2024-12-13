#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int row[m] = {0};
    int col[n] = {0};
    // marking all the posns 1
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1; // ith row is marked
                col[j] = 1; // ith col is marked
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j]) // checks if a row or col is marked 1(non-zero)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main()
{

    vector<vector<int>> matrix = {{-1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);

    for (auto it : ans)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << "\n";
    }
    return 0;
}