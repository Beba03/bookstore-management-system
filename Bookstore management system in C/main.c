#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    char month[5];
    char year[5];
} DATE;

typedef struct
{
    char ISBN[15];
    char Title[100];
    char Author_Name[100];
    char quantity[100];
    char price[100];
    DATE publication_date;
} BOOKS;

typedef struct
{
    char user[100];
    char pass[100];
} CREDENTIALS;

char line[256];
BOOKS book[100];
int count=0;
FILE *fpbook;

void LOAD()
{
    printf("\n");
    fpbook=fopen("books.txt","r");
    while (fgets(line,sizeof(line),fpbook)!=NULL)
        printf("%s",line);

    fclose(fpbook);
}

void MENU()
{
    printf("\n\n1)ADD \n2)DELETE\n3)MODIFY \n4)SEARCH \n5)ADVANCED SEARCH \n6)PRINT \n7)SAVE \n8)QUIT \n");
    int x,k=1;
    char y[5];
    printf("\n");
    gets(line);
    x = atoi(line);
    if(strlen(line) == 1 && x != 0)
    {
        switch(x)
    {
    case 1:
        printf("\nADD\n");
        ADD();
        MENU();
        break;
    case 2:
        printf("\nDELETE\n");
        DELETE();
        MENU();
        break;
    case 3:
        printf("\nMODIFY\n");
        MODIFY();
        MENU();
        break;
    case 4:
        printf("\nSEARCH\n");
        QUERY();
        MENU();
        break;
    case 5:
        printf("\nADVANCED SEARCH\n");
        ADVANCED_SEARCH();
        MENU();
        break;
    case 6:
        printf("\nPRINT\n");
        SORT();
        MENU();
        break;
    case 7:
        SAVE();
        MENU();
        break;
    case 8:
        while(k!=0)
        {
            printf("\a\t\t  Warning!\n\tAll Changes Will Be Discarded\n\tAre you sure you want to Quit? \n\t1)Yes,Quit 2)No,Return to Menu\n");
            gets(y);
            if(strcmp(y,"1") == 0)
            {
                k=0;
                break;
            }

            else if (strcmp(y,"2") == 0)
            {
                k=0;
                MENU();
            }
            else
            {
                printf("Invalid Input\n");
            }
        }
        if(k==0)
        {
            return;
        }
    default :
        printf("\nInvalid Input\n");
        MENU();
        break;

    }
    }
    else
    {
        printf("\nInvalid Input\n");
        MENU();
    }

}

void ADD()
{
    int i=count;
    int y;
    long long x;

    printf("Enter The Book's ISBN Here: ");
    gets(line);
    if(strlen(line)==13)
        x=atoll(line);
    while((strlen(line)!= 13) || !(x > 999999999999 && x < 10000000000000))
    {
        printf("Invalid ISBN");
        printf("\nEnter The Book's ISBN Here: ");
        gets(line);
        x = atoll(line);
    }
    strcpy(book[i].ISBN,line);

    printf("Enter The Book's Title Here: ");
    gets(book[i].Title);
    printf("Enter The Author's Name Here: ");
    gets(book[i].Author_Name);
    printf("Enter The Quantity Of The Books Here: ");
    gets(line);
    for(int j=0; j<strlen(line);)
    {
        if(isdigit(line[j])==0)
        {
            printf("Invalid Quantity\n");
            printf("Enter The Quantity Of The Books Here: ");
            gets(line);
            j=0;
        }
        else
            j++;
    }
    strcpy(book[i].quantity,line);

    printf("Enter The Book's Price Here: ");
    gets(line);
    int flag = 0;

    for(int j=0; j<strlen(line);)
    {
        if(isdigit(line[j])==1)
        {
            j++;
        }
        else
        {

            if(line[j]=='.' && flag==0)
            {
                flag=1;
                j++;
            }
            else
            {
                if(line[j]=='.' && flag==1)
                {
                    printf("Invalid Price\n");
                    printf("Enter The Price Of The Book Here: ");
                    gets(line);
                    j=0;
                    flag=0;
                }
                else
                {
                    printf("Invalid Price\n");
                    printf("Enter The Price Of The Book Here: ");
                    gets(line);
                    j=0;
                    flag=0;
                }
            }
        }
    }
    strcpy(book[i].price,line);

    printf("Enter The Book's Publication Month Here: ");
    gets(line);
    y=atoi(line);
    while(!(y > 0 && y < 13))
    {
        printf("Invalid Month");
        printf("\nEnter The Book's Publication Month Here: ");
        gets(line);
        y = atoi(line);
    }
    strcpy(book[i].publication_date.month,line);

    printf("Enter The Book's Publication Year Here: ");
    gets(line);
    y=atoi(line);
    while(!(y > 0 && y < 2023))
    {
        printf("Invalid Year");
        printf("\nEnter The Book's Publication Year Here: ");
        gets(line);
        y = atoi(line);
    }
    strcpy(book[i].publication_date.year,line);

    count++;
}

