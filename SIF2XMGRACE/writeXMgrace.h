#ifndef WRITEXMGRACE_H
#define WRITEXMGRACE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <set>
#include <algorithm>
#include <map>
#include <sstream>
#include "curve.h"

#include <fstream>
#include <algorithm>
#include <sstream>

#include <cmath>
#include <time.h>
#include <unistd.h>
#define PI 3.14159265

using namespace std;
using std::cout;
using std::endl;

class WriteXMgrace
{
 private:
 
  // write a file that has characteristics for the SIFs
  // plot.
  ofstream batchfile;
  
 public:
  
  WriteXMgrace();

  WriteXMgrace(const string& file2, 
	       vector<Curve> Propcurves, 
	       vector<Curve> GLcurves, 
	       vector<Curve> GLmlscurves, 
	       vector<Curve> Lcurves, 
	       vector<Curve> Lmlscurves, string PCols, int opt,
	       bool PROP, bool PGL, bool PGLMLS, bool PL, bool PLMLS, 
	       /*vector<int> planeV, vector<double> Center,*/
	       double X_ini, double X_end, vector <int> Pindex,
           bool deleteFiles, bool isPropFile);
  
  void writeBatch(Curve Acurve, int opt, 
		  bool isPropFile, int & icurve);
 
  
 
};
 #endif
