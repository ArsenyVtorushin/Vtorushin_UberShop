#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// Iron Box. Продажа комплектующих для компьютеров


//Глобальные массивы

int size = 10;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
int* priceArr = new int[size];

//Основые функции

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
	std::cout << "\t- Добро пожаловать в интернет-магазин -\n\n";
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
		std::cout << "\n\nВведите логин: ";
		std::getline(std::cin, login);
		std::cout << "Введите пароль: ";
		std::getline(std::cin, password);

		if (login != adminLogin || password != adminPassword)
		{
			do
			{
				std::cerr << "\nНеверный логин или пароль\n";
				std::cout << "Попробовать ещё раз?\n    1 - да\n    2 - выход из программы\n";
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
				std::cout << "\nВведите формат склада: \n    1 - готовый склад\n    2 - создать склад вручную\n";
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
				std::cout << "В разработке\n";
			}
			else
			{
				std::cerr << "Ошибка";
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
		"Жёсткий диск", "Оперативная память", "Материнская плата",
	    "Процессор", "Видеокарта", "Корпус", "Кулер для процессора", 
		"Блок питания", "Монитор", "Веб-камера" 
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
		<< std::setw(25) << "Название" 
		<< std::setw(15) << "Количество" 
		<< std::setw(25) << "Цена" << "\n\n";

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
			std::cout << "\n1 - Показать склад\n";
			std::cout << "2 - Начать продажу\n";
			std::cout << "3 - Изменить цену\n";
			std::cout << "4 - Списать товар\n";
			std::cout << "5 - Пополнить товар\n";
			std::cout << "6 - Изменение склада\n";
			std::cout << "0 - Закончить смену\n";
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
