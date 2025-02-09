#include <stdio.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char *text = argv[1];
    int textLength = strlen(text);
    int dimension = sqrt(textLength);
    char outText[textLength];
    int position = textLength-1;
    int tmp = dimension-1;
    if(dimension == 2)
        {
            outText[0]=text[3];
            outText[1]=text[2];
            outText[2]=text[0];
            outText[3]=text[1];
            printf("%s",outText);
            return 0;
        }
    if(dimension == 3)
        {
            outText[0]=text[8];
            outText[1]=text[7];
            outText[2]=text[6];
            outText[3]=text[3];
            outText[4]=text[0];
            outText[5]=text[1];
            outText[6]=text[2];
            outText[7]=text[5];
            outText[8]=text[4];
            printf("%.*s", textLength, outText);
            return 0;
        }
    int i=1;
    int secondRound =0;
    outText[0]=text[position];
    int j;
    while(i<textLength)
        {
            if(tmp==2)
                {
                    outText[i++]=text[--position];
                    outText[i++]=text[--position];
                    position-=dimension;
                    outText[i++]=text[position];
                    outText[i++]=text[++position];
                }
            for(j=0; j<tmp && i<textLength; j++)
                {
                    outText[i++]=text[--position];
                }
            tmp -= secondRound;
            for(j=0; j<tmp && i<textLength; j++)
                {
                    position-=dimension;
                    outText[i++]=text[position];
                }
            for(j=0; j<tmp && i<textLength; j++)
                {
                    outText[i++]=text[++position];

                }
            tmp--;
            for(j=0; j<tmp && i<textLength; j++)
                {
                    position+=dimension;
                    outText[i++]=text[position];
                }
            secondRound = 1;
        }
    //printf("%s",outText);
    printf("%.*s", textLength, outText);
    return 0;
}
