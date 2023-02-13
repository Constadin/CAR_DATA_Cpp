//c file.h

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h> 
#include <ctype.h>   
#include <string.h> //ЦИА strcmp


#define MEASURER_GRAF 4
#define SIZE_SYSTEM_READY 1
#define SIZE_OF_STRING 5000
#define PASSWKEY_1 "LORD"     //KODIKOS GIA EISAGOGH PROGRAMMATOS


typedef struct
{	
	char companies[SIZE_OF_STRING];  //STRING
	char colors[SIZE_OF_STRING];    //STRING
	int year_info;                 //INTIGER  
	int pinakida_info;            //INTIGER
	
}Datacars;



void pass_word_s(char* argv[]); 
int vasiko_menu(char *msg);     //сумаят/еисодос сто басийо лемоу  
void measureeGraf();          //grafiko 
int AfterCheckBasicMenu(char *input_str_num) ;   //екемвос циа пкгйтокоцисг ломо аяихлым сто басийо лемоу
int chekInputDataStruct(char* input_str);       //екемвос циа пкгйтокоцгсг ломо цяаллатым
void system_ready();        //сумаят/еFE SYSTEM READY
void updateSystem();       //сумаят/еFE update 
int menu1(char *filename,Datacars *car_strt,int *sz_of_Lines);   //сумаят/елжамисг окым //лемоу 1
void swapTwo(Datacars *x, Datacars *y);
void quickSort(Datacars *matrix,const int first_id,const int last_id);
int cars_s(char *filename, Datacars *matrix, int Lines);     //сумая/аутойимHTA елжамифеи та дедолема ажоу диабасеи стгм охомг
void cars_UPDATE(char *filename, Datacars *matrix, int lines);    //сумая/аутойимHTA update
int countLinesOfTextFile(char *filename);        //летяаеи тис цяаллес сто аявеио
void copyTextDataToArray(char *filename, Datacars *matrix, int lines);    //диабафеи та дедолема сто аявеио
void printData(Datacars *matrix, int size);   //елжамифеи стгм охомг та дедолема аявеиоу 
void colors_car(char*filename,Datacars* matrix,int *lines);      //диабасла аявеиоу елжамисг вяылатым
void companies_s(char *filename, Datacars *matrix,int *lines);   //сумаят/ елжамисг йатасйеуастым     
int menu_anazitisis_s(char *anazitisi);     //сумаят/ лемоу амафгтгсгс
int goodbaye();	  //EXODOS GRAFIKA


 
void pass_word_s(char* argv[])    //сумаят/еисодос сто пяоцяалла /PASS//екемвос ле йыдийо еисодоу
{   
    system("CHCP 1253>NULL");
    
	
	
    const char pass_Admin[SIZE_OF_STRING]=PASSWKEY_1;    //йыдийос еисодоу	
	char user_pass[SIZE_OF_STRING];                     //апохгйеусг тилгс сумаятгсгс екевоу PASS
	int  check_pass;       //апохгйеусг тилгс strcmp еисодоу
	int flag=1;           // летягтгс /flag екемвоу
	int tries=0;
 
  do
   {  	 		 
		printf("\n\n\n"); 
		printf("\t\t\t D. A. T. A.   C A R S             by Nick Kwnstantinidis %c 2023\n",169);	
		printf("\t\t\t***********************\n");
		printf("\t\t\t   * W E L C O M E * \n\n");      	//ЛЩМГЛА ОМОЛАСъАs ЕТАИЯъАs  ЙАИ ЙАКОСЫЯъСЛАТОs  		   
		printf("\t\t\tPASSWORD :");  		
		gets(user_pass);                               	  //ЕИСАЦЫЦч pass апо том вягстг//
		//strcpy(user_pass,argv[1]);
	 	printf("\n"); 
 	 	printf("\t\t\tпкгйтяокоцгсате \"%s\" циметаи екемвос йыдийоу...\n\n",user_pass); 	
   
     	check_pass=strcmp(pass_Admin,user_pass);  //екемвос йыдийоу еидодоу strcmp 
		                                  	
     	measureeGraf();
     	
   	 	sleep(2);  	    	
   	if(check_pass!=0)
   	 	{  
	     	flag=0;
   	     	printf("\t\t\tпяосбасг адуматг о йыдийос сас еимаи кахос\n");
	 	 	sleep(2);
	
   	  	if(check_pass!=0 && tries==1)
   	   		{   	  
	     	  	printf("\t\t\tевете айола 1 пяоспахеиа лета ха пяацлатопоигхеи енодос\n");	
		 		sleep(2);	 	
	    	}	  
      	else if(check_pass!=0 && tries==2)
   	    	{   	  
	      		printf("\t\t\tпяацлатопоигте енодос апо то пяоцяалла\n");	     
	      		sleep(2);
	      		exit(1);	 	
	    	}   	  
	  	}
	  	  
   	if(check_pass==0)        	//ЕэМ ПКГЙТОКОЦчСЕИ О ВЯчСТГР ТО СЫСТЭ pass ЛПАъМЕИ СЕ АУТч ТГМ СУМХчЙГ
	 	{  	  
	   		printf("\t\t\tепитувгс еисодос сто пяоцяалла \n");
	   		flag=1;        
	   		sleep(2);	
	  	}    
	   tries++;  	 	    	//летяитгс кахос пяоспахеиас	  
	   system("CLS");	   	
	}while(flag==0);

}



