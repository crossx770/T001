#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include <iostream>
#include <fstream>
#include <cstddef>

using namespace std;
static ofstream e("error.txt");

template<typename T>
class Matrix
{
protected:

    T** data;
    int lines, columns;

public:

    Matrix();
    Matrix(int,int, T** );
    Matrix(const Matrix<T>&);
    Matrix<T>& operator=(const Matrix<T>&);
    const Matrix<T> operator+(const Matrix<T>&);
    const Matrix<T> operator*(const Matrix<T>&);
    const Matrix<T> transpus();
    const Matrix<T> inverse();

    friend ofstream& operator << (ofstream& out, Matrix<T>& mat){

        out<<"number of lines:"<<mat.lines<<endl;
        out<<"Number of columns:"<<mat.columns<<endl;

        for(int i = 0; i < mat.lines; i++ ){
            for(int j = 0; j < mat.columns; j++)
                out<<mat.data[i][j]<<" ";
            out<< endl;
        }

        return out;
    }

    friend ifstream& operator >> (ifstream& in, Matrix<T>& mat){

        int nrLinii,nrColoane;
        in>>nrLinii;
        in>>nrColoane;

        if(mat.data != NULL){
            for(int i=0; i < mat.lines; i++)
                delete[] mat.data[i];
            delete[] mat.data;
        }

        mat.lines=nrLinii;
        mat.columns=nrColoane;
        mat.data=new T* [nrLinii];

        for(int i = 0; i< nrLinii; i++)
            mat.data[i] = new T [nrColoane];

        for(int i = 0; i < nrLinii; i++ )
            for(int j = 0; j < nrColoane; j++)
                in>>mat.data[i][j];


        return in;
    }



    ~Matrix();
};
#endif
