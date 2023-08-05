#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int metr; // metavlhth pu parusiazei se poio kelh vrethhke to username kai o kwdikos pu tha ekxwrhthun , an uparxoun
int i=0;                // metavlhth pu metraei tis eggrafes kai xrhsimopoieitai sto diavasma ths epomenhs eggrafhs kathe fora
int viewclient;         //metavlhth pu deixnei ton arithmo tu atomu pu ekane login apo ton pinaka clnt[20]
struct client           //arxh domhs me onoma client
{
	char name[100];     //onoma pelath
	char surname[100];  // epitheto pelath
	struct address      //arxh domhs me onoma address
	{
		char odos[100]; //odos petalh
		int num;        //arithmos
		int tm;         //tetragwnika metra katoikias pelath
	}ad;                //dhmiourgia global metavlhths ths domhs address
	char username[100]; //username pelath
	char password[100]; //kwdikos pelath
	float cost[12][3];  //pinakas cost pu sthn prwth sthlh exei ths katanalwmenes kilovatwres , sthn deyterh to teliko poso kai sthn trith-
}clnt[20];              //-fainetai an o xrhsths exei plhrwsei (1=nai ,0=oxi) gia kathe mhna antistoixa

int hmeresmhna[12]={31,28,31,30,31,30,31,30,31,30,31,30}; //pinakas me tis hmeres kathe mhna 
int calculated[20];    //pinakas pu deixnei an o xrhsths exei ypologisei to teliko poso prin provei sthn plhrwmh (1=nai , 0=oxi)

void signup_user();    //synarthsh gia thn eggrafh tu pelath
void login_user();     //synarthsh gia thn syndesh tu pelath
void view_user();      //synarthsh gia thn provolh stoixeiwn tu pelath pu exei syndethei
void modify_user();    //synarthsh gia tis allages timwn ths odou , tou arithmu kai twn tetragwnikwn metrwn tu spitiou
void calculate_cost(); //synarthsh gia tus ypologismus kostus gia kathe mhna
void payment();        //synarthsh gia thn plhrwmh tu kostus kapoiou mhna
void most_expensive(); //synarthsei pu ektupwnei ta stoixeia tu pio akrivu mhna tu sygkekrimenou pelath

int main(int argc, char *argv[]) {
	char option;               //metavlhth pu diavazei thn epilogh tu pelath (a=register b=login c=exit)
	int customeroption;       //metavlhth pu diavazei thn epilogh tu pelath (view,modify,calculate,pay,most expensive,exit)
    int counter1=0;           //metavlhth pu kanei prospelash ston pinaka calculated 20  
    while (counter1<20)      
    {
    	calculated[counter1]=0; 
    	counter1=counter1+1;
	}
	printf("---------------------------------\n"); //emfanish katallhlu mhnymatos 
	printf("	HOME SCREEN\n");
	printf(" Please press:\n a. Register\n b. Login\n c. Exit\n");
	printf("---------------------------------\n");
	scanf("%c",&option);
	while ((option!='a')&&(option!='c'))// elegxos egkurothtas ths timhs option.
    {
      	scanf("%c",&option); //allagh ths timhs option.
   	}
   	do //epanalhpsh h opoia trexei oso o xrhsths den thelei na kanei exit 
	{	
   		if (option=='c') // an o xrhsths epileksei to 3 tote termatizetai to programma
   		{
   			break;
		}
    	if (option=='a') //an epileksei to 1
    	{
    		signup_user(); //kaleitai h signup_user
    		printf("---------------------------------\n"); // katallhlo mhnyma
			printf("	HOME SCREEN\n");
			printf(" Please press:\n a. Register\n b. Login\n c. Exit\n");
			printf("---------------------------------\n");
			scanf("%c",&option);
			while ((option!='a')&&(option!='b')&&(option!='c'))// elegxos egkurothtas ths timhs option.
   			{
     		   	scanf("%c",&option); //allagh ths timhs option.
   			}
   			if (option=='a')
   			{
   				continue;
			}
		}
		if (option=='b') //an epileksei to 2
		{
			
			login_user(); //kaleitai h synarthsh login_user
			while (1) // anoigei while (1) h opoia termatizei otan o pelaths epileksei na kanei logout 
			{	
				printf("---------------------------------\n");	//katallhlo mhnyma
				printf("	CLIENT SCREEN\n");
				printf("Please press:\n 1. View\n 2. Modify\n 3. Calculate\n 4. Payment\n 5. Most Expensive\n 6. Logout\n");
				scanf("%d",&customeroption);
				while ((customeroption!=1)&&(customeroption!=2)&&(customeroption!=3)&&(customeroption!=4)&&(customeroption!=5)&&(customeroption!=6)) // elegxos timhs customeroption
				{
					scanf("%d",&customeroption); // an einai lathos tote ksanadiavazetai 
				}
				if (customeroption==1) // an epelekse to 1
				{
					view_user(); // kaleitai h synarthsh view_user
					continue; // tha ksanaemfanistei h othonh pelath
	   			}
	   			if (customeroption==2) // an epelekse to 2
	   			{
	   				modify_user(); // kaleitai h synarthsh modify_user
					continue;  // tha ksanaemfanistei h othonh pelath 	
		 	    }
		 	    if (customeroption==3) // an epelekse to 3
		    	{
		    		calculate_cost(); // kaleitai h synarthsh calculate_cost
		   		 	calculated[viewclient]=1; // ekxwreitai ston pinaka calculated sto kelh tu sygkekrimenu pelath h timh 1 , dhladh oti exei metrhthei to kostos kathe mhna
		   		 	continue; // tha ksanaemfanistei h othonh pelath
				}
				if ((customeroption==4)&&(calculated[viewclient]==1)) // an epelekse to 4 KAI exei metrhthei to kostos kathe mhna tu sygkekrimenu pelath tote ..
				{
					payment(); // kaleitai h synarthsh payment
					continue; // tha ksanaemfanistei h othonh pelath
				}
				if((customeroption==4)&&(calculated[viewclient]!=1)) // an epelekse to 4 KAI den exei metrhthei to kostos kathe mhna tu sugkekrimenu pelath tote..
				{
					printf("You haven't calculated the cost yet. Please type 3. to procceed with the calculation.\n"); //emfanizetai katallhlo mhnyma
					continue; // tha ksanaemfanistei h othonh pelath
				}
				if (customeroption==5) // an epelekse to 5
				{
					printf("\n");
					system("cls");
					most_expensive(); // kaleitai h synarthsh most_expensive
					continue; // ksanaemfanizetai h othonh tu pelath
				}
				if (customeroption==6) // an epelekse to 6
				{
					system("cls");
					break; // termatizetai h epanalhpsh 
				}
	    
     		}
		}
		printf("---------------------------------\n"); // emfanish katallhlu mhnymatos
		printf("	HOME SCREEN\n");
		printf(" Please press:\n a. Register\n b. Login\n c. Exit\n");
		printf("---------------------------------\n");
		scanf("%c",&option);
		while ((option!='a')&&(option!='b')&&(option!='c'))// elegxos egkurothtas ths timhs option.
    	{
    	  	scanf("%c",&option); //allagh ths timhs option.
   		}	
    }
    while (option!='c');
	return 0;
}


