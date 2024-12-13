#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m)
{
    int col0 = 1;
    // marking row and col
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0; // mark row
                if (j != 0)       // mark col
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }
    // return matrix;

    // mark from (1,1) to (n-1,m-1)

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            { // checking row and col
                matrix[i][j] = 0;
            }
        }
    }

    // updating col[horizontal] first and then row[vertical] as row is dependent on col
    if (matrix[0][0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
    // now row
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    return matrix;
}

int main()
{

    vector<vector<int>> matrix = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 1}};
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