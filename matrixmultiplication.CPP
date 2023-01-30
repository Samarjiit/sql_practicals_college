#include<iostream>
int const rsize=10, csize=10;
// #define rsize 10
// #defien csize 10
using namespace std;

class Matrix {
    int row_size, col_size;
    int Mat[rsize][csize];

   public:
    Matrix(int r ,int c){
        row_size=r;
        col_size=c;
    } 


    void read_matrix();
    void display_matrix();


    friend Matrix operator*(int, Matrix);
};

Matrix operator*(int a, Matrix M){
    Matrix Res(M.row_size,M.col_size);

    for(int i=0;i<M.row_size;i++){
        for(int j=0;j<M.col_size;j++){
            Res.Mat[i][j]=M.Mat[i][j]*a;
        }
    }

    return Res;

}


void Matrix :: read_matrix(){
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            cin>>Mat[i][j];
        }
    }
}
void Matrix :: display_matrix(){
    for(int i=0;i<row_size;i++){
        for(int j=0;j<col_size;j++){
            cout<<Mat[i][j]<<" ";
        }
    }
}


int main(){
    int r,c,x;
    cout<<"enter the dimension of matix1: ";
    cin>>r>>c;

    Matrix M1(r,c);
    cout<<"\n enter the matrix :";
    M1.read_matrix();
    cout<<"enter the x value :";
    cin>>x;

    Matrix M2=x*M1;
    cout<<"\n M1 = \n";
    M1.display_matrix();
    cout<<"\n M2=\n";
    M2.display_matrix();
    return 0;
}