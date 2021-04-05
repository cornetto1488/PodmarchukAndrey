#include <string>
#include <iostream>

using namespace std;

struct obj {
	string name;
	obj* pointer1, * pointer2;
	void writePoiters() {
		if (pointer1 && pointer2)
			cout << "I " << name << " have pointer to " << pointer1->name << endl << "I " << name << " have pointer to " << pointer2->name << endl;
		else if (pointer1 && !pointer2)
			cout << "I " << name << " have pointer to " << pointer1->name << endl;
		else if (!pointer1 && pointer2)
			cout << "I " << name << " have pointer to " << pointer2->name << endl;
		else
			cout << "I " << name << " dont have any pointers." << endl;
	}
};

int main() {
	obj object1 = { "obj1" },
		object2 = { "obj2" },
		object3 = { "obj3" },
		object4 = { "obj4" },
		object5 = { "obj5" },
		object6 = { "obj6" };
	object1.pointer1 = &object2;
	object1.pointer2 = &object3;
	object2.pointer1 = &object3;
	object2.pointer2 = &object4;
	object3.pointer1 = &object2;
	object3.pointer2 = &object5;
	object4.pointer1 = &object5;
	object4.pointer2 = &object6;
	object5.pointer1 = &object4;
	object5.pointer2 = &object6;
	object1.writePoiters();
	object2.writePoiters();
	object3.writePoiters();
	object4.writePoiters();
	object5.writePoiters();
	object6.writePoiters();
}
