#include <iostream>
#include "Venicle.h"
#include "Camel.h"
#include "Centaur.h"
#include "Boots.h"
#include "Speedcamel.h"
#include <vector>
#include "Magiccarpet.h"
#include "Eagle.h"
#include "Broom.h"
#include <map>

void reg(char* game, std::vector<Venicle*>* venicle,int* dist, bool* change)
{
	char z;

	std::cout << "����� ��� ��������� ����������. ���������: " << *dist << std::endl;
	std::cout << "�������� ����������� �������� " << std::endl;
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
				venicle->push_back(new Boots());
				break;
			case '2':
				venicle->push_back(new Broom());
				break;
			case '3':
				venicle->push_back(new Camel());
				break;
			case '4':
				venicle->push_back(new Centaur());
				break;
			case '5':
				venicle->push_back(new Eagle());
				break;
			case '6':
				venicle->push_back(new Speedcamel());
				break;
			case '7':
				venicle->push_back(new Magiccarpet());
				break;
			case '0':
				return;
			}
		}
		else
			std::cout << "������������ ��� ����������!\n";
	}
	std::cout << venicle->back()->get_veniclename() << " ������� ���������������!" << std::endl;
	std::cout << "������������������ ������������ ��������: ";
	size_t y = 0;
	for (auto& i : *venicle)
	{
		std::cout << i->get_veniclename();
		y++;
		if (y != venicle->size())
			std::cout << ", ";
		else
			std::cout << "." << std::endl;

	}
}

void racing(std::vector<Venicle*>* venicle,int* dist)
{
	system("cls");
	std::cout << "��������� �����:\n";
	int j = 1;
	std::map<double, std::string> venicle2;
	for (auto& i : *venicle)
	{
		venicle2.insert(std::pair <double, std::string>(i->time(dist), i->get_veniclename()));
	}
	for (auto& i : venicle2)
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

void gameMenu(char* game, std::vector<Venicle*>* venicle, int *dist)
{
	char z;
	bool change = false;
	while (!change)
	{
		if (venicle->size() < 2)
		{
			std::cout << "������ ���� ����������������� ���� �� 2 ������������ ��������." << std::endl;
			std::cout << "1. ���������������� ������������ ��������.";
			std::cin >> z;
			if (z != '1')
				std::cout << "������������ �����!\n";
			else
				reg(game, venicle, dist, &change);
		}
		else
		{
			std::cout << "1. ���������������� ������������ ��������.\n";
			std::cout << "2. ������ �����.\n";
			std::cin >> z;
			if (z != '1' && z != '2')
				std::cout << "������������ �����!\n";
			else if (z == '1')
				reg(game, venicle, dist, &change);
			else
				change = true;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector<Venicle*> venicle;
	char game;
	int dist;
	int t = 1;
	while (t == 1)
	{
		mainMenu(&dist, &game);
		gameMenu(&game, &venicle, &dist);
		racing(&venicle, &dist);
		venicle.clear();
		std::cout << "\n\n1. �������� ��� ���� �����.\n2. �����.\n";
		std::cout << "�������� ��������: ";
		std::cin >> t;
	}
}