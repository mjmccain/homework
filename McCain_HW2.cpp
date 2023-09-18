/* McCain_HW2.cpp
Marcus McCain
September, 19, 2023
EGG 1060 */

// Needs to handle GCF

#include <iostream>
#include <cmath>
#include <string>
#include <thread>
#include <Windows.h>
#include < stdlib.h >
using namespace std;

//declare variables
double solutionOne;
double solutionTwo;
const int superScriptTwo = 253;
string factorOne;
string factorTwo;

//Declaring functions
void timer();
void userInput();

//a function to solve the quadratic equation by passing in coefficients
void quadEq(int a, int b, int c, int gcf)

{

    //make sure solutions exist and are real numbers
    if ((pow(b, 2) - 4 * a * c) < 0)
    {
        cout << "There are no real solutions to that equation. Agent X, please input correct coefficients.\n";
        userInput();
    }


    //store the solutions using quadratic formula
    solutionOne = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    solutionTwo = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    

    //Create the factors by checking the value of the solutions.
    if (solutionOne < 0)
    {
        factorOne =  "(x + " + to_string(-1 * solutionOne) + ")";
    }
    else if (solutionOne == 0) {

        factorOne =  "x";
    }

    else if (solutionOne > 0)
    {
        factorOne =  "(x -" + to_string(solutionOne) + ")";

    }

    if (solutionTwo < 0)
    {
        factorTwo =  "(x + " + to_string(-1 * solutionTwo) + ")";
    }
    else if (solutionTwo == 0) {

        factorTwo =  "x";
    }

    else if (solutionTwo > 0)
    {
        factorTwo =  "(x -" + to_string(solutionTwo) + ")";

    }

    cout << "The factored equation is: " << gcf << factorOne << factorTwo << " = 0\n";
    cout << "The solutions are: " << solutionOne << " and " << solutionTwo << endl;
    cout << "Weapon disengeaged.\n";

    string outro = "Well done Agent X, the world is safe once again!";

    for (char c : outro)
    {

        cout << c;
        Sleep(40);
    }

}

/* The timer function runs as a thread in the background as a countdown timer.
If it hits 0 the screen is wiped,'Mission Failed' is printed,
and the program exits. */

void timer() 
{
   
    for (int time = 60; time > 0; time--)
    {
        Sleep(1000);
    }
    system("CLS");
    cout << "Mission Failed!\n";
    exit(0);
}



//The userInput() function takes the users input, validates it, and passes it to 
void userInput()
{
    
    int a = 0;
    int b;
    int c;
    


    //input validation for coefficient 'a'
    cout << "Input a number for coefficient 'a':";
    cin >> a;
    while (a == 0 or cin.fail()) {

        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input a number for coefficient 'a':";
        cin >> a;
        if (a == 0 or cin.fail()) {
            cout << "Agent, coeffcient 'a' must be a real non-zero number.\n";
        }    
    }
    

    cout << "Input a number for coefficient 'b':";
    cin >> b;
    while (cin.fail())
    {
        //clear the failed state and ask for input again.
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Coefficient 'b' must be a number.\n";
    }

    cout << "Input a number for coefficient 'c':";
    cin >> c;
    while (cin.fail())
    {
        //clear the failed state and ask for input again.
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Coefficient 'c' must be a number.\n";
    }

    string equation = to_string(a) + "x" + char(superScriptTwo) + " + " + to_string(b) + "x" + " + " + to_string(c) + " = 0";
    cout << "Thank you Agent X, finding solutions for the equation " << equation << endl;

    //find the greatest common factor of the user input
    int gcf = 0;

    gcf = max(a, max(b, c));

    for (int i = gcf; i > 1; i--)
    {
        if ((a % i == 0) and (b % i == 0) and (c % i == 0))
        {
       
            gcf = i;
            cout << "The greatest common factor is " << i << endl;
        }
    }

    //simplify the integers by dividing by the gcf
    a = a / gcf;
    b = b / gcf;
    c = c / gcf;

    quadEq(a, b, c, gcf);

    
}


int main() {

    //An introducation explaining the program and how it works.
    string intro = " \nHello Agent X, your mission, if you choose to accept it (and you do): \n"
        "Disarm the bomb in front of you before it detonates. Our intel suggests that it can\n"
        "only be disarmed by solving a quadratic equation. All you need to do is give us the\n" 
        "coefficients a, b, c. Remember, a quadratic equation is an equation of the form a(x*x)+ bx + c = 0, \n"
        "where a,b, and c are the coefficients. The coefficients will be whole numbers.\n"
        "We'll then be able to find the solutions to the equation.\n"
        "Keep in mind: \n\n"
        "1. If b*b- 4 * a * c < 0 then the solutions will be complex and no good to us.\n"
        "2. If b*b - 4 * a * c > 0 then there are two real solutions.\n"
        "3. If b *b - 4 * a * c = 0 then there will be only 1 real solution.\n"
        "4. Coefficient 'a' cannot equal 0. Otherwise the equation is no longer quadratic, but a line.\n"
        "We estimate from here you have about 2 minutes. The world is counting on you.\n\n";


    for (char c : intro)
    {

        cout << c;
        Sleep(40);
    }

    //run the timer in the background and detach it from the main function
    thread t1(timer);
    t1.detach();

    //call the userInput function
    userInput();
   

    return 0;
}
