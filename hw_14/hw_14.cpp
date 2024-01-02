#include <iostream>
#include <vector>

using namespace std;

// 函数用于生成矩阵
vector<vector<int>> generateMatrix(int size) {
    vector<vector<int>> matrix(size, vector<int>(size, 0));//生成二維vector 初始值為0
    int count = 1;

    for (int i = 0; i < size; ++i) {   //印出方陣的值
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = count++;
        }
    }

    return matrix;
}

//相乘
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& matrix) {
    int size = matrix.size();
    vector<vector<int>> result(size, vector<int>(size, 0));

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }

    return result;
}


// 函数用于打印矩阵
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << "\t";
        }
        cout << endl;
    }
}

int main() {
    int size;

    
    cout << "input matrix size：";
    cin >> size;

    
    vector<vector<int>> matrix = generateMatrix(size);
    printMatrix(matrix);
    cout << endl << "matrix multiplied by itself:\n";
    vector<vector<int>> result = multiplyMatrices(matrix);
    printMatrix(result);
    return 0;
}