int vasiko_menu(char *msg)     //сумаят/еисодос сто басийо лемоу  
  {  	
       int i;
	   char number_menu[SIZE_OF_STRING];
	   int num_menu;  	
	   int flag=1; 
	   int count=0;	
	   
	   system("CLS");
    do{  
  	     printf("\n\n\n");	   
	     printf("\t\t        D. A. T. A.   C A R S \n");	
	     printf("\t\t       ***********************\n");
	     sleep(1);
         printf("\t\t\t    басийо лемоу\n");
		 printf("\t\t\t_____________________ \n\n");
		 printf("\t\t\t[1] елжамисг окым-сумдесг ле тгм басг\n");
		 printf("\t\t\t[2] еисацыцг меас еццяажгс\n");
		 printf("\t\t\t[3] диацяажг еццяажгс\n");
		 printf("\t\t\t[4] амамеысг еццяажгс (ПЕЯИщВЕИ УПОЛЕМОЩ)\n");
		 printf("\t\t\t[5] амафгтгсг (ПЕЯИщВЕИ УПОЛЕМОЩ)\n");
		 printf("\t\t\t[6] емглеяысг басгс\n");
		 printf("\t\t\t[0] енодос\n\n");
		 sleep(1);
		 printf("\t                **********************    \n");
		 printf("\t               ************************   \n");
		 printf("\t             ****          *************  \n");
		 printf("\t      ()*********----------************** \n");
		 printf("\t      ***********************************      @\n");
		 printf("\t      *****  *  *****************  *  ***    @@@           D. A. T. A.  C A R S %c \n",169);
		 printf("\t      ****  ***  ***************  *** ***==@@              we are professionals   \n");
		 printf("\t             *                     *      \n");
		 printf("\t    --------------------------------------------\n");
		 sleep(1);
		 printf("\n\t\t        ** SYSTEM READY **\n\n\n");
	     printf(" *пяосовг:ЛЕТэ АПЭ ЙэХЕ ЕМщЯЦЕИА (еисацыцг,диацяажг,амамеысг) \n ТГР БэСГР ДЕДОЛщМЫМ Г АПОХчЙЕУСГ ЦъМЕТАИ ПАТЧМТАР ТО (6) \n АККИЧР ВэМЕТАИ Г ЭПОИА АККАЦч!!! \n\n\a");
	 
	 	 flag=1;		  
	     printf("%s", msg);	     
		 scanf("%s",number_menu);
		 
		 num_menu=AfterCheckBasicMenu(number_menu);      //сумаятгсг еисодоу аяихлоу лета апо екемво
		  
	if (num_menu<0 || num_menu>6)
		   {
	        count++;
		    flag=0;   
		    printf("\t ***пяосовг пкгйтокоцисте аяихло апо то о-6***\n");
			printf("\t     евете бакеи (%d) жояес кахос аяихло  \n\n",count);	
			
		  if (count==3)
			{
			 printf("\t        теялатислос пяоцяаллатос  \n\n");			
			 exit (1);
			}	      	             		     
           }
           
	    else if (num_menu>=0  ||  num_menu<=6)
	       {
		     flag=1;	       		 
		   	   break;
	        }
	      sleep(4);
		  system("CLS");					      	        
	     }while(flag==0);
	     
		return num_menu;          //епистяожг имт стгм MAIN циа еисодо сто лемоу
}


