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
	string un(int i)
	{
		return username[i];
	}
	string pas(int i)
	{
		return password[i];
	}
};