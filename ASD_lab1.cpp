#include <iostream>
#include <stdexcept> 

using namespace std;

class List {

private:

	class Node {
	public:
		int date; // date of element
		Node* next; // next element
	};
	Node* head; // begin of List
	Node* tail; // end of List

public:
	// Constructor with date
	List(int date) {

		Node* temp = new Node; 
		temp->date = date;
		temp->next = tail;
		head = temp;
		tail = temp;
	}

	// Constructor without date
	List() {
		head = tail = NULL;
		Node* temp = new Node; 
		temp->next = NULL;
		temp->date = NULL;
	}

	// Destructor
	~List() {
		clear();
	}

	// getting list size
	int get_size() {
		int list_size = 0;
		Node* temp = head;
		while (temp != NULL) {
			list_size++;
			temp = temp->next;
		}
		return list_size;
	}

	// checking if the list is empty
	bool isEmpty() {
		bool result = false;
		if (get_size() == NULL) result = true;
		return result;
	}

	// adding to the end of the list
	void push_back(int date) {
		Node* temp = new Node;
		if (isEmpty() == 1) { // If List is empty  
			temp->date = date;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else { // If List isn't empty
			temp->date = date;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;
		}

	}

	// adding to the beginning of the list
	void push_front(int date) {
		Node* temp = new Node; // Create temporary node
		if (isEmpty() == 1) { // If List is empty
			temp->date = date;
			temp->next = NULL;
			head = temp;
			tail = temp;
		}
		else {  // If List isn't empty
			temp->date = date;
			temp->next = head;
			head = temp;
			temp = temp->next;
		}
	}

	// removing the last item
	void pop_back() {
		if (isEmpty() == 0) 
		{
			Node* temp = head; 
			if (head->next == NULL) {
				pop_front();
			}
			else {
				while (temp->next != NULL) {
					tail = temp;
					temp = temp->next;
				}
				tail->next = NULL;
				delete temp;
			}
		}
		else {
			throw invalid_argument("List is empty, so last element can't be deleted");  
		}
	}

	// deleting the first element deleting an element
	void pop_front() {

		if (isEmpty() == 0) 
		{
			Node* temp = head; 
			head = head->next;
			delete temp;
			if (head == NULL) tail = head;
		}
		else {
			throw invalid_argument("List is empty, so first element can't be deleted");  
		}
	}

	// adding an item at index (insertion before an item that was previously accessible at that index)
	void insert(int date, size_t index) {
		if (index < get_size())
		{
			if (index == 0) { 
				return push_front(date);
			}
			else 
			{
				Node* temp = head;  
				Node* insert = new Node;
				insert->date = date;
				for (int i = 0; i < index - 1; i++) {
					temp = temp->next;
				}
				insert->next = temp->next;
				temp->next = insert;
				temp = insert;
			}
		}
		else {
			throw out_of_range("The position of the element is greater than the maximum index of the List"); // Error message 
		}
	}

	// getting an element by index
	int at(size_t index) {
		if (index < get_size()) // If index is in List range
		{
			Node* temp = head; // Create temporary node
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			return temp->date;
		}
		else {
			throw out_of_range("The position of the element is out of range List index\n"); // Error message
		}
	}

	// deleting an element by index
	void remove(size_t index) {
		if (index < get_size()) { 

			if (index == 0)
			{
				return pop_front();
			}
			else if (index == get_size() - 1)
			{
				return pop_back();
			}
			else {
				Node* temp = head; 
				for (int i = 0; i < index - 1; i++) {
					temp = temp->next;
				}
				Node* remove = temp->next;
				temp->next = remove->next;
				delete remove;


			}
		}
		else {
			throw out_of_range("The position of the element is out of range List index"); // Error message
		}
	}

	// removing all list items
	void clear() {
		Node* temp = head; 
		while (head != NULL) {
			temp = head->next;
			delete head;
			head = temp;
		}
		tail = NULL;
	}

	// replacing the element by index with the passed element
	void set(size_t index, int date) {
		if (index < get_size()) { 
			Node* temp = head; 
			for (int i = 0; i < index; i++) {
				temp = temp->next;
			}
			temp->date = date;
		}
		else {
			throw out_of_range("The position of the element is out of range List index"); // Error message
		}
	}

	//swap the elements by indexes
	void swap(size_t index1, size_t index2) {
		// это обозначение элементов и счетчик для значения индекса
		int element1 = 0;
		int element2 = 0;
		int counter = 0;

		// начиная с начала списка проходим и присваиваем значения элементам
		Node* temp = head;
		while (temp != NULL) {
			if (counter == index1) element1 = temp->date;
			else if (counter == index2) element2 = temp->date;
			temp = temp->next;
			counter++;
		}
		// список опять начинаем с начала и обнуляем счетчик индексов
		temp = head;
		counter = 0;
		// меняем элементы местами
		while (temp != NULL) {
			if (counter == index1) temp->date = element2;
			else if (counter == index2) temp->date = element1;
			temp = temp->next;
			counter++;
		}
	}

	//	Overloading the output operator <<
	friend ostream& operator << (ostream& stream, const List& list);

	
};

//	Overloading the output operator <<
ostream& operator << (ostream& stream, const List& list)
{
	List::Node* current = list.head;
	while (current != NULL) {
		stream << current->date << " ";
		current = current->next;
	}
	stream << endl;
	return stream;
}



int main()
{
	cout << "New empty List: \n";
	List WorkList;
	cout << WorkList;

	cout << "Add '2' to the end of our List: \n";
	WorkList.push_back(2);
	cout << WorkList << endl;
	cout << "Get second element: \n";
	try {
		cout << WorkList.at(2) << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl;
	}
	cout << "Add '1' to the begin and '3' to the end: \n";
	WorkList.push_front(1);
	WorkList.push_back(3);
	cout << WorkList << endl;
	cout << "Get second element again: \n";
	try {
		cout << WorkList.at(2) << endl << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Size of List: \n";
	cout << WorkList.get_size() << endl << endl;

	cout << "Remove the first and last element: \n";
	WorkList.pop_back();
	WorkList.pop_front();
	cout << WorkList << endl;
	cout << "And back: \n";
	WorkList.push_front(1);
	WorkList.push_back(3);
	cout << WorkList << endl;

	cout << "Insert '3' at first position: \n";
	WorkList.insert(3, 1);
	cout << WorkList << endl;
	cout << "Set '13' at second position: \n";
	try {
		WorkList.set(2, 13);
		cout << WorkList << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Set '5' at sixth position: \n";
	try {
		WorkList.set(6, 5);
		cout << WorkList << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Swap element at first and second position: \n";
	try {
		WorkList.swap(1,2);
		cout << WorkList << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Remove element at first position: \n";
	WorkList.remove(1);
	cout << WorkList;

	cout << "Check empty of List if: \n0 - not empty \n1 - empty \n";
	cout << WorkList.isEmpty() << endl << endl;
	cout << "Clear the List: \n";
	WorkList.clear();
	cout << WorkList;
	cout << "Check empty of List if: \n0 - not empty \n1 - empty \n";
	cout << WorkList.isEmpty() << endl;

}

