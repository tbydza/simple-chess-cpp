#include "FileIO.h"

pair<string, string> FileIO::Load(const string &saveName)
{
    string line1, line2;
    is.open(saveName);
    if (is.is_open())
    {

        if (is.good())
        {
            getline(is, line1);
        }
        else
        {
            throw exception();
        }
        if (is.good())
        {
            getline(is, line2);
        }
        else
        {
            throw exception();
        }
        is.close();
    }
    else
    {
        throw exception();
    }

    return pair<string, string>(line1, line2);
}
void FileIO::Save(const string &saveName, const pair<string, string> &gameInfo)
{
    os.open(saveName);
    if (os.is_open())
    {

        if (os.good())
        {
            os << gameInfo.first << endl;
        }
        else
        {
            throw exception();
        }
        if (os.good())
        {
            os << gameInfo.second << endl;
        }
        else
        {
            throw exception();
        }
        os.close();
    }
    else
    {
        throw exception();
    }
}