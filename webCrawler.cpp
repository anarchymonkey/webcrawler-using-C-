#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#define HASH_SIZE 100
#define URL_LENGTH 1000
#define SEED_URL "https://www.youtube.com/results?search_query=codestien"
#define MAX_URL_PER_PAGE 10
#define INTERVAL_TIME 10
/* FUNCTION TO INSERT INTO FILES */
using namespace std;
void insertIntoFILE()
{
    FILE *inputFile;
    inputFile =fopen("temp.txt","w");

    if (inputFile==NULL)
    {
        fprintf(stderr," ERROR OPENING FILE ");
    }
    else
    {
        fprintf(inputFile,"FILE OPENED %s",system("curl https://www.youtube.com/results?search_query=codestien > temp.txt"));
    }
}

/* ********************************************************* */

/* FUNCTION TO EXTRACT URLS FROM THE FILE */
void extractURLS()
{
    FILE *extractData;
    extractData = fopen("temp.txt","r");
    char ch;

    if(extractData == NULL)
    {
        printf("INSERT A HTML PAGE");
        exit(0);
    }
    else
    {
        ch = fgetc(extractData);

        while(ch!= EOF)
        {
            if(ch!='<' && ch!='>')
            {
                cout<<ch<<endl;
            }
            ch = fgetc(extractData);
        }
    }

}
/* END OF EXTRACT FUNCTION */
int main(int argc,char *argv[]) // command line arguments
{
    printf("PROGRAMME NAME IS %s \n",argv[0]);
    if(argc >2)
    {
        for(int i = 1 ; i<argc; i++)
        {
            printf("\nThe arguments supplied are %s\n",argv[i]);
        }
    }

    else
    {
        printf("THE PROGRAMME CONTAINS NO ARGUMENTS");
    }
	printf("%s",argv[1]);
		
	if(strcmp(argv[1],"https://www.youtube.com/results?search_query=codestien")==0)
	{
		printf("valid url");
		if(strcmp(argv[2],"2")==0)
		{	
		     printf("valid depth");
			if(strcmp(argv[3],"files")==0)
			{
				printf("valid folder");
			}
		}
	}
    //insertIntoFILE();
    //extractURLS();
    return 0;
}
