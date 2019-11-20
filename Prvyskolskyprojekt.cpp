// Prvyskolskyprojekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <ctype.h>
#define MAX 1000


void funkcia_n(char povodny_texto[], int *pi)
{
	char n;
	int i = 0;
	FILE* fr;
	if ((fr = fopen("sifra.txt", "r")) == NULL) 
	{
		printf("Spravu sa nepodarilo nacitat\n");
	}
	else
	{
		while ((n = fgetc(fr)) != EOF)
		{
			povodny_texto[i] = n;
			i++;
			if (i > (MAX - 1))
			{
				break;
			}
			
		}

	fclose(fr);
	}
	*pi = i;
}

void funkcia_v(char povodny_text[])
{

	for (int i = 0; i < MAX; i++)
	{
		if (povodny_text[0] != '\0') {
			printf("%c", povodny_text[i]);
		}
	}
	if (povodny_text[0] == '\0')
	{
		printf("Sprava nie je nacitana\n");
	}

}

int funkcia_u(char povodny_text[], char upraveny_text[])
{
	int counter = 0; 
	for (int i = 0; i < MAX; i++)
	{
		if ((povodny_text[i] >= 'A' && povodny_text[i] <= 'Z') || (povodny_text[i] >= 'a' && povodny_text[i] <= 'z'))
		{
			upraveny_text[counter] = toupper(povodny_text[i]);
			counter++;
		}
	}

	if (povodny_text[0] == '\0')
	{
		printf("Sprava nie je nacitana\n");
	}
	return counter;
}

void funkcia_s(char upraveny_text[])
{
	int counter = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (upraveny_text[i] == '\0') 
		{
			continue;
		}
		printf("%c", upraveny_text[i]);
	}

}

void funkcia_d(char povodny_text[], int pocitadlo){
	int cislo, counter=0, pomocny_counter;
	
	while (1)
	{
		int tmp;
		tmp = scanf("%d", &cislo);
		if (cislo >= 1 && cislo <= 100)
		{
			for (int i = 0; i < pocitadlo; i++)
			{
				counter++;
				if (povodny_text[i] == ' ' && cislo == counter)
				{
					pomocny_counter = i - cislo;
					for (int j = 0; j < cislo; j++)
					{
						printf("%c", povodny_text[pomocny_counter]);
						pomocny_counter++;
					}
				}
			}
			break;
		}
		else
		{
			printf("Zadajte ine cislo.");
			int tmp1;
			tmp1 = scanf("%d", &cislo);
		}
	}
	
	
}
int main()
{
	int pocitadlo = 0;
	char povodny_text[MAX] = "", upraveny_text[MAX] = "";
	char vstup;
	
	while ((vstup = getchar()) != 'k')
	{
		
		switch (vstup)
		{
		case 'n':
			funkcia_n(povodny_text, &pocitadlo);
			break;
		case 'v':
			funkcia_v(povodny_text);
			break;
		case 'u':
			funkcia_u(povodny_text, upraveny_text);
			break;
		case 's' :
			funkcia_s(upraveny_text);
			break;
		case 'd':
			funkcia_d(povodny_text, pocitadlo);
			break;
		}
	}
	
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
