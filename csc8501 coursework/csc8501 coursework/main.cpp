
#include <fstream>
#include <iostream>
#include <vector>
#include<string>
#include <sstream>

#include "encrypt.h"
using namespace std;







int main() {
	

	std::string username;
	std::string password;
	vector<long long> encrypted_password;
	ofstream users_pw;
	users_pw.open("data_user_test.txt");
	cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬``¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
	cout << " please input your username" << endl;
	getline(cin, username);
	cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬``¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
	cout << " please input your password" << endl;
	getline(cin, password);
	encrypt(password, encrypted_password);
	

	/*cout << password << endl;*/



	users_pw << username << ' ' /*<< password << ' '*/ ;

	for (auto it = encrypted_password.begin(); it != encrypted_password.end(); ++it) {
		cout << * it;
		users_pw << *it;
	}
	cout << endl;
	users_pw << " \n";
	users_pw.close();

	ifstream users_pw_open;
	users_pw_open.open("data_user_test.txt" ,  ios::in);
	/*char total;*/
	//string total;
	//int s;


	//while (users_pw_open >> total ) {
	//	cout << total << ' ';
	//}
	string username_test;
	string username_test_sample;
	long long password_test_sample;
	getline(users_pw_open, username_test);
	istringstream ss(username_test);
    ss >> username_test_sample >> password_test_sample;
	cout << username_test_sample << ' ' << password_test_sample;
	
	users_pw_open.close();

	authenticating();

	

    

	
	/*string total;
	*/

	//return 0;
}