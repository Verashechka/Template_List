#include <iostream>
#include <string>
#include "Errors.h"
#include "Class_List.h"
using namespace std;

int main()
{
	list<string> a;
	string data;
	int index;
	int menu;
	do
	{
		try
		{
			system("cls");
			cout << "0-output list\n1-push_back\n2-push_front\n3-pop_back\n4-pop_front \n5-insert\n6-at\n7-remove\n8-get_size\n9-clear\n10-set\n11-isEmpty\n\n12-Exit\n";
			cin >> menu;
			switch (menu)
			{
			case 0:
				cout << a;
				break;
			case 1:
				cout << "Enter data: ";
				cin >> data;
				a.push_back(data);
				break;
			case 2:
				cout << "Enter data: ";
				cin >> data;
				a.push_front(data);
				break;
			case 3:
				a.pop_back();
				cout << "An element has been poped\n";
				break;
			case 4:
				a.pop_front();
				cout << "An element has been poped\n";
				break;
			case 5:
				cout << "Enter data: ";
				cin >> data;
				cout << "Enter index: ";
				cin >> index;
				a.insert(data, index);
				break;
			case 6:
				cout << "Enter index: ";
				cin >> index;
				cout << "\n" << a.at(index);
				break;
			case 7:
				cout << a;
				cout << "Enter index: ";
				cin >> index;
				a.remove(index);
				cout << "An element has been removed\n";
				break;
			case 8:
				cout << "Size of list is " << a.get_size();
				break;
			case 9:
				a.clear();
				break;
			case 10:
				cout << "Enter data: ";
				cin >> data;
				cout << "Enter index: ";
				cin >> index;
				a.set(data, index);
				break;
			case 11:
				cout << a.is_empty();
				break;
			case 12:

				break;
			default:
				break;
			}
		}
		catch (Wrong_index_of_element a)
		{
			cout << a.what();
		}
		catch (Head_is_null a)
		{
			cout << a.what();
		}
		system("pause");
	} while (menu != 12);
	return 0;
}