#include <string>
#include <iostream>
 
using namespace std;
 
struct obj {
    string name;
    obj* pointer1, * pointer2;
    void writePoiters() {
        if (pointer1 && pointer2)
            cout << "I " << name << " have pointer to " << pointer1->name << " and to " << pointer2->name << endl;
        else if (pointer1 && !pointer2)
            cout << "I " << name << " have pointer to " << pointer1->name << endl;
        else if (!pointer1 && pointer2)
            cout << "I " << name << " have pointer to " << pointer2->name << endl;
        else
            cout << "I " << name << " dont have any pointers." << endl;
    }
};
 
int getInt()
{
    int number;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Do input again." << endl;
        }
        else
            return number;
    }
}
 
int main() {
    obj* objects;
    int numberOfLayers, numberOfObjects;
    cout << "Input numbers of layers: ";
    while (true) {
        numberOfLayers = getInt();
        if (numberOfLayers < 0) {
            cout << "Number of layers must be > 0: ";
            continue;
        }
        else
            break;
    }
 
    if (numberOfLayers == 1 || numberOfLayers == 2)
        numberOfObjects = numberOfLayers;
    else
        numberOfObjects = (numberOfLayers - 2) * 2 + 2;
 
    objects = new obj[numberOfObjects];
    for (int i = 0; i < numberOfObjects; i++)
        objects[i].name = "object" + to_string(i + 1);
 
    objects[numberOfObjects - 1].pointer1 = nullptr;
    objects[numberOfObjects - 1].pointer2 = nullptr;
    if (numberOfObjects == 2) {
        objects[0].pointer1 = &objects[1];
        objects[0].pointer2 = &objects[1];
    }
    else if (numberOfObjects > 2) {
        objects[0].pointer1 = &objects[1];
        objects[0].pointer2 = &objects[2];
        for (int i = 1; i < numberOfObjects - 1; i++) {
            if (i % 2 == 1)
                objects[i].pointer1 = &objects[i + 1];
            else
                objects[i].pointer1 = &objects[i - 1];
            if (i + 2 != numberOfObjects)
                objects[i].pointer2 = &objects[i + 2];
            else
                objects[i].pointer2 = &objects[i + 1];
        }
    }
 
    for (int i = 0; i < numberOfObjects; i++)
        objects[i].writePoiters();
 
    return 0;
}