void measureeGraf()    //grafiko 
{
 system("CHCP 850>NULL"); 
 int m=1; 
  
 do{
	printf("\n\t     CODE CHECK ");
	printf("%c",176);
	for(int i=0; i<MEASURER_GRAF; i++)
	   {
		printf("%c",205);
		sleep(1);
		printf("%c", 205);
	   }
		printf("%c",176);
		printf(" loaded", 205);
		m--;
		printf("\n");
	}while(m>0);
	
  printf("\n\n");
  system("CHCP 1253>NULL");
}



int AfterCheckBasicMenu(char *input_str_num)      //екемвос циа пкгйтокоцисг ломо аяихлым сто басийо лемоу
{    
    int flag=1;
	int result_isdigit,i,arith;
      
   do
     {
	    flag=1;
	    
  	  for( i=0; i<strlen(input_str_num); i++)
	    { 
	   
	       result_isdigit=isdigit(input_str_num[i]);
	   
		if(result_isdigit==0 )
		   {		  
			  flag=0;
		     // printf("\t(%d)екемвос check isdigit ебакес цяаллата г сулбоко \n",i);
	 	      return -1;     //епистежеи аямгтийо аяихло циа ма лпеи стгм сумхгйг епамакгьгс
	        }
		else
		    {		
			  flag =1;
	         // printf("\t(%d)екемвос checkInputNum isdigit ебакес аяихло \n",i);
			  arith = atoi(input_str_num)	; //ОПЭТЕ ЛЕТАТЯщПОУЛЕ ТО string СЕ АЯИХЛЭ      
	        }					  	        
	    }
	      
    }while(flag==0);     //╪СО Г flag ПАЯАЛщМЕИ false ТО ПЯЭЦЯАЛЛА ХА ФГТэЕИ ЕЙ МщОУ АЯИХЛЭ
                        //лЭКИР БЦЕИ АПЭ ТГ while СъЦОУЯА ХА щВЕИ ПэЯЕИ АЯИХЛОЩР СЕ ЭКО ТО string,
    return arith;      //ОПЭТЕ ЛЕТАТЯщПОУЛЕ ТО string СЕ АЯИХЛЭ
}



int chekInputDataStruct(char* input_str)  //екемвос циа пкгйтокоцгсг ломо цяаллатым
{
    int result_isalpha_str,flag=1;
   
    for(int i=0; i<strlen(input_str); i++)
       {
	    flag=1;
	  
	    result_isalpha_str=isalpha(input_str[i]);
             
      if(result_isalpha_str== 0 )
	    {  
	     flag =0;		 
		 break;   
	    }
	  else 
	     {	  	 
          // printf("\t(%d)екемвос chekInputDataStruct isalpha ебакес цяаллата \n",i);
	     }		  
       }		 	
       return result_isalpha_str;    
}



void system_ready()     //сумаят/еFE SYSTEM READY
 {  
    int i;
    for(i=0; i<SIZE_SYSTEM_READY; i++)
	 {
	  system("CLS");			    		    
      printf("\n\n\n\t\t\t( ** SYSTEM READY ** )    \n");
	  sleep(1);			    
	  system("CLS");
	  printf("\n\n\n\t\t\t( **              ** )    \n");
	  sleep(1);			  
	  system("CLS");					 	
	  printf("\n\n\n\t\t\t( ** SYSTEM READY ** )    \n");
	  sleep(1);			    
	  system("CLS");
	  printf("\n\n\n\t\t\t( **              ** )    \n");
	  sleep(1);			  
	  system("CLS");	 
	  printf("\n\n\n\t\t\t( ** SYSTEM READY ** )    \n");
	  sleep(1);				 
	  system("CLS");	 						 				 				 	
	  }
} 



