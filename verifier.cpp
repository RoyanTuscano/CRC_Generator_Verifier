#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
using namespace std;
static void division(char *message, char *generator, char *remainder, int m_len, int g_len, int r_len, int startptr);
static void XOR(char *a, char *b, char *c);

int main()
{
    string line;
/*
    while (getline(cin, line)) // read from std::cin
    {
        // show that it arrived
        cout << "Line Received: " << line << '\n';
    }*/
    getline(cin, line);
     cout << "Message received: " << line << '\n';
    int i_len;
    i_len = line.length();
 //   cout<<"i_len"<<i_len<<"Line"<<line<<endl;
    char input_message[i_len];
    strcpy(input_message, line.c_str());
    getline(cin, line);
    cout << "Polynomial received: " << line << '\n';
    int k_len;
    k_len = line.length();
    char polynomial[k_len + 1];
    strcpy(polynomial, line.c_str());
            int r_len = k_len - 1;
        char remainder[r_len];
      int tempptr = 0;
        while (input_message[tempptr] == '0')
        {
            tempptr++;
        }
    division(input_message, polynomial, remainder, i_len, k_len, r_len, tempptr);
  //  cout<<remainder<<" "<<i_len<<k_len<<r_len<<endl;
    for(int i=0; i<r_len;i++)
    {
        if(remainder[i]!='0')
        {
            cout<<"There is Error in Transmission";
            return 0;
        }

    }
    cout<<"Transmission Successful,NO error found";

    return 0;
}
void XOR(char *a, char *b, char *c)
{
    if ((*b == '0' && *c == '0') | (*b == '1' && *c == '1'))
    {
        *a = '0';
    }
    else
    {
        *a = '1';
    }
}
void division(char *message, char *generator, char *remainder, int m_len, int g_len, int r_len, int startptr)
{
    //start from begining and do the exor
    bool only_once = true;
    int temp = startptr;
    for (int i = temp; i < (temp + g_len); i++)
    {
        XOR(&message[i], &generator[(i - temp)], &message[i]);
        //division with that byte
        if ((message[i] == '0') && only_once == true)
        {
            // only_once=false;
            startptr++;
        }
        else
        {
            only_once = false;
        }
    }
    //  cout<<endl<<"startptr "<<startptr<<" Message : ";
    //  print_char(message,m_len);

    if (m_len - startptr > r_len)
    {
        division(message, generator, remainder, m_len, g_len, r_len, startptr);
    }
    strncpy(remainder, &message[m_len - r_len], r_len);
    return;
}