#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED
#include <iostream>
#include <cstddef>
#include <type_traits>

using namespace std;


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

    //Din cauza unor probleme de compilare am pastrat operatorul in hpp.
    friend ostream& operator << (ostream& out, Matrix<T>& mat){
        out<<"number of lines:"<<mat.lines<<endl;
        out<<"Number of columns:"<<mat.columns<<endl;
        for(int i = 0; i < mat.lines; i++ )
        {
            for(int j = 0; j < mat.columns; j++)
                out<<mat.data[i][j]<<" ";
            out<< endl;
        }
        return out;

    }

    friend istream& operator >> (istream& in, Matrix<T>& mat){
        int nrLinii,nrColoane;

        cout<<"Number of lines:";in>>nrLinii;
        cout<<endl;
        cout<<"Number of columns:";in>>nrColoane;
        cout<<endl;
        mat.lines=nrLinii;
        mat.columns=nrLinii;
        if(mat.data != NULL){
            for(int i=0; i < mat.lines; i++)
                delete[] mat.data[i];
            delete[] mat.data;
        }
        mat.data=new T* [nrLinii];
        for(int i = 0; i< nrLinii; i++){
            mat.data[i] = new T [nrColoane];
        }
        cout<<"Introduceti valori pentru matrice"<<endl;
        for(int i = 0; i < nrLinii; i++ )
        {
            for(int j = 0; j < nrColoane; j++){
                cout<<"Matrix["<<i<<"]["<<j<<"]";
                cin>>mat.data[i][j];
            }
            cout<< endl;
        }

        return in;

    }



    ~Matrix();
};
#endif
