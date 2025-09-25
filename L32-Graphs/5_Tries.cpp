#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
	char ch;
	bool isEnd;
	unordered_map<char, node*> h;
	node(char c) {
		ch = c;
		isEnd = false;
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node('\0');
	}

	void addWord(char *word) {
		node* temp = root; // we cannot lose root address
		for (int i = 0; word[i] != '\0' ; ++i)
		{
			char ch = word[i];
			if (temp->h.count(ch) == 0) {
				temp->h[ch] = new node(ch);
			}
			temp = temp->h[ch];
		}

		temp->isEnd = true;
	}

	bool isWordPresent(char*word) {
		node* temp = root;
		for (int i = 0; word[i] != '\0' ; ++i)
		{
			char ch = word[i];

			if (temp->h.count(ch) == 0) {
				return false;
			}

			temp = temp->h[ch];
		}

		return temp->isEnd;
	}

	void autoFillHelper(node* temp, string &word) {
		if (temp == NULL) {
			return;
		}

		if (temp->isEnd) {
			cout << word << endl;
		}

		for (auto p : temp->h) {
			word.push_back(p.first);
			autoFillHelper(p.second, word);
			word.pop_back();
		}
	}

	void autoFill(char *word) {
		node* temp = root;
		string x = "";
		for (int i = 0; word[i] != '\0' ; ++i)
		{
			char ch = word[i];
			x.push_back(ch);
			if (temp->h.count(ch) == 0) {
				return;
			}

			temp = temp->h[ch];
		}

		autoFillHelper(temp, x);
	}
};

int main() {

	Trie t;
	t.addWord("Hello");
	t.addWord("He");
	t.addWord("Her");
	t.addWord("HelloWorld");
	t.addWord("World");
	t.autoFill("Hel");
	// while (1) {
	// 	char key[100];
	// 	cin >> key;

	// 	if (t.isWordPresent(key)) cout << "Yes\n";
	// 	else cout << "No\n";
	// }

	return 0;
}
















