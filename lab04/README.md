# Lab 04 - A Visit to Array and Vector

## Our Goal in Lab 04

1. Learn to declare vectors of different datatypes
2. Learn to use loops to visit the elements in the vectors
3. Learn to pass the vectors to a function and operate with the vectors

## To Declare and Traverse the Vectors

```cpp
// Include the required headers
#include <iostream>
#include <vector>

// Main function
int main(){

	// Declare a vector and initialize it with some elements
	std::vector<int> myVector = {1,1,2,3,5,8,13,21,34};
	
	// Use a for-loop to traverse the vector
	for(int i=0; i < myVector.size(); i++){
		
		std::cout << myVector[i] << " ";
	}
	std::cout << std::endl;
	// Compute the next element of the vector
	int next;
	int rear = myVector.size() - 1;
	next = myVector[rear] + myVector[rear-1];
	// Push it into the vector
	myVector.push_back(next);

	// Output the vector again

	// Return value of the main function
	return 0;
}
```

## Task 0: Learn the basic usage of the vector

1. Get the Lab code from Github, and open the Lab folder in VS Code or your favorite editor.
2. Complete the code in `lab04` according to the comments and instructions.
3. Fill the vector with random elements and output them in the original order.
4. Compile the code and run it.

## Recap: Use Online Judge to submit your code

1. Open and log in to the Online Judge ([http://10.5.178.148](http://10.5.178.148/)).
2. Find the lab contest according to your lab session.
    1. Click and enter the **Contests**.
    2. Find and enter the corresponding contest (E.g. UFUG2601-Lab 04(S1)).
    3. Submit your code to each problem of the contest.
3. **IMPORTANT: Starting from this lab, your attendance will be recorded based on your submissions to the contest. You need to make at least one submission to the contest to be regarded as attended. To get full grades for labs, you need to clear all problems of the contests and get ACs (accepted).**

## Task 1: E****stimate the trend of arrays****

1. Complete **Problem 1 - Up or Down** in the contest.
2. Given some arrays and ranges of interest (ROIs), estimate the trend of arrays in the given ranges.
3. Submit your code to the Online Judge.

## Task 2: Implement set operations using vectors

1. Complete **Problem 2 - Set Operations** in the contest.
2. You may notice that the problem requires sorted outputs, please search and learn the way to sort the vectors in C++.
    1. Design a function that receives and sorts a vector. Try to learn the most basic sorting algorithm - **Bubble Sort**.
    2. Use the `<algorithm>` headers to sort the vectors.
    
    **Reminder: It’s always easier and pain-free to use the headers/standard libraries to complete the problems. However, what you missed here will bother you again sooner or later, especially if you want to get into any computer-related areas like AI and data science.**
    
3. Submit your code to the Online Judge.

## Additional Contents

Instead of using vectors to implement the operations for sets, C++ already prepared a header for the concept of set, which is `<set>`, just as you can guess.

You can read the document here and search online to learn about it: https://en.cppreference.com/w/cpp/container/set