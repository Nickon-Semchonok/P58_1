#pragma once
#include "product.h"

struct ListNode {
	Product product;
	ListNode* next = NULL;
};

struct Price {
	const std::string PRICE_FILENAME = "price.txt";
	ListNode* first = NULL;

	bool init();
	bool load();
	void show() const;
	void show_by_price_ascending();
	void show_by_price_descending();
	void show_by_discount_ascending();
	void show_by_discount_descending();
	void show_by_popularity();

private:
	void _swap12();
	void _swap23(ListNode* node);
};