void DELETE()
{
    int i,f=0;
    char n[15];
    printf("\nEnter The ISBN Of The Book To Delete : ");
    gets(n);

    for(i=0 ; i < count ; i++)
    {

        while (strcmp(n,book[i].ISBN)== 0)
        {
            f = 1;
            printf("File Deleted");

            while(i < count)
            {
                strcpy(book[i].ISBN,book[i+1].ISBN);

                strcpy(book[i].Title,book[i+1].Title);

                strcpy(book[i].Author_Name,book[i+1].Author_Name);

                strcpy(book[i].quantity,book[i+1].quantity);

                strcpy(book[i].price,book[i+1].price);

                strcpy(book[i].publication_date.month,book[i+1].publication_date.month);

                strcpy(book[i].publication_date.year,book[i+1].publication_date.year);
                i++;
            }
        }
    }
    while(f == 0)
    {
        printf("Invalid ISBN");
        printf("\nEnter The ISBN Of The Book To Delete : ");
        gets(n);
        for(i=0 ; i < count ; i++)
        {

            while (strcmp(n,book[i].ISBN)== 0)
            {
                f = 1;
                printf("File Deleted\n");

                while(i < count)
                {
                    strcpy(book[i].ISBN,book[i+1].ISBN);

                    strcpy(book[i].Title,book[i+1].Title);

                    strcpy(book[i].Author_Name,book[i+1].Author_Name);

                    strcpy(book[i].quantity,book[i+1].quantity);

                    strcpy(book[i].price,book[i+1].price);

                    strcpy(book[i].publication_date.month,book[i+1].publication_date.month);

                    strcpy(book[i].publication_date.year,book[i+1].publication_date.year);
                    i++;
                }
            }
        }
    }
    count-- ;
}

