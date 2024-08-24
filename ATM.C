
#include <stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
unsigned long int acc,bal;
double amount,amt;
long int billid;
int i,j,pin,err=0,a=0,y;
void fun()
{
 float *p,a;
 p=&a;
}

int smiley()
{
	//initilizing graphic driver and
	//graphic mode variable
	int graphicdriver=DETECT,graphicmode;

	//calling initgraph function with
	//certain parameters
	initgraph(&graphicdriver,&graphicmode,"c:\\turboc3\\bgi");

	//Printing message for user
	   printf("                                HAVE A NICE DAY :)\n");
	printf("********************************************************************************\n");
	//setting color to yellow
	setcolor(YELLOW);

	//creating circle and fill it with
	//yellow color using floodfill.
	circle(300, 100, 40);
	setfillstyle(SOLID_FILL, YELLOW);
	floodfill(300, 100, YELLOW);

	//setting color to black
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, BLACK);

	//using fill ellipse and ellipse for creating face.
	fillellipse(310, 85, 2, 6);
	fillellipse(290, 85, 2, 6);

	ellipse(300, 100, 205, 335, 20, 9);
	ellipse(300, 100, 205, 335, 20, 10);
	ellipse(300, 100, 205, 335, 20, 11);


	getch();
	return 0;
}


struct bank
{
 long unsigned int account;
 double balance;
 int pin;
}S[10];
FILE *b,*u,*slip;

void read()
{

 b=fopen("bank21.txt","r");
 for(i=0;i<10;i++)
  fscanf(b,"%lu\n%d\n%lf\n\n\n",&S[i].account,&S[i].pin,&S[i].balance);
 fclose(b);

}


void dt()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void fdt()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  fprintf(slip,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}
void PIN()
{
 char *P[4];
 int k,q;
 pin=0;

 for(k=0;k<4;k++)
 {
  P[k]=getch();
  printf("*");
  q=atoi(&P[k]);
  pin=pin*10+q;
 }

 getch();
}

int checkPIN()
{
 if(pin==S[i].pin)
  return 1;
 else
  return 0;
}

void update()
{
 int k=0;
 b=fopen("BANK21.txt","w");
 for(k=0;k<10;k++)
 {
  if(a==1&&k==i)
   continue;
  fprintf(b,"%lu\n%d\n%lf\n\n",S[k].account,S[k].pin,S[k].balance);
 }
 fclose(b);
}

void checkbalance()
{
 int c;
 time_t t = time(NULL);
  struct tm tm = *localtime(&t);
 printf("                                 ENTER YOUR PIN\n");
 PIN();
 c=checkPIN();
 if(c==0)
 {
  printf("\033[0;31m");
  printf("                              INVALID PIN\n");
  printf("\033[0;33m");
  err=1;
  return;
 }
 printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");
 printf("\n                          YOUR BALANCE IS %lf\n",S[i].balance);
 u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 1 > CHECK BLALANCE\nBALANCE=%lf\n",S[i].balance);
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
 update();
}


void withdraw()
{

 time_t t = time(NULL);
  struct tm tm = *localtime(&t);

 printf("                                 ENTER YOUR PIN\n");

 PIN();

 if(checkPIN()==0)
 {
  printf("\033[0;31m");
  printf("                               INVALID PIN\n");
  printf("\033[0;33m");
  err=1;
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 2 > WITHDRAW\nINVALID PIN\n");
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
  return;
 }
printf("\n                       ENTER THE AMOUNT YOU WANT TO WITHDRAW\n");
scanf("%lf",&amount);
if(amount>S[i].balance)
{
printf("\033[0;31m");
printf("                              INSUFFICIENT BALANCE\n");
printf("\033[0;33m");
err=1;
u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 2 > WITHDRAW\n INSUFFICIENT BALANCE\n");
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);

}
else
{
 S[i].balance=S[i].balance-amount;
printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");
printf("                        REMAINING BALANCE=%lf\n",S[i].balance);
u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 2 > WITHDRAW\n REMAINING BALANCE=%lf\n",S[i].balance-amount);
	fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
 update();
 err=0;
}
}

void deposit()
{

 time_t t = time(NULL);
  struct tm tm = *localtime(&t);
 printf("                                 ENTER YOUR PIN\n");
 PIN();
 if(checkPIN()==0)
 {
  printf("\033[0;31m");
  printf("                                INVALID PIN\n");
  printf("\033[0;33m");
  err=1;
  u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf	(u,"SELECTED OPTION: < 3 > DEPOSIT AMOUNT\nENTERED INVALID PIN\n");
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
  return;
 }
printf("\n                       ENTER THE AMOUNT YOU WANT TO DEPOSIT\n");
scanf("%lf",&amount);
S[i].balance=S[i].balance+amount;
printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");
printf("                         YOUR CURRENT BALANCE=%lf\n",S[i].balance);
u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 3 > DEPOSIT AMOUNT\n CURRENT BALANCE=%lf\n",S[i].balance);
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
 err=0;
 update();
}


