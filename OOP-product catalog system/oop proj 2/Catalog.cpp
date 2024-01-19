#include "Catalog.h"

Catalog::Catalog(string name)
{
	fileName = name;
}

void Catalog::add()
{
    Products temp;
    cin.ignore();
    char name[150], catagory[150];
    int price = 0;

    cout << "Enter product name: ";
    cin.getline(name, 150);
    cout << "Enter product catagory: ";
    cin.getline(catagory, 150);

    cout << "Enter product price: ";
    cin >> price;

    temp.setName(name);
    temp.setCatagory(catagory);
    temp.setPrice(price);

    ofstream myFile(fileName, ios::binary | ios::app);
    if (myFile.write((char*)&temp, sizeof(Products)))
        cout << "Product added to catalog" << endl;
    else
        cout << "Couldnt add product" << endl;
    myFile.close();
}

void Catalog::removeProd()
{
    char name[150];
    cin.ignore();
    cout << "Enter product name to remove: ";
    cin.getline(name, 150);

    Products temp;
    fstream myFile(fileName, ios::in | ios::out | ios::binary);
    ofstream myFile_temp("temp.bin", ios::app | ios::binary);
    while (myFile.read((char*)&temp, sizeof(temp))) {
        if (temp.getName() != name) {
            myFile_temp.write((char*)&temp, sizeof(temp));
        }
    }
    myFile.close();
    myFile_temp.close();
    const char* filename = fileName.c_str();
    remove(filename);
    rename("temp.bin", filename);
}

void Catalog::display()
{
    Products temp;
    ifstream myFile(fileName, ios::binary);
    while (myFile.read((char*)&temp, sizeof(temp))) {
        temp.displayCat();
    }
    myFile.close();
}

void Catalog::edit()
{
    Products temp;
    
    char update[150];
    char name[150];
    char option;
    cin.ignore();
    cout << "Enter name of product you want to edit" << endl;
    cin.getline(name, 150);

    cout << "What would you like to change in catalog" << endl;
    cout << "1. Name" << endl;
    cout << "2. Catagory" << endl;
    cin >> option;

    if (option == '1' || option == '2') {
        cout << "Enter update" << endl;
        cin.getline(update, 150);

        if (option == '1')
        {
            fstream myFile(fileName, ios::in | ios::out | ios::binary);
            while (myFile.read((char*)&temp, sizeof(temp))) {
                if (temp.getName() == name) {
                    strcpy_s(temp.getName(), sizeof(update), update);
                    int current = myFile.tellg();
                    int oneblock = sizeof(temp);
                    myFile.seekg(current - oneblock);
                    myFile.write((char*)&temp, sizeof(temp));
                    myFile.close();
                }
            }
        }
        else {
            fstream myFile(fileName, ios::in | ios::out | ios::binary);
            while (myFile.read((char*)&temp, sizeof(temp))) {
                if (temp.getName() == name) {
                    strcpy_s(temp.getCatagory(), sizeof(update), update);
                    int current = myFile.tellg();
                    int oneblock = sizeof(temp);
                    myFile.seekg(current - oneblock);
                    myFile.write((char*)&temp, sizeof(temp));
                    myFile.close();
                }
            }
        }
    }
    else
        cout << "Invalid choice" << endl;
}
