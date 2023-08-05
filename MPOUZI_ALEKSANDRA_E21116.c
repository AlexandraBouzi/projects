#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


		
unsigned long long cardnum; // h metavlhth antistoixei ston arithmo kartas tu xrhsth.	
float t;              // h metavlhth antistoixei sto teliko kostos pu tha plhrwsei o xrhsths .
char name[100],surname[100],address[100],username[10],password[5]; //oi metavlhtes apothhkevun ta stoixeia tu xrhsth .
float s1,s2,s3;      // oi metavlhtes xrhsimopoiountai gia prwth fora sthn synarthsh calculate_cost kai antistoixoun sto kostos dhmu , synolikes xrewseis kai teliko poso xrewshs.
int k,s;             // oi metavlhtes dhlwnun tis kilovatwres kai ta tetragwnika metra antistoixa. 
float kwh1=0.00542;  // h metavlhth antistoixei stis katanalwsh kwh otan o xrhsths einai sthn vathmida 1. 
float kwh2=0.00682;	 // h metavlhth antistoixei sthn katanalwsh kwh otan o xrhsths einai sthn vathmida 2.
float kwh3=0.00822;   // h metavlhth antistoixei sthn katanalwsh kwh otan o xrhsths einai sthn vathmida 3.

//  oi 3 parapanw metavlhtes arxikopoiuntai prwta me tis times pu dinontai ston pinaka , sthn synexeia omws mporun na allaksun me thn synarthsh ths change_cost.

void signup_user();   //synarthsh 1: eggrafh tu xrhsth .. sthn sygkekrimenh synarthsh o xrhsths arxikopoiei to onoma , epitheto , diefthhnsh , username kai password tou.
void login_user();    //synarthsh 2: eisodos tu xrhsth stis leitourgies .. zhteitai to username kai o kwdikos ews otu ekxwrhthun swsta.
void calculate_cost();//synarthsh 3: ypologismos tu kostus.
void payment();       //synarthsh 4: plhrwmh tu kostus me metrhta h karta. 
void get_receipt();   //synarthsh 5:emfanish apodeikshs.
void exit_user();     //synarthsh 6:eksodos xrhsth apo tis leirugies kai metavash sthn arxikh othonh xrhsth.
void logout();        //synarthsh 7:metavash xrhsth h diaxeiristh sthn arxikh othonh tu programmatos.
void login_admin();   //synarthsh 8:eisodos diaxeiristh stis leiturgies.
void change_cost();   //synarthsh 9:allagh kostus kilovatwras.
void exit_admin();    //synarthsh 10:eksodos diaxeiristh kai metavash sthn arxikh othonh diaxeiristh.
void terminate();     //synarthsh 11:termatismos programmatos