void changepin(pin)
{
	int otp;
 char ch;

time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char *P[4];
 int k,q;
 pin=0;
 u=fopen("datas21.txt","a");
 printf("                                 ENTER YOUR PIN\n");
 PIN();


 if(checkPIN()==1)
 {

   printf("\n                            ENTER YOUR NEW PIN\n");
   for(k=0;k<4;k++)
 {
  P[k]=getch();
  printf("*");
  q=atoi(&P[k]);
  pin=pin*10+q;
 }
 printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\nNEW PIN SET SUCCESSFULLY\n");
 getch();
   S[i].pin=pin;
   //printf("%d %d\n",pin,S[i].pin);
   err=0;
   fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
   fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
   fprintf(u,"SELECTED OPTION: < 4 > CHANGE PIN\nPIN NUMBER CHANGED\n");
   fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
    fclose(u);
    update();
   return;
 }
 printf("                     PRESS X IF YOU FORGOT YOUR CURRENT PIN\n");
 fflush(stdin);
 scanf("%c",&ch);
 if(ch=='X')
 {
  printf("                  PLEASE VISIT THE BANK FOR FURTHER INFORMATION\n");
  fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
  fprintf(u,"SELECTED OPTION: < 4 > CHANGE PIN\nFORGOT CURRENT PIN\n");
  fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
  fclose(u);
 }
 err=1;
 update();
}




 void greenpin()
{
 time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char *P[4];
 int k,q;
 pin=0;
 u=fopen("datas21.txt","a");
 printf("                                 ENTER YOUR PIN\n");
 PIN();

 if(checkPIN()==0)
 {
  printf("\033[0;31m");
  printf("                                  INVALID PIN\n");
  printf("\033[0;33m");
  err=1;
  fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
  fprintf(u,"SELECTED OPTION: < 6 > GREEN PIN\nENTERED INVALID PIN\n");
  fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
  return;
 }
printf("\n                                ENTER THE NEW PIN\n");
/*for(k=0;k<4;k++)
 {
  P[k]=getch();
  printf("*");
  q=atoi(&P[k]);
  pin=pin*10+q;
 }*/
 PIN();
 printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\nPIN SET SUCCESSFULLY\n");
 getch();
S[i].pin=pin;
//printf("%d %d",pin,S[i].pin);

 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 6 > GREEN PIN\nNEW PIN HAS BEEN SET\n");
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 err=0;
 fclose(u);
 update();
}

void billamount()
{int c;

 time_t t = time(NULL);
  struct tm tm = *localtime(&t);
 printf("                                 ENTER YOUR PIN\n");
 PIN();
 c=checkPIN();
 if(c==0)
 {
  printf("\033[0;31m");
  printf("                                   INVALID PIN\n");
  printf("\033[0;33m");
  err=1;
  return;
 }
printf("\n                                 ENTER BILL ID\n");
scanf("%ld",&billid);

amount=(S[i].balance)/100;
printf("                                  YOUR BILL AMOUNT IS %lf\n",amount);
printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");
printf("                    YOUR CURRENT BALANCE IS %lf\n",(S[i].balance)-amount);
S[i].balance=S[i].balance-amount;
u=fopen("datas21.txt","r");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"SELECTED OPTION: < 7 > BILL PAYMENT\nBILLING ID=%ld\nBILL AMOUNT=%lf\nCURRENT BALANCE=%lf\n",billid,amount,S[i].balance);
  fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
 update();
 err=0;
}


