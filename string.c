#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TXT 1024
#define WORD 30
int countLetter(char* c)
{
    int i = 0,sum = 0;
    while(c[i])
    {
        if(c[i]!=' '&& c[i]!='\n'&&c[i]!='\t')
            sum++;
        i++;
    }
    return sum;
}
void revers(char* c)
    {
        int end = strlen(c)-1;
        for (int i = 0; i <= end/2; i++)
        {
            char temp = c[i];
            c[i] = c[end-i];
            c[end-i] = temp;
        }
        
    }
int find(char* w, char c)
    {
        int i = 0, ind = 0;
        while (w[i])
        {
            if(w[i]==c) return ind;
            i++;
            ind++;
        }
        return -1;
        
    }
int gimatria(char *c)
    {
        int sum = 0,i=0;
        while(c[i])
        {
            if(c[i] >= 'a' && c[i] <= 'z')
                sum += c[i]-'a'+1;
            else if (c[i] >= 'A' && c[i] <= 'Z')
                sum += c[i]- 'A' +1;
            i++;
        }
        
        return sum;
    }
void atbsh(char *c)
    {
        int i =0;
        while (c[i])
        {   
            if(c[i] >= 'a' && c[i] <= 'z')
                c[i] = 'z'-c[i]+'a';
            else if (c[i] >= 'A' && c[i] <= 'Z')
                c[i] = 'Z' -c[i] +'A';
            i++;
        }
        
    }
int anagram(char *w,char *c)
{
    if(c[0]==' '|| c[0]=='\n'||c[0]=='\t')return 0;
    if(countLetter(w)!=countLetter(c))return 0;
    char copy [strlen(w)];
    strcpy(copy,w);
    int i=0;
    while (c[i])
    {
        if(strlen(copy)!=0)
        {
            int num = find(copy,c[i]);
            if (num == -1){
                if(c[i]!=' ')
                    return 0;
            }
            else
            {
                memmove(&copy[num],&copy[num+1],strlen(copy)-num);
            }
        }
        else
        {
            if(c[i]!=' ')
                return 0;
        }
        i++;
    }
    //printf("great!\n");
    //printf("%s~",c);
    return 1;
        
        
}
void gematriaSequences(char* word, char* text)
{
    printf("Gematria Sequences: ");
    char cp[strlen(text)];
    strcpy(cp,text);
    int count = gimatria(word);
    int len = strlen(cp),s=0, flag = 0;;
    for (int i = 0; i < len; i++)
    {
        s=0;
        char temp[len];
        for (int g = 0; g < len; g++)
        {
            temp[g] = 0;
        }
        for (int j = 0; j < strlen(cp); j++)
        {
            if((cp[0]>='a'&&cp[0]<='z')||(cp[0]>='A'&&cp[0]<='Z')){
            char f;
            f = cp[j];
            temp[s++] = f;

            int sum = gimatria(temp);
            if (sum == count)
            {
                if (flag != 0)
                    printf("~%s",temp);
                else
                {
                    flag = 1;
                    printf("%s",temp);
                }
                break;
            }
            else if(sum > count) break;
            }
            
        }
        memmove(&cp[0],&cp[0+1],strlen(cp)-0);
    
    }
    
}
void anagramSequences(char* word, char* text)
{
    char cp[strlen(text)];
    strcpy(cp,text);
    printf("\nAnagram Sequences: ");
    int s =0,len=strlen(cp),flag = 0;
    for (int i = 0; i < len; i++)
    {
        s=0;
        char temp[len];
        for (int g = 0; g < len; g++)
        {
            temp[g] = 0;
        }
        for (int j = 0; j < strlen(cp); j++)
        {
            if((cp[0]!=' '&& cp[0]!='\n'&&cp[0]!='\t')){
            char f;
            f = cp[j];
            temp[s++] = f;
            if (anagram(word,temp)==1) 
            {
                if(flag != 0)
                    printf("~%s",temp);
                else
                {
                    flag = 1;
                    printf("%s",temp);
                }
                break;
            }
            }
        }   
        memmove(&cp[0],&cp[0+1],strlen(cp)-0);
    
    }
}
void atbshSequences(char* word, char* text)
{
    char cp[strlen(text)];
    strcpy(cp,text);
    int s =0,len=strlen(cp),flag = 0;
    printf("\nAtbsh Sequences: ");
    for (int i = 0; i < len; i++)
    {
        s=0;
        char temp[len];
        char temp_copy[strlen(temp)];
        char rev_temp_copy[strlen(temp)];

        for (int g = 0; g < len; g++)
        {
            temp[g] = 0;
            temp_copy[g]=0;
            rev_temp_copy[g]=0;
        }
        for (int j = 0; j < strlen(cp); j++)
        {
            if((cp[0]>='a'&&cp[0]<='z')||(cp[0]>='A'&&cp[0]<='Z')){
            char f;
            f = cp[j];
            temp[s++] = f;
            strcpy(temp_copy,temp);
            strcpy(rev_temp_copy,temp);
            revers(rev_temp_copy);
            atbsh(temp_copy);
            atbsh(rev_temp_copy);
            int num1 = strcmp(word,temp_copy);
            int num2 = strcmp(word,rev_temp_copy);
            if(num1 == 0 || num2 == 0)
            {
                if (flag!=0)
                    printf("~%s",temp);
                else
                {
                    flag = 1;
                    printf("%s",temp);
                }
            }

            }
        }   
        memmove(&cp[0],&cp[0+1],strlen(cp)-0);
    
    }
}
int main()
{   
    char word[WORD];
    char text[TXT];
    char c = ' ';
    scanf("%c",&c);
    int i = 0;
    for (; i < WORD && c != ' '&&c!= '\n'&&c!='\t'; i++)
    {
        word[i] = c;
        scanf("%c",&c);
    }
    c = ' ';
    scanf("%c",&c);

    i = 0;
    for(;i<TXT&&c!='~';i++)
    {
        text[i] = c;
        scanf("%c",&c);
    }
    gematriaSequences(word,text);
    atbshSequences(word,text);
    anagramSequences(word,text);
} 
