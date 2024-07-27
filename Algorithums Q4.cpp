// Algorithums Q4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include <stdio.h>

std::vector<int> a;
std::vector<int> b;
std::vector<int> c;


void GetInputIntoVector();
void OutputVector(std::vector<int> vectorOut);
void printArray(int mydynamicarray[], int size);
void Towers(int n, std::vector<int> a, std::vector<int> b, std::vector<int> c); //error dont use
void Towers2(int n, std::vector<int> a, std::vector<int> b, std::vector<int> c); //error dont use
void Towers3(int n, std::vector<int>* source, std::vector<int>* target, std::vector<int>* aux); //works with an sides of values in a 

//Q4 Heap Sort Algorithm Sam Deadman

int main()
{
    std::cout << "Hello World!\n";
	//a.push_back(x);
	//largest number
	a.push_back(10);
	a.push_back(9);
	a.push_back(8);
	//7 left out for test, still works
	//a.push_back(7);
	a.push_back(6);
	a.push_back(5);
	a.push_back(4);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	//smallest number

	//GetInputIntoVector(); 

	int n = a.size(); //n number of pieces in collum a

	Towers3(n, &a, &c, &b);

	OutputVector(c); //final output ! THE ANSWER !

}

void GetInputIntoVector()
{
	int i;
	bool endInput = false;
	while (endInput == false)
	{
		printf("Input your N value"); //assumption, not other characters will be input
		scanf_s("%d", &i);
		if (i == 0)
		{
			endInput = true;
			break;
		}

		for (i; i != 0; i--) 
		{
			a.push_back(i);
		}
		
	}
	OutputVector(a);
}

void OutputVector(std::vector<int> vectorOut)
{
	for (int i = 0; i < vectorOut.size(); i++) // output test
	{
		std::cout << vectorOut[i];
		std::cout << " ";
	}
}

void printArray(int mydynamicarray[], int size)
{
	for (int i = 0; i < size; i++) // output test
	{
		std::cout << mydynamicarray[i];
		std::cout << " ";
	}
}
//                      soucre             dest                 aux
void Towers(int n, std::vector<int> a, std::vector<int> b, std::vector<int> c) //error with this 
{
	if (n == 1)
	{
		if (a.size() == 0)
		{
			return;
		}
		printf("Move disk 1\n");
		int temp = a.back();
		a.pop_back();
		b.push_back(temp);
		return;
	}
	Towers(n - 1, a, c, b);
	printf("move disk%d\n" , n);
	int temp1 = a.back();
	a.pop_back();
	b.push_back(temp1);
	Towers(n - 1, c, b, a);

}//error with this 

void Towers2(int n, std::vector<int> a, std::vector<int> b, std::vector<int> c) //error with this 
{
	if (n > 0)
	{
		Towers2(n - 1, a, c, b);
		
		c.push_back(a.back());
		a.pop_back();

		Towers2(n - 1, c, b, a);

	}
}//error with this 

void Towers3(int n, std::vector<int> *source, std::vector<int> *target, std::vector<int> *aux) //works
{
	if (n > 0)
	{
		Towers3(n - 1, source, aux, target);
		//printf("Moving %d source: %d target: %d aux %d \n", n, source->back() , target->back() , aux->back()); //error with this output sytle, cant output enmpty vector
		printf("Moving %d \n", n);
		target->push_back(source->back());
		source->pop_back();
		Towers3(n - 1, aux, target, source);
	}
}//works


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
