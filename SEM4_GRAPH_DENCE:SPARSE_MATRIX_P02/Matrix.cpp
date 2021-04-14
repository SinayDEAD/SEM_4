//
//  Matrix.cpp
//
//  Created by MacBook on 28.03.2021.
//

#include "Matrix.hpp"
#include "IterableSparseMatrix.hpp"
#include "IterableDenseMatrix.hpp"
#include "IterableSquareMatrix.hpp"

Matrix::Matrix(size_t i){
    Matrixx = new IterableSparseMatrix(i);
    type = false;
}

Matrix::~Matrix(){
    delete Matrixx; //???
}

size_t Matrix::GetSize() const{
    return Matrixx->GetSize();
}

double Matrix::FindMax() const{
    return Matrixx->FindMax();
}

int Matrix::Diametr() const{
    return Matrixx->Diametr();
}

double Matrix::GetVal(size_t i, size_t j) const{
    return this->Matrixx->GetVal(i, j);
}

void Matrix::SetVal(size_t i, size_t j, double val){
    this->Matrixx->SetVal(i, j, val);
}

void Matrix::DenseToSparse(){
    IterableSquareMatrix *buf = new IterableSparseMatrix(GetSize());
    for(auto i = 0; i < (int)GetSize(); i++)
        for(auto j = 0; j < (int)GetSize(); j++)
            buf->SetVal(i, j, this->Matrixx->GetVal(i,j));
    delete (this->Matrixx);
    this->Matrixx = buf;
}

void Matrix::SparseToDense(){
    IterableSquareMatrix *buf = new IterableDenseMatrix(GetSize());
    for(auto i = 0; i < (int)GetSize(); i++)
        for(auto j = 0; j < (int)GetSize(); j++)
            buf->SetVal(i, j, this->Matrixx->GetVal(i,j));
    delete (this->Matrixx);
    this->Matrixx = buf;
}

void Matrix::AddEdge(size_t a1, size_t a2) {
    if((int)(this->Matrixx->GetVal(a1,a2))==0)
        fullness++;
    this->Matrixx->AddEdge(a1,a2);
    if ((2*fullness>this->Matrixx->GetSize()*this->Matrixx->GetSize()) && !type) {
        this->SparseToDense();
        type = true;
    }
}

void Matrix::RemoveEdge(size_t a1, size_t a2) {
    if((int)this->Matrixx->GetVal(a1,a2)==1)
        fullness--;
    this->Matrixx->RemoveEdge(a1,a2);
    if ((2*fullness<this->Matrixx->GetSize()*this->Matrixx->GetSize()) && type) {
        this->DenseToSparse();
        type = false;
    }
}

void Matrix::SetSize(size_t a) {
    this->Matrixx->SetSize(a);
}

IterableSquareMatrix::row_iterator Matrix::iterate_rows(size_t row) const {
    size_t column = -1;
    while (++column < GetSize() && !(int)GetVal(row, column));
    return row_iterator(row, column, *this);
}


IterableSquareMatrix::row_iterator Matrix::end_row(size_t row) const {
    return row_iterator(row, GetSize(), *this);
}


IterableSquareMatrix::column_iterator Matrix::iterate_columns(size_t column) const {
    size_t row = -1;
    while (++row < GetSize() && !(int)GetVal(row, column));
    return column_iterator(row, column, *this);
}


IterableSquareMatrix::column_iterator Matrix::end_column(size_t column) const {
    return column_iterator(GetSize(), column, *this);
}
