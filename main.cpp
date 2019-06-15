#include <iostream>
#include <typeinfo>
#include "Matrix.hpp"
using namespace std;
int main()
{

    cout<<"Enter the data type of your the matrix"<<endl;
    string type;
    fflush(stdin);
    cin >> type;

    if(type == "int"){

        int nrL;
        int nrC;
        int **data;


        Matrix<int> mat; // Test Constructor fara parametrii

        cin>>mat;  // Test operator <<
        cout<< "Matrix 2 got initialized with Matrix 1 values"<<endl;

        Matrix<int> matInverse,matTranspus,matAdd,matMulti;
        Matrix<int> mat2(mat); // Test constructor copiere
        cout<<"Matrix 1: "<<endl;
        cout <<mat;

        cout << "Inverse of Matrix 1"<<endl;
        matInverse=mat.inverse();  // Test inverse of matrixnt
        cout<< matInverse<<endl;
        cout << "Matrix1 * Matrix2 = "<<endl;
        matMulti=mat*mat2;  //Test operator *
        cout<< matMulti<<endl;
        cout << "Matrix1 + Matrix2 ="<<endl;
        matAdd=mat+mat2;   //Test operator +
        cout<<matAdd<< endl;

        cout<< "Enter values for a new matrix of type int"<<endl;
        cout<< "number of lines :"; cin >> nrL;
        cout<< "number of columns:"; cin >> nrC;
        data= new int* [nrL];
        for(int i = 0; i < nrL; i++)
            data[i] = new int [nrC];
        for(int i = 0; i < nrL; i++ )
        {
            for(int j = 0; j < nrC; j++){
                cout<<"Matrix["<<i<<"]["<<j<<"]";
                cin>>data[i][j];
            }
            cout<< endl;
        }
        Matrix<int> mat3(nrL, nrC,data); // Test constructor cu parametrii
        cout<<"Matrix 3 transpus:" <<endl;
        matTranspus=mat3.transpus(); //Test transpus

        cout<<matTranspus;

        cout << "(Matrix 3)T + Matrix 2 = " << endl;
        matAdd=matTranspus+mat2;
        cout << matAdd;

    }
    else if (type=="float"){
        int nrL;
        int nrC;
        float **data;


        Matrix<float> mat; // Test Constructor fara parametrii

        cin>>mat;  // Test operator <<
        cout<< "Matrix 2 got initialized with Matrix 1 values"<<endl;

        Matrix<float> matInverse,matTranspus,matAdd,matMulti;
        Matrix<float> mat2(mat); // Test constructor copiere
        cout<<"Matrix 1: "<<endl;
        cout <<mat;

        cout << "Inverse of Matrix 1"<<endl;
        matInverse=mat.inverse();  // Test inverse of matrixnt
        cout<< matInverse<<endl;
        cout << "Matrix1 * Matrix2 = "<<endl;
        matMulti=mat*mat2;  //Test operator *
        cout<< matMulti<<endl;
        cout << "Matrix1 + Matrix2 ="<<endl;
        matAdd=mat+mat2;   //Test operator +
        cout<<matAdd<< endl;

        cout<< "Enter values for a new matrix of type float"<<endl;
        cout<< "number of lines :"; cin >> nrL;
        cout<< "number of columns:"; cin >> nrC;
        data= new float* [nrL];
        for(int i = 0; i < nrL; i++)
            data[i] = new float [nrC];
        for(int i = 0; i < nrL; i++ )
        {
            for(int j = 0; j < nrC; j++){
                cout<<"Matrix["<<i<<"]["<<j<<"]";
                cin>>data[i][j];
            }
            cout<< endl;
        }
        Matrix<float> mat3(nrL, nrC,data); // Test constructor cu parametrii
        cout<<"Matrix 3 transpus:" <<endl;
        matTranspus=mat3.transpus(); //Test transpus

        cout<<matTranspus;

        cout << "(Matrix 3)T + Matrix 2 = " << endl;
        matAdd=matTranspus+mat2;
        cout << matAdd;

    }
  else
    cout<< "invalid type";



    return 0;
}
