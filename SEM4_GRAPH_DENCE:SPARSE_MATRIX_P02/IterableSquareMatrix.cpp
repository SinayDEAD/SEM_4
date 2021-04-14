//
//  IterableSquareMatrix.cpp
//  Спасите_Наши_Души_Часть_2
//
//  Created by MacBook on 05.04.2021.
//

#include "IterableSquareMatrix.hpp"
IterableSquareMatrix::row_iterator & IterableSquareMatrix::row_iterator::operator++() {
    while (++(this->column) < matrix.GetSize() && !matrix.GetVal(this->row, this->column));
    return *this;
}


IterableSquareMatrix::row_iterator IterableSquareMatrix::row_iterator::operator++(int) {
    row_iterator itr = *this;
    while (++(this->column) < matrix.GetSize() && !matrix.GetVal(this->row, this->column));
    return itr;
}


bool IterableSquareMatrix::row_iterator::operator==(const row_iterator & it) const {
    return this->row == it.row && this->column == it.column && &(this->matrix) == &it.matrix;
}


bool IterableSquareMatrix::row_iterator::operator!=(const row_iterator & it) const {
    return !(*this == it);
}


int IterableSquareMatrix::row_iterator::operator*() const {
    return matrix.GetVal(this->row, this->column);
}


size_t IterableSquareMatrix::row_iterator::get_column() {
    return this->column;
}


IterableSquareMatrix::column_iterator & IterableSquareMatrix::column_iterator::operator++() {
    while (++(this->row) < matrix.GetSize() && !matrix.GetVal(this->row, this->column));
    return *this;
}


IterableSquareMatrix::column_iterator IterableSquareMatrix::column_iterator::operator++(int) {
    column_iterator itr = *this;
    while (++(this->row) < matrix.GetSize() && !matrix.GetVal(this->row, this->column));
    return itr;
}


bool IterableSquareMatrix::column_iterator::operator==(const column_iterator & it) const {
    return this->row == it.row && this->column == it.column && &(this->matrix) == &it.matrix;
}


bool IterableSquareMatrix::column_iterator::operator!=(const column_iterator & it) const {
    return !(*this == it);
}


int IterableSquareMatrix::column_iterator::operator*() const {
    return matrix.GetVal(this->row, this->column);
}


size_t IterableSquareMatrix::column_iterator::get_row() {
    return this->row;
}
