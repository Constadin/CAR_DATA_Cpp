//CAR DATA NEO VERSION


#include <cstdlib>
#include <iostream>
#include <string>
#include <unistd.h>
#include <ctime> 
#include <ctype.h>

#define MAX_NCAR 9999
#define MIN_NOFYEAR  1985
#define MAX_NOFYEAR  2023

using namespace std;


extern "C"
{
  #include "C_file.h"
  
}


class Cars; //FORW_DEC

class DataCarCompany{
	
	public:
		DataCarCompany();                  //constuctor defult	
		DataCarCompany(int in_m_size);    //constructor orismata to megethos toy pinaka	
		~DataCarCompany();               //destracting
		DataCarCompany(int in_i_car,const Cars &obj);//copy constuctor
		void setm_size(int in_m_size);              //theti to size toy pinaka
		int getm_size()const;                      //epistefei to megethos toy pinaka   
	private:
		Cars *matrix_car; 
		int  m_size;                           //to megethos toy pinaka poy TO DINEI TO FILE (LINES)
};


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



void inptData_C(Datacars *car_strt_Matrix,int sz_of_Lines);  //пяосыяимг апохгйеусг DATA_FILE апо C_FILE
int checkPointPinakida();
int checkPointYear();


int main(void)
{
	system("CHCP 1253>NULL");
	
	Datacars car_strt;    //BUFFER STRC APO C FILE
	Datacars car_color;  //BUFFER STRC APO C FILE
	Datacars car_factory;  //BUFFER STRC APO C FILE
	
	char str_color[10];
    char str_factory[15];
	
	char msg[20]="епикоцг :";  //MHNYMA
	int basic_menu;           //RETURN APO C FILE NUM OF MENU
	int reload_menu=0;
    int chk_return;
    int sz_of_Lines=0; 
    bool flag=true;
    DataCarCompany *matrIX;
	Cars *arrayCAR; 
	pass_word_s();    //ELENXOS KODIKOY PROSBASIS
	int lines;
	int static static_check=0;
	Cars buff;
	int pivot_1=0;
	int pivot_2=1;
	int inpUT_i;
	
	
	
	
	
	do
      {
       do{
	   	  
	      basic_menu=vasiko_menu(msg);      	//SYNARTHSH BASIKO MENOY STO C FILE
	      
	      if(static_check==0 && basic_menu!=1)
	        {
	      	 cout<<"\t   епекене то (1) циа сумдесг стгм басг дедолемым\n"<<endl;
	      	 cout<<"\t   пяепеи ма упаявоум дедолема циа ма пяовыяисте\n"<<endl;
	         sleep(3);
	         if(static_check==0 && basic_menu==0)
	           {
	           	goodbaye();        	          //сумаят/енодос 
	            flag=false;
			   }
		    }
	     }while(static_check ==0 && basic_menu!=1); 
		  
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
			cout<<"\t\t      епикенате **** меа еццяажг\n\n";
		    cout<<"\t\t        ( ** SYSTEM READY ** )    \n";        
		    cout<<"\t\t      __________________________\n\n";	            
		    cout<<"\t\t          ( басг дедолемым )    \n\n";           
	        cout<<"\t\t     **  D. A. T. A.    C A R S  **  \n\n"; 
	        sleep(1);   
		    cout<<"\t\t     паяайакы дысте тгм меа еццяажг\n\n";
			cout<<"\t* ая.пимайидым поу упаявоум еидг сто сустгла (*ЕАМ УПэЯВЕИ ПИМАЙъДА 0 ЛПОЯЕъ МА ЦъМЕИ ЕЦЦЯАЖч): "<<endl;
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
				
				   if(arrayCAR[i].getPinakida()!=0 && i==(*matrIX).getm_size()-1)
				     {
				   	  cout<<"\n\n\t* дем лпояеите ма йамете меа ецяажг аутойимгтоу адумалиа екеухеяоу выяоу\n"<<endl;
				   	  cout<<"\t => циа епистяожг сто лемоу пата Oпоиодгпоте пкгйтяо:\n"<<endl;
				   	  flag_nomem=false;
				   	  system("PAUSE");
				     }
					else if(arrayCAR[i].getPinakida()==0)
					  {
					  flag_nomem=true;
				        break;	
					  }
					     
			     } 
		//	system("PAUSE");  
		 if(flag_nomem==true)
		    { 
		     cout<<"\n\n\t(епитяеполемес тилес 1000-"<<MAX_NCAR<<")\n";
		    
		    int new_pinakida;
		    do{
			   new_pinakida=checkPointPinakida();
			   for(int i=0; i<(*matrIX).getm_size(); i++)
	             {
	       	        if(arrayCAR[i].getPinakida()==new_pinakida)
	       	          {
	       	          	cout<<"\tERROR упаявеи аутг г пимайида (дем епитяепете дипкоеццяажг)\n"<<endl;
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
		    cout<<"\t>епитувгс йатавыягсг пимайидас :"<<new_pinakida<<"\n"<<endl;  
		    cout<<"\t\t=> та еидг диахесила вяылата аутойимHтоу стгм басг EINAI : \n";
		    cout<<"\t\t  > (се пеяиптысг йатавыяHсгс меоу вяылатос ха еимаи диахесило лета то UPDATE тгс басгс)\n";
		    sleep(2);
	        colors_car("BasicColors.txt",&car_color,&lines);          //сумаят/вяылата аутойимитым
		    cout<<"\n\tдысе то вяыла тоу аутойимгтоу :";cin>>str_color;
		    cout<<"\n\tакжаяихлгтийос екемвос еисацыцгс дедолемым апо том вягстг"<<endl;
		    for(int i=0; i<strlen(str_color); i++)
			    {
			   	 str_color[i]=(toupper(str_color[i])); 
				}
				
		
		   
		    chk_return=chekInputDataStruct(str_color); 
		    while(chk_return==0 || strlen(str_color)>7)
		      {
		       if(strlen(str_color)>7)
			     cout<<"\tевеис непеяасеи том лецисто аяихло цяаллатым (лав 7)"<<endl;
			   else if(chk_return==0 )	 	
			     cerr<<"\tEROOR  кахос еисацыцг дедолемым (епитяепомтаи ломо цяаллата)\n";
			   
			   cout<<"\tдысе то вяыла тоу аутойимгтоу :";cin>>str_color;
			   
		
			   
			   chk_return=chekInputDataStruct(str_color); 
			  }
			  string new_color; 
			  for(int i=0; i<strlen(str_color); i++)
			    {
			   	 new_color+=(toupper(str_color[i])); 
				}
		      cout<<"\t>епитувгс йатвыяисг вяылатос :"<<new_color<<endl;
		      cout<<endl;
		    int new_year;  
			new_year=checkPointYear();
		    cout<<"\t>епитувгс йатавыягсг вяомокоциас йатасйеугс:"<<new_year<<endl;
		    
		    cout<<"\n\n\t\t=> ои еидг диахесилес лаяйес аутойимHтоу стгм басг EINAI : \n";
		    cout<<"\t\t  > (се пеяиптысг йатавыягсгс меас лаяйас ха еимаи диахесилг лета то UPDATE тгс басгс)\n";
		    sleep(2);
	        companies_s("Companies.txt",&car_factory,&lines);
		    cout<<"\tдысе тгм етаияиа йатасйеуастг :";cin>>str_factory;
		    cout<<"\n\tакжаяихлгтийос екемвос еисацыцгс дедолемым апо том вягстг"<<endl;
		    for(int i=0; i<strlen(str_factory); i++)
			    {
			   	 str_factory[i]=(toupper(str_factory[i])); 
				}
				
		
		   
		    chk_return=chekInputDataStruct(str_factory); 
		    while(chk_return==0 || strlen(str_factory)>15)
		      {
		       if(strlen(str_factory)>15)
			     cout<<"\tевеис непеяасеи том лецисто аяихло цяаллатым (лав 15)"<<endl;
			   else if(chk_return==0 )	 	
			     cerr<<"\tEROOR  кахос еисацыцг дедолемым (епитяепомтаи ломо цяаллата)\n";
			    
			   cout<<"\n\tдысе тгм етаияиа йатасйеуастг :";cin>>str_factory;
			   chk_return=chekInputDataStruct(str_factory); 
			  }
			  string new_factory; 
			  for(int i=0; i<strlen(str_factory); i++)
			    {
			   	 new_factory+=(toupper(str_factory[i])); 
				}
		      cout<<"\t>епитувгс йатвыяHсг етаияиас йатасйеуастг :"<<new_factory<<endl;
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
				    cout<<"\n\tепитувгс меа ецяажг аутойимгтоу :\n"<<endl;   
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
			 cout<<"\t\t      епикенате  ****  диацяажг\n\n";
		     cout<<"\t\t        ( ** SYSTEM READY ** )    \n";        
		     cout<<"\t\t      __________________________\n\n";	            
		     cout<<"\t\t          ( басг дедолемым )    \n\n";           
	         cout<<"\t\t     **  D. A. T. A.    C A R S  **  \n\n"; 
	         sleep(1);       
		     cout<<"\t\t\n";
		     for(int i=0; i<matrIX->getm_size(); i++)
			      {
			       arrayCAR[i].printCars(i);
			      }
	         
	         cout<<"\n\t* епикоцг аутойимгтоу поу ха диацяажеи"<<endl;
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
			       }
			  }while(flag==1);
		     cout<<"\n\t>епитувгс еуяесг пимайидас пяовыяисте стгм диацяажг тгс :"<<del_pinakida<<endl; 
		 	 cout<<"\t => епикенате диацяажг тоу паяайатоу аутойимгтоу : (ЕъСАСТЕ СъЦОУЯОР?)\n"<<endl;
		 	 char del_car;
			  getchar(); 
		     cout<<"\t  => патгсте то пкгйтяо 'Y' циа ма пяовыягсEI г диацяажг г опоиодгпоте акко пкгйтяо циа айуяысг:";cin>>del_car;
		     
		     if(del_car=='Y')
		       {
		       	buff.setPinakida(NULL);
		       	buff.setColorize(" ");
		       	buff.setYear_Constrc(NULL);
		       	buff.setBrand(" ");
			    
			    for( i=0; i<matrIX->getm_size(); i++)
	               {
	       	        if(inpUT_i==i)
					  {
					   arrayCAR[i]=buff;
					   cout<<"\n\tепикенате диацяажг тоу паяайатоу аутойимгтоу: \n"<<endl;
					   arrayCAR[i].printCars(i);
					   flag=0;
					    break;
					  }
			        }
			    cout<<"\n\tаккацг дедолемым сто пяоцяалла пяос епенеяцасиа ...\n"<<endl;     
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
			    cout<<"\t  циа епистяожг сто лемоу пата Oпоиодгпоте пкгйтяо:\n"<<endl;	
		        system("PAUSE");
			   }
	         flag=true;
       		}
   		else if(basic_menu==4)
	  		{	
	            cout<<"EISODOS SE 4"<<endl;         //сумаят/амамеысг
	            system("PAUSE");
	   		} 
   		else if(basic_menu==5)
	  		{
			 system_ready();                //сумаят/еFE SYSTEM READY	
             do
               {
			    cout<<"\n\n\tапохгйеусг дедолемым сто пяоцяалла пяос епенеяцасиа ...\n"<<endl; 		
				for(int i=0; i<matrIX->getm_size(); i++)
			      {
			       arrayCAR[i].printCars(i);
			      }
			      
	    int anazitisi;  
		      				
                anazitisi=menu_anazitisis_s(anazitisi);    //сумаят/ лемоу амафгтгсгс      				 		 			     			 			          	            
				if(anazitisi==1) 
				  {
				  	
			int find_pinakida;
				  	 cout<<"\n\tая.пимайидым поу упаявоум еидг сто сустгла : "<<endl;
					 int cnt=7;
				     for(int i=0; i<(*matrIX).getm_size(); i++)
				       {
				       	if(arrayCAR[i].getPinakida()==0 && i!=cnt)
				       	  {
				       	    arrayCAR[i].setBrand("  ////");
			               	cout<<arrayCAR[i].getBrand();
						  }
				       	else
						  {
						   cout<<"\t"<<arrayCAR[i].getPinakida()<<"  ";
					      }
				       	if(i==cnt)
				       	  {
				       	   cout<<"\n";
				           cnt+=8; 	
						  } 
					    }
					  cout<<endl;
					  cout<<"\n\tдысе пимайида аутойимHтоу: ";cin>>find_pinakida;
					  cout<<endl;
					  for(int i=0; i<matrIX->getm_size(); i++)
			            {
			             
			             if(arrayCAR[i].getPinakida()==find_pinakida )
			               {
			               	arrayCAR[i].printCars(i);
						   }
						 else if(i==matrIX->getm_size() && arrayCAR[i].getPinakida()!=find_pinakida)
						    {
						     cout<<"\tдем упаявеи йатавыяглемг аутг г пимайида "<<endl;
						      break;
							}
			             }
					  cout<<endl;	
					  cout<<"\t*епистяожг сто лемоу амафгтгсгс*  \n\n"<<endl;
					  getchar();  
			   	     } 
						 
			
				     
				else if(anazitisi==2) 
					 {
					 	
			string find_color;	
			 	
					  cout<<endl;
					  cout<<"\tдысе вяыла аутойимHтоу: ";cin>>find_color;
					  cout<<endl;
					  for(int i=0; i<matrIX->getm_size(); i++)
			            {
			            
			             if(arrayCAR[i].getColorize()==find_color )
			               {
			               	arrayCAR[i].printCars(i);
			               	flag=true;
						   }
			             }
					  cout<<endl;
					  cout<<"\t*епистяожг сто лемоу амафгтгсгс*  \n\n"<<endl;
					  getchar(); 		    
					  }
					  
				else if(anazitisi==3) 
					  {
					  	
			string find_factory;
					  	
					    cout<<endl;
					    cout<<"\tдысе лаяйа аутойимHтоу: ";cin>>find_factory;
					    cout<<endl;
					    for(int i=0; i<matrIX->getm_size(); i++)
			              {
			             
			               if(arrayCAR[i].getBrand()==find_factory )
			                 {
			                  arrayCAR[i].printCars(i);
						    }
						   
			               }
					    cout<<endl;
					    cout<<"\t*епистяожг сто лемоу амафгтгсгс*  \n\n"<<endl;
					    getchar();
					   }	
				else if(anazitisi==4) 
					   {
					   	
			int find_year;
					   	
					   	cout<<endl;
					    cout<<"\tдысе вяомокоциа аутойимHтоу: ";cin>>find_year;
					    cout<<endl;
					    int i;
					    for(i=0; i<matrIX->getm_size(); i++)
			              {
			               if(arrayCAR[i].getYear_Constrc()==find_year )
			                 {
			               	  arrayCAR[i].printCars(i);
			               	
						     }
						  else if(i==matrIX->getm_size() && arrayCAR[i].getYear_Constrc()!=find_year )
						    {
						     cout<<"дем бяехгйе \n";
							}
						   }
					    cout<<endl;
					    cout<<"\t*епистяожг сто лемоу амафгтгсгс*  \n\n"<<endl;
					    getchar();	
					   }
				else if(anazitisi==0) 
					   {
					   	cout<<endl;	 
					    cout<<"\t\t*епистяожг сто басийо лемоу*  \n\n"<<endl;
					    sleep(2); 
			   	         break;                	
					    }
					  flag=1;
					  system("PAUSE"); 
			   	      system("CLS");		
			    }while(flag==1 );
			       	   
				   
				system("PAUSE"); 
       		   }		
   		else if(basic_menu==6)
	  		{
	            cout<<"EISODOS SE 6"<<endl;       	//сумаят/UPDATE
	            Datacars bufferCars_array[matrIX->getm_size()];              //BUFFER MATRIX GIA  APOTHIKEYSH MATRIX STRUCT
			 
	    	    copyTextDataToArray("Cars.txt",bufferCars_array,matrIX->getm_size());     //диабафеи та дедолема сто аявеио стгм C
	            Datacars bufCars_array[matrIX->getm_size()+1];
	            printData(bufferCars_array,matrIX->getm_size());
	            
	            for(int i=0; i<matrIX->getm_size(); i++)
			      {
			   	    bufCars_array[i].pinakida_info=arrayCAR[i].getPinakida();
			   	    bufCars_array[i].year_info=arrayCAR[i].getYear_Constrc();
				    strcpy(bufCars_array[i].colors,arrayCAR[i].getColorize().c_str());
				    strcpy(bufCars_array[i].companies,arrayCAR[i].getBrand().c_str());
				     
			      }
			    cout<<"\n\tмеа ейтупысг леса стгм C ME NA KATAXVRHSH\n\n"<<endl;
		        printData(bufCars_array,matrIX->getm_size());
		        cars_UPDATE("update.txt",bufCars_array, matrIX->getm_size());    
			    for(int i=0; i<matrIX->getm_size(); i++)
			      {
			       arrayCAR[i].printCars(i);
			      }
	              system("PAUSE");
       		  }       
   		else if(basic_menu==0)
	  		{
	            goodbaye();        	               //сумаят/енодос 
	            flag=false;
       		}   
        
   	   	//system("CLS");
			  	 
      }while((reload_menu>=0 || reload_menu<=6) && flag==true);
      
    //delete []	matrIX;  
    //delete [] arrayCAR;
   
	 
	return 0;
}





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
	cout<<"  Id ("<<inp_i<<")"<<"\tая.йуйк   "<<getPinakida()<<"   "
	    <<"\tвяыла   "<<getColorize()<<"     "<<"\tвяомокоциа  "<<getYear_Constrc()<<"    "
		<<"    йатасйеуастгс   "<<getBrand()<<endl;
		
}







