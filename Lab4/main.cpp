#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;
string Reverse(string text, int pos);
bool Palindrome(string text, int pos);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);
const int SIZE = 10;
int arr[SIZE];

int main()
{
	srand(time(NULL));
	string word;
	int choice;
	do {
		system("cls");
		cout << "Welcome to Lab4" << endl;
		cout << "1. Reverse a Word" << endl;
		cout << "2. Palindrome Check" << endl;
		cout << "3. Quicksort Array" << endl << ">";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Enter a Word:\n";
			cin.ignore();
			getline(cin, word);
			cout << "Reverse: " << Reverse(word, word.length()) << endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout << "Enter a Word:\n";
			cin.ignore();
			getline(cin, word);
			cout << "Palindrome: ";
			cout << Palindrome(word, 0) << endl;
			if (Palindrome(word, 0)) cout << "true\n";
			else cout << "false\n";
			system("pause");
			break;
		case 3:
			int userSize;
			do {
				system("cls");
				cout << "Enter an array Size (1-10):\n";
				cin >> userSize;
				if (userSize > SIZE) {
					system("cls");
					cout << "Array requested too large";
				}
			} while (userSize > SIZE);
			for (unsigned i = 0; i < userSize; i++)
			{
				arr[i] = rand() % 100;
			}
			printArray(arr, userSize);
			quickSort(arr, 0, userSize - 1);
			printArray(arr, userSize);
			system("pause");
			break;
		default:
			break;

		}
	} while (choice < 3 && choice > 0);
	return 0;
}


string Reverse(string text, int pos)
{
	if (pos != 0) {
		return text[pos] + Reverse(text, --pos);
	}
	return "";
}

bool Palindrome(string text, int pos)
{
	if (pos < text.length()) {
		if (text[0 + pos] == text[text.length() - pos - 1])
		{
			return 1 * Palindrome(text, ++pos);
		}
		else
		{
			return 0 * Palindrome(text, ++pos);
		}
	}
	return 1;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	cout << "----------------------" << endl;
	cout << "pivot: " << pivot << endl;
	cout << "j Index: " << low << " | i Index: " << low - 1 << endl;
	printArray(arr, high + 1);
	cout << "----------------------" << endl;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		printArray(arr, high + 1);
		if (arr[j] < pivot)
		{
			i++;
			cout << arr[j] << " < " << pivot << endl;

			swap(&arr[i], &arr[j]);
			//printArray(arr, high);
		}
		else {
			cout << arr[j] << " >= " << pivot << endl;
		}
		cout << "j Index: " << j << " | i Index: " << i << endl;
		printArray(arr, high + 1);
		cout << "----------------------" << endl;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}


//int main()
//{
//    int arr[] = { 10, 7, 8, 9, 1, 5 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//    quickSort(arr, 0, n - 1);
//    cout << "Sorted array: \n";
//    printArray(arr, n);
//    return 0;
//}