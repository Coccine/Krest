#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void displayArea(char *area);
void inCross(char *area);
void inZero(char *area);
short winCombination(char *area);




int main(void)
{
	
	
	/*
	setlocale(LC_ALL, "RU");

	char area[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	displayArea(area);
	//Основной цикл
	for (int i = 1; i < 10; i++)
	{
		short checkWin;

		// Добавление крестика
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
		{
			inCross(area);
		}

		// Добавление нолика
		else
		{
			inZero(area);
		}

		// Проверка на победу(после 2-го хода каждого из противников)
		if (i > 4)
		{
			checkWin = winCombination(area);
			if (checkWin == 1)
			{
				system("color F4");
				puts(" *-------- ПОБЕДИЛ КРЕСТИК -------*");
				break;
			}
			else if (checkWin == 2)
			{
				system("color F4");
				puts(" *-------- ПОБЕДИЛ НОЛИК -------*");
				break;
			}
			else if (i == 9)
			{
				system("color F4");
				puts(" *-------- НИЧЬЯ -------*");
				break;
			}
		}
	}*/

	while (getchar() != '\n');
	getchar();
	return 0;
}


//////////   ВЫВОД КЛЕТОК  /////////
void displayArea(char *area)
{
	system("cls");
	printf("\n\n");
	for (int i = 1; i < 10; i++)
	{
		if (area[i] == 'X')
			printf("| %c |", area[i]);
		else
			printf("| %d |", area[i]);
		if (i == 3 || i == 6 || i == 9)
			printf("\n");
	}
	printf("\n\n\n");
}

///////////   КРЕСТИК      ////////	
void inCross(char *area)
{
	printf("ХОД КРЕСТИКА!");
	int pos, ifNormal;
	ifNormal = 1;
	while (ifNormal == 1)
	{
		printf("\nВведите позицию для крестика: ");
		scanf("%d", &pos);
		if (pos > 0 && pos < 10)
		{
			if (area[pos] != 0 && area[pos] != 'X')
			{
				area[pos] = 'X';
				displayArea(area);
				ifNormal = 0;
			}
			else if (area[pos] == 'X')
			{
				puts("Вы уже использовали этот ход, повторите снова...");
				pos = 0;
			}
			else if (area[pos] == 0)
			{
				puts("Вы попытались замазать ход противника, выбите другой ход");
				pos = 0;
			}
			
	    }
		else
		{
			printf("\nТакой позиции не существует, повторите попытку...");
			pos = 0;
		}
	}
}
 
////////////   НОЛИК  //////////////

void inZero(char* area)
{
	printf("ХОД НОЛИКА!");
	int pos, ifNormal;
	ifNormal = 1;
	while (ifNormal == 1)
	{
		printf("\nВведите позицию для нолика: ");
		scanf("%d", &pos);
		if (pos > 0 && pos < 10)
		{
			if (area[pos] != 'X' && area[pos] != 0)
			{
				area[pos] = 0;
				displayArea(area);
				ifNormal = 0;
			}
			else if (area[pos] == 0)
			{
				puts("Вы уже использовали этот ход, повторите снова...");
				pos = 0;
			}
			else if (area[pos] == 0)
			{
				puts("Вы попытались замазать ход противника, выбите другой ход");
				pos = 0;
			}
		}
		else
			printf("\nТакой позиции не существует, повторите попытку...");
	}
}

//////////// ПРОВЕРКА ПОБЕДНОЙ КОМБИНАЦИИ /////////
short winCombination(char *area)
{
		//Проверка победной комбинации для крестиков
		if (area[1] == 'X' && area[2] == 'X' && area[3] == 'X')
			return 1;
		else if (area[4] == 'X' && area[5] == 'X' && area[6] == 'X')
			return 1;
		else if (area[7] == 'X' && area[8] == 'X' && area[9] == 'X')
			return 1;
		else if (area[1] == 'X' && area[4] == 'X' && area[7] == 'X')
			return 1;
		else if (area[2] == 'X' && area[5] == 'X' && area[8] == 'X')
			return 1;
		else if (area[3] == 'X' && area[6] == 'X' && area[9] == 'X')
			return 1;
		else if (area[1] == 'X' && area[5] == 'X' && area[9] == 'X')
			return 1;
		else if (area[3] == 'X' && area[5] == 'X' && area[7] == 'X')
			return 1;
		//Проверка победной комбинации для нолика
		else if (area[1] == 0 && area[2] == 0 && area[3] == 0)
			return 2;
		else if (area[4] == 0 && area[5] == 0 && area[6] == 0)
			return 2;
		else if (area[7] == 0 && area[8] == 0 && area[9] == 0)
			return 2;
		else if (area[1] == 0 && area[4] == 0 && area[7] == 0)
			return 2;
		else if (area[2] == 0 && area[5] == 0 && area[8] == 0)
			return 2;
		else if (area[3] == 0 && area[6] == 0 && area[9] == 0)
			return 2;
		else if (area[1] == 0 && area[5] == 0 && area[9] == 0)
			return 2;
		else if (area[3] == 0 && area[5] == 0 && area[7] == 0)
			return 2;
		//Если ни одна из комбинаций не подошла
		else
			return 0;
}
