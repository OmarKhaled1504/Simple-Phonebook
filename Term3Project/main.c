#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char contlastname[25];
int choice,numberofcontacts,newnumberofcontacts,m,z;
struct date
{
    int day;
    int month;
    int year;
};

struct contact
{
    char Fname[25],
         Lname[25],
         PHno[20],
         address[150],
         email[100];
    struct date bd;
};
struct contact cont[100];
int load()
{
    int i=0;
    FILE *phonebook =fopen("/Users/xxxom/Desktop/Term3Project/phonebook.txt","r");
    if(phonebook!=NULL)
    {
        while(!feof(phonebook))
        {
            fscanf (phonebook, "%[^,],",&cont[i].Fname);
            if(feof(phonebook))
            {
                break;
            }
            fscanf (phonebook, "%[^,],",&cont[i].Lname);
            fscanf (phonebook, "%d-",&cont[i].bd.day);
            fscanf (phonebook, "%d-",&cont[i].bd.month);
            fscanf (phonebook, "%d,",&cont[i].bd.year);
            fscanf (phonebook, "%[^,],",&cont[i].address);
            fscanf (phonebook, "%[^,],",&cont[i].email);
            fscanf (phonebook, "%s\n",&cont[i].PHno);
            i++;
        }
        printf ("# of Contacts saved= %d\n", i);
    }
    else
    {
        printf("FILE NOT FOUND!");
        exit(0);
    }
    fclose (phonebook);
    return i;
}
int search(int x)
{
    int noofrpt=0;
    printf("Enter the last name of the contact you want to search for:");
    scanf("%s",&contlastname);
    for(m=0; m<x; m++)
    {
        if(strcasecmp(contlastname,cont[m].Lname)==0)
        {
            noofrpt++;
            printf("Contact #%d:-\n",m+1);
            printf("First name: %s\n",cont[m].Fname);
            printf("Last name: %s\n",cont[m].Lname);
            printf("Phone number: %s\n",cont[m].PHno);
            printf("Date of birth: %d/%d/%d\n",cont[m].bd.day,cont[m].bd.month,cont[m].bd.year);
            printf("E-mail: %s\n",cont[m].email);
            printf("Address: %s\n===================================================\n",cont[m].address);
            z=m;
        }
    }
    if(noofrpt!=0)
        printf("Found %d contacts with the same last name.\n ",noofrpt);
    else
        printf("No contact with this last name is found");
    return noofrpt;
}

void addcontact()
{
    printf("Enter first name:");
    scanf("%s",&cont[newnumberofcontacts].Fname);
    printf("Enter Last name:");
    scanf("%s",&cont[newnumberofcontacts].Lname);
    printf("Enter day of birth:");
    scanf("%d",&cont[newnumberofcontacts].bd.day);
    printf("Enter month of birth:");
    scanf("%d",&cont[newnumberofcontacts].bd.month);
    printf("Enter year of birth:");
    scanf("%d",&cont[newnumberofcontacts].bd.year);
    printf("Enter email:");
    scanf("%s",&cont[newnumberofcontacts].email);
    printf("Enter address:");
    scanf (" %[^\n]s",&cont[newnumberofcontacts].address);
    printf("Enter phone #:");
    scanf("%s",&cont[newnumberofcontacts].PHno);
    printf("\n\tContact added!\nPress 6 to save.\n");
}
void deletecontact()
{
    int noofrpt=0;
    char contfirstname[25];
    printf("Enter the first name of the contact you want to delete:");
    scanf("%s",&contfirstname);
    printf("Enter the last name of the contact you want to delete:");
    scanf("%s",&contlastname);
    for(m=0; m<newnumberofcontacts; m++)
    {
        if(strcasecmp(contlastname,cont[m].Lname)==0&&strcasecmp(contfirstname,cont[m].Fname)==0)
        {
            noofrpt++;
            printf("Contact number (%d):\nFirst name: %s\n",m+1,cont[m].Fname);
            printf("Last name: %s\n",cont[m].Lname);
            printf("Day of birth: %d\n",cont[m].bd.day);
            printf("Month of birth: %d\n",cont[m].bd.month);
            printf("Year of birth: %d\n",cont[m].bd.year);
            printf("E-mail: %s\n",cont[m].email);
            printf("Address: %s\n",cont[m].address);
            printf("Phone #: %s\n",cont[m].PHno);
            break;
        }
    }
    if(noofrpt==0)
        printf("No contact with this name is found");
    if(noofrpt)
    {
        do
        {
            printf("\nAre you sure you want to delete?\n1-Yes\n2-No:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");
        }
        while(choice!=1&&choice!=2);
    }

    if(choice==1)
    {
        for(int i=m; i<=newnumberofcontacts; i++)
        {
            strcpy( cont[i].Fname,cont[i+1].Fname);
            strcpy(cont[i].Lname,cont[i+1].Lname);
            cont[i].bd.day=cont[i+1].bd.day;
            cont[i].bd.month=cont[i+1].bd.month;
            cont[i].bd.year=cont[i+1].bd.year;
            strcpy(cont[i].email,cont[i+1].email);
            strcpy(cont[i].address,cont[i+1].address);
            strcpy(cont[i].PHno,cont[i+1].PHno);
        }
        newnumberofcontacts--;
        if(noofrpt)
            printf("Contact deleted successfully!\n Press 6 to save.");
    }
    else if(choice==2)
        printf("\nContact not deleted.");
}

