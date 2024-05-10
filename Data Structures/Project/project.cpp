/*
21L-6291
21L-5662
21L-5674
*/


#include <iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
using namespace std;
void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct node
{
	char data;
	node* left;
	node* right;
	node* up;
	node* down;
	int xcord;
	int ycord;
};
class TwoDLLADT
{
	node* start;
	node* current;
	int x, y;
	void insert_start(node*& current, node* temp) {

		temp->xcord = current->xcord;
		temp->ycord = current->ycord;
		int x1 = current->xcord;
		if (current->up == NULL && current->down == NULL) {
			temp->right = start;
			start->left = temp;
			start = temp;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}

		}
		else if (current->up == NULL) {
			temp->right = current;
			current->left = temp;
			start = temp;
			start->down = current->down;
			current->down->up = start;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}
			if (current != NULL) {
				t = current;

				node* d = t->down;
				while (d->right != NULL) {
					d = d->right;
					if (t != NULL) {
						t->down = d;
						d->up = t;
						t = t->right;
					}
				}
			}

		}
		else if (current->down == NULL) {
			temp->right = current;
			current->left = temp;
			current->up->down = temp;
			temp->up = current->up;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}
			if (current != NULL) {
				t = current;
				node* d = current->up;
				while (d->right != NULL) {
					d = d->right;
					while (t != NULL) {
						d->down = t;
						t->up = d;
						t = t->right;
					}
				}
			}

		}
		else {
			temp->right = current;
			current->left = temp;
			current->up->down = temp;
			temp->up = current->up;
			current->down->up = temp;
			temp->down = current->down;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}

			if (current != NULL) {
				t = current;
				node* d = current->up;
				while (d->right != NULL) {
					d = d->right;
					while (t != NULL) {
						d->down = t;
						t->up = d;
						t = t->right;
					}
				}
				t = current;
				node* f = current->down;
				while (f->right != NULL) {
					f = f->right;
					while (t != NULL) {
						t->down = f;
						f->up = t;
						t = t->right;
					}
				}
			}
		}
		x++;
	}

	void insert_between(node*& current, node* temp) {
		temp->xcord = current->xcord;
		temp->ycord = current->ycord;
		int x1 = current->xcord;
		if (current->up == NULL && current->down == NULL) {
			current->left->right = temp;
			temp->left = current->left;
			temp->right = current;
			current->left = temp;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}
		}
		else if (current->up == NULL) {
			temp->left = current->left;
			current->left->right = temp;
			temp->right = current;
			current->left = temp;
			current->down->up = temp;
			temp->down = current->down;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}
			if (current != NULL) {
				t = current;
				node* d = current->down;
				while (d->right != NULL) {
					d = d->right;
					if (t != NULL) {
						t->down = d;
						d->up = t;
						t = t->right;
					}
				}
			}

		}
		else if (current->down == NULL) {
			temp->left = current->left;
			current->left->right = temp;
			temp->right = current;
			current->left = temp;
			temp->up = current->up;
			current->up->down = temp;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}
			/*if (current != NULL) {
				t = current;
				node* u = current->up;
				while (u->right) {
					u = u->right;
					while(u != NULL) {
						u->down = t;
						t->up = u;
						t = t->right;
					}
				}
			}*/
		}
		else {
			temp->left = current->left;
			current->left->right = temp;
			temp->right = current;
			current->left = temp;
			temp->up = current->up;
			current->up->down = temp;
			temp->down = current->down;
			current->down->up = temp;
			node* t = current;
			while (t) {
				t->xcord = ++x1;
				t = t->right;
			}

		}
		x++;


	}
	void insert_end(node*& current, node* temp) {
		temp->xcord = x;
		temp->ycord = y;
		if (current->up == NULL && current->down == NULL) {
			current->right = temp;
			temp->left = current;
			current = temp;
		}
		else if (current->up == NULL) {
			node* prev = current->down;
			if (prev->right == NULL) {
				current->right->left = temp;
				temp->right = current->right;
				temp->left = current;
				current->right = temp;
				current = temp;
			}
			else {
				prev = prev->right;
				current->right->left = temp;
				temp->right = current->right;
				temp->left = current;
				current->right = temp;
				temp->down = prev;
				prev->up = temp;
				current = temp;

			}
		}
		else if (current->down == NULL) {
			node* d = current->up;
			if (d->right == NULL) {
				current->right = temp;
				temp->left = current;
				current = temp;
			}
			else {
				d = d->right;
				temp->left = current;
				current->right = temp;
				current = temp;
				d->down = current;
				current->up = d;
			}
		}
		else {
			node* u = current->up;
			node* d = current->down;
			if (u->right == NULL || d->right == NULL) {
				if (u->right == NULL) {

				}
				else {

				}
			}

		}

		x++;
	}
	void delete2(node*& current)
	{
		node* temp = current;
		temp->xcord = x;
		temp->ycord = y;
		int x1 = current->xcord;

		if (temp->up == NULL && temp->down == NULL)
		{
			if (temp->left != NULL)
			{
				temp->left->right = temp->right;

				if (temp->right != NULL)
				{
					temp->right->left = temp->left;
				}

				current = current->left;
				delete temp;

				/*node* f = current;
				while (f != NULL)
				{
					f = f->right;
					x1--;
					f->xcord = x1;
				}*/

				x--;
			}

			else if (temp->right != NULL)
			{
				start = start->right;
				current = start;
				current->left = NULL;
				delete temp;

				/*while (t) {
					t->xcord = --x1;
					t = t->right;
				}*/
			}
		}

		else if (temp->up != NULL)
		{

			if (temp->left != NULL)
			{
				temp->left->right = temp->right;

				node* z = current->up;
				node* x = current->down;
				node* j = current;

				if (temp->right != NULL)
				{
					temp->right->left = temp->left;
				}

				if (z != NULL)
				{
					while (z != NULL)
					{
						j = j->right;

						if (j == NULL)
							break;

						z->down = j;
						j->up = z;
						z = z->right;
					}
				}

				j = current;

				if (x != NULL)
				{
					while (x != NULL)
					{
						j = j->right;

						if (j == NULL)
							break;

						x->up = j;
						j->down = x;
						x = x->right;
					}
				}

				current = current->left;
				delete temp;
			}

			else if (temp->right != NULL)
			{
				node* z = current->up;
				node* x = current->down;
				node* j = current;

				if (temp->right != NULL)
				{
					temp->right->left = temp->left;
				}

				if (z != NULL)
				{
					while (z != NULL)
					{
						j = j->right;

						if (j == NULL)
							break;

						z->down = j;
						j->up = z;
						z = z->right;
					}
				}

				j = current;

				if (x != NULL)
				{
					while (x != NULL)
					{
						j = j->right;

						if (j == NULL)
							break;

						x->up = j;
						j->down = x;
						x = x->right;
					}
				}

				current = current->right;
				current->left = NULL;
				delete temp;
			}
		}

		/*node* t = current;
		node* d = t->down;

		while (d->right != NULL)
		{
			d = d->right;
			if (t != NULL)
			{
				t->down = d;
				d->up = t;
				t = t->right;
			}
		}*/

		/*node* f = current;
		while (f) {
			f->xcord = --x1;
			f = f->right;
		}*/
	}