void signup_user() 
{
	system("cls"); // katharizetai h othonh
	i=i+1; // h metavlhth pu metraei tus pelates pu exun eggrafei ayksanetai kata 1
	printf("	SIGN UP\n"); // emfanish katallhlu mhnumatos
	printf("Please enter your name.\n");
	scanf("%s",&clnt[i].name); // diavasma onomatos
	printf("Please enter your surname.\n");
	scanf("%s",&clnt[i].surname); // diavasma epwnumou
	printf("Please enter the street.\n");
	scanf("%s",&clnt[i].ad.odos); // diavasma odu
	printf("Please enter the number.\n");
	scanf("%d",&clnt[i].ad.num); // diavasma arithmu
	printf("Please enter the total square meters of your house.\n");
	scanf("%d",&clnt[i].ad.tm); // diavasma tetragwnikwn metrwn
	printf("Please enter your password.\n");
	scanf("%s",clnt[i].password); // diavasma kwdiku
    char losur[100]; //lower case surname
	int counterx;
	 while( clnt[i].surname[counterx] )  // ekxwrei sto losur to periexomeno tu epithetu me mikra grammata
	{
      losur[counterx]=tolower(clnt[i].surname[counterx]);
      counterx++;
    }
    int len = strlen(clnt[i].surname);
	losur[len] = '\0'; //topothetume sto telos tu string ton xarakthra \0
	strcpy(clnt[i].username,losur);
	char ott[4]="123";
    strcat(clnt[i].username,ott); // to username isoutai me to onoma tu pelath +123 sto telos
    printf("(Your username automatically is :%s .)\n",clnt[i].username);
    sleep(1);
    printf("**Successful signup user.**\n"); // emfanish katallhlou mhnymatos
    sleep(5); // anamonh gia 5 deyterolepta mexri thn metavash sthn othonh pelath
    system("cls");
}

