#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "header.h"
#include <cstdlib>
#include <sstream>

using namespace std;
// Quicksort functions
int partition(vector <Vehicle*>& vehicles, int first, int last) {

    double pivot = vehicles[first]->getTotalPrice();  // taking the first element as pivot
    int i = first;
    int j = last;
    bool done = false;

    while (!done) {
        while (i <= j && vehicles[i]->getTotalPrice() <= pivot) {
            i++;    //if pivot is bigger increment the smaller element
        }
        while (j >= i && vehicles[j]->getTotalPrice() >= pivot) {
            j--;    //if pivot is smaller decrement the bigger element
        }
        if (j < i) {
            done = true;
        }
        else {
            swap(vehicles[j], vehicles[i]);
        }
    }

    swap(vehicles[j], vehicles[first]);

    return j;
}

void quickSort(vector <Vehicle*>& vehicles, int first, int last) {


    if (first < last) {

        int p = partition(vehicles, first, last);
        quickSort(vehicles, first, p);  // sort before the pivot
        quickSort(vehicles, p + 1, last);   // sort after the pivot
    }
} 
// KMP string matching algorithm 
void computeLPSArray(string pat, int M, vector <int> lps)
{
    int len = 0;  // used to store the length of previous longest proper prefix that is also a suffix 
    lps[0] = 0; // value of the first element 
    int i = 1;
    while (i < M) // while i is less than the length of the pattern
    {
        if (pat[i] == pat[len]) // if character at index i matches len 
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)  // if len is not equal to 0 
            {
                len = lps[len - 1];
            }
            else  // if len is 0 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
// 
bool KMPSearch(string pat, string txt)
{
    int M = pat.length();  // m is equal to the length of pattern 
    int N = txt.length();  // n equal to the length of txt

    vector <int> lps(M);

    computeLPSArray(pat, M, lps);  // computes the pattern

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])  // if the characters match increment both i and j 
        {
            j++;
            i++;
        }

        if (j == M)  // we have reached end of the pattern 
        {
            return true;
        }

        else if (i < N && pat[j] != txt[i]) // if there is no match
        {
            if (j > 0)
                j = lps[j - 1];  // if there is no match and j is greater than zero, we move to j - 1 
            else
                i = i + 1;
        }
    }
    return false;  // we return no match 
}

// creating a function like stoi() and stod(), but to convert the string from the file into boolean
bool String2Bool(string str) {
    if (str == "true") {
        return true;
    }
    else if (str == "false") {
        return false;
    }
    else {
        return false;
    }
}

// creating a function that will help convert the string from the file to the respective enum type
FuelType convertFuelType(string fuelType) {
    if (fuelType == "petrol") {
        return petrol;
    }
    else if (fuelType == "diesel") {
        return diesel;
    }
    else if (fuelType == "lpg") {
        return lpg;
    }
    else if (fuelType == "electric") {
        return electric;
    }
}

// creating a function that will help convert the string from the file to the respective enum type
VanType covertVanType(string vanType) {
    if (vanType == "cargo") {
        return cargo;
    }
    else if ( vanType == "passenger") {
        return passenger;
    }
}


