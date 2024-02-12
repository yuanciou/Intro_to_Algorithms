
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    vector<int> row, col;
    cin >> n;
    row.push_back(1);
    col.push_back(1);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < pow(2, i - 1); j++){
            row.push_back(row[j] + pow(2, (i - 1) * 2));
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < pow(2, i - 1); j++){
            col.push_back(col[j] + pow(2, i * 2 - 1));
        }
    }
    for(int i = 0; i < pow(2, n); i++){
        for(int j = 0; j < pow(2, n); j++){
            cout << row[j] + col[i] - 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}