void login_user()
{
	system("cls"); // ekkatharhsh othonhs
	printf("-------------------------------------\n"); // katallhlo mhnyma
	printf("LOGIN\n"); //katallhlo mhnyma
	printf("\n");
	int isxyei=0; // metavlhth pu exei thn timh 0 oso den exei vrethei to username kai o kwdikos pu tha ekxwrhthun kai thn timh 1 an uparxun
	char usernamecheck[100],passwordcheck[100]; // metavlhth pu tha diavazei to username kai ton kwdiko gia na mporei na syndethei o pelaths stis leiturgies
	printf("Please enter your username.\n"); // katallhlo mhnyma
	scanf("%s",&usernamecheck); // diavasma usernamecheck
     while (1)
    {
    	metr=1;
		while (metr<=i)
		{
			if (strcmp(usernamecheck,clnt[metr].username)==0) // an isxuei h sygkekrimenh synthhkh tote vrethhke to username pu ekxwrhthhke sthn metavlhth usernamecheck
			{
				isxyei=1; // allagh timhs isxyei
				printf("**Valid username.**\n"); // katallhlo mhnyma
				break; // eksodos apo thn while
			}
			metr=metr+1;
		}
		if (isxyei==1) //an vrethhke username pu na einai idio me to usernamecheck tote ..
		{
			viewclient=metr; // h global metavlhth viewclient pairnei thn timh sthn opoia vrethhke to username
			break; // eksodos apo thn while (1) 
		}
		scanf("%s",&usernamecheck); // diavasma ths usernamecheck , se periptwsh pu den vrethhke sthn for pu prohghthhke
		continue;		
    } 
   printf("Please enter your password.\n"); //katallhlo mhnyma
   scanf("%s",&passwordcheck);	// diavasma ths passwordcheck
   while (strcmp(passwordcheck,clnt[metr].password)!=0) // elegxos egkyrothtas timhs
   {
   		scanf("%s",&passwordcheck);
   }
   printf("**Correct password.**\n");
   sleep(2); // anamonh 2 deyteroleptwn
   system("cls"); // ekkatharhsh othonhs
}


void view_user()
{
	system("cls"); // ekkatharhsh othonhs
	printf("-------------------------------------\n"); // katallhlo mhnyma
	printf("\n");
	printf("		CLIENT DETAILS\n");
	printf("\n");
	printf("Name : %s \n",clnt[viewclient].name);
	printf("Surname : %s \n",clnt[viewclient].surname);
	printf("Street : %s \n",clnt[viewclient].ad.odos);
	printf("Number : %d \n",clnt[viewclient].ad.num);
	printf("Square meters of your house : %d\n",clnt[viewclient].ad.tm);	
	sleep(4);
	system("cls");
}

void modify_user()
{
	system("cls"); // ekkatharhsh othonhs
	printf("---------------------------------\n"); // katallhlo mhnyma
	printf("\n");
	printf("	MODIFY CLIENT DETAILS\n");
	printf("\n");
	printf("Please enter the new street.\n");
	scanf("%s",&clnt[viewclient].ad.odos);
	printf("Please enter the new number.\n");
	scanf("%d",&clnt[viewclient].ad.num);
	printf("Please enter the total square meters of your house .\n");
	scanf("%d",&clnt[viewclient].ad.tm);
	system("cls"); //ekkatharhsh othonhs
}

