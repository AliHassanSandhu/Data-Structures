#include<iostream>
#include<random>
#include<fstream>
#include<cmath>
using namespace std;
template<class T>
class QueueADT {
private:
	T* queue;
	int max;
	int rear;
	int front;
public:
	QueueADT() {
		max = 10;
		rear = front = 0;
		queue = new T[max];

	}
	QueueADT(int size) {
		max = size;
		rear = front = 0;
		queue = new T[max];
	}
	bool IsFull() {
		if (front == (rear + 1) % max)
			return true;
		return false;
	}
	bool Enque(T a) {
		if (IsFull())
			return false;
		
		queue[rear] = a;
		rear = (rear + 1) % max;
		return true;
	}
	bool IsEmpty() {
		if (front == rear)
			return true;
		return false;
	}
	bool Deque(T & a) {
		if (IsEmpty())
			return false;

		  a = queue[front];
		front = (front + 1) % max;
		return true;
	}
	~QueueADT() {
		delete[] queue;
		queue = nullptr;
	}

};
struct program {
	float ProgramAge;
    int programNumber;
	int priority_level;
};
void ProcessThis(program p) {
	fstream file("config.txt",ios::app);
	file <<"       " << "Program Number = " << p.programNumber << "," << "Program Age = " << ceil(p.ProgramAge *100)/100 << endl;
}

void descending(program prog[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (prog[i].ProgramAge < prog[j].ProgramAge) {
				float temp = prog[i].ProgramAge;
				prog[i].ProgramAge = prog[j].ProgramAge;
				prog[j].ProgramAge = temp;
			}
		}
	}
}
program getNextProgram() {
    program p;
	p.ProgramAge = (float)rand() / (float) (RAND_MAX / 15);  //produce random age between 0-15
	p.priority_level = rand() % 3; // produce random priority to 0,1 or 2
    p.programNumber = 0;
	static int a = 0;
	p.programNumber = a;
	a++;
	return p;
}
int main() {
	QueueADT<int>obj1;
	QueueADT<char>obj2;
	int newval;
	cout<<obj1.Deque(newval);
	obj1.Enque(1);
	obj1.Enque(2);
	obj2.Enque('3');
	obj1.Enque(5);
	if (!obj1.IsFull())
		obj1.Enque(4);
	for (int i = 0; i < 6; i++)
	{
		obj1.Deque(newval);
		cout<< newval;
	}

	QueueADT<program>low;
	QueueADT<program>high;
	QueueADT<program>mid;
	
	program pro[6];
	program l[5];
	program m[5];
	program h[5];
	fstream myfile("progseq.txt",ios::out);

	int n1 = 0, n2 = 0, n3 = 0;
	for (int i = 0; i < 6; i++) {
		pro[i] = getNextProgram();
		myfile <<"Program Age = "<< ceil((pro[i].ProgramAge)*100)/100 << "      " << "Program Number = "<<pro[i].programNumber << endl;
	}
	for (int i = 0; i < 6; i++) {
		if (pro[i].priority_level == 0) {
			l[n1] = pro[i];
			n1++;
		}

		else if (pro[i].priority_level == 1) {
			m[n2] = pro[i];
			n2++;
		}
		else if (pro[i].priority_level == 2)
		{
			h[n3] = pro[i];
			n3++;
		}
	}
	//Sorting programs for Queues
	descending(l,n1);
	descending(m, n2);
	descending(h, n3);

	//Inserting Elemnets based on priority
	for (int i = 0; i < n1; i++) {
		low.Enque(l[i]);
	}
	for (int i = 0; i < n2; i++) {
		mid.Enque(m[i]);
	}
	for (int i = 0; i < n3; i++) {
		high.Enque(h[i]);
	}
	//processing the queue and writing in file
	fstream file;
	file.open("config.txt", ios::app);
	if (!file) {
		cout << "No such File " << endl;
	}
	file << "High :" << endl;
	for (int i = 0; i < n3; i++) {
		ProcessThis(h[i]);
	}
	file.close();
	file.open("config.txt", ios::app);
	if (!file) {
		cout << "No such File " << endl;
	}
	file << "Mid :" << endl;
	for (int i = 0; i < n2; i++) {
		ProcessThis(m[i]);
	}
	file.close();
	file.open("config.txt", ios::app);
	if (!file) {
		cout << "No such File " << endl;
	}
	file << "Low :" << endl;
	for (int i = 0; i < n1; i++) {
		ProcessThis(l[i]);
	}


	
}