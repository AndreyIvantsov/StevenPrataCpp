﻿/*****************************************************************************
 *
 *  Глава 5. Упражнение 1.
 *
 *  Напишите программу,  запрашивающую у  пользователя ввод двух целых чисел. 
 *  Затем программа должна вычислить и выдать сумму всех целых чисел, лежащих 
 *  между этими  двумя целыми. Предполагается, что  меньшее значение вводится 
 *  первым. Например, если пользователь ввел 2 и 9, программа должна сообщить, 
 *  что сумма всех целых чисел от 2 до 9 равна 44. 
 *
 *****************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int first;
    int second;
    int summa;

    #if OS_WIN == true 
        system("chcp 1251 > nul");
        system("cls");
    #else
        system("clear");
    #endif

    cout << "5.1 СУММА ЧИСЕЛ\n";
    cout << "-----------------------------------\n";

    cout << "Введите первое число: "; cin >> first;
    cout << "Введите второе число: "; cin >> second;

    for (int i = first; i <= second; i++)
    {
        summa += i;
    }

    cout << "Сумма чилсел = " << summa << endl;
    cout << "-----------------------------------\n\n";

    #if OS_WIN == true 
        system("pause");
    #endif 
}