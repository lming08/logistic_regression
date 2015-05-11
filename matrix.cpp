#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <vector>
#include "matrix.h"

template <typename T>
matrix<T>::matrix(){
  mat.resize(1);
  mat[0].resize(1);
}

template <typename T>
matrix<T>::matrix(unsigned int _nrows, unsigned int _ncols){
  mat.resize(_nrows);
  for (size_t i=0; i<mat.size(); i++) {
    mat[i].resize(_ncols);
  }
  nrows = _nrows;
  ncols = _ncols;
}

template <typename T>
unsigned int matrix<T>::getCols() const{
  return ncols;
}

template <typename T>
unsigned int matrix<T>::getRows() const{
  return nrows;
}

template <typename T>
void matrix<T>::add(const std::vector<T>& vec){
  mat.push_back(vec);
  nrows++;

}

template <typename T>
T& matrix<T>::operator()(const unsigned& _nrows, const unsigned& _ncols){
  return mat[_nrows][_ncols];
}

template <typename T>
unsigned int matrix<T>::Size(){
  return mat.size();
}

#endif /* MATRIX_CPP */
