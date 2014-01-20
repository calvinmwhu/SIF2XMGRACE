#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <deque>
#include <iterator>
#include <algorithm>
#include <vector>
#include <math.h>
#include "curve.h"
using namespace std;
using std::cout;
typedef boost::tokenizer< boost::char_separator<char> > PhTokenizer;

Curve::Curve(){
}


void Curve::addPoint2Curve(string inputString){
  string itvalue;
  boost::char_separator<char> sepNod(", \t");
  PhTokenizer inputTokens(inputString, sepNod);
  PhTokenizer::iterator tok_iterz;
  inputTokens.assign(inputString);
  
  
  for(tok_iterz = inputTokens.begin();tok_iterz != inputTokens.end(); tok_iterz++){    
    itvalue = *tok_iterz;
    id.push_back(atof(itvalue.c_str() ));
    tok_iterz++;
    
    itvalue = *tok_iterz;
    x.push_back(atof(itvalue.c_str() ));
    tok_iterz++;
    
    itvalue = *tok_iterz;		
    y.push_back(atof(itvalue.c_str() ));
    tok_iterz++; 
         
    itvalue = *tok_iterz;
    z.push_back(atof(itvalue.c_str() ));
    tok_iterz++; 
    
     itvalue = *tok_iterz;
     KI.push_back(atof(itvalue.c_str() ));// /sqrt(3.1415926*1.8) );
     tok_iterz++;
     
     itvalue = *tok_iterz;
     KII.push_back(atof(itvalue.c_str() ));// /(-sqrt(3.1415926*1.8)));
     tok_iterz++;
            
     itvalue = *tok_iterz;
     KIII.push_back(atof(itvalue.c_str() ));// /(sqrt(3.1415926*1.8)));
     tok_iterz++;
     
     itvalue = *tok_iterz;
     G.push_back(atof(itvalue.c_str() ));
     tok_iterz++;
     
      if (tok_iterz != inputTokens.end()){
	//cout<<"No es el final todavia: "<<endl;
	break;
	//TBD for crp delta ....
      }else{
	//cout<<"Si es el final : "<<endl;
	break;
      }   
    }
    
}
//************************************************************
//************************************************************
void Curve::setMethod(string inputString){
 
    boost::char_separator<char> sepNod(":");
    PhTokenizer inputTokens(inputString, sepNod);
    PhTokenizer::iterator tok_iterz;
    inputTokens.assign(inputString);

   
    for(tok_iterz = inputTokens.begin();tok_iterz != inputTokens.end(); tok_iterz++){    
     
      tok_iterz++;
      method = *tok_iterz;
    }
    
}
//************************************************************
//************************************************************
void Curve::setR1(string inputString){
  string str_r1;
  boost::char_separator<char> sepNod(":");
  PhTokenizer inputTokens(inputString, sepNod);
  PhTokenizer::iterator tok_iterz;
  inputTokens.assign(inputString);
  
   
  for(tok_iterz = inputTokens.begin();tok_iterz != inputTokens.end(); tok_iterz++){    
    
    tok_iterz++;
    str_r1 = *tok_iterz;
    }
  r1=atof(str_r1.c_str());
  
}
//************************************************************
//************************************************************
void Curve::setR2(string inputString){
  string str_r2; 
  boost::char_separator<char> sepNod(":");
  PhTokenizer inputTokens(inputString, sepNod);
  PhTokenizer::iterator tok_iterz;
  inputTokens.assign(inputString);

   
  for(tok_iterz = inputTokens.begin();tok_iterz != inputTokens.end(); tok_iterz++){    
    
    tok_iterz++;
    str_r2 = *tok_iterz;
    }
  r2=atof(str_r2.c_str());

}
//************************************************************
//************************************************************
void Curve::setStepNum(string inputString){
  string str_step; 
  boost::char_separator<char> sepNod(":");
  PhTokenizer inputTokens(inputString, sepNod);
  PhTokenizer::iterator tok_iterz;
  inputTokens.assign(inputString);

   
  for(tok_iterz = inputTokens.begin();tok_iterz != inputTokens.end(); tok_iterz++){    
    
    tok_iterz++;
    str_step = *tok_iterz;
    }
  stepNum=atof(str_step.c_str());

}
//**************************************************************
//**************************************************************
 
vector<vector<double> > Curve::getCurveInfo(){
  vector<vector<double> > p;
  p.push_back(id);
  p.push_back(x);
  p.push_back(y);
  p.push_back(z);
  p.push_back(KI);
  p.push_back(KII);
  p.push_back(KIII);
  p.push_back(G);  //need to add G column here!
  return p;

}
//**************************************************************
//**************************************************************
 void Curve::clear(){
    id.clear();
    x.clear();
    y.clear();
    z.clear();
    KI.clear();
    KII.clear();
    KIII.clear();
    G.clear();
    method="";
    r1=0;
    r2=0;
    stepNum=-1;
 }
//**************************************************************
//**************************************************************
 void Curve::clearPoints(){
    id.clear();
    x.clear();
    y.clear();
    z.clear();
    KI.clear();
    KII.clear();
    KIII.clear();
    G.clear();
 }
