﻿/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                               *
 *  Глава 6. Упражнение 5.                                                       *
 *                                                                               *
 *  Королевство Нейтрония, где денежной единицей служит тварп,                   *
 *  использует следующую шкалу налогообложения:                                  *
 *      первые 5 000 тварпов      — налог  0%                                    *
 *      следующие 10 000 тварпов  — налог 10%                                    *
 *      следующие 20 000 тварпов  — налог 15%                                    *
 *      свыше 35 000 тварпов      — налог 20%                                    *
 *                                                                               *
 *  Например, если некто зарабатывает 38 000 тварпов, то он должен               *
 *  заплатить налогов:                                                           *
 *      5000 х 0.00 + 10000 х 0.10 + 20000 х 0.15 + 30000 х 0.20,                *
 *      или 4 600 тварпов.                                                       *
 *                                                                               *
 *  Напишите программу которая использует цикл для запроса доходов и выдачи      *
 *  подлежащего к выплате налога. Цикл должен завершаться, когда                 *
 *  пользовательвводит отрицательное или нечисловое значение.                    *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include "../common.h"

using namespace std;

double GetTax(double income)
{
    double tax{};
    income -= 5000;

    if (income > 0)
    {
        if (income < 10000)
        {
            tax = income * 0.1;
        }
        else
        {
            tax = 10000 * 0.1;
            income -= 10000;

            if (income < 20000)
            {
                tax += income * 0.15;
            }
            else
            {
                tax += 20000 * 0.15;
                income -= 20000;
                tax += income * 0.2;
            }
        }
    }

    return tax;
}

int main()
{
    prepareConsole();

    cout << "6.5 ДОХОДЫ И НАЛОГИ\n";
    cout << "-----------------------------------\n";

    const int BUFF_SIZE = 256;
    double income{};
    bool error;
    char buffer[BUFF_SIZE];

	do
	{
        cout << "\nВведите сумму дохода: ";
        cin >> income;
        error = !cin || income < 0;
        cin.getline(buffer, BUFF_SIZE);

		if (!error)
		{
			double tax = GetTax(income);
			cout << "Налог составит      : " << tax << endl;
		}
		
	} while (!error);

    cout << "\n-----------------------------------\n\n";

    pauseConsole();
}