int main(int argc, char *argv[]) 
{
    int y;             //metavlhth h opoia xrhsimeyei sthn epilogh tu xrhsth anamesa sto 1.Sign Up 2.Login 3.Logout .
	char cho[2];       // epilogh user an pathsei to 2 ( dhladh epilogh anamesa se a.Calculate Cost b.Payment c.Get receipt d.Exit ).
	
	//Oi parakatw 4 metavlhtes tha xreiastun sthn eyresh ths epiloghs tu user ( dhladh poia apo tis epiloges a.Calculate Cost b.Payment c.Get receipt d.Exit dialekse).
	
	char a[2]="a";     
	char b[2]="b";
	char c[2]="c";
	char d[2]="d";
	char who[10],user[5]="user",admin[6]="admin",zero[2]="0"; /*1. h metavlhth who anaferetai sto poios plhktrologei ( user h admin ) 2. oi metavlhtes user , admin kai zero xrhsimeyoun
	ston elegxo ths timhs ths metavlhths who kai sthn eyresh ths epiloghs tu atomu pu plhktrologei .*/
	printf("Please type user , admin or 0.\n");
    scanf("%s",&who);
    while ((strcmp(user, who)!=0)&&(strcmp(admin, who)!=0)&&(strcmp(zero, who)!=0)) // elegxos egkurothtas ths timhs who.
    {
        printf("Please type user , admin or 0.\n"); // katallhlo mhnyma.
        scanf("%s",&who); //allagh ths timhs who.
        continue;
    }
	do                               // anoigei mia megalh epanalhpsh h opoia diasfalizei thn epanalhpsh tu programmatos mexris otou plhktrologhthei h timh 0.
	{
	 	if (strcmp(zero,who)==0)     // an ekxwrhthei sthn metavlhth who h timh 0 ..
    	{
    		terminate();
    		break;                  //..termatizetai to programma.
		}
		while (1)
		{
    		if (strcmp(user, who)==0) // an sthn metavlhth who ekxwrhthhke h timh user tote ..
   		    {
    			while (1) /*anoigei deyterh while (1) h opoia otan o xrhsths kanei exit o vrogxos ksanarxizei apo ayto to shmeio ,an kanei logout o vrogxos den tha ektelestei pali	
    			 ektos ean erthei epomenos user.*/
    			{
	        		printf (" 1.Sign up \n 2.Login \n 3.Logout \n");	// menu user 
	 				scanf ("%d", &y);                               // diavazetai h timh ths y pu antistoixei se mia apo tis parapanw epiloges.
	 		 		while ((y!=1)&&(y!=3))	                // elegxos egkurothtas timhs pu ekxwrhthhke apo ton xrhsth.
	    			{ 
	     				 scanf ("%d", &y);                          // ksanadiavazetai h timh ths y mexri ayth na einai egkyrh.
	    			}
	                if (y==1)   // an o xrhsths epelekse na kanei sign up tote .. 
	  			    {
	      				signup_user ();     // kaleitai h synarthsh 1 : signup_user()
	      				printf (" 1.Sign up \n 2.Login \n 3.Logout \n");	    // menu user 
	     				scanf ("%d", &y);  // diavazetai h timh ths y pu antistoixei se mia apo tis parapanw epiloges.
	     				while (y!=2)       // elegxos egkurothtas ths timhs y ( dhladh oti den tha ksanakanei signup kai den tha kanei logout apo enan logariasmo pu den exei syndethei.
						{
			  				scanf ("%d", &y); // ksanadiavazetai h timh ths y mexri ayth na einai egkyrh.
						}
				    }    // klenei h if (y==1)
					if (y==2)   // an o xrhsths epelekse na kanei login tote ..
					{
		 	   			login_user();     //kaleitai h synarthsh 2 : login_user()	
	        		    printf(" a. Calculate Cost \n b. Payment \n c.Receipt \n d. Exit\n"); // leiturgies pu mporei na dialeksei o xrhsths.
	        			scanf("%s",&cho); // scanf ths epiloghs a , b ,c ,d.
	        			while (strcmp(cho,a)!=0)
	        			{
	        				printf("To calculate the cost press 'a'.\n");
	        				scanf("%s",&cho);
						}
	        			if (strcmp(cho,a)==0) //an o xrhsths pathsei a..
	        			{
	        				calculate_cost();	         // kaleitai h synarthsh 3 : calculate_cost()
	        				printf(" a. Calculate Cost \n b. Payment \n c.Receipt \n d. Exit\n"); //leiturgies pu mporei na dialeksei o xrhsths.
	        				scanf("%s",&cho);           // scanf ths epiloghs a,b,c,d.		
	        	  		    while (strcmp(cho,b)!=0)    //meta apo ton ypologismo tu kostus , o xrhsths prepei na plhrwsei (ara na epileksei to b).
	        	   			{
	        	   				printf("In order to pay , please press 'b'.\n");
	        	    			scanf("%s",&cho);      //scanf ths epiloghs a,b,c,d.
							}
						} // telos ths if (strcmp(cho,a)==0).
						if (strcmp(cho,b)==0)         //an o xrhsths pathsei to b..
						{
							payment();               // kaleitai h synarthsh 4 :payment()
	        				printf(" a. Calculate Cost \n b. Payment \n c.Receipt \n d. Exit\n"); //leiturgies pu mporei na dialeksei o xrhsths
	        				scanf("%s",&cho);        // scanf ths epiloghs a,b,c,d.	
	        	   			while (strcmp(cho,c)!=0) // meta apo thn plhrwmh , o xrhsths prepei na parei thn apodeiksh (ara na epileksei to c).
	        	   			{
	        	   				printf("In order to get the receipt , please press 'c'.\n");
	        	    			scanf("%s",&cho);    //scanf ths epiloghs a,b,c,d	
							} 
				        }//telos ths if (strcmp(cho,b)==0).
						if (strcmp(cho,c)==0)      //an o xrhsths pathsei to c..
						{
							get_receipt();        // kaleitai h synarthsh 5 : get_receipt()
	        				printf(" a. Calculate Cost \n b. Payment \n c.Receipt \n d. Exit\n");
	        				scanf("%s",&cho);	 // scanf ths epiloghs a,b,c,d.
	        	    		while (strcmp(cho,d)!=0)   // meta apo thn emfanish ths apodeikshs prepei o xrhsths na kanei exit (ara na epileksei to d ).
	        	    		{
	        	    			printf("In order to exit , please press 'd'.\n");
	        	     			scanf("%s",&cho); // scanf ths epiloghs.	
							}
						}//telos ths if (strcmp(cho,c)==0).
						if (strcmp(cho,d)==0)    // an o xrhsths pathsei to d..
						{
							exit_user();         // kaleitai h synarthsh 6 : exit_user()
							continue;            //ginetai continue tu vrogxou ths deyterhs while(1)
						}		
        			} // telos ths if (y==3)
                    if (y==3) // an o xrhsths epelekse logout ..
                    {
        				logout();               //kaleitai h synarthsh 7 : logout()
        				break;                  // ginetai break ths deyterhs while(1)
					} // telos ths if (y==3)
                } //kleinei h deyterh while(1)
            } // kleinei h if(strcmp(user,cho)==0).
			if (strcmp(who,admin)==0)
			{
				int cadmin; // metavlhth pu dhlwnei thn epilogh tu diaxeiristh (1 gia login 2 gia logout ).
				char cadmin2[2]; // metavlhth pu dhlwnei thn epilogh tu diaxeiristh ( a gia Change Cost b gia Exit ).
				while (1)   // trith while (1) h opoia otan o diaxeirisths kanei exit ksanarxizei o vrogxos ,otan o diaxeirisths kanei logout ginetai break ths sygkekrimenhs while.
				{
					printf("1.Login\n2.Logout\n");  // menu admin
					scanf("%d",&cadmin);             //scanf ths epiloghs login , logout.
					if (cadmin==1)                   // an epelekse login
					{
						login_admin();               //kaleitai h synarthsh 8 : login_admin()
	    				printf("a. Change Cost \nb. Exit \n");
	    				scanf("%s",&cadmin2);        // scanf ths epiloghs 
						while ((strcmp(cadmin2,a)!=0)&&(strcmp(cadmin2,b)!=0)) // elegxos egkyrothtas ths metavlhths cadmin2.
						{
							printf("a. Change Cost \nb. Exit \n");            
	    					scanf("%s",&cadmin2);   //scanf ths epiloghs. 
						}
     				    if (strcmp(cadmin2,a)==0)  // an epelekse na allaksei to kostos twn kwh..
       			    	{
        					change_cost();         //kaleitai h katallhlh synarthsh.
        					printf("a. Change Cost \nb. Exit \n");
	    					scanf("%s",&cadmin2);  //scanf ths epiloghs 
							while (strcmp(cadmin2,b)!=0) // o diaxeirhsths meta apo thn allagh prepei na pathsei exit.
							{
								printf("a. Change Cost \nb. Exit \n"); 
	    						scanf("%s",&cadmin2);   //scanf ths epiloghs.
							}
		                }
						if (strcmp(cadmin2,b)==0)     // an pathsei exit.
						{
		 					exit_admin();            // kaleitai h katallhlh synarthsh.
		 					continue;                //ginetai continue ths triths while (1) ,etsi wste na ksanaemfanistei to menu tu admin.
						}
					}
					if (cadmin==2)                  //an epelekse logout.
					{
						logout();                  // kaleitai h katallhlh synarthsh. 
						break;                     /* ginetai break ths triths while (1) etsi wste na emfanistei to menu opu epilegei kaneis an einai user admin h an thelei na 
					termatisei to programma. */
					}
				}	
			}
			break;
		} // kleinei h prwth epanalhpsh while(1) poy kanume break me thn synarthsh logout
		printf("Please type user , admin or 0.\n");  
   	 	scanf("%s",&who);    
    	while ((strcmp(user, who)!=0)&&(strcmp(admin, who)!=0)&&(strcmp(zero, who)!=0)) // elegxos egkurothtas ths who
    	{
        	printf("Please type user , admin or 0.\n");
        	scanf("%s",&who);
       		continue;
   		}
	}	// kleinei h megalh do while pu skopos ths einai na termatisei to programma otan ekxwrhthei h timh tu 0.
	while (strcmp(who,zero)!=0); 
    return 0;
}


