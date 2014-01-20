#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <deque>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "readSIFs.h"
#include "curve.h"

using namespace std;
using namespace boost;
using std::cout;
using std::endl;
typedef boost::tokenizer< boost::char_separator<char> > PhTokenizer;



//********************************************************************
//*******************************************************************
ReadSIFs::ReadSIFs(const string& file1,int FRONT,bool multiFronts,  bool multiExists) {
 	front=FRONT;
 	multiF=multiFronts;
   // test that input file opens properly
    ifstream infile(file1.c_str());
    if (! infile){
	cerr << "can't open input file\"" << file1 << "\""
	     << endl;
	exit(EXIT_FAILURE);
    }

    int length;
    
    infile.seekg(0,ios::end);
    length=infile.tellg();
    infile.seekg(0,ios::beg);
    
    cout<<"The length of the file is: "<<length<<"  Chars"<<endl;
    string temp;
    int i=0;
    while(!infile.eof()){   //while there are still lines left to read  
	getline(infile, temp);
	storeLines(temp);
	i++;
    }
    
    /*
    int pos=0;
    while(pos<lines.size()){
    	if(lines[pos]=="# GLOBAL PROBLEM")
    		cout<<"another one!!"<<endl;
    	pos++;
    }  
    */
    hasMLS=checkMLS();
    if(multiExists)
            numOfFronts=getNumFronts();
    else numOfFronts=1;
    cout<<"Number of Lines:  "<<i<<endl;
    cout<<"Number of Curves:  "<<numberCurves()<<endl;
    cout<<"Number of Fronts: "<<numOfFronts<<endl;
    
    if(hasMLS){ 
    	setStret();
    	setVertices();
    	//cout<<vertices.size()<<endl;
    	for(int i=0;i<(int)vertices.size();i++){
 	
 		cout<<"we have "<<vertices[i]<<" vertices in front#"<<i+1<<endl;
 
 	}
   	 for(int i=0;i<(int)stretches.size();i++){
 	
 		cout<<"we have "<<stretches[i]<<" vertices in stretch#"<<i+1<<endl;
 
 	}
    }
    
    isPropFile = false;
      
}
//********************************************************************
//*******************************************************************
void ReadSIFs::storeLines(string inputString){
   lines.push_back(inputString);
}



//********************************************************************
//*******************************************************************
int ReadSIFs::numberCurves(){
    string temp2;
    int n=0;
    int cuenta=0;
    while( n<(int)lines.size() ){
      if(/*temp2=="# Propagation Law: Paris' Law" ||*/ 
	 temp2=="# MLS approximation: " || temp2=="# LOCAL PROBLEM" ||
	 temp2=="# GLOBAL PROBLEM" ){
	cuenta++;
      }
      temp2=getLine(n);
      n++;
    }
    
    return cuenta;
}   // it added ; ?

bool ReadSIFs::checkMLS() const{
  	int n=0;
  	string curr;
  	while(n<(int)lines.size()){
 		curr=getLine(n);
 		if(curr=="# MLS approximation: "){
 			return true;
 		}
 		n++;
 	}
 	return false;
  }
  
  
 int ReadSIFs::getNumFronts(){
    if(!hasMLS) return 1;
    int n=0;
    int numFronts=0;
    string curr;
    while(n<(int)lines.size()){
 		curr=getLine(n);
 		if(curr=="# MLS approximation: "){
 			n=n+2;
 			break;
 		}
 		n++;
 	}
 	while(curr!="#"){
 		curr=getLine(n);
 		
 		if(curr.compare(0,22,"# Crack front stretch:")==0) numFronts++;
 		n++;
 	}
 
 	return numFronts;
 }

  void ReadSIFs::setStret(){
  	int n=0;
 	string curr;
    if(!hasMLS) {stretches.push_back(0);return;}
    while(n<(int)lines.size()){
 		curr=getLine(n);
 		if(curr=="# MLS approximation: "){
 			n=n+3;
 			break;
 		}
 		n++;
 	}
 	curr=getLine(n);
 	//cout<<curr<<endl;
 	for(int i=0; i<numOfFronts;i++){
  		int num=0;
  		while(curr!="" && curr!="#") {
  			num++;
  			curr=getLine(++n);
  		}
  	stretches.push_back(num);
  	n=n+2;
  	 curr=getLine(n);
  	}
  
  
  
  }


  void ReadSIFs::setVertices(){
    if(hasMLS){
   	 for(int i=0;i<(int)stretches.size();i++){
  	    	vertices.push_back(stretches[i]/3+1);	
  	}
    }
    /*
    else {
    	int n=0;
    	int pos=0;
    	int num=0;
  	string curr;
  	while(n<(int)lines.size()){
 		curr=getLine(n);
 		if(curr=="# Vertex, X,              Y,              Z,              K_I,            K_II,           K_III,           J"){
 			break;
 		}
 		n++;
 	}
 	n++;

        while(true){
	    curr=getLine(n);
	    if(curr!="#") break;
	    num++;	    
        }
    	vertices.push_back(num);	 
      
    }
*/
  
 } 


