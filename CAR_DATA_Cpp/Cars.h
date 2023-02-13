//class Cars

#ifndef CARS_H
#define CARS_H

#include <iostream>
#include <string>
using namespace std;



class Cars{
	
	public:
		Cars();              //constuctor defult	
		Cars(int inp_pinakida,string inp_colorize,int inp_year_constrc,string inp_brand); //constructor orismata to megethos toy pinaka	
		~Cars();           //destracting
		void setPinakida(int inp_pinakida);
	    void setColorize(string inp_colorize);
	    void setYear_Constrc(int inp_year_constrc);
	    void setBrand(string inp_brand);
		int getPinakida();
	    string getColorize();
	    int getYear_Constrc();
	    string getBrand();
		void printCars(int inp_i);	
    private:
	    int pinakida;
	    string colorize;
	    int year_constrc;
	    string brand;
    
};
#endif
