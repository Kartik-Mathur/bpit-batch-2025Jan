#include <iostream>
using namespace std;

class node {
public:
	string key;
	int data;
	node* next;

	node(string k, int d) {
		key = k;
		data = d;
		next = NULL;
	}
};

class hashmap {
	node** h;
	int ts; // 5
	int cs; // to know when to do rehashing

	void rehashing() {
		node** oldh = h;
		int oldts = ts;

		h = new node*[2 * ts];
		ts *= 2;

		for (int i = 0; i < ts; ++i)
		{
			h[i] = NULL;
		}

		cs = 0; // Because new array h ke andar koi data nhi hai as such

		for (int i = 0; i < oldts; ++i)
		{
			node* t = oldh[i];
			while (t) {
				string k = t->key;
				int v = t->data;

				insert(k, v);

				t = t->next;
			}
		}
	}

	int hashIndex(string key) {
		int ans = 0;
		int mul = 1;
		for (int i = 0; i < key.size(); ++i)
		{
			ans += (key[i] % ts) * (mul % ts);
			ans %= ts;

			mul *= 17;
			mul %= ts;
		}

		return ans % ts;
	}
public:

	hashmap(int s = 5) {
		h = new node*[s];
		ts = s;
		cs = 0; // Abhi table ke andar koi element nhi add kia hai humne
		for (int i = 0; i < ts; ++i)
		{
			h[i] = NULL;
		}
	}

	void insert(string key, int value) {
		if (search(key) != NULL) return;

		node* n = new node(key, value);
		int i = hashIndex(key);

		n->next = h[i];
		h[i] = n;
		cs++;

		float loadFactor = cs / (ts * 1.0);
		if (loadFactor >= 0.5) {
			rehashing(); // To be implemented
		}
	}

	void print() {

		for (int i = 0; i < ts; ++i)
		{
			cout << i << " : ";
			node* t = h[i];
			while (t) {
				cout << "(" << t->key << ", " << t->data << ") ";

				t = t->next;
			}
			cout << "\n";
		}
	}

	node* search(string key) {
		int indx = hashIndex(key);

		node* t = h[indx];

		while (t) {
			if (t->key == key) return t;

			t = t->next;
		}

		return NULL;
	}


	int& operator[](string key) {
		node* ans = search(key);

		if (ans == NULL) {
			insert(key, -1); // Value abhi kuch bhi daal do
		}

		ans = search(key); //ab 100% key present hogi

		return ans -> data;
	}

};

int main() {

	hashmap h;

	h.insert("Mango", 100);
	h.insert("Apple", 120);
	h.insert("Kiwi", 70);
	h.insert("Papaya", 70);
	h.insert("Guava", 70);
	h.insert("Orange", 70);


	node* ans = h.search("Orange");
	if (ans) cout << ans->key << ", " << ans->data << endl;
	else cout << "Key Not found\n";

	h["Pineapple"] = 100; // Upar se Pineapple ki data bucket by reference aaegi

	h["Pineapple"] = 120; // Upar se Pineapple ki data bucket by reference aaegi

	cout << h["Pineapple"] << endl;


	h.print();


	return 0;
}
















