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

			for (pass = 0; pass < n - 1; pass++)
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
			while (i < k)
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
			// 6  4  12  5
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
			double sum = 0;

			cout << "учет успеваемости" << endl << endl;
			for (i = 0; i < 10; i++)
			{
				cout << left << setw(4) << "student" << " " << i << "  |   ";
				for (j = 0; j < n; j++)
				{
					a[i][j] = 6 + rand() % 6; // зададим такой диапозон по 12 больной системе, чтобы с большей вероятностью
											  // были и хорошисты и отличники для наглядности
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
						sum = 0;
						for (j = 0; j < n; j++)
						{
							if (a[i][j] >= 7)
							{
								k++;
								sum += a[i][j];

							}
							if (k == n && (sum / n < 10)) kh++; // средний балл ниже 10, чтобы отделить хорошистов от отличников
						}
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
					double sum = 0;

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
		case 10: // другое решение предыдущей задачи (то, которое предложили на доске коллективно)
				 // код не работает, у них много недочетов, логические ошибки при написании условий, не могут разделить отличников и хорошистов
				 // лучше смотреть свой код, а в этом только формат составления цикла while, exit и что еще может пригодиться.
				
		{
			const int n = 10;
			const int m = 10;
			int a[n][m];

			for (int i = 0; i < n; i++)
			{
				cout << "Студент № " << i + 1 << " ";
				for (int j = 0; j < m; j++)
				{
					a[i][j] = rand() % 4 + 8;
					cout << setw(5) << a[i][j] << " ";
				}

				cout << endl;
			}

			int choice;
			int e_count = 0;
			bool e_f = false;
			bool g_f = false;
			int g_count = 0;


			while (true)
			{
				cout << "Выберите из следующих вариантов: " << endl;
				cout << "1)	процент и количество отличников" << endl;
				cout << "2)	процент и количество хорошистов" << endl;
				cout << "3)	список оценок конкретного студента и его средний бал" << endl;
				cout << "4)	список оценок по конкретной дисциплине" << endl;
				cout << "0)	Для выхода" << endl;

				cin >> choice;

				switch (choice)
				{
				case 1:
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							if (a[i][j] > 10)
							{
								e_f = true; // у них был фолз, исправила на тру
								break;
							}
						}
						if (e_f)
							e_count++;
					}

					cout << e_count*100.0 / n << endl;
				}
				break;
				case 2:
				{
					for (int i = 0; i < n; i++)
					{
						for (int j = 0; j < m; j++)
						{
							if (a[i][j] > 7 && a[i][j] < 10)
							{
								g_f = true; // у них был фолз, исправила на тру
								break;
							}
						}
						if (g_f)
							g_count++;
					}

					cout << g_count*100.0 / n << endl;

				}
				break;

				case 3:
				{
					int n = 0;
					int sum = 0;
					double average = 0;
					cout << "Введите номер студента: ";
					cin >> n;

					for (int i = 0; i < m; i++)
					{
						cout << a[n - 1][i] << " ";
					}

					cout << endl;

					for (int i = 0; i < m; i++)
					{
						sum += a[n - 1][i];
						average = (double)sum / 10;
					}
					cout << "Средний балл = " << average;
					cout << endl;

				}
				break;

				case 4:
				{
					int k = 0;

					cout << "Введите номер предмета: ";
					cin >> k;

					for (int i = 0; i < 10; i++)
					{
						cout << a[i][k - 1] << " ";
					}

					cout << endl;
				}
				break;

				case 0:
				{
					exit(0); // для выхода 
				}
				break;
				default:
					break;
				}
			}
		}
		break;
		case 46:
		{
			// ***Написать программу «Подсчет единичных островов». Заполнить двухмерный
			// массив 12х12 0 и 1. 0 – это вода, 1 – это земля.Воды должно быть в три раза
			// больше, чем земли.Необходимо посчитать количество единичных островов.
			// Единичным островом считается 1, окруженная со всех сторон 0.
			// 11000
			// 00010
			// 10000
			// Примечание: единичный остров, стоящий на углу, не будет окружен водой со всех
			// сторон, учтите это при проверке, чтобы не выйти за пределы массива.

			const int n = 12;
			int a[n][n];
			int i, j;
			int island = 0;

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					a[i][j] = rand() % 4;
					if (a[i][j] == 2 || a[i][j] == 3) a[i][j] = 0; // не строго, но приблизительно в три раза больше нулей будет
					
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			cout << "координаты островов:" << endl;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					if (i != 0 && i != n - 1 && j != 0 && j != n - 1)
					if (a[i][j] == 1)
						if (a[i - 1][j - 1] == 0 && a[i - 1][j + 1] == 0 && a[i - 1][j] == 0 && a[i][j - 1] == 0 && a[i][j + 1] == 0 && a[i + 1][j - 1] == 0 && a[i + 1][j + 1] == 0 && a[i + 1][j] == 0)
						{
							island++;
							cout << i << ", " << j << endl;
						}
				}
			}
			cout << endl << "Единичных островов " << island << endl << endl;
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}