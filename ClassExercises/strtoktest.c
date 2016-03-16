#include <stdio.h>
#include <string.h>

#define STR_LEN 1000
#define WORDS 50

int read_line(char *str, int n);

int main () {
  /*  int read_num;
    char input[STR_LEN + 1];
    char pointer[WORDS][STR_LEN],
    char * pch;
    
    printf("Please enter a sentence: \n");
    read_num = read_line(input, STR_LEN);
    
    printf ("Splitting string \"%s\" into tokens:\n",str);
    
    pch = strtok (input," ,.-");
    
    while (pch != NULL) {
        printf ("%s\n",pch);
        pch = strtok (NULL, " ,.-");
    }
    
    return 0;*/
    int count = 0, c = 0, i, j = 0, k, space = 0;
    int read_num;
    char str[STR_LEN], p[WORDS][STR_LEN], ptr1[WORDS][STR_LEN];
    char *ptr;
    char *pch;
    
    printf("Enter the string\n");
    read_num = read_line(str, STR_LEN);
    printf("string length is %lu\n", strlen(str));
    for (i = 0;i<strlen(str);i++)
    {
        if ((str[i] == ' ')||(str[i] == ',')||(str[i] == '.'))
        {
            space++;
        }
    }
    for (i = 0, j = 0, k = 0;j < strlen(str);j++)
    {
        if ((str[j] == ' ')||(str[j] == 44)||(str[j] == 46))
        {
            p[i][k] = '\0';
            i++;
            k = 0;
        }
        else
            p[i][k++] = str[j];
    }
    k = 0;
    for (i = 0;i <= space;i++)
    {
        for (j = 0;j <= space;j++)
        {
            if (i == j)
            {
                strcpy(ptr1[k], p[i]);
                k++;
                count++;
                break;
            }
            else
            {
                if (strcmp(ptr1[j], p[i]) != 0)
                    continue;
                else
                    break;
            }
        }
    }
    for (i = 0;i < count;i++)
    {
        for (j = 0;j <= space;j++)
        {
            if (strcmp(ptr1[i], p[j]) == 0)
                c++;
        }
        printf("%s -> %d times\n", ptr1[i], c);
        c = 0;
    }
}

/*
 /*extracting each and every string and copying to a different place
while (input_words[i] != '\0') {
    if (input_words[i] == ' ') {
        word[j][k] = '\0';
        k = 0;
        j++;
    } else {
        word[j][k++] = input_words[i];
    }
    i++;
}

word[j][k] = '\0';
n = j;
*/
/* sort the words in the given string */

/*for (i = 0; i < n; i++) {
    strcpy(temp, word[i]);
    for (j = i + 1; j <= n; j++) {
        if (strcmp(word[i], word[j]) > 0) {
            strcpy(temp, word[j]);
            strcpy(word[j], word[i]);
            strcpy(word[i], temp);
        }
    } //inner for
}  //outer for

printf("Frequency of words:\n");
i = 0;
*/
/* find the frequency of each word and print the results */
/*while (i <= n) {
    count = 1;
    if (i != n) {
        for (j = i + 1; j <= n; j++) {
            if (strcmp(word[i], word[j]) == 0) {
                count++;
            }
      //  }//for
    //}*/
    
    /* count - indicates the frequecy of word[i] */
  //  printf("%s\t%d\n", word[i], count);
    
    /* skipping to the next word to process */
   // i = i + count;
//}



/*read_line skips the white space(s) before beginning to store input characters*/
int read_line(char *str, int n) {
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++= ch;
            i++;
        }
    }
    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}