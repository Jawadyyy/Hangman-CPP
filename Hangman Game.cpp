//Jawad Mansoor-232414
#include <iostream>
#include <fstream> //Library for file handling
#include <ctime>  //Library for time function
#include <windows.h> //Library for Sleep function
#include <iomanip> //Library for SetW

using namespace std;

void printHangman(int chance); //Function to print Hangman as the chances decrease
string wordselect(string term); //Function to select a random word from a list of given words
void hangman(string target, string user); //Function for all the working and conditions of the game
void scorerecord(int tries, string user); //Function to keep record of scores of players

//The sleep function is for adding delay until the next output 3000=3 seconds and system("cls") means clear screen

int main()
{
    string name, words, word;
    bool exitgame;
    char opt;

    cout << "Starting Game!!!!!!" << endl;

    Sleep(3000); //Adds delay until the next output

    cout << "___________________________________" << endl;
    cout << "|                                 |" << endl;
    cout << "|------------HANGMAN--------------|" << endl;
    cout << "|_________________________________|" << endl;
    cout << "               |                   " << endl;
    cout << "               O                   " << endl;
    cout << "              /|\\                 " << endl;
    cout << "              / \\                 " << endl;
    cout << "                                   " << endl;

    cout << "Enter your name challenger" << endl; //Getting a name for the user
    getline(cin, name);

while(!exitgame) //Making boolean while loop such that the user keeps coming back to the menu 
{
    do
    {
        system("cls"); // Clear the console screen

        cout << "___________________________________" << endl;
        cout << "|                                 |" << endl; //Menu Selection
        cout << "|--------------Menu---------------|" << endl;
        cout << "|_________________________________|" << endl;
        cout << "a) Start Game " << endl; // Play game
        cout << "b) Check Scores" << endl; //Check score list from the scores.txt file
        cout << "c) End Game" << endl; //Exit game
        cin >> opt;

        if (opt == 'a' || opt == 'A') //If the user presses Option A the whole game starts
        {
            char theme;
            do
            {
                system("cls");
                cout << "___________________________________" << endl;
                cout << "|                                 |" << endl; //Theme Selection
                cout << "|-------------Theme---------------|" << endl;
                cout << "|_________________________________|" << endl;
                cout << "Which theme would you like to select?" << endl;
                cout << "1) Animals " << endl; //To select animal related words
                cout << "2) Countries" << endl; //To select countries names
                cout << "3) Fruits" << endl; //To select different fruits
                cout << "4) Sports" << endl; //To select different sports
                cout << "5) Colors" << endl; //To get different colors
                cin >> theme;

                switch (theme)
                {
                case '1':
                    words = "lion,zebra,elephant,horse,dolphin,penguin,tiger,koala,octopus,fox"; //Storing string according to the option user selects
                    break;
                case '2':
                    words = "pakistan,italy,spain,england,japan,france,germany,brazil,canada,russia";
                    break;
                case '3':
                    words = "apple,banana,orange,grape,strawberry,mango,kiwi,peach,cherry,papaya";
                    break;
                case '4':
                    words = "football,cricket,basketball,tennis,hockey,golf,rugby,badminton,squash,volleyball";
                    break;
                case '5':
                    words = "black,blue,white,green,brown,pink,red,purple,yellow,orange";
                    break;
                default:
                    cout << "Invalid Input" << endl;
                }

                if (theme != '1' && theme != '2' && theme != '3' && theme != '4' && theme != '5') //Condition for wrong input asks user again to input if a wrong input is entered
                {
                    char retry;
                    cout << "Do you want to try again? (Y/y for yes): ";
                    cin >> retry;
                    if (retry != 'y' && retry != 'Y')
                    {
                        return 0; // Exit the program if the user dont want to try again
                    }
                }

            } while (theme != '1' && theme != '2' && theme != '3' && theme != '4' && theme != '5');

            system("cls");

            cout << "Get ready " << name << endl;

            Sleep(3000); //Using sleep to make it more like a game
            system("cls"); //Using clearscreen to make it clean looking

            word = wordselect(words); //Calling Radnom word select Function

            hangman(word, name); //Calling the whole working function
        }

        else if (opt == 'b' || opt == 'B') //If the user presses option B he can see the whole scores list
        {
            cout << "Scores List : " << endl;
            ifstream inFile("scores.txt");  //Creating a ifstream file to read the data from the file

            string line; //Creating a string variable so the data could be shown 
            while (getline(inFile, line))
            {
                cout << line << endl; 
            }

            inFile.close(); //Closing the file

            Sleep(9000);
        }
        else if (opt == 'c' || opt == 'C') //If the user presses c the program is closed
        {
            cout << "Exiting Game" << endl;
            exitgame=true;
            return 0;
        }
        else //If wrong input is entered the user asks for the input again because of do while loop
        {
            cout << "Wrong Input" << endl;
        }

    } while (opt != 'a' && opt != 'A' && opt != 'b' && opt != 'B' && opt != 'c' && opt != 'C'); //While Condition for Input Validation

}

return 0;

}

