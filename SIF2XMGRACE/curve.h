#ifndef CURVE_H
#define CURVE_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Curve
{
 private:
  vector <double> id;
  vector <double> x;
  vector <double> y;
  vector <double> z;
  vector <double> KI;
  vector <double> KII;
  vector <double> KIII;
  vector <double> G;
  string method;
  double r1;
  double r2;
  double stepNum;

 public:
  Curve();
  void addPoint2Curve(string);
  void setMethod(string);
  void setR1(string);
  void setR2(string);
  void setStepNum(string);
 
  string getMethod(){
    return method;
  };
  double getR1(){
    return r1;
  };
  double getR2(){
    return r2;
  };
  double getStepNum(){
    return stepNum;
  };
  
  vector<vector<double> >getCurveInfo();
  
  void clear();
  void clearPoints();

};

#endif
