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


int* intFun() {
	int integer = 0;
	int intArr[5];
	cout << "Enter an interger: ";
	cin >> integer;

	while (integer > 0) {
		int digit = integer % 10;
		integer /= 10;
		
	}
}
string stringFun() {}
char charFun() {}


int main() {
	char type;
	Base* b;
	cout << "Enter type of list: " << endl;
	cout << "1. Integer" << endl;
	cout << "2. Character" << endl;
	cout << "3. String" << endl;
	cin >> type;

	switch (type) {
	case 1:
		b = new SLinkedList<int>; 
		intFun();
		break;
	case 2:
		b = new SLinkedList<char>; 
		charFun();
		break;
	case 3:
		b = new SLinkedList<string>; 
		stringFun();
		break;
	default:
		exit(-1);
	}



	delete b; //delete allocated memory
	return 0;
}
