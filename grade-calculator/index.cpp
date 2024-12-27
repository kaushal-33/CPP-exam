#include <iostream>

using namespace std;

int main()
{
    int score;
    char grade;
    cout << "Enter your score : ";
    cin >> score;
    if (score > 100)
    {
            cout << "Please enter your score out 100 !\n " ;
    }else{
        (score >= 90) ? grade = 'A': 
    (score >= 80) ? grade = 'B': 
    (score >= 70) ? grade = 'C': 
    (score >= 33) ? grade = 'D': grade = 'F';
    cout<<"Your grade is : "<<grade<<endl;
    switch (grade)
    {
    case 'A':
        cout << "Execellent Work !\n";
        break;
    case 'B':
        cout << "Well done !\n";
        break;
    case 'C':
        cout << "Good Job !\n";
        break;
    case 'D':
        cout << "You passed ! but you could do bettwer\n";
        break;
    case 'F':
        cout << "Sorry, you Failed !\n";
        break;
    }
    if (grade >= 'A' and grade <= 'D')
        cout << "Congratulation, you are eliglible for next level\n";
    else
        cout << "Please try again next time\n";
    }

    return 0;
}