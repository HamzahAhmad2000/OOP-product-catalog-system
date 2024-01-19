#include "Inventory.h"

Inventory::Inventory(string name)
{
	fileName = name;
}

void Inventory::setName(string name)
{
    fileName = name;
}

void Inventory::add()
{
    Products temp;
    char name[150], catagory[150];
    int stock=0, price=0;
    cout << "Enter product name: ";
    cin.getline(name, 150);
    cout << "Enter product catagory: ";
    cin.getline(catagory, 150);
    cout << "Enter product price: ";
    cin >> price;
    cout << "Enter product in stock: ";
    cin >> stock;

    temp.setName(name);
    temp.setCatagory(catagory);
    temp.setPrice(price);
    temp.setStock(stock);

        ofstream myFile(fileName, ios::binary | ios::app);
        if (myFile.write((char*)&temp, sizeof(temp)))
            cout << "Product added to inventory" << endl;
        else
            cout << "Couldnt add product" << endl;
        myFile.close();
   
}

void Inventory::removeProd()
{
    char name[150];
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

void Inventory::display()
{
    Products temp;
    ifstream myFile(fileName, ios::binary);
    while (myFile.read((char*)&temp, sizeof(temp))) {
        temp.display();
    }
    myFile.close();
}

void Inventory::edit()
{
    Products temp;

    char update[150];
    char name[150];
    char option;
    cout << "Enter name of product you want to edit" << endl;
    cin.getline(name, 150);

    cout << "What would you like to change in inventory" << endl;
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
