//CAR DATA NEA VERSION

#include  "DataCarCompany.h"
#include  "Cars.h"


#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime> 
#include <ctype.h>
#include <iomanip>
#include <fstream>


#define MAX_NCAR 9999        //MAX NUM PINAKIDAS
#define MIN_NOFYEAR  1985   //MIN NUM XRONOLOGIAS CAR
#define MAX_NOFYEAR  2023  //MAX  NUM XRONOLOGIAS CAR

using namespace std;


extern "C"
{
  #include "C_file.h"
  
}



void inptData_C(Datacars *car_strt_Matrix,int sz_of_Lines);  //��������� ���������� DATA_FILE ��� C_FILE
int checkPointPinakida();
int checkPointYear();
void swapTwoCP(Cars *x, Cars *y);
void quickSortCP(Cars *matrix,const int first_id,const int last_id);
void UpdateBackup(char *filename, Cars *matrix, int lines) ;
void UpdateBackup(std::string filename,Cars *matrix, int lines);


int main(int argc, char* argv[])
{
	system("CHCP 1253>NULL");
	

    //argv[1]="LORD";	
	
	Datacars car_strt;       //BUFFER STRC APO C FILE
	Datacars car_color;     //BUFFER STRC APO C FILE
	Datacars car_factory;  //BUFFER STRC APO C FILE
	
	char str_color[10];
    char str_factory[15];
	
	char msg[20]="������� :";  //MHNYMA
	int basic_menu;           //RETURN APO C FILE NUM OF MENU
	int reload_menu=0;
    int chk_return;
    int sz_of_Lines=0; 
    bool flag=true;
    DataCarCompany *matrIX;
	Cars *arrayCAR; 
	
	int lines;
	int static static_check=0;
	Cars buff;
	int inpUT_i;
	int  cnt_zero=0;
	

	pass_word_s(argv);     //ELENXOS KODIKOY PROSBASIS
	do
      {
       do{
	      basic_menu=vasiko_menu(msg);      	//SYNARTHSH BASIKO MENOY STO C FILE
	      
	      if(static_check==0 && basic_menu!=1 && basic_menu!=0)
	        {
	      	 cout<<"\t   ������� �� (1) ��� ������� ���� ���� ���������\n"<<endl;
	      	 cout<<"\t   ������ �� �������� �������� ��� �� �����������\n"<<endl;
	         sleep(5);
		    }
	      }while(static_check ==0 && basic_menu!=1 && basic_menu!=0); 
		  
    	if(basic_menu==1) 
	       { 
			    static_check++; 
		    	chk_return=menu1("Cars.txt",&car_strt,&sz_of_Lines);  //SYNARTHSH EPILOGH MENOY 1 STO C FILE
		    	Datacars bufferCars_array[sz_of_Lines];              //BUFFER MATRIX GIA  APOTHIKEYSH MATRIX STRUCT
			    if(chk_return!=0)                                   //ELENXOS READ FILE FROM C FILE
			      { 
			       cerr<<"ERROR MEMORY I CAN T READ THIS FILE"<<endl;
				      exit(1);	
				  }
				else
				inptData_C(bufferCars_array,sz_of_Lines);        //SYNARTHSHS APOUHKEYSH DATA APO C_FILE.h
				
			    Cars matr_vehicle[sz_of_Lines];               //BUFFER MATRIX OBJ CAR
			    matrIX=new DataCarCompany(sz_of_Lines);      //DYNAMIKH DESMESYSH PINAKA ANALOGA ME SIZE APO C FILE(BASIC)
			    if(!matrIX)cout<<"\tERROR ALLOCATING MEMORY"<<endl;    //ELENXOS DYNAMHKHS DESMEYSHS MATRIX		    
			    matrIX->setm_size(sz_of_Lines); 
			    for(int i=0; i<matrIX->getm_size(); i++)   //METADOSH DEDOMENON APO STRUCT BUFFERMATRX STHN KLASH CARS
			       { 
		            matr_vehicle[i].setPinakida((bufferCars_array[i].pinakida_info));
				    matr_vehicle[i].setColorize((bufferCars_array[i].colors));
					matr_vehicle[i].setBrand((bufferCars_array[i].companies));
					matr_vehicle[i].setYear_Constrc((bufferCars_array[i].year_info));
		           }
			    arrayCAR= new Cars[matrIX->getm_size()];                     //DYNAMIKH DESMEYSH KYRIOY PINAKA OBJ MEFOTHOS OSO TO C FILE
			    if(!arrayCAR)cout<<"\tERROR ALLOCATING MEMORY"<<endl; //ELENXOS DYNAMHKHS DESMEYSHS MATRIX		    
			    
			    //memcpy(arrayCAR,matr_vehicle,sizeof(Cars )*matrIX->getm_size());//copies data bytes by byte 
			    
			    for(int i=0; i<(*matrIX).getm_size(); i++)   //ARXIKOPOIHSH
	               {
	               	if(matr_vehicle[i].getPinakida()==0)
	               	  {
	               		matr_vehicle[i].setColorize("      ");
	               	    matr_vehicle[i].setBrand("               ");
	               	    matr_vehicle[i].setYear_Constrc(0);
					   }
	       	        arrayCAR[i]=matr_vehicle[i];
		           }
		           
		        cout<<"\t____________________________________________"
					          "_____________________________________________________"
					          "_________________"<<endl;   
		        for(int i=0; i<matrIX->getm_size()-1; i++)  //EKTYPOSI
				      {
				       cout<<endl;	
				       arrayCAR[i].printCars(i);
				       cout<<"\t____________________________________________"
					          "_____________________________________________________"
					          "_________________"<<endl;
				      }
		         
			    flag=true;
			    cout<<endl;
			    system("PAUSE");
            } 
   		else if(basic_menu==2) 
	  	   {
				//system("CLS");
				system_ready(); 
		    	cout<<"\n\n\n";   
				cout<<"\t\t      ��������� **** ��� �������\n\n";
			    cout<<"\t\t        ( ** SYSTEM READY ** )    \n";        
			    cout<<"\t\t      __________________________\n\n";	            
			    cout<<"\t\t          ( ���� ��������� )    \n\n";           
		        cout<<"\t\t     **  D. A. T. A.    C A R S  **  \n\n"; 
		        sleep(1);   
			    cout<<"\t\t     �������� ����� ��� ��� �������\n\n";
				cout<<"\t* ��.��������� ��� �������� ���� ��� ������� (*��� ������� �������� 0 ������ �� ����� �������): "<<endl;
				cout<<"\t  --------------------------------------------\n";
				int flag_nomem=false;
			    
			  	    int cnt=7;
			  	   
			        for(int i=0; i<(*matrIX).getm_size(); i++)
			         {
			           cout<<"\t"<<arrayCAR[i].getPinakida()<<"  ";
			       	   if(i==cnt)
			       	     {
			       	      cout<<"\n";
			              cnt+=8; 	
					     }
				       }
				       
					for(int i=0; i<(*matrIX).getm_size(); i++) 
					   {
						  if(arrayCAR[i].getPinakida()==0)
						   {
							  flag_nomem=true;
						        break;	
							}  
						  else if(i==(*matrIX).getm_size()-1)
						     {
						   	  cout<<"\n\n\t* ��� �������� �� ������ ��� ������ ����������� �������� ��������� �����\n"<<endl;
						   	  cout<<"\t => ��� ��������� ��� ����� ���� O���������� �������:\n"<<endl;
						   	  flag_nomem=false;
						   	  system("PAUSE");
						     }
				        } 
			   //	system("PAUSE");  
		     if(flag_nomem==true)
		       { 
			    cout<<"\n\n\t(������������� ����� 1000-"<<MAX_NCAR<<")\n";
			    int new_pinakida;
			    do{
				   new_pinakida=checkPointPinakida();
				   for(int i=0; i<(*matrIX).getm_size(); i++)
		             {
		       	      if(arrayCAR[i].getPinakida()==new_pinakida)
		       	        {
		       	         cout<<"\tERROR ������� ���� � �������� (��� ���������� ������������)\n"<<endl;
		       	         cout<<"\t____________________________________________"
						          "_____________________________________________________"
						          "_________________\n"<<endl;	
				          arrayCAR[i].printCars(i);
					      cout<<"\t____________________________________________"
						          "_____________________________________________________"
						          "_________________"<<endl;
		       	          flag=1;
		       	          	  break;  	
					    }
					    flag=0;
				     }
				   }while(flag==1);
			    cout<<"\t>�������� ���������� ��������� :"<<new_pinakida<<"\n"<<endl;  
			    cout<<"\t\t=> �� ���� ��������� ������� �������H��� ���� ���� EINAI : \n";
			    cout<<"\t\t  > (�� ��������� �������H��� ���� �������� �� ����� ��������� ���� �� UPDATE ��� �����)\n";
			    sleep(2);
		        colors_car("BasicColors.txt",&car_color,&lines);          //������/������� �����������
			    cout<<"\n\t���� �� ����� ��� ����������� :";cin>>str_color;
			    cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
			    for(int i=0; i<strlen(str_color); i++)
				    {
				   	 str_color[i]=(toupper(str_color[i])); 
					}
			    chk_return=chekInputDataStruct(str_color); 
			    
			    while(chk_return==0 || strlen(str_color)>10)
			      {
			        if(strlen(str_color)>10)
				       cout<<"\t����� ��������� ��� ������� ������ ��������� (��� 10)"<<endl;
				    else if(chk_return==0 )	 	
				       cerr<<"\tEROOR  ����� �������� ��������� (������������ ���� ��������)\n";
				   
				    cout<<"\t���� �� ����� ��� ����������� :";cin>>str_color;
				   
				    chk_return=chekInputDataStruct(str_color); 
				  }
				  string new_color; 
				for(int i=0; i<strlen(str_color); i++)
				  {
				   	  new_color+=(toupper(str_color[i])); 
				  }
			    cout<<"\t>�������� ��������� �������� :"<<new_color<<endl;
			    cout<<endl;
			    int new_year;  
				new_year=checkPointYear();
			    cout<<"\t>�������� ���������� ����������� ����������:"<<new_year<<endl;
			    cout<<"\n\n\t\t=> �� ���� ���������� ������ �������H��� ���� ���� EINAI : \n";
			    cout<<"\t\t  > (�� ��������� ����������� ���� ������ �� ����� ��������� ���� �� UPDATE ��� �����)\n";
			    sleep(2);
		        companies_s("Companies.txt",&car_factory,&lines);
			    cout<<"\t���� ��� ������� ������������ :";cin>>str_factory;
			    cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
			    for(int i=0; i<strlen(str_factory); i++)
				    {
				   	 str_factory[i]=(toupper(str_factory[i])); 
					}
			    chk_return=chekInputDataStruct(str_factory); 
			    while(chk_return==0 || strlen(str_factory)>15)
			      {
			       if(strlen(str_factory)>15)
				      cout<<"\t����� ��������� ��� ������� ������ ��������� (��� 15)"<<endl;
				   else if(chk_return==0 )	 	
				      cerr<<"\tEROOR  ����� �������� ��������� (������������ ���� ��������)\n";
				    
				   cout<<"\n\t���� ��� ������� ������������ :";cin>>str_factory;
				   chk_return=chekInputDataStruct(str_factory); 
				  }
				  string new_factory; 
				for(int i=0; i<strlen(str_factory); i++)
				  {
				   new_factory+=(toupper(str_factory[i])); 
				  }
			    cout<<"\t>�������� ������H�� �������� ������������ :"<<new_factory<<endl;
			    cout<<endl;
				for(int i=0; i<matrIX->getm_size(); i++)
				   {  
				    if(arrayCAR[i].getPinakida()==0)
				      {
					    arrayCAR[i].setPinakida(new_pinakida);
					    arrayCAR[i].setColorize(new_color);
					    arrayCAR[i].setYear_Constrc(new_year);
					    arrayCAR[i].setBrand(new_factory);
					    cout<<"\t____________________________________________"
						          "_____________________________________________________"
						          "_________________\n"<<endl;
					    cout<<"\n\t�������� ��� ������ ����������� :\n"<<endl;   
				        arrayCAR[i].printCars(i);
				        cout<<"\t____________________________________________"
						          "_____________________________________________________"
						          "_________________"<<endl;
					      break;
				       }
				   }
				cout<<endl;   
		    	system("PAUSE");
		    	flag=true;
	           }
       	    }  
  	    else if(basic_menu==3)                       
	  	   {    
		        system("CLS");
			    system_ready(); 
		        cout<<"\n\n\n";   
			    cout<<"\t\t      ���������  ****  ��������\n\n";
			    cout<<"\t\t        ( ** SYSTEM READY ** )    \n";        
			    cout<<"\t\t      __________________________\n\n";	            
			    cout<<"\t\t          ( ���� ��������� )    \n\n";           
		        cout<<"\t\t     **  D. A. T. A.    C A R S  **  \n\n"; 
		        sleep(1);       
			    cout<<"\t\t\n";
			    for(int i=0; i<matrIX->getm_size(); i++)
				      {
				        if(arrayCAR[i].getPinakida()!=0)	
				         arrayCAR[i].printCars(i);
				        else if(arrayCAR[i].getPinakida()==0)
				         {
						  cout<<"\t____________________________________________"
						          "_____________________________________________________"
						          "_________________\n"<<endl;
				          arrayCAR[i].printCars(i); 
						  cout<<" *���������� ���� ("<<i<<") � ���� ����"<<endl;
				          cout<<"\t____________________________________________"
						          "_____________________________________________________"
						          "_________________\n"<<endl;
					     }
				      }
		        cout<<"\n\t* ������� ����������� ��� �� ���������"<<endl;
		        cout<<"\t  ------------------------------------"<<endl;
			    int del_pinakida;     
			    int i;
			    do{
				    del_pinakida=checkPointPinakida();
				    cout<<endl;
				    for( i=0; i<matrIX->getm_size(); i++)
		              {
		       	        if(arrayCAR[i].getPinakida()==del_pinakida)
						 {
						  arrayCAR[i].printCars(i);
						  Cars buff=arrayCAR[i];
						  inpUT_i=i;
						  flag=0;
						    break;
						 }
						else if(arrayCAR[i].getPinakida()!=del_pinakida && i==matrIX->getm_size()-1) 
						 {
						   cout<<"\t*��� ������� ���� � �������� ���� ���� ��� �� ���������\n"<<endl;
						   flag=1; 
						 }
				       }
				}while(flag==1);
			    cout<<"\n\t>�������� ������ ��������� ���������� ���� �������� ��� :"<<del_pinakida<<endl; 
			 	cout<<"\t => ��������� �������� ��� ��������� ����������� : (������� ��������?)\n"<<endl;
			 	char del_car;
				getchar(); 
			    cout<<"\t  => ������� �� ������� 'Y' ��� �� ��������EI � �������� � ����������� ���� ������� ��� �������:";cin>>del_car;
			     
				del_car=(toupper(del_car)); 
				  
			    if(del_car=='Y')
			      {
			       	 buff.setPinakida(0);
			       	 buff.setColorize("'del'");
			       	 buff.setYear_Constrc(0);
			       	 buff.setBrand("'del'");
				    
				    for( i=0; i<matrIX->getm_size(); i++)
		               {
		       	        if(inpUT_i==i)
						  {
						    arrayCAR[i]=buff;
						    cout<<"\n\t��������� �������� ��� ��������� �����������: \n"<<endl;
						    arrayCAR[i].printCars(i);
						    flag=0;
						     break;
						  }
				        }
				    cout<<"\n\t������ ��������� ��� ��������� ���� ����������� ...\n"<<endl;     
				    for( i=0; i<matrIX->getm_size(); i++)
		               {
					     arrayCAR[i].printCars(i);
						}
				 	cout<<"\n";	
					system("PAUSE"); 
				    cout<<"\n";  
				   }
			    else
			       {
			       	 cout<<"\t\t\n";
				     cout<<"\t  ��� ��������� ��� ����� ���� O���������� �������:\n"<<endl;	
			         system("PAUSE");
			         getchar();
				   }
		        flag=true;
       		}
   		else if(basic_menu==4)
	  	   {	
	            system("CLS");
			    system_ready(); 
		        cout<<"\n\n\n";   
			    cout<<"\t\t     ���������  ****  ��������-WR\n\n";
			    cout<<"\t\t        ( ** SYSTEM READY ** )    \n";        
			    cout<<"\t\t      __________________________\n\n";	            
			    cout<<"\t\t          ( ���� ��������� )    \n\n";           
		        cout<<"\t\t     **  D. A. T. A.    C A R S  **  \n\n"; 
		        sleep(1);       
			    cout<<"\t\t\n";
			    int find_pinakida;
				cout<<"\n\t�������A ��� ��������� ���� ����������� ...\n"<<endl;     
				for(int i=0; i<matrIX->getm_size(); i++)
		           {
		           	if(arrayCAR[i].getPinakida()!=0)
					   arrayCAR[i].printCars(i);
				   }
				cout<<"\n"<<endl;
				find_pinakida=checkPointPinakida();
				cout<<endl;
				int set_pinakida;
				int set_year;
				for(int i=0; i<matrIX->getm_size(); i++)
			       {
			        if(arrayCAR[i].getPinakida()==find_pinakida )
			          { 
					    arrayCAR[i].printCars(i);
					    cout<<endl;	
			          	cout<<"��������� �������� : \n\n";
			          	set_pinakida=checkPointPinakida();
			          	cout<<"\t>�������� �������H ��������� :"<<set_pinakida<<endl;
			          	cout<<"\n��������� �� ����� : \n\n";
			          	cout<<"\t\t=> �� ���� ��������� ������� �������H��� ���� ���� EINAI : \n";
					    cout<<"\t\t  > (�� ��������� �������H��� ���� �������� �� ����� ��������� ���� �� UPDATE ��� �����)\n";
					    sleep(2);
				        colors_car("BasicColors.txt",&car_color,&lines);          //������/������� �����������
					    cout<<"\n\t���� �� ����� ��� ����������� :";cin>>str_color;
					    cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
					    for(int i=0; i<strlen(str_color); i++)
						    {
						   	 str_color[i]=(toupper(str_color[i])); 
							}
					    chk_return=chekInputDataStruct(str_color); 
					    
					    while(chk_return==0 || strlen(str_color)>10)
					      {
					        if(strlen(str_color)>10)
						       cout<<"\t����� ��������� ��� ������� ������ ��������� (��� 10)"<<endl;
						    else if(chk_return==0 )	 	
						       cerr<<"\tEROOR  ����� �������� ��������� (������������ ���� ��������)\n";
						   
						    cout<<"\t���� �� ����� ��� ����������� :";cin>>str_color;
						   
						    chk_return=chekInputDataStruct(str_color); 
						  }
						  string new_color; 
						for(int i=0; i<strlen(str_color); i++)
						  {
						   	  new_color+=(toupper(str_color[i])); 
						  }
					    cout<<"\t>�������� �������� �������� :"<<new_color<<endl;
					    cout<<endl;
					    cout<<"\n��������� ���� ���������� : \n\n";
					    set_year=checkPointYear();
					    cout<<"\t>�������� �������� ���� ���������� :"<<set_year<<endl;
					    cout<<"\n��������� ������������ :";
						cout<<"\n\n\t\t=> �� ���� ���������� ������ �������H��� ���� ���� EINAI : \n";
					    cout<<"\t\t  > (�� ��������� ����������� ���� ������ �� ����� ��������� ���� �� UPDATE ��� �����)\n";
					    sleep(2);
				        companies_s("Companies.txt",&car_factory,&lines);
					    cout<<"\t���� ��� ������� ������������ :";cin>>str_factory;
					    cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
					    for(int i=0; i<strlen(str_factory); i++)
						    {
						   	 str_factory[i]=(toupper(str_factory[i])); 
							}
					    chk_return=chekInputDataStruct(str_factory); 
					    while(chk_return==0 || strlen(str_factory)>15)
			                 {
			                 if(strlen(str_factory)>15)
				               cout<<"\t����� ��������� ��� ������� ������ ��������� (��� 15)"<<endl;
				             else if(chk_return==0 )	 	
				               cerr<<"\tEROOR  ����� �������� ��������� (������������ ���� ��������)\n";
				    
				             cout<<"\n\t���� ��� ������� ������������ :";cin>>str_factory;
				             chk_return=chekInputDataStruct(str_factory); 
				            }
						string new_factory; 
						for(int i=0; i<strlen(str_factory); i++)
						  {
						   new_factory+=(toupper(str_factory[i])); 
						  }
					    cout<<"\t>�������� �������� �������� ������������ :"<<new_factory<<endl;
					    cout<<endl;
					    arrayCAR[i].setPinakida(set_pinakida);
					    arrayCAR[i].setColorize(new_color);
					    arrayCAR[i].setYear_Constrc(set_year);
					    arrayCAR[i].setBrand(new_factory);
					    cout<<"\n\t��� �������A ��������� ...\n"<<endl; 
						arrayCAR[i].printCars(i); 
					         break;
					   }
					else if(arrayCAR[i].getPinakida()!=find_pinakida && i==matrIX->getm_size()-1) 
					   {
					    cout<<"\t��� ������� ������������ ���� � �������� "<<endl;
					       break;
					   }
			        }
				cout<<endl;	
				cout<<"\t*��������� ��� ������ �����*  \n\n"<<endl;
				flag=1;
	            system("PAUSE");
	   		} 
   		else if(basic_menu==5)
	  	   {
			system_ready();                //������/�FE SYSTEM READY	
            do
              {
			    cout<<"\n\n\t���������� ��������� ��� ��������� ���� ����������� ...\n"<<endl; 		
				for(int i=0; i<matrIX->getm_size(); i++)
			      {
			       //if(arrayCAR[i].getPinakida()!=0)	
			         arrayCAR[i].printCars(i);
			      }
	            char str_anazitisi[5];  
	            int  anazitisi;
                anazitisi=menu_anazitisis_s(str_anazitisi);    //������/ ����� ����������      				 		 			     			 			          	            
				if(anazitisi==1) 
				  {
			        int find_pinakida;
				    cout<<"\n\t* ��.��������� ��� �������� ���� ��� ������� (*��� ������� �������� (0) )(����� ���� ����): "<<endl;
					int cnt=7;
				    for(int i=0; i<(*matrIX).getm_size(); i++)
				       {
				       	//if(arrayCAR[i].getPinakida()==0 && i!=cnt)
				       	  {
				       	   // arrayCAR[i].setBrand("  ////");
			               	//cout<<arrayCAR[i].getBrand();
						  }
				       	//else
						  {
						   cout<<"\t"<<arrayCAR[i].getPinakida()<<"  ";
					      }
				       	if(i==cnt)
				       	  {
				       	   cout<<"\n";
				           cnt+=8; 	
						  } 
					    }
					cout<<"\n"<<endl;
					find_pinakida=checkPointPinakida();
					cout<<endl;
					for(int i=0; i<matrIX->getm_size(); i++)
			           {
			             if(arrayCAR[i].getPinakida()==find_pinakida )
			               {
			               	arrayCAR[i].printCars(i);
			               	 break;
						   }
						 else if(arrayCAR[i].getPinakida()!=find_pinakida && i==matrIX->getm_size()-1) 
						    {
						     cout<<"\t��� ������� ������������ ���� � �������� "<<endl;
						       break;
							}
			             }
					cout<<endl;	
					cout<<"\t*��������� ��� ����� ����������*  \n\n"<<endl;
					getchar();  
			   	   } 
				else if(anazitisi==2) 
				   {
			        char find_color[10];
					cout<<endl;
					cout<<"\t\t=> �� ���� ��������� ������� �������H��� EINAI : \n";
					sleep(2);
				    colors_car("BasicColors.txt",&car_color,&lines);          //������/������� �����������
					cout<<"\n\t���� �� ����� ��� ����������� :";cin>>find_color;
					cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
					for(int i=0; i<strlen(find_color); i++)
					  {
					    find_color[i]=(toupper(find_color[i])); 
					  }
							
					chk_return=chekInputDataStruct(find_color); 
					    
					while(chk_return==0 || strlen(find_color)>10)
					   {
					    if(strlen(find_color)>10)
						   cout<<"\t����� ��������� ��� ������� ������ ��������� (��� 10)"<<endl;
						else if(chk_return==0 )	 	
						     cerr<<"\tEROOR  ����� �������� ��������� (������������ ���� ��������)\n";
						   
						cout<<"\t���� �� ����� ��� ����������� :";cin>>find_color;
						   
						chk_return=chekInputDataStruct(find_color); 
					   }
						string new_find_color; 
						for(int i=0; i<strlen(find_color); i++)
						  {
						   new_find_color+=(toupper(find_color[i])); 
						  }
					    cout<<endl;
					 
					    for(int i=0; i<matrIX->getm_size(); i++)
			              {
			               if(arrayCAR[i].getColorize()==new_find_color)
			                 {
			               	  arrayCAR[i].printCars(i);
			               	  flag=true;
						     }
			               } 	   
					    cout<<endl;
					    cout<<"\t*��������� ��� ����� ����������*  \n\n"<<endl;
					    getchar(); 		    
				      }
				else if(anazitisi==3) 
					 {
			            char find_factory[15];
					    cout<<endl;
					    cout<<"\n\t\t=> �� ���� ���������� ������ �������H��� ���� ���� EINAI : \n";
					    cout<<"\t\t  > (�� ��������� ����������� ���� ������ �� ����� ��������� ���� �� UPDATE ��� �����)\n";
					    sleep(2);
				        companies_s("Companies.txt",&car_factory,&lines);
					    cout<<"\t���� ��� ������� ������������ :";cin>>find_factory;
					    cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
					    for(int i=0; i<strlen(find_factory); i++)
						    {
						   	 find_factory[i]=(toupper(find_factory[i])); 
							}
					    chk_return=chekInputDataStruct(find_factory); 
					    while(chk_return==0 || strlen(find_factory)>15)
					      {
					       if(strlen(find_factory)>15)
						     cout<<"\t����� ��������� ��� ������� ������ ��������� (��� 15)"<<endl;
						   else if(chk_return==0 )	 	
						     cerr<<"\tEROOR  ����� �������� ��������� (������������ ���� ��������)\n";
						    
						   cout<<"\n\t���� ��� ������� ������������ :";cin>>find_factory;
						   chk_return=chekInputDataStruct(find_factory); 
						  }
						  string new_find_factory; 
						  for(int i=0; i<strlen(find_factory); i++)
						    {
						   	 new_find_factory+=(toupper(find_factory[i])); 
							}
			              cout<<endl;
					    for(int i=0; i<matrIX->getm_size(); i++)
			              {
			               if(arrayCAR[i].getBrand()==new_find_factory )
			                 {
			                  arrayCAR[i].printCars(i);
						     }
			               }
					    cout<<endl;
					    cout<<"\t*��������� ��� ����� ����������*  \n\n"<<endl;
					    getchar();
					  }	
				else if(anazitisi==4) 
					{
			         int find_year;
			         cout<<"\n\t* ����������� ��� �������� ���� ��� ������� (*��� ������� ���������� //// (����� ���� ����): "<<endl;
					 int cnt=7;
				     for(int i=0; i<(*matrIX).getm_size(); i++)
				       {
				       	if(arrayCAR[i].getYear_Constrc()>MAX_NOFYEAR  && i!=cnt)
				       	  {
				       	    arrayCAR[i].setBrand("////");
			               	cout<<arrayCAR[i].getBrand();
						  }
				       	else
						  {
						   cout<<"\t"<<arrayCAR[i].getYear_Constrc()<<"  ";
					      }
				       	if(i==cnt)
				       	  {
				       	   cout<<"\n";
				           cnt+=8; 	
						  } 
					    }
					    cout<<"\n"<<endl;
					    find_year=checkPointYear();
					    cout<<endl;
					    for(int i=0; i<matrIX->getm_size(); i++)
			              {
			               if(arrayCAR[i].getYear_Constrc()==find_year)
			                 {
			               	  arrayCAR[i].printCars(i);
						     }
			              }
			           /* for(int i=0; i<matrIX->getm_size(); i++)
			              {
			               if(arrayCAR[i].getYear_Constrc()!=find_year && i==matrIX->getm_size()-1)
			                 {
			               	  cout<<"\n\t* ��� ������� ������ ���������� ������������\n"<<endl;
						     }
			              }  */
					    cout<<endl;
					    cout<<"\t*��������� ��� ����� ����������*  \n\n"<<endl;
					    getchar();	
					  }
				else if(anazitisi==0) 
					  {
					   	 cout<<endl;	 
					     cout<<"\t\t*��������� ��� ������ �����*  \n\n"<<endl;
					     sleep(2); 
			   	           break;                	
					  }
			    else 		    
					flag=1;
					
					system("PAUSE"); 
			   	    system("CLS");		
			    }while(flag==1 );
				system("PAUSE"); 
       		   }	
   		else if(basic_menu==6)
	  		{   
	  		    system("CLS");
			    updateSystem();
			    cout<<"\n\n\n\t\t\t( ** please whait...** ) \n"; 
			    cout<<"\n\t\t      ( ** file classification** ) \n"; 
			    sleep(3);
			    system("CLS");
		        cout<<"\n\n\n";   
			    cout<<"\t\t       ���������  ****  UPDATE\n\n";
			    cout<<"\t\t       ( ** UPDATE SYSTEM ** ) \n";        
			    cout<<"\t\t      __________________________\n\n";	            
			    cout<<"\t\t          ( ���� ��������� )    \n\n";           
		        cout<<"\t\t     **  D. A. T. A.    C A R S  **  \n\n"; 
		        sleep(1);       
			    cout<<"\t\t\n";
	            Datacars bufferCars_array[matrIX->getm_size()];              //BUFFER MATRIX GIA  APOTHIKEYSH MATRIX STRUCT
			 
	    	    copyTextDataToArray("Cars.txt",bufferCars_array,matrIX->getm_size());     //�������� �� �������� ��� ������ ���� C
	            Datacars bufCars_array[matrIX->getm_size()];
	            //printData(bufferCars_array,matrIX->getm_size());
	            
	            for(int i=0; i<matrIX->getm_size(); i++)
			      {
			      	if(arrayCAR[i].getPinakida()==0)
			      	  {
					   arrayCAR[i].setColorize("'del'");
			      	   strcpy(bufCars_array[i].colors,arrayCAR[i].getColorize().c_str());
			      	   arrayCAR[i].setBrand("'del'");
				       strcpy(bufCars_array[i].companies,arrayCAR[i].getBrand().c_str());
				       arrayCAR[i].setPinakida(0);
				       bufCars_array[i].pinakida_info=arrayCAR[i].getPinakida();
				       arrayCAR[i].setYear_Constrc(0);
			   	       bufCars_array[i].year_info=arrayCAR[i].getYear_Constrc();
					  }
					else
					  {
					   bufCars_array[i].pinakida_info=arrayCAR[i].getPinakida();
			   	       bufCars_array[i].year_info=arrayCAR[i].getYear_Constrc();
				       strcpy(bufCars_array[i].colors,arrayCAR[i].getColorize().c_str());
				       strcpy(bufCars_array[i].companies,arrayCAR[i].getBrand().c_str());
					  }
			       }
			    //cout<<"\n\t��� �������� ���� ���� C  KATAXVRHSH ARRAYCARS\n\n"<<endl;
		        //printData(bufCars_array,matrIX->getm_size());
		        
   
                quickSortCP(arrayCAR,0,matrIX->getm_size()-1);
		        cars_UPDATE("Cars.txt",bufCars_array, matrIX->getm_size());
		        
		        
		        std::string filename = "BACKUPDATA.txt";
		        UpdateBackup(filename, arrayCAR, matrIX->getm_size());
				cout<<"\n"<<endl;  
				
				  
			    for(int i=0; i<matrIX->getm_size(); i++)
			      {
			       arrayCAR[i].printCars(i);
			      }
			    cout<<"\n\n\n\t\t ( ** SYSTEM UPDATED successfully ** ) \n";  
			    cout<<"\n"<<endl;
			    system("PAUSE");
			    
			    std::string command = "start msedge http://localhost/my_first_web/PROJECT_BMV/indexph.php";
                system(command.c_str());
       		  }       
   		else if(basic_menu==0)
	  		{
	            flag=goodbaye();   //������/������
	            if(flag==0)
	              {
	               flag=false;
				    exit(0);	
				  }
	            else if(flag==1)
				  flag=true;
       		}
		//getchar();   
   	   	//system("CLS");			  	 
      }while((reload_menu>=0 || reload_menu<=6) && flag==true);
      
    //delete []	matrIX;  
    //delete [] arrayCAR;
	// Clean up
  
	return 0;
}





