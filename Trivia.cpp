// This program calls the Rectangle class constructor.
#include <iostream>
#include <iomanip>
#include "Questions.h"
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;

void readfromfile(Questions game[],int number_of_questions);
void welcome (string &Player_1, string &Player_2);
void LetTheGameBegin(Questions game[],int number_of_questions,string Player_1, string Player_2, int& points_player1, int &points_player2);
void endofgame(string Player_1, string Player_2, int points_player1, int points_player2);

int main()
{
    SetConsoleTitle("                                              ======  FUN GAME  ======"); // title for the Console, just for fun :)

    string Player_1, Player_2; // names of the players
    srand(time(NULL)); // random number seed for the shuffling function, a lot of fun ahead ;)

    int number_of_questions  = 10; // total of questions
    int points_player1 = 0; // initial points for both players
    int points_player2 = 0;

    Questions game [number_of_questions]; // number of questions

    readfromfile(game,number_of_questions); // read from file into the class
    welcome (Player_1,Player_2); // welcome function that also takes the name of the players
    LetTheGameBegin (game,number_of_questions,Player_1,Player_2,points_player1,points_player2); // ask the players questions and take thier answers, and if it's correct add one to their points
    endofgame(Player_1,Player_2,points_player1,points_player2);// print the results and the winner



   return 0;
}

void readfromfile(Questions game[],int number_of_questions)
{
    ifstream infile;
    infile.open("Questions.txt"); // open infile
    if (!infile)
    {
        cout << "Error occurred while opening the input file ! Please contact the developer " << endl;
        exit(1);
    } // same old, didn't find just get out


    for (int count = 0 ; count < number_of_questions; count++)
    {
    string ques,ans1,ans2,ans3,ans4,empty_line,hold,hold2; // temp strings just to from file:)

    int random = rand()%10; // random number from 0 to 9

    getline (infile,ques); // read the question to the first temp string
    getline(infile,ans1);
    getline(infile,ans2);
    getline(infile,ans3);
    getline(infile,ans4);
    getline(infile,empty_line); // same for the rest of the answers, and this is just to read the line between the questions


    game[count].setRightAnswer(ans1); // get the first question
    game[count].setQuestion(ques); // get the right answer, which is the first choice of each question in the input file

    // shuffling begin :)!

    if (random % 3 == 0 )
    {
        random = rand()%10;
            if (random < 5)
        {
            hold = ans3;
            ans3 = ans1;
            ans1 = hold;
        }

        else
            {
                hold = ans4;
                ans4 = ans3;
                ans3 = hold;
            }
    }

    else
    {
         if (random > 5)
        {
            hold = ans2;
            ans2 = ans1;
            ans1 = hold;
        }

        else
            {
                hold = ans4;
                ans4 = ans1;
                ans1 = hold;
            }
    }

    random = rand()%10;

    if (random % 2)
    {
            hold = ans4;
            ans4 = ans3;
            ans3 = hold;
            hold = ans1;
            ans1 = ans2;
            ans2 = hold;
    }


// really all easy if statments , but it's very effective try it ;)
// set the new shuffled answers to the class question
    game[count].setAnswer_1(ans1);
    game[count].setAnswer_2(ans2);
    game[count].setAnswer_3(ans3);
    game[count].setAnswer_4(ans4);
    }

}
// after making sure that the file is open correctly, we ask about thier names :)

void welcome (string &Player_1, string &Player_2)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 79);
    cout << '\t'<< '\t'<< '\t'<< '\t' << "Trivia Game" << '\t' << '\t' << '\t'<< '\t'<< '\t'<< endl << endl; // title
    SetConsoleTextAttribute(hConsole, 15);
    cout << "Name of the first player (White): "; // get first name
    cin >> Player_1;

    SetConsoleTextAttribute(hConsole, 11);
    cout << endl << "Name of the second player (Blue) : "; // get second name
    cin >> Player_2;
    cin.ignore();
}

void LetTheGameBegin(Questions game[],int number_of_questions, string Player_1, string Player_2,int &points_player1, int &points_player2)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int counter = 1;

