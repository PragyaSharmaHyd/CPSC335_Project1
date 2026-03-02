// Algorithm 1 - Pragya Sharma, Raphael Padua

// puedocode
//SET swaps = 0

//FOR i = 0 TO length(row) - 1 STEP 2

 //   SET firstPerson = row[i]

    //checks to see if person is odd (left pair) or even (right pair)
//    IF firstPerson is even
//        SET partner = firstPerson + 1
//   ELSE
//        SET partner = firstPerson - 1
//    END IF
//
    //checks if pairing is wrong
//    IF row[i + 1] is not equal to partner
//
        //swap to align with partner
//        FOR j = i + 2 TO length(row) - 1
//            IF row[j] is equal to partner
//                SWAP row[i + 1] and row[j]
//                INCREMENT swaps
//        END FOR
// END FOR

// RETURN swaps
#include <vector>
#include <algorithm>
#include <iostream>


int coupleSwaps(std::vector<int> row) {

int swaps = 0;  

for (int i = 0; i < row.size() - 1; i += 2) {

   int firstPerson = row[i];
   int partner;

   // checking to see if the person is odd (left pair) or even (right pair)
   if (firstPerson % 2 == 0)
    { 
        partner = firstPerson + 1;
    }
    else {
        partner = firstPerson - 1;
    }

    // check to see if the pairing is incorrect
    if (row[i + 1] != partner)
    {   
        // swap to align with the partner
        for(int j = i + 2; j < row.size(); j++) {
            if(row[j] == partner) {
            std::swap(row[i+1], row[j]);    // swapping the i + 1 with j
            swaps++;
            break;
            }
        }
    }
}
return swaps; // output: number of swaps needed
}

bool individual_checker(int individual) {           // checking to see if the individual input is correct
    if (individual % 2 != 0 || individual > 30) {
        std::cout << "This is the wrong input. Please enter an even and less than 30 value" << std::endl;
        return false; // Return error code
    }
    return true;    // return true
}

int main() {
    int individual;
    std::cout << "Enter the number of people in the plane (must be 30 or less and even): ";
    std::cin >> individual;

    if (!individual_checker(individual)) {
        return -1; // if input is invalid, exit the function
    }

    std::cout << "Enter the seating arrangement (space-separated): ";
    std::vector<int> row(individual);
   
    for (int i = 0; i < individual; i++) {  // for each input i until number...
        std::cin >> row[i];             
    }
    
    int swaps = coupleSwaps(row);       // input row into coupleSwaps functions
    
    std::cout << "Minimum swaps needed: " << swaps << std::endl;
    
    return 0;
}
