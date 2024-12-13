#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &matrix, int n, int m, int i) // matrix is passed by reference
{
    for (int k = 0; k < m; k++)
    { // set all non-zero elements as -1 in row i
        if (matrix[i][k] != 0)
        {
            matrix[i][k] = -1;
        }
    }
}

void markCol(vector<vector<int>> &matrix, int n, int m, int j) // matrix is passed by reference
{
    for (int k = 0; k < n; k++)
    {
        if (matrix[k][j] != 0)
        {
            matrix[k][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) // matrix is passed by reference
{
    // set -1 for rows and cols
    // that contains 0.

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0) // if an element is 0 then
            {
                markRow(matrix, n, m, i); // mark all elements of that row -1
                markCol(matrix, n, m, j); // mark all elements of that col -1
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}

int main()
{

    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
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