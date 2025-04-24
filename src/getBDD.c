#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getBDD.h>

void filter_contain(char liste[TOTAL_WORDS][MAX_WORD_LENGTH], char* lettre)
{
    for (int i = 0; i < TOTAL_WORDS; i++)
    {
        if (strchr(liste[i], *lettre))
        {
            printf("%s\n", liste[i]);
        }
    }
}

void filter_exclude(char liste[TOTAL_WORDS][MAX_WORD_LENGTH], char* lettre)
{
    for (int i = 0; i < TOTAL_WORDS; i++)
    {
        if (!strchr(liste[i], *lettre))
        {
            printf("%s\n", liste[i]);
        }
    }
}

void getWord(char* bddName, char words[TOTAL_WORDS][MAX_WORD_LENGTH])
{
    FILE* file = fopen(bddName, "r");
    if (!file) {
        perror("Erreur ouverture fichier");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (fgets(words[i], MAX_WORD_LENGTH, file) && i < TOTAL_WORDS)
    {
        words[i][strcspn(words[i], "\n")] = '\0';
        i++;
    }

    fclose(file);
}

