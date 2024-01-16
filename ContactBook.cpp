#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Contact
{
    string name;
    string phone;
    string email;
};

void addCont(vector<Contact> &cont)
{
    Contact newCont;
    cout<<"Enter name: ";
    cin>>newCont.name;
    cout<<"Enter phone: ";
    cin>>newCont.phone;
    cout<<"Enter email: ";
    cin>>newCont.email;
    cont.push_back(newCont);
    cout<<"Contact has been saved."<<endl;
}

void dispCont(const vector<Contact> &cont)
{
    for(const auto &contact : cont)
    {
        cout<<"Name: "<<contact.name<<", Phone: "<<contact.phone
        <<", Email: "<<contact.email<< endl;
    }
}

void searchCont(const vector<Contact> &cont)
{
    string searchSaved;
    cout<<"Enter name to search: ";
    cin>>searchSaved;

    bool res = false;
    for(const auto &contact : cont)
    {
        if(contact.name == searchSaved)
        {
            cout<<"Name: "<<contact.name<<", Phone: "<<contact.phone
            <<", Email: "<<contact.email<< endl;
            res = true;
            break;
        }
    }

    if(!res)
    {
        cout<<"Contact not found."<<endl;
    }
}

void delCont(vector<Contact> &cont)
{
    string delName;
    cout<<"Enter name to delete: ";
    cin>>delName;

    auto temp=remove_if(cont.begin(),cont.end(),[&](const Contact &contact){ return contact.name == delName; });

    if(temp != cont.end())
    {
        cont.erase(temp, cont.end());
        cout<<"Contact has been erased."<<endl;

    }
    else
    {
        cout<<"Contact not found."<<endl;
    }
}

int main()
{
    vector<Contact> cont;
    int ch;

    do
    {
        cout << "\n1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Search Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;

        switch(ch)
        {
            case 1:
            addCont(cont);
            break;
            case 2:
            dispCont(cont);
            break;
            case 3:
            searchCont(cont);
            break;
            case 4:
            delCont(cont);
            case 5:
            cout<<"Contact Book closed.";
            break;
            default:
            cout<<"Invalid choice."<<endl;
            break;
        }
    }while(ch != 5);    
 
    return 0;
}