import java.util.PriorityQueue;

class Student {
	int marks;
	int age;
	String name;

	Student(String name, int age, int marks) {
		this.name = name;
		this.age = age;
		this.marks = marks;
	}

	void print() {
		System.out.println("Name  : " + name);
		System.out.println("Age   : " + age);
		System.out.println("Marks : " + marks);
		System.out.println();
	}
}

class MyClass implements java.util.Comparator<Student> {
	public int compare(Student a, Student b) {
		return a.name.compareTo(b.name);
	}
}

public class Main {
	public static void main(String[] args) {
		PriorityQueue<Student> pq = new PriorityQueue<>(new MyClass());

		Student a = new Student("Devansh", 21, 88);
		Student b = new Student("Daksh", 20, 89);
		Student c = new Student("Ankur", 22, 79);
		Student d = new Student("Pankaj", 19, 100);

		pq.add(a);
		pq.add(b);
		pq.add(c);
		pq.add(d);

		while (!pq.isEmpty()) {
			Student x = pq.poll();
			x.print();
		}
	}
}








