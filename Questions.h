#ifndef Questions_h
#define Questions_h
#include <iostream>

using namespace std;


class Questions
{

    private:
    string Question;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;
    string Right_Answer;
    string User_Answer;


    public:


    void setQuestion(string ques);
    string getQuestion() const
    {
        return Question;
    }


    void setAnswer_1(string ans1);
    string getAnswer_1() const
    {
        return Answer_1;
    }

    void setAnswer_2(string ans2);
    string getAnswer_2() const
    {
        return Answer_2;
    }

    void setAnswer_3(string ans3);
    string getAnswer_3() const
    {
        return Answer_3;
    }

    void setAnswer_4(string ans4);
    string getAnswer_4() const
    {
        return Answer_4;
    }

    void setRightAnswer(string right_ans);
    string getRight_Answer() const
    {
        return Right_Answer;
    }

     void setUserAnswer(string user_ans,int &points_player1);
     void setUserAnswer_2(string user_ans,int &points_player2);

    string getUser_Answer() const
    {
        return User_Answer;
    }


};

#endif // Questions