//********************************************************************
//*******************************************************************

string ReadSIFs::getLine(int num) const{
    string temp;
    temp=lines[num];
    return temp;
}
//********************************************************************
//*******************************************************************

void ReadSIFs::storeCurves(){

    string temp2;
    string method, r1, r2, stepNum; //used to recognize each curve
    int n=0;
    int i2=0;
    int i3=0;
    int i4=0;
    int i5=0;
    int flg=0;
    Curve Acurve;
    bool isGlobal = false;
    bool isLocal = false;
    
    while( n<(int)lines.size() ){  //read each line
      temp2=getLine(n); //store each line into temp
      flg=0;
     // cout<<"Alerta 0:     "<<temp2<<endl;
      
//***************************************GLOBAL PROBLEM***********************************************************      
      if (temp2=="# GLOBAL PROBLEM") {
	isGlobal = true;
	//cout<<"does this work !!!!!!!!!?" <<endl;
	//get info to recognize curve
	method=getLine(n+2);  //used to tell what method it belongs to
	Acurve.setMethod(method); //pass this method to setMethod function to modify Acurve object
	//cout<<"method "<<method<<endl;

	if(Acurve.getMethod() == " CFM"){
	  r1=getLine(n+5);    //get radius#1
	  Acurve.setR1(r1);   //store the value of radius #1 in R1 variable in Acurve object of type curve
	  r2=getLine(n+6);    //get radius#2
	  Acurve.setR2(r2);   //store the value of radius #2 in R2 variable in Acurve object of type curve
	  // take the step number in case of propagation
	  // TBD:: need to check this case and get the right
	  // line number
	  if(isPropFile){
	    stepNum=getLine(n+14);
	    Acurve.setStepNum(stepNum);
	  }
	  
	}
	else{ //if the extraction method is not CFM
	  r1=getLine(n+4); //same thing here,get radius#1 for methods other than CFM
	  Acurve.setR1(r1); //and set method
	  //cout<<"r1 "<<r1<<endl;
	  // take the step number in case of propagation
	  if(isPropFile){
	  
	    	string temp_check=getLine(n+18);
	    	string temp_sifs=temp_check.substr (0,37);
	    
	    	if(temp_sifs=="# Raw SIFs at Crack Propagation Step:"){
	    		stepNum=getLine(n+18) ;  
	    	}

	    	else	
	    		stepNum=getLine(n+14) ;  
	    			    			    			   
	        Acurve.setStepNum(stepNum);
	    //cout<<"stepNum "<<stepNum<<endl;
	  }
	}
	
      }
 //*************************************************************************************************************************************//
 
 
 
//***********************************************LOCAL PROBLEM**********************************************************************//
      if (temp2=="# LOCAL PROBLEM") {
	// TBD: this needs to be checked!!!!
	isLocal = true;
	//get info to recognize curve
	method=getLine(n+2);
	Acurve.setMethod(method);
	
	if(Acurve.getMethod() == " CFM"){
	  r1=getLine(n+5);
	  Acurve.setR1(r1);
	  r2=getLine(n+6);
	  Acurve.setR2(r2);
	  // take the step number in case of propagation
	  // TBD:: need to check this case and get the right
	  // line number
	  if(isPropFile){
	    stepNum=getLine(n+14);
	    Acurve.setStepNum(stepNum);
	  }
	  
	}
	else{
	  r1=getLine(n+4);
	  Acurve.setR1(r1);
	  // take the step number in case of propagation
	  if(isPropFile){
	        if(hasMLS)
	    		stepNum=getLine(n+14);
	    	else
	    	        stepNum=getLine(n+18);

	    Acurve.setStepNum(stepNum);
	  }
	}
      }
 //***********************************************************************************************************************************//
 
 
 
 
      
//***************************This portions reads and saves RAW data...most important part!!!****************************************//
      
      
      string startLine;
      if(isPropFile)
      //startline is the line before reading data, for crp and sif files, startlines are different
	startLine = "# Vertex, X,              Y,              Z,              K_I,            K_II,           K_III,           J";
      else
	startLine = "# this value should be bounded as small as possible.";
      
      // For local problem
      if(isLocal && temp2==startLine){
               //  cout<<"the line is"<<getLine(n)<<endl;
	flg=1;
	n+=1;
	i4++;
	
	if(hasMLS){
		int startNew=n;
		int endNew=n+vertices[0];
	
		for(int i=0;i<front-1;i++){
			startNew=startNew+vertices[i];		
		}
		endNew=startNew+vertices[front-1];
	
		if(multiF){ temp2=getLine(startNew); n=startNew;}
	
		else temp2 = getLine(n);
	
		//this portion extracts all the raw SIFs Data
		do {
		  Acurve.addPoint2Curve(temp2);
		  n++;
		  temp2 = getLine(n);
		} while ((!multiF)? (temp2!="" && temp2!="#"):(n<endNew)  );
	
	}
	
	else {
		temp2=getLine(n);
		while(temp2!="#"){
			Acurve.addPoint2Curve(temp2);//add data to curve
			n++;
			temp2=getLine(n);
		}
	}
	
	Lcurves.push_back(Acurve);
	Acurve.clearPoints();
      }
      
      //for Global problem
      // saves extraction even in case of propagation
      if(isGlobal && temp2==startLine){

	flg=1;
	n+=1;
	i5++;
	
	if(hasMLS){
		int startNew=n;
		int endNew=n+vertices[0];
	    	   // cout<<"true"<<endl;
		for(int i=0;i<front-1;i++){
			startNew=startNew+vertices[i];		
		}
		endNew=startNew+vertices[front-1];
	 
		if(multiF){ temp2=getLine(startNew); n=startNew;}
		 
		else temp2 = getLine(n);
		//cout << "line " << __LINE__ << endl;

		do {
		  Acurve.addPoint2Curve(temp2);//add data to curve
		  n++;
	 	 temp2 = getLine(n);
		} while ((!multiF)? (temp2!="" && temp2!="#"):(n<endNew)  );	
	
		if(temp2!="") {
			//cout<<"true"<<endl;
			while(temp2!="" ){
				n++;
				//cout<<"n is "<<n<<endl;
				temp2=getLine(n);
			}
		}
		//cout << "line " << __LINE__ << endl;	
	}
	else {
		temp2=getLine(n);
		while(temp2!="#"){
			Acurve.addPoint2Curve(temp2);//add data to curve
			n++;
			temp2=getLine(n);
		}
	}
		
	GLcurves.push_back(Acurve);
	Acurve.clearPoints();
	
      }
      

      // This reads and saves the MLS extraction 
      // for both Local and global problems
      if (temp2=="# MLS approximation: "){
      //cout<<"n now is "<<n<<endl;
     // cout<<"the line is"<<getLine(n)<<endl;
	flg=1;
	n+=3;
	i3++;
	
	int startNew=n;
	int endNew=n+stretches[0];
	for(int i=0;i<front-1;i++){
		startNew=startNew+stretches[i]+2;		
	}
	endNew=startNew+stretches[front-1];
	
	//cout<<"startNew is "<<startNew<<endl;
	
		//  cout<<"endnew="<<endNew<<endl;
	if(multiF){ temp2=getLine(startNew); n=startNew;}

	else temp2 = getLine(n);
	
	do {
	  Acurve.addPoint2Curve(temp2);
	  n++;
	  temp2 = getLine(n);
	} while ((!multiF)? (temp2!="" && temp2!="#"):(n<endNew) );
	
	

    if(isPropFile){
            if(temp2!="#") {
               // cout<<"true"<<endl;
                while(temp2!="#" ){
                    n++;
                   // cout<<"n is "<<n<<endl;
                    temp2=getLine(n);
                }

            }
        }
        else {
            if(temp2!="") {
              //  cout<<"true"<<endl;
                while(temp2!="" ){
                    n++;
                   // cout<<"n is "<<n<<endl;
                    temp2=getLine(n);
                }

            }
        }

  
	if (isGlobal) {
	  GLmlsCurves.push_back(Acurve);
	  isGlobal = false;
	}
	else{
	  LmlsCurves.push_back(Acurve);
	  isLocal = false;
	}
	if(isPropFile)
	  Acurve.clearPoints();
	else
	  Acurve.clear();
      }
  
      // Only when propagating
      // it assumes it only propagates on global problem
      // this reads the values used in the extraction
      // used to compute the propagation. (sometimes MLS at crack vertices)
    //  if(temp2=="# CrackFrontPropagator::advanceCrFrontWithPhysics: SIFs, Propagation Directions ")
      		//cout<< "OK"<<endl;
      		
     /* stores sif data*/
     
     if(temp2=="# CrackFrontPropagator::advanceCrFrontWithPhysics: SIFs, Propagation Directions "){
     
     	string temp_paris=getLine(n+3);
	if(temp_paris=="# Propagation Law: Paris' Law"){
			n=n+3;
			int lineNumber=n;
			string temp3=getLine(lineNumber+11);
			if(temp3!="") n+=9;
			else n+=12;

			flg=1;
	
			i2++;
	
			int startNew=n;
			int endNew=n+vertices[0];
	   		   //  cout<<"true"<<endl;
			for(int i=0;i<front-1;i++){
			startNew=startNew+vertices[i];		
			}
			endNew=startNew+vertices[front-1];
	 
			if(multiF){ temp2=getLine(startNew); n=startNew;}
		 
			else temp2 = getLine(n);
	
	
			do {
	 	 		Acurve.addPoint2Curve(temp2);
	 			 n++;
	  			temp2 = getLine(n);
			} while ((!multiF)? (temp2!="" && temp2!="#"):(n<endNew)  );
	
			//(temp2!="" && temp2!="#");
	
	
			if(temp2!="") {
				//cout<<"t21212rue"<<endl;
				while(temp2!="" ){
					n++;
					//cout<<"n is "<<n<<endl;
					temp2=getLine(n);
				}
		
			}
				
			Propcurves.push_back(Acurve);
			isGlobal= false;
			Acurve.clear();
	}
	
	else{
		        n=n+2;
     			temp2=getLine(n);
     			while(temp2!=""){
     				Acurve.addPoint2Curve(temp2);
	 			n++;
	  			temp2 = getLine(n);
     			}
     			Propcurves.push_back(Acurve);
			isGlobal= false;
			Acurve.clear();
		
	
	}
     
     }
     
     
     
     
     
     
      		
  
    /*  		
      if(hasMLS){
     		 if (temp2=="# Propagation Law: Paris' Law"){

			int lineNumber=n;
			string temp3=getLine(lineNumber+11);
			if(temp3!="") n+=9;
			else n+=12;

			flg=1;
	
			i2++;
	
			int startNew=n;
			int endNew=n+vertices[0];
	   		   //  cout<<"true"<<endl;
			for(int i=0;i<front-1;i++){
			startNew=startNew+vertices[i];		
			}
			endNew=startNew+vertices[front-1];
	 
			if(multiF){ temp2=getLine(startNew); n=startNew;}
		 
			else temp2 = getLine(n);
	
	
			do {
	 	 		Acurve.addPoint2Curve(temp2);
	 			 n++;
	  			temp2 = getLine(n);
			} while ((!multiF)? (temp2!="" && temp2!="#"):(n<endNew)  );
	
			//(temp2!="" && temp2!="#");
	
	
			if(temp2!="") {
				//cout<<"t21212rue"<<endl;
				while(temp2!="" ){
					n++;
					//cout<<"n is "<<n<<endl;
					temp2=getLine(n);
				}
		
			}
				
			Propcurves.push_back(Acurve);
			isGlobal= false;
			Acurve.clear();
      		}
      
     }
     else{
     		if(temp2=="# CrackFrontPropagator::advanceCrFrontWithPhysics: SIFs, Propagation Directions "){
     			n=n+2;
     			temp2=getLine(n);
     			while(temp2!=""){
     				Acurve.addPoint2Curve(temp2);
	 			n++;
	  			temp2 = getLine(n);
     			}
     			Propcurves.push_back(Acurve);
			isGlobal= false;
			Acurve.clear();
     		}
     }
     
     
     */
      
      if(flg==0)n++; 
    }


    cout<<"Stored Curves (for propagation) =  "<<i2<<endl;
    cout<<"Stored GLobal Problem Curves =  "<<i5<<endl;
    cout<<"Stored MLS Curves =  "<<i3<<endl;
    cout<<"Stored Local Problem Curves =  "<<i4<<endl;
}
//********************************************************************
//*******************************************************************

vector<Curve> ReadSIFs::getPropSIFs(){
    return Propcurves;
}
//********************************************************************
//*******************************************************************

vector<Curve> ReadSIFs::getGLSIFs(){
    return GLcurves;
}
//********************************************************************
//*******************************************************************

vector<Curve> ReadSIFs::getGLMlsSIFs(){
    return GLmlsCurves;
}
//********************************************************************
//*******************************************************************

vector<Curve> ReadSIFs::getLSIFs(){
    return Lcurves;
}
//********************************************************************
//*******************************************************************

vector<Curve> ReadSIFs::getLMlsSIFs(){
    return LmlsCurves;
}
//********************************************************************
//*******************************************************************