void inptData_C(Datacars *bufferCars_array,int sz_of_Lines)            //��������� ���������� DATA_FILE ��� C_FILE
{
	
    copyTextDataToArray("Cars.txt",bufferCars_array,sz_of_Lines);     //�������� �� �������� ��� ������ ���� C
			
	cout<<"\n\t���������� ��������� ��� ��������� ���� ����������� ..."<<endl; 
	//cout<<endl;
	/*for(int i =0 ;  i<sz_of_Lines-1 ; i++)
	   {
	   	//sleep(1);	
	   	cout<<"  Id ("<<i<<")"<<"\t��.����   "<<bufferCars_array[i].pinakida_info
		    <<"\t�����   "<<bufferCars_array[i].colors<<"\t����������  "
		    <<bufferCars_array[i].year_info
		    <<"    �������������   "<<bufferCars_array[i].companies<<endl;
	   }
	cout<<"\t  ��� ��������� ��� ����� ���� O���������� �������:\n\n"<<endl;	
	system("PAUSE");*/	   	
}


int checkPointPinakida()
{   
    char str_pinakida[10];
    
    cout<<"\t���� ������ ��������� :";cin>>str_pinakida;
 	cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
	int new_pinakida;
	new_pinakida=AfterCheckBasicMenu(str_pinakida);
	while(new_pinakida<1000 || new_pinakida >MAX_NCAR)
	  {
	   cerr<<"\tEROOR  ����� �������� ��������� (������������� ����� 1000-"<<MAX_NCAR<<")\n";
	   cout<<"\t���� ������ ��������� :";cin>>str_pinakida;
	   new_pinakida=AfterCheckBasicMenu(str_pinakida);
	  }
	
	return new_pinakida;		    
}


