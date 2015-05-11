#ifndef LOGISTIC_H
#define LOGISTIC_H

#include <vector>
#include "matrix.h"

class logistic {

 private:

  matrix<double> data;
  std::vector<double> init;
  double alpha;
  unsigned int nrows;
  unsigned int ncols;

  

 public:
  
  logistic();
  logistic(matrix<double> data ,std::vector<double> init ,double alpha);

  void fit();



};






#endif /* LOGISTIC_H */
