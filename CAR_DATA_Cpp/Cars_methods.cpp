//methodoi CARS

#include  "Cars.h"

#include <iomanip>
#include <iostream>
using namespace std;


Cars::Cars()   //CONSTUCTOR defult
{
   pinakida=0;
   colorize="";
   year_constrc=0;
   brand="";
   //cout<<"constracting DEFULT"<<endl;	
}

Cars::Cars(int inp_pinakida,string inp_colorize,int inp_year_constrc,string inp_brand)   //constractor gia arxikopoihsh 
{   
    
    pinakida=inp_pinakida;
    colorize=inp_colorize;
    year_constrc=inp_year_constrc;
    brand=inp_brand;
    
    //cout<<"\nconstracting DYNAMIC MATRX"<<endl;
}

Cars::~Cars() //destuctor
{
  
  //cout<<"\ndestracting  MATRX OBJ"<<endl;
}

void Cars::setPinakida(int inp_pinakida)
{
	pinakida=inp_pinakida;
}

void Cars::setColorize(string inp_colorize)
{
	colorize=inp_colorize;
}

void Cars::setYear_Constrc(int inp_year_constrc)
{
	year_constrc=inp_year_constrc;
}

void Cars::setBrand(string inp_brand)
{
	brand=inp_brand;
}

int Cars::getPinakida()
{
	return pinakida;
}

string Cars::getColorize()
{
	return colorize;
}

int Cars::getYear_Constrc()
{
	return year_constrc;
}

string Cars::getBrand()
{
	return brand;
}

void Cars::printCars(int inp_i)
{
	//sleep(1);	
	cout<<setw(10)<<"  Id ("<<inp_i<<")"<<setw(15)<<"\tÁÑ.ÊÕÊË   "<<getPinakida()<<setw(15)<<
	    "\t×ÑÙÌÁ   "<<getColorize()<<setw(20)<<"\t×ÑÏÍÏËÏÃÉÁ   "<<getYear_Constrc()<<setw(23)<<
		"\tÊÁÔÁÓÊÅÕÁÓÔÇÓ   "<<getBrand()<<endl;
		
}
