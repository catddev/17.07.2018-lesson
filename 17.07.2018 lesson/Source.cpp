#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;
		

		switch (tn)
		{
		case 1: // сортировка строк по максимальному элементу каждой строки
		{
			const int n = 8;
			const int m = 6;
			int a[n][m];
			int b[n];
			int i, j, k, pass;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					a[i][j] = rand() % 21;
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

			for (i = 0; i < n; i++)
			{
				int max = INT_MIN;
				for (j = 0; j < m; j++)
				{
					if (a[i][j] > max) max = a[i][j];
				}
				b[i] = max;
				cout << b[i] << " ";
			}
			cout << endl << endl;

			for (pass = 0; pass < n-1; pass++)
			{
				for (k = 0; k < n - 1; k++)
				{
					if (b[k] > b[k + 1]) // сортируем максимумы в каждой строке
					{
						swap(b[k], b[k + 1]);

						for (i = 0; i < m; i++) // в этом же условии делаем поэлементную замену в строках двухмерного массива
							swap(a[k][i], a[k + 1][i]);
					}
				}
			}
			cout << endl << endl;

			for (i = 0; i < n; i++)
			{
				cout << b[i] << " ";
			}
			cout << endl << endl;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

		}
		break;
		case 3: // найти сумму элементов каждой строки и переставить строки в порядке убывания суммы
		{
			const int n = 8;
			const int m = 6;
			int a[n][m];
			int b[n];
			int i, j, k, pass;

			for (i = 0; i < n; i++)
			{
				int sum = 0;
				for (j = 0; j < m; j++)
				{
					a[i][j] = rand() % 10;
					sum += a[i][j];
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << "|" << sum << endl;
				b[i] = sum;
			}
			cout << endl;

			for (pass = 0; pass < n - 1; pass++)
			{
				for (k = 0; k < n - 1; k++)
				{
					if (b[k] < b[k + 1]) // сортируем максимумы в каждой строке
					{
						swap(b[k], b[k + 1]);

						for (i = 0; i < m; i++) // в этом же условии делаем поэлементную замену в строках двухмерного массива
							swap(a[k][i], a[k + 1][i]);
					}
				}
			}
			cout << endl << endl;

			for (i = 0; i < n; i++)
			{
				cout << b[i] << " ";
			}
			cout << endl << endl;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

		}
		break;
		case 4: // Напишите программу, которая спрашивает у пользователя
			// IP адрес (4 цифры, каждая из которых от 0 до 255) и заносит их в массив.
			// Выполнить проверку корректности введенных цифр. Результат вывести в виде цифр, разделенных точкой (160.1.8.1).
		{
			const int n = 4;
			int a[n];

			for (int i = 0; i < n; i++)
			{
				cin >> a[i];
			}

			for (int i = 0; i < n; i++)
			{
				if (a[i] >= 0 && a[i] <= 255)
					cout << a[i] << ".";
				else break;
			}
			cout << endl;
		}
		break;
		case 6: // перевод чисел в двоичную и в десятичнную
		{
			int a[100];
			int i = 0;
			int n;

			cout << "enter a number: ";
			cin >> n;
			int k = 0;

			while (n / 2 > 0)
			{
				if (n >= 2)
				{
					a[i] = n % 2;
					n = n / 2;
					i++;
					k++;
				}
				if (n < 2) // обязательно НЕ else if, а просто отдельное условие которое должно проверяться всегда
				{
					a[i] = n;
					k++;
				}
			}
			/*cout << k << endl;

			for(i=0; i<k; i++) 
			cout << a[i];

			cout << endl;*/

			for (i = 0; i < k / 2; i++)
			{
				swap(a[i], a[k - 1 - i]);
			}

			for (int i = 0; i < k; i++)
			{
				cout << a[i];
			}
			cout << endl << endl;

		}
		break;
		case 7: // перевод чисел в десятичнную
		{
			int a[100];
			int i = 0;
			int n;

			cout << "enter a number: ";
			cin >> n;
			double k = 0;

			while (n / 10 > 0)
			{
				if (n >= 10)
				{
					a[i] = n % 10;
					n = n / 10;
					i++;
					k++;
				}
				
				if (n < 10)
				{
					a[i] = n;
					k++;
				}
			}
			/*cout << k << endl;*/

			/*for (i = 0; i<k; i++)
				cout << a[i] <<" ";
			cout << endl << endl;*/

			double sum = 0;
			
			i = 0;
			while(i<k)
			{
				sum += a[i] * pow(2, i);
				i++;
			}
			cout << sum << endl << endl;
		}
		break;
		case 8:
		{

		}
		break;
		case 9:
		{
			// 44.	**Написать программу «учет успеваемости». Создайте двухмерный массив целых чисел 10х10. Строки отвечают за конкретного студента, столбцы за оценки. 
			// Например,
			// 11 10  9  8
			// 6   4 12 5
			// первая строка – оценки первого студента по математике, физике, программированию и физкультуре.
			// вторая строка – оценки второго студента по математике, физике, программированию и физкультуре.
			// Реализовать меню, которое содержит следующие пункты :
			// a)	процент и количество хорошистов(хорошист – если все оценки не ниже 7 баллов).
			// b)	процент и количество отличников(отличник – если все оценки не ниже 10).
			// c)	список оценок конкретного студента и его средний бал(вводится номер строки).
			// d)	список оценок по конкретной дисциплине (вводится номер столбца).

				int a[10][10];
				int n = 4;
				int i, j;
				int k, kh = 0, ko = 0;
				int total;

				cout << "учет успеваемости" << endl << endl;
				for (i = 0; i < 10; i++)
				{
					cout << left << setw(4) << "student" << " " << i << "  |   ";
					for (j = 0; j < n; j++)
					{
						a[i][j] = 6 + rand() % 6;
						cout << right << setw(3) << a[i][j] << " ";
					}
					cout << endl << endl;
				}

				int info;

				int c = 0;
				while (c < 4)
				{
					c++;
					cout << "выберите тип запроса:" << endl << endl;
					cout << "1 - процент и количество хорошистов, 2 - процент и количество отличников, 3 - список оценок конкретного студента и его средний бал, 4 - список оценок по конкретной дисциплине" << endl;
					cin >> info;

					switch (info)
					{
					case 1:
					{
						for (i = 0; i < 10; i++)
						{
							k = 0;
							for (j = 0; j < n; j++)
							{
								if (a[i][j] >= 7) k++;
							}
							if (k == n) kh++;
						}
						double percent = (kh / 10.0) * 100.0;
						cout << kh << " хорошистов - " << percent << "%" << endl;
					}
					break;
					case 2:
					{
						for (i = 0; i < 10; i++)
						{
							k = 0;
							for (j = 0; j < n; j++)
							{
								if (a[i][j] >= 10) k++;
							}
							if (k == n) ko++;
						}
						double percent = (ko / 10.0) * 100.0;
						cout << ko << " отличников - " << percent << "%" << endl;
					}
					break;
					case 3:
					{
						int number;
						cout << "номер студента: " << endl;
						cin >> number;
						double sum=0;

						for (j = 0; j < n; j++)
						{
							cout << a[number][j] << " ";
							sum += a[number][j];
						}
						cout << endl << endl;
						cout << "average score = " << sum / n << endl << endl;
					}
					break;
					case 4:
					{
						int number;
						cout << "введите номер дисциплины: 0 - оценки всех студентов по математике, 1 - физике, 2 - программированию и 3 - физкультуре" << endl;
						cin >> number;

						for (i = 0; i < 10; i++)
						{
							cout << a[i][number] << " ";
						}
						cout << endl << endl;
					}
					break;
					}
				}
		}
		break;
		case 10: // другое решение предыдущей задачи (то, которое предложили на доске коллективно
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}