void inptData_C(Datacars *bufferCars_array,int sz_of_Lines)            //пяосыяимг апохгйеусг DATA_FILE апо C_FILE
{
	
    copyTextDataToArray("Cars.txt",bufferCars_array,sz_of_Lines);     //диабафеи та дедолема сто аявеио стгм C
			
	cout<<"\n\tапохгйеусг дедолемым сто пяоцяалла пяос епенеяцасиа ..."<<endl; 
	//cout<<endl;
	/*for(int i =0 ;  i<sz_of_Lines-1 ; i++)
	   {
	   	//sleep(1);	
	   	cout<<"  Id ("<<i<<")"<<"\tая.йуйк   "<<bufferCars_array[i].pinakida_info
		    <<"\tвяыла   "<<bufferCars_array[i].colors<<"\tвяомокоциа  "
		    <<bufferCars_array[i].year_info
		    <<"    йатасйеуастгс   "<<bufferCars_array[i].companies<<endl;
	   }
	cout<<"\t  циа епистяожг сто лемоу пата Oпоиодгпоте пкгйтяо:\n\n"<<endl;	
	system("PAUSE");*/	   	
}


int checkPointPinakida()
{   
    char str_pinakida[10];
    
    cout<<"\tдысе аяихло пимайидас :";cin>>str_pinakida;
 	cout<<"\n\tакжаяихлгтийос екемвос еисацыцгс дедолемым апо том вягстг"<<endl;
	int new_pinakida;
	new_pinakida=AfterCheckBasicMenu(str_pinakida);
	while(new_pinakida<1000 || new_pinakida >MAX_NCAR )
	  {
	   cerr<<"\tEROOR  кахос еисацыцг дедолемым (епитяеполемес тилес 1000-"<<MAX_NCAR<<")\n";
	   cout<<"\tдысе аяихло пимайидас :";cin>>str_pinakida;
	   new_pinakida=AfterCheckBasicMenu(str_pinakida);
	  }
	
	return new_pinakida;		    
}


int checkPointYear()
{   
    char str_year[5];
    
    cout<<"\tдысе етос йатасйеугс :";cin>>str_year;
 	cout<<"\n\tакжаяихлгтийос екемвос еисацыцгс дедолемым апо том вягстг"<<endl;
	int new_year;
	new_year=AfterCheckBasicMenu(str_year);
	while(new_year==-1 || new_year < MIN_NOFYEAR  || new_year>MAX_NOFYEAR )
	  {
	   cerr<<"\tEROOR  кахос еисацыцг дедолемым (епитяеполемес тилес "<<MIN_NOFYEAR<<"-"<<MAX_NOFYEAR<<")\n";
	   cout<<"\tдысе етос йатасйеугс :";cin>>str_year;
	   new_year=AfterCheckBasicMenu(str_year);
	  }
	
	return new_year;		    
}
