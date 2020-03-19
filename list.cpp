//Linked List manipulation
#include <iostream> 
#include <string>
using namespace std;


template <typename E>
struct Node {
	Node() :elem(NULL), next(NULL) {}
	Node(const E& elem, Node<E>* next = nullptr) :
		elem(elem), next(next) {}

	friend ostream& operator<<(ostream& os, const Node<E>& n) {
		os << n.elem << ", ";
		os << n.next;
		return os;
	}
	friend istream& operator>>(istream& is, Node<E>& n) {
		return is >> n; 
	}

	E elem;
	Node<E>* next;
};


template <typename E>
class SLinkedList {
public:
	SLinkedList() :head(NULL), size_(0) {}

	bool const empty() { return size_ == 0; }
	size_t size() { return size_; }

	friend ostream& operator<<(ostream& os, const SLinkedList<E>& sll) {
		if (sll.empty()) { return os << "empty list..." << endl; }
		Node<E>* p = head;
		while (p != NULL) {
			os << *p << " ";
			p = p->next;
		}
		return os;
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
		if (empty()) { head = newNode; }
		else {
			while (p->next != NULL) {
				p = p->next;
			}
			p->next = newNode;
		}
		size_++;
	}
	void addToFrontOfList(const E& data) {
		Node<E>* newNode = new Node<E>;
		newNode->elem = data;
		Node<E>* p = head;
		if (empty()) { head = newNode; }
		else {
			newNode->next = p;
			head->next = newNode;
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


SLinkedList<int>* intFun(SLinkedList<int>* i) {
	int integer = 0;
	cout << endl << "Enter an interger: ";
	cin >> integer;		//integer = 123

	while (integer >= 10) {
		int digit = integer % 10;		//digit = 123 % 10 = 3  ------  digit = 12 % 10 = 2
		integer /= 10;					//integer = 123 / 10 = 12 ----  integer = 12 / 10 = 1
		i->addToFrontOfList(digit);
	}

	i->addToFrontOfList(integer);

	return i;
}

SLinkedList<string>* stringFun(SLinkedList<string>* s) {

	return s;
}

SLinkedList<char>* charFun(SLinkedList<char>* c) {

	return c;
}


int main() {
	char type;

	cout << "Welcome to Linked List Data Manipulation" << endl << endl;


	do {
		cout << "Enter type of list: " << endl;
		cout << "1. Integer" << endl;
		cout << "2. String" << endl;
		cout << "3. Character" << endl;
		cout << "Q. Quit" << endl;
		cin >> type;
	

		switch (type) {
		case '1': {
			SLinkedList<int>* i = new SLinkedList<int>;
			cout << intFun(i) << endl;
			break;
		}
		case '2': {
			SLinkedList<string>* s = new SLinkedList<string>;
			cout << stringFun(s) << endl;
			break;
		}
		case '3': {
			SLinkedList<char>* c = new SLinkedList<char>;
			cout << charFun(c) << endl;
			break;
		}
		case 'Q':
		case 'q':
			exit(-1);
		default:
			cout << "Invalid option..." << endl;
		}
	} while (type != 'Q' || type != 'q');
	
	return 0;
}
