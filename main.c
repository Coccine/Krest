#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


void displayArea(char *area);
short inCross();
short inZero();
short winCombination(char *area);
short easyBot(char *area);


int main(void)
{
	srand(time(NULL));
	system("color F0");
	setlocale(LC_ALL, "RU");

	char area[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	displayArea(area);
	//Основной цикл
	for (int i = 1; i < 10; i++)
	{
		short pos, checkWin, whileTrueForX, whileTrueFor0;
		whileTrueForX = 1;
		whileTrueFor0 = 1;

		// Добавление крестика
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
		{
			printf("ХОД КРЕСТИКА!");
			pos = inCross();
			while (whileTrueForX == 1)
			{
				if (area[pos] != 0 && area[pos] != 'X')
				{
					area[pos] = 'X';
					displayArea(area);
					whileTrueForX = 0;
				}
				else if (area[pos] == 'X')
				{
					puts("Вы уже использовали этот ход, повторите снова...");
					pos = inCross();
				}
				else if (area[pos] == 0)
				{
					puts("Вы попытались замазать ход противника, выбите другой ход");
					pos = inCross();
				}
			}
		}

		// Добавление нолика
		else
		{
			printf("ХОД НОЛИКА!");
			pos = inZero();
			while (whileTrueFor0 == 1)
			{
				if (area[pos] != 0 && area[pos] != 'X')
				{
					area[pos] = 0;
					displayArea(area);
					whileTrueFor0 = 0;
				}
				else if (area[pos] == 0)
				{
					puts("Вы уже использовали этот ход, повторите снова...");
					pos = inCross();
				}
				else if (area[pos] == 'X')
				{
					puts("Вы попытались замазать ход противника, выбите другой ход");
					pos = inCross();
				}
			}
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
		}
	}

	while (getchar() != '\n');
	getchar();
	return 0;
}


//////////   ВЫВОД КЛЕТОК  /////////
void displayArea(char *area)
{
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
short inCross()
{
	short pos, ifNormal;
	ifNormal = 1;
	while (ifNormal == 1)
	{
		printf("\nВведите позицию для крестика: ");
		scanf_s("%i", &pos);
		if (pos > 0 && pos < 10)
			ifNormal = 0;
		else
		{
			printf("\nТакой позиции не существует, повторите попытку...");
			pos = 0;
		}
	}

	return pos;
}
 
////////////   НОЛИК  //////////////

short inZero()
{
	short pos, ifNormal;
	ifNormal = 1;
	while (ifNormal == 1)
	{
		printf("\nВведите позицию для нолика: ");
		scanf_s("%i", &pos);
		if (pos > 0 && pos < 10)
			ifNormal = 0;
		else
			printf("\nТакой позиции не существует, повторите попытку...");
	}

	return pos;
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

//////////// EASY BOT ////////////////
short easyBot(char *area)
{
	short pos, ifNormPos;
	pos = rand() % 11 + 1;
	ifNormPos = 1;
	while (ifNormPos)
	{
		if (area[pos] != 0 && area[pos] != 'X')
		{
			area[pos] = 0;
			displayArea(area);
			ifNormPos = 0;

		}
		else if (area[pos] == 0)
		{
			pos = rand() % 10 + 1;

		}
		else if (area[pos] == 'X')
		{
			pos = rand() % 10 + 1;
		}
	}
}