void updateSystem()    //сумаят/еFE SYSTEM update
 {  
    int i;
    for(i=0; i<SIZE_SYSTEM_READY; i++)
	 {
	  system("CLS");			    		    
      printf("\n\n\n\t\t\t( ** UPDATE SYSTEM ** )    \n");
	  sleep(1);			    
	  system("CLS");
	  printf("\n\n\n\t\t\t( **               ** )    \n");
	  sleep(1);			  
	  system("CLS");					 	
	  printf("\n\n\n\t\t\t( ** UPDATE SYSTEM ** )    \n");
	  sleep(1);			    
	  system("CLS");
	  printf("\n\n\n\t\t\t( **               ** )    \n");
	  sleep(1);			  
	  system("CLS");	 
	  printf("\n\n\n\t\t\t( ** UPDATE SYSTEM ** )    \n");
	  sleep(1);				 
	  system("CLS");	 						 				 				 	
	  }
} 




int menu1(char *filename,Datacars *car_strt,int *sz_of_Lines)   //сумаят/елжамисг окым //лемоу 1
{
	int flag_car_s=1;
	
	    system("CLS");
        *sz_of_Lines= countLinesOfTextFile(filename);    //летяаеи то пкухос тым цяалллым стом аявеио
        //printf("\n\n\t\t   > екемвос аявеиоу: евеи %d еццяажес (цяаллес)\n\n",*sz_of_Lines-1); 
		 
	    car_strt = (Datacars *)malloc(*sz_of_Lines* sizeof(Datacars));   //дглиOуяцеиа пимайа ле пкHхос цяаллым аявеиоу
	    if (car_strt == NULL || *sz_of_Lines==0) 
	      { 
            printf("Memory not allocated.\n"); 
            exit(1); 
           }
	    copyTextDataToArray(filename,car_strt,*sz_of_Lines); //диабафеи та дедолема сто аявеио
        //printData(car_strt,*sz_of_Lines); //ейтупысг FILE CARS.TXT
        for(int i=0; i<2; i++)
           {
	           	printf("\n\n\tconnecting C++ with C_file.h...\n");
	           	sleep(2);
	           	system("CLS");
	           	sleep(1);
		   }
	    printf("\n\n\t\t   > епитувгс екемвос аявеиоу: евеи %d еццяажес & %d LINES \n\n",
		         *sz_of_Lines-2,*sz_of_Lines-1); 
	    sleep(3);
	    system("CLS");
	    system_ready(); 
	     
		printf("\n\n\n");   
	 	printf("\t\t     епикенате **** елжамисг окым\n\n");
	    printf("\t\t        ( ** SYSTEM READY ** )    \n");        
	    printf("\t\t      __________________________\n\n");	            
	    printf("\t\t          ( басг дедолемым )    \n\n");           
        printf("\t\t    **  D. A. T. A.    C A R S  **  \n\n"); 
        sleep(1);       

	    printf(" ****| аяихлос | *** |  вяыла  | *** | йатасйеуастгс | *** | вяомокоциа |**** \n\n");
		    	            
	    flag_car_s=cars_s(filename,car_strt,*sz_of_Lines);    //сумая/аутойимHTA елжамифеи та дедолема ажоу диабасеи стгм охомг 
	    
	    free(car_strt); 
		flag_car_s=0;                         
		printf("\n");
        if(flag_car_s==1) 
           return 1;
        else
          return flag_car_s=0;
}


void swapTwo(Datacars *x, Datacars *y)
{
	Datacars  temp= *x;
	
	*x=*y;
	*y= temp;
}