void transfer()
{  int flag=0;
   long unsigned int oacc;
   time_t t = time(NULL);

  struct tm tm = *localtime(&t);
  u=fopen("datas21.txt","a");
  printf("                PLEASE ENTER THE ACCOUNT NUMBER TO TRANSFER THE AMOUNT\n");
   scanf("%lu",&oacc);
for(j=0;j<10;j++)
 {
  if(oacc==S[j].account)
  {
   flag=1;
   break;
  }
 }
 if(flag==0)
 {
  printf("\033[0;31m");
   printf("                         THE ACCOUNT DOES NOT EXIST. PLEASE TRY AGAIN:)\n");
   printf("\033[0;33m");
   fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
  fprintf(u,"SELECTED OPTION: < 7 > TRANSFER AMOUNT\nENTERED INVALID ACCOUNT NUMBER\n");
  fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
   err=1;
   getch();
   return;
 }
printf("                     PLEASE ENTER THE AMOUNT TO TRANSFER\n");
scanf("%lf",&amt);
if(amt<S[i].balance)
 {  S[i].balance-=amt;
  S[j].balance+=amt;
printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");

printf("                    YOUR CURRENT BALANCE IS %lf\n",(S[i].balance));

 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 7 > TRANSFER AMOUNT\nTRANSFERED TO ACCOUNT:%lu\nTRANSFERED AMOUNT=%lf\nCURRENT BALANCE=%lf\n",S[j].account,amt,S[i].balance);
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 err=0;
}
else
 { printf("\033[0;31m");
   printf("                    PLEASE CHECK YOUR BANK BALANCE:)\n");
   printf("\033[0;33m");
   fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
   fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
   fprintf(u,"SELECTED OPTION: < 7 > TRANSFER AMOUNT\nINSUFFICIENT BALANCE\n");
   fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
  err=1;}
 fclose(u);
 update();
}