void signup_user()
{
    printf("Please enter your name.\n");
    scanf("%s",&name); // diavasma tu onomatos
    printf("Please enter your surname.\n");
    scanf("%s",&surname); // diavasma tu epwnumou
    fflush(stdin);
    while (1)
    {
    	printf("Please enter your address.\n");
    	fgets(address,100,stdin);//diavasma ths diefthhnshs
    	break;
   }
   fflush(stdin);
	while (1)
    {
   		printf("Please enter your username.\n");
    	scanf("%s",&username); //diavasma tu username
    	break;
   	}
    while (1)
    {
    	printf("Please enter your password.\n");
    	scanf("%s",&password); //diavasma tu password
    	break;
    }
}

    
    
    
  void login_user()
	{
   		char u[10],p[5];  // metavlhtes username kai password.
   		printf("Please enter your username.\n"); 
   		scanf("%s",&u);  //diavasma tu username.
  		 while (strcmp(u,username)!=0) //elegxos an to username pu ekxwrhthhke twra einai idio me to username pu diavasthke sta stoixeia.
  		{
   			scanf("%s",&u);
   		}
    	printf("Please enter your password.\n");
    	scanf("%s",&p); //diavasma tu password.
    	while (strcmp(p,password)!=0) //elegxos an to password pu ekxwrhthhke twra einai idio me to password pu diavasthke sta stoixeia.
    	{
    		scanf("%s",&p);	
		}
	}
   
   

   void calculate_cost()
	{
		
		printf("Please enter your total number of kwh.\n");
		scanf("%d",&k); //diavasma kilovatwrwn
		while (k<0) // an oi kilovatwres einai arnhtikes tote ksanadiavazontai 
		{
			printf("Please enter your correct total of kwh.\n");
			scanf("%d",&k);
		}
		printf("Enter the total square meters of your house.\n");
		scanf("%d",&s); //diavasma tetragwnikwn metrwn
		while (s<0) // an ta tetragwnika metra einai arnhtika tote tha prepei na ksanaekxwrhthei h timh tus 
		{
			printf("Please enter the square meters.\n");
			scanf("%d",&s);
		}
		if (k<=1600) //vathmhda 1 twn kwh
		{
			if (s<75) //tm<75
			{
				s1=s*0.13*116/365;
				s2=k*kwh1;
				s3=s1+s2;
			}
			else if (s<115) //tm<115
			{
				s1=s*0.26*116/365;
				s2=k*kwh1;
				s3=s2+s1;
			}
			else        //tm>=115
			{
				s1=s*0.42*116/365;
				s2=k*kwh1;
				s3=s1+s2;
			}
		}
		else if (k<=2000) //vathmhda 2 twn kwh	
		{
			if (s<75) //tm<75
			{
				s1=s*0.13*116/365;
				s2=k*kwh2;
				s3=s1+s2;
			}
			else if (s<115) //tm<115
			{
				s1=s*0.26*116/365;
				s2=k*kwh2;
				s3=s2+s1;
			}
			else //tm>=115
			{
				s1=s*0.42*116/365;
				s2=k*kwh2;
				s3=s1+s2;
			}
		}
		else //vathmhda 3 twn kwh
		{
			if (s<75) //tm<75
			{
				s1=s*0.13*116/365;
				s2=k*kwh3;
				s3=s1+s2;
			}
			else if (s<115) //tm<115
			{
				s1=s*0.26*116/365;
				s2=k*kwh3;
				s3=s2+s1;
			}
			else //tm>=115
			{
				s1=s*0.42*116/365;
				s2=k*kwh3;
				s3=s1+s2;
			}
		}
	}
   
 void payment()
	{
		int pay; //int tropos plhrwmhs 
		double x; //poso pu plhktrologei o user 
		printf("Would you like to pay with cash or a card?\nPress 1 to pay with cash or press 2 to pay with a card ( which gives you a  discount.)\n");
		scanf("%d",&pay);
		while ((pay!=1)&&(pay!=2)) //elegxos egkurothtas ths pay
		{
			scanf("%d",&pay);
		}
			if (pay==2) // an plhrwsei me karta tote..
			{
				t=0.9*s3; // teliko poso meta thn ekptwsh 10%
				printf("The total cost after the discount is : %.2f\n",t);
				printf("Please enter your card number.\n");
				scanf("%lld",&cardnum);
				while ((cardnum<1000000000000000)||(cardnum>9999999999999999)) // elegxos oti o arithmos kartas einai 16pshfios
				{
					printf("Please enter the correct card number\n");
					scanf("%lld",&cardnum);
				}
				printf("Please enter the total cost after the discount (which is %.2f)\n",t);
				scanf("%lf",&x);
			    while (fabs(x-t)>=0.01) // elegxos oti to teliko poso kai o x einai isoi
			    {
					printf("Please enter the correct amount.\n");
					scanf("%lf",&x);
		     	}
				printf("Succesful payment. \n");
			}
			else // an plhrwsei me metrhta..
			{
				cardnum=0; // den yparxei arithmos kartas
				t=s3; //teliko poso
				printf("You chose to pay with cash , your total cost is :%.2f\n",t);
				printf("In order to pay please enter the correct amount of money.\n");
				scanf("%lf",&x);
				while ((fabs(x-t)>=0.01)) // elegxos oti x kai t einai isa.
				{
					printf("In order to pay please enter the correct amount of money.\n");
					scanf("%lf",&x);
				}
				printf("Successful payment.\n");
			}
	}
  
  
  
