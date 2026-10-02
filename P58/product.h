#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <fstream>

struct Product {
	std::string name = "";
	float price = 0.0f;
	int stock = 0;
	int discount_percent = 0;
	int order = 0;

	bool load_from_file(std::ifstream& file);
	void save_to_file(std::ofstream& file) const;
	std::string to_string();
};

#endif  

