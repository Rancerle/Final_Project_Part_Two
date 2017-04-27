//Created by Reilly Q. Curran and Amna Tariq
//Created on 4/24/2017
//last edited: 4/27/2017
//last compiled: 4/27/2017

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{
	//******************************************
	vector<string> context; 
	//holds the text and is indexed while printing
	map<string, vector<int> > lines; 
	//holds each unique instance of the word along with each context position it occures in
	ifstream inData;
	//loads the chosen file
	string word;
	//used to load the vector and map
	string keyword;
	//used to search the map
	int wordCount;
	//iterates for each instance of the keyword that is found
	int chooseText;
	//allows the user to pick the text file they want to load
	//******************************************

	//User chooses which text document to load in
	cout << "Would you like to scan 1) The Gutenberg Bible, or 2) A Sherlock Holmes Novel: ";
	cin >> chooseText;
	cout << endl;

	//error checks if the user made an invalid selection
	while (chooseText > 2 || chooseText < 1)
	{
		if (chooseText > 2 || chooseText < 1)
		{
			cout << "I'm sorry, but you entered an invalid selection." << endl;
			cout << endl;
			cout << "Would you like to scan 1) The Gutenberg Bible, or 2) A Sherlock Holmes Novel: ";
			cin >> chooseText;
			cout << endl;
		}
	}

	cout << endl;

	//opens the selected file
	switch (chooseText)
	{
	case 1:
		inData.open("pg10.txt");
		cout << "Loading the Gutenberg Bible." << endl;
		cout << endl;
		break;

	case 2:
		inData.open("big.txt");
		cout << "Loading Sherlock Holmes." << endl;
		cout << endl;
		break;
	}	

	//loads the vector with the words of the file
	inData >> word;

	while (inData)
	{	
		context.push_back(word);
		//i++;
		inData >> word;
	}

	cout << endl;

	inData.close();

	//notifies the user that the text document has completely been loaded in
	cout << "Vector Loaded, Establishing Map..." << endl;
	cout << endl;

	//loads the map with each unique word and a vector containing the index positions they apear in in the vector
	for (int i = 0; i < context.size(); i++)
	{
		word = context[i];
		if (lines.find(word) == lines.end())
		{
			vector<int> Locations;
			Locations.push_back(i);
			lines[word] = Locations;
		}
		else
		{
			lines[word].push_back(i);
		}
	}

	//lets the user know that the map is finished loading
	cout << "Map Established." << endl;
	cout << endl;

	//loops while the user has not chosen to input Q
	while (keyword != "Q")
	{
		wordCount = 0; // reinitializes after each search
		cout << "Enter a KeyWord (Q to quit): "; // asks for the user's input
		cin >> keyword;
		cout << endl;
		if (keyword != "Q") //runs when the user didn't enter Q
		{
			if (lines.find(keyword) != lines.end()) //if the word exists in the map
			{
				for (int j = 0; j < lines[keyword].size(); j++) // runs through each instance of the word
				{
					int k = lines[keyword][j]; // establishes K with the context index position
					cout << context[k - 2] << " "
						<< context[k - 1] << " "
						<< context[k] << " "
						<< context[k + 1] << " "
						<< context[k + 2] << endl; 
					// prints out the keyword along with the words immediately before and after the keyword instance
					wordCount++; 
				}
			}
			//notifies the user how many times the word they chose appears in their chosen text file
			cout << endl;
			cout << "The word " << keyword << " was found " << wordCount << " times." << endl;
		}	
		cout << endl;
	}
	//bids the user farewell
	cout << "Thank you, have a nice day!" << endl;

	return 0;
}