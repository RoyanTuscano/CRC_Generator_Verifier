#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;
void print_char(char *to_print, int &i_len)
{
    for (int i = 0; i < i_len; i++)
        cout << to_print[i]; //<<" ,";

    return;
}
int main(int arg, char *argv[])
{
    int bitNo;
    for (int i = 0; i < arg; i++)
    {
        bitNo = atoi(argv[i]);
    }
    string line;
    getline(cin, line);
    int i_len;
    i_len = line.length();
    char input_message[i_len];
    strcpy(input_message, line.c_str());
    getline(cin, line);
    int k=line.length();
    // alter the bitNo in the passed message
  if(bitNo<k+i_len){
    if (input_message[bitNo - 1] == '1')
        input_message[bitNo - 1] = '0';
    else
        input_message[bitNo - 1] = '1';
  }


    print_char(input_message, i_len);
    cout<<endl<<line;
    

    return 0;
}