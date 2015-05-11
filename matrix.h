#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template <typename T>
class matrix{


  private:
  unsigned int nrows;
  unsigned int ncols;
  std::vector<std::vector<T>> mat;
  
public:

  matrix();
  matrix(unsigned int _nrows, unsigned int _ncols);

  unsigned int getCols() const;
  unsigned int getRows() const;

  void add(const std::vector<T>& vec);

  T& operator()(const unsigned& _nrow, const unsigned& _ncol);

  unsigned int Size();

  std::vector<T> last();

};

#include "matrix.cpp"

#endif /* MATRIX_H */
