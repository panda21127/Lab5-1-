﻿/*
Создать функцию для поиска слов в строке, начинающихся с заглавной буквы (возвращается массив указателей на начало слов).
Тестовая программа: Ввести текст (несколько строк) с клавиатуры, признак окончания – слово «end».
Данные размещать в динамической области.
Изменить текст: слова, начинающиеся с заглавной буквы переместить в начало строки.
Вывести текст на экран и отформатировать: После точки начинать с «красной строки»
*/
#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
	int N, i;
	setlocale(LC_ALL, "Russian");
	string* M;
	string answer;
	M = new string[10];
	string buff;
	cout << "Введите несколько строк с текстом; для завершения введите \"end.\".\n";
	cout << "Примечание 1: текст вводить на английском\n";
	cout << "Примечание 2: \"end.\" вводить с новой строки\n";
	int k = 0;
	for (i = 0; ((buff[0] != 'e') || (buff[1] != 'n') || (buff[2] != 'd') || (buff[3] != '.')); i++) //Ввод текста
	{
		getline(cin, buff);
		M[i] = buff;
		for (int k = 0; k < buff.size(); k++)
		{
			if (k == 0)
			{
				if (isupper(buff[k]) > 0)
				{
					int j = k;
					while (((buff[j]) != ' ') && ((buff[j]) != '\0') && ((buff[j]) != '.'))//обработка текста на просмотр первого слова (с Заглавной)
					{
						answer += buff[j];
						j++;
					}
					answer += " ";
				}
			}
			else
			{
				if ((buff[k - 1] == ' ') && (isupper(buff[k]) > 0))
				{
					int j = k;
					while (((buff[j]) != ' ') && ((buff[j]) != '\0') && ((buff[j]) != '.'))//обработка текста на нахождение слов с  Заглавной буквы
					{
						answer += buff[j];
						j++;
					}
					answer += " ";
				}

			}
		}
		for (int k = 0; k < buff.size(); k++)
		{

			if (buff[k] == '.')
			{
				answer += ". \n";
			}
			if (k == 0)
			{
				if (isupper(buff[k]) == 0)
				{
					int j = k;
					while (((buff[j]) != ' ') && ((buff[j]) != '\0') && ((buff[j]) != '.'))//обработка текста на просмотр первого слова (с не Заглавной)
					{
						answer += buff[j];
						j++;
					}
					answer = answer + " ";
				}
			}
			else
			{
				if ((buff[k - 1] == ' ') && (isupper(buff[k]) == 0))
				{
					int j = k;
					while (((buff[j]) != ' ') && ((buff[j]) != '\0') && ((buff[j]) != '.'))//обработка текста на нахождение слов с не Заглавной буквы
					{
						answer += buff[j];
						j++;
					}
					answer += " ";
				}
			}

		}
	}
	cout << answer << endl;//вывод обработанного текста(Программа выводит все слова начинающиеся с Заглавной буквы, затем оставшиеся слова)
	return 0;
}


