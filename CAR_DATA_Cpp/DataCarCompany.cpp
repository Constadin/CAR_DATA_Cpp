//methodoi DATACARCOMPANY

#include  "DataCarCompany.h"
#include  "Cars.h"

#include <iostream>
using namespace std;




DataCarCompany::DataCarCompany() //CONSTUCTOR defult
{
   matrix_car=NULL;
   m_size=0;
   
   //cout<<"constracting DEFULT"<<endl;	
}

DataCarCompany::DataCarCompany(int in_m_size)   //constractor gia arxikopoihsh kai desmeysh mnhmhs dynamika
{
    m_size= in_m_size;                        //arxikop toy megethoys me thn eiserxomenh timi
  
    //matrix_car= new int [m_size]; desmeysi mnhmhs dynamika gia pinaka monodiastato int
  
  if(!(matrix_car = new Cars [m_size]))
    {cout<<"ERROR ALLOCATING MEMORY"<<endl;}
    
    //cout<<"\nconstracting DYNAMIC MATRX"<<endl;
}

DataCarCompany::DataCarCompany(int in_i_car,const Cars &obj)   //copy constuctor
{
	matrix_car[in_i_car]=obj;
	
   //cout<<"\n\tcopy constracting ";
}

DataCarCompany::~DataCarCompany() //destuctor
{
  delete []	matrix_car;
  
  cout<<"\ndestracting  MATRX OBJ"<<endl;
}

void DataCarCompany::setm_size(int in_m_size)  //theti to size toy pinaka
{
 	m_size=in_m_size;
 	//cout<<"LINES METHODO "<<m_size<<endl;
}

int DataCarCompany::getm_size()const   //epistefei to megethos toy pinaka
{
	return m_size;
}
