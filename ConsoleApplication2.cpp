#include <bits/stdc++.h>
using namespace std;
ifstream fin("userbase.inout");
ofstream fout("userbase.inout", ios::out | ios::trunc);

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
    void userdisplay()
    {
        cout << username << ' ' << password << '\n';
    }
    void fileuserdisplay()
    {
        fout << username << ' ' << password << '\n';
    }
    bool userexcheck(string newname)
    {
        if (newname == username)
            return 1;
        return 0;
    }
    bool passcheck(string newpass)
    {
        if (newpass == password)
            return 1;
        return 0;
    }
};
int act, con, i, j;
string newname, newpass, newpass2, newpass3, newname2;
char v;
user n[1005];
int main()
{
    cout << "enter action \n 1.Log in  \n 2.Create user \n 3.List users \n 4.exit \n";
    fin >> con;
    for (i = 1; i <= con; i++)
    {
        fin >> newname >> newpass;
        n[i].createuser(newname, newpass);
    }
    /*de adaugat schimbare user si parola dupa logare*/
    while (true)
    {
        cin >> act;
        switch (act)
        {
        case 1:
        {
            bool ok = 0;
            cout << "are you sure you want to proceed?(y/n) \n";
            cin >> v;
            if (v == 'n')
                break;
            cout << "enter username";
            do
            {
                cin >> newname;
                for (i = 1; i <= con; i++)
                {
                    if (n[i].userexcheck(newname))
                        ok = 1;
                }
                if (ok == 0)
                    cout << "user does not exist";
            } while (!ok);
            ok = 0;
            do
            {
                cin >> newpass;
                if (n[i].passcheck(newpass))
                    ok = 1;
            } while (!ok);
            cout << "succesfull login, welcome";
            /// de scris asta ca mie lene
            break;
        }
        case 2:
        {
            cout << "are you sure you want to proceed?(y/n) \n";
            cin >> v;
            if (v == 'n' || v == 'N')
                break;
            cout << "enter username and password \n";
            cin >> newname >> newpass;
            cout << "enter password again \n";
            cin >> newpass2;
            if (newpass == newpass2)
            {
                n[++con].createuser(newname, newpass);
                cout << "user succesfully created, enter new action \n";
            }
            break;
        }
        case 3:
        {
            cout << "username" << ' ' << "password \n";
            for (i = 1; i <= con; i++)
                n[i].userdisplay();
            break;
        }
        case 4:
        {
            fout << con << '\n';
            for (i = 1; i <= con; i++)
                n[i].fileuserdisplay();
            return 0;
        }
        default:
        {
            cout << "wrong input \n";
            break;
        }
        };
    }
}