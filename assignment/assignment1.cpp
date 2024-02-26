#include <iostream>
using namespace std;
#include <cmath>
#define pi 3.142
#define h_conv 3600
#define m_conv 60


int main(){
    int choice;
    cout << "1. Program to solve simultaneous equations " << endl;
    cout << "2. Program to convert temperature in Kelvin to Fahrenheit " << endl;
    cout << "3. Program to calculate the volume of a cylinder" << endl;
    cout << "4. Program to calculate the volume of a cube " << endl;
    cout << "5. Program to calculate the volume of a sphere " << endl;
    cout << "6. Program to convert a given number into hours and minutes" << endl;
    cout << "What program do you want to make use of?: " ;
    cin >> choice;

    if(choice == 1)
    {
        // Program to solve simultaneous equations
        double x1;
        cout << "Enter the first constant: "; 
        cin >> x1;

        double x2;
        cout << "Enter the second constant: "; 
        cin >> x2;

        double x3;
        cout << "Enter the equivalent value: "; 
        cin >> x3;

        double y1;
        cout << "Enter the first constant(2): "; 
        cin >> y1;

        
        double y2;
        cout << "Enter the second constant(2): "; 
        cin >> y2;

        double y3;
        cout << "Enter the equivalent value(2): "; 
        cin >> y3;

        double dt = x1 * y2 - y1 * x2;
        double dtx = x2 * y3 - y2 * x3;
        double dty = x1 * y3 - y1 * x3;

        if(dt != 0)
        {
            double x = dtx / dt;
            double y = dty / dt;
            cout << "The value of variable 'x' is: " << x << endl;
            cout << "The value of variable 'y' is: " << y << endl;
        }
        else
        {
            cout << "Math Error Detected";
        }

    }
    else if(choice == 2)
    {
        // Program to convert temperature in Kelvin to Fahrenheit
        double kelvin;
        cout << "Enter your temperature in Kelvins: ";
        cin >> kelvin;

        double fahrenheit = ((kelvin - 273.15) * 9/5) + 32;
        cout << "Your temperature in Fahrenheit is: " << fahrenheit << endl;

        // Program to calculate the volume of a cylinder
        double height;
        cout << "Input a value for height: ";
        cin >> height;

        double radius;
        cout << "Input a value for radius: ";
        cin >> radius;

        double volume = pi * height * pow(radius, 2);
        cout << "The volume of the cylinder is: " << volume << endl;

    }
    else if(choice == 3)
    {
        // Program to calculate the volume of a cylinder
        double height;
        cout << "Input a value for height: ";
        cin >> height;

        double radius;
        cout << "Input a value for radius: ";
        cin >> radius;

        double volume = pi * height * pow(radius, 2);
        cout << "The volume of the cylinder is: " << volume << endl;
        
        
    }
    else if(choice == 4)
    {
        // Program to calculate the volume of a cube 
        double length;
        cout << "Input the length of a side of the cube: ";
        cin >> length;

        double volume1 = pow(length, 3);
        cout << " The volume of the cube is: " << volume1 << endl;

    }
    else if(choice == 5)
    {
        // Program to calculate the volume of a sphere
        double radius1;
        cout << "Input a value for radius: ";
        cin >> radius1;

        double volume2 = 4 / 3 * pi * pow(radius1, 2);
        cout << "The volume of the sphere is: " << volume2 << endl;

    }
    else if(choice == 6)
    {
        // Program to convert a given number into hours and minutes
        double seconds;
        cout << "Input a number in seconds: ";
        cin >> seconds;

        double hour = seconds / h_conv;
        double minute = seconds / m_conv;
        cout << "The number in hours and minutes respectively are- " << hour << ":" << minute << endl;

    }
    else
    {
        cout << "Invalid Input";
    }

    return 0;

}