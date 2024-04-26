#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// Iron Box. Продажа комплектующих для компьютеров


//Глобальные массивы
int size = 10;
int receiptSize = 1;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];


//Массивы для чека
std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];


//Основые функции
void Start();
void DeleteMainArrays();
void DeleteReceiptArrays();
void CreateStorage();
void ShowStorage();
void Shop();
void Selling();
void AddElementToReceipt(int& receiptSize, int id, int count);
void PrintReceipt();
void ChangePrice();
void RemoveFromStorage();
void AddToStorage();
void AddElementToEnd();
void DeleteElementByIndex();
void ChangeStorage();

template <typename ArrType>
void FillArr(ArrType staticArr, ArrType dinArr, int size);


int main()
{
	setlocale(LC_ALL, "ru");
	Start();
	CreateStorage();
	DeleteMainArrays();
	DeleteReceiptArrays();
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
void DeleteReceiptArrays()
{
	delete[]nameReceiptArr;
	delete[]countReceiptArr;
	delete[]priceReceiptArr;
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
	double price[staticSize]{ 5340.0, 790.0, 12900.0, 17900.0, 23890.0, 2300.0, 1190.0, 4790.0, 2100.0, 570.0 };

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
			Selling();
		}
		else if (choose == 3)
		{
			ChangePrice();
		}
		else if (choose == 4)
		{
			RemoveFromStorage();
		}
		else if (choose == 5)
		{
			AddToStorage();
		}
		else if (choose == 6)
		{
			ChangeStorage();
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
void Selling()
{
	int chooseId, chooseCount, confirm;
	bool isFirst = true;
	while (true)
	{
		do
		{
			std::cout << "\nВведите id товара: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "\nДанного товара нет\n";
				continue;
			}
			if (countArr[chooseId - 1] >= 0) // ошибка? (>= 0)
			{
				while (true)
				{
					std::cout << "\nВыбранный товар: " << nameArr[chooseId - 1] << "\n";
					std::cout << "Кол-во данного товара на складе: " << countArr[chooseId - 1];
					std::cout << "\n\nВведите кол-во товара: ";
					std::cin >> chooseCount;
					if (chooseCount < 1 || chooseCount > countArr[chooseId - 1])
					{
						std::cerr << "\nError\n";
					}
					else
					{
						break;
					}

				}

			}
			else
			{
				std::cerr << "\nТовара на складе нет\n";
				continue;
			}

			std::cout << "\nТовар: " << nameArr[chooseId - 1] << "\nКол-во: " << chooseCount;
			std::cout << "\n1 - Подтвердить\n2 - Отмена\n\n";
			std::cin >> confirm;

			if (confirm == 1)
			{
				if (isFirst)
				{
					nameReceiptArr[receiptSize - 1] = nameArr[chooseId - 1];
					countReceiptArr[receiptSize - 1] = chooseCount;
					priceReceiptArr[receiptSize - 1] = priceArr[chooseId - 1] * chooseCount;
					countArr[chooseId - 1] -= chooseCount;
					isFirst = false;
				}
				else
				{
					AddElementToReceipt(receiptSize, chooseId, chooseCount);
				}

			}
			else
			{
				continue;
			}

			std::cout << "\nКупить ещё один товар?\n\n";
			std::cout << "1 - Да\n 2 - Закончить покупки\n";
			std::cin >> confirm;
			if (confirm == 1)
			{
				continue;
			}
			break;
		} while (true);

		PrintReceipt();
		system("pause");
		ShowStorage();

	}



}
void AddElementToReceipt(int& receiptSize, int id, int count)
{
	std::string* nameReceiptArrTemp = new std::string[receiptSize];
	int* countReceiptArrTemp = new int[receiptSize];
	double* priceReceiptArrTemp = new double[receiptSize];

	for (int i = 0; i < receiptSize; i++)
	{
		nameReceiptArrTemp[i] = nameReceiptArr[i];
		countReceiptArrTemp[i] = countReceiptArr[i];
		priceReceiptArrTemp[i] = priceReceiptArr[i];
	}
	delete[]nameReceiptArr;
	delete[]countReceiptArr;
	delete[]priceReceiptArr;

	receiptSize++;
	nameReceiptArr = new std::string[receiptSize];
	countReceiptArr = new int[receiptSize];
	priceReceiptArr = new double[receiptSize];

	for (int i = 0; i < receiptSize - 1; i++)
	{
		nameReceiptArr[i] = nameReceiptArrTemp[i];
		countReceiptArr[i] = countReceiptArrTemp[i];
		priceReceiptArr[i] = priceReceiptArrTemp[i];
	}
	nameReceiptArr[receiptSize - 1] = nameArr[id - 1];
	countReceiptArr[receiptSize - 1] = count;
	priceReceiptArr[receiptSize - 1] = priceArr[id - 1] * count;
	countArr[id - 1] -= count;
	delete[]nameReceiptArrTemp;
	delete[]countReceiptArrTemp;
	delete[]priceReceiptArrTemp;
}
void PrintReceipt()
{
	std::cout << "Название\t\t\tКол-во\tЦена\n";
	for (int i = 0; i < receiptSize; i++)
	{

		std::cout << nameReceiptArr[i] << "\t\t" << countReceiptArr[i] << "\t" << priceReceiptArr[i] << "\n";
	}
	std::cout << "\n";

}
void ChangePrice()
{
	int id;
	double newPrice;

	do
	{
		std::cout << "\n\nВведите ID товара: ";
		std::cin >> id;
	} while (id < 1 || id > 10);

	std::cout << "Вы выбрали товар: \n" << nameArr[id - 1] << "  -  " << priceArr[id - 1];

	do
	{
		std::cout << "\n\nВведите новую цену: ";
		std::cin >> newPrice;
	} while (newPrice < 1 || newPrice > 500000);

	priceArr[id - 1] = newPrice;
	std::cout << "\n\nЦена успешно изменена\n\n";
}
void RemoveFromStorage()
{
	{
		int id;
		int count;
		do
		{
			std::cout << "Введите Id товара для списания: ";
			std::cin >> id;
		} while (id < 1 || id > idArr[size - 1]);

		std::cout << "\n\nВыбран товар: " << nameArr[id - 1] << "  -  " << countArr[id - 1] << " штук\n\n";

		do
		{
			std::cout << "\nВведите кол-во товара: ";
			std::cin >> count;
		} while (count < 0 || count  > countArr[id - 1]);
		countArr[id - 1] -= countArr[id - 1];
		std::cout << "\nТовар успешно списан";
	}
}
void AddToStorage()
{
		int id;
		int count;
		do
		{
			std::cout << "Введите Id товара для пополнения: ";
			std::cin >> id;


		} while (id < 1 || id > idArr[size - 1]);
		std::cout << "\nВыбран товар: " << nameArr[id - 1] << "  -  кол-во: " << countArr[id - 1];
		do
		{
			std::cout << "\nПополнить: ";
			std::cin >> count;
		} while (count < 0 || count > 1000);
		countArr[id - 1] += count;
		std::cout << "\nУспешно пополнено";
	
}
void AddElementToEnd()
{
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* countArrTemp = new int[size];
	double* priceArrTemp = new double[size];
	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
		nameArrTemp[i] = nameArr[i];
		countArrTemp[i] = countReceiptArr[i];
		priceArrTemp[i] = priceArr[i];
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	size++;

	idArr = new int[size];
	nameArr = new std::string[size];
	countArr = new int[size];
	priceArr = new double[size];

	for (int i = 0; i < size - 1; i++)
	{
		idArr[i] = idArrTemp[i];
		nameArr[i] = nameArrTemp[i];
		countArr[i] = countArrTemp[i];
		priceArr[i] = priceArrTemp[i];
	}
	idArr[size - 1] = size - 1;
	std::cout << "Введите имя нового товара: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nameArr[size - 1], '\n');
	std::cout << "Введите кол-во нового товара: \n";
	std::cin >> countArr[size - 1];
	std::cout << "\nВведите цену нового товара: \n";
	std::cin >> priceArr[size - 1];
	delete[]idArrTemp;
	delete[]nameArrTemp;
	delete[]countArrTemp;
	delete[]priceArrTemp;
}
void DeleteElementByIndex()
{
	int* idArrTemp = new int[size];
	std::string* nameArrTemp = new std::string[size];
	int* CountArrTemp = new int[size];
	double* priceArrTemp = new double[size];
	for (int i = 0; i < size; i++)
	{
		idArrTemp[i] = idArr[i];
		nameArrTemp[i] = nameArr[i];
		CountArrTemp[i] = countReceiptArr[i];
		priceArrTemp[i] = priceArr[i];
	}
	delete[]idArr;
	delete[]nameArr;
	delete[]countArr;
	delete[]priceArr;
	size--;

	idArr = new int[size];
	nameArr = new std::string[size];
	countArr = new int[size];
	priceArr = new double[size];
	int index = 0;
	do
	{
		std::cout << "Введите Id товара для удаления: ";
		std::cin >> index;

	} while (index < 1 || index > size);
	for (int i = 0; i < size; i++)
	{


	}
}
void ChangeStorage()
{
	int choose;
	do
	{
		std::cout << "1 - Добавить товар в склад\n";
		std::cout << "2 - Убрать товар из склада\n";
		std::cout << "0 - Выход\n";
		std::cin >> choose;
	} while (choose < 0 || choose < 2);
	if (choose == 1)
	{
		AddElementToEnd();
	}
	else if (choose == 2)
	{
		DeleteElementByIndex();
	}
	else
	{
		std::cout << "Выход";
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
