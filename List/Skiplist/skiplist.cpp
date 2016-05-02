/**
 * File name: skiplist.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: main executable
 * Date: 04/02/2016
 */
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include "skiplist.hpp"
#include "SLNode.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    vector<string> v;
    string name = "";
    int n;
    int shuffleTime;
    
    //Check for Arguments
    if(argc != 4){
        cout << "Invalid number of arguments.\n"
        << "Usage: ./benchmark_skiplist <input filename>"
        << "<number of elements> <number of shuffle times>.\n";
        return -1;
    }
    
    // Check if user enter a valid number of elements
    char* temp = argv[2];
    while( *temp != 0 ){
        if(!isdigit(*temp)){
            cout<<"Please enter numbers!\n";
            return -1;
        }
        temp++;
    }
    
    // Check if user enter a valid number of shuffle
    temp = argv[3];
    while( *temp != 0 ){
        if(!isdigit(*temp)){
            cout<<"Please enter numbers!\n";
            return -1;
        }
        temp++;
    }
    
    // Get n and shuffle time
    n = atoi(argv[2]);
    shuffleTime = atoi(argv[3]);
    
    //Open file
    ifstream in;
    in.open("/Users/Zhuyupei/Documents/123/123/actors.txt", ios::binary);
    
    //Check if input file was actually opened
    if(!in.is_open())
    {
        cout<< "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }
    
    //Check for empty file
    in.seekg(0, ios_base::end);
    unsigned int len = in.tellg();
    if(len==0)
    {
        cout << "The file is empty. \n";
        return -1;
    }
    
    //Resets the stream to beginning of file
    in.seekg(0, ios_base::beg);
    
    //main function implementation should go here
    
    //add names from the file to the vector
    int i = 0;
    while (getline(in, name) && i < n)
    {
        v.push_back(name);
        i++;
    }
    
    // vector to save the comparison times for each shuffle
    vector<double> timeArr;
    
    // do shuffleTime times of whole implement
    for(i = 0;i < shuffleTime; i++){
        skiplist<string> sl(""); // create a new skiplist
        
        // insert elements to the vector
        vector<string>::iterator vit = v.begin();
        vector<string>::iterator ven = v.end();
        for(vit = v.begin(); vit != ven; ++vit) {
            sl.insert(*vit);
        }
        
        double sum = 0;// save the number of comparisons
        
        // start to find elements
        for(vit = v.begin(); vit != ven; ++vit) {
            double t = sl.find(*vit).getTime();
            sum += t;
        }
        
        // save the sum to timeArr
        timeArr.push_back(sum/n);
        // reshuffle the vector
        random_shuffle(v.begin(), v.end());
    }
    // calculate the average and standard deviation
    double standardD = 0;
    double sum =0;
    for (double m: timeArr)
    {
        sum += m;
    }
    double average = sum / shuffleTime;
    for (double m: timeArr)
    {
        standardD += (m - average)*(m - average);
    }
    
    standardD = standardD / shuffleTime;
    
    standardD = sqrt(standardD);
    // print the results
    cout << "number of elements: " << n << " average compare time: " << average
    << " standard Deviation: " << standardD << endl;
    if(in.is_open())
        in.close();
    return 0;
}