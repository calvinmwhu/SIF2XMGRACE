#include "writeXMgrace.h"
#include <algorithm>
using namespace std;


//*********************************************************
//*********************************************************
WriteXMgrace::WriteXMgrace(const string& file2, 
			   vector<Curve> Propcurves,
			   vector<Curve> GLcurves, 
			   vector<Curve> GLmlscurves, 
			   vector<Curve> Lcurves, 
			   vector<Curve> Lmlscurves, string PCols, 
			   int opt, bool PROP, bool PGL, 
			   bool PGLMLS, bool PL, bool PLMLS, 
			   /*vector<int> planeV, vector<double> Center,*/
			   double X_ini, double X_end, vector <int> Pindex,
               bool deleteFiles, bool isPropFile) {
  
  //START WRITING XMgrace files
  vector<vector<double> > currentCurv;
  double x, y, angle, deltaX/*, maxAngle*/;
  string plotString ="xmgrace ";
  char * pEnd;
  int icurve=-1;
  int endCurves= 0;
  int numPoints = 0;
  
   
  // string batchFileName = "batchFile";
  batchfile.open("batchFile");
  batchfile<<"# File used to set some options for xmgrace plot"<<endl;
  
  //WRITE curves for propagation
  if(PROP){
    endCurves=Propcurves.size();
    
    cout<<"propagation curve has "<<Pindex.size()<<" curves plotted"<<endl;
    
    for (int x=0; x<(int)Pindex.size(); x++){
    	int i=0;
    	if(Pindex[x]>endCurves) i=endCurves;
    	else i=Pindex[x];

      icurve++;
      string outFileName = file2 + ".sifPropXM_";
      plotString +=" -block " + file2 + ".sifPropXM_";
      char elementIndex_chr [10];
      sprintf(elementIndex_chr, "%d", i);
      //add string of the element ID to the name
      outFileName += elementIndex_chr;
      plotString +=  elementIndex_chr;

      // test that input file opens properly
      ofstream outfile(outFileName.c_str());
      if (! outfile){
	cerr << "can't open output file\"" << file2 << "\""
	     << endl;
	exit(EXIT_FAILURE);
      }
    
      // get curves and curve information 
      currentCurv=Propcurves[i].getCurveInfo();
      numPoints=currentCurv[0].size();
      deltaX = (X_end - X_ini)/(numPoints-1);
      // loop over points (or vertex)
      for(int iv=0; iv<numPoints; iv++){
	// loop over information type (id,x,y,z,KI,KII,KIII)
    for(int itype=0; itype<(int)currentCurv.size(); itype++){
	 //cout << "line " << __LINE__ <<  endl ;	  
	  if(itype == 0){ 
	    //this will be X axis value to plot
	    // this value depends on the user input
	    // and the number of vertex points found
	    // in the extraction file
	    
	    // tmp for ellipsed crack
	    /* if(X_ini + deltaX*iv > 360)
	      outfile<<X_ini + deltaX*iv-360<<"  ";
	      else*/
	      outfile<<X_ini + deltaX*iv<<"  ";
	  }else{ // this are the points info 
	    outfile<<currentCurv[itype][iv]<<"  ";
	  }
	}
	outfile<<endl;
	
      }
      // here choose to write batch file according to the 
      // option choosen by the user (printing only KI or KII...)
      writeBatch(Propcurves[i], opt, isPropFile, icurve);
      plotString +=  " -graph 0" + PCols;
    }
  }
 
  
  //WRITE global Raw curves 
  if(PGL){
    endCurves=GLcurves.size();
    
   cout<<"global raw curve has "<<Pindex.size()<<" curves plotted"<<endl;
    
    for (int x=0; x<(int)Pindex.size(); x++){
    	int i=0;
    	if(Pindex[x]>endCurves) i=endCurves;
    	else i=Pindex[x];
    
    
      icurve++;
      string outFileName = file2 + ".sifGXM_";
      plotString +=" -block " + file2 + ".sifGXM_";
      char elementIndex_chr [10];
      sprintf(elementIndex_chr, "%d", i);
      //add string of the element ID to the name
      outFileName += elementIndex_chr;
      plotString +=  elementIndex_chr;

      // test that input file opens properly
      ofstream outfile(outFileName.c_str());
      if (! outfile){
	cerr << "can't open output file\"" << file2 << "\""
	     << endl;
	exit(EXIT_FAILURE);
      }
    
      // get all the curves and its information 
      currentCurv=GLcurves[i].getCurveInfo();
      numPoints=currentCurv[0].size();
      deltaX = (X_end - X_ini)/(numPoints-1);
      // loop over points (or vertex)
      for(int iv=0; iv<numPoints; iv++){
	// loop over information type (id,x,y,z,KI,KII,KIII)
    for(int itype=0; itype<(int)currentCurv.size(); itype++){
	 
	  if(itype == 0){ 
	    //this will be X axis value to plot
	    // this value depends on the user input
	    // and the number of vertex points found
	    // in the extraction file

	    // tmp for ellipsed crack
	    //   if(X_ini + deltaX*iv > 360)
	    //   outfile<<X_ini + deltaX*iv-360<<"  ";
	    //else
	      outfile<<X_ini + deltaX*iv<<"  ";
	  }else{ // this are the points info 
	    outfile<<currentCurv[itype][iv]<<"  ";
	  }
	}
	outfile<<endl;
	
      }
      // here choose to write batch file according to the 
      // option choosen by the user (printing only KI or KII...)
      writeBatch(GLcurves[i], opt, isPropFile, icurve);
      plotString +=  " -graph 0" + PCols;
    }
  }
  
  //WRITE global MLS curves 
  if(PGLMLS){
    endCurves=GLmlscurves.size();
    
    cout<<"global MLS curve has "<<Pindex.size()<<" curves plotted"<<endl;
    
    
    for (int x=0; x<(int)Pindex.size(); x++){
    	int i=0;
    	if(Pindex[x]>endCurves) i=endCurves;
    	else i=Pindex[x];
    	
      icurve++; 
      string outFileName = file2 + ".sif_GLMLS_XM_";
      plotString +=" -block " + file2 + ".sif_GLMLS_XM_";
      char elementIndex_chr [10];
      sprintf(elementIndex_chr, "%d", i);
      //add string of the element ID to the name
      outFileName += elementIndex_chr;
      plotString +=  elementIndex_chr;
      // test that input file opens properly
      ofstream outfile(outFileName.c_str());
      
      if (! outfile){
	cerr << "can't open output file\"" << file2 << "\""
	     << endl;
	exit(EXIT_FAILURE);
      }
      
      // get all the curves and its information 
      currentCurv=GLmlscurves[i].getCurveInfo();
      numPoints=currentCurv[0].size();
      deltaX = (X_end - X_ini)/(numPoints-1);
      for(int iv=0; iv<(int)currentCurv[0].size(); iv++){
    for(int itype=0; itype<(int)currentCurv.size(); itype++){
	   
	  if(itype == 0){ 
	    //this will be X axis value to plot
	    // this value depends on the user input
	    // and the number of vertex points found
	    // in the extraction file
	    outfile<<X_ini + deltaX*iv<<"  ";
	  }else{
	    outfile<<currentCurv[itype][iv]<<"  ";
	  }
	}
	outfile<<endl;
      }
      // here choose to write batch file according to the 
      // option choosen by the user (printing only KI or KII...)
      writeBatch(GLmlscurves[i], opt, isPropFile, icurve);

      plotString +=  " -graph 0" + PCols;
    }
  }
  

  //WRITE local Raw curves 
  if(PL){
    endCurves=Lcurves.size();
    
    cout<<"local raw curve has "<<Pindex.size()<<" curves plotted"<<endl;
    
    
   // cout << "\n writeSIF:: Local curves number" << endCurves << endl;

    for (int x=0; x<(int)Pindex.size(); x++){

   // if(endCurves == 0)
   // break;

    	int i=0;
    	if(Pindex[x]>endCurves) i=endCurves;
    	else i=Pindex[x];
      icurve++;
      string outFileName = file2 + ".sifLXM_";
      plotString +=" -block " + file2 + ".sifLXM_";
      char elementIndex_chr [10];
      sprintf(elementIndex_chr, "%d", i);
      //add string of the element ID to the name
      outFileName += elementIndex_chr;
      plotString +=  elementIndex_chr;
      // test that input file opens properly
      ofstream outfile(outFileName.c_str());
      
      if (! outfile){
	cerr << "can't open output file\"" << file2 << "\""
	     << endl;
	exit(EXIT_FAILURE);
      }
          
      // get all the curves and its information 
      currentCurv=Lcurves[i].getCurveInfo();
      numPoints=currentCurv[0].size();
      deltaX = (X_end - X_ini)/(numPoints-1);
      for(int iv=0; iv<(int)currentCurv[0].size(); iv++){
    for(int itype=0; itype<(int)currentCurv.size(); itype++){
	  if(itype == 0){ 
	    //this will be X axis value to plot
	    // this value depends on the user input
	    // and the number of vertex points found
	    // in the extraction file
	    outfile<<X_ini + deltaX*iv<<"  ";
	  }else{
	    outfile<<currentCurv[itype][iv]<<"  ";
	  }
	}
	outfile<<endl;
      }
      // here choose to write batch file according to the 
      // option choosen by the user (printing only KI or KII...)
      writeBatch(Lcurves[i], opt, isPropFile, icurve);

      plotString +=  " -graph 0" + PCols;
    }
  }
  
  // WRITE local MLS curves 
  if(PLMLS){
    endCurves=Lmlscurves.size();
    cout<<"local MLS curve has "<<Pindex.size()<<" curves plotted"<<endl;

    //cout << "\n writeSIF:: Local  MLS curves number" << endCurves << endl;
    
    for (int x=0; x<(int)Pindex.size(); x++){

   // if(endCurves == 0)
   // break;

    int i=0;
    	if(Pindex[x]>endCurves) i=endCurves;
    	else i=Pindex[x];
      icurve++;
      string outFileName = file2 + ".sif_LMLS_XM_";
      plotString +=" -block " + file2 + ".sif_LMLS_XM_";
      char elementIndex_chr [10];
      sprintf(elementIndex_chr, "%d", i);
      //add string of the element ID to the name
      outFileName += elementIndex_chr;
      plotString +=  elementIndex_chr;
      // test that input file opens properly
      ofstream outfile(outFileName.c_str());
      
      if (! outfile){
	cerr << "can't open output file\"" << file2 << "\""
	     << endl;
	exit(EXIT_FAILURE);
      }
      
      // get all the curves and its information 
      currentCurv=Lmlscurves[i].getCurveInfo();
      numPoints=currentCurv[0].size();
      deltaX = (X_end - X_ini)/(numPoints-1);
      for(int iv=0; iv<(int)currentCurv[0].size(); iv++){
    for(int itype=0; itype<(int)currentCurv.size(); itype++){
	  if(itype == 0){ 
	    //this will be X axis value to plot
	    // this value depends on the user input
	    // and the number of vertex points found
	    // in the extraction file
	    outfile<<X_ini + deltaX*iv<<"  ";
	  }else{
	    outfile<<currentCurv[itype][iv]<<"  ";
	  }
	}
	outfile<<endl;
      }
      // here choose to write batch file according to the 
      // option choosen by the user (printing only KI or KII...)
      writeBatch(Lmlscurves[i], opt, isPropFile, icurve );
      plotString +=  " -graph 0" + PCols;
    }
  }

  // finish with last options for xmgrace 
  // plot on batch file
  batchfile<<"yaxis label \"SIFs\" "<<endl;
  batchfile<<"xaxis label \" \\f{Symbol}q\\f{} \" "<<endl;
  batchfile<<"world xmin "<<X_ini<<endl;
  batchfile<<"world xmax "<<X_end<<endl;
  batchfile<<"world ymin 0"<<endl;

  //plotString += "-block ellip_exact -graph 0 -bxy 1:5 -batch batchFile &";
  plotString += " -batch batchFile &";
  //cout<<plotString<<endl;
  system(plotString.c_str());

  if(deleteFiles){
    time_t rawtime;
    time ( &rawtime );
    string removeFiles;
    sleep(2);
    if(PROP){
      removeFiles = "rm -f " + file2 + ".sifPropXM_*";
      system(removeFiles.c_str());
    }
    if(PGL){
      removeFiles = "rm -f " + file2 + ".sifGXM_*";
      system(removeFiles.c_str());
    }
    if(PGLMLS){
      removeFiles = "rm -f " + file2 + ".sif_GLMLS_XM_*";
      system(removeFiles.c_str());
    }
    if(PL){
      removeFiles = "rm -f " + file2 + ".sifLXM_*";
      system(removeFiles.c_str());
    }
    if(PLMLS){
      removeFiles = "rm -f " + file2 + ".sif_LMLS_XM_*";
      system(removeFiles.c_str());
    }
  }
}
//********************************************************
//*******************************************************
void WriteXMgrace::writeBatch(Curve Acurve, int opt, 
			      bool isPropFile, int & icurve){

      switch(opt){
      case(1):
      case(2):
      case(3):
      case(4):
	{
	if(!isPropFile){
	  
	  if(Acurve.getMethod() == " CFM"){
	    batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		     <<Acurve.getMethod()<<" \\xr\\s1\\N = "
		     <<Acurve.getR1();
	    batchfile<<", r\\s2\\N = "
		     <<Acurve.getR2();
	  }
	  else{
	    batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		     <<Acurve.getMethod()<<" \\xr = "
		     <<Acurve.getR1();
	  }
	batchfile<<" \" "<<endl;
	batchfile<<"s"<<icurve<<" "<<"line type 1 \n";
	//batchfile<<"s"<<icurve<<" "<<"line width 2 \n";
	batchfile<<"s"<<icurve<<" "<<"symbol "<<icurve+1<<endl;
	batchfile<<"s"<<icurve<<" "<<"symbol char 60 \n";
	batchfile<<"s"<<icurve<<" "<<"symbol size 0.5 \n";
	}
	else{
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" Step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;
	  /*batchfile<<"s"<<icurve<<" "<<"line type 0 \n";
	  batchfile<<"s"<<icurve<<" "<<"symbol "<<icurve+1<<endl;
	  batchfile<<"s"<<icurve<<" "<<"symbol char 60 \n";
	  batchfile<<"s"<<icurve<<" "<<"symbol size 0.5 \n";*/
	}
	break;
      }
	
      case(5):{
	if(!isPropFile){
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KI r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;
	  
	  icurve++;
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KII r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;
	  
	  icurve++;
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KIII r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;
	  
	  //icurve++;
	}
	else{
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KI step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;
	  
	  icurve++;
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KII step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;
	  
	  icurve++;
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KIII step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;
	  
	  //icurve++;
	}
	break;
      }
     case(6):{
     if(!isPropFile){
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KI r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;
	  icurve++;
	  
	  
	  
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KII r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;	  
	  icurve++;
	  
	  
	  
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KIII r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;	  
	  icurve++;
	  
	  
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" G r1 = "
		   <<Acurve.getR1();
	  if(Acurve.getMethod() == " CFM")
	    batchfile<<", r2 = "
		     <<Acurve.getR2();
	  
	  batchfile<<" \" "<<endl;
	  //icurve++;
	  
	}
	else{
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KI step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;	
	  icurve++;
	  
	  
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KII step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;	  
	  icurve++;
	  
	  
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" KIII step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;	  
	  icurve++;
	  
	  
	  batchfile<<"s"<<icurve<<" "<<"legend"<<" \" "
		   <<Acurve.getMethod()<<" G step = "
		   <<Acurve.getStepNum();
	  batchfile<<" \" "<<endl;
	 
	  
	  
	}
	break;
     }
      
    }


}
