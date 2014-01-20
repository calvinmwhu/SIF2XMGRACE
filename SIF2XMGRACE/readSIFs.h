#ifndef READSIFS_H
#define READSIFS_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <algorithm>
#include <sstream>

#include "curve.h"

using namespace std;

class ReadSIFs
{
private:
  vector <string> lines;  //lines of file
  vector <Curve> Propcurves;   //Propagation problem curves of SIFs 
  vector <Curve> GLcurves;   //raw Global problem curves of SIFs 
  vector <Curve> Lcurves;   //raw Local problem curves of SIFs 
  vector <Curve> GLmlsCurves;   //Global MLS curves of SIFs
  vector <Curve> LmlsCurves;   //Local MLS curves of SIFs
  int front; //stores what front we want to print;
  int numOfFronts;
  bool isPropFile;
  bool hasMLS;
  vector<int> vertices;  //number of vertices for each front (for files having MLS data)
  vector<int> stretches; //number of samples for each front (for files having MLS data)
  bool multiF;

  
   
public:
  
  ReadSIFs();
  ReadSIFs(const string&, int FRONT,bool multiFronts,  bool multiExists );
  //ReadSIFs(const string&);
  void set_isPropFile(bool isPropFile_in){
    isPropFile = isPropFile_in;
  }
  void storeLines(string);
  string getLine(int) const;
  void storeCurves();
  vector<Curve> getPropSIFs();
  vector<Curve> getGLSIFs();
  vector<Curve> getGLMlsSIFs();
  vector<Curve> getLSIFs();
  vector<Curve> getLMlsSIFs();
  
  int numberCurves(); //count how many curves are in the given file
  int getNumFronts();
  
  void setVertices();
  void setStret();
  bool checkMLS() const;

};
#endif
