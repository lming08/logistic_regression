#include <iostream>
#include <vector>
#include <cmath>
#include "logistic.h"
#include "matrix.h"

logistic::logistic(){}

logistic::logistic(matrix<double> ddata,
		   std::vector<double> iinit,double aalpha):
  data(ddata),init(iinit),alpha(aalpha),nrows(ddata.getRows()),ncols(ddata.getCols())
{
  if(init.size()!=(ncols-1)) std::cerr << "Error" << std::endl;
}


void logistic::fit(){

  std::vector<double> cur  = init;
  matrix<double> points(0,ncols-1);

  // initialise matrix
  points.add(cur);

  double tol = 1e-9;
  double val;
  double gradient[ncols-1];
  unsigned int t = 0;

  // compute gradients
  do
    {
      for (size_t k = 0; k < (ncols-1); k++) {
	for (size_t i = 0; i < nrows; i++) {
	  gradient[k] += (((1/(1+exp(-(cur[0]*data(i,1)+cur[1]*data(i,2))))) - data(i,0))*data(i,k+1));

	}

      }

      cur.clear();

      // compute new point and delete content of gradient
      for (size_t i = 0; i < (ncols-1); i++) {
	val = points(t,i) - (alpha * gradient[i]);
	cur.push_back(val);
	gradient[i] = 0.;
      }

      points.add(cur);
      t++;
      

    } while (std::abs(points(t,0)-points(t-1,0)) > tol);

  for (size_t i = 0; i < points.getRows(); i++) {
    for(size_t k = 0; k < points.getCols(); k++){
      std::cout << points(i,k) << "\n";
    }
  }
  
}






