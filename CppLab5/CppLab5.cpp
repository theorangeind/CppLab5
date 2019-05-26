#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int goodNumber();

int main()
{
	srand(time(0));

	cout << "Enter a 'k' value:\n";
	int k = goodNumber();
	cout << "Enter a 'n' value:\n";
	int n = goodNumber();
	cout << "Enter a 'l' value:\n";
	int l = goodNumber();

	//---------------------------------------------------
	//запись

	ofstream output;
	//первый файл
	output.open("D:\\first.txt");
	if (output.is_open())
	{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int h = 0; h < n; h++)
				{
					output << ((rand() % 9) + 1) << " ";
				}
				output << "\n";
			}
			output << "\n----------\n\n";
		}

		//дополнение единичными матрицами
		if (k != 1 && l > k)
		{
			for (int i = k; i < l; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int h = 0; h < n; h++)
					{
						output << (j == h ? 1 : 0) << " ";
					}
					output << "\n";
				}
				output << "\n----------\n\n";
			}
		}
	}
	output.close();

	//второй файл
	output.open("D:\\second.txt");
	if (output.is_open())
	{
		for (int i = 0; i < l; i++)
		{
			int r = (rand() % 9) + 1;
			for (int j = 0; j < r; j++)
			{
				for (int h = 0; h < r; h++)
				{
					output << ((rand() % 9) + 1) << " ";
				}
				output << "\n";
			}
			output << "\n----------\n\n";
		}

		//дополнение единичными матрицами
		if (k > l)
		{
			for (int i = l; i < k; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int h = 0; h < n; h++)
					{
						output << (j == h ? 1 : 0) << " ";
					}
					output << "\n";
				}
				output << "\n----------\n\n";
			}
		}
	}
	output.close();

	//---------------------------------------------------
	//чтение

	//первый файл
	cout << "\n\nReading first file...\n----------\n\n";
	string line;
	ifstream input1("D:\\first.txt");
	if (input1.is_open())
	{
		while (getline(input1, line))
		{
			cout << line << "\n";
		}
	}
	input1.close();

	//второй файл
	cout << "\n\nReading second file...\n----------\n\n";
	ifstream input2("D:\\second.txt");
	if (input2.is_open())
	{
		while (getline(input2, line))
		{
			cout << line << "\n";
		}
	}
	input2.close();

	//-------------------------------------------------

	system("pause");
}

//защита ввода
int goodNumber()
{
	string s = "c";
	int n = 0;

	while (n <= 0 || n > 9)
	{
		cout << "Enter a number between 1 and 9:\n";
		getline(cin,s);
		n = atoi(s.c_str());
	}
	return n;
}
