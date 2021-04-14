#include "SparseMatrix.h"
double epsilon = 0.000001; // значение для корректного сравнения
Element::Element(size_t c, double v, Element *nxt){
        col = c;
        value = v;
        next = nxt;
}
void Element::operator = (double v){
    value = v;
}
Element& Element::operator *(){
    return *this;
}
const Element& Element::operator *() const{
    return *this;
}
ostream &operator << (ostream &out, Element e){
    out << e.value;
    return out;
}
//_____________________________________________________________________________
ElementList::ElementList(const size_t max){
        maxCols = max;
        list = nullptr;
}
ElementList::ElementList(const ElementList &rhs){
    maxCols = rhs.maxCols;
    list = rhs.list;
    if(list != nullptr){
        list = new Element(rhs.list->col, rhs.list->value, rhs.list->next);
        Element *leftPtr = list;
        Element *rightPtr = rhs.list;
        while(rightPtr->next != nullptr){
            Element *elementToCopy = rightPtr->next;
            leftPtr->next = new Element(elementToCopy->col, elementToCopy->value, elementToCopy->next);
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
    }
}
ElementList::~ElementList(){
    deleteList(list);
}
void ElementList::put(size_t max){
    list = nullptr;
    maxCols = max;
}
double ElementList::getIth(size_t i){
    Element *ptr = list;
    for(size_t j = 0; j < maxCols && ptr != nullptr; ++j){
        if(ptr->col == i)
            return ptr->value;
        ptr = ptr->next;
    }
    return 0;
}
ElementList ElementList::operator = (const ElementList &rhs){
    maxCols = rhs.maxCols;
    if(list != nullptr)
        deleteList(list);
    if(rhs.list != nullptr){
        list = new Element(rhs.list->col, rhs.list->value, rhs.list->next);
        Element *leftPtr = list;
        Element *rightPtr = rhs.list;
        while(rightPtr->next != nullptr){
            Element *elementToCopy = rightPtr->next;
            leftPtr->next = new Element(elementToCopy->col, elementToCopy->value, elementToCopy->next);
            leftPtr = leftPtr->next;
            rightPtr = rightPtr->next;
        }
    }
    return *this;
}
double ElementList::operator[] (size_t col) const {
    Element * ptr = list;
    while (ptr != nullptr && ptr->col < col)
        ptr = ptr->next;
    if (ptr == nullptr || ptr->col  > col)
        return 0;
    else
        return ptr->value;
}
double & ElementList::operator[] (size_t col){
    Element * ptr = list;
    Element * newNode;
    Element * trailer = list;
    if (list == nullptr || col < list->col){
        newNode = new Element(col,0, list);
        list = newNode;
        return newNode->value;
    }
    while (ptr != nullptr && ptr->col  < col){
        trailer = ptr;
        ptr = ptr->next;
    }
    if (ptr != nullptr && ptr->col == col)
        return ptr->value;
    else{
        newNode = new Element(col, 0, ptr);
        trailer->next = newNode;
        return newNode->value;
    }
}
const Element & ElementList::operator + (size_t col) const{
    Element * ptr = list;
    while (ptr != nullptr && ptr->col < col)
        ptr = ptr->next;
    return *ptr;
}
Element & ElementList::operator + (size_t col){
    Element * ptr = list;
    Element * newNode;
    Element * trailer = list;
    if (list == nullptr || col < list->col){
        newNode = new Element(col,0, list);
        list = newNode;
        return *newNode;
    }
    while (ptr != nullptr && ptr->col  < col){
        trailer = ptr;
        ptr = ptr->next;
    }
    if (ptr != nullptr && ptr->col == col)
        return *ptr;
    else{
        newNode = new Element(col, 0, ptr);
        trailer->next = newNode;
        return *newNode;
    }
}
ElementList& ElementList::operator *(){
    return *this;
}
const ElementList& ElementList::operator *() const{
    return *this;
}
ostream & operator << (ostream &out, ElementList list){
    Element *ptr = list.list;
    out << "[ ";
    for(size_t i = 0; i < list.maxCols; ++i){
        if(ptr != nullptr && ptr->col == i){
            out << ptr->value << " ";
            ptr = ptr->next;
        }
        else
            out << 0 << " ";
    }
    out << "]";
    return out;
}
void ElementList::deleteList(Element *head){
    Element *current = head;
    Element *next = NULL;
    while (current != nullptr && current->next != nullptr){
        next = current->next;
        delete current;
        current = next;
    }
    if(current != nullptr)
        delete current;
    list = nullptr;
}
//_____________________________________________________________________________
SparseMatrix::SparseMatrix(size_t n, size_t m){
    numRows = n;
    numCols = m;
    rows = new ElementList[n];
    for(size_t i = 0; i < n; ++i)
        rows[i].put(m);
}
SparseMatrix::SparseMatrix(const SparseMatrix &rhs){
    numRows = rhs.numRows;
    numCols = rhs.numCols;
    rows = new ElementList[rhs.numRows];
    for(size_t i = 0; i < rhs.numRows; ++i)
        rows[i] = rhs.rows[i];
}
SparseMatrix::~SparseMatrix(){
    delete [] rows;
}
size_t SparseMatrix::num_columns() const{
    return numCols;
}
size_t SparseMatrix::num_rows() const{
    return numRows;
}
double SparseMatrix::get(size_t i, size_t j) const{
    return rows[i][j];
}
void SparseMatrix::set(size_t i, size_t j , double a){
    rows[i][j] = a;
}
bool operator != (const SparseMatrix& mtrx1, const SparseMatrix& mtrx2){
    if (mtrx1.numCols == mtrx2.numCols && mtrx1.numRows == mtrx2.numRows){
        for (size_t i = 0; i < mtrx1.numCols; ++i){
            for (size_t j = 0; j < mtrx1.numRows; ++j){
                if (abs(mtrx1[j][i] - mtrx2[j][i]) >= epsilon){
                    return true;
                }
            }
        }
        return false;
    }
    return true;
}
bool operator == (const SparseMatrix& mtrx1, const SparseMatrix& mtrx2){
    if (mtrx1.numCols == mtrx2.numCols && mtrx1.numRows == mtrx2.numRows){
        for (size_t i = 0; i < mtrx1.numCols; ++i){
            for (size_t j = 0; j < mtrx1.numRows; ++j){
                if (abs(mtrx1[j][i] - mtrx2[j][i]) >= epsilon){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
SparseMatrix SparseMatrix::operator = (const SparseMatrix &rhs){
    numRows = rhs.numRows;
    numCols = rhs.numCols;
    delete [] rows;
    rows = new ElementList[rhs.numRows];
    for(size_t i = 0; i < rhs.numRows; ++i)
       rows[i] = rhs.rows[i];
    return *this;
}
SparseMatrix SparseMatrix::operator + (const SparseMatrix &rhs) const{
    SparseMatrix newMatrix(numRows, numCols);
    for (size_t i = 0; i < numRows; ++i){
        for (size_t j = 0; j < numCols; ++j) {
            double toAdd = rows[i].getIth(j) + rhs.rows[i].getIth(j);
            newMatrix.rows[i][j] = toAdd;
        }
    }
    return newMatrix;
}
SparseMatrix SparseMatrix::operator * (const SparseMatrix &rhs) const{
    SparseMatrix newMatrix(numRows, rhs.numCols);
    size_t m = numCols;
    for(size_t row = 0; row < newMatrix.numRows; ++row){
        for(size_t col = 0; col < newMatrix.numCols; ++col){
            double val = 0;
            for(size_t counter = 0; counter < m; ++counter){
                double lhsVal = rows[row].getIth(counter);
                double rhsVal = rhs.rows[counter].getIth(col);
                val += (lhsVal * rhsVal);
            }
            if(val > epsilon)
                newMatrix.rows[row][col] = val;
        }
    }
    return newMatrix;
}
const ElementList SparseMatrix::operator [] (size_t row ) const{
    return rows[row];
}
ElementList & SparseMatrix::operator [] (size_t row){
    return rows[row];
}
const ElementList & SparseMatrix::operator + (size_t x) const{
    return rows[x];
}
ElementList & SparseMatrix::operator + (size_t x){
    return rows[x];
}
ostream &operator << (ostream &out, SparseMatrix matrix){
    for(size_t i = 0; i < matrix.numRows; ++i){
        out << matrix[i];
        if(i+1 < matrix.numRows)
            out << endl;
    }
    return out;
}


