#include <iostream>
#include "encrypt.h"
#include  <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

bool encrypt(string a, vector<long long> &s) {
	
	vector<int> encrypted_password;
	
	int len=a.length();

	long long offset=0;
	
	for (int i = 0; i < len; ++i) {
		
		int b=(int)a[i]+offset;
		
		offset = 0;
		while (b != 1) {
			if (b % 2 == 0) {
				b = b / 2;
			}
			else {
				b = 3*b + 1;
			}
			offset = offset + 1;
			
		}
	
		encrypted_password.push_back(offset);
		s.push_back(offset);
	}


	/*for (auto it = encrypted_password.begin(); it != encrypted_password.end(); ++it){
		cout << (int)* it;
	}*/

	return 1;

}

void authenticating() {
	string username;
	string password;

	vector<long long> encrypted_password_visa;
	cout << " please login in your account" << endl;
	cout << "Username: " << endl;
	getline(cin, username);
	cout << "Password: " << endl;
	getline(cin, password);
	encrypt(password, encrypted_password_visa);
	const int lenth = encrypted_password_visa.size();
	string as;
	for (int i = 0; i < lenth; ++i) {
		string s;
		stringstream ss(s);
		ss << encrypted_password_visa[i];
		as = as + ss.str();
	}
	cout << as << endl;


	//int encrypted_password_visa[];
	//for (int i = 0; i < lenth; ++i) {
	//	int[i] = encrypted_password_visa[i];
	//}

	string username_timely;
	ifstream infile;
	string a;
	string b;
	vector<string> total_username;
	vector<string> total_password;
	infile.open("users and password.txt");
	/*infile >> username;
	cout << username;
	for (auto it = encrypted_password_visa.begin(); it != encrypted_password_visa.end(); ++it) {
		cout << *it;
		infile >> *it;
	}*/


	while (getline(infile, username_timely)) {
		istringstream ss(username_timely);
		ss >> a >> b;
		total_username.push_back(a);
		total_password.push_back(b);

	}

	infile.close();
	int x = 0;
	int y = 0;

	for (auto it = total_username.begin(); it != total_username.end(); ++it) {
		if (username == *it) {
			cout << "your username is vaild" << endl;
			y = 1;
			for (auto its = total_password.begin(); its != total_password.end(); ++its) {
				if (password == *its) {
					cout << " your password is correct" << endl;
					x = 1;
					break;
				}
				

			}
		}
		else;
	}
	if (x == 0) {
		cout << "your usename is wrong" << endl;
	}
	else if(x==1 && y==0){
		cout << "your password is wrong" << endl;

	}
	
}


