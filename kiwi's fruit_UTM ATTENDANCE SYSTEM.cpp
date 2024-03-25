#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>

using namespace std;

class nodeStack
{
    public:
        string FullName;
        string MatricNum;
        string dt;
        nodeStack *next;
        nodeStack(){
            FullName="";
            MatricNum="";
        }
        nodeStack(string FullName, string MatricNum,string dt){
            this->FullName=FullName;
            this->MatricNum=MatricNum;
            this->dt=dt;
        }
};

class stack
{
    private:
        nodeStack* top;
    public:
        void createStack(){
            top=NULL;
        }    
        bool isEmpty(){
            return top == NULL;
        }
        void push();
        void pop();
        void display();
        void search();
        void sort();
        
};

void stack::push()
{
    string newFullName, newMatricNum;
    nodeStack* node = new nodeStack;
    nodeStack* currNode = top;
    time_t datetime = time(0);
    string dt = ctime(&datetime);
    if(node == NULL){
        cout << "Cannot allocate memory." << endl;
    }
    else{
        system("CLS");
        cout << "<<<<<<< Insert Attendance >>>>>>>" << endl << endl;

        cout<<"Enter Matric Number:"<<endl;
        getline(cin,newMatricNum);
        transform(newMatricNum.begin(), newMatricNum.end(), newMatricNum.begin(), ::toupper);
        
        cout<<"Enter Full Name:"<<endl;
        getline(cin,newFullName);
        transform(newFullName.begin(), newFullName.end(), newFullName.begin(), ::toupper);
        

        cout<<"Date : "<<dt<<endl;    
        node->MatricNum = newMatricNum;
        node->FullName = newFullName;
        node->dt=dt;
        
        node->next = top;
        top = node;
    }
}

void stack::pop(){
    nodeStack* delNode;
    nodeStack* currNode = top;
    time_t datetime = time(0);
    string dt = ctime(&datetime);
    system("CLS");
    
    if(top == NULL){
    	cout<<"Attendance is empty"<<endl;
    	cout<<"<<Press any key to continue>>";
		cin.get();
	}
	
	else{
		string matricNum;
		cout << "Enter the Matric Number of the student whose attendance you want to remove: ";
		cin >> matricNum;

		nodeStack* delNode;
		nodeStack* currNode = top;
		nodeStack* prevNode = NULL;

		while (currNode != NULL) {
    		if (currNode->MatricNum == matricNum) {
        		cout << "Full Name : " << currNode->FullName << endl;
        		cout << "Matric Number : " << currNode->MatricNum << endl;
        		cout<<"Date: "<<currNode->dt<<endl;    
        		cout << "<< Press any key to continue >>";
        		cin.get();
        	if (prevNode == NULL) {
            	top = currNode->next;
        	} 
			else {
            	prevNode->next = currNode->next;
        	}
        delNode = currNode;
        delete delNode;
        break;
    }
    prevNode = currNode;
    currNode = currNode->next;
	}
	}

}


void stack::display(){
	int num=0;
	nodeStack* currNode = top;
	system("CLS");
	cout << "<<<<<<< Display Attendance History >>>>>>>" << endl << endl;
	

	if (isEmpty()){
		cout<<"no History"<<endl;
	}
	else{
		while(currNode != NULL){
			cout<<"["<< num++ <<"]" << "\tFull Name : " << currNode->FullName <<endl;
			cout<<"\tMatric Number : " << currNode->MatricNum <<endl;
			cout<<"\tDate: "<<currNode->dt<<endl <<endl;	
			currNode = currNode->next;
		}
	}
	cout<<"<<Press any key to continue>>";
	cin.get();
	
}

