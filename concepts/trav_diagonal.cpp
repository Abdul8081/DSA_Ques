// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    int rows = 4, cols = 4;
    vector<vector<char>> grid = {{'a','b','c','d'}, {'e','f','g','h'},{'i','j','k','l'}, {'m','n','o','p'}};
    
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    for(int r = rows -1 ; r >=0; r--) {
        int i = r, j = 0;
        
        while(i < rows && j < cols) {
            cout << grid[i][j] << " ";
            i++;
            j++;
        }
        cout << endl;
    }
    for(int c = 1; c < cols; c++) {
        int r = 0, j = c;
        
        while(r < rows && j < cols) {
            cout << grid[r][j] << " ";
            r++;
            j++;
        }
        cout << endl;
    }
}