#include <iostream>
#include <string>
#include <fstream>
#include <map>


using namespace std;


//will be used to track the items
class trackItem {
private:

	//using map to store the frequency of each item
	map <string, int> itemFreq;
	string dataFilePath;

public:
	trackItem() {
		dataFilePath = "frequency.dat";
	}

	//function will process input
	void inputProcessFile(const string& filePath) {
		ifstream inputFile(filePath);
		string item;

		//if file is open iterate		
		if (inputFile.is_open()) {
			while (getline(inputFile, item)) {
				itemFreq[item]++;
			}

			//close the file
			inputFile.close();
		}
		else {
			cout << "Error: Cannot open file!" << filePath << endl;
		}

	}

	//function will be used to save data
	void saveDataFile() {
		ofstream outputFile(dataFilePath);

		//loop to save items
		if (outputFile.is_open()) {
			for (const auto& pair : itemFreq) {
				outputFile << pair.first << " " << pair.second << endl;
			}
			//close the file
			outputFile.close();
			cout << "Data saved to " << dataFilePath << endl;
		}
		else {
			cout << "Error: unable to create output file" << dataFilePath << endl;
		}
	}

	// function for display
	void runMenu() {
		int choice;
		string userIn;

		//while option is not 4, run the menu
		do {
			cout << "Menu Options:" << endl;
			cout << "1. Run item frequency" << endl;
			cout << "2. Print item frequency" << endl;
			cout << "3. print item frequency histogram" << endl;
			cout << "4. Exit" << endl;
			cin >> choice;

			//switch case for deciding what to do with option
			switch (choice) {
			case 1:
				cout << "Enter the item you would like to look up: ";
				cin.ignore();
				getline(cin, userIn);
				cout << "Frequency of " << userIn << ": " << itemFreq[userIn] << endl;
				break;

			case 2:
				printItemFreq();
				break;

			case 3:
				printHist();
				break;

			case 4:
				saveDataFile();
				break;

			default:
				cout << "Please enter a valid choice." << endl;
				break;

			}
		} while (choice != 4);
	}

	//function to print item frequency
	void printItemFreq() {
		for (const auto& pair : itemFreq) {
			cout << pair.first << " " << pair.second << endl;
		}
	}

	//function to print histogram showing item frequency
	void printHist() {
		for (const auto& pair : itemFreq) {
			cout << pair.first << " ";
			
			//loop to create graph
			for (int i = 0; i < pair.second; i++) {
				cout << "*";
			}
			cout << endl;
			
		}
	}
};

//main loop for program
int main() {
	string inputFile = "CS210_Project_Three_Input_File.txt";
	trackItem tracker;
	tracker.inputProcessFile(inputFile);
	tracker.runMenu();

	return 0;
}