#include <iostream>
#include <fstream>
using namespace std;



int main(){
    int cnt = 0;
    string Arr[50];
    bool ValidUser = 0;
    bool ValidPass = 0;
    ifstream file;
    file.open("peopleData.txt");

    while (!file.fail()){
        string Val;
        file >> Val;
        Arr[cnt] = {Val};
        cnt += 1;
        }



    string username;
    string password;
    cout << "Enter username:" << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;

    for(int i = 0; i < cnt/2; ++i){
        if(username == Arr[i*2]){
            ValidUser = 1;
            if(password == Arr[i*2+1]){
                cout << "Login successful!" << endl;
            }
            else{
                cout << "Alert! Hacker detected!" << endl;;
            }
        }
    }
    if(ValidUser == 0){
        cout << "No account created." << endl;
    }






    file.close();
}
