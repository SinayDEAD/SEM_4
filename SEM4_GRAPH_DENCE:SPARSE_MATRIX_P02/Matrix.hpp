//
//  Matrix.hpp
//
//  Created by MacBook on 28.03.2021.
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include <stdio.h>
#include "IterableSquareMatrix.hpp"
class Matrix: public IterableSquareMatrix {
public:
    Matrix(size_t);
    size_t GetSize() const override;
    double FindMax() const override;
    int Diametr() const override;
    double GetVal(size_t, size_t) const override;
    void SetVal(size_t, size_t, double) override;
    virtual ~Matrix() override;
    void DenseToSparse();
    void SparseToDense();
    void AddEdge(size_t,size_t) override;
    void RemoveEdge(size_t,size_t) override;
    void SetSize(size_t) override;
    
    row_iterator iterate_rows(size_t) const override;
    row_iterator end_row(size_t) const override;
    column_iterator iterate_columns(size_t) const override;
    column_iterator end_column(size_t) const override;
private:
    IterableSquareMatrix *Matrixx;
    bool type;
    size_t fullness;

};

#endif /* Matrix_hpp */
