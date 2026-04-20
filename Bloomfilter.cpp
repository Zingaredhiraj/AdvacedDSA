#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// Hash Function 1
int h1(string s, int arrSize)
{
    int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + int(s[i]);
        hash = hash % arrSize;
    }
    return hash;
}

// Hash Function 2
int h2(string s, int arrSize)
{
    int hash = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + (i * int(s[i]));
        hash = hash % arrSize;
    }
    return hash;
}

// Hash Function 3
int h3(string s, int arrSize)
{
    int hash = 2;
    for (int i = 0; i < s.size(); i++)
    {
        hash = hash + pow(19, i);
        hash = hash % arrSize;
    }
    return hash;
}

// Insert Function
void insert(int bfilter[], string name, int arrSize)
{
    int a = h1(name, arrSize);
    int b = h2(name, arrSize);
    int c = h3(name, arrSize);

    if (bfilter[a] == 1 && bfilter[b] == 1 && bfilter[c] == 1)
    {
        cout << "\nThe Name is Probably Present !!\n";
    }
    else
    {
        bfilter[a] = 1;
        bfilter[b] = 1;
        bfilter[c] = 1;

        cout << name << " is inserted !!\n";
    }
}

// Search Function
void search(int bfilter[], string name, int arrSize)
{
    int a = h1(name, arrSize);
    int b = h2(name, arrSize);
    int c = h3(name, arrSize);

    if (bfilter[a] == 1 && bfilter[b] == 1 && bfilter[c] == 1)
    {
        cout << name << " is Probably Present !!\n";
    }
    else
    {
        cout << name << " is NOT Present !!\n";
    }
}

// Main Function (User Input)
int main()
{
    int arrSize = 10;
    int bfilter[10] = {0};

    int choice;
    string name;

    while (true)
    {
        cout << "\n--- Bloom Filter Menu ---\n";
        cout << "1. Insert Name\n";
        cout << "2. Search Name\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter name to insert: ";
            cin >> name;
            insert(bfilter, name, arrSize);
            break;

        case 2:
            cout << "Enter name to search: ";
            cin >> name;
            search(bfilter, name, arrSize);
            break;

        case 3:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
