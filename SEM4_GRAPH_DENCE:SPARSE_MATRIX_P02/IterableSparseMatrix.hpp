//
//  IterableSparseMatrix.hpp
//
//  Created by MacBook on 28.03.2021.
//

#ifndef IterableSparseMatrix_hpp
#define IterableSparseMatrix_hpp

#include "SparseMatrix.hpp"
#include "IterableSquareMatrix.hpp"
#include "Matrix.hpp"

class IterableSparseMatrix: public IterableSquareMatrix {
public:
    SparseMatrix *Link;
    explicit IterableSparseMatrix(size_t);
    size_t GetSize() const override;
    double FindMax() const override;
    int Diametr() const override;
    double GetVal(size_t, size_t) const override;
    void SetVal(size_t, size_t, double) override;
    virtual ~IterableSparseMatrix();
    void SetSize(size_t) override;
    void AddEdge(size_t, size_t) override;
    void RemoveEdge(size_t, size_t) override;
    row_iterator iterate_rows(size_t) const override;
    row_iterator end_row(size_t) const override;
    column_iterator iterate_columns(size_t) const override;
    column_iterator end_column(size_t) const override;
private:
    size_t size;
};
int MIN2 (int a, int b);
#endif /* IterableSparseMatrix_hpp */