int checkPointYear()
{   
    char str_year[5];
    
    cout<<"\t���� ���� ���������� :";cin>>str_year;
 	cout<<"\n\t�������������� ������� ��������� ��������� ��� ��� ������"<<endl;
	int new_year;
	new_year=AfterCheckBasicMenu(str_year);
	while(new_year==-1 || new_year < MIN_NOFYEAR  || new_year>MAX_NOFYEAR )
	  {
	   cerr<<"\tEROOR  ����� �������� ��������� (������������� ����� "<<MIN_NOFYEAR<<"-"<<MAX_NOFYEAR<<")\n";
	   cout<<"\t���� ���� ���������� :";cin>>str_year;
	   new_year=AfterCheckBasicMenu(str_year);
	  }
	
	return new_year;		    
}


void swapTwoCP(Cars *x, Cars *y)
{
	Cars  temp= *x;
	
	*x=*y;
	*y= temp;
}



void quickSortCP(Cars *matrix,const int first_id,const int last_id)
{
	int pivot,i,j;
	
	if(first_id<last_id  )
	 {
	 	pivot=first_id;
	 	i=first_id;
	 	j=last_id;
	 	
	  while(i<j)	
	    {	  
	 	 while(matrix[i].getPinakida() <= matrix[pivot].getPinakida() && i<last_id)
	 	    i++;
	 	
	      while(matrix[j].getPinakida()>matrix[pivot].getPinakida())
	        j--;
	      
	      if(i<j)
		    swapTwoCP(&matrix[i],&matrix[j]);
        }
         swapTwoCP(&matrix[pivot],&matrix[j]);
	     quickSortCP(matrix,first_id,j-1);
	     quickSortCP(matrix,j+1,last_id);
     }
    
}



void UpdateBackup(string filename, Cars *matrix, int lines) 
{
	
    std::ofstream file(filename); // creates/opens the file
    for(int i=0; i<lines; i++)
		{
		 if(matrix[i].getPinakida()!=0)
		   {
		 	file<<setw(15)<<i<<setw(20)<<matrix[i].getPinakida()<<setw(20)
	        <<matrix[i].getColorize()<<setw(20)<<matrix[i].getBrand()<<setw(20)
		    <<matrix[i].getYear_Constrc()<<endl;
		   }
		}   
    
    file.close(); // close the file
}