void quickSort(Datacars *matrix,const int first_id,const int last_id)
{
	int pivot,i,j;
	
	if(first_id<last_id  )
	 {
	 	pivot=first_id;
	 	i=first_id;
	 	j=last_id;
	 	
	  while(i<j)	
	    {	  
	 	 while(matrix[i].pinakida_info <= matrix[pivot].pinakida_info && i<last_id)
	 	    i++;
	 	
	      while(matrix[j].pinakida_info>matrix[pivot].pinakida_info)
	        j--;
	      
	      if(i<j)
		    swapTwo(&matrix[i],&matrix[j]);
        }
         swapTwo(&matrix[pivot],&matrix[j]);
	     quickSort (matrix,first_id,j-1);
	     quickSort(matrix,j+1,last_id);
     }
     
}


int cars_s(char *filename, Datacars *matrix, int lines)    //сумая/аутойимHTA елжамифеи та дедолема ажоу диабасеи стгм охомг
{ 
	FILE *file;
	
	file = fopen(filename, "r");
	
    for(int i=0; i<lines; i++)
		fscanf(file,"\t%4d    \t%5s     \t%10s     \t%12d\n", &matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,&matrix[i].year_info);
	
	for(int i=0; i<lines-1; i++)
		printf("\t%4d    \t%5s     \t%10s     \t%12d\n",matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,matrix[i].year_info);	
	printf("\n\n\t\t    ** file was read successfully **  \n");
	fclose(file);
	
	if(!fclose(file))
	  {
	   return 1;	
	  }
	else
	   return 0;
} 



void cars_UPDATE(char *filename, Datacars *matrix, int lines)    //сумая/аутойимHTA елжамифеи та дедолема ажоу диабасеи стгм охомг
{ 
   
    quickSort(matrix,0,lines-1);
    
	FILE *file;
	//printf("LINES....%d\n",lines);
	file = fopen(filename, "w");
	
	 
    for(int i=0; i<lines; i++)
       {
        if(matrix[i].pinakida_info!=0)
		  fprintf(file,"\t%4d    \t%5s     \t%10s     \t%12d\n", matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,matrix[i].year_info); 	
		}
		
	for(int i=0; i<lines; i++)
	    printf("\t%8d   \t%10s     \t%10s     \t%8d\n",matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,matrix[i].year_info);	
	
	fclose(file);

} 



int countLinesOfTextFile(char *filename)       //летяаеи тис цяаллес сто аявеио
{
	FILE *file;
	int lines;
	
	file = fopen(filename, "r");
	
	if(file==NULL) //!file1
	  {
		printf("File not available...!\n\a");
		printf("дем деслеутийе выяос лмглгс\n");
		exit(1);
	  }
	
	else
	  {
		lines=0;
		do
		  {
			if(fgetc(file) == '\n')
				lines++;
		  }while(!feof(file));
	   }
	fclose(file);
	
	return lines+1; //вяеиафетаи +1╢╢
}



void copyTextDataToArray(char *filename, Datacars *matrix, int lines)    //диабафеи та дедолема сто аявеио
{
	FILE *file;
	
	file = fopen(filename, "r");
	
	   for(int i=0; i<lines; i++)
	   	   fscanf(file, "%d	%s	%s	%d", &matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,&matrix[i].year_info);
	   	   
	fclose(file);
}



void printData(Datacars *matrix, int size)   //елжамифеи стгм охомг та дедолема аявеиоу 
{
	printf("\t\t\t     ** READ DаTA FILE CARS **\n\n");
	for(int i=0; i<size; i++)
		printf("  (%d--line)\t%10d     \t%15s     \t%15s     \t%10d\n",i, matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,matrix[i].year_info);
	//printf("\n\t\t  пата ENTER циа елжамисг аутойимгтым стгм басг дедолемым (FILE)\n\n");    
	system("PAUSE");
}



void colors_car(char*filename,Datacars* matrix,int *lines)      //сумаят/вяылата аутойимитым
{
    FILE *file;
    
	*lines= countLinesOfTextFile(filename);   //летяаеи то пкухос тым цяалллым стом аявеио
    printf("\n\t\t   > екемвос аявеиоу: евеи %d йатавыяилема вяылата :\n\n",*lines);  
	matrix= (Datacars *)malloc(*lines*sizeof(Datacars)); //дглиOуяцеиа пимайа ле пкHхос цяаллым аявеиоу
    if (matrix == NULL || *lines==0) 
	  { 
       printf("Memory not allocated.\n"); 
          exit(1); 
      }
	
	file = fopen(filename, "r");
	
	for(int i=0; i<*lines; i++)
		fscanf(file, "%s",matrix[i].colors);//
	
	for(int i=0; i<*lines; i++)
		printf("\t\t\t%s\n",matrix[i].colors);	
	
	fclose(file);
	free(matrix);	
}

  
   
