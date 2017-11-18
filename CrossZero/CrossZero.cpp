// CrossZero.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
int Calculation_cross_zero(int &counterc, int &cross, int mass[3][3], char mass1[3][3]);
int Calculation_zero_cross(int &counterz, int &zero, int mass[3][3], char mass1[3][3]);
int main()
{
	int c = 0, z = 0, f = 0, g = 0;
	int mass[3][3] = { { 1,2,3 },{ 4,5,6 },{ 7,8,9 } };
	char mass1[3][3] = { {},{},{} };
	char S;
	setlocale(LC_ALL, "rus");
	system("COLOR 0A");
	std::cout << "\t\t\t\t\t\t КРЕСТИКИ - НОЛИКИ " << std::endl;
	std::cout << " X - Крестик " << std::endl;
	std::cout << " 0 - Нолик " << std::endl << std::endl;
	std::cout << " Для того чтобы играть вводите числа 1 - 9 " << std::endl;
	std::cout << " Выберите с чего ходить первым (введите X или 0) : ";
start:
	std::cin >> S;
	switch (S)
	{
	case 'X':
		do
		{
			if (((f == 4 && g == 5) || (f == 5 && g == 4)) && (c != 1 && z != 1))
			{
				std::cout << " Ничья " << std::endl;
				goto end;
			}
			if (z == 1)
			{
				goto end;
			}
			Calculation_cross_zero(f, c, mass, mass1);
			if (((f == 4 && g == 5) || (f == 5 && g == 4)) && (c != 1 && z != 1))
			{
				std::cout << " Ничья " << std::endl;
				goto end;
			}
			if (c == 1)
			{
				goto end;
			}
			Calculation_zero_cross(g, z, mass, mass1);

		} while ((c != 1) || (z != 1)); break;

	case '0':
		do
		{
			if (((f == 4 && g == 5) || (f == 5 && g == 4)) && (c != 1 && z != 1))
			{
				std::cout << " Ничья " << std::endl;
				goto end;
			}
			if (c == 1)
			{
				goto end;
			}
			Calculation_zero_cross(g, z, mass, mass1);
			if (((f == 4 && g == 5) || (f == 5 && g == 4)) && (c != 1 && z != 1))
			{
				std::cout << " Ничья " << std::endl;
				goto end;
			}
			if (z == 1)
			{
				goto end;
			}
			Calculation_cross_zero(f, c, mass, mass1);
		} while ((c != 1) || (z != 1)); break;

	default: std::cout << " Ошибка, введите либо X либо 0 : "; goto start; break;
	}
end:
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                    //
int Calculation_cross_zero(int &counterc, int &cross, int mass[3][3], char mass1[3][3]) // Вычисление хода крестиком//
{                                                                                                                   //
	int a;                                                                                                          //
	std::cout << " Поставьте крестик ";                                                                             //
	std::cin >> a;                                                                                                  //
	std::cout << std::setw(5) << "   ---------------   " << std::endl;                                              //
	for (int i = 0; i < 3; i++)                                                                                     //
	{                                                                                                               //
		for (int j = 0; j < 3; j++)                                                                                 //
		{                                                                                                           //
			if (mass[i][j] == a && mass1[i][j] != '0')                                                              //
			{                                                                                                       //
				mass1[i][j] = 'X';                                                                                  //
			}                                                                                                       //
			std::cout << std::setw(4) << "|" << mass1[i][j] << "|";                                                 //
		}                                                                                                           //
		std::cout << std::endl;                                                                                     //
		std::cout << std::setw(5) << "   ---------------   " << std::endl;                                          //
	}                                                                                                               //
	counterc++;                                                                                                     //
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 3; i++)////Горизонталь
	{
		for (int j = 1; j < 2; j++)
		{
			if (mass1[i][j] == 'X' && mass1[i][j + 1] == 'X' && mass1[i][j - 1] == 'X')
			{
				cross++;
				if (cross == 1)
				{
					std::cout << " Игра окончена, победили крестики " << std::endl;
				}
			}
		}
	}
	for (int j = 0; j < 3; j++)////Вертикаль
	{
		for (int i = 1; i < 2; i++)
		{
			if (mass1[i][j] == 'X' && mass1[i + 1][j] == 'X' && mass1[i - 1][j] == 'X')
			{
				cross++;
				if (cross == 1)
				{
					std::cout << " Игра окончена, победили  крестики" << std::endl;
				}
			}
		}
	}
	for (int i = 1; i < 2; i++)////Главная диагональ
	{
		for (int j = 1; j < 2; j++)
		{
			if (mass1[i][j] == 'X' && mass1[i + 1][j + 1] == 'X' && mass1[i - 1][j - 1] == 'X')
			{
				cross++;
				if (cross == 1)
				{
					std::cout << " Игра окончена, победили крестики " << std::endl;
				}
			}
		}
	}
	for (int i = 1; i < 2; i++)////Побочная диагональ
	{
		for (int j = 1; j > 0; j--)
		{
			if (mass1[i][j] == 'X' && mass1[i + 1][j - 1] == 'X' && mass1[i - 1][j + 1] == 'X')
			{
				cross++;
				if (cross == 1)
				{
					std::cout << " Игра окончена, победили крестики " << std::endl;
				}
			}
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                                                  //
int Calculation_zero_cross(int &counterz, int &zero, int mass[3][3], char mass1[3][3]) // Вычисление хода ноликом //
{                                                                                                                 //
	int b;                                                                                                        //
	std::cout << " Поставьте нолик ";                                                                             //
	std::cin >> b;                                                                                                //
	std::cout << std::setw(5) << "   ---------------   " << std::endl;                                            //
	for (int i = 0; i < 3; i++)                                                                                   //
	{                                                                                                             //
		for (int j = 0; j < 3; j++)                                                                               //
		{                                                                                                         //
			if (mass[i][j] == b && mass1[i][j] != 'X')                                                            // 
			{                                                                                                     //
				mass1[i][j] = '0';                                                                                //
			}                                                                                                     //
			std::cout << std::setw(4) << "|" << mass1[i][j] << "|";                                               //
		}                                                                                                         //
		std::cout << std::endl;                                                                                   //
		std::cout << std::setw(5) << "   ---------------   " << std::endl;                                        //
	}                                                                                                             //
	counterz++;                                                                                                   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < 3; i++)////Горизонталь
	{
		for (int j = 1; j < 2; j++)
		{
			if (mass1[i][j] == '0' && mass1[i][j + 1] == '0' && mass1[i][j - 1] == '0')
			{
				zero++;
				if (zero == 1)
				{
					std::cout << " Игра окончена, победили нолики " << std::endl;
				}
			}
		}
	}
	for (int j = 0; j < 3; j++)////Вертикаль
	{
		for (int i = 1; i < 2; i++)
		{
			if (mass1[i][j] == '0' && mass1[i + 1][j] == '0' && mass1[i - 1][j] == '0')
			{
				zero++;
				if (zero == 1)
				{
					std::cout << " Игра окончена, победили нолики " << std::endl;
				}
			}
		}
	}
	for (int i = 1; i < 2; i++)////Главная диагональ
	{
		for (int j = 1; j < 2; j++)
		{
			if (mass1[i][j] == '0' && mass1[i + 1][j + 1] == '0' && mass1[i - 1][j - 1] == '0')
			{
				zero++;
				if (zero == 1)
				{
					std::cout << " Игра окончена, победили нолики " << std::endl;
				}
			}
		}
	}
	for (int i = 1; i < 2; i++)////Побочная диагональ
	{
		for (int j = 1; j > 0; j--)
		{
			if (mass1[i][j] == '0' && mass1[i + 1][j - 1] == '0' && mass1[i - 1][j + 1] == '0')
			{
				zero++;
				if (zero == 1)
				{
					std::cout << " Игра окончена, победили нолики " << std::endl;
				}
			}
		}
	}
	return 0;
}