void printHangman(int chance) //Function to print the hangman
{
    switch (chance) //Passing the chance variable meaning seven tries
    {
    case 7: //Shape when seven chances are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;
        break;

    case 6: //Shape when six chances are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "   O    |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;
        break;

    case 5: //Shape when five chances are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "   O    |" << endl;
        cout << "   |    |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;

        break;
    case 4: //Shape when four chances are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "   O    |" << endl;
        cout << "  /|    |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;
        break;

    case 3: //Shape when three chances are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "   O    |" << endl;
        cout << "  /|\\   |" << endl;
        cout << "        |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;
        break;

    case 2: //Shape when two chances are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "   O    |" << endl;
        cout << "  /|\\   |" << endl;
        cout << "  /     |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;
        break;

    case 1: //Shape when one chance are left
        cout << "   +----+" << endl;
        cout << "   |    |" << endl;
        cout << "   O    |" << endl;
        cout << "  /|\\   |" << endl;
        cout << "  / \\   |" << endl;
        cout << "        |" << endl;
        cout << "=========" << endl;
        break;

    default:
        cout << "";
    }
}

string wordselect(string term) //Function for random word selection
{
    srand(time(0)); //Using this function so that the random value each time is different

    int k; //Declaring variables
    string word;
    string letter[99];
    int i = 0, j = 0;

    while (term[i] != '\0') // This loop will go on until there is a null character until the end of string
    {
        if (term[i] != ',') //Before the comma adding all the letters in a word to get a complete word
        {
            letter[j] += term[i]; //Storing word in each index of letter
        }
        else
        {
            j++; 
        }
        i++;
    }

    k = 1 + (rand() % 9); //Using a random function to get a random value and setting a limit to 9
    word = letter[k]; // Storing the random word to the word variable

    return word; //Returning the word variable
}

