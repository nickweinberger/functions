#include <cs50.h>
#include <stdio.h>
#include <string.h> // for string length
#include <math.h> // for rounding
#include <ctype.h>

int main(int argc, string argv[])
{

    string text = get_string("text: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        {
            //Letter Counter
            if (isalpha(text[i]))
            {
                letters++;
            }

            //Word counter
            if (isalpha(text[i]) && text[i - 1] == ' ')
            {
                words++;
            }
            if (text[i] == '"' && text[i - 1] == ' ')

            //Sentence counter, can clean up below line
            if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            {
                sentences++;
            }
        }
    }
    //print # of letters, words, sentences
    //printf("%i\n", letters);
    //printf("%i\n", words);
    //printf("%i\n", sentences);


    //average number of letters per 100 words
    float averageletters = ((float)letters / (float)words * 100);
    //printf("%f\n", averageletters);

    //average number of sentences per 100 words
    float averagesentences = ((float)sentences / (float)words * 100);
    //printf("%f\n", averagesentences);

    //plugging variables into coleman-liau index
    int x = round((0.0588 * averageletters) - (0.296 * averagesentences) - 15.8);

    if (x >= 1 && x <= 16)
    {
        printf("Grade %i\n", x);
    }

    if (x > 16)
    {
        printf("Grade 16+\n");

    }
    if (x < 1)
    {
        printf("Before Grade 1\n");
    }

}