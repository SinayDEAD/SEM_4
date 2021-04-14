#include "SparseMatrix.h"
#include <iostream>

int main() {
    SparseMatrix m1(2,3), m2(2,3), m3(3,2);
    m1.set(0,0, 1.02);
    m1.set(0,1, 1.02);
    m1.set(1,2, 1.02);
    cout << m1 << endl << endl;
    m2[0][0] = 0.02;
    m2[0][1] = 0.02;
    m2[1][0] = 0.02;
    m2[1][1] = 2.02;
    m2[1][2] = 2.02;
    cout << m2 << endl << endl;
    SparseMatrix m4 = m1 + m2;
    cout << m4 << endl << endl;
    *(*(m3 + 0)+ 0) = 1;
    *(*(m3 + 0)+ 1) = 1;
    *(*(m3 + 1)+ 0) = 1;
    *(*(m3 + 1)+ 1) = 1;
    *(*(m3 + 2)+ 1) = 1;
    *(*(m3 + 2)+ 0) = 1;
    cout << m3 << endl << endl;
    SparseMatrix m5 = m4 * m3;
    cout << m5 << endl;
    
    cout << m5.get(1,1) << endl;
    cout << m1.num_rows() << endl;
    cout << m1.num_columns() << endl;
    cout << (m1 == m2) << endl;
    cout << (m1 != m2) << endl;
    
    const SparseMatrix m6 = m5;
    cout << m6 << endl << endl;
    cout << (m5 == m6) << endl;
    cout << (m5 != m6) << endl;
    cout << m6.get(1,1) << endl;
    cout << m6.num_rows() << endl;
    cout << m6.num_columns() << endl;
    const SparseMatrix m7 = m6 + m6;
    cout << m7 << endl << endl;
    const SparseMatrix m8 = m7 * m6;
    cout << m8 << endl << endl;
    cout << *(*(m8 + 1)+ 1) << endl;
    cout << m8[0][0] << endl;
    return 0;
}
