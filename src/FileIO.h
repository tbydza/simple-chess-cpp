#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <fstream>

using namespace std;

/**
 * FileIO class.
 * This class takes care of reading from files and writing to files.
 * This is used to save game / load game mechanics
 */
class FileIO
{
public:
  /**
 * Load method opens savefile (textfile) and reads 2 lines containig game data.
 * @param saveName filename of the save file
 * @return 2 loaded lines as pair of strings
 */
  pair<string, string> Load(const string &saveName);
  /**
 * Save method opens savefile (textfile) and writes 2 lines containig game data.
 * @param saveName filename of the save file
 * @param gameInfo pair of strings with game data in textform
 */
  void Save(const string &saveName, const pair<string, string> &gameInfo);

private:
  ifstream is;
  ofstream os;
};

#endif