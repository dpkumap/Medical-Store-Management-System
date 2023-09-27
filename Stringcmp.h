#ifndef Stringcmp_H
#define Stringcmp_H
#include <string.h>
int strCmp(char ch1[], char ch2[])
{

    int len1 = strlen(ch1);
    int len2 = strlen(ch2);
    int tag = 0;
    
    if (len1 == len2)
    {

        for (int i = 0; i < len1; i++)
        {

            int v = ch1[i] - ch2[i];

            if (v == 0)
            {
                tag = 1;
            }
            else
            {
                tag = 0;
                break;
            }
        }
        if (tag)
        {

            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return -1;
    }
}

#endif