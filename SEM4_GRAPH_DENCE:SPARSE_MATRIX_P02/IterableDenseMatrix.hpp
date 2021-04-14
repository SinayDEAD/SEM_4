//
//  IterableDenseMatrix.hpp
//
//  Created by MacBook on 28.03.2021.
//

#ifndef IterableDenseMatrix_hpp
#define IterableDenseMatrix_hpp

#include "IterableSquareMatrix.hpp"

class IterableDenseMatrix: public IterableSquareMatrix {
public:
    double **Link;
    IterableDenseMatrix(size_t);
    size_t GetSize() const override;
    double FindMax() const override;
    int Diametr() const override;
    double GetVal(size_t, size_t) const override;
    void SetVal(size_t, size_t, double) override;
    virtual ~IterableDenseMatrix();
    void SetSize(size_t) override;
    void AddEdge(size_t,size_t) override;
    void RemoveEdge(size_t,size_t) override;
    row_iterator iterate_rows(size_t) const override;
    row_iterator end_row(size_t) const override;
    column_iterator iterate_columns(size_t) const override;
    column_iterator end_column(size_t) const override;
private:
    size_t size;
};
int MIN (int a, int b);
#endif /* IterableDenseMatrix_hpp */
