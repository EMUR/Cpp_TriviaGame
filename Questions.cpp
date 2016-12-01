// Implementation file for the Rectangle class.
// This version has a constructor that accepts arguments.
#include "Questions.h"
#include <iostream>      // Needed for cout
#include <cstdlib>       // Needed for the exit function
#include <fstream>

using namespace std;


void Questions::setQuestion(string ques)
{
    Question = ques;
//    Player1[0].Questions = Question_m;
}

void Questions::setAnswer_1(string ans1)
{
    Answer_1 = ans1;
}

void Questions::setAnswer_2(string ans2)
{
    Answer_2 = ans2;
}

void Questions::setAnswer_3(string ans3)
{
    Answer_3 = ans3;
}

void Questions::setAnswer_4(string ans4)
{
    Answer_4 = ans4;
}


void Questions::setRightAnswer(string right_ans)
{
    Right_Answer = right_ans;
}

void Questions::setUserAnswer(string user_ans, int &points_player1)
{
    User_Answer = user_ans;

    if (User_Answer == "A" || User_Answer == "a")
    {
        if (Right_Answer == Answer_1)
        {
            //Player_1_point++;
            points_player1++;

        }
    }

    if (User_Answer == "B" || User_Answer == "b")
    {
        if (Right_Answer == Answer_2)
        {
           // Player_1_point++;
            points_player1++;
        }
    }

    if (User_Answer == "C" || User_Answer == "c")
    {
        if (Right_Answer == Answer_3)
        {
            //Player_1_point++;
            points_player1++;

        }
    }

    if (User_Answer == "D" || User_Answer == "d")
    {
        if (Right_Answer == Answer_4)
        {
            //Player_1_point++;
            points_player1++;
        }
    }

}

void Questions::setUserAnswer_2(string user_ans, int &points_player2)
{
    User_Answer = user_ans;

    if (User_Answer == "A" || User_Answer == "a")
    {
        if (Right_Answer == Answer_1)
        {
        points_player2++;
        }
    }

    if (User_Answer == "B" || User_Answer == "b")
    {
        if (Right_Answer == Answer_2)
        {
        points_player2++;
        }
    }

    if (User_Answer == "C" || User_Answer == "c")
    {
        if (Right_Answer == Answer_3)
        {
        points_player2++;

        }
    }

    if (User_Answer == "D" || User_Answer == "d")
    {
        if (Right_Answer == Answer_4)
        {
        points_player2++;
        }
    }

}