public:
	TwoDLLADT()
	{
		start = NULL;
		current = NULL;
		x = 0;
		y = 0;
	}
	void delete1()
	{
		if (start == NULL)
			return;

		else
			delete2(current);
	}
	void insert(char val)
	{
		node* temp = new node;
		temp->data = val;
		temp->up = temp->down = temp->left = temp->right = NULL;

		if (start == NULL)
		{
			temp->xcord = x;
			temp->ycord = y;
			start = current = temp;
			x++;
		}
		else if (current->right == NULL) {
			insert_end(current, temp);
		}
		else if (current->right->right == NULL) {
			insert_between(current, temp);
		}
		else if (current->left == NULL) {
			insert_start(current, temp);
		}
		else {
			insert_between(current, temp);
		}

	}

	void insert1(char val) {
		node* temp = new node;
		temp->data = val;
		temp->up = temp->down = temp->left = temp->right = NULL;
		y++;
		x = 0;
		temp->xcord = x;
		temp->ycord = y;
		while (current->left != NULL)
			current = current->left;
		current->down = temp;
		temp->up = current;
		current = temp;
		x++;

	}
	void save() {
		ofstream myfile("save.txt");
		node* cur = start;
		while (cur) {
			node* temp = cur;
			while (temp) {
				myfile << temp->data;
				temp = temp->right;
			}
			cur = cur->down;
		}
		myfile.close();
	}
	void load() {
		char ch;
		ifstream myfile("save.txt");
		while (myfile >> noskipws >> ch) {
			if (ch == '\n') {
				insert(ch);
				myfile >> ch;
				insert1(ch);
				continue;
			}
			insert(ch);
		}
		myfile.close();
	}
	void move_left() {
		if (current->left == NULL)
			return;
		current = current->left;
	}
	void move_right() {
		if (current->right == NULL || current->right->right == NULL)
			return;
		current = current->right;
	}
	void move_up() {
		if (current->up == NULL || current->up->data == '\n')
			return;
		current = current->up;
	}
	void move_down() {
		if (current->down == NULL)
			return;
		current = current->down;
	}
	void display()
	{
		node* cur = start;
		while (cur)
		{
			node* temp = cur;
			while (temp) {
				gotoxy(temp->xcord, temp->ycord);
				cout << temp->data;
				temp = temp->right;
			}
			cur = cur->down;
		}
		gotoxy(100, 29);
		cout << "Cursor :" << current->data;
	}
	void delete_notepad() {
		if (start == NULL) {
			return;
		}
		node* cur = start;
		while (cur) {
			node* temp = cur;
			cur = cur->down;
			while (temp->right) {
				node* t = temp;
				temp = temp->right;
				delete t;
			}
		}
		start = NULL;
		current = 0;
		x = 0;
		y = 0;
	}
	~TwoDLLADT() {
		delete_notepad();
	}
};
void run(TwoDLLADT &n) {
	//TwoDLLADT n;
	while (1) {
		gotoxy(1, 29);
		cout << "Press CTRL + s to save to file";
		gotoxy(35, 29);
		cout << "Press ESC to return to main menu";
		gotoxy(70, 29);
		cout << "Press CTRL + l to load file";
		char c = _getch();
		if (c == 27) {
			break;
		}
		else if (c == 19) {
			n.save();
		}
		else if (c == 12) {
			n.load();
			n.display();
		}
		else if (c == '\r') {
			n.insert('\n');
			c = _getch();
			n.insert1(c);
			system("cls");
			n.display();
		}
		else if (c == '\b' || c == 127) {
			n.delete1();
			system("cls");
			n.display();
		}
		else if (c == -32) {
			c = _getch();
			if (c == 72) {
				n.move_up();
				system("cls");
				n.display();
			}
			if (c == 75) {
				n.move_left();
				system("cls");
				n.display();
			}
			if (c == 77) {
				n.move_right();
				system("cls");
				n.display();
			}
			if (c == 80) {

				n.move_down();
				system("cls");
				n.display();
			}
		}
		else {
			n.insert(c);
			system("cls");
			n.display();
		}

	}
}
int main()
{
	TwoDLLADT n;
	int choice;
	bool flag = true;
	//while (flag) {
	
	while (flag) {
		system("cls");
		cout << "Enter 1 to open notepad" << endl;
		cout << "Enter 2 to to load saved file" << endl;
		cout << "Enter 3 to exit" << endl;
		cout << "Enter Choice:";
		cin >> choice;
		switch (choice) {
		case 1:
			system("cls");
			run(n);
			break;
		case 2:
			n.delete_notepad();
			n.load();
			system("cls");
			n.display();
			run(n);
			break;
		case 3:
			flag = false;
		}
	}
		/*while (1) {
			gotoxy(1, 29);
			cout << "Press CTRL + s to save to file";
			gotoxy(40, 29);
			cout << "Press ESC to exit";
			gotoxy(70, 29);
			cout << "Press CTRL + l to load file";
			char c = _getch();
			if (c == 27) {
				break;
			}
			else if (c == 19) {
				n.save();
			}
			else if (c == 12) {
				n.load();
				n.display();
			}
			else if (c == '\r') {
				n.insert('\n');
				c = _getch();
				n.insert1(c);
				system("cls");
				n.display();
			}
			else if (c == -32) {
				c = _getch();
				if (c == 72) {
					n.move_up();
					system("cls");
					n.display();
				}
				if (c == 75) {
					n.move_left();
					system("cls");
					n.display();
				}
				if (c == 77) {
					n.move_right();
					system("cls");
					n.display();
				}
				if (c == 80) {

					n.move_down();
					system("cls");
					n.display();
				}
			}
			else {
				n.insert(c);
				system("cls");
				n.display();
			}

		}*/
	

	//}
	//}
}