void delete()
{
 time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("                                 ENTER YOUR PIN\n");
 PIN();
 if(checkPIN()==0)
 {
  printf("\033[0;31m");
  printf("                                INVALID PIN\n");
  printf("\033[0;33m");
  err=1;
  u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf	(u,"SELECTED OPTION: < 8 > DELETE ACCOUNT\nENTERED INVALID PIN\n");
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
  return;
 }
 printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");
 printf("YOUR ACCOUNT IS DELETED\n");

 u=fopen("datas21.txt","a");
 fprintf(u,"DATE:%d-%02d-%02d----------------------------------------------------TIME:%02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
 fprintf(u,"ACCOUNT NUMBER=%lu\n",S[i].account);
 fprintf(u,"SELECTED OPTION: < 8 > DELETE ACCOUNT\n ACCOUNT DELETED\n");
 fprintf(u,"---------------------------------------------------------------------------------------------\n\n");
 fclose(u);
 a=1;
 err=0;
 update();
}

void printslip(int opt)
{

 slip=fopen("slip.txt","a");
 clrscr();
 printf("\033[0;36m");
 printf("\n\nPLEASE WAIT...\n");
 delay(1000);
 printf("YOUR TRANSACTION IS BEING CARRIED OUT");
 for(y=0;y<3;y++)
 {
   delay(1000);
   printf(".");
 }
 delay(1000);
 printf("\n");
 delay(2);
 clrscr();
 printf("********************************************************************************\n");
 fprintf(slip,"********************************************************************************\n");
 printf("\033[1;33m");
 printf("                           ***WELCOME TO VNR BANK***\n\n");
 fprintf(slip,"                           ***WELCOME TO VNR BANK***\n\n");


 dt();
 fdt();
 //printf("\033[0m");
switch(opt)
{
  case 1: printf("ACCOUNT NUMBER:%lu\nBALANCE:%lf\n",acc,S[i].balance);
	  printf("HAVE A NICE DAY:)\n");
	    fprintf(slip,"ACCOUNT NUMBER:%lu\nBALANCE:%lf\n",acc,S[i].balance);
	 fprintf(slip,"HAVE A NICE DAY:)\n");
	   break;
  case 2: printf("ACCOUNT NUMBER:%luBALANCE:%lf\nWITHDRAWED AMOUNT:%lf\n",acc,S[i].balance,amount);
	  printf("HAVE A NICE DAY:)\n");
	   fprintf(slip,"ACCOUNT NUMBER:%luBALANCE:%lf\nWITHDRAWED AMOUNT:%lf\n",acc,S[i].balance,amount);
	  fprintf(slip,"HAVE A NICE DAY:)\n");
	  break;
  case 3: printf("ACCOUNT NUMBER:%luBALANCE:%lf\nWITHDRAWED AMOUNT:%lf\n",acc,S[i].balance,amount);
	  printf("HAVE A NICE DAY:)\n");
	    fprintf(slip,"ACCOUNT NUMBER:%luBALANCE:%lf\nWITHDRAWED AMOUNT:%lf\n",acc,S[i].balance,amount);
	  fprintf(slip,"HAVE A NICE DAY:)\n");
	  break;
  case 4: printf("ACCOUNT NUMBER:%lu\nBALANCE:%lf\nTRANSFERED AMOUNT:%lf\nTRANSFERED TO ACCOUNT=%lu\n",acc,S[i].balance,amt,S[j].account);
	  printf("HAVE A NICE DAY:)\n");
	   fprintf(slip,"ACCOUNT NUMBER:%lu\nBALANCE:%lf\nTRANSFERED AMOUNT:%lf\nTRANSFERED TO ACCOUNT=%lu\n",acc,S[i].balance,amt,S[j].account);
	  fprintf(slip,"HAVE A NICE DAY:)\n");
	  break;
  case 5: printf("ACCOUNT NUMBER:%lu\nBALANCE:%lf\nPIN CHANGED SUCCESSFULLY\n",acc,S[i].balance);
	  printf("HAVE A NICE DAY:)\n");
	    fprintf(slip,"ACCOUNT NUMBER:%lu\nBALANCE:%lf\nPIN CHANGED SUCCESSFULLY\n",acc,S[i].balance);
	  fprintf(slip,"HAVE A NICE DAY:)\n");
	  break;
  case 6: printf("ACCOUNT NUMBER:%lu\nBALANCE:%lf\nNEW PIN SET SUCCESSFULLY\n",acc,S[i].balance);
	  printf("HAVE A NICE DAY:)\n");
	    fprintf(slip,"ACCOUNT NUMBER:%lu\nBALANCE:%lf\nNEW PIN SET SUCCESSFULLY\n",acc,S[i].balance);
	  fprintf(slip,"HAVE A NICE DAY:)\n");
	  break;
  case 7: printf("ACCOUNT NUMBER:%lu\nBALANCE:%lf\nBILL ID=%ld\nBILL AMOUNT=%lf\n",acc,S[i].balance,billid,amount);
	  printf("HAVE A NICE DAY:)\n");
	    fprintf(slip,"ACCOUNT NUMBER:%lu\nBALANCE:%lf\nBILL ID=%ld\nBILL AMOUNT=%lf\n",acc,S[i].balance,billid,amount);
	  fprintf(slip,"HAVE A NICE DAY:)\n");
	  break;
  case 8: printf("DELETED ACCOUNT: %lu\n",acc);
	    fprintf(slip,"DELETED ACCOUNT: %lu\n",acc);
  case 9: printf("                                HAVE A NICE DAY :)\n");
	    fprintf(slip,"                                HAVE A NICE DAY :)\n");

 }
 printf("\033[0;36m");
 printf("********************************************************************************\n");
  fprintf(slip,"********************************************************************************\n");
  fclose(slip);
}





void main()
{

 int flag=0,opt;
 char ch;
 clrscr();
 printf("\033[0;36m");
 printf("********************************************************************************\n");
 printf("\033[0;33m");
 printf("                           ***WELCOME TO VNR BANK***\n\n");
 //printf("\033[1;33m");
 dt();
 //printf("\033[0m");
 read();

 printf("                         PLEASE ENTER YOUR ACCOUNT NUMBER\n");
 scanf("%lu",&acc);
 for(i=0;i<10;i++)
 {
  if(acc==S[i].account)
  {
   flag=1;
   break;
  }
 }
 if(flag==0)
 {
   printf("                                       THE ACCOUNT DOES NOT EXIST. PLEASE TRY AGAIN:)\n\n");
   getch();
   return;
 }
 do
 {
 printf("\033[0;36m");
 printf("********************************************************************************\n");
 printf("\033[1;33m");
 printf("\n                             PLEASE SELECT AN OPTION\n\n");
 printf("\t < 1 >CHECK BALANCE                          < 2 >WITHDRAW CASH\n");
 printf("\t < 3 >DEPOSIT AMOUNT                         < 4 >TRANSFER AMOUNT\n");
 printf("\t < 5 >CHANGE PIN                             < 6 >GREEN PIN\n");
 printf("\t < 7 >BILL PAYMENT                           < 8 >DELETE ACCOUNT\n");
 printf("\t < 9 > EXIT\n\n");
 scanf("%d",&opt);
 if(opt<1||opt>9)
 {
  printf("                                 INVALID OPTION\n\n");
  getch();
  return;
 }
 if(opt>=1&&opt<=8)
  flag=1;
 switch(opt)
 {
  case 1: checkbalance();
	   break;
  case 2: withdraw();
	  break;
  case 3: deposit();
	  break;
  case 4: transfer();
	  break;
  case 5: changepin();
	  break;
  case 6: greenpin();
	  break;
  case 7: billamount();
	  break;
  case 8: delete();
	  break;
  case 9: smiley();
	     printf("                                HAVE A NICE DAY :)\n");
	  printf("********************************************************************************\n");

	  return;
 }
 if(flag==1&&err==0)
 {
  printf("                 DO YOU WANT RECEIPT FOR YOUR TRANSACTION(Y/N)?\n\n");
  fflush(stdin);
  scanf("%c",&ch);
  if(ch=='Y')
   printslip(opt);

 }
 }while(opt!=9&&err==0);
 if(err==1)
 {
 smiley();
 }
 getch();
}

