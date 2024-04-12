#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

// Iron Box. Продажа комплектующих для компьютеров
//                                             Определить функции!!!!!!!!!!!!!!!!!!!!!!!!


void Start();

int main()
{
	setlocale(LC_ALL, "ru");
	Start();


	return 0;
}

void Start()
{
	std::cout << "Добро пожаловать в интернет-магазин";

	std::string adminLogin = "admin";
	std::string adminPassword = "admin";
	std::string login, password;
	int choose;
	bool exit = false;

	do
	{
		std::cout << "Введите логин: ";
		std::getline(std::cin, login);
		std::cout << "Введите пароль: ";
		std::getline(std::cin, password);

		if (login != adminLogin || password != adminPassword)
		{
			std::cerr << "Неверный логин или пароль\n";
			std::cout << "Попробовать ещё раз?\n    1 - да\n    2 - выход из программы\n";
			std::cin >> choose;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			if (choose == 2)
			{
				exit = true;
			}
			else
			{
				exit = true;
				int chooseStorageType;
				do
				{
					std::cout << "Введите формат склада: \n    1 - готовый склад\n    2 - создать склад вручную\n";
					std::cin >> chooseStorageType;
				} while (chooseStorageType < 1 || chooseStorageType > 2);

				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				if (chooseStorageType == 1)
				{
					// создать склад и запускать магазин
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
		}
	} while (!exit);
}