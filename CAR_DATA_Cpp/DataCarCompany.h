//class DataCarCompany

#ifndef DATACARCOMPANY_H
#define DATACARCOMPANY_H

#include  "Cars.h"

#include <iostream>
#include <string>
using namespace std;

class Cars; //FORW_DEC

class DataCarCompany{
	
	public:
		DataCarCompany();                  //constuctor defult	
		DataCarCompany(int in_m_size);    //constructor orismata to megethos toy pinaka	
		~DataCarCompany();               //destracting
		DataCarCompany(int in_i_car,const Cars &obj);   //copy constuctor
		void setm_size(int in_m_size);     //theti to size toy pinaka
		int getm_size()const;             //epistefei to megethos toy pinaka   
	private:
		Cars *matrix_car; 
		int  m_size;               //to megethos toy pinaka poy TO DINEI TO FILE (LINES)
};
#endif
