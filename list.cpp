//Linked List manipulation
#include <iostream> 
#include <string>
using namespace std;


template <typename E>
struct Node {
	Node() :next(NULL), elem(NULL) {}

	Node<E>* next;
	E elem;
};


template <typename E>
class SLinkedList {
public:
	SLinkedList() :head(NULL), size_(0) {}

	bool const empty() { return size_ == 0; }
	size_t size() { return size_; }

	friend ostream& operator<<(ostream& os, const SLinkedList& sll) {
		if (sll.empty()) { cout << "empty list..." << endl; }
		Node* p = head;
		while (p != NULL) {
			os << *p << " ";
			p = p->next;
		}
		return os;
	}
	friend istream& operator>>(istream& is, SLinkedList& sll) {
		return is >> sll.elem;
	}

	Node<E>* front() { return head; }

 
	void pop_front() {
		if (empty()) {
			throw new std::invalid_argument("Cannot pop empty list...");
		}
		Node<E>* p = head;
		head = head->next;
		p->next_ = NULL;
		--size_;
	}

	void addToEndOfList(const E& data) {
		Node<E>* newNode = new Node<E>;
		newNode->elem = data;
		Node<E>* p = head;
		if (empty()) {
			head = newNode;
		}
		else {
			while (p->next != NULL) {
				p = p->next;
			}
			p->next = newNode;
		}
		size_++;
	}

	void rotateLeft(int times) {
		if (size_ < 2) { return; }
		Node<E>* p = front();
		pop_front();
		addToEndOfList(p);
	}



private:
	Node<E>* head;
	size_t size_;
};


int* intFun(SLinkedList<int>* i) {
	int integer = 0;
	int intArr[5];
	int count = 1, digit = 0;
	cout << "Enter an interger: ";
	cin >> integer;

	while (integer > 0) {
		digit = integer % 10;			//digit = 12 % 10 = 2
		integer /= 10;					//integer = 12 / 10 = 1
		count++;						//count = 2

	}


	return 0;
}
string stringFun(SLinkedList<string>* s) {

	return "end";
}
char charFun(SLinkedList<char>* c) {

	return 'n';
}


int main() {
	char type;

	cout << "Welcome to Linked List Data Manipulation" << endl << endl;


	do {
		cout << "Enter type of list: " << endl;
		cout << "1. Integer" << endl;
		cout << "2. String" << endl;
		cout << "3. Character" << endl;
		cin >> type;
	

		switch (type) {
		case 1:
			SLinkedList<int>* i = new SLinkedList<int>;
			intFun(i);
			break;
		case 2:
			SLinkedList<string>* s = new SLinkedList<string>;
			stringFun(s);
			break;
		case 3:
			SLinkedList<char>* c = new SLinkedList<char>;
			charFun(c);
			break;
		case -1:
			exit(-1);
		default:
			cout << "Invalid option..." << endl;
		}
	} while (type != -1);
	
	return 0;
}