void get_receipt() 
{//dhmiourgia apodeikshs
    float afterre; // timh meta thn ekptwsh
    afterre=0.9*s3;
 	printf("****************************************************************************************************\n");
   	printf("*                                  PERSONAL DETAILS                                                *\n");
   	printf("*                                                                                                  *\n");
   	printf("* Name                                                    %s                              	   *\n",name);
   	printf("* Surname                                                 %s                                   *\n",surname);
   	int i=0;
   	printf("* Address                                                 " );
   	int loopss=0;
   	int fores=0; // etsi h emfwleymenh if tha ginei mono mia fora 
   	while (address[i]!='\0')
   	{
   		loopss=loopss+1;
    	printf("%c",address[i++]);
    	if (fores==0)
    	{
    		if (address[loopss+1]=='\0')
    		{
    			printf("          *");
    			fores=1;
			}
		}
    }
   	printf("* Total days of consuption                                116                                      *\n");
   	printf("* Sq. Meters                                              %d                                      *\n",s);
   	printf("*                                                                                                  *\n");
   	printf("****************************************************************************************************\n");
   	printf("*                                                                                                  *\n");
   	printf("*                                  PRICING                                                         *\n");
   	printf("* Initial Cost                                            EUR %.2f                                 *\n",s3);
   	printf("* Details                                                                                          *\n");
   	printf("*        Municipial Taxes                                 EUR %.2f                                 *\n",s1);
   	printf("*        Total Charges                                    EUR %.2f                                 *\n",s2);
   	if (cardnum!=0)
   	{
   		printf("* Final Cost (after pay card payment reduction)           EUR %.2f                                 *\n",afterre);
    }
    else
    {
    	printf("* Final Cost                                              EUR %.2f                                 *\n",s3);
	}
   	printf("*                                                                                                  *\n");
   	printf("****************************************************************************************************\n");
   	printf("*                                 PAYMENT DETAILS                                                  *\n");
   	printf("*                                                                                                  *\n");
   if (cardnum!=0)
   {	
   		 printf("* Credit Card Number                                      %lld                         *\n",cardnum);
   		 printf("*                                                                                                  *\n");
   		printf("****************************************************************************************************\n");
   }
   else
   {
   		printf("* Credit Card Number                                      -                                        *\n");
   		printf("*                                                                                                  *\n");
   		printf("****************************************************************************************************\n");
    }	
}
  
  
  void exit_user()
  {
  	int temp;
	for(temp=1;temp<2;temp++)
	{
		continue;
	}
  }

