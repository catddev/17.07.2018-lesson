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
		case 1:
		{
			/*int a[4][4] = { {1, 5, 7, 8}, {3, 2, 0, 5}, {7, 9, 4, 7}, {2,4,0,3} };
			int b[4];
			int i, j;

			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

			for (i = 0; i < 4; i++)
			{
				int max = INT_MIN;
				for (j = 0; j < 4; j++)
				{
					if (a[i][j] > max) max = a[i][j];
				}
				b[i] = max;
				cout << b[i] << " ";
				cout << endl;
			}
			cout << endl;

			for (i = 0; i < 4-1; i++)
			{
				for (int k = 0; k < 4 - 1; k++)
				{
					if (b[k] > b[k + 1])
					{
						swap(b[k], b[k + 1]);
						for (int p = 0; p<4; p++)
						{
							for (j = 0; j < 4; j++)
							{
								cout << a[p][j] << " ";
							}
							cout << endl;
						}
					}
				}
			}
			cout << endl;*/
				
		}
		break;
		case 2: // сортировка строк по максимальному элементу каждой строки
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
					a[i][j] = rand() % 21;
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
		case 5:// 44.	**Написать программу «учет успеваемости». Создайте двухмерный массив целых чисел 10х10. Строки отвечают за конкретного студента, столбцы за оценки. 
			// Например,
			// 11 10  9  8
			// 6   4 12 5
			// первая строка – оценки первого студента по математике, физике, программированию и физкультуре.
			// вторая строка – оценки второго студента по математике, физике, программированию и физкультуре.
			// Реализовать меню, которое содержит следующие пункты :
			// a)процент и количество хорошистов(хорошист – если все оценки не ниже 7 баллов).
			// b)	процент и количество отличников(отличник – если все оценки не ниже 10).
			// c)	список оценок конкретного студента и его средний бал(вводится номер строки).
			// d)	список оценок по конкретной дисциплине(вводиться номер столбца).

			// forever cyc // double
		{
			const int n = 10;
			int a[n][n];
			int i, j;
			int k;
			int total;

			cout << "учет успеваемости" << endl << endl;
			for (i = 0; i < n; i++)
			{
				cout << left << setw(4) << "student" << " " << i + 1 << "|";
				for (j = 0; j < n; j++)
				{
					a[i][j] = 2 + rand() % 12;
					cout << left << setw(3) << a[i][j] << " ";
				}
				cout << endl << endl;
				
			}

			int info;
			cout << "выберите тип запроса:" << endl << endl;
			cout << "1 - процент и количество хорошистов, 2 - процент и количество отличников, 3 - список оценок конкретного студента и его средний бал, 4 - список оценок по конкретной дисциплине" << endl;
			cin >> info;

			switch (info)
			{
			case 1:
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						if (a[i][j] >= 7) k++;
						if (k < 10) k = 0;
					}
				}
				int percent = k / n * 100;
				cout << percent << "%" << endl;
			}
			break;
			case 2:
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						if (a[i][j] >= 10) k++;
						if (k < 10) k = 0;
					}
				}
				int percent = k / n * 100;
				cout << percent << "%" << endl;
			}
			break;
			case 3:
			{
				int number;
				cout << "номер студента: " << endl;
				cin >> number;
				int sum1;

					for (j = 0; j < n; j++)
					{
						cout << a[number][j] << " ";
					//	sum1 += a[i][j];
					}
						
				
				/*cout << "| average score = " << sum1 / n << endl;*/

			}
			break;
			case 4:
			{
				int number;
				cout << "введите номер дисциплины: " << endl;
				cin >> number;
				int sum1;

				for (i = 0; i<n; i++)
				{
					i = number;
					for (j = 0; j < n; j++)
					{
						cout << a[i][j] << " ";
						sum1 += a[i][j];
					}
					break;
				}
				
			}
			break;
			}

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
				if (n < 2) // обязательно не else if, а просто отдельное условие которое должно проверяться всегда
				{
					a[i] = 1;
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

		}
		break;
		case 10:
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