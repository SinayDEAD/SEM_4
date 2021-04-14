//
//  main.cpp
//
//  Created by MacBook on 27.03.2021.
//

#include "Matrix.hpp"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    Matrix a(4);
    a.SetVal(0, 0, 1);
    std::cout << a.GetVal(0, 0) << std::endl;
    a.DenseToSparse();
    std::cout << a.GetVal(0, 0) << std::endl;
    a.SparseToDense();
    std::cout << a.GetVal(0, 0) << std::endl;
    std::cout << a.GetVal(0, 1) << std::endl;
    Matrix b(4);
    b.AddEdge(2,1);
    for(auto i = 0; i<4;i++){
        for(auto j = 0; j<4;j++){
            cout << b.GetVal(i,j) <<' ';
        }
        cout << endl;
    }
    cout << b.GetSize() << endl;
    b.iterate_rows(3);
    cout << b.FindMax()<< endl;
    b.AddEdge(1,0);
    b.AddEdge(0,1);
    b.AddEdge(0,3);
    b.AddEdge(3,3);
    for(auto i = 0; i < 4;i++){
        for(auto j = 0; j < 4;j++){
            cout << b.GetVal(i,j) <<' ';
        }
        cout << endl;
    }
    cout << b.Diametr() << endl;
    b.iterate_rows(2);
    b.iterate_columns(2);
    b.DenseToSparse();
    cout << b.Diametr() << endl;
    b.iterate_rows(2);
    b.iterate_columns(2);
    return 0;
}
