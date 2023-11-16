#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//function prototypes
void pressEnterToContinue();
bool readFromFile(string filename);

int main() {
	string datafile;
	cout << "Lab 12 Intro to Text Files!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);
	bool status = readFromFile(datafile);
	if (status) cout << "Success!\n";
	else cout << "failure. :-( \n";
	pressEnterToContinue();

}


//functions

void pressEnterToContinue() {
	cout << "\nPress enter to continue... \n";
	cin.clear();
	while (cin.get() != '\n') continue;
}

bool readFromFile(string filename) {
	ifstream inFile;		//input filestream for reading in our data
	string movieTitle;		//film title
	int year;				//year film was released
	inFile.open(filename);	//attempt to open the specified text file

	if (inFile.fail()) {	//error when problem occurs
		cout << "read error - sorry\n";
		return false;
	}

	//if here then read in data until we're done
	while (true) {
		inFile >> movieTitle >> year;
		if (inFile.fail()) break; //when there no more data to read
		
		cout << movieTitle << ": " << year << endl;
	}
	//close the file and return
	inFile.close();
	return true;
}