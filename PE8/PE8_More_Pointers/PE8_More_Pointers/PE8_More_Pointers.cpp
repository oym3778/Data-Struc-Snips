#include <iostream>

using namespace std;

void changeVariable(int x);
void changePointer(int* x);
void getLengthArray(int myArray[], const unsigned int ARRAY_SIZE);
void getLengthPointer(int* myArray);
int* createStackArray();
int* createHeapArray(const unsigned int ARRAY_SIZE);

void printPtrArray(int* myArray, const unsigned int ARRAY_SIZE);

int main()
{
	int myInt = 5;
	cout << "myInt = " << myInt << endl;

	changeVariable(myInt);
	cout << "myInt = " << myInt << endl;

	changePointer(&myInt);
	cout << "myInt = " << myInt << endl;

	// The difference between these 2 methods is that changeVariable() is 
	// changing a new integer created within the methods parameter while
	// changePointer is changing the reference to the integer being used in the parameter. 
	// This explains why we see that myInt has changed to 6

	const unsigned int ARRAY_SIZE = 7;
	int myArray[ARRAY_SIZE] = { 1, 2, 3, 4, 0, 0, -1 };

	int* myPtrArray = myArray;

	getLengthArray(myPtrArray, ARRAY_SIZE);
	getLengthPointer(myArray);

	int* arrayOnStack = createStackArray();
	int* arrayOnHeap = createHeapArray(5);

	printPtrArray(arrayOnStack, 5);
	printPtrArray(arrayOnHeap, 5);

	// I didn't notice anything different from the array created on the stack compared to the 
	// array created on the heap, they both seem to function in similar ways. This is the case 
	// because both arrays are created in functions and used to initialize variables in the main 
	// funciton.

	delete arrayOnHeap;

}

void changeVariable(int x)
{
	cout << "Inside changeVariable( ), " << x;
	x++;
	cout << " is now : " << x << endl;
}
void changePointer(int* x)
{
	cout << "Inside changePointer( ), " << *x;
	*x += 1;
	cout << " is now : " << *x << endl;
}
void getLengthArray(int myArray[], const unsigned int ARRAY_SIZE)
{
	int numOfElements = 0;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (myArray[i] == -1) {
			break;
		}
		numOfElements++;
	}
	cout << "Elements prior to the -1 : " << numOfElements << endl;
}
void getLengthPointer(int* myArray)
{
	int numOfElements = 0;
	while (myArray[numOfElements] != -1) {
		numOfElements++;
	}
	cout << "Elements prior to the -1 : " << numOfElements << endl;
}
int* createStackArray()
{
	int myArray[5] = { 0, 1, 2, 3, 4 };
	return myArray;
}
int* createHeapArray(const unsigned int ARRAY_SIZE)
{
	int* myArray = new int[ARRAY_SIZE] { 0, 1, 2, 3, 4 };
	return myArray;
}
void printPtrArray(int* myArray, const unsigned int ARRAY_SIZE)
{
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cout << myArray[i] << ", ";
	}
	cout << endl;
}