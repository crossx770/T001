#include <fstream>
#include <functional>
#include "Matrix.hpp"
using namespace std;
template<typename T>
Matrix<T> :: Matrix(){

    this->lines=0;
    this->columns =0;
    this->data=NULL;
}

template<typename T>
Matrix<T> :: Matrix(int lines, int columns , T** data){

    if(lines > 0 && columns  > 0){
        this->lines = lines;
        this->columns  = columns ;
        this->data=new T* [lines];

        for(int i = 0; i< lines; i++)
            this->data[i] = new T [columns ];

        for(int i = 0; i<lines; i++)
            for(int j = 0; j<columns ; j++)
                this->data[i][j] = data[i][j];
    }
    else{
        this->lines=0;
        this->columns=0;
        this->data=NULL;
    }
}

template<typename T>
Matrix<T>:: Matrix(const Matrix<T>& mat){

    if(mat.columns  > 0 && mat.lines > 0){
        this->lines=mat.lines;
        this->columns =mat.columns ;
        this->data=new T* [mat.lines];

        for(int i = 0; i< mat.lines; i++)
            this->data[i] = new T [mat.columns ];

        for(int i = 0; i<mat.lines; i++)
            for(int j = 0; j<mat.columns ; j++)
                this->data[i][j] = mat.data[i][j];
    }
    else{
        e<<"Failed - number lines/columns invalid"<<endl ;
        this->lines=0;
        this->columns =0;
        this->data=NULL;
    }

}

template<typename T>
Matrix<T>& Matrix<T>:: operator=(const Matrix<T>& mat){

    if(this->data != NULL){
        for(int i = 0;i<this->lines;i++)
            delete[] this->data[i];
        delete[] this->data;
    }

    if((mat.columns  > 0 && mat.lines > 0)&& mat.data != NULL){
        this->lines=mat.lines;
        this->columns =mat.columns ;
        this->data=new T* [mat.lines];

        for(int i = 0; i< mat.lines; i++)
            this->data[i] = new T [mat.columns ];

        for(int i = 0; i<mat.lines; i++)
            for(int j = 0; j<mat.columns ; j++)
                this->data[i][j] = mat.data[i][j];
    }
    else{
        e<<"Failed - number lines/columns invalid"<<endl;
        this->lines=0;
        this->columns =0;
        this->data=NULL;
    }

    return *this;
}

template<typename T>
const Matrix<T> Matrix<T>::operator+(const Matrix<T>& mat){

    Matrix<T> temp(*this);
    if(this->data != NULL && mat.data != NULL){
        if(this->lines == mat.lines && this->columns  == mat.columns ){
            for(int i = 0; i < mat.lines; i++)
                for(int j = 0; j < mat.columns ; j++)
                    temp.data[i][j]=mat.data[i][j] + temp.data[i][j];
        }
        else
            e<<"We can't add , no values changed"<<endl;
    }
    else
        e<<"Matrix has no values"<<endl;

    return temp;
}

template<typename T>
const Matrix<T> Matrix<T>::operator*(const Matrix<T>& mat){

    Matrix<T> temp(mat);
    if(this->data != NULL && mat.data != NULL){
        if(this->columns  == mat.lines){
            for(int i = 0; i < temp.lines; i++)
                for(int j = 0; j < temp.columns ; j++){
                    temp.data[i][j]=0;
                    for(int k = 0; k < this->columns ; k++)
                            temp.data[i][j] =temp.data[i][j] + this->data[i][k]*mat.data[k][j];
                }
        }
        else
            e<<"we can't multiply"<<endl;
    }
    else
        e<<"No values in matrix"<<endl;

    return temp;
}

template<typename T>
const Matrix<T> Matrix<T>::transpus(){

    Matrix<T> temp;
    if(this->data != NULL){
        temp.lines=this->columns ;
        temp.columns =this->lines;
        temp.data=new T* [temp.lines];

        for(int i = 0; i< temp.lines; i++)
            temp.data[i] = new T [temp.columns];

        for(int j = 0; j < temp.columns ; j++)
            for(int i = 0; i <temp.lines;i++)
                temp.data[i][j]=this->data[j][i];
    }
    else
        e<< "matricea este goala"<<endl;

    return temp;
}

template<typename T>
const Matrix<T> Matrix<T>::inverse(){

    Matrix<T> temp(*this);
    float Det=0;
    if(this->data != NULL && this->lines == this->columns ){
        if(this->lines == 1){
            temp.data[0][0]=1/this->data[0][0];
        }

        if(this->lines == 2){
            Det = this->data[0][0]*this->data[1][1]-this->data[1][0]*this->data[0][1];

            if(Det != 0){
                temp.data[0][0] = (this->data[1][1])/Det;
                temp.data[0][1] = (0-this->data[0][1])/Det;
                temp.data[1][1] = (this->data[0][0])/Det;
                temp.data[1][0] = (0-this->data[1][0])/Det;
            }
            else
                e<<"No inverse, no value changed"<<endl;
        }
        else
        if(this->lines == 3){
            Det = this->data[0][0]*this->data[1][1]*this->data[2][2] + this->data[1][0]*this->data[2][1]*this->data[0][2] + this->data[0][1]*this->data[1][2]*this->data[2][0];
            Det = Det - this->data[0][2]*this->data[1][1]*this->data[2][0] - this->data[1][0]*this->data[0][1]*this->data[2][2] - this->data[2][1]*this->data[1][2]*this->data[0][0];
            if(Det != 0){
                temp.data[0][0] = (this->data[1][1]*this->data[2][2]-this->data[1][2]*this->data[2][1])/Det;
                temp.data[1][0] = (-1)*(this->data[1][0]*this->data[2][2]-this->data[1][2]*this->data[2][0])/Det;
                temp.data[2][0] = (this->data[1][0]*this->data[2][1]-this->data[2][0]*this->data[1][1])/Det;
                temp.data[0][1] = (-1)*(this->data[0][1]*this->data[2][2]-this->data[2][1]*this->data[0][2])/Det;
                temp.data[1][1] = (this->data[0][0]*this->data[2][2]-this->data[2][0]*this->data[0][2])/Det;
                temp.data[2][1] = (-1)*(this->data[0][0]*this->data[2][1]-this->data[2][0]*this->data[0][1])/Det;
                temp.data[0][2] = (this->data[0][1]*this->data[1][2]-this->data[1][1]*this->data[0][2])/Det;
                temp.data[1][2] = (-1)*(this->data[0][0]*this->data[1][2]-this->data[1][0]*this->data[0][2])/Det;
                temp.data[2][2] = (this->data[0][0]*this->data[1][1]-this->data[1][0]*this->data[0][1])/Det;
            }
            else
                e<<"No inverse, no value changed"<<endl;
        }
        else
                e<<"No inverse calculated for 4x4 or bigger"<<endl;
    }
    else
        e<<"Matrix isn't nxn"<<endl;
    return temp;
}

template<typename T>
Matrix<T> :: ~Matrix(){

    for(int i=0; i < this->lines; i++)
        delete[] this->data[i];
    delete[] this->data;
}

template class Matrix<int>;
template class Matrix<float>;







