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
//XOR operation for char

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

int main()
{

    string line;
    ifstream myfile("input.txt");
    if (myfile.is_open())
    {
        getline(myfile, line);
        int i_len;
        i_len = line.length();
        char input_message[i_len];
        strcpy(input_message, line.c_str());
        getline(myfile, line);
        int k_len;
        k_len = line.length();
        char polynomial[k_len + 1];
        strcpy(polynomial, line.c_str());
        //  cout << "print input " << sizeof(input_message) << endl;
        //  print_char(input_message, i_len);
        //    cout << "print poly " << sizeof(polynomial) << endl;
        //        print_char(polynomial, k_len);

        int message_size = k_len + i_len - 1;

        char new_message[message_size];
        char output_message[message_size + 1] = "";
        //store data in it
        strncpy(new_message, input_message, i_len);
        //add the padding
        for (int i = i_len; i < message_size; i++)
        {
            new_message[i] = '0';
        }
        strncpy(output_message, new_message, message_size);
        //   cout << endl
        //        << "New Message " << sizeof(new_message) << endl;
      //  print_char(new_message, message_size);
        int r_len = k_len - 1;
        char remainder[r_len];
        int tempptr = 0;
        while (new_message[tempptr] == '0')
        {
            tempptr++;
        }

        division(new_message, polynomial, remainder, message_size, k_len, r_len, tempptr);
        //do the division and get the remainder
        //     cout << endl
        //          << "division output " << endl;
     //   print_char(remainder, r_len);
        //replace the remainder terms in the new message
        //output message

        for (int i = i_len; i < message_size; i++)
        {
            output_message[i] = remainder[i - i_len];
        }
        //      cout<<"The new Message:"<<sizeof(output_message)<<endl;
       
        print_char(output_message, message_size);
         cout << endl;
         print_char(polynomial, k_len);
        myfile.close();
        ofstream myfile("Output.txt");
        if (myfile.is_open())
        {
            //  myfile<<"output"<<endl;
            myfile << output_message << endl;
            myfile << polynomial << endl;
        }
    }
    return 0;
}