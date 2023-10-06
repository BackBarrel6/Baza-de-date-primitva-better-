#include <bits/stdc++.h>
using namespace std;
class user
{
private:
    string username, password;

public:
    void createuser(string newname, string newpass)
    {
        username = newname;
        password = newpass;
    }
	/*int userreturn(string currentname, string currentpassword)
	{

	}*/
};
int act, con;
string newname, newpass, newpass2;
user n[1005];
int main()
{
    cout << "enter action \n 1.Log in \n 2.Create user \n 3.Change password or username \n 4.List users \n 5.(admin)Read users from file \n"; 
    cin >> act;
    while (true)
    {
        switch (act)
        {
        case 1:
            /// de scris asta ca mie lene
        case 2:
            cout << "enter username and password";
            cin >> newname >> newpass;
            cout << "enter password again";
            cin >> newpass2;
            if (newpass == newpass2)
                {
					n[++con].createuser(newname, newpass);
					cout<<"user succesfully created, enter new action";
				}
            break;
		case 3:
		int actcase3;
			cout<<"enter old username and password \n";
		cin>>newname>>newpass;
			cout<< "what do you want to change: 1 for username \n 2 for password \n";
				cin>>actcase3;
			switch(actcase3)
			{case 1:


			};
        }
    };
}