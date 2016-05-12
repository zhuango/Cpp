#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;


vector<string> *split(string line)
{
    istringstream toLine(line);
    vector<string> *tokens = new vector<string>(istream_iterator<string>{toLine}, istream_iterator<string>{});
//    copy(
//        istream_iterator<string>(toLine),
//        istream_iterator<string(),
//        back_inserter(tokens)
//    )
    return tokens;
}

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

map<string, string> *generateVectirDict(string vectorDictPath)
{
    map<string, string> *vectors = new map<string, string>();
    
    int linenumber = 0;
    
    ifstream vectorFile;
    vectorFile.open(vectorDictPath.c_str());
    if(vectorFile.is_open())
    {
        string line = "";
        while(getline(vectorFile, line))
        {
            linenumber++;
            if(linenumber % 1000 == 0)
            {
                cout << "generate vector dict: " << linenumber << endl;
            }
            vector<string> *vals = split(line, ' ');
            string vectorStr = "";
            for(unsigned int i = 1; i < (*vals).size(); i++)
            {
                vectorStr += (*vals)[i] + " ";
            }
            vectors->insert(pair<string, string>((*vals)[0], vectorStr));
        }
            
    }
    
    return vectors;
}

vector<double> RandInOne(unsigned int size)
{
    vector<double> data;
    for(unsigned int i = 0; i < size; i++)
    {
        double a = rand() % 10000 / 10000.0 - 0.5;
        data.push_back(a);
    }
    return data;
}

template<class T>
string str(T number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}

void generate(string wordlist, map<string, string> &vectors, unsigned int dimension, string dictPath, string serializationPath)
{
    map<string, int> dictTable;
    int dictIndex = 0;
    ofstream dictFile(dictPath.c_str());
    ofstream serializationFile(serializationPath.c_str());
    ifstream wordslistFile(wordlist.c_str());

    /////////////////////////
    int linenumber = 0;
    int notFoundCount = 0;
    /////////////////////////
    
    string line;
    while(getline(wordslistFile, line))
    {
        string serialicationNumbersStr = "";
        linenumber += 1;
        if(linenumber % 1000 == 0)
        {
            cout << serializationPath + " generate serialization: " << linenumber << endl;
        }
        vector<string> *words = split(line, ' ');
        string wordVector = "";
        for(unsigned int i = 0; i < words->size(); i++)
        {
            string word = (*words)[i];
            if(dictTable.find(word) == dictTable.end())
            {
                if(vectors.find(word) != vectors.end())
                {
                    wordVector = vectors[word];
                }
                else
                {
                    notFoundCount += 1;
                    vector<double> data = RandInOne(dimension);
                    for(vector<double>::iterator iter = data.begin(); iter != data.end(); iter++)
                    {
                        wordVector += str(*iter) + " ";
                    }
                }
                dictIndex += 1;
                dictTable.insert(pair<string, int>(word, dictIndex));
                dictFile << wordVector << "\n";
            }
            serialicationNumbersStr += str(dictTable[word]) + " ";
        }
        serializationFile << serialicationNumbersStr << "\n";
    }
    cout << serializationPath << " Done, there are " << notFoundCount << " words which are not found.";
    dictFile.close();
    serializationFile.close();
}