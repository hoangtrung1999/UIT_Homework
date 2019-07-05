#include <bits/stdc++.h> 
using namespace std; 

// driver code 
int main() 
{ 
    // filestream variable file 
    fstream file; 
    ifstream input;
    ofstream output;
    char word; 
    unordered_map <char, long long int> preCode;
    // opening file 
    file.open("Test_Case.txt", fstream::in); 
    input.open("PreCode.txt", ios::app);
    output.open("Compress.bin",ios::out | ios::binary);
    // input precodeex
    int size;
    char c;
    long long int d;
    std::string line;
    while(getline(input, line))
    {
        input >> c >> d;
        cout<<c<<" "<<d<<endl;
        pair<char, long long int> mydata(c,d);
        preCode.insert(mydata);
    }
    input.close();
    // extracting words form the file 
    unordered_map<char, long long int>:: iterator p;

    while (file >> word) 
    {
        for (p = preCode.begin(); p != preCode.end(); p++)
            if (p->first == word)
            {
                d = p->second;
                output.write ((char*) &d, sizeof(long long int));
                break;
            }
    } 
    file.close();
    output.close();
    return 0; 
} 
