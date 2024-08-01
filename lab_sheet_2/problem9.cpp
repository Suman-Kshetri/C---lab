//  Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to
//  Add Two MATRIX objects. Write a main function to implement it.

#include<iostream>
#define max 10
using namespace std;

class MATRIX{
    int row, cols;
    int matrix[max][max];
    public:
    MATRIX ()
    {
        row=0;
        cols=0;
    };
    MATRIX (int a,int b){
        row=a;
        cols=b;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                matrix[i][j]==0;
            }
        }
    };

    void input(int row, int col){

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                cin>>matrix[i][j];
            }
        }
    }
    friend MATRIX operator + (MATRIX& mat1, MATRIX& mat2);
    void output()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<matrix[i][j]<<"   ";
            }
            cout<<endl;
        }
    }
};
MATRIX operator + (MATRIX & mat1, MATRIX & mat2)
{
    if (mat1.row != mat2.row || mat1.cols != mat2.cols) {
            cout<<"Matrices must have the same dimensions for addition.";
        }
        MATRIX sum_matrix(mat1.row,mat1.cols);
        for(int i=0;i<mat1.row;i++)
        {
            for(int j=0;j<mat2.cols;j++)
            {
                sum_matrix.matrix[i][j]=mat1.matrix[i][j]+mat2.matrix[i][j];
            }
        }
        return sum_matrix;     
} 

int main(){

    int x=0,y=0,a=0,b=0;
    cout<<"Enter the dimension of first matrix: ";
    cin>>x>>y;
    cout<<"Enter the dimension of second matrix: ";
    cin>>a>>b;
    MATRIX mat1(x,y),mat2(a,b);
    cout<<"Enter the elements of first matrix"<<endl;
    mat1.input(x,y);
    cout<<"The first matrix is: "<<endl;
    mat1.output();
    cout<<"Enter the elements of second matrix"<<endl;
    mat2.input(a,b);
    cout<<"The second matrix is: "<<endl;
    mat2.output();
    MATRIX sum_matrix;
    sum_matrix=mat1+mat2;
    cout<<"The sum of matrix is: "<<endl;
    sum_matrix.output();
    return 0;
}