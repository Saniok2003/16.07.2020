#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <map>
#include <fstream>
using namespace std;


class Directory
{
private:
    string company;
    string owner;
    string tel;
    string address;
    string job;
    friend ostream& operator<<(ostream& os, const Directory& str);
    friend istream& operator>>(istream& in, Directory& str);
public:
    Directory()
    {   }
    Directory(string company, string owner, string tel, string address, string job)
    {
        this->company = company;
        this->owner = owner;
        this->tel = tel;
        this->address = address;
        this->job = job;
    }

    void Write(vector<Directory> vec, ifstream& ifs)
    {
        ifs.open("test.txt");
        if (!ifs.bad())
        {
            Directory buff;
            ifs >> buff;
            vec.push_back(buff);
            ifs.close();
        }
    }
    
    void Read(vector<Directory> vec, ofstream& ofs) 
    {
        ofs.open("test.txt");
        if (!ofs.bad())
        {
            for (auto i = vec.begin(); i != vec.end(); i++)
                ofs << *i;

            ofs.close();
        }
    }

    void FindData(vector<Directory> vec, const string& str) 
    {
        auto it = find_if(vec.begin(), vec.end(), [&str](const Directory& dir)
        {
            return dir.company == str;
        });
        if (it != vec.end())
        { 
            cout << *it;
        }
        else
        {
            cout << "Not found!" << endl;
        }
            
    }
    void Show(vector<Directory>& vec) 
    {
        for (auto i = vec.begin(); i != vec.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }

};
ostream& operator<<(ostream& ofs, const Directory& str)
{
    ofs << "Company: " << str.company;
    ofs << "Owner: " << str.owner;
    ofs << "Phone number: " << str.tel;
    ofs << "Address: " << str.address;
    ofs << "Job: " << str.job << endl;
    return ofs;
}
istream& operator>>(istream& ifs, Directory& str)
{
    ifs >> str.company;
    ifs >> str.owner;
    ifs >> str.tel;
    ifs >> str.address;
    ifs >> str.job;
    return ifs;
}

int main()
{
    return 0;
}