for (int count = 0 ; count < number_of_questions; count++)
{
    string answer;
    if (count % 2 == 0)
    {
    SetConsoleTextAttribute(hConsole, 79);
    cout << '\n' << '\t'<< '\t'<< '\t'<< '\t' <<"Question "<< (counter) << '\t'<< '\t'<< '\t'<< '\t'<< '\t' << '\n' << endl;
        SetConsoleTextAttribute(hConsole, 7);
    cout << "Q :" << game[count].getQuestion() << '\n' << endl;
    cout << "A. " <<game[count].getAnswer_1()<< endl;
    cout << "B. " <<game[count].getAnswer_2()<< endl;
    cout << "C. " <<game[count].getAnswer_3()<< endl;
    cout << "D. " <<game[count].getAnswer_4()<< endl;

        SetConsoleTextAttribute(hConsole, 31);
    cout << '\n' << '\t'<< '\t'<< '\t'<< '\t' << Player_1 <<"'s Turn "<< '\t'<< '\t'<< '\t'<< '\t'<< '\t' <<endl;
        SetConsoleTextAttribute(hConsole, 15);
    cout << "The correct answer is : ";
    cin >> answer;
    cin.ignore();
    game[count].setUserAnswer(answer,points_player1);
    }

    else
    {
        SetConsoleTextAttribute(hConsole, 79);
    cout << '\n' << '\t'<< '\t'<< '\t'<< '\t' <<"Question "<< (counter) << '\t'<< '\t'<< '\t'<< '\t'<< '\t' << '\n' << endl;
        SetConsoleTextAttribute(hConsole, 7);
    cout << "Q :" << game[count].getQuestion() << '\n' << endl;
    cout << "A. " <<game[count].getAnswer_1()<< endl;
    cout << "B. " <<game[count].getAnswer_2()<< endl;
    cout << "C. " <<game[count].getAnswer_3()<< endl;
    cout << "D. " <<game[count].getAnswer_4()<< endl;

        SetConsoleTextAttribute(hConsole, 27);
    cout << '\n' << '\t'<< '\t'<< '\t'<< '\t' << Player_2 <<"'s Turn "<< '\t'<< '\t'<< '\t'<< '\t'<< '\t'<<endl;
        SetConsoleTextAttribute(hConsole, 11);
    cout << "The correct answer is : ";
    cin >> answer;
    cin.ignore();
    game[count].setUserAnswer_2(answer,points_player2);
    counter++;
    }
}


}

void endofgame(string Player_1, string Player_2, int points_player1, int points_player2)
{
        HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

       SetConsoleTextAttribute(hConsole, 79);
    cout << '\n' << '\n' << '\t'<< '\t'<< '\t'<< '\t' << "The Results" << '\t'<< '\t'<< '\t'<< '\t'<< '\t' << '\n' << endl;

    if ( points_player1 > points_player2)
    {
        SetConsoleTextAttribute(hConsole, 31);
        cout << "  Congratulation ! " << Player_1 << " You have made it ! You are the master of classes now!"<< '\t' << endl;
    }

        if ( points_player1 < points_player2)
    {
        SetConsoleTextAttribute(hConsole, 27);
        cout << "  Congratulation ! " << Player_2 << " You have made it ! You are the master of classes now!"<< '\t' << endl;
    }

        if ( points_player1 == points_player2)
        {
        SetConsoleTextAttribute(hConsole, 11);
        cout << '\t' << "  It's a tie ! well, you both are masters in classes! good job!"<< '\t' << '\t'<< '\t'<< endl;
        }

              SetConsoleTextAttribute(hConsole, 10);
    cout << '\n' << '\t'<< '\t'<< '\t' << '\t'<< Player_1 << " : " << points_player1 << '\t'<< '\t'<< '\t' << '\t'<< '\t'<< '\t';
    cout << '\n' << '\t'<< '\t'<< '\t' << '\t'<< Player_2 << " : " << points_player2 << '\t'<< '\t'<< '\t' << '\t'<< '\t'<< '\t';
              SetConsoleTextAttribute(hConsole, 7);

}
