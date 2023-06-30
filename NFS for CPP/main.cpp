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
			std::cout << "����� ��� ��������� ����������. ���������: " << *dist << std::endl;
			std::cout << "�������� ����������� �������� " << std::endl;
		}
		else if (*game == '2')
		{
			std::cout << "����� ��� ���������� ����������. ���������: " << *dist << std::endl;
			std::cout << "�������� ����������� �������� " << std::endl;
		}
		else if (*game == '3')
		{
			std::cout << "����� ��� ��������� � ���������� ����������. ���������: " << *dist << std::endl;
			std::cout << "�������� ����������� �������� " << std::endl;
		}
		bool tmp = false;
		while (!tmp)
		{
			std::cout << "1. �������-���������" << std::endl
				<< "2. ����� " << std::endl
				<< "3. ������� " << std::endl
				<< "4. ������� " << std::endl
				<< "5. ��� " << std::endl
				<< "6. �������-��������� " << std::endl
				<< "7. �����-������ " << std::endl
				<< "0. ��������� �����������" << std::endl;
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
				std::cout << "������������ ��� ����������!\n";

			std::cout << vehicle->back()->get_vehiclename() << " ������� ���������������!" << std::endl;
			std::cout << "������������������ ������������ ��������: ";
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
	std::cout << "��������� �����:\n";
	int j = 1;
	std::map<double, std::string> vehicle2;
	for (auto& i : *vehicle)
	{
		vehicle2.insert(std::pair <double, std::string>(i->time(dist), i->get_vehiclename()));
	}
	for (auto& i : vehicle2)
	{
		std::cout  << j++<<". " << i.second << " �����: " << i.first << std::endl;
	}
}

void mainMenu(int* dist, char* game)
{
	bool f = false;
	while (!f)
	{
		std::cout << "����� ���������� � �������� ���������!" << std::endl
			<< "1. ����� ��� ��������� ���������� " << std::endl
			<< "2. ����� ��� ���������� ���������� " << std::endl
			<< "3. ����� ��� ��������� � ���������� ����������" << std::endl
			<< "�������� ��� �����: ";
		std::cin >> *game;
		if (*game < 49 || *game > 51)
			std::cout << "�������� ����!\n";
		else
			f = true;
	}
	while (f)
	{
		std::cout << "������� ����� ��������� ( ������ ���� ������������): ";
		std::cin >> *dist;
		if (*dist <= 0)
			std::cout << "�������� ����!\n";
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
			std::cout << "������ ���� ����������������� ���� �� 2 ������������ ��������." << std::endl;
			reg(game, vehicle, dist, &change);
				
		}
		else
		{
			std::cout << "1. ���������������� ������������ ��������.\n";
			std::cout << "2. ������ �����.\n";
			std::cin >> z;
			if (z != '1' && z != '2')
				std::cout << "������������ �����!\n";
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
		std::cout << "\n\n1. �������� ��� ���� �����.\n2. �����.\n";
		std::cout << "�������� ��������: ";
		std::cin >> t;
	}
}