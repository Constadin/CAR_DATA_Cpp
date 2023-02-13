//c file.h

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <time.h> 
#include <ctype.h>   
#include <string.h> //��� strcmp


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
int vasiko_menu(char *msg);     //������/������� ��� ������ �����  
void measureeGraf();          //grafiko 
int AfterCheckBasicMenu(char *input_str_num) ;   //������� ��� ������������ ���� ������� ��� ������ �����
int chekInputDataStruct(char* input_str);       //������� ��� ������������ ���� ���������
void system_ready();        //������/�FE SYSTEM READY
void updateSystem();       //������/�FE update 
int menu1(char *filename,Datacars *car_strt,int *sz_of_Lines);   //������/�������� ���� //����� 1
void swapTwo(Datacars *x, Datacars *y);
void quickSort(Datacars *matrix,const int first_id,const int last_id);
int cars_s(char *filename, Datacars *matrix, int Lines);     //�����/�������HTA ��������� �� �������� ���� �������� ���� �����
void cars_UPDATE(char *filename, Datacars *matrix, int lines);    //�����/�������HTA update
int countLinesOfTextFile(char *filename);        //������� ��� ������� ��� ������
void copyTextDataToArray(char *filename, Datacars *matrix, int lines);    //�������� �� �������� ��� ������
void printData(Datacars *matrix, int size);   //��������� ���� ����� �� �������� ������� 
void colors_car(char*filename,Datacars* matrix,int *lines);      //�������� ������� �������� ��������
void companies_s(char *filename, Datacars *matrix,int *lines);   //������/ �������� �������������     
int menu_anazitisis_s(char *anazitisi);     //������/ ����� ����������
int goodbaye();	  //EXODOS GRAFIKA


 
void pass_word_s(char* argv[])    //������/������� ��� ��������� /PASS//������� �� ������ �������
{   
    system("CHCP 1253>NULL");
    
	
	
    const char pass_Admin[SIZE_OF_STRING]=PASSWKEY_1;    //������� �������	
	char user_pass[SIZE_OF_STRING];                     //���������� ����� ���������� ������ PASS
	int  check_pass;       //���������� ����� strcmp �������
	int flag=1;           // �������� /flag �������
	int tries=0;
 
  do
   {  	 		 
		printf("\n\n\n"); 
		printf("\t\t\t D. A. T. A.   C A R S             by Nick Kwnstantinidis %c 2023\n",169);	
		printf("\t\t\t***********************\n");
		printf("\t\t\t   * W E L C O M E * \n\n");      	//������ ��������s �������s  ��� �������������s  		   
		printf("\t\t\tPASSWORD :");  		
		gets(user_pass);                               	  //�������� pass ��� ��� ������//
		//strcpy(user_pass,argv[1]);
	 	printf("\n"); 
 	 	printf("\t\t\t��������������� \"%s\" ������� ������� �������...\n\n",user_pass); 	
   
     	check_pass=strcmp(pass_Admin,user_pass);  //������� ������� ������� strcmp 
		                                  	
     	measureeGraf();
     	
   	 	sleep(2);  	    	
   	if(check_pass!=0)
   	 	{  
	     	flag=0;
   	     	printf("\t\t\t�������� ������� � ������� ��� ����� �����\n");
	 	 	sleep(2);
	
   	  	if(check_pass!=0 && tries==1)
   	   		{   	  
	     	  	printf("\t\t\t����� ����� 1 ���������� ���� �� ��������������� ������\n");	
		 		sleep(2);	 	
	    	}	  
      	else if(check_pass!=0 && tries==2)
   	    	{   	  
	      		printf("\t\t\t�������������� ������ ��� �� ���������\n");	     
	      		sleep(2);
	      		exit(1);	 	
	    	}   	  
	  	}
	  	  
   	if(check_pass==0)        	//��� ������������� � ������� �� ����� pass ������� �� ���� ��� �������
	 	{  	  
	   		printf("\t\t\t�������� ������� ��� ��������� \n");
	   		flag=1;        
	   		sleep(2);	
	  	}    
	   tries++;  	 	    	//�������� ����� �����������	  
	   system("CLS");	   	
	}while(flag==0);

}