void MODIFY()
{
    char n[15];
    int i, f=0 ;
    int y;
    long long x;
    printf("Enter The ISBN Of The Book To Modify : ");
    gets(n);

    for(i=0 ; i < count ; i++)
    {

        while (strcmp(n,book[i].ISBN)== 0)
        {
            f = 1;

            printf("Enter The Book's ISBN Here: ");
            gets(line);
            if(strlen(line)==13)
                x=atoll(line);
            while((strlen(line)!= 13) || !(x > 999999999999 && x < 10000000000000))
            {
                printf("Invalid ISBN");
                printf("\nEnter The Book's ISBN Here: ");
                gets(line);
                x = atoll(line);
            }
            strcpy(book[i].ISBN,line);

            printf("Enter The Book's Title Here: ");
            gets(book[i].Title);
            printf("Enter The Author's Name Here: ");
            gets(book[i].Author_Name);

            printf("Enter The Quantity Of The Books Here: ");
            gets(line);
            for(int j=0; j<strlen(line);)
            {
                if(isdigit(line[j])==0)
                {
                    printf("Invalid Quantity\n");
                    printf("Enter The Quantity Of The Books Here: ");
                    gets(line);
                    j=0;
                }
                else
                    j++;
            }
            strcpy(book[i].quantity,line);

            printf("Enter The Book's Price Here: ");
            gets(line);
            int flag = 0;

            for(int j=0; j<strlen(line);)
            {
                if(isdigit(line[j])==1)
                {
                    j++;
                }
                else
                {

                    if(line[j]=='.' && flag==0)
                    {
                        flag=1;
                        j++;
                    }
                    else
                    {
                        if(line[j]=='.' && flag==1)
                        {
                            printf("Invalid Price\n");
                            printf("Enter The Price Of The Book Here: ");
                            gets(line);
                            j=0;
                            flag=0;
                        }
                        else
                        {
                            printf("Invalid Price\n");
                            printf("Enter The Price Of The Book Here: ");
                            gets(line);
                            j=0;
                            flag=0;
                        }
                    }
                }
            }
            strcpy(book[i].price,line);

            printf("Enter The Book's Publication Month Here: ");
            gets(line);
            y=atoi(line);
            while(!(y > 0 && y < 13))
            {
                printf("Invalid Month");
                printf("\nEnter The Book's Publication Month Here: ");
                gets(line);
                y = atoi(line);
            }
            strcpy(book[i].publication_date.month,line);

            printf("Enter The Book's Publication Year Here: ");
            gets(line);
            y=atoi(line);
            while(!(y > 0 && y < 2023))
            {
                printf("Invalid Year");
                printf("\nEnter The Book's Publication Year Here: ");
                gets(line);
                y = atoi(line);
            }
            strcpy(book[i].publication_date.year,line);
        }
    }

    while(f == 0)
    {
        printf("Invalid ISBN");
        printf("\nEnter The ISBN Of The Book To Modify : ");
        gets(n);
        for(i=0 ; i < count ; i++)
        {

            while (strcmp(n,book[i].ISBN)== 0)
            {
                f = 1;

                printf("Enter The Book's ISBN Here: ");
                gets(line);
                if(strlen(line)==13)
                    x=atoll(line);
                while((strlen(line)!= 13) || !(x > 999999999999 && x < 10000000000000))
                {
                    printf("Invalid ISBN");
                    printf("\nEnter The Book's ISBN Here: ");
                    gets(line);
                    x = atoll(line);
                }
                strcpy(book[i].ISBN,line);

                printf("Enter The Book's Title Here: ");
                gets(book[i].Title);
                printf("Enter The Author's Name Here: ");
                gets(book[i].Author_Name);

                printf("Enter The Quantity Of The Books Here: ");
                gets(line);
                for(int j=0; j<strlen(line);)
                {
                    if(isdigit(line[j])==0)
                    {
                        printf("Invalid Quantity\n");
                        printf("Enter The Quantity Of The Books Here: ");
                        gets(line);
                        j=0;
                    }
                    else
                        j++;
                }
                strcpy(book[i].quantity,line);

                printf("Enter The Book's Price Here: ");
                gets(line);
                int flag = 0;

                for(int j=0; j<strlen(line);)
                {
                    if(isdigit(line[j])==1)
                    {
                        j++;
                    }
                    else
                    {

                        if(line[j]=='.' && flag==0)
                        {
                            flag=1;
                            j++;
                        }
                        else
                        {
                            if(line[j]=='.' && flag==1)
                            {
                                printf("Invalid Price\n");
                                printf("Enter The Price Of The Book Here: ");
                                gets(line);
                                j=0;
                                flag=0;
                            }
                            else
                            {
                                printf("Invalid Price\n");
                                printf("Enter The Price Of The Book Here: ");
                                gets(line);
                                j=0;
                                flag=0;
                            }
                        }
                    }
                }
                strcpy(book[i].price,line);

                printf("Enter The Book's Publication Month Here: ");
                gets(line);
                y=atoi(line);
                while(!(y > 0 && y < 13))
                {
                    printf("Invalid Month");
                    printf("\nEnter The Book's Publication Month Here: ");
                    gets(line);
                    y = atoi(line);
                }
                strcpy(book[i].publication_date.month,line);

                printf("Enter The Book's Publication Year Here: ");
                gets(line);
                y=atoi(line);
                while(!(y > 0 && y < 2023))
                {
                    printf("Invalid Year");
                    printf("\nEnter The Book's Publication Year Here: ");
                    gets(line);
                    y = atoi(line);
                }
                strcpy(book[i].publication_date.year,line);
            }
        }
    }
}

void QUERY()
{
    int n=count;
    int i, flag=0;
    char isbn[100];
    printf("\nEnter the ISBN for required book: ");
    gets(isbn);
    for(i=0 ; i<n ; i++)
    {
        if (strcmp(isbn,book[i].ISBN) == 0)
        {
            printf("\nISBN: %s",book[i].ISBN);
            printf("\nTitle: %s",book[i].Title);
            printf("\nAuthor: %s",book[i].Author_Name);
            printf("\nQuantity: %s",book[i].quantity);
            printf("\nPrice: %s",book[i].price);
            printf("\nPublished: %s-%s\n\n",book[i].publication_date.month,book[i].publication_date.year);
            flag = 1 ;
            break ;
        }
    }
    if(flag == 0)
        printf("ISBN not found\n\n");
}

void SAVE()
{
    int i=0;
    fpbook=fopen("books.txt","w");
    while(i<count)
    {
        fprintf(fpbook,"%s,%s,%s,%s,%s,%s-%s\n",book[i].ISBN,book[i].Title,book[i].Author_Name,book[i].quantity,book[i].price,book[i].publication_date.month,book[i].publication_date.year);
        i++;
    }
    fclose(fpbook);
    printf("\nFile Saved\n");
}

void ADVANCED_SEARCH()
{
    char keyword[30];
    printf("Enter Keyword : ");
    gets(keyword);
    int i, flag = 0 ;
    for(i=0 ; i<count ; i++)
    {
        if(strstr(book[i].Title,keyword) > 0)
        {
            printf("ISBN : %s",book[i].ISBN);
            printf("\nTitle : %s",book[i].Title);
            printf("\nAuthor : %s",book[i].Author_Name);
            printf("\nQuantity : %s",book[i].quantity);
            printf("\nPrice : %s",book[i].price);
            printf("\nPublished : %s - %s\n",book[i].publication_date.month,book[i].publication_date.year);
            printf("\n");
            flag = 1 ;
        }
    }
    if(flag == 0)
    {
        printf("No matches found\n");
    }
}