void hangman(string target, string user) //Function where all the main working takes place
{
    int chance = 7; //Number of tries
    int score = 0; //Score user got/Score=How many attempts he guessed the word in
    int total = 0; //Length of word
    int exposed = 0; //Variable used to reveal the guessed characters
    string panel, name; //Panel is used to hide the characters and name is the users name
    bool correct, clone; //Boolean type variables to check if a correct or same character is entered
    char letter, hint; //The character user enters and hint if user wants one
    bool characters[26] = {false}; //A boolean array to store all the letters so whenever user enters the same it can be checked 

    name = user; //Making name equal to user
    panel = target; //Making panel equal to the target

    for (int i = 0; i < panel.length();) //Loop Condition to convert the characters into panels
    {
        panel[i] = '_';
        total = total + 1;
        i++;
    }

    while (exposed < target.length()) //The main loop where all the working takes place this loop will go on until either the chances run out or the panels are exposed
    {
        correct = false; //Making Correct bool false so if its true later on it can be used
        clone = false; //Making clone bool false so if its true it can be used

        cout << "____________________________ " << endl;
        cout << "|                          |" << endl;
        cout << "|Number of Tries left:  " << chance << "  |" << endl; //It shows the Number of tries left for the user at the start of every turn
        cout << "|Length: " << total << " letters         |" << endl; //It shows the total length of the word; that how many characters are present in it
        cout << "|__________________________|" << endl
             << endl;

        cout << setw(10) << "( " << panel << " )" << endl; //It shows a set of panels which reveals the character when guessed
        cout << "Enter your letter" << endl; //Letter Input from the User
        cin >> letter;

        system("cls");

        if (letter >= 65 && 90 >= letter) //Condition if the User enters an Uppercase letter it converts it to lowercase
        {
            letter = tolower(letter);
        }

        if (!isalpha(letter)) //Condition that any invalid symbol is not allowed only valid characters are allowed
        {
            cout << "Invalid input! Please enter a valid alphabetic character." << endl;
            continue;
        }

        if (characters[letter - 'a']) //Condition for if the letter is entered again it outputs this string
        {
            cout << letter << " has already been either guessed correctly/guessed wrongly" << endl;
            continue;
        }

        else
        {
            characters[letter - 'a'] = true; //Else the letter is stores in the array so it can me checked later on
        }

        for (int i = 0; i < target.length(); i++) //Loop for match if a character matches the entered letter it is exposed and correct is turned true
        {
            if (letter == target[i])
            {
                panel[i] = target[i];
                exposed++;
                correct = true;
            }
        }

        if (correct)
            continue;

        system("cls");
        printHangman(chance); //If the correct is false then hangman is printed with its starting body parts

        if (chance == 2) //Condition for If only 2 chances are left it asks the user for a Hint and exposes a random panel
        {
            cout << "Do you want a HINT(Y/N)?" << endl;
            cin >> hint;

            if (hint == 'y' || hint == 'Y') //Using if condition to match the Input
            {
                int randomIndex;
                do //Using a do while loop to check which index in unexposed and then it is exposed using a rand function
                {
                    randomIndex = rand() % target.length();
                } while (panel[randomIndex] != '_');
                panel[randomIndex] = target[randomIndex];
                exposed++;

                cout << "________One of the panel is now exposed_______" << endl;
                Sleep(3000);
                system("cls");
            }
        }

        chance--; //Decreamenting chances when the user guesses wrong
        cout << endl;
        cout << letter << " is not in the word " << endl;

        if (chance == 0) //When there are no chances left It displays this screen which says You lose and reveals the word
        {
            cout << "_______________YOU LOSE!!!!_____________" << endl;
            cout << "___________________________________" << endl;
            cout << "|                                  " << endl;
            cout << "|The word was: ( " << target << " )" << endl;
            cout << "|__________________________________" << endl;
            Sleep(3000);
            system("cls");
            break;
        }
    }

    if (chance > 0) //If chances still remain and you guessed the word then that means You won and it displays this screen
    {
        cout << "_______________YOU WIN!!!!_____________" << endl;
        cout << "___________________________________" << endl;
        cout << "|                                  " << endl;
        cout << "|The word was: ( " << target << " )" << endl;
        cout << "|__________________________________" << endl;
        Sleep(3000);
        system("cls");
    }
    scorerecord(chance, name); //Then it calls the score record function where all the score record is kept and saves the score
}


void scorerecord(int tries, string user) //Function to keep record of the scores of all the users
{
    int score; //Declaring a score variable
    score = tries; 

    cout << "Your score is: " << score << " out of 7" << endl; //Telling the score of the user score is according to the chance

    ofstream outFile("scores.txt", ios::app); //Creating an ofstream file and using append to save the data in a file and make sure that doesnot go away for that we used append
    if (outFile.is_open())
    {
        outFile << "Challenger " << user << " - Your score is: " << score << " out of 7 " << endl; //Saving this data in the file
        outFile.close();
    }
    else
    {
        cout << "Error opening the file for writing." << endl; //Condtion if file doesnot open
    }
}