int vasiko_menu(char *msg)     //������/������� ��� ������ �����  
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
         printf("\t\t\t    ������ �����\n");
		 printf("\t\t\t_____________________ \n\n");
		 printf("\t\t\t[1] �������� ����-������� �� ��� ����\n");
		 printf("\t\t\t[2] �������� ���� ��������\n");
		 printf("\t\t\t[3] �������� ��������\n");
		 printf("\t\t\t[4] �������� �������� (�������� ��������)\n");
		 printf("\t\t\t[5] ��������� (�������� ��������)\n");
		 printf("\t\t\t[6] ��������� �����\n");
		 printf("\t\t\t[0] ������\n\n");
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
	     printf(" *�������:���� ��� ���� �������� (��������,��������,��������) \n ��� ����� ��������� � ���������� ������� �������� �� (6) \n ������ ������� � ����� ������!!! \n\n\a");
	 
	 	 flag=1;		  
	     printf("%s", msg);	     
		 scanf("%s",number_menu);
		 
		 num_menu=AfterCheckBasicMenu(number_menu);      //��������� ������� ������� ���� ��� ������
		  
	if (num_menu<0 || num_menu>6)
		   {
	        count++;
		    flag=0;   
		    printf("\t ***������� ������������� ������ ��� �� �-6***\n");
			printf("\t     ����� ����� (%d) ����� ����� ������  \n\n",count);	
			
		  if (count==3)
			{
			 printf("\t        ����������� ������������  \n\n");			
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
	     
		return num_menu;          //��������� ��� ���� MAIN ��� ������ ��� �����
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



int AfterCheckBasicMenu(char *input_str_num)      //������� ��� ������������ ���� ������� ��� ������ �����
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
		     // printf("\t(%d)������� check isdigit ������ �������� � ������� \n",i);
	 	      return -1;     //��������� �������� ������ ��� �� ���� ���� ������� ����������
	        }
		else
		    {		
			  flag =1;
	         // printf("\t(%d)������� checkInputNum isdigit ������ ������ \n",i);
			  arith = atoi(input_str_num)	; //����� ������������ �� string �� ������      
	        }					  	        
	    }
	      
    }while(flag==0);     //��� � flag ��������� false �� ��������� �� ������ �� ���� ������
                        //����� ���� ��� �� while ������� �� ���� ����� �������� �� ��� �� string,
    return arith;      //����� ������������ �� string �� ������
}



int chekInputDataStruct(char* input_str)  //������� ��� ������������ ���� ���������
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
          // printf("\t(%d)������� chekInputDataStruct isalpha ������ �������� \n",i);
	     }		  
       }		 	
       return result_isalpha_str;    
}



void system_ready()     //������/�FE SYSTEM READY
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



void updateSystem()    //������/�FE SYSTEM update
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




