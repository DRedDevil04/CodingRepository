/*Devam Desai
IIT2022035 Assignment 6 TOC LAB*/


#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

vector<char> terminals;					
vector<char> nonTerminals;				

vector< pair<char, string> > rules;

queue <string> states;					
queue <string> paths;					

// used to convert the int to string.
namespace patch
{
	template < typename T > std::string to_string(const T& n)
	{
		std::ostringstream stm;
		stm << n;
		return stm.str();
	}
}


int BFS(string state, string path)
{
	
	if (state.length() == 1)
	{
		cout << "YES" << endl;
		cout << path[0];	
		for (int i = 1; i < path.length(); i++)
		{
			cout << ' ' << path[i];
		}
		cout << endl;
		return 1;
	}

	
	for (int i = 0; i < rules.size(); i++)
	{
		int location = state.find(rules[i].second);			

		if (location != string::npos) 
		{
			string tempString = state;
			tempString.replace(location, rules[i].second.length(), &rules[i].first);	
			states.push(tempString);													
			paths.push(path + patch::to_string(i + 1));		
		}
	}
	return 0;		
}

// Most effective way to clear all queue
void clearQueue(queue <string> &q)
{
	queue<string> empty;
	swap(q, empty);
}


// Main program
int main()
{
	freopen("grammar.txt", "r", stdin);			
	freopen("result.txt", "w", stdout);			
	char tempC;
	string line;
	getline(cin, line);		

	
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ')		
		{
			terminals.push_back(line[i]);
		}
	}

	getline(cin, line);		
	
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] != ' ')		 
		{
			nonTerminals.push_back(line[i]);
		}
	}


	getline(cin, line);		


	
	{
		pair <char, string> tempPair;		
		tempPair.first = line[2];			
		string second;
		for (int j = 7; j < line.size(); j++) 	
		{
			if (line[j] != ' ')
			{
				second.push_back(line[j]);		
			}
		}
		tempPair.second = second;			
		rules.push_back(tempPair);		
		getline(cin, line);
	}



	ifstream words;
	words.open("words.txt");	 	
	string tempPath = "";			

	
	while (words >> line)
	{
		states.push(line);		
		paths.push(tempPath);	
		int result = 0;			

		while (!states.empty())			
		{
			string currentState = states.front();	
			states.pop();							
			string currentPath = paths.front();		
			paths.pop();							

			if (BFS(currentState, currentPath) == 1)	
			{
				result = 1;
				break;		
			}
		}


		if (result == 0)		// If result is zero, this means that given word is not for this language.
		{
			cout << "NO" << endl;
		}
		clearQueue(states);	
		clearQueue(paths);			}
}