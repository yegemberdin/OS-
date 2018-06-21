#include <bits/stdc++.h>
using namespace std;
vector<string> buf(20, "NULL");
void menu();
void insert(){
    cout << "enter name: ";
	string fname;
	cin >> fname;
	cout << "start: ";
	int st;
	cin >> st;
	cout << "length:";
	int l;
	cin >> l;
   	for(int i = st; i <(st+l); i++){
		buf[i] = fname;
	}
	cout << "done" << endl;
	menu();

}
void ddelete(){
   	cout << "file name: ";
	string fname;
	cin >> fname;
	for(int i = 0; i < buf.size(); i++){
		if(fname == buf[i]){
			buf[i] = "NULL";
		}
	}
	cout << "done" << endl;
	menu();
}
void compact(){
    for(int i = 0; i < buf.size(); i++){
		if(buf[i] == "NULL"){
			for(int j = i; j < buf.size(); j++){
				if(buf[j] != "NULL"){
					swap(buf[i], buf[j]);
					break;
				}
			}
		}
	}
	cout << "done" << endl;
	menu();
}

void display(){
	cout << "---------------------------------------------------------------------------------" << endl;
	for(int i = 1; i < buf.size(); i++){
		cout << i << ": " << buf[i] << "  ";
	}
	cout << "---------------------------------------------------------------------------------" << endl;
	menu();
}

void menu(){
    int choice;
    cout<<"Enter ur choice to exit press 0"<<endl;
    cout << "1. Insert file" << endl;
	cout << "2. Delete file" << endl;
	cout << "3. Compact file" << endl;
	cout << "4. Display" << endl;
	cin >> choice;
	if (choice==1){
	    insert();
	}
	else if(choice==2){
	    ddelete();

	}
	else if(choice==3){
	    compact();
	}
	else if(choice==4){
	    display();
	}
	else if(choice==0){
	    exit(0);
	}
}

int main(){
    cout<<"buffer size is 20"<<endl;
   	menu();
    return 0;
}




