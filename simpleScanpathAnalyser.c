/*
    Creator: Yagmur Saygili / School Assigment: Algorithms

    For explanation about the project look at the README file

    Inline comments are added.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Scanpath
{
	char scanpath[100];
	struct scanpath *next;
};

struct Scanpath* createHeadList();
struct Scanpath* newNode(char *);
char find_most_repated_AOI(char *);
char get_most_common(char *);

struct Scanpath* createScanpathList(char filename[])
{
	struct Scanpath* head = createHeadList();
	struct Scanpath* tail = (struct Scanpath*)malloc(sizeof(struct Scanpath));

	tail = head;

	FILE *fp = fopen(filename,"r");

	if (fp==NULL)
	{
		printf("Error! COuld not open the file %s",filename);
		return 1;
	}

	int maxScanpathLength = 100;
	char line[maxScanpathLength];

	while(fgets(line, maxScanpathLength, fp))
	{

		// I will load the scanpaths into linked lists directly in the loop so I wont need to create 2D array to keep all the scanpaths
		struct scanpath* newnode = newNode(line);
		tail->next = newnode;
		tail = tail->next;
	}

	printf("\nFile reading and writing to the nodes is complete succesfully \n");

	fclose(fp);

	return head;
}

int main()
{
	char p_with_autism[100];
	char p_without_autism[100];
	char pattern[50];

	printf("Enter the file name for people with autism: ");
	gets(p_with_autism);// File name for people with autism
    struct Scanpath* autism_List_head = createScanpathList(p_with_autism);


    printf("Enter the file name for people without autism:");
	gets(p_without_autism);// File name for people without autism
    struct Scanpath* withoutautism_List_head = createScanpathList(p_without_autism);

    printf("Enter the pattern:");
    gets(pattern);

    printf("\nDetected patterns for people with autism:\n");
    searchPattern(autism_List_head,pattern);

    printf("\n\nDetected patterns for people without autism:\n");
    searchPattern(withoutautism_List_head,pattern);



	return 0;
}



struct Scanpath* createHeadList()
{
	struct Scanpath* head = (struct Scanpath*)malloc(sizeof(struct Scanpath));

	if (head==NULL)
        printf("\nOut of memory");
	head->next = NULL;

	return head;
}

struct Scanpath* newNode(char string[]) //this string is one scan path
{
	struct Scanpath* newnode = (struct Scanpath*)malloc(sizeof(struct Scanpath));

	if (newnode==NULL)
        printf("\nOut of memory");

	strcpy(newnode->scanpath,string);

	newnode->next = NULL;

	return newnode;
}

void printList(struct Scanpath* head)
{
	struct Scanpath* temp = head->next;
	//temp = temp->next;//I dont know why but it does not read on on the next node of the head

	while (temp !=NULL)
	{
		printf("%s",temp->scanpath);
		temp = temp->next;
	}
}


void   searchPattern(struct Scanpath*  people_list_head,char pattern[])
{
    int count = 0;;// Counts the number of lines that is found at least one pattern
    int pattern_counter=0;
    int s; // Sliding counter
    int outer_loop_counter;
    struct Scanpath* temp = people_list_head->next;//points to first non empty value of linked list
    temp = temp->next;


    int n,m,h,p,t,i,j,d,q,foundIndexes_count;
    int found_indexes[25];// This array holds the indexes which found scanpath
    char AOI_chars[25];// This array holds the characters of the indexes of AOI in text

    while(temp!=NULL){
    foundIndexes_count=0;// Counts how many pattern is found in one scanpath

    n = strlen(temp->scanpath);//4
    m = strlen(pattern);//3
    h = 1; //h value
    p = 0;//hash value for pattern
    t = 0;// hash value for text
    d=10; // 10 digits
    q=11;// Nearest prime



    for(i=0;i<m-1;i++)// h = pow(d,m-1)%q
        h = (h*d)%q;

    //printf("\n\nNumber of hash is : %d",h);


    //printf("\n\nNumber of characters in the pattern is: %d\n\nNumber of characters in the text is %d",m,n);

    for (i=0;i<m;i++)
    {
        p=(d*p+pattern[i])%q;
        t =(d*t + temp->scanpath[i])%q;
    }



    for ( s=0 ; s<=n-m ; s++)// Sliding text one by one over pattern
    {
        if ( p == t)
        {
            // Checking characters one by one

            for (j=0;j < m;j++)
            {
                if (temp->scanpath[s+j] != pattern[j])
                    break;
            }

            if (j == m)
                {


                    if (s !=0 )// iF s = 0 there is no point looking for AOI because it will be null
                    {

                        found_indexes[foundIndexes_count] = s;
                        AOI_chars[foundIndexes_count] = temp->scanpath[s-1];

                        foundIndexes_count++;
                        pattern_counter++;
                    }

                }
        }

        if ( s < n-m)
        {
            t = (d*(t - temp->scanpath[s]*h) + temp->scanpath[s+m])%q;


        if (t < 0)// In case we get negative, update t value
            t = (t + q);
        }

    }



    if (foundIndexes_count != 0)
        {
         count++;
         printScanpathWithPattern(count,temp->scanpath,found_indexes,strlen(pattern),foundIndexes_count);
        }

        temp = temp->next;


    }//End of while

    if(count==0)
        printf("\None");
    else
    {
        printf("\n%d patterns detected in %d scanpaths",pattern_counter,count);
        printf("\nThe most frequent AOI for the pattern is %c",get_most_common(AOI_chars));

    }

}

char    find_most_repated_AOI(char AOI_chars[])
// This function basically calculates the most repeated AOI by taking the array, holds the values of AOIs, and index counts
{
    char most_repated_AOI = get_most_common(AOI_chars);

    printf("\n\nThe most repeated AOI is %c\n ",most_repated_AOI);

    return most_repated_AOI;
}

char get_most_common(char array[])
{

    int i=0, j, count,total_count;
    while(array[i]=='0'|| array[i]=='1' || array[i]=='2' || array[i]=='3'
          || array[i]=='4' || array[i]=='5' || array[i]=='6' || array[i]=='7'
          || array[i]=='8' || array[i]=='9')
    {
        i++;//TO count how many element in the array
    }
    total_count=i;



    int most = 0;
    char temp, element;

    for(i = 0; i < total_count; i++) {
        temp = array[i] ; // char equal char
        count = 1;
        for(j = i + 1; j < total_count; j++) {
            if(array[j] == temp) {
                count++;
            }
        }
        if (most < count) {
            most = count;
            element = array[i];
        }
    }

    return element;

}



void printScanpathWithPattern(int count,char scanpath[],int found_indexes[],int length_Of_Pattern,int foundIndexes_count)
//This function takes the indexes of AOI and print them in required format
{
    int i,j=0;




    printf("%d. ",count);


    int lengthOfScanpath = strlen(scanpath);
    int temp;//Holds the i + length of pattern value



    for (i=0;i<lengthOfScanpath;i++)
    {
        if (found_indexes[j] == i)
        {

            printf("[");
            temp = i + length_Of_Pattern;
            for (i ;i < temp ;i++)
            {
                printf("%c",scanpath[i]);
            }
            printf("]");
            j++;
            i--;
        }
        else
        {
            printf("%c",scanpath[i]);
        }
    }


    //printf("\n");


}

