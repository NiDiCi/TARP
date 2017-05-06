#ifndef ORDEREDARRAY_H
#define OREDEREDARRAY_H


#include <iostream>

template<class Datatype>
class OrderedArray
{

private:

	Datatype* ordArray;
	int arraySize;
	int numElements;
	int growSize;
	//Constructor
public:
	OrderedArray()
	{
		ordArray = new Datatype[10];
		arraySize = 10;
		numElements = 0;
		growSize = 1;
	}
	OrderedArray(int newSize, int newGrowSize)
	{
		ordArray = new Datatype[newSize];
		arraySize = newSize;
		numElements = 0;
		growSize = newGrowSize;
	}

	//Destructor
	~OrderedArray()
	{
		if (ordArray != 0)
			delete[] ordArray;
		ordArray = 0;
	}

	//Access Operator
	Datatype& operator[] (int index)
	{
		return ordArray[index];
	}

	//Conversion Operator
	operator Datatype* ()
	{
		return ordArray;
	}

	//Returns size of your Array.
	int getSize()
	{
		return numElements;
	}

	//Add items to the array in assending order. Works for all datatypes(If file has both strings and ints than ints go first).
	void push(Datatype item)
	{
		int i = 0;

		//If theres no more room then resize the array.
		if ((arraySize - numElements) == 0)
		{
			Resize(arraySize + growSize);
		}
		//assuming theres no reason to have multiples in it so dont alow it to save space.

		bool added = false;
		i = numElements;
		//This loop is in order c.
		while (!added)
		{
			//Sorts it and moves it all values forward by one until it gets to where the item needs to go.

			if (i > 0 && ordArray[i - 1] > item)
			{
				ordArray[i] = ordArray[i - 1];
				i--;
			}
			else
			{
				//adds the item and exits the while loop.
				ordArray[i] = item;
				added = true;
			}
		}


		numElements++;
	}

	//Removes the last item in the array list.
	void pop()
	{
		numElements--;
	}

	//Removes one item in the array.
	void remove(int index)
	{
		//This loop is in order c.
		if (index >= 0 && index <= numElements)
			for (int i = index + 1; i < numElements; i++)
			{
				ordArray[i - 1] = ordArray[i];
			}
		numElements--;
	}

	//Searches for an index of an item.
	int searchBinary(Datatype item)
	{
		//lowest point in the array
		int min = 0;
		//highest point in the array
		int max = numElements;
		int mid;

		//This loop is in order c.
		while (max >= min)
		{
			//gets the midpoint of the array.
			mid = min + ((max - min) / 2);
			//Checks which side to search.
			if (ordArray[mid] < item) {
				//increase min to cut the array in half.
				min = mid + 1;
			}
			else if (ordArray[mid] > item) {
				//reduce max to cut the array in half.
				max = mid - 1;
			}
			else {
				//The first two steps will repeat until there is only one point remaining which will be the point your looking for.
				return mid;

			}
			//If noting happens then it is not found and returns a -1.

		}
		return -1;
	}

	int searchLinear(Datatype item)
	{
		//This loop is in order c.
		for (int i = numElements; i >= 0; i--)
		{
			if (ordArray[i] == item)
			{
				return i;
			}
		}
	}
	//Resizes the array by the amount you specify.Taken from the array.h file we were given.
	void Resize(int newSize)
	{
		// create a new array with the new size
		Datatype* newarray = new Datatype[newSize];

		// if the new array wasn't allocated, then just return
		// and don't change anything.
		if (newarray == 0)
			return;

		// determine which size is smaller.
		int min;
		if (newSize < arraySize)
			min = newSize;
		else
			min = arraySize;

		// loop through and copy everything possible over.
		int index;
		//This loop is in order n.
		for (index = 0; index < min; index++)
			newarray[index] = ordArray[index];

		// set the size of the new array
		arraySize = newSize;

		// delete the old array.
		if (ordArray != 0)
			delete[] ordArray;

		// copy the pointer over.
		ordArray = newarray;
	}

	void clearArray()
	{
		Datatype* newArray = new Datatype[1];

		//delete the old array
		/*	if(ordArray !=0)
		{
		delete[] ordArray;
		}*/
		//Assign the new empty array to the old pointer. The size of the array gets set to 1 to save memory.
		ordArray = newArray;
		arraySize = 1;
		numElements = 0;
	}

	//Writes the ordered array into a new file.
	bool writeOrderedFile(const char* filename)
	{
		ofstream outfile(filename);

		if (outfile.is_open())
		{
			//This loop is in order n.
			for (int i = 0; i < numElements; i++)
			{
				outfile << ordArray[i] << endl;
			}

			outfile.close();
			return true;
		}
		return false;
	}
	//Read a file and stores the information into an array in order.
	//Ronan Murphy helped me with this.
	bool readUnorderedFile(const char* filename)
	{
		Datatype input;

		ifstream myfile(filename);
		if (myfile.is_open())
		{
			//This loop is in order n.
			while (!myfile.eof()) //keeps going until end of the file is reached
			{
				myfile >> input;
				push(input);
			}
			myfile.close();
			return true;
		}

		return false;
	}


};
#endif