void companies_s(char *filename, Datacars *matrix,int *lines)     //сумаят/ елжамисг йатасйеуастым                                                  
{ 
    
	FILE *file;
    
	*lines= countLinesOfTextFile(filename);    //летяаеи то пкухос тым цяалллым стом аявеио
    printf("\n\t\t   > екемвос аявеиоу: евеи %d йатавыяилемоус йатасйеуастес :\n\n",*lines);  
	matrix= (Datacars *)malloc(*lines*sizeof(Datacars));   //дглиOуяцеиа пимайа ле пкHхос цяаллым аявеиоу
    if (matrix == NULL || *lines==0) 
	  { 
       printf("Memory not allocated.\n"); 
          exit(1); 
      }
	
	file = fopen(filename, "r");
	
	for(int i=0; i<*lines; i++)
		fscanf(file, "%s",matrix[i].colors);//
	
	for(int i=0; i<*lines; i++)
		printf("\t\t\t%s\n",matrix[i].colors);	
	
	fclose(file);
	free(matrix);
}




int menu_anazitisis_s(char *anazitisi)      //сумаят/ лемоу амафгтгсгс
{  
   int anazitisi_s;
   do
	{		
     printf("\n\n\n");  			 
	 printf("\t\t  епикенате ***** амафгтгсг \n");
	 printf("\t\t ___________________________\n\n");
	 printf("\t\t   ( ** SYSTEM READY ** )    \n\n");
	 printf("\t\t\n");
	 printf("\t\t      лемоу амафгтгсгс  \n");
	 printf("\t\t __________________________\n\n");
	 printf("\t\t [1] амафгтгсг пимайидас\n");
	 printf("\t\t [2] амафгтгсг вяылатос\n");						        
	 printf("\t\t [3] амафгтгсг лаяйас\n");	       
	 printf("\t\t [4] амафгтгсг вяомокоциас\n");
	 printf("\t\t [0] епистожг сто басийо лемоу\n");
	 printf("\t\t ___________________________\n\n");         
	 printf(" амафгтгсте ч епистяеьте сто басийо лемоу:\n");
       						    			 	      
	 printf(" епикоцг лемоу :");
	 scanf("%s",anazitisi);	
	 
		 anazitisi_s=AfterCheckBasicMenu(anazitisi);      //сумаятгсг еисодоу аяихлоу лета апо екемво
    if ((anazitisi_s<0)||(anazitisi_s>4))
	   {
		   printf("\n");   
		   printf("**пяосовг пкгйтокоцисте аяихло апо то о-4**\n");	   			  	      	             		     
       }
	else if ((anazitisi_s>=0) && (anazitisi_s<=4))
	   {
		   return anazitisi_s;
	   }
	  sleep(2); 
   	  system("CLS"); 	
	 }while((anazitisi_s<0)||(anazitisi_s>4));
}




