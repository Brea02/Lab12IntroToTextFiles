#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

//function prototypes
void pressEnterToContinue();
bool readFromFile(string filename);
bool readFromCSVFile(string filename);


int main() {
	string datafile;
	cout << "Lab 12 Intro to Text Files!\n";
	cout << "Enter filename: ";
	getline(cin, datafile);
	bool status = readFromCSVFile(datafile);
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

bool readFromCSVFile(string filename) {
	ifstream inFile;			//input filestream for reading in out data
	istringstream thisLine;		//onr line (a record of info
	string movieInfo;			//film info
	string movieTitle;			//film title
	string year;				//year flim was released
	string director;			//film directors

	inFile.open(filename);		//attempt to open the specified text files
	if (inFile.fail()) {		//return error
		cout << "read error - sorry\n";
		return false;
	}

	//read in each record of info
	//format: title, year of release, director <, co-director>
	while (true) {
		getline(inFile, movieInfo);		//read in one record of info
		if (inFile.fail()) break;		//until no lines left
		thisLine.clear();				//treat record as input stream
		thisLine.str(movieInfo);
		getline(thisLine, movieTitle, ',');		//get first name of film
		getline(thisLine, year, ',');			//get year of release

		vector<string> directorList;			//vector to hold director names
		string dir;
		while (getline(thisLine, dir, ','))
			directorList.push_back(dir);

		director = directorList[0];			//always at least one director
		for (int i = 1; i < directorList.size(); i++) {
			director = director + " and " + directorList[i];
		}

		cout << movieTitle << " is a " << year << " film directed by " << director << endl;
	}

	//close the file and return
	inFile.close();
	return true;
}