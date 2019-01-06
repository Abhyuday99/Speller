// Implements a dictionary's functionality

#include <stdbool.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#include "dictionary.h"

typedef struct alphabet{
    bool word ;
    struct alphabet* next[27] ;
} letter ;

letter *head = NULL ;

void add_node(letter *node , int index )
{
    letter* temp = NULL ;
    node->next[index] = malloc(sizeof(letter)) ;
    temp = node->next[index] ;
    temp->word = false ;
    for(int i =0 ; i < 27 ; i++)
        temp->next[i] = NULL ;

}

// Returns true if word is in dictionary else false
 bool check(const char *word)
{
    int z,c;
    letter *temp = head ;
    for(z = 0 ; word[z] != '\0' ; z++)
    {
        char single_letter =  tolower(word[z]) ;
        c = single_letter ;
        if(isalpha(c))
        {
          if(temp->next[c-'a'] ==NULL)
                return false;
          else
            temp = temp-> next[c-'a'] ;

        }
        else if( c == '\'')
        {

          if(temp->next[26] ==NULL)
                return false;
          else
            temp = temp-> next[26] ;

        }
    }
    if(temp->word == true)
        return true;
    else
        return false;
    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE* ptr = fopen(dictionary,"r") ;

    if(ptr == NULL)
        return false;

    head =malloc(sizeof(letter)) ;
    for(int i =0 ; i < 27 ; i++)
    {
        head->next[i] = NULL ;
    }
    letter *temp =head ;

    for (int c = fgetc(ptr); c != EOF; c = fgetc(ptr))
    {
        // Allow only alphabetical characters and apostrophes
        if (isalpha(c))
        {
            int index= c-'a' ;
            if(temp->next[index] == NULL)
            {
                add_node(temp,index) ;
                temp = temp->next[index] ;
            }
            else

                temp = temp->next[index] ;
        }

        else if(c == '\'')
        {
            if(temp->next[26] == NULL)
            {
                add_node(temp,26) ;
                temp = temp->next[26] ;
            }
            else

                temp = temp->next[26] ;
        }

        // We must have found a whole word
        else if (temp != head)
        {
            // Terminate current word
            temp->word = true;
            temp = head ;
        }
    }
    temp->word = true ;
    fclose(ptr) ;
    return true ;

}

unsigned int count_node(letter *node)
{
    if(node == NULL)
        return 0;

    unsigned int x =0 ;

    if(node-> word == true)
       x++;
    for( int i=0 ; i < 27 ; i++)
    {   if(node != NULL)
            x += count_node(node->next[i]) ;
    }
    return x ;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if(head == NULL)
        return 0;

    int sum = 0 ;
    for(int i = 0 ; i < 27 ; i++)
    {   if( head -> next[i] != NULL)
            sum += count_node(head->next[i]) ;
    }
    return sum ;

}

void rm_node(letter *node)
{

    for(int i =0; i < 27 ;i++)
    {
        if(node->next[i] != NULL)
            rm_node(node->next[i]) ;

    }
     free(node) ;
     node =NULL ;
}

bool unload(void)
{
    if(head != NULL )
    {
        rm_node(head) ;
        return true;
    }

    return false ;

}

