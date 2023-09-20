#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//initialize vectors
vector<double> time;
vector<double>  voltage;


//calculate average discharge voltage
void avgDischarge()
{

}

//Calculate charge capacity
void chargeCap()
{

}

//calculate discharge capacity
void dischargeCap()
{

}

//calculate discharge energy
void dischargeEng()
{

}

//calculate coulombiceffic

void coulEff()
{

}


//main function reads the file, creates vectors from the data, and passes necessary data to other functions
int main()
{
    // Set string for filename. 
    string filename;
    cout<<"Please enter the name of the file to read: \n";
    cin>>filename;


    string line;
    ifstream file;
    file.open(filename);
    if(file.is_open())
    {
      while(getline (file, line))
        {   
        cout << line << '\n';
        }  
    file.close();
    }
    else cout << "File could not be opened for reading.";
    
    return 0;
}
