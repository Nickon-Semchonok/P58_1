#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "product.h"
#include "price.h"

int main()
{
	setlocale(LC_ALL, "UA");
	Price* price = new Price();
	while (true) {
		int choice;
		std::cout << "Choice an action:\n"
			<< "1: Init price\n"
			<< "2: Load price\n"
			<< "3: Show by popularity\n"
			<< "4: Show from cheap to expensive\n"
			<< "5: Show from expensive to cheap\n"
			<< "6: Show by discount from low to high\n"
			<< "7: Show by discount from high to low\n"
			<< "0: Exit\n";

		choice = _getch();
		switch (choice) {
		case 49:  // '1'
			if (price->init()) {
				std::cout << "Price init success" << std::endl;
			}
			else {
				std::cout << "Price init error" << std::endl;
			}
			break;
		case 50:  // '2'
			if (price->load()) {
				std::cout << "Price load success" << std::endl;
			}
			else {
				std::cout << "Price load error" << std::endl;
			}
			break;
		case 51:  // '3'
			price->show_by_popularity();
			break;
		case 52:  // '4'
			price->show_by_price_ascending();
			break;
		case 53:  // '5'
			price->show_by_price_descending();
			break;
		case 54:  // '6'
			price->show_by_discount_ascending();
			break;
		case 55:  // '7'
			price->show_by_discount_descending();
			break;
		case 48:  // '0'
			return 0;
		default:
			std::cout << "Invalid choice" << std::endl;
		}
	}
	return 0;
}