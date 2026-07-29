#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>matrix = {{1, 0,3}};
    int m = matrix.size();
    int n = matrix[0].size();
    bool isAffected = false;
    if(matrix[0][0] == 0 ) isAffected = true;
    for (int i = 0; i< m; i++){
        for(int j = 0 ; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
       for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                int j = 1;
                while (j < n) {
                    matrix[i][j] = 0;
                    j++;
                }
            }
        }
      if(isAffected){
             int i = 0;
             int j = 0;
            while(j<n){
                matrix[0][j] = 0;
                j++;
            }
             while(i<m){
                matrix[i][0] = 0;
                i++;
            }
        }
        cout << "After Modificaiton : " << endl;
        for (int i = 0; i< m; i++){
        for(int j = 0 ; j < n; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}