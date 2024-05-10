#include<iostream>
#include<fstream>

using namespace std;
struct coordinate
{
	int x, y;
};


template<class t>
class stackadt {
private:
	t* arr;
	int size;
	int current_size;
public:
	stackadt() {
		size = 10;
		current_size = -1;
		arr = new t[size];
	}
	stackadt(int size) {
		this->size = size;
		arr = new t[size];
		current_size = -1;
	}
	bool push(t val);
	bool pop(t& newval);
	bool isempty();
	bool isfull();
	bool top(t& val);
	~stackadt() {
		delete[] arr;
		arr = NULL;
	}
};

template<class t>
bool stackadt<t>::isfull() {
	if (current_size == size - 1) {
		cout << "stack full" << endl;
		return true;
	}
	return false;
}

template<class t>
bool stackadt<t>::isempty() {
	if (current_size == -1) {
		return true;
	}
	return false;
}

template<class t>
bool stackadt<t>::push(t val) {

	if (isfull() == true) {
		return false;
	}

	current_size++;
	arr[current_size] = val;
	return true;

}

template<class t>
bool stackadt<t>::pop(t& newval) {
	if (isempty()) {
		return false;
	}
	newval = arr[current_size];
	current_size--;
	return true;
}


template<class t>
bool stackadt<t>::top(t& newval) {
	if (isempty()) {
		return false;
	}

	newval = arr[current_size];
	return true;
}


int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

bool maze(char** arr, const int rows, const int cols) {
	// Finding first opening
	int x = -1, y = -1;
	for (int i = 0; i < cols; i++)
	{
		if (arr[0][i] == '-') {
			x = i;
			y = 0;
		}
	}
	// If opening is not found then return false;
	if (x == -1)
		return false;

	stackadt<coordinate> s1(rows * cols);
	coordinate firstIndex = { x,y };
	s1.push(firstIndex);

	while (s1.isempty() == false) {

		coordinate temp;
		s1.pop(temp);

		arr[temp.y][temp.x] = '*';

		if (temp.y == rows - 1)
			return true;

		for (int i = 0; i < 4; i++)
		{
			int new_x = temp.x + dx[i];
			int new_y = temp.y + dy[i];

			if (new_x >= 0 && new_y >= 0 && new_x < cols && new_y < rows && arr[new_y][new_x] == '-') {
				coordinate i = { new_x,new_y };
				s1.push(i);
			}
		}
	}
	return false;
}










int main()
{

	//part b
	stackadt<int>obj1(5);
	stackadt<char>obj2(5);
	int newval;
	cout << obj1.pop(newval);
	obj1.push(1);
	obj1.push(2);
	obj2.push('3');
	obj1.push(5);
	if (!obj1.isfull())
		obj1.push(4);
	for (int i = 0; i < 6; i++)
	{
		obj1.pop(newval);
		cout << newval;
	}

	cout << endl;








	// reading from file
	fstream myfile;
	int rows, cols;
	myfile.open("data.txt", ios::in);
	if (!myfile) {
		cout << "no such file" << endl;
	}
	else {
		myfile >> rows;
		myfile << endl;
		myfile >> cols;

		char** arr = new char* [rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new char[cols];

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				myfile >> arr[i][j];
			}
			myfile << endl;
		}





		if (maze(arr, rows, cols)) {
			cout << "Way out is found" << endl;
		}
		else {
			cout << "Way out is not found" << endl;
		}


		//deallocating memory
		for (int i = 0; i < rows; i++) {
			delete[] arr[i];
		}
		delete[] arr;
	}

}