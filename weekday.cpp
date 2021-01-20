//name: Lisa Wang
//UID: 105502901

#include<iostream>
#include<string>

using namespace std;

int main()
{
	//declaring and initializing any variables such as monthCode, centuryCode, yearCode, and dayCode which will be used
	string month;
	char firstLetter;
	int day = 0;
	int year = 0;
	int monthCode;
	int centuryCode;
	int yearCode;
	int dayCode;

	//prompt for user input
	cout << "Provide a month: " ;
	//ignores after user's space, space is also not permitted (will return invalid statement)
	getline(cin, month);
	//the first letter would be the string's first char
	firstLetter = month[0];
	// first conditional for checking, only will process if the first letter is uppercase and if month is one of the twelve indicated
	if (isupper(firstLetter) && (month == "January" || (month == "February") || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December"))
	{
		cout << "Provide a day: ";
		cin >> day;
		//line 33 can be an alternative, taking in consideration that space can be seen as a divider for user responses 
		//cin.ignore(256,'\n');                   
		//after being in the first condition, we now are checking for day's conditions
		if (day <= 31 && day >= 1)
		{
			cout << "Provide a year: " ;
			cin >> year;
			//after being in the second condition, we now are checking for year's conditions 
			if (year <= 3000 && year >= 1)
			{
				//assigning monthCode
				if (month == "April" || month == "July")
				{
					monthCode = 0;
				}
				if (month == "October" || month == "January") {
					monthCode = 1;
				}
				if (month == "May") {
					monthCode = 2;
				}
				if (month == "August")
				{
					monthCode = 3;
				}
				if (month == "February" || month == "March" || month == "November") { monthCode = 4; }
				if (month == "June") { monthCode = 5; }
				if (month == "September" || month == "December") { monthCode = 6; }


				//leap year offset 
				if (year % 4 == 0 && ((year % 100 != 0) || (year % 400 == 0)))
				{
					if (month == "January" || month == "February") {
						monthCode--;
					}
				}
				
				//century code 
				if ((year / 100) % 4 == 0) {
					centuryCode = -2;
				}
				if ((year / 100) % 4 == 1) {
					centuryCode = 3;
				}
				if ((year / 100) % 4 == 2) {
					centuryCode = 1; 
				}
				if ((year / 100) % 4 == 3) {
					centuryCode = -1;
				}

				//year Code 
				yearCode = (year % 100) / 4 + (year % 100);

				//Day Code 
				dayCode = (centuryCode + day + yearCode + monthCode) % 7;

				if (dayCode == 0) {
					cout << month << " " << day << ", " << year << " was a Sunday!" << endl;
				}
				if (dayCode == 1 || dayCode == -6) {
					cout << month << " " << day << ", " << year << " was a Monday!" << endl;
				}
				if (dayCode == 2 || dayCode == -5) {
					cout << month << " " << day << ", " << year << " was a Tuesday!" << endl;
				}
				if (dayCode == 3 || dayCode == -4) {
					cout << month << " " << day << ", " << year << " was a Wednesday!" << endl;
				}
				if (dayCode == 4 || dayCode == -3) {
					cout << month << " " << day << ", " << year << " was a Thursday!" << endl;
				}
				if (dayCode == 5 || dayCode == -2) {
					cout << month << " " << day << ", " << year << " was a Friday!" << endl;
				}
				if (dayCode == 6 || dayCode == -1) {
					cout << month << " " << day << ", " <<year << " was a Saturday!" << endl;
				}

			}
			else {
				cout << "Invalid year!" << endl;

			}
		}
		else {
			cout << "Invalid day!" << endl;
		}
	}
	else
	{
		cout << "Invalid month!"<< endl;
	}
	return 0;
}