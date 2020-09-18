#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

struct Tname
{
    char Tname[15];
};

struct Tnumber
{
    char Tnumber[15];
};

struct elem {
    struct Tname *name , *surname, *fName;
    struct Tnumber *number;
    struct elem* next;
};

int equals(struct Tnumber* x, struct Tnumber* y)
{
    int j = 0;
    while (x->Tnumber[j] != '\0')
    {
        if (x->Tnumber[j] != y->Tnumber[j]) return 0;
        j++;
    }
    return 1;
}

int equals(struct Tname* x, struct Tname* y)
{
    int j = 0;
    while (x->Tname[j] != '\0')
    {
        if (x->Tname[j] != y->Tname[j]) return 0;
        j++;
    }
    return 1;
}

int main()
{
    struct elem* current = (struct elem*)malloc(sizeof(struct elem));
    struct elem* head = current;
    current->next = NULL;

    printf("Enter size of the book: ");
    int kol;
    char inter;
    scanf("%d%c", &kol, &inter);

    for (int i = 0; i < kol; i++)
    {
        printf("%d) name: ", i);
        struct Tname *name = (struct Tname*)malloc(sizeof(struct elem));
        int j = -1;
        while (name->Tname[j] != '\12')
        {
            j++;
            scanf("%c", &name->Tname[j]);
        }
        name->Tname[j] = '\0';

        printf("%d) surname: ", i);
        struct Tname* surname = (struct Tname*)malloc(sizeof(struct elem));
        j = 0-1;
        while (surname->Tname[j] != '\12')
        {
            j++;
            scanf("%c", &surname->Tname[j]);
        }
        surname->Tname[j] = '\0';

        printf("%d) fName: ", i);
        struct Tname* fName = (struct Tname*)malloc(sizeof(struct elem));
        j = -1;
        while (fName->Tname[j] != '\12')
        {
            j++;
            scanf("%c", &fName->Tname[j]);
        }
        fName->Tname[j] = '\0';

        printf("%d) number: ", i);
        struct Tnumber *number = (struct Tnumber*)malloc(sizeof(struct elem));
        j = -1;
        while (number->Tnumber[j] != '\12')
        {
            j++;
            scanf("%c", &number->Tnumber[j]);
        }
        number->Tnumber[j] = '\0';


        current->next = (struct elem*)malloc(sizeof(struct elem));
        current = current->next;
        current->name = name;
        current->surname = surname;
        current->fName = fName;
        current->number = number;

    }

    int exit = 0;
    do
    {
        int c;
        char enter;
        printf("(1) find number   (2) find surname   (3) exit\n");
        scanf("%d", &c);
        scanf("%c", &enter);
        switch (c)
        {
        case 1:
        {
            ///////////////////////////////////////////////////////////////////// по номеру
            printf("Enter a number: ");
            struct Tnumber* myNumber = (struct Tnumber*)malloc(sizeof(struct elem));
            int j = -1;
            while (myNumber->Tnumber[j] != '\12')
            {
                j++;
                scanf("%c", &myNumber->Tnumber[j]);
            }
            myNumber->Tnumber[j] = '\0';


            current = head;
            for (int i = 0; i < kol; i++)
            {
                current = current->next;
                int j;
                if (equals(current->number, myNumber) == 1)
                {
                    j = 0;
                    printf("%d) name: ", i);
                    while (current->name->Tname[j] != '\0')
                    {
                        printf("%c", current->name->Tname[j]);
                        j++;
                    }
                    printf("\n");

                    j = 0;
                    printf("%d) surname: ", i);
                    while (current->surname->Tname[j] != '\0')
                    {
                        printf("%c", current->surname->Tname[j]);
                        j++;
                    }
                    printf("\n");

                    j = 0;
                    printf("%d) fName: ", i);
                    while (current->fName->Tname[j] != '\0')
                    {
                        printf("%c", current->fName->Tname[j]);
                        j++;
                    }
                    printf("\n");

                    j = 0;
                    printf("%d) number: ", i);
                    while (current->number->Tnumber[j] != '\0')
                    {
                        printf("%c", current->number->Tnumber[j]);
                        j++;
                    }
                    printf("\n");
                }
            }
            ///////////////////////////////////////////////////////////////////// по номеру
        }
        break;



        case 2:
        {
            ///////////////////////////////////////////////////////////////////// по фамилии
            printf("Enter a name: ");
            struct Tname* myName = (struct Tname*)malloc(sizeof(struct elem));
            int j = -1;
            while (myName->Tname[j] != '\12')
            {
                j++;
                scanf("%c", &myName->Tname[j]);
            }
            myName->Tname[j] = '\0';


            current = head;
            for (int i = 0; i < kol; i++)
            {
                current = current->next;
                int j;
                if (equals(current->name, myName) == 1)
                {
                    j = 0;
                    printf("%d) name: ", i);
                    while (current->name->Tname[j] != '\0')
                    {
                        printf("%c", current->name->Tname[j]);
                        j++;
                    }
                    printf("\n");

                    j = 0;
                    printf("%d) surname: ", i);
                    while (current->surname->Tname[j] != '\0')
                    {
                        printf("%c", current->surname->Tname[j]);
                        j++;
                    }
                    printf("\n");

                    j = 0;
                    printf("%d) fName: ", i);
                    while (current->fName->Tname[j] != '\0')
                    {
                        printf("%c", current->fName->Tname[j]);
                        j++;
                    }
                    printf("\n");

                    j = 0;
                    printf("%d) number: ", i);
                    while (current->number->Tnumber[j] != '\0')
                    {
                        printf("%c", current->number->Tnumber[j]);
                        j++;
                    }
                    printf("\n");
                }
            }

            ///////////////////////////////////////////////////////////////////// по фамилии
        }
        break;


        case 3: exit = 1;
            break;

        default: 
            printf("Enter 1, 2 or 3");
        }
    }while (exit == 0); 

}