void modifycontact(int x)
{
    int y = search(x);
    if(y!=0)
    {
        if(y>1)
        {
            printf("\n Enter number of the contact you want to modify:");
            scanf("%d",&z);
            z--;
        }
        do
        {
            printf("\nFirst name..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");
        }
        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new first name: ");
            scanf("%s",&cont[z].Fname);
        }

        do
        {
            printf("\nLast name..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");
        }
        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new last name: ");
            scanf("%s",&cont[z].Lname);
        }
        do
        {
            printf("\nDay of birth..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");
        }

        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new day of birth:");
            scanf("%d",&cont[z].bd.day);
        }
        do
        {
            printf("\nMonth of birth..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");
        }

        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new month of birth:");
            scanf("%d",&cont[z].bd.month);
        }
        do
        {
            printf("\nYear of birth..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");

        }
        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new year of birth: ");
            scanf("%d",&cont[z].bd.year);
        }
        do
        {
            printf("\nEmail..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");
        }
        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new email: ");
            scanf("%s",&cont[z].email);
        }
        do
        {
            printf("\nAddress..\n1-Modify\n2-Skip;");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");

        }
        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new address: ");
            scanf("%s",cont[z].address);
        }
        do
        {
            printf("\nPhone Number..\n1-Modify\n2-Skip:");
            scanf("%d",&choice);
            if(choice!=1&&choice!=2)
                printf("ERROR! Wrong Entry.\n");

        }
        while(choice!=1&&choice!=2);
        if(choice==1)
        {
            printf("Enter new phone no.: ");
            scanf("%s",cont[z].PHno);
        }
        printf("Contact number (%d) after modification:\nfirst name: %s\n",m+1,cont[z].Fname);
        printf("last name: %s\n",cont[z].Lname);
        printf("day of birth: %d\n",cont[z].bd.day);
        printf("month of birth: %d\n",cont[z].bd.month);
        printf("year of birth: %d\n",cont[z].bd.year);
        printf("email: %s\n",cont[z].email);
        printf("address: %s\n",cont[z].address);
        printf("phone #: %s\n\nContact modified successfully!\nPress 6 to save.",cont[z].PHno);
    }

}
void savecontact()
{
    int i;
    FILE *phonebook =fopen("/Users/xxxom/Desktop/Term3Project/phonebook.txt","w");
    for(i=0; i<newnumberofcontacts; i++)
    {
        fprintf (phonebook, "%s,", cont[i].Fname);
        fprintf (phonebook, "%s,", cont[i].Lname);
        fprintf (phonebook, "%d-", cont[i].bd.day);
        fprintf (phonebook, "%d-", cont[i].bd.month);
        fprintf (phonebook, "%d,", cont[i].bd.year);
        fprintf (phonebook, "%s,", cont[i].email);
        fprintf (phonebook, "%s,", cont[i].address);
        fprintf (phonebook, "%s\n", cont[i].PHno);
    }
    printf ("All changes have been saved\n");
    fclose (phonebook);
}
void printcontacts()
{
    do
    {
        printf("Ho do you want to sort the contacts?\n1-Last name\t2-Date of birth:");
        scanf("%d",&choice);
    }
    while(choice!=1&&choice!=2);
    if(choice==1)
    {
        printf("Sorting by last name...\n");
        sortbylname();
    }
    else
    {
        printf("Sorting by date of birth...\n");
        sortbydob();
    }
    for(m=0; m<newnumberofcontacts; m++)
    {
        printf("Contact #%d:-\n",m+1);
        printf("First name: %s\n",cont[m].Fname);
        printf("Last name: %s\n",cont[m].Lname);
        printf("Phone number: %s\n",cont[m].PHno);
        printf("Date of birth: %d/%d/%d\n",cont[m].bd.day,cont[m].bd.month,cont[m].bd.year);
        printf("E-mail: %s\n",cont[m].email);
        printf("Address: %s\n===================================================\n",cont[m].address);


    }
}
void sortbylname()
{
    struct contact temp;
    for (m = 0; m < newnumberofcontacts-1; m++)
    {


        for (z = 0; z < newnumberofcontacts-m-1; z++)
        {

            if (strcasecmp(cont[z].Lname,cont[z+1].Lname)>0)
            {
                temp=cont[z];
                cont[z]=cont[z+1];
                cont[z+1]=temp;

            }

        }
    }
}
void sortbydob()
{
    struct contact temp;
    for (m = 0; m < newnumberofcontacts-1; m++)
    {


        for (z = 0; z < newnumberofcontacts-m-1; z++)
        {

            if (cont[z].bd.year > cont[z+1].bd.year)
            {
                temp=cont[z];
                cont[z]=cont[z+1];
                cont[z+1]=temp;

            }
            else if(cont[z].bd.year == cont[z+1].bd.year)
            {
                if(cont[z].bd.month > cont[z+1].bd.month)
                {
                    temp=cont[z];
                    cont[z]=cont[z+1];
                    cont[z+1]=temp;
                }
                else if(cont[z].bd.month == cont[z+1].bd.month)
                {
                    if(cont[z].bd.day > cont[z+1].bd.day)
                    {
                        temp=cont[z];
                        cont[z]=cont[z+1];
                        cont[z+1]=temp;

                    }

                }

            }
        }
    }
}
int main()
{
    numberofcontacts=load();
    newnumberofcontacts=numberofcontacts;
    while(1)
    {
        printf("\nHow can I help you?\n\n1-Search\t\t2-Add\n\n3-Delete\t\t4-Modify\n\n5-Print\t\t\t6-Save\n\n\t   7-Exit\n\n  Please enter a number(1-7): ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Searching...\n");
            search(newnumberofcontacts);
            break;
        case 2:
            printf("Adding...\n");
            addcontact();
            newnumberofcontacts++;
            break;
        case 3:
            printf("Deleting...\n");
            deletecontact();
            break;
        case 4:
            printf("Modifying...\n");
            modifycontact(newnumberofcontacts);
            break;
        case 5:
            printcontacts();
            break;
        case 6:
            printf("Saving...\n");
            savecontact();
            break;
        case 7:
            do
            {
                printf("Are you sure you want to exit? ALL UNSAVED CHANGES WILL BE DELETED!\n1-Yes\t2-No\n");
                scanf("%d",&choice);
                if(choice==1)
                    exit(0);
                else if(choice==2)
                    break;
                else
                {
                    printf("ERROR! Wrong Entry.\n");
                }
            }
            while(choice!=1&&choice!=2);
        }
    }
    return 0;
}

