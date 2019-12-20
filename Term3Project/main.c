#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "phonebook.c"
int main()
{
    numberofcontacts=load();
    newnumberofcontacts=numberofcontacts;
    while(1)
    {
        printf("\nHow can I help you?\n\n1-Search\t\t2-Add\n\n3-Delete\t\t4-Modify\n\n5-Print\t\t\t6-Save\n\n\t   7-Exit\n\n");
        do {printf("\nPlease enter a number(1-7): \n");
             scanf("%d",&choice);
        if(choice<1||choice>7)
            printf("ERROR! Wrong Entry.\n");}
    while(choice<1||choice>7);
        switch (choice)
        {
        case 1:
            printf("Searching...\n");
            searchcontact(newnumberofcontacts);
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
