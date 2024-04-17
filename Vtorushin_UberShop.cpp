#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// Iron Box. ������� ������������� ��� �����������


//���������� �������

int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
int* priceArr = new int[size];

//������� �������

void Start();
void DeleteMainArrays();
void CreateStorage();
void ShowStorage();
void Shop();

template <typename ArrType>
void FillArr(ArrType staticArr, ArrType dinArr, int size);


int main()
{
	setlocale(LC_ALL, "ru");
	Start();
	
	DeleteMainArrays();
	return 0;
}


void Start()
{
	std::cout << "\t- ����� ���������� � ��������-������� -\n\n";
	std::cout << "           ________                          _____\n";
	std::cout << "          /__   __/                         /     \\ \n";
	std::cout << "            /  /    _ ___  ____  ____      /  /)  /  ____ __  __ \n";
	std::cout << "         __/  /__  / /\\_/ / * / / __ \\    /  /_) \\  / * / \\ \\/ /\n";
	std::cout << "        /_______/ /_/    /___/ /_/ /_/   |_______/ /___/  /_/\\_\\ \n";

	std::string adminLogin = "admin";
	std::string adminPassword = "admin";
	std::string login, password;
	int choose;
	bool exit = false;

	do
	{
		std::cout << "\n\n������� �����: ";
		std::getline(std::cin, login);
		std::cout << "������� ������: ";
		std::getline(std::cin, password);

		if (login != adminLogin || password != adminPassword)
		{
			do
			{
				std::cerr << "\n�������� ����� ��� ������\n";
				std::cout << "����������� ��� ���?\n    1 - ��\n    2 - ����� �� ���������\n";
				std::cin >> choose;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (choose == 2)
				{
					exit = true;
				}
			} while (choose < 1 || choose > 2);
		}

		else
		{
			exit = true;
			int chooseStorageType;
			do
			{
				std::cout << "\n������� ������ ������: \n    1 - ������� �����\n    2 - ������� ����� �������\n";
				std::cin >> chooseStorageType;
			} while (chooseStorageType < 1 || chooseStorageType > 2);

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (chooseStorageType == 1)
			{
				CreateStorage();
				Shop();
			}
			else if (chooseStorageType == 2)
			{
				std::cout << "� ����������\n";
			}
			else
			{
				std::cerr << "������";
			}
		}
	} while (!exit);
}

void DeleteMainArrays()
{
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
}

void CreateStorage()
{
	const int staticSize = 10;

	int id[staticSize]{ 0,1,2,3,4,5,6,7,8,9 };
	std::string name[staticSize]
	{ 
		"Ƹ����� ����", "����������� ������", "����������� �����",
	    "���������", "����������", "������", "����� ��� ����������", 
		"���� �������", "�������", "���-������" 
	};
	int count[staticSize]{ 6, 5, 12, 7, 10, 8, 6, 7, 9, 15 };
	int price[staticSize]{ 5340, 790, 12900, 17900, 23890, 2300, 1190, 4790, 2100, 570 };

	FillArr(id, idArr, staticSize);
	FillArr(name, nameArr, staticSize);
	FillArr(count, countArr, staticSize);
	FillArr(price, priceArr, staticSize);
}

void ShowStorage()
{
	std::cout << std::left 
		<< std::setw(7) << "\n\nID"
		<< std::setw(25) << "��������" 
		<< std::setw(15) << "����������" 
		<< std::setw(25) << "����" << "\n\n";

	for (int i = 0; i < size; i++)
	{
		std::cout << std::left 
			<< std::setw(5) << idArr[i] + 1 
			<< std::setw(25) << nameArr[i]
			<< std::setw(15) << countArr[i] 
			<< std::setw(25) << priceArr[i] << "\n";
	}
}

void Shop()
{
	while (true)
	{
		int choose;
		do
		{
			std::cout << "\n1 - �������� �����\n";
			std::cout << "2 - ������ �������\n";
			std::cout << "3 - �������� ����\n";
			std::cout << "4 - ������� �����\n";
			std::cout << "5 - ��������� �����\n";
			std::cout << "6 - ��������� ������\n";
			std::cout << "0 - ��������� �����\n";
			std::cin >> choose;

		} while (choose > 6 || choose < 0);

		if (choose == 1)
		{
			ShowStorage();
		}
		else if (choose == 2)
		{

		}
		else if (choose == 3)
		{

		}
		else if (choose == 4)
		{

		}
		else if (choose == 5)
		{

		}
		else if (choose == 6)
		{

		}
		else if (choose == 0)
		{
			break;
		}
		else 
		{
			std::cerr << "Error";
		}
	}
}

template<typename ArrType>
void FillArr(ArrType staticArr, ArrType dinArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
