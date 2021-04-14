#include <iostream>
using namespace std;
struct Element {
    size_t col;
    double value;
    Element *next;
    Element(size_t c = -1, double v = 0.0, Element *nxt = nullptr);
    void operator = (double v);
    Element& operator *();
    const Element& operator *() const;
    friend ostream &operator << (ostream &out, Element e);
};

class ElementList{
public:
    ElementList(const size_t max = 0);
    ElementList(const ElementList &rhs);
    ~ElementList();
    
    void put(size_t);
    double getIth(size_t);
    
    ElementList operator = (const ElementList &rhs);
    
    double operator[] (size_t col) const;
    double & operator[] (size_t col);
    const Element& operator + (size_t col)const;
    Element& operator + (size_t col);
    
    ElementList& operator *();
    const ElementList& operator *() const;
    
    friend ostream & operator << (ostream &out, ElementList list);
private:
    Element *list;
    size_t maxCols;
    void deleteList(Element *head);
};

class SparseMatrix {
public:
    SparseMatrix(size_t n = 0, size_t m = 0);
    SparseMatrix(const SparseMatrix &rhs);
    ~SparseMatrix();
    
    size_t num_columns() const;
    size_t num_rows() const;
    
    double get(size_t i, size_t j)const;
    void set(size_t i, size_t j , double a);
    
    SparseMatrix operator = (const SparseMatrix &rhs);
    SparseMatrix operator + (const SparseMatrix &rhs) const;
    SparseMatrix operator * (const SparseMatrix &rhs) const;
    friend bool operator == (const SparseMatrix& mtrx1, const SparseMatrix& mtrx2);
    friend bool operator!=(const SparseMatrix& mtrx1, const SparseMatrix& mtrx2);
    const ElementList operator [] (size_t row ) const;
    ElementList & operator [] (size_t row);
    const ElementList & operator + (size_t x) const;
    ElementList & operator + (size_t x);
    
    friend ostream &operator << (ostream &out, SparseMatrix matrix);
private:
    size_t numRows;
    size_t numCols;
    ElementList *rows;
};
