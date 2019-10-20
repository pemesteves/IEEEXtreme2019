#include <iostream>
#include <vector>

using namespace std;

unsigned long int calculate_perimeter(vector<vector<bool>> & hive, vector<vector<bool>> & visited, int row, int col) {
    
    //cout << "Trying pos " << row+1 << " - " << col+1 << endl;
    
    int col_size = hive[0].size();
    if ((row+1) % 2 == 0) col_size--;
    if (row >= (int)hive.size() || row < 0 || col < 0 || col >= col_size || !hive[row][col]) return 1;
    
    if (visited[row][col]) return 0;
    
    visited[row][col] = true;
    
    unsigned long int perimeter = 0;
    //cout << perimeter << " ";
    
    int next_col = (row+1) % 2 == 0 ? col : col-1;
    perimeter += calculate_perimeter(hive, visited, row-1, next_col);
    
    //cout << perimeter << " ";
    next_col = (row+1) % 2 == 0 ? col+1 : col;
    perimeter += calculate_perimeter(hive, visited, row-1, next_col);
    
    //cout << perimeter << " ";
    perimeter += calculate_perimeter(hive, visited, row, col-1);
    
    //cout << perimeter << " ";
    perimeter += calculate_perimeter(hive, visited, row, col+1);
    
    //cout << perimeter << " ";
    next_col = (row+1) % 2 == 0 ? col : col-1;
    perimeter += calculate_perimeter(hive, visited, row+1, next_col);
    
    //cout << perimeter << " ";
    next_col = (row+1) % 2 == 0 ? col+1 : col;
    perimeter += calculate_perimeter(hive, visited, row+1, next_col);
    
    //cout << perimeter << endl;
    
    
    
    //visited[row][col] = false;
    
    return perimeter;
}

int main() {
    
    int N, M; cin >> N >> M;
    
    int k;
    vector<vector<bool>> hive(N, vector<bool>(M, false));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (((i+1) % 2) == 0 && (j == M-1)) continue;
            
            cin >> k;
            if (k == 1)
                hive[i][j] = true;
        }
    }
    
    unsigned long int Q;
    cin >> Q;
    
    char type;
    int row, col;
    for (unsigned long int i = 0; i < Q; i++) {
        cin >> type >> row >> col;
        
        if(type == 'a') {
            hive[row-1][col-1] = true;
            continue;
        }
        
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        unsigned long per =  calculate_perimeter(hive, visited, row-1, col-1);
        
        cout << ((per == 1) ? 0 : per)  << endl;
    }
    
    
    return 0;
}