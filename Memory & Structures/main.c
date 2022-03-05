#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_RECORDS 100

int Menu();
void addRecord();
void printNumberOfRecords();
void getDBSize();
void printRecords();
void accessCounter();
void deleteRecord();

struct Personal_recored
 {
    char First_name[10];
    char Last_name[10];
    char Date_of_Birth[10];
    char ID_Number[6];
}

typedef Personal_recored;
Personal_recored *adder[MAX_RECORDS];
int lastRecordIndex = 0;
int size_DB = 0;
int counter = 0;

void addRecord()
{
    Personal_recored *person = malloc(sizeof(Personal_recored));
    adder[lastRecordIndex] = person;

    printf("Enter First Name: ");
    scanf("%s", person->First_name);

    printf("Enter Last Name: ");
    scanf("%s", person->Last_name);

    printf("Enter DOB: ");
    scanf("%s", person->Date_of_Birth);

    printf("Enter Id Number: ");
    scanf("%s", person->ID_Number);

    printf("Record Added!!\n\n");
    lastRecordIndex++;
    counter++;
    size_DB = sizeof(Personal_recored) * (lastRecordIndex+1);
}

void printNumberOfRecords()
{
    printf("Total Number Of Records: %d\n", lastRecordIndex);
}

void getDBSize()
{
    int data_Size;
    data_Size = sizeof(Personal_recored)*(lastRecordIndex+1);
    printf("Total Database Size: %d\n", data_Size);
}

void printRecords()
{
    int i;
    if(lastRecordIndex==0)
    {
        printf("No Record Found!!\n");
        counter++;
    }
    else
    {
        printf("Personal Record\n");
        printf("-------------------\n");
        for(i = 0; i < lastRecordIndex; i++)
        {
            printf("%s | %s | %s | %s \n",adder[i]->First_name, adder[i]->Last_name, adder[i]->Date_of_Birth, adder[i]->ID_Number);
            counter++;
        }
    }
}

void accessCounter()
{
    printf("Number Of Accesses: %d\n",counter-1);
}

void deleteRecord()
{
    free(adder[lastRecordIndex-1]);
    printf("Record Deleted!!\n");
    counter++;
    lastRecordIndex--;
}

int Menu()
{
    int choice=0;
    do
    {
        printf("\n");
        printf("MENU:\n");
        printf("----\n");
        printf("1-Print All Records\n");
        printf("2-Print Number Of Records\n");
        printf("3-Print Size Of Database\n");
        printf("4-Add Record\n");
        printf("5-Delete Record\n");
        printf("6-Print Number Of Accesses To Database\n");
        printf("0-Exit\n");

        printf("\nYour Choice: ");
        scanf("%d",&choice);

        if(choice==0)
        {
            exit(0);
        }
    }
    while(choice>6||choice<0);
    printf("\n");

    return choice;
}

int main() {

    int choice=0;
    //lastRecordIndex = -1;

    while(1)
    {
        choice=Menu();
        switch (choice)
        {
            case 1:
            {
                printRecords();
                break;
            }
            case 2:
            {
                printNumberOfRecords();
                break;
            }
            case 3:
            {
                getDBSize();
                break;
            }
            case 4:
            {
                addRecord();
                break;
            }
            case 5:
            {
                deleteRecord();
                break;
            }
            case 6:
            {
                accessCounter();
                break;
            }
            default:
            {
                printf("Invalid Response\n");
                break;
            }
        }
    }
}
