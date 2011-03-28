//Spencer Krum
//March 28 2011
//karlaf
//cs162
//
//Algorithm:
//Welcome the user to the program.
//Print a usage.
//Begin loop.
//Ask User for instructions. Provide 3 options. 1) Print usage. 2) Compress word. 3) Quit. If none or invalid is given, quit.
//If print usage: 
//  Print usage.
//If compress word:
//  Ask user for a list of words.
//      Save in char *
//  Process list of words.
//      Instantiate forward_backward integer = 1;
//      Instantiate new char *
//      Enter into while loop around (first address of input array = temp).
//      If temp is the spacebar then toggle the forward_backward variable.
//          Forward_backward variable is forward_backward variable * 1.
//      If temp is between (b-y), (B-Y):
//        Next address of output word array = temp + forward_backward variable.
//      If forward_backward = 1:
//          If temp = a:
//              temp = b
//              Next address of output word array = temp
//          If temp = A:
//              temp = B
//              Next address of output word array = temp
//          If temp = z:
//              temp = a
//              Next address of output word array = temp
//          If temp = Z:
//              temp = A
//              Next address of output word array = temp
//      If forward_backward = -1:
//          If temp = a:
//              temp = z
//              Next address of output word array = temp
//          If temp = A:
//              temp = Z
//              Next address of output word array = temp
//          If temp = z:
//              temp = y
//              Next address of output word array = temp
//          If temp = Z:
//              temp = Y
//              Next address of output word array = temp
//      return processed word array.
//  Print out processed word array.
//  Loop again.
//If quit: 
//  Print goodbye.
//  Quit.


#include <iostream>

using namespace std;

void welcome(){
    cout << "Welcome to cs162 program 1 by Spencer Krum" << endl;
}

void usage(){
    cout << "This program will help you compress your words. Enter a word list and it will compress a word for you." << endl;
    cout << "What would you like to do?" << endl;
    cout << "1) Print a usage." << endl;
    cout << "2) Compress a list of words." << endl;
    cout << "3) Quit" << endl;
}

void quit(){
    cout << "Thank you for enjoying the word compressor" << endl;
}

void process_words(char line[]){
    char output[80];
    char temp;
    int i;
    int forward_backward = 1;
    for (i= 0; line[i] != '\0'  ; i++){
        cout << forward_backward << endl;
        temp = line[i];
        if (temp == 32){
            forward_backward = forward_backward * -1;
            output[i] = ((char)(32));
        }
        else if ((98 <= temp <= 121) || (66 <= temp <= 89)){
            output[i] = ((char)(temp + forward_backward));
        }
        else if (forward_backward == 1){
            switch (temp){
                case 97:
                    output[i] = ((char)(98));
                    break;
                case 65:
                    output[i] = ((char)(66));
                    break;
                case 122:
                    output[i] = ((char)(97));
                    break;
                case 90:
                    output[i] = ((char)(65));
                    break;
            }
        }
        else if (forward_backward == -1){
            cout << "made it" << endl;
            switch (temp){
                case 97:
                    output[i] = ((char)(122));
                    break;
                case 65:
                    output[i] = ((char)(90));
                    break;
                case 122:
                    output[i] = ((char)(121));
                    break;
                case 90:
                    output[i] = ((char)(89));
                    break;
            }
        }
        else {
            output[i] = ((char)(temp));
        }
    }


    cout << output << endl;
    cout << line[0] << endl;
    cout << ((char)(line[0] + 1)) << endl;
    cout << ((char)(line[1] + -1)) << endl;
}

void compress_word(){
    cout << "Please enter a list of words to compress, 80 chars max." << endl;
    char line[80];
    cout << " Type a line terminated by carriage return\n>";
    cin.get( line, 25);
    cout << " " << line << endl;
    process_words(line);
}

int ask_instructions(){
    cout << "" << endl;
    cout << "What would you like to do? [1|2|3]" << endl;
    int selection;
    cin >> selection;
    cin.ignore();
    switch (selection){
        case 1:
            usage();
            break;
        case 2:
            compress_word();
            break;
        case 3:
            quit();
            return 3;
            break;
        default:
            quit();
            return 4;
            break;
    }
}



int main(){
    welcome();
    usage();
    while (true){
        int code = ask_instructions();
        if (code == 4){
            cout << "Program exited on code 4: Didn't enter a valid response." << endl;
            break;
        }
        if (code == 3){
            cout << "Program exited on code 3: Normal, premeditated exit." << endl;
            break;
        }
    }

    return 1;
}

