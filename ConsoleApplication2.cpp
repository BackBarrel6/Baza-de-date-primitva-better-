#include<bits/stdc++.h>
using namespace std;
class user
{
private:
	string username[1005], password[1005];
public:
	void createuser(string newname, string newpass, int i)
	{
		username[i] = newname;
		password[i] = newpass;
	}
	bool passcheck(string passcheck, string usercheck, int i) const
	{
		return(password[i] == passcheck && username[i] == usercheck);
	}
	void change(string passch, int i, bool t)
	{
		if (t)
			password[i] = passch;
		else
			username[i] = passch;
	}
	void lista(int i)
	{
		cout << username[i] << "   " << password[i] << " ";
	}
};
int act, con, i;
string newname, newpass, newpass2;
user can[1005];
int main()
{
	cout << "Actiune: \n 1.Log in \n 2.New User \n 3.Change username or password \n 4.List Users \n";
	while (true)
	{
		cin >> act;
		switch (act)
		{
		case 1:
			///de construit functia de logare si actiuni
		case 2:
			cout << "enter usernname and password \n";
			cin >> newname >> newpass;
			cout << "confirm pass \n";
			cin >> newpass2;
			if (newpass == newpass2)
				can[++con].createuser(newname, newpass, con);
			break;
		case 3:
			bool t;
			cout << "enter username and old password \n";
			cin >> newname >> newpass2;
			cout << "do you want to change name or password, 1 for password and 0 for username \n";
			cin >> t;
			for (i = 1; i <= con; i++)
				if (can[i].passcheck(newname, newpass, i))
				{
					cout << "enter new password \n";
					cin >> newpass;
					can[i].change(newpass, i, t);
					break;
				}
			break;
		case 4:
			cout << "username" << "   " << "password \n";
			for (i = 1; i <= con; i++)
				can[i].lista(i);
		default:
			cout << "wrong input \n";
		};
	}
}