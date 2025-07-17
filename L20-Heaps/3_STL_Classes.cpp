#include <iostream>
#include <queue> // heap is called priority_queue inside STL
#include <functional>
using namespace std;

class Student {
public:
	int marks;
	int age;
	string name;

	Student(string s, int a, int m) {
		age = a;
		marks = m;
		name = s;
	}

	void print() {
		cout << "Name  :" << name << endl;
		cout << "AGE   :" << age << endl;
		cout << "Marks :" << marks << endl << endl;
	}
};

class myClass {
public:
	bool operator() (Student a, Student b) { // Functor
		return a.name > b.name;
	}
};

int main() {

	priority_queue<Student, vector<Student>, myClass > h;

	Student a("Devansh", 21, 88);
	Student b("Daksh", 20, 89);
	Student c("Ankur", 22, 79);
	Student d("Pankaj", 19, 100);

	h.push(a);
	h.push(b);
	h.push(c);
	h.push(d);

	while (!h.empty()) {
		Student x = h.top();
		x.print();

		h.pop();
	}

	return 0;
}
















