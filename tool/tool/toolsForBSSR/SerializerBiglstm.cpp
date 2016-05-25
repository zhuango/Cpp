#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;


vector<string> *split(string line, char delim)
{
    istringstream toLine(line);
    vector<string> *tokens = new vector<string>();
    string item;
    while(getline(toLine, item, delim))
    {
        tokens->push_back(item);
    }
    return tokens;
}

void replace(vector<string> &tokens, string targetStr, string replacer)
{
    for(unsigned int i = 0; i < tokens.size(); ++i)
    {
        if(tokens[i] == targetStr)
        {
            tokens[i] = replacer;
        }
    }
}

map<string, bool> *loadSentiList(string dictPath)
{
    ifstream f;
    map<string, bool> *wordlist = new map<string, bool>();
    
    f.open(dictPath.c_str());
    if(f.is_open())
    {
        string word;
        while(getline(f, word))
        {
            wordlist->insert(pair<string, bool>(word, true));
        }
    }
    f.close();
    return wordlist;
}

map<string, string> * mapSentEmbedding(string sentIndexPath, string sentEmbedPath)
{
    map<string, string> *sentMap = new map<string, string>();
    ifstream indexreader;
    indexreader.open(sentIndexPath.c_str());
    ifstream embedreader;
    embedreader.open(sentEmbedPath.c_str());
    string indexLine= "";
    string embedLine = "";
    while(getline(indexreader,indexLine) && getline(embedreader, embedLine))
    {
        //embedLine = 
    }
    
    return sentMap;
}