void SORT()
{
    char y[5];
    int x;
    printf("Enter sort type : ");
    printf("\n1)Title");
    printf("\n2)Date");
    printf("\n3)Price\n");
    gets(line);
    x = atoi(line);

    if(x == 1)
    {
        SortByTitle();
        Print();
    }
    else if(x == 2)
    {
        SortByDate();
        Print();
    }
    else if(x == 3)
    {
        SortByPrice();
        Print();
    }
    else
    {
        printf("Invalid input\n");
    }
}
void SortByTitle()
{
    printf("\nSort by Title\n");
    int i,j ;
    BOOKS temp ;
    for(j = 0 ; j < count-1; j++)
    {
        for(i = 0 ; i<count-j-1 ; i++)
        {
            if (strcmp(book[i].Title,book[i+1].Title) == 1)
            {
                temp = book[i] ;
                book[i] = book[i+1] ;
                book[i+1] = temp ;
            }
        }
    }
}
void  SortByDate()
{
    printf("\nSort by Date\n");
    int i,j ;
    BOOKS temp ;
    for(j = 0 ; j < count-1 ; j++)
    {
        for(i = 0 ; i < count-j-1 ; i++)
        {
            if (strcmp(book[i].publication_date.year,book[i+1].publication_date.year) == -1)
            {
                temp = book[i] ;
                book[i] = book[i+1] ;
                book[i+1] = temp ;
            }
            else if(strcmp(book[i].publication_date.year,book[i+1].publication_date.year) == 0)
            {
                if(strcmp(book[i].publication_date.month,book[i+1].publication_date.month) == -1)
                {
                    temp = book[i] ;
                    book[i] = book[i+1] ;
                    book[i+1] = temp ;
                }
            }
        }
    }
}
void  SortByPrice()
{
    float x=0,y=0;
    printf("\nSort by Price\n");
    int i,j ;
    BOOKS temp ;
    for(j = 0 ; j < count-1 ; j++)
    {
        for(i = 0 ; i < count-j-1 ; i++)
        {
            x=atof(book[i].price);
            y=atof(book[i+1].price);
            if (x>y)
            {
                temp = book[i] ;
                book[i] = book[i+1] ;
                book[i+1] = temp ;
            }
        }
    }
}
void Print()
{
    int i ;
    for(i=0; i<count ; i++)
    {
        printf("ISBN : %s",book[i].ISBN);
        printf("\nTitle : %s",book[i].Title);
        printf("\nAuthor : %s",book[i].Author_Name);
        printf("\nQuantity : %s",book[i].quantity);
        printf("\nPrice : %s",book[i].price);
        printf("\nPublished : %s - %s",book[i].publication_date.month,book[i].publication_date.year);
        printf("\n\n");

    }
}

int main()
{
    fpbook=fopen("books.txt","a+");
    fclose(fpbook);
    CREDENTIALS a;
    CREDENTIALS b;
    FILE *fptr = fopen("credentials.txt","r");
    while(!feof(fptr))
        fscanf(fptr,"%s %s",b.user,b.pass);

    printf("Enter THe Username Here : ");
    gets(a.user);
    printf("Enter THe Password Here : ");
    gets(a.pass);

    int i=strcmp(a.user,b.user);
    int j=strcmp(a.pass,b.pass);

    while (!(i==0&&j==0))
    {
        printf("Wrong Username Or Password\n");
        printf("Enter THe Username Here : ");
        gets(a.user);
        printf("Enter THe Password Here : ");
        gets(a.pass);
        i=strcmp(a.user,b.user);
        j=strcmp(a.pass,b.pass);
    }

    fpbook=fopen("books.txt","r");
    fgets(line,256,fpbook);
    /*Inserting Book's Information in Array*/
    while(!feof(fpbook))
    {
        char *token = strtok(line,",");
        strcpy(book[count].ISBN,token);

        token = strtok(NULL, ",");
        strcpy(book[count].Title,token);

        token = strtok(NULL, ",");
        strcpy(book[count].Author_Name,token);

        token = strtok(NULL, ",");
        strcpy(book[count].quantity,token);

        token = strtok(NULL, ",");
        strcpy(book[count].price,token);

        token = strtok(NULL, "-");
        strcpy(book[count].publication_date.month,token);

        token = strtok(NULL,"\n");
        strcpy(book[count].publication_date.year,token);
        count++;
        fgets(line,256,fpbook);
    }
    fclose(fpbook);
    LOAD();
    MENU();
}
