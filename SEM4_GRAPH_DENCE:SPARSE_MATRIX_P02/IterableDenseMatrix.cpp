//
//  IterableDenseMatrix.cpp
//
//  Created by MacBook on 28.03.2021.
//

#include "IterableDenseMatrix.hpp"
#include <iostream>

int MIN (int a, int b)
{
    return (a>b ? b : a);
}


size_t IterableDenseMatrix::GetSize() const{
    return size;
}

double IterableDenseMatrix::FindMax() const{
    double mas[GetSize()];
    for(int i = 1; i < (int)GetSize(); i++){
        for(int j = 1; j < (int)GetSize(); j++){
            mas[i] += Link[i][j];
            mas[j] += Link[i][j];
        }
    }
    double max = 0;
    double maxNum = mas[0];
    for(int i = 1; i < (int)GetSize(); i++){
        if (maxNum <= mas[i]){
            maxNum = mas[i];
            max = i;
        }
    }
    return max;
}

int IterableDenseMatrix::Diametr() const{
    int **edge = new int *[GetSize()];
    for (int i = 0; i < (int)GetSize(); i++)
        edge[i] = new int [GetSize()];
    for (int i = 0; i < (int)GetSize(); i++)
    {
        for (int j = 0; j < (int)GetSize(); j++) {
            edge[i][j] = Link[i][j];
            if (!edge[i][j])
                edge[i][j] = 10000;
        }
    }
    for (int k = 0; k < (int)GetSize(); k++)
        for (int i = 0; i < (int)GetSize(); i++)
            for (int j = 0; j < (int)GetSize(); j++)
                if (i != j)
                    edge[i][j] = MIN(edge[i][j], edge[i][k]+edge[k][j]);
    for (int i = 0; i < (int)GetSize(); i++) {
        for (int j = 0; j < (int)GetSize(); j++) {
            if (edge[i][j] == 10000)
                edge[i][j] = 0;
        }
    }
    int max = edge[0][1];
    for(int i = 0; i < (int)GetSize(); i++)
    {
        for (int j = i+1; j < (int)GetSize(); j++) {
            if(edge[i][j] > max)
                max = edge[i][j];
        }
    }
    for(auto i = 0; i < (int)GetSize() ; i++)
        delete[] edge[i];
    delete[] edge;
    return max;
}


IterableDenseMatrix::IterableDenseMatrix(size_t i){
    Link = new double *[i];
    for(auto count = 0; count < (int)i; count++)
        Link[count] = new double [i];
    size = i;
}

IterableDenseMatrix::~IterableDenseMatrix(){
    for(auto i = 0; i < (int)size ; i++)
        delete[] Link[i];
    delete[] Link;
}

double IterableDenseMatrix::GetVal(size_t i, size_t j) const{
    return Link[i][j];
}

void IterableDenseMatrix::SetVal(size_t i, size_t j, double val){
    Link[i][j] = val;
}
void IterableDenseMatrix::AddEdge(size_t a1, size_t a2) {
    Link[a1][a2]++;
}

void IterableDenseMatrix::RemoveEdge(size_t a1, size_t a2) {
    if (Link[a1][a2]>0)
        Link[a1][a2]--;
}

void IterableDenseMatrix::SetSize(size_t a) {
    this->size = a;
}




IterableSquareMatrix::row_iterator IterableDenseMatrix::iterate_rows(size_t row) const {
    size_t column = -1;
    while ((++column < size) && (!(int)GetVal(row, column)));
    return row_iterator(row, column, *this);
}


IterableSquareMatrix::row_iterator IterableDenseMatrix::end_row(size_t row) const {
    return row_iterator(row, size, *this);
}


IterableSquareMatrix::column_iterator IterableDenseMatrix::iterate_columns(size_t column) const {
    size_t row = -1;
    while (++row < size && (!((int)GetVal(row, column))));
    return column_iterator(row, column, *this);
}


IterableSquareMatrix::column_iterator IterableDenseMatrix::end_column(size_t column) const {
    return column_iterator(size, column, *this);
}