int menu1(char *filename,Datacars *car_strt,int *sz_of_Lines)   //������/�������� ���� //����� 1
{
	int flag_car_s=1;
	
	    system("CLS");
        *sz_of_Lines= countLinesOfTextFile(filename);    //������� �� ������ ��� �������� ���� ������
        //printf("\n\n\t\t   > ������� �������: ���� %d �������� (�������)\n\n",*sz_of_Lines-1); 
		 
	    car_strt = (Datacars *)malloc(*sz_of_Lines* sizeof(Datacars));   //����O������ ������ �� ��H��� ������� �������
	    if (car_strt == NULL || *sz_of_Lines==0) 
	      { 
            printf("Memory not allocated.\n"); 
            exit(1); 
           }
	    copyTextDataToArray(filename,car_strt,*sz_of_Lines); //�������� �� �������� ��� ������
        //printData(car_strt,*sz_of_Lines); //�������� FILE CARS.TXT
        for(int i=0; i<2; i++)
           {
	           	printf("\n\n\tconnecting C++ with C_file.h...\n");
	           	sleep(2);
	           	system("CLS");
	           	sleep(1);
		   }
	    printf("\n\n\t\t   > �������� ������� �������: ���� %d �������� & %d LINES \n\n",
		         *sz_of_Lines-2,*sz_of_Lines-1); 
	    sleep(3);
	    system("CLS");
	    system_ready(); 
	     
		printf("\n\n\n");   
	 	printf("\t\t     ��������� **** �������� ����\n\n");
	    printf("\t\t        ( ** SYSTEM READY ** )    \n");        
	    printf("\t\t      __________________________\n\n");	            
	    printf("\t\t          ( ���� ��������� )    \n\n");           
        printf("\t\t    **  D. A. T. A.    C A R S  **  \n\n"); 
        sleep(1);       

	    printf(" ****| ������� | *** |  �����  | *** | ������������� | *** | ���������� |**** \n\n");
		    	            
	    flag_car_s=cars_s(filename,car_strt,*sz_of_Lines);    //�����/�������HTA ��������� �� �������� ���� �������� ���� ����� 
	    
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


int cars_s(char *filename, Datacars *matrix, int lines)    //�����/�������HTA ��������� �� �������� ���� �������� ���� �����
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



void cars_UPDATE(char *filename, Datacars *matrix, int lines)    //�����/�������HTA ��������� �� �������� ���� �������� ���� �����
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



int countLinesOfTextFile(char *filename)       //������� ��� ������� ��� ������
{
	FILE *file;
	int lines;
	
	file = fopen(filename, "r");
	
	if(file==NULL) //!file1
	  {
		printf("File not available...!\n\a");
		printf("��� ���������� ����� ������\n");
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
	
	return lines+1; //���������� +1��
}



void copyTextDataToArray(char *filename, Datacars *matrix, int lines)    //�������� �� �������� ��� ������
{
	FILE *file;
	
	file = fopen(filename, "r");
	
	   for(int i=0; i<lines; i++)
	   	   fscanf(file, "%d	%s	%s	%d", &matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,&matrix[i].year_info);
	   	   
	fclose(file);
}



void printData(Datacars *matrix, int size)   //��������� ���� ����� �� �������� ������� 
{
	printf("\t\t\t     ** READ D�TA FILE CARS **\n\n");
	for(int i=0; i<size; i++)
		printf("  (%d--line)\t%10d     \t%15s     \t%15s     \t%10d\n",i, matrix[i].pinakida_info,matrix[i].colors,matrix[i].companies,matrix[i].year_info);
	//printf("\n\t\t  ���� ENTER ��� �������� ����������� ���� ���� ��������� (FILE)\n\n");    
	system("PAUSE");
}



void colors_car(char*filename,Datacars* matrix,int *lines)      //������/������� �����������
{
    FILE *file;
    
	*lines= countLinesOfTextFile(filename);   //������� �� ������ ��� �������� ���� ������
    printf("\n\t\t   > ������� �������: ���� %d ������������ ������� :\n\n",*lines);  
	matrix= (Datacars *)malloc(*lines*sizeof(Datacars)); //����O������ ������ �� ��H��� ������� �������
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

  
   
void companies_s(char *filename, Datacars *matrix,int *lines)     //������/ �������� �������������                                                  
{ 
    
	FILE *file;
    
	*lines= countLinesOfTextFile(filename);    //������� �� ������ ��� �������� ���� ������
    printf("\n\t\t   > ������� �������: ���� %d �������������� ������������� :\n\n",*lines);  
	matrix= (Datacars *)malloc(*lines*sizeof(Datacars));   //����O������ ������ �� ��H��� ������� �������
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




int menu_anazitisis_s(char *anazitisi)      //������/ ����� ����������
{  
   int anazitisi_s;
   do
	{		
     printf("\n\n\n");  			 
	 printf("\t\t  ��������� ***** ��������� \n");
	 printf("\t\t ___________________________\n\n");
	 printf("\t\t   ( ** SYSTEM READY ** )    \n\n");
	 printf("\t\t\n");
	 printf("\t\t      ����� ����������  \n");
	 printf("\t\t __________________________\n\n");
	 printf("\t\t [1] ��������� ���������\n");
	 printf("\t\t [2] ��������� ��������\n");						        
	 printf("\t\t [3] ��������� ������\n");	       
	 printf("\t\t [4] ��������� �����������\n");
	 printf("\t\t [0] �������� ��� ������ �����\n");
	 printf("\t\t ___________________________\n\n");         
	 printf(" ���������� � ���������� ��� ������ �����:\n");
       						    			 	      
	 printf(" ������� ����� :");
	 scanf("%s",anazitisi);	
	 
		 anazitisi_s=AfterCheckBasicMenu(anazitisi);      //��������� ������� ������� ���� ��� ������
    if ((anazitisi_s<0)||(anazitisi_s>4))
	   {
		   printf("\n");   
		   printf("**������� ������������� ������ ��� �� �-4**\n");	   			  	      	             		     
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
	char msg[20] ="������� :" ;		
	printf("\n\n"); 		 
	printf("\t\t��������� **** ������ ��� �� ��������� \n");
	printf("\t\t          ������� ��������?\n\n"); 
	printf("\t\t���� 'Y' ������� ��� ����� - ������ �� ����������� ��� ������ �����\n\n");
	printf(" �������..."); 
	scanf("%s",&yes_exit);
	yes_exit=(toupper(yes_exit)); 
        if (yes_exit!='Y')
          {
	        printf("\t\t��� �������� ����� \n");
	        printf("\t\t������� �������� ��� ������ ����� \n");
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