void stack::search(){
	int choice;
	string input;
	string abc;
	nodeStack* currNode = top;
	system("CLS");
	cout << "<<<<<<< Search Attendance(s) >>>>>>>" << endl << endl;

	cout << "Enter Matric Number : ";
	getline(cin,input);
	
	if(currNode == NULL){
		cout<<"No Record Found, Stack Empty"<<endl;
	}
	
else{
		bool found = false;
		while(currNode != NULL){
			abc = currNode->MatricNum;
			if(input == abc){
				cout<< "\tPage Full Name : " << currNode->FullName <<endl;
				cout<< "\tPage Matric Number : " << currNode->MatricNum <<endl;
				cout<<"\tDate: "<<currNode->dt<<endl;
				found = true;
			}
			currNode = currNode->next;
		}
		if(!found){
			cout<<"No Record Found"<<endl;
		}
	}
	
	
	cout << "<< Finish searching... Press any key to continue >>";
	cin.get();
}

void stack::sort(){
    nodeStack* currNode;
    nodeStack* nextNode;
    bool swapped;
    int n = 0;
    nodeStack* lastNode = NULL;
    if (isEmpty()){
        cout<<"no data to sort"<<endl;
    }
    else {
        while (lastNode != top) {
            currNode = top;
            swapped = false;
            while (currNode->next != lastNode) {
                nextNode = currNode->next;
                if (currNode->FullName > nextNode->FullName) {
                    swap(currNode->FullName, nextNode->FullName);
                    swap(currNode->MatricNum, nextNode->MatricNum);
                    swap(currNode->dt, nextNode->dt);
                    swapped = true;
                }
                currNode = currNode->next;
            }
            lastNode = currNode;
            if (!swapped) break;
        }
        display();
    }
}




//To display main menu
void dispMenu()
{
	system("CLS");
	cout << "UTM ATTENDANCE " << endl
	<< "\n\t1. Remove Name"
	<< "\n\t2. Search Attendance"
	<< "\n\t3. Display List of Attendance"
	<< "\n\t4. Display by Sorting Alphabetical Order"
	<< "\n\t5. Exit"
	<< "\n\t6. Back To Main Page"<<endl;
	
}
void dispMenuStudent()
{
	system("CLS");
	cout << "UTM ATTENDANCE " << endl
	<< "\n\t1. Insert Name / Attendance"
	<< "\n\t2. Return To Main Page" << endl;
}

int main()
{	
		
	time_t datetime = time(0);
	string dt = ctime(&datetime);
	stack attend;
	attend.createStack();	
	int choice, option1;
	
	do{
		  system("cls");
		  cout << "\n:::::::::::::::::::: UTM ATTENDANCE SYSTEM ::::::::::::::::::::\n";
		  cout << "Welcome to our Main Menu!\n\n";
		  cout << "Are you a staff or student?\n";
		  cout << "[1] Staff\n";
		  cout << "[2] Student\n";
		  cout << "[3] Exit\n";
		  
		  cin>>option1;
		  
		  if(option1 == 1){
		  	
		  	do
				{
					dispMenu();
					cout << "\nEnter your choice [1-6]: ";
					cin >> choice;
					cin.ignore();
					switch (choice)
					{
					case 1:
			            attend.pop();
			            break;
			        case 2:
			            attend.search();
			            break;
			        case 3:
			            attend.display();
			            break;
			        case 4:
			        	attend.sort();
			            break;
			        case 5:
			            exit(0);
			            break;
			        default:
			            cout<<"Invalid input, try again."<<endl;
			            break;	
					}
				}while ((choice>0)&&(choice<=5));
		  }
		  if(option1 == 2){
		  	
		  	do
				{
					dispMenuStudent();
					cout << "\nEnter your choice [1-2]: ";
					cin >> choice;
					cin.ignore();
					switch (choice)
					{
					 case 1:
			            attend.push();
			            break;
			        default:
			            cout<<"Invalid input, try again."<<endl;
			            break;	
					}
				}while ((choice>0)&&(choice<=1));
		  }
		  
	}while(option1 != 3);
  cout << "Thank you for choosing our system!\n";
	
	
	
	return 0;
}
