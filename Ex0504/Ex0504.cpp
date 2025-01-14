﻿/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                               *
 *  Глава 5. Упражнение 4.                                                       *
 *                                                                               *
 *  Дафна инвестировала $100 под простые 10%. Другими словами, ежегодно          *
 *  инвестиция должна приносить 10% инвестированной суммы, т.е. $10 каждый год:  * 
 *                                                                               *
 *                  прибыль = 0,10 х исходный баланс.                            *
 *                                                                               *
 *  В то же время Клео инвестировала $100 под сложные 5%. Это значит, что        *
 *  прибыль составит 5% от текущего баланса, включая предыдущую накопленную      *
 *  прибыль:                                                                     *
 *                  прибыль = 0,05 х текущий баланс.                             *
 *                                                                               *
 *  Клео зарабатывает 5% от $100 в первый год, что дает ей $105. На следующий    *
 *  год она зарабатывает 5% от $105, что составляет $5.25, и т.д.                *
 *                                                                               *
 *  Напишите программу, которая вычислит, сколько лет понадобится для того,      *
 *  чтобы сумма баланса Клео превысила сумму баланса Дафны, с отображением       *
 *  значений обоих балансов за каждый год.                                       *
 *                                                                               *
 *                                                                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>

using namespace std;

int main()
{
    const float SimplePercent = 0.1f;           // Коэффициент по простому проценту
    const float CompoundPercent = 0.05f;        // Коэффициент по сложному проценту
    const float startBallanceSimpPer = 100.0f;  // Стартовый баланс по сложному проценту
    
    float ballanceSimpPer = startBallanceSimpPer;   // Балланс по простому проценту
    float ballfnceCompPer = 100.0f;                 // Балланс по сложному проценту

    #if OS_WIN == true 
        system("chcp 1251 > nul");
        system("cls");
    #else
        system("clear");
    #endif

    cout << "5.4 ПРОСТОЙ И СЛОЖНЫЙ ПРОЦЕНТЫ\n";
    cout << "-----------------------------------------------------\n";
    cout << " Год\tПростой процент 10%\tСложный процент 5%" << endl;
    cout << "-----------------------------------------------------\n";

    int year;

    for (year = 1; ballanceSimpPer >= ballfnceCompPer; year++)
    {
        ballanceSimpPer += startBallanceSimpPer * SimplePercent;
        ballfnceCompPer += ballfnceCompPer * CompoundPercent;
        cout 
            << " " << year << "\t\t" 
            << ballanceSimpPer << "\t\t\t" 
            << ballfnceCompPer << endl;
    }
     
    cout << "-----------------------------------------------------\n\n";

    cout << "Ответ: сумма баланса Клео (сложный процент) превысит\n";
    cout << "сумму баланса Дафны (простой процент) через " << year - 1 << " лет.\n\n";

    #if OS_WIN == true 
        system("pause");
    #endif
}