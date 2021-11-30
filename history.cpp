#include "history.h"
#include <fstream>
#include <iostream>

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

History::History(string username, vector<string> items, vector<int> quantity)
{
  //initializes values
  user = username;
  file_name = "History_" + username + ".txt";
  items_ids = items;
  quantities = quantity;

  //creates history file if not already created
  ifstream userFile(file_name);
  if(!userFile.good())
  {
    cout << "Creating New User History File" << endl;
    ofstream newUserFile(file_name);
    newUserFile.close();
  }

  //adds items and quantities to history file
  ofstream UserFile;
  UserFile.open(file_name, std::ios_base::app);
  for(int i = 0; i < items_ids.size(); i++)
  {
    UserFile << items_ids[i] << " " << quantities[i] << "\n";
  }
}

History::History(string username)
{
  user = username;
  file_name = "History_" + username + ".txt";
}

void History::Display()
{
  string line;
  ifstream HistoryFile(file_name);
  if (HistoryFile.is_open())
  {
    while(getline(HistoryFile, line))
    {
      cout << line << endl;
    }
  }
  else
  {
    cout << "User has no history" << endl;
  }
}

void History::DeleteHistory()
{
  const char * c = file_name.c_str();
  cout << "Deleting History (" << c << ")" << endl;
  remove(c);
}
