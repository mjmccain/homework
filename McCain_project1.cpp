#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <numeric>
using namespace std;

//initialize vectors
vector<double> timeVect;
vector<double>  voltage;

double current = 0.2;

void findValues()
{

//declare variables that will need to be found
int maxVoltIndex = 0;
double maxVolt = 0;
double dischargeSum = 0;
double dischargeAvg;
double dischargeSize = 0;
double dischargeEng = 0;
double dischargeCap;
double chargeCap;
double coulEff;

//loop through voltage vector to find the max voltage
for(int i = 0; i < voltage.size(); i++)
{
    maxVolt = max(maxVolt, voltage[i]);
    if (voltage[i] == maxVolt)
    {
        maxVoltIndex = i;
    }
}
cout << "Max voltage is " << maxVolt << endl;

//split charge from discharge data and make calculations
for(int i = 0; i < voltage.size(); i++)
{
    //calculate charging values
    if(i == maxVoltIndex)
    {
    chargeCap = current * timeVect[i];
    cout << "The charge capacity is: " << chargeCap << endl;
    dischargeCap = current * (timeVect[timeVect.size() - 1] - timeVect[i]);
    cout << "The discharge capacity is: " << dischargeCap << endl;
    }


    //calculate discharge values
    if(i >= maxVoltIndex)
    {
    dischargeSum = dischargeSum + voltage[i];
    dischargeSize = dischargeSize + 1;
    dischargeEng = dischargeEng + (voltage[i] * timeVect[i] * current);
    }
}

//calculate average discharge
dischargeAvg = (dischargeSum / dischargeSize);
coulEff = (dischargeCap / chargeCap) * 100;
cout << "The average discharge voltage is " << dischargeAvg << endl;
cout << "The total discharge energy is: " << dischargeEng << endl;
cout << "The Coulombic Efficiency is: " << coulEff << "%";


}


int main()
{
// Set string for filename. File must be in same directory as .cpp and .exe files!!
string filename;
cout<<"Please enter the data file name: \n";
cin>>filename;

// Define vectors for rows and columns
	vector<vector<string> >content;
	vector<string> row;
	
    // Define the line and value strings
    string line;
    string value;
 
    // Call filestream
	fstream file (filename, ios::in);
	
    // Check that the file is indeed open.
    if(file.is_open())
	{
		
        // Getting each line
        while(getline(file, line))
		{
			// Clears the row value from the last loop
            row.clear();
 
			stringstream str(line);
 
            // Delimits by commas (Comma Seperated Value file!)
			while(getline(str, value, ','))

                // Adds the cell value to the row vector using pushback
                row.push_back(value);
			
            // Adds the row to the content vector (2d vector!)
            content.push_back(row);
		}
	}
    // Tells the user that the file they named was not found.
	else
		cout<<"The filename you entered was not found in the code directory!\n";

// Make a vector for Column_A
vector<double> Column_A;

// Make a vector for Column_B
vector<double> Column_B;

double col_A_double, col_B_double;

// Splitting the data into columns instead of rows
for(int i=1 ;i<content.size();i++)
{
    // Converts the value for columns A and B to doubles
    col_A_double = stod(content[i][0]);
    col_B_double = stod(content[i][1]);

    // Saves the column values
    timeVect.push_back(col_A_double);
    voltage.push_back(col_B_double);
}

findValues();
// End of main function
return 0;
}
