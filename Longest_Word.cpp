#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
//using std::string;
//const std::string FNAME = "/home/manikanta/Desktop/words";

int replaceWord(std::string topWrds[10], std::string word, int wordlen)
{	
	int minCount = /*INT_MAX*/topWrds[0].length(), indx = 0;
	for (int itt = 0; itt <= 9; itt++)
	{		
		if ((int)topWrds[itt].length() < (int)minCount)
		{
			minCount = topWrds[itt].length();
			indx = itt;			
		}
	}
	if (topWrds[indx].length() < word.length())
	{
		topWrds[indx] = word;
	}
	
	return 0;
}

int main()
{
	cout << "-----Program to display longest 10 words-----\n";

	ifstream file;
	file.open("/home/manikanta/Desktop/words");
	std::string word = "";
	
	std::string topWords[10] = {"", "", "", "" , "" , "" , "" , "" , "" , "" };
	int i = 0;

	while (file >> word)
	{
		if (i > 9)
		{						
			replaceWord(topWords, word, word.length());					
		}
		else
		{
			topWords[i] = word;
		}				
		i++;		
	}

	cout << "Top 10 words are as follows:"<<endl;
	//Final answer printing:
	for (int itt = 0; itt <= 9; itt++)
	{		
		cout << topWords[itt] <<endl;		
	}

	file.close();
	return 0;
}