//Determines if a word or phrase is an isogram
//9 test cases: 
//1. empty string, 2. lowercase only, 3. duplicated letter, 4. longest known isogram
//5. duplicated letter mixed case, 6. non letter char, 7.duplicated non letter char
//8. multiple whitespace, 9. duplicated letter w/in word 

#include "isogram.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
bool is_isogram(const char phrase[])
{
    //1. Iterate through the phrase
    //2. Test each letter against the letters in the phrase
    //3. If that letter does not match against another letter in the  
    // phrase, then return true

    int i, j;
    int whiteSpaceCnt = 0;
    int nonLetterCnt = 0;
    char *lowerCasePhrase = (char *)malloc(strlen(phrase) * sizeof(char));

    for (i = 0; i < (int)(strlen(phrase)); i++)
    {
        lowerCasePhrase[i] = tolower(phrase[i]);
    }

    for (i = 0; i < (int)(strlen(phrase)); i++)
    {
        for (j = i + 1; phrase[j] != '\0'; j++)
        {
            if(lowerCasePhrase[i] == lowerCasePhrase[j])
            {
                return false;
            }
            else if(lowerCasePhrase[i] == 32)
            {
                whiteSpaceCnt++;
                if(whiteSpaceCnt > 1)
                {
                    return true;
                }
            }
            else if(lowerCasePhrase[i] >= 33 && lowerCasePhrase[i] <= 64)
            {
                nonLetterCnt++;
                if(nonLetterCnt > 1)
                {
                    return true;
                }
            }
        }
    }
    return true;
    free(lowerCasePhrase);
}