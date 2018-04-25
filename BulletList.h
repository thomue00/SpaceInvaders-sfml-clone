#pragma once
#ifndef BULLETLISTH
#define BULLETLISTH

#include "Bullet.h"

struct BulletNode {

	Bullet data;
	BulletNode *next;
};

class BulletList {

public:
	BulletList() {

		head = NULL;
		tail = NULL;
	}

	void Add(Bullet value) {

		BulletNode *tmp = new BulletNode;
		tmp->data = value;
		tmp->next = NULL;
		if (head == NULL) {

			head = tmp;
			tail = tmp;
			tmp = NULL;
		}
		else {

			tail->next = tmp;
			tail = tmp;
		}
	}

	void Draw(sf::RenderWindow &win) {

		BulletNode *tmp = new BulletNode;
		tmp = head;
		while (tmp != NULL) {

			tmp->data.Draw(win);
			tmp = tmp->next;
		}
	}

private:
	BulletNode *head;
	BulletNode *tail;
};

#endif