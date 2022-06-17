#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct date
{
	int day;
	int month;
	int year;
};
void edit_budget();
void expence();
void track_exp();
void budget_status();
int main ()
{
	int choice;
	while(1)
	{
		FILE *rem;
		char buffer[20];
		printf("****************************** Easy Track ***********************************\n\n");
		rem=fopen("remain.txt","r");
		fgets(buffer,20,rem);
		if (atoi(buffer)<=1000)
		{
			printf("please Add more budget!!!\n\n");
		}
		printf("1.Add budget.\n2.Enter Expence.\n3.Track Expence.\n4.Check budget status.\n5.Exit.\n");
		printf("Enter choise: ");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
			edit_budget();
		else if (choice == 2)
			expence();
		else if (choice==3)
			track_exp();
		else if (choice==4)
			budget_status();
		else if (choice==5)
			break;
		else
			printf("Invalid input\n");
			
	}
}
void edit_budget()
{
	FILE *budg,*rem;
	int amount,ramount,re;
	char buffer[50],buffer1[50];
	printf("****************************** Easy Track ***********************************\n\n");
	while(1)
	{
		printf("Enter amount:");
		scanf("%d",&amount);
		if (amount<=10000000)
		{
			break;
		}
	}
	budg=fopen("budget.txt","r+");
	rem=fopen("remain.txt","r+");
	fgets(buffer,50,budg);
	fgets(buffer1,50,rem);
	ramount=atoi(buffer);
	ramount+=amount;
	itoa(ramount,buffer,10);
	fseek(budg,0,SEEK_SET);
	fputs(buffer,budg);
	re=atoi(buffer1)+amount;
	itoa(re,buffer1,10);
	fseek(rem,0,SEEK_SET);
	fputs(buffer1,rem);
	fclose(budg);
	fclose(rem);
	printf("Amount added successfully\n");
	sleep(1);
	system("cls");
}
void expence()
{
	struct date tdate;
	FILE *Hel,*food,*edu,*oth,*budg,*exp,*rem;
	char buffer[50],buffer1[50],buffer2[50];
	int amount,expence,choice,iamount,re;
	budg=fopen("budget.txt","r+");
	rem=fopen("remain.txt","r+");
	exp=fopen("expence.txt","r+");
	fgets(buffer,50,budg);
	fgets(buffer1,50,rem);
	fgets(buffer2,50,exp);
	amount=atoi(buffer);
	re=atoi(buffer1);
	expence=atoi(buffer2);
	fclose (rem);
	while(1)
	{
		printf("****************************** Easy Track ***********************************\n\n");
		printf("Enter today's date (dd/mm/yyyy):");
		scanf("%d/%d/%d",&tdate.day,&tdate.month,&tdate.year);
		system("cls");
		if ((tdate.day>28 && tdate.month==2) || (tdate.day>30 && tdate.month%2==0))
		{
			printf("Invalid date!\n");
		}
		else
		{
			break;
		}
		sleep(1);
		system("cls");
	}
	while (1)
	{
		printf("****************************** Easy Track ***********************************\n\n");
		printf("1.Health.\n2.Food.\n3.Education.\n4.Other.\n5.Exit.\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
		{
			while (1)
			{
				printf("Enter amount:");
				scanf("%d",&iamount);
				if (re>iamount)
				{
					break;
				}
				else
				{
					printf("Enter amount greater that your budget!!\n");
				}
			}
			expence+=iamount;
			re-=iamount;
			Hel=fopen("health.txt","r+");
			fseek(Hel,0,SEEK_END);
			fprintf(Hel,"%d/%d/%d\n",tdate.day,tdate.month,tdate.year);
			fprintf(Hel,"%d\n",iamount);
			fclose(Hel);
			itoa(expence,buffer2,10);
			itoa(re,buffer1,10);
			fseek(exp,0,SEEK_SET);
			fprintf(exp,"%s",buffer2);
			rem=fopen("remain.txt","w");
			fseek(rem,0,SEEK_SET);
			fprintf(rem,"%s",buffer1);
			fclose(rem);
		}
		else if (choice==2)
		{
			while (1)
			{
				printf("Enter amount:");
				scanf("%d",&iamount);
				if (re>iamount)
				{
					break;
				}
				else
				{
					printf("Enter amount greater that your budget!!\n");
				}
			}
			expence+=iamount;
			re-=iamount;
			food=fopen("food.txt","r+");
			fseek(food,0,SEEK_END);
			fprintf(food,"%d/%d/%d\n",tdate.day,tdate.month,tdate.year);
			fprintf(food,"%d\n",iamount);
			fclose(food);
			itoa(expence,buffer2,10);
			itoa(re,buffer1,10);
			fseek(exp,0,SEEK_SET);
			fprintf(exp,"%s",buffer2);
			rem=fopen("remain.txt","w");
			fseek(rem,0,SEEK_SET);
			fprintf(rem,"%s",buffer1);
			fclose(rem);
		}
		else if (choice==3)
		{
			while (1)
			{
				printf("Enter amount:");
				scanf("%d",&iamount);
				if (re>iamount)
				{
					break;
				}
				else
				{
					printf("Enter amount greater that your budget!!\n");
				}
			}
			expence+=iamount;
			re-=iamount;
			edu=fopen("education.txt","r+");
			fseek(edu,0,SEEK_END);
			fprintf(edu,"%d/%d/%d\n",tdate.day,tdate.month,tdate.year);
			fprintf(edu,"%d\n",iamount);
			fclose(edu);
			itoa(expence,buffer2,10);
			itoa(re,buffer1,10);
			fseek(exp,0,SEEK_SET);
			fprintf(exp,"%s",buffer2);
			rem=fopen("remain.txt","w");
			fseek(rem,0,SEEK_SET);
			fprintf(rem,"%s",buffer1);
			fclose(rem);
		}
		else if (choice==4)
		{
			while (1)
			{
				printf("Enter amount:");
				scanf("%d",&iamount);
				if (re>iamount)
				{
					break;
				}
				else
				{
					printf("Enter amount greater that your budget!!\n");
				}
			}
			expence+=iamount;
			re-=iamount;
			oth=fopen("other.txt","r+");
			fseek(oth,0,SEEK_END);
			fprintf(oth,"%d/%d/%d\n",tdate.day,tdate.month,tdate.year);
			fprintf(oth,"%d\n",iamount);
			fclose(oth);
			itoa(expence,buffer2,10);
			itoa(re,buffer1,10);
			fseek(exp,0,SEEK_SET);
			fprintf(exp,"%s",buffer2);
			rem=fopen("remain.txt","w");
			fseek(rem,0,SEEK_SET);
			fprintf(rem,"%s",buffer1);
			fclose(rem);
		}
		else if (choice==5)
		{
			break;
		}
		else
		{
			printf("Invalid input\n");
		}
		system("cls");
	}
	fclose(exp);
	fclose(budg);
}
void track_exp()
{
	FILE *Hel,*food,*edu,*oth;
	int choice;
	char buffer[15];
	while(1)
	{
		printf("****************************** Easy Track ***********************************\n\n");
		printf("1.Health.\n2.Food.\n3.Education.\n4.Other.\n5.Exit.\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		system("cls");
		if (choice==1)
		{
			printf("Health Expence Record\n----------------------\n\n");
			Hel=fopen("health.txt","r");
			while (fgets(buffer,15,Hel)!=NULL)
			{
				printf("%s",buffer);
			}
			fclose(Hel);
			sleep(3);
		}
		else if (choice==2)
		{
			printf("Food Expence Record\n----------------------\n\n");
			food=fopen("food.txt","r");
			while (fgets(buffer,15,food)!=NULL)
			{
				printf("%s",buffer);
			}
			fclose(food);
			sleep(3);
		}
		else if (choice==3)
		{
			printf("Education Expence Record\n----------------------\n\n");
			edu=fopen("education.txt","r");
			while (fgets(buffer,15,edu)!=NULL)
			{
				printf("%s",buffer);
			}
			fclose(edu);
			sleep(3);
		}
		else if (choice==4)
		{
			printf("Other Expence Record\n----------------------\n\n");
			oth=fopen("other.txt","r");
			while (fgets(buffer,15,oth)!=NULL)
			{
				printf("%s",buffer);
			}
			fclose(oth);
			sleep(3);
		}
		else if (choice==5)
		{
			break;
		}
		else
		{
			printf("Invalid input.\n");
		}
		system("cls");
	}
}
void budget_status()
{
	FILE *rem,*budg,*exp;
	char buffer[20];
	budg=fopen("budget.txt","r");
	rem=fopen("remain.txt","r");
	exp=fopen("expence.txt","r");
	printf("The Total Budget is:");
	while (fgets(buffer,20,budg)!=NULL)
	{
		printf("%s",buffer);
	}
	printf("PKR\n");
	printf("The Total expance is:");
	while (fgets(buffer,20,exp)!=NULL)
	{
		printf("%s",buffer);
	}
	printf("PKR\n");
	printf("The Remaining balance is:");
	while (fgets(buffer,20,rem)!=NULL)
	{
		printf("%s",buffer);
	}
	printf("PKR\n");
	fclose(rem);
	fclose(exp);
	fclose(budg);
	sleep(4);
	system("cls");
}

