//Linked List manipulation
#include <iostream> 
#include <string>
using namespace std;


class Base {
public:
	virtual ~Base() {};
};

template <typename E>
struct Node {
	Node() :next(NULL), elem(NULL) {}

	Node<Base>* next;
	Base elem;
};


template <typename E>
class SLinkedList : public Base {
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
	Node<Base>* head;
	size_t size_;
};


int* intFun(SLinkedList<int>* s) {
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
char charFun(SLinkedList<char>* s) {

	return 'n';
}


int main() {
	char type;
	Base* b;

	cout << "Welcome to Linked List Data Manipulation" << endl << endl;


	do {
		cout << "Enter type of list: " << endl;
		cout << "1. Integer" << endl;
		cout << "2. String" << endl;
		cout << "3. Character" << endl;
		cin >> type;
	

		switch (type) {
		case 1:
			intFun(new SLinkedList<int>);
			break;
		case 2:
			stringFun(new SLinkedList<string>);
			break;
		case 3:
			charFun(new SLinkedList<char>);
			break;
		case -1:
			exit(-1);
		default:
			cout << "Invalid option..." << endl;
		}
	} while (type != -1);
	



	delete b; //delete allocated memory
	return 0;
}
