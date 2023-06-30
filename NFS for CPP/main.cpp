#include <iostream>
#include "Vehicle.h"
#include "Camel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Speedcamel.h"
#include <vector>
#include "Magiccarpet.h"
#include "Eagle.h"
#include "Broom.h"
#include <map>

void reg(char* game, std::vector<Vehicle*>* vehicle,int* dist, bool* change)
{
	char z;
	while (true)
	{
		if (*game == '1')
		{
			std::cout << "Гонка для наземного транспорта. Растояние: " << *dist << std::endl;
			std::cout << "Выберите транспорное средство " << std::endl;
		}
		else if (*game == '2')
		{
			std::cout << "Гонка для воздушного транспорта. Растояние: " << *dist << std::endl;
			std::cout << "Выберите транспорное средство " << std::endl;
		}
		else if (*game == '3')
		{
			std::cout << "Гонка для наземного и воздушного транспорта. Растояние: " << *dist << std::endl;
			std::cout << "Выберите транспорное средство " << std::endl;
		}
		bool tmp = false;
		while (!tmp)
		{
			std::cout << "1. Ботинки-вездеходы" << std::endl
				<< "2. Метла " << std::endl
				<< "3. Верблюд " << std::endl
				<< "4. Кентавр " << std::endl
				<< "5. Орёл " << std::endl
				<< "6. Верблюд-быстроход " << std::endl
				<< "7. Ковер-самолёт " << std::endl
				<< "0. Закончить регистрацию" << std::endl;
			std::cin >> z;
			system("cls");
			if ((*game == '1' && (z == '1' || z == '3' || z == '4' || z == '6')) || (*game == '2' && (z == '2' || z == '5' || z == '7')) || *game == '3' || z == '0')
			{
				tmp = true;
				switch (z)
				{
				case '1':
					vehicle->push_back(new Boots());
					break;
				case '2':
					vehicle->push_back(new Broom());
					break;
				case '3':
					vehicle->push_back(new Camel());
					break;
				case '4':
					vehicle->push_back(new Centaur());
					break;
				case '5':
					vehicle->push_back(new Eagle());
					break;
				case '6':
					vehicle->push_back(new SpeedCamel());
					break;
				case '7':
					vehicle->push_back(new MagicCarpet());
					break;
				case '0':
					return;
				}
			}
			else
				std::cout << "Недопустимый тип транспорта!\n";

			std::cout << vehicle->back()->get_vehiclename() << " успешно зарегистрирован!" << std::endl;
			std::cout << "Зарегистрированные транспортные средства: ";
			size_t y = 0;
			for (auto& i : *vehicle)
			{
				std::cout << i->get_vehiclename();
				y++;
				if (y != vehicle->size())
					std::cout << ", ";
				else
					std::cout << "." << std::endl;

			}
		}
	}
}

void racing(std::vector<Vehicle*>* vehicle,int dist)
{
	system("cls");
	std::cout << "Результат гонки:\n";
	int j = 1;
	std::map<double, std::string> vehicle2;
	for (auto& i : *vehicle)
	{
		vehicle2.insert(std::pair <double, std::string>(i->time(dist), i->get_vehiclename()));
	}
	for (auto& i : vehicle2)
	{
		std::cout  << j++<<". " << i.second << " Время: " << i.first << std::endl;
	}
}

void mainMenu(int* dist, char* game)
{
	bool f = false;
	while (!f)
	{
		std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl
			<< "1. Гонка для наземного транспорта " << std::endl
			<< "2. Гонка для воздушного транспорта " << std::endl
			<< "3. Гонка для наземного и воздушного транспорта" << std::endl
			<< "Выберите тип гонки: ";
		std::cin >> *game;
		if (*game < 49 || *game > 51)
			std::cout << "Неверный ввод!\n";
		else
			f = true;
	}
	while (f)
	{
		std::cout << "Укажите длину дистанции ( должна быть положительна): ";
		std::cin >> *dist;
		if (*dist <= 0)
			std::cout << "Неверный ввод!\n";
		else
			f = false;
	}
	system("cls");
}

void gameMenu(char* game, std::vector<Vehicle*>* vehicle, int *dist)
{
	char z;
	bool change = false;
	while (!change)
	{
		if (vehicle->size() < 2)
		{
			std::cout << "Должно быть зарегистрированно хотя бы 2 транспортных средства." << std::endl;
			reg(game, vehicle, dist, &change);
				
		}
		else
		{
			std::cout << "1. Зарегистрировать транспортное средство.\n";
			std::cout << "2. Начать гонку.\n";
			std::cin >> z;
			if (z != '1' && z != '2')
				std::cout << "Неправильный выбор!\n";
			else if (z == '1')
				reg(game, vehicle, dist, &change);
			else
				change = true;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector<Vehicle*> vehicle;
	char game;
	int dist;
	int t = 1;
	while (t == 1)
	{
		mainMenu(&dist, &game);
		gameMenu(&game, &vehicle, &dist);
		racing(&vehicle, dist);
		vehicle.clear();
		std::cout << "\n\n1. Провести ещё одну гонку.\n2. Выйти.\n";
		std::cout << "Выберите действие: ";
		std::cin >> t;
	}
}