void calculate_cost() 
{
	system("cls"); // ekkatharhsh othonhs
	int k=0;
	int months=0; // metavlhth pu parusiazei tus mhnes
	printf("-------------------------------------\n"); // katallhlo mhnyma
	printf("\n");
	printf("	CALCULATE COST\n");
	printf("\n");
	printf("Please enter the kwh consumption of each month of the year.\n");
    while(months<12) // parakatw diavazontai ta posa kilovatwras gia kathe mhna
    {
        if (months==0)
        {
            printf("January: ");
            scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
        }
		if (months==1)
		{
		    printf("February: ");
            scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==2)
		{
		    printf("March: ");
            scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==3)
		{
		    printf("April: ");
            scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==4)
		{
		    printf("May: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==5)
		{
		    printf("June: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==6)
		{
		    printf("July: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==7)
		{
		    printf("August: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==8)
		{
		    printf("September: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==9)
		{
		    printf("October: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]); 	
			}
		}
		if (months==10)
		{
		    printf("November: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		if (months==11)
		{
		    printf("December: ");
		    scanf("%f",&clnt[viewclient].cost[months][1]);
            printf("\n");
            while (clnt[viewclient].cost[months][1]<0) // elegxos egkyrothtas
            {
            	scanf("%f",&clnt[viewclient].cost[months][1]);	
			}
		}
		months=months+1;
		continue;
	}
	months=0;
	while (months<12) // while h opoia ypologizei to teliko poso kathe mhna
	{
		if (clnt[viewclient].cost[months][1]<=1600)
		{
			clnt[viewclient].cost[months][2]=clnt[viewclient].ad.tm*clnt[viewclient].cost[months][1]*0.005*hmeresmhna[months]/365;	
		}
		else if (clnt[viewclient].cost[months][1]<=2000)
		{
			clnt[viewclient].cost[months][2]=clnt[viewclient].ad.tm*clnt[viewclient].cost[months][1]*0.008*hmeresmhna[months]/365;
		}
		else
		{
			clnt[viewclient].cost[months][2]=clnt[viewclient].ad.tm*clnt[viewclient].cost[months][1]*0.009*hmeresmhna[months]/365;
		}	
		months=months+1;
	}
	system("cls");
}


void payment()
{
	system("cls");
	printf("-------------------------------------\n"); // katallhlo mhnyma
	printf("\n");
	printf("	PAYMENT\n");
	printf("\n");
	printf("The cost each month is:\n"); // parakatw ektupwnetai to kostos kathe mhna
	int months=0;
    while(months<12)
    {
        if (months==0)
        {
            printf("1.January: ");
            printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
        }
		if (months==1)
		{
		    printf("2.February: ");
            printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==2)
		{
		    printf("3.March: ");
            printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==3)
		{
		    printf("4.April: ");
            printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==4)
		{
		    printf("5.May: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==5)
		{
		    printf("6.June: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==6)
		{
		    printf("7.July: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==7)
		{
		    printf("8.August: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==8)
		{
		    printf("9.September: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==9)
		{
		    printf("10.October: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==10)
		{
		    printf("11.November: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		if (months==11)
		{
		    printf("12.December: ");
		    printf("%.2f",clnt[viewclient].cost[months][2]);
            printf("\n");
		}
		months=months+1;
		continue;
	}
	printf("Please enter the number of the month u would like to pay.\n"); // katallhlo mhnyma
	int plhrwmh; // metavlhth pu parusiazei ton mhna pu thelei o pelaths na plhrwsei 
	scanf("%d",&plhrwmh);
	while ((plhrwmh>12)||(plhrwmh<0)) // elegxos egkurothtas timhs mhna
	{
		printf("Invalid number of month, please try again.\n");
		scanf("%d",&plhrwmh);
	}
	while (clnt[viewclient].cost[plhrwmh-1][3]!=0) // elegxos oti o mhnas den exei plhrwsei pio prin
	{
		printf("You have already paid the chosen month .\n");
		scanf("%d",&plhrwmh);
	}
	printf("Please enter the total cost shown next to the month you chose.\n"); // katallhlo mhnyma
	float final;
	scanf("%f",&final); // diavazei to teliko poso
	while (fabs(final-(clnt[viewclient].cost[plhrwmh-1][2]))>=0.01)
	{
		printf("Please enter the correct amount.\n");
		scanf("%f",&final);
	}
	printf("**Successful payment.**\n");
	clnt[viewclient].cost[plhrwmh-1][3]=1;
	sleep(3);
	system("cls");
}



void most_expensive()
{

	int a=0;
	int flag=0;
	int metrhthss=0;
	float temp=-1; // temp akraia timh , me skopo thn evresh tu megistu
	while (metrhthss<12)
	{
		if (clnt[viewclient].cost[metrhthss][3]!=0) // prepei enas tulaxiston mhnas na exei plhrwthei
		{
			flag=1;
			break;
		}
		metrhthss=metrhthss+1;
	}
	metrhthss=0;
	if (flag==0)
	{
		printf("\n");
		printf("**You have not paid the final cost on any of the months of this year.\n**");
	}
	else
	{
		while (metrhthss<12)
		{
			if ((temp<clnt[viewclient].cost[metrhthss][2])&&(clnt[viewclient].cost[metrhthss][3]==1))
			{
				temp=clnt[viewclient].cost[metrhthss][2];
			}
			metrhthss=metrhthss+1;
		}
			metrhthss=0;
       		printf("\nMOST EXPENSIVE \n");
			while (metrhthss<12)
			{
				if (a==0)
				{
					printf("\n");
					a=1;
				}
				if ((temp==clnt[viewclient].cost[metrhthss][2])&&(clnt[viewclient].cost[metrhthss][3]==1))// an einai iso me to megisto kai exei plhrwthei tote ektupwnetai mhnyma
				{
					if (metrhthss==0)
					{
						printf("January\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==1)
					{
						printf("February\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==2)
					{
						printf("March\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==3)
					{
						printf("April\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==4)
					{
						printf("May\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==5)
					{
						printf("June\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf( "cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==6)
					{
						printf("July\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==7)
					{
						printf("August\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==8)
					{
						printf("September\n");
						printf("%.2f kwh consumed \n",clnt[viewclient].cost[metrhthss][1]);
						printf( "cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==9)
					{
						printf("October\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==10)
					{
						printf("November\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
					if (metrhthss==11)
					{
						printf("December\n");
						printf("%.2f kwh consumed\n",clnt[viewclient].cost[metrhthss][1]);
						printf("cost:%.2f\n",clnt[viewclient].cost[metrhthss][2]);
					}
			}	
			metrhthss=metrhthss+1;
		}
	}
	sleep(4);
	system("cls");
}






