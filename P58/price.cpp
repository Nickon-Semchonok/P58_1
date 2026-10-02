#include "price.h"
#include <iostream>

bool Price::init() {
	std::ofstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error" << std::endl;
		return false;
	}
	Product product = { "Black Pencil", 14.95f, 20, 0 };
	product.save_to_file(file);

	product = { "Blue Pen", 19.95f, 25, 5 };
	product.save_to_file(file);

	product = { "Green Whiteboard Marker", 17.50f, 10, 10 };
	product.save_to_file(file);

	product = { "Lined Copybook", 7.50f, 20, 10 };
	product.save_to_file(file);

	product = { "Grided Copybook", 7.50f, 20, 5 };
	product.save_to_file(file);

	product = { "Ruller 30cm", 3.50f, 50, 0 };
	product.save_to_file(file);

	file.close();
	return true;
}

bool Price::load() {
	std::ifstream file(PRICE_FILENAME);
	if (!file.is_open()) {
		std::cout << "File open error" << std::endl;
		return false;
	}
	ListNode* last = NULL;
	if (first) {
		do {
			last = first->next;
			delete first;
			first = last;
		} while (first);
	}
	Product product;
	int current_order = 1;
	while (product.load_from_file(file)) {
		product.order = current_order++;
		if (last == NULL) {
			first = last = new ListNode;
			last->product = product;
			last->next = NULL;
		}
		else {
			last->next = new ListNode;
			last->next->product = product;
			last->next->next = NULL;
			last = last->next;
		}
	}
	file.close();
	return true;
}

void Price::show() const {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	ListNode* node = first;
	while (node) {
		std::cout << node->product.to_string() << std::endl;
		node = node->next;
	}
}

void Price::_swap12() {
	ListNode* tmp;
	tmp = first->next;         
	first->next = tmp->next;   
	tmp->next = first;         
	first = tmp;
}

void Price::_swap23(ListNode* node) {
	ListNode* tmp;
	tmp = node->next;             
	node->next = tmp->next;       
	tmp->next = tmp->next->next;  
	node->next->next = tmp;       
}

void Price::show_by_price_descending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
		ListNode* node = first;
		if (node->product.price < node->next->product.price) {
			_swap12();
			node = first;
			is_ordered = false;
		}
		while (node->next->next) {
			if (node->next->product.price < node->next->next->product.price) {
				_swap23(node);
				is_ordered = false;
			}
			node = node->next;
		}
	} while (!is_ordered);
	show();
}

void Price::show_by_price_ascending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
		ListNode* node = first;
		if (node->product.price > node->next->product.price) {
			_swap12();
			node = first;
			is_ordered = false;
		}
		while (node->next->next) {
			if (node->next->product.price > node->next->next->product.price) {
				_swap23(node);
				is_ordered = false;
			}
			node = node->next;
		}
	} while (!is_ordered);
	show();
}

void Price::show_by_discount_ascending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
		ListNode* node = first;
		if (node->product.discount_percent > node->next->product.discount_percent) {
			_swap12();
			node = first;
			is_ordered = false;
		}
		while (node->next->next) {
			if (node->next->product.discount_percent > node->next->next->product.discount_percent) {
				_swap23(node);
				is_ordered = false;
			}
			node = node->next;
		}
	} while (!is_ordered);
	show();
}

void Price::show_by_discount_descending() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
		ListNode* node = first;
		if (node->product.discount_percent < node->next->product.discount_percent) {
			_swap12();
			node = first;
			is_ordered = false;
		}
		while (node->next->next) {
			if (node->next->product.discount_percent < node->next->next->product.discount_percent) {
				_swap23(node);
				is_ordered = false;
			}
			node = node->next;
		}
	} while (!is_ordered);
	show();
}

void Price::show_by_popularity() {
	if (first == NULL) {
		std::cout << "Price is empty" << std::endl;
		return;
	}
	if (first->next == NULL) {
		std::cout << first->product.to_string() << std::endl;
		return;
	}
	bool is_ordered;
	do {
		is_ordered = true;
		ListNode* node = first;
		if (node->product.order > node->next->product.order) {
			_swap12();
			node = first;
			is_ordered = false;
		}
		while (node->next->next) {
			if (node->next->product.order > node->next->next->product.order) {
				_swap23(node);
				is_ordered = false;
			}
			node = node->next;
		}
	} while (!is_ordered);
	show();
}