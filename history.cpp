#include "history.h"
#include <fstream>

using std::string;
using std::vector;

History::History(string username, vector<string> items, vector<int> quantity)
{
  //initializes values
  user = username;
  file_name = "History_" + username + ".txt";
  items_ids = items;
  quantities = quantity;

  //creates history file if not already created
  std::ifstream userFile(file_name);
  if(!userFile.good())
  {
    std::ofstream newUserFile(file_name);
    newUserFile.close();
  }
  //adds items and quantities to history file



}
