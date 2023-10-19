/*
Name of Program: EECS 348 lab 6
Description: read matrix data from a file, perform matrix operations, and output the results
Inputs: user matrix
Outputs: Pthe result of the matrix operations
Author: Reeny Huang
Creation Date: 10/18/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//this defines a structure to hold 2 matrices
struct MatrixPair {
    std::vector<std::vector<int>> matrix1;
    std::vector<std::vector<int>> matrix2;
};
//this calls the function before main
MatrixPair readMatrix(const string fileName);

int main(){
    string fileName = "matrix_input.txt";
    MatrixPair matrices = readMatrix(fileName);
    vector<vector<int>> matrix1 = matrices.matrix1;
    vector<vector<int>> matrix2 = matrices.matrix2;
    cout <<"Reeny Huang\n";
    cout << "Lab #6: Matrix Manipulation\n";
    //this following prints out matrix A
    cout << "Matrix A:\n";
    for (int i=0;i<matrix1.size(); i++){
        for (int j=0;j<matrix1.size();j++){
            cout<<matrix1[i][j] << ' ';
        }
        cout <<endl;
    }
    //the following prints out matrix B
    cout << "Matrix B:\n";
    for (int i=0;i<matrix2.size(); i++){
        for (int j=0;j<matrix2.size();j++){
            cout<<matrix2[i][j] << ' ';
        }
        cout <<endl;
    }
    //thsi prints out the sum of two matrices
    cout<<"Matrix Sum (A + B):\n";
    if (matrix1.size() == matrix2.size()){
        for (int i = 0;i<matrix1.size();i++){
            for (int j=0;j<matrix1.size();j++){
                cout<<matrix1[i][j]+matrix2[i][j]<<' ';
            }
            cout <<endl;
        }
    }
    else{
        cout<<"This operation can not be done because of size difference\n";
    }
    //this prints out the product of the two matrices, assume both matrices are the same sizes
    cout<<"Matrix Product (A * B):\n";
    for (int i = 0;i<matrix1.size();i++){
        for (int j=0;j<matrix1.size();j++){
            cout<<matrix1[i][j]*matrix2[j][i]<<' ';
        }
        cout <<endl;
    }
    //this prints out the difference between the two matrices, assume both matrices are the same size
    cout<<"Matrix Difference (A - B):\n";
    for (int i = 0;i<matrix1.size();i++){
        for (int j=0;j<matrix1.size();j++){
            cout<<matrix1[i][j]-matrix2[i][j]<<' ';
        }
        cout <<endl;
    }
    return 0;
}

//this function uses the vector library to read in matrix data from a file
MatrixPair readMatrix (const string fileName){
    MatrixPair result;
    int n;
    string line;
    int i = 0;
    int size = 0;

    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return result;
    }

    while (getline(inputFile, line)){
        vector<int> row;
        int num;
        istringstream iss(line);
        if (i == 0){
            iss >> size;
        } else if(i <= size){
                while (iss >> num) {
                    row.push_back(num);
                }
                result.matrix1.push_back(row);
            } else if (size < i && i <= (size*2)){
                while (iss >> num) {
                    row.push_back(num);
                }
                result.matrix2.push_back(row);
            }
            i++;
        }
    inputFile.close();
    return result;
}