void logout()
{
	while(1)
	{
		break;
	}
}


void login_admin()
{
	char correct_username_admin[5]="root"; //username admin = root
	char correct_password_admin[9]="admin123"; //password admin = admin123
	char usernameadmin[5]; //username pu tha plhktrologhthei
	char passwordadmin[9]; //password pu tha plhktrologhthei
	printf("Give username.\n");
	scanf("%s",&usernameadmin);
	while (strcmp(usernameadmin,correct_username_admin)!=0) //elegxos oti to username einai root
	{	
		scanf("%s",&usernameadmin);
    
	}
	printf("Give password.\n");
	scanf("%s",&passwordadmin);
	while (strcmp(passwordadmin,correct_password_admin)!=0)	//elegxos oti to password einai admin123
	{
		scanf("%s",&passwordadmin);
	}
}

void change_cost()
{
	int vathmhdes; // poia vathmhda dialekse o diaxeirhsths
	float neatimh; //nea timh kwh
	printf("Which number of kwh you want to change?(1,2 or 3).\n");
	scanf("%d",&vathmhdes);
	while ((vathmhdes!=1)&&(vathmhdes!=2)&&(vathmhdes!=3)) // elegxos egkurothtas
	{
		printf("You chose the wrong number,\nWhich number of kwh you want to change?(1,2 or 3).\n");
	    scanf("%d",&vathmhdes);
	}
	printf("Please type the new cost.\n");
	scanf("%f",&neatimh); //diavasma neas timhs 
	if (vathmhdes==1) // an einai sthn vathmhda 1
	{
		while ((neatimh>0.2*kwh1+kwh1)||(neatimh<kwh1*0.8)) //elegxos egkyrothtas
		{
			printf("Wrong new cost.Please type the new cost again.\n");
			scanf("%f",&neatimh);
		}
		printf("Sucessful change.\n");
		kwh1=neatimh; // allazei h timh ths kwh 1
	}
	else if (vathmhdes==2) //an einai sthn vathmhda 2
   {
		while ((neatimh>0.2*kwh2+kwh2)||(neatimh<0.8*kwh2)) //elegxos egkurothtas
		{
			printf("Wrong new cost.Please type the new cost again.\n");
			scanf("%f",&neatimh);
		}
		printf("Sucessful change.\n");
		kwh2=neatimh;		//allazei h timh ths kwh 2
   }
   else
   {
   	while ((neatimh>0.2*kwh3+kwh3)||(neatimh<0.8*kwh3)) //elegxos egkyrothtas
		{
			printf("Wrong new cost.Please type the new cost again.\n");
			scanf("%f",&neatimh);
		}
		printf("Sucessful change.\n");
		kwh3=neatimh;	// allazei h timh ths kwh 3
   }
}



void exit_admin()
{
	int temp;
	for(temp=1;temp<2;temp++)
	{
		continue;
	}	
}



void terminate()
{
    while (1)
    {
		break;
    }
}












