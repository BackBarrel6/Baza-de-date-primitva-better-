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
    short userreturn(string currentname, string currentpassword) const
    {
        if (username == currentname && password == currentpassword)
            return 1;
        if (username != currentname)
            return 2;
        if (username == currentname && password != currentpassword)
            return 3;
    }
    void changeuser(string newname)
    {
        username = newname;
    }
    void changepass(string newpass)
    {
        password = newpass;
    }
    bool passverify(string newpass1, string newpass2)
    {
        if (newpass1 == newpass2)
            return 1;
        else
            return 0;
    }
    void passchangeread()
    {
    }
};
int act, con;
string newname, newpass, newpass2, newpass3, newname2;
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
                cout << "user succesfully created, enter new action";
            }
            break;
        case 3:
            int act_case3;
            cout << "enter old username and password \n";
            cin >> newname >> newpass;
            cout << "what do you want to change: 1 for username \n 2 for password \n";
            cin >> act_case3;
            for (int i = 1; i <= con; i++)
                switch (n[i].userreturn(newname, newpass))
                {
                case 1:
                    switch (act_case3)
                    {
                    case 1:
                        cout << "enter new pass";
                        do
                        {
                            cin >> newpass2;
                            cout << "please verify the password";
                            cin >> newpass3;
                        } while (!n[i].passverify(newpass2, newpass3));
                        n[i].changepass(newpass2);
                        cout << "password succesfully changed";
                        i = con;
                        break;
                    case 2:
                        cout << "enter new name";
                        n[i].changeuser(newname2);
                        cout << "username succesfully changed";
                        break;
                    default:
                        cout << "wrong input";
                        break;
                    };
                case 2:
                    cout << "user does not exist";
                    break;
                case 3:
                    cout << "password is incorrect";
                    break;
                };
        }
    };
}