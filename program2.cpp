//SpencerKrum
//cs162
//may1, 2010
//
//algorithm
//  o   Welcome the user.
//  o   Provide a usage.
//  o   Define a struct to hold number, description, operator.
//  o   Initialize an array of length 10 of this struct.
//  o   Enter into a loop
//      *   Print usage.
//      *   Prompt user for number.
//      *   Prompt user for description.
//      *   Prompt user for operator.
//      *   Set these values in the array of structs.
//  o   Evaluate the struct by looping through it and applying the operations.
//  o   Print the output.
//  
//
//
//

#include <iostream>
#include <string.h>

using namespace std;

//define our calcuiation structure
struct calculation {
    float number; //of the form 3.1415926535897932384626
    char * operation; //of the form *, /, +, -
    char * description;
};

//welcome function
void welcome(){
    cout << "Welcome to the 2nd CS162 Program" << endl;
    cout << "This program is a caclulator of sorts, it will keep track of 10 numbers and operations, printing out the final result at the end" << endl;
}

//function to get floating point number from user
float get_number(){
    float number;
    //number = 3.1415926535897932384626;
    cout << "Please enter a number: " << endl;
    cin >> number;
    cin.ignore();
    return number;
}

//function to get operation from user stored as a char
char * get_operation(){
    //operation has the form /, *, +, -
    char operation[2];
    cout << "Please enter an operation(as one letter '*', '/', '+', '-' : " << endl;
    cin.get(operation, 3, '\n');
    cin.ignore(3,'\n');
    return operation;
}

//function to get description from user, stored as a char *
// have to pass in an array by reference and modify it
char * get_description(){
    char  description[80]= "The cost of one oil change.";
    cout << "Please enter a discription of this number: " << endl;
    cin.get(description, 80, '\n');
    cin.ignore(80,'\n');
    return description;
}

//function to print out a usage
void usage(){
    cout << "Please enter the number you would like to calculate on, \n"
        << "the operation you would like to perform (as ONE of /, *, +, -) \n"
       << "and a short description of the number's significance" << endl;
}

//function to printout subtotal
float subtotal(float& total, char operation, float& number){
    switch (operation)
    {
        case '/':
            total = total / number;
            break;
        case '*':
            total = total * number;
            break;
        case '+':
            total = total + number;
            break;
        case '-':
            total = total - number;
            break;
        default:
            cout << "DUN GOOFED" << endl;
            cout << operation << endl;
    }
    cout << total << endl;
}

//function to populate a struct of calculations
void populate(calculation history[], float& total){
    //we know length is 10, or 9 zero indexed
    // in a more complicated program with variable length of array
    // we would pass in an int length
    
    int length = 9;
    //for loop over our array
    for (int i = 0; i <= length; i++){
        usage();                                        //print usage
        history[i].operation = get_operation();         //function to streamline this
        history[i].number = get_number();               //function to streamline this
        history[i].description = get_description();        //function to streamline this
        //function to printout subtotal
        //cout << history[i].operation << endl;
        subtotal(total, history[i].operation[0], history[i].number);

    }
}

float get_initial_number(){
    float number;
    //number = 3.1415926535897932384626;
    cout << "Please enter a number: " << endl;
    cin >> number;
    cin.ignore();
    return number;

}

void printout(calculation history[]){
    //we know length is 10, or 9 zero indexed
    // in a more complicated program with variable length of array
    // we would pass in an int length
    
    int length = 9;
    //for loop over our array
    for (int i = 0; i <= length; i++){
        cout << history[i].number << endl;
        cout << history[i].operation << endl;
        cout << history[i].description << endl;

    }
}

//main function
int main(){
    //welcome the user
    welcome();
    //init an array of length 10 of type calculation
    float total = get_initial_number();
    calculation history[10];
    populate(history, total);
    return 0;
}
