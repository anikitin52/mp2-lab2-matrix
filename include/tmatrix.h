// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Никитин А. А.
// 3823Б1ФИ2
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:

  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero");
    if (sz > MAX_VECTOR_SIZE) {
        throw "Error!";
    }
    pMem = new T[sz]();
  }

  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }

  TDynamicVector(const TDynamicVector& v) {
      this->sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }

  TDynamicVector(TDynamicVector&& v) noexcept
  {
      this->pMem = v.pMem;
      v.pMem = nullptr;
      this->sz = v.sz;
      v.sz = 0;
  }

  ~TDynamicVector()
  {
      delete[] pMem;
  }

  T* getMem() {
      return pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v)
          return *this;
      if (sz != v.sz) {
          T* p = new T[v.sz];
          delete[] pMem;
          sz = v.sz;
          pMem = p;
      }
      std::copy(v.pMem, v.pMem + sz, pMem);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind < 0 || ind >= sz) {
          throw "Error! Invalid index!";
      }
      else {
          return pMem[ind];
      }
 
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind >= sz) {
          throw "Error! Invalid index!";
      }
      else {
          return pMem[ind];
      }
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (this->sz != v.sz) {
          return false;
      }
      for (int i = 0; i < this->sz; i++) {
          if (pMem[i] != v.pMem[i]) {
              return false;
          }
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (this->sz != v.sz) {
          return true;
      }
      for (int i = 0; i < this->sz; i++) {
          if (pMem[i] != v.pMem[i]) {
              return true;
          }
      }
      return false;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + val;
      }
      return res;
  }
  TDynamicVector operator-(double val)
  {
      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          pMem[i] -= val;
      }
      return res;
  }
  TDynamicVector operator*(double val)
  {

      TDynamicVector res(sz);
      for (int i = 0; i < sz; i++) {
          pMem[i] *= val;
      }
      return res;
  }
  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (this->size() != v.size()) {
          throw "Error! The lengths of the vectors are not equal";
      }
      TDynamicVector res(sz);
      for (int i = 0; i < res.sz; i++) {
          res.pMem[i] = pMem[i] + v.pMem[i];
      }
      return res;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (this->size() != v.size()) {
          throw "Error! The lengths of the vectors are not equal";
      }
      TDynamicVector<T> res(*this);
      for (int i = 0; i < sz; i++) {
          res.pMem[i] = this->pMem[i] - v.pMem[i];
      }
      return res;
  }
  T operator*(const TDynamicVector& v) 
  {
      if (this->size() != v.size()) {
          throw "Error! The lengths of the vectors are not equal";
      }
      T res = 0;
      for (int i = 0; i < v.sz; i++) {
          res += pMem[i] * v.pMem[i];
      }
      return res;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
  
public:

    using TDynamicVector<TDynamicVector<T>>::size;
    using TDynamicVector<TDynamicVector<T>>::at;
    using TDynamicVector<TDynamicVector<T>>::operator*;
    using TDynamicVector<TDynamicVector<T>>::operator[];
    using TDynamicVector<TDynamicVector<T>>::getMem;


  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if (sz > MAX_MATRIX_SIZE) {
          throw "ERROR! The maximum size of the matrix has been exceeded";
      }
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  // сравнение
  bool operator==(const TDynamicMatrix& m) const 
  {
      if (this->sz != m.sz)
          return false;
      for (int i = 0; i < sz; i++) {
          if (this->pMem[i] != m.pMem[i]) {
              return false;
          }
      }
      return true;
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] * val;
      }
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++) {
          res[i] = pMem[i] * v;
      }
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] + m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++) {
          res.pMem[i] = pMem[i] - m.pMem[i];
      }
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix res(sz);
      for (size_t i = 0; i < sz; i++) {
          for (size_t j = 0; i < sz; j++) {
              for (size_t k = 0; k < sz; k++) {
                  res.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
              }
          }
      }
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++)
          for (int i = 0; i < pMem[i].sz; i++)
              istr >> v.pMem[i].pMem[i];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (int i = 0; i < v.sz; i++) {
          for (int j = 0; j < v.sz; j++)
              ostr << v.pMem[i][j] << " ";
      }

      return ostr;
  }
};

#endif
