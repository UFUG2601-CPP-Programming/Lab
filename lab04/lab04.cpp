/*
    This is the code template for Lab 04 - A Visit to Array and Vector
*/

// Include required headers
#include <iostream> // Input & Output
#include <vector>   // Vector
#include <cstdlib>  // Random

// Set the random seed for the program
// The seed can be an arbitrary number chosen by the user
// As long as the random seed is the same,
// the random procedure is determined.
// Modify the value to observe the difference.
int seed = 114514; 

void push_random_number(std::vector<int> &v){
    int rand_num = std::rand();
    /*
        TODO: Fill your code here to push a random element into the 
            vector v.
    */
}

// Main function
int main(){
    // Set the random seed for the program
    std::srand(seed);

    /*
        The program receives an integer n - the length of the vector,
        and outputs a vector filled with n random numbers.
    */
    int n;
    std::cin >> n;

    // Declare your vector here

    for(int i=0; i<n; i++){
        // Use the function above to fill the vector
        push_random_number(/* <your vector> */);
    }

    for(int i=0; i < /* <the size of your vector>*/; i++){
        // Output your vector here
    }

    // Return value of the main function
    return 0;
}