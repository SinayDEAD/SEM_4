//
//  IterableSquareMatrix.hpp
//  Спасите_Наши_Души_Часть_2
//
//  Created by MacBook on 05.04.2021.
//

#ifndef IterableSquareMatrix_hpp
#define IterableSquareMatrix_hpp

#include <stdio.h>
#include <cstdio>

class IterableSquareMatrix {
public:
    virtual size_t GetSize() const = 0;
    virtual double FindMax() const = 0;
    virtual int Diametr() const = 0;
    virtual double GetVal(size_t, size_t) const = 0;
    virtual void SetVal(size_t, size_t, double) = 0;
    virtual ~IterableSquareMatrix(){} //без идей что тут надо
    virtual void AddEdge(size_t,size_t) = 0;
    virtual void RemoveEdge(size_t,size_t) = 0;
    virtual void SetSize(size_t) = 0;
    
    class row_iterator {
        size_t row;
        size_t column;
        const IterableSquareMatrix & matrix;
    public:
        row_iterator(size_t r, size_t c, const IterableSquareMatrix & m) : row(r), column(c), matrix(m) {};
        row_iterator & operator++();
        row_iterator operator++(int);
        bool operator==(const row_iterator &) const;
        bool operator!=(const row_iterator &) const;
        int operator*() const;
        size_t get_column();
    };

    class column_iterator {
        size_t row;
        size_t column;
        const IterableSquareMatrix & matrix;
    public:
        column_iterator(size_t r, size_t c, const IterableSquareMatrix & m) : row(r), column(c), matrix(m) {};
        column_iterator & operator++();
        column_iterator operator++(int);
        bool operator==(const column_iterator &) const;
        bool operator!=(const column_iterator &) const;
        int operator*() const;
        size_t get_row();
    };
    
    
public:
    virtual row_iterator iterate_rows(size_t) const = 0;
    virtual row_iterator end_row(size_t) const = 0;
    virtual column_iterator iterate_columns(size_t) const = 0;
    virtual column_iterator end_column(size_t) const = 0;
    
};
#endif /* IterableSquareMatrix_hpp */
