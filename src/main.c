#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"getBDD.h"
#include <time.h>


int main()
{
	char listeMots[TOTAL_WORDS][MAX_WORD_LENGTH];
	getWord("ressource/bdd_wordle_only.txt",listeMots);
	char next='i';
	char var;
	while(next=='i')
	{
		printf("Words with : '.....' "); //search with position = ..p..
		scanf(" %c",&var);
		filter_contain(listeMots, &var);
		printf("What filter do you want to try next [Include/Exclude/Filter]?");
		scanf("%c",&next);
		if(next=='e')
		{
			printf("Exclude all words containing letter: ");
			scanf("%c", &var);
			filter_exclude(listeMots, &var);
		}
		else if(next=='f')
		{
			break;
		}
	}
	return 0;

}
