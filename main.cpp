#include <iostream>
#include <fstream>
#include "Matrix.hpp"
using namespace std;
int main(int argc, char *argv[])
{
    ifstream f(argv[1]);
    ofstream g("output.txt");
    g << "Data type of your the matrix is ";
    string type;
    f >> type;
    g << type << endl;
    if(type == "int")
    {
        int nrL;
        int nrC;
        int **data;
        Matrix<int> mat; // Test Constructor fara parametrii

        f >> mat;  // Test operator <<
        g << "Matrix 2 got initialized with Matrix 1 values\n";

        Matrix<int> matInverse,matTranspus,matAdd,matMulti;
        Matrix<int> mat2(mat); // Test constructor copiere
        g << "\nMatrix 1: \n";
        g << mat << endl;

        g << "Inverse of Matrix 1\n";
        matInverse=mat.inverse();  // Test inverse of matrixnt
        g << matInverse << endl;
        g << "Matrix1 * Matrix2 = \n";
        matMulti=mat*mat2;  //Test operator *
        g << matMulti << endl;
        g << "Matrix1 + Matrix2 =\n";
        matAdd=mat+mat2;   //Test operator +
        g << matAdd << endl;

        f >> nrL;
        f >> nrC;

        data= new int* [nrL];
        for(int i = 0; i < nrL; i++)
            data[i] = new int [nrC];

        for(int i = 0; i < nrL; i++ )
            for(int j = 0; j < nrC; j++)
                f>>data[i][j];


        Matrix<int> mat3(nrL, nrC,data); // Test constructor cu parametrii
        g << "Matrix 3 transpus:\n";
        matTranspus=mat3.transpus(); //Test transpus

        g << matTranspus<<endl;

        g << "(Matrix 3)T + Matrix 2 = \n";
        matAdd=matTranspus+mat2;
        g << matAdd;
    }
    else if (type=="float"){
        int nrL;
        int nrC;
        float **data;
        Matrix<float> mat; // Test Constructor fara parametrii

        f >> mat;  // Test operator <<
        g << "Matrix 2 got initialized with Matrix 1 values\n";

        Matrix<float> matInverse,matTranspus,matAdd,matMulti;
        Matrix<float> mat2(mat); // Test constructor copiere
        g << "\nMatrix 1: \n";
        g << mat << endl;

        g << "Inverse of Matrix 1\n";
        matInverse=mat.inverse();  // Test inverse of matrixnt
        g << matInverse << endl;
        g << "Matrix1 * Matrix2 = \n";
        matMulti=mat*mat2;  //Test operator *
        g << matMulti << endl;
        g << "Matrix1 + Matrix2 = \n";
        matAdd=mat+mat2;   //Test operator +
        g << matAdd << endl;
        f >> nrL;
        f >> nrC;
        data= new float* [nrL];
        for(int i = 0; i < nrL; i++)
            data[i] = new float [nrC];

        for(int i = 0; i < nrL; i++ )
            for(int j = 0; j < nrC; j++)
                f>>data[i][j];

        Matrix<float> mat3(nrL, nrC,data); // Test constructor cu parametrii
        g << "Matrix 3 transpus:\n";
        matTranspus=mat3.transpus(); //Test transpus

        g << matTranspus << endl;

        g << "(Matrix 3)T + Matrix 2 = \n";
        matAdd=matTranspus+mat2;
        g << matAdd;

    }
    else
        g << "invalid type";


    return 0;
}
