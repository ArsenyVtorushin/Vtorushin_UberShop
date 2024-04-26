#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// Iron Box. ������� ������������� ��� �����������


//���������� �������
int size = 10;
int receiptSize = 1;
int* idArr = new int[size];
std::string* nameArr = new std::string[size];
int* countArr = new int[size];
double* priceArr = new double[size];


//������� ��� ����
std::string* nameReceiptArr = new std::string[receiptSize];
int* countReceiptArr = new int[receiptSize];
double* priceReceiptArr = new double[receiptSize];


//������� �������
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
		"Ƹ����� ����", "����������� ������", "����������� �����",
		"���������", "����������", "������", "����� ��� ����������",
		"���� �������", "�������", "���-������"
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
			std::cout << "\n������� id ������: ";
			std::cin >> chooseId;
			if (chooseId < 1 || chooseId > size)
			{
				std::cerr << "\n������� ������ ���\n";
				continue;
			}
			if (countArr[chooseId - 1] >= 0) // ������? (>= 0)
			{
				while (true)
				{
					std::cout << "\n��������� �����: " << nameArr[chooseId - 1] << "\n";
					std::cout << "���-�� ������� ������ �� ������: " << countArr[chooseId - 1];
					std::cout << "\n\n������� ���-�� ������: ";
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
				std::cerr << "\n������ �� ������ ���\n";
				continue;
			}

			std::cout << "\n�����: " << nameArr[chooseId - 1] << "\n���-��: " << chooseCount;
			std::cout << "\n1 - �����������\n2 - ������\n\n";
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

			std::cout << "\n������ ��� ���� �����?\n\n";
			std::cout << "1 - ��\n 2 - ��������� �������\n";
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
	std::cout << "��������\t\t\t���-��\t����\n";
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
		std::cout << "\n\n������� ID ������: ";
		std::cin >> id;
	} while (id < 1 || id > 10);

	std::cout << "�� ������� �����: \n" << nameArr[id - 1] << "  -  " << priceArr[id - 1];

	do
	{
		std::cout << "\n\n������� ����� ����: ";
		std::cin >> newPrice;
	} while (newPrice < 1 || newPrice > 500000);

	priceArr[id - 1] = newPrice;
	std::cout << "\n\n���� ������� ��������\n\n";
}
void RemoveFromStorage()
{
	{
		int id;
		int count;
		do
		{
			std::cout << "������� Id ������ ��� ��������: ";
			std::cin >> id;
		} while (id < 1 || id > idArr[size - 1]);

		std::cout << "\n\n������ �����: " << nameArr[id - 1] << "  -  " << countArr[id - 1] << " ����\n\n";

		do
		{
			std::cout << "\n������� ���-�� ������: ";
			std::cin >> count;
		} while (count < 0 || count  > countArr[id - 1]);
		countArr[id - 1] -= countArr[id - 1];
		std::cout << "\n����� ������� ������";
	}
}
void AddToStorage()
{
		int id;
		int count;
		do
		{
			std::cout << "������� Id ������ ��� ����������: ";
			std::cin >> id;


		} while (id < 1 || id > idArr[size - 1]);
		std::cout << "\n������ �����: " << nameArr[id - 1] << "  -  ���-��: " << countArr[id - 1];
		do
		{
			std::cout << "\n���������: ";
			std::cin >> count;
		} while (count < 0 || count > 1000);
		countArr[id - 1] += count;
		std::cout << "\n������� ���������";
	
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
	std::cout << "������� ��� ������ ������: \n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, nameArr[size - 1], '\n');
	std::cout << "������� ���-�� ������ ������: \n";
	std::cin >> countArr[size - 1];
	std::cout << "\n������� ���� ������ ������: \n";
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
		std::cout << "������� Id ������ ��� ��������: ";
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
		std::cout << "1 - �������� ����� � �����\n";
		std::cout << "2 - ������ ����� �� ������\n";
		std::cout << "0 - �����\n";
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
		std::cout << "�����";
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
