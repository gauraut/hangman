#include <iostream>
#include <string> //using string functions
#include<fstream> //for input from file
#include<cstring> //memset
#include<vector> //for dynamic array
#include<time.h> //for random number

using namespace std;

int main()
{
	cout<<"Welcome to hangmonkey"<<endl;

	string line;
	vector<string> lines; //behaves like a dynamic array

	srand(time(0)); //initializing time

	ifstream file("words.txt"); //word file

	int total_lines=0;
	while(getline(file,line)) //getline(file,line) scans the file and reads a line. This loop will run until 'file' reaches last lines
	{
	    total_lines++;
	    lines.push_back(line); //pushes new input into vector array
	}

	int random_number=rand()%total_lines; //selects a random number within total_lines
	string secretword=lines[random_number]; //secretword is selected based on random number generated and corresponding element vector array
	unsigned int a= secretword.length();

	cout<<"Number of characters in secret word are "<<a<<endl;

	int count=0;
	char guesses[secretword.length()+12];
	guesses[secretword.length()+12]='\0';
	char guess;
	bool found;
	int i=0;
	unsigned int d;

	char dash[a];
	dash[a]='\0';
	memset(dash,'_',a);

	while (i<8)
	{
		cout<<"You have "<<7-i<<" guesses left.\n";
		for (d=0; d<a; ++d)
			{
				cout<<dash[d]<<" ";
				//cout<<secretword[d]<<" ";
			}
		cout<<"\nEnter your guess: ";
		cin>>guess;
		guesses[count]=guess;
		count++;
		cout<<"\nGuesses: ";
		for (int j=0;j<count;j++)
		{
			cout<<guesses[j]<<", ";
		}
		found = false;
		for (unsigned int t=0;t<a;t++)
		{
			if(guess==secretword[t])
			{
				cout<<"\nCORRECT Guess\n";
				dash[t]=guess;
				found=true;
			}
			else if(t==a-1 &&found==false)
			{
				cout<<"\nWRONG guess\n";
				++i;
				if (i>=7)
				{
					cout<<secretword<<" is the correct answer"<<"\nYou lost. Try again.";
					return 0;
				}
			}
		}
		if (dash==secretword)
		{
			cout<<secretword<<"\nCongratulations! You Won.";
			return 0;
		}
	}
	return 0;
}