vector<Vehicle*> retrieveData(string filename) // this function will collect the data from file and convert it to the types we need and create the objects
{  // we create a function that will ease the process, instead of doing it for every single object.
    vector<Vehicle*> vehicles;
    vector<string> temporaryVector;
    ifstream data;
    data.open(filename.c_str(), ios::in);
    if (!data)  // if somehow file could not be opened this message will appear so we have clue what is the problem
    {
        cerr << "couldnt open file" << endl;
    }
    else {
        string line;
        while (getline(data, line)) { 
            temporaryVector.push_back(line);  // we create a temporary vector where we will store the data
        }
        for (int i = 0; i < temporaryVector.size(); i++)
        {
            vector<string>contents;
            string str = temporaryVector[i]; 
            stringstream stream(str);

            while (stream.good()) {   // after that we go through the whole line of strings which are separated by a coma(,).
                string substring;              // we divide them into substrings and include them in the contents vector
                getline(stream, substring, ',');  // after that we start accessing every string in the contents vector and converting it to the type we need
                contents.push_back(substring);
            }
            if (contents[0] == "Car") {  // we start by checking the first string of the line, and we understand the type of the vehicle. After we know the type, 
                FuelType fuelType = convertFuelType(contents[7]);  //we just convert the other strings to match the constructor attributes
                vehicles.push_back(new Car(contents[1], contents[2], contents[3], stoi(contents[4]), stoi(contents[5]), //we use stoi to convert from string to integer and stod to convert strings from the file to double, so we can use them to calculate
                    contents[6], fuelType, stod(contents[8]), stoi(contents[9]), stod(contents[10]), stod(contents[11]), String2Bool(contents[12]), stod(contents[13])));
               // we put the newly created object, in that case was Car into the vehicles vector
            } //repeat the same for every type of vehicle
            else if (contents[0] == "Electric") {
                FuelType fuelType = convertFuelType(contents[7]);
                vehicles.push_back(new Electric(contents[1], contents[2], contents[3], stoi(contents[4]), stoi(contents[5]),
                    contents[6], fuelType, stod(contents[8]), stoi(contents[9]), stod(contents[10]), stod(contents[11]), String2Bool(contents[12]), stod(contents[13])));     
            }
            else if (contents[0] == "Van") {
                VanType vanType = covertVanType(contents[2]); // Van type object has another additional enum type that needs to be checked
                FuelType fuelType = convertFuelType(contents[10]);
                vehicles.push_back(new Van(stoi(contents[1]), vanType, stoi(contents[3]), contents[4], contents[5], contents[6], stoi(contents[7]), stoi(contents[8]), contents[9],
                    fuelType, stod(contents[11]), stoi(contents[12]), stod(contents[13]), stod(contents[14]), String2Bool(contents[15]), stod(contents[16])));
            }
            else if (contents[0] == "Luxury") {
                FuelType fuelType = convertFuelType(contents[9]);
                vehicles.push_back(new Luxury(String2Bool(contents[1]), String2Bool(contents[2]), contents[3], contents[4], contents[5], stoi(contents[6]), stoi(contents[7]),
                    contents[8], fuelType, stod(contents[10]), stoi(contents[11]), stod(contents[12]), stod(contents[13]), String2Bool(contents[14]), stod(contents[15])));
            }
            else if (contents[0] == "Scooter") {
                vehicles.push_back(new Scooter(contents[1], stod(contents[2]), stod(contents[3]), stod(contents[4]), stoi(contents[5]), stod(contents[6])));
            }
            else if (contents[0] == "Bike") {
                vehicles.push_back(new Bike(contents[1], stoi(contents[2]), stod(contents[3]), stod(contents[4]), stoi(contents[5]), contents[6], stoi(contents[7])));
            }
            else if (contents[0] == "Kart") {
                vehicles.push_back(new Kart(contents[1], stoi(contents[2]), stod(contents[3]), stoi(contents[4]), stoi(contents[5]), stoi(contents[6])));
            }
            else if (contents[0] == "RX7") {
                vehicles.push_back(new RX7(contents[1], stoi(contents[2]), stod(contents[3]), stoi(contents[4]), stoi(contents[5]), stoi(contents[6])));
            }
            else if (contents[0] == "RX250") {
                vehicles.push_back(new RX250(stod(contents[1]), String2Bool(contents[2]), contents[3], stoi(contents[4]), stod(contents[5]), stoi(contents[6]), stoi(contents[7]), stoi(contents[8])));
            }
            else if (contents[0] == "Double") {
                vehicles.push_back(new Double(stoi(contents[1]), stod(contents[2]), contents[3], stoi(contents[4]), stod(contents[5]), stoi(contents[6]), stoi(contents[7]), stoi(contents[8])));
            }
            else { 
                cerr << "could not process data" << endl;
            }
        }
    }
    return vehicles;
}


    int main()
    {
       //vector<Vehicle*>vehicles;
       
        vector<Vehicle*>vehicles = retrieveData("Data.txt");  //creating new vector 
 
        cout << "The program shows all rented vehicles: " << endl;  
        quickSort(vehicles, 0, vehicles.size() - 1);  // call the quicksort algorith for the vector items that we have created

        cout << "All vehicles sorted by total price: " << endl;  // we SORT BY TOTAL PRICE (but additionaly show the rent and refill prices for more information)
        for (Vehicle* v : vehicles)
        {
            cout << "\n\tName: " << v->getName() << "\n\tTotal price: " << v->getTotalPrice() << "$" <<"\n\tTotal rent price: " << v->getTotalRentPrice() << "$" << "\n\tTotal refill price: " << v->getRefillTankPrice() << "$" << endl;
        }

        cout << "\n\nAre you looking for a specific vehicle ?\n " << endl;
        string pat;
        cout << "Enter what you are searching: " << endl;
        cin >> pat;
        cout << "\nVehicles with the current match :\n " << endl;
        for (Vehicle* v : vehicles)
        {  // display the matching items through a for loop 

            string txt = v->getName();

            bool match = KMPSearch(pat, txt);

            if (match == true)
            {
                cout << v->getName() << " - Total price: " << v->getTotalPrice() << "$" << endl;
            }
        }

    }