int goodbaye()	
{
    char yes_exit;
	int  update_base=0;
	int efe_car=0; 
	int good_baye =0;
	char return_num;
	char msg[20] ="епикоцг :" ;		
	printf("\n\n"); 		 
	printf("\t\tепикенате **** енодос апо то пяоцяалла \n");
	printf("\t\t          ЕъСАСТЕ СъЦОУЯОР?\n\n"); 
	printf("\t\tпата 'Y' ПКчЙТЯО ЦИА щНОДО - АККИЧР ХА ЕПИСТЯщЬЕИР СТО АЯВИЙЭ ЛЕМОЩ\n\n");
	printf(" епекене..."); 
	scanf("%s",&yes_exit);
	yes_exit=(toupper(yes_exit)); 
        if (yes_exit!='Y')
          {
	        printf("\t\tдем епекенес енодо \n");
	        printf("\t\tциметаи епистожг сто басийо лемоу \n");
	        sleep(3);
	        system("CLS");
			return 1;      	
		  }   
	 else if (yes_exit=='Y')
		  {		    
		   while(efe_car<4)
		     {
		   	    ++efe_car;
				printf("\n\n");
			   	printf("\t\t\t\t\t                                               **********************    \n");
		        printf("\t\t\t\t\t                                              ************************   \n");
		        printf("\t\t\t\t\t                                            *****         *************  \n");
		        printf("\t\t\t\t\t                                     ()*********----------************** \n");
		        printf("\t\t\t\t\t                                     ***********************************      \n");
		        printf("\t\t\t\t\t                                     *****  *  *****************  *  ***                \n");
		        printf("\t\t\t\t\t                                     ****  ***  ***************  *** ***==                \n");
		        printf("\t\t\t\t\t                                            *                     *      \n");
		        printf("\t\t\t\t\t                                  --------------------------------------------\n");
		        usleep(5000000);
				system("CLS");
				printf("\n\n");
			   	printf("\t\t\t\t\t                                               **********************    \n");
		        printf("\t\t\t\t\t                                              ************************   \n");
		        printf("\t\t\t\t\t                                            *****         *************  \n");
		        printf("\t\t\t\t\t                                     ()*********----------************** \n");
		        printf("\t\t\t\t\t                                     ***********************************      \n");
		        printf("\t\t\t\t\t                                     *****  *  *****************  *  ***                \n");
		        printf("\t\t\t\t\t                                     ****  ***  ***************  *** ***==                \n");
		        printf("\t\t\t\t\t                                            *                     *      \n");
		        printf("\t\t\t\t\t                                  --------------------------------------------\n");
		        sleep(1);
				system("CLS");   		   	    
 			   	printf("\n\n");
			   	printf("\t\t\t\t\t                                               **********************    \n");
		        printf("\t\t\t\t\t                                              ************************   \n");
		        printf("\t\t\t\t\t                                            *****         *************  \n");
		        printf("\t\t\t\t\t                                     ()*********----------************** \n");
		        printf("\t\t\t\t\t                                     ***********************************      @\n");
		        printf("\t\t\t\t\t                                     *****  *  *****************  *  ***    @@@            \n");
		        printf("\t\t\t\t\t                                     ****  ***  ***************  *** ***==@@                \n");
		        printf("\t\t\t\t\t                                            *                     *      \n");
		        printf("\t\t\t\t\t                                  --------------------------------------------\n");
		        printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        sleep(1);
	            system("CLS");
				printf("\n\n");  
			   	printf("\t\t\t\t\t                                         **********************    \n");
		        printf("\t\t\t\t\t                                        ************************   \n");
		        printf("\t\t\t\t\t                                      *****         *************  \n");
		        printf("\t\t\t\t\t                               ()*********----------************** \n");
		        printf("\t\t\t\t\t                               ***********************************          @\n");
		        printf("\t\t\t\t\t                               *****  *  *****************  *  ***      @@ @             \n");
		        printf("\t\t\t\t\t                               ****  ***  ***************  *** ***==@@                 \n");
		        printf("\t\t\t\t\t                                      *                     *      \n");
		        printf("\t\t\t\t\t                            ----------------------------------------------------\n");
		        printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(1000000);
		        system("CLS");
				printf("\n\n");
			   	printf("\t\t\t\t\t                                 **********************    \n");
		        printf("\t\t\t\t\t                                ************************   \n");
		        printf("\t\t\t\t\t                              *****         *************  \n");
		        printf("\t\t\t\t\t                       ()*********----------************** \n");
		        printf("\t\t\t\t\t                       ***********************************             @\n");
		        printf("\t\t\t\t\t                       *****  *  *****************  *  ***         @@ @             \n");
		        printf("\t\t\t\t\t                       ****  ***  ***************  *** ***==@   @                 \n");
		        printf("\t\t\t\t\t                              *                     *      \n");
		        printf("\t\t\t\t\t                  ---------------------------------------------------------------\n");
		  //    printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(1000000);
		        system("CLS");
				printf("\n\n");
			   	printf("\t\t\t\t                          **********************    \n");
		        printf("\t\t\t\t                         ************************   \n");
		        printf("\t\t\t\t                       *****         *************  \n");
		        printf("\t\t\t\t                ()*********----------************** \n");
		        printf("\t\t\t\t                ***********************************             @\n");
		        printf("\t\t\t\t                *****  *  *****************  *  ***      @   @  @             \n");
		        printf("\t\t\t\t                ****  ***  ***************  *** ***==@  @                 \n");
		        printf("\t\t\t\t                       *                     *      \n");
		        printf("\t\t\t\t            -----------------------------------------------------------------------\n");
	     //     printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(1000000);
		        system("CLS");
		        printf("\n\n");
			   	printf("\t\t\t                         **********************    \n");
		        printf("\t\t\t                        ************************   \n");
		        printf("\t\t\t                      *****         *************  \n");
		        printf("\t\t\t               ()*********----------************** \n");
		        printf("\t\t\t               ***********************************              @\n");
		        printf("\t\t\t               *****  *  *****************  *  ***         @@  @             \n");
		        printf("\t\t\t               ****  ***  ***************  *** ***== @  @                 \n");
		        printf("\t\t\t                     *                     *      \n");
		        printf("\t\t\t           ---------------------------------------------------------------------------\n");
	      //    printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(9000000);
		        system("CLS");
				printf("\n\n");
			   	printf("        **********************    \n");
		        printf("       ************************   \n");
		        printf("     *****         *************  \n");
		        printf("*********----------************** \n");
		        printf("*********************************            @\n");
		        printf("***  *  *****************  *  ***       @  @  @             \n");
		        printf("**  ***  ***************  *** ***==  @  @                 \n");
		        printf("     *                     *      \n");
		        printf("----------------------------------------------------------------------------------------\n");
		  //    printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(9000000);
		        system("CLS");
				printf("\n\n");
			   	printf("****************    \n");
		        printf("*****************   \n");
		        printf("     *************  \n");
		        printf("-----************** \n");
		        printf("*******************            @\n");
		        printf("***********  *  ***      @  @ @             \n");
		        printf("**********  *** ***==   @@                 \n");
		        printf("             *      \n");
		        printf("----------------------------------------------------------------------------------------\n");
		  //    printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(9000000);
		        system("CLS");
				printf("\n\n");
			   	printf("*******    \n");
		        printf("********   \n");
		        printf("*********  \n");
		        printf("********** \n");
		        printf("**********        @\n");
		        printf("**  *  ***     @     @  @             \n");
		        printf("*  *** ***==@  @                \n");
		        printf("    *      \n");
		        printf("----------------------------------------------------------------------------------------\n");
		  //    printf("\n\t\t\t\t\t\t\t\t\t\t         G O O D B A Y E \n\n\n");
		        usleep(9000000);
		        system("CLS");
			}
	    	while(good_baye<35)
		      {
		   	    ++good_baye;
				//printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");    
                printf("\n\n\n\t\t\t\t\t\t\t          G O O D B A Y E \n\n\n");
		        usleep(1000000);
				system("CLS");	
	           }
	        while(update_base==0)
			  {
				update_base+=1;
				
				 //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");   
				 printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n..                                                                                                                                                                    ..\n ");
				 usleep(1000000);
				 printf("\n\n\n\t\t....                                                                                                                                                           ......\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t...                                                                                                                                                    ..........\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t.......                                                                                                                                          ...............\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t...........                                                                                                                      .........................\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t....................                                                                                        ........................................\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t..............................                                                        .........................................................\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t.................................................            ..............................................................................\n ");
				 usleep(1000000);
				 system("CLS");
				 printf("\n\n\n\t\t...................................................... [0]....................................................................................\n ");
				 usleep(1000000);
				 system("CLS");	
				 printf("\n\n\n\t\t                                                     [ CLOSE ]                                                                                    \n ");
				 sleep(4);
				 system("CLS");				 				 
			   }
			  return 0;    
			}
			
}   
