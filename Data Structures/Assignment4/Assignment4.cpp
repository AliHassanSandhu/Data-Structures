//21L-6291
//21L-5674
#include <iostream>
#include <random>
#include<ctime>
#include<Windows.h>
#include <fstream>
#include <cmath>
using namespace std;

template <class T>
class HeapADT
{
	T* arr;
	int size;
	int current;

public:
	HeapADT()
	{
		size = 50;
		arr = new T[size];
		current = 0;
	}

	HeapADT(int size)
	{
		this->size = size;
		arr = new T[size];
		current = 0;
	}

	void insert(T val)
	{
		arr[current] = val;

		int child = current;
		while (child > 0 && arr[child] > arr[(child - 1) / 2])
		{
			int parent = (child - 1) / 2;
			if (arr[child] > arr[parent])
				swap(arr[child], arr[parent]);
			child = parent;
		}

		current++;
	}


	T remove()
	{
		T temp = arr[0];
		arr[0] = arr[current - 1];
		int i = 0;
		while (i < current)
		{
		    int p = i;
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			if (left < current && arr[left] > arr[p])
			{
				swap(arr[left], arr[p]);
				p = left;
			}
			if (right < current && arr[right] > arr[p])
			{
				swap(arr[right], arr[p]);
				p = right;
			}
			if (p == i)
				break;
			i = p;
		}
		current--;
		return temp;
	}
	bool isEmpty() {
		if (current == 0)
			return true;
		return false;
	}
	void display()
	{
		cout << "Heap = ";
		for (int i = 0; i < current; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~HeapADT()
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
	}
};
struct Program
{
	float ProgramAge;
	int ProgramNumber;
	int priority_level;

	bool operator>(const Program& other) const
	{
		// Compare based on priority_level 
		if (priority_level > other.priority_level)
			return true;
		else if (priority_level < other.priority_level)
			return false;
	}

};

Program getNextProgram()
{
	Program p;
	p.ProgramAge = (float)rand() / (float)(RAND_MAX / 15); // produce random age between 0-15
	p.priority_level = rand() % 3;                         // produce random priority to 0,1 or 2
	static int a = 0;
	p.ProgramNumber = a;
	a++;
	return p;
}

void ProcessThis(Program p)
{
	fstream file("config.txt", ios::app);
	file << "       "
		<< "Program Number = " << p.ProgramNumber << ","
		<< "Program Age = " << ceil(p.ProgramAge * 100) / 100 << endl;
}
	


int main()
{
	srand(time(0));
	HeapADT<int> h(10);
	h.insert(10);
	h.insert(11);
	h.insert(9);
	h.insert(5);
	h.insert(8);
	h.display();

	HeapADT<Program> low(10);
	HeapADT<Program> mid(10);
	HeapADT<Program> high(10);

	Program pro[6];
	fstream myfile("progseq.txt", ios::out);

	int n1 = 0, n2 = 0, n3 = 0;
    for (int i = 0; i < 6; i++)
	{
		time_t now = time(0);
		char str[26];
		Sleep(250);
		ctime_s(str,sizeof str,&now);
	    pro[i] = getNextProgram();
		if (pro[i].priority_level == 0)
			low.insert(pro[i]);
		if (pro[i].priority_level == 1)
			mid.insert(pro[i]);
		if (pro[i].priority_level == 2)
			high.insert(pro[i]);
		myfile << "Program Age = " << ceil((pro[i].ProgramAge) * 100) / 100 << "      "
			<< "Program Number = " << pro[i].ProgramNumber << "      "
			<< "Creation time = " << str << endl;
	}
	fstream file("config.txt", ios::app);
	Program p;
	file << "high" << endl;
	while (high.isEmpty() != true) {
		p = high.remove();
		ProcessThis(p);
	}

	file << "Mid" << endl;
	while (mid.isEmpty() != true) {
		p = mid.remove();
		ProcessThis(p);
	}

	file << "Low" << endl;
	while (low.isEmpty() != true) {
		p = low.remove();
		ProcessThis(p);
	}

	
}
