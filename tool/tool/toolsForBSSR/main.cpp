#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>
using namespace std;

void maptest()
{
    map<string, string> *m = new map<string, string>();
    m->insert(pair<string, string>("liuzhuang", "12 3 423 4234 234"));
    m->insert(pair<string, string>("shen", "12 3 423 4234 234"));
    
    cout << (*m)["liuzhuang"] << endl;
    
    delete m;
    //m->insert("SDFSD", "SDFSD");
}

void inFileStreamTest()
{    
    const string filepath = "test";
    ifstream file;
    file.open(filepath.c_str());
    string line;
    if(file.is_open())
    {
        while(getline(file, line))
        {
            cout << line << '\n';
        }
    }
    file.close();
}
void ofilestreamTest()
{
    const string filepath = "test";
    ofstream file;
    file.open(filepath.c_str());
    if(!file.is_open())
    {
        cout << "cannot open file"+filepath << endl;
        return;
    }
    file << "one line\n";
    file << "another line\n";
    file.close();
}

void stringTest()
{
    string vector = "23123 12312 3123 4234 1231 123";
    //vector.s
}

vector<string> *splitTest(string line)
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

vector<string> *splitTest(string line, char delim)
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
map<string, string> *generateVectirDict(string vectorDictPath);
void generate(string wordlist, map<string, string> &vectors, unsigned int dimension, string dictPath, string serializationPath);

map<string, bool> *loadSentiList(string dictPath);
void replace(vector<string> &tokens, string targetStr, string replacer);

int main(int argc, char **argv)
{
    
    vector<string> tokens;
    tokens.push_back("SDFSDF");
    tokens.push_back("  ");
    tokens.push_back("  ");
    tokens.push_back("SDFS");
    replace(tokens, "  ", " ");
    
    string dictPath = "/home/laboratory/corpus/en/SentiWordList_en.txt";
    map<string, bool> * dict = loadSentiList(dictPath);
    cout << (*dict)["abandon"] << endl;
    delete dict;
//  vector<string> strs();
//  string vectorsDict = "../cn_vectors_50.txt";
//  string wordslist = "../test_book_new.txt.extract";
//    
//
//  string dictPath = "../test_book_new.txt.extract_50.lstmDict";
//  string serializationPath = "../test_book_new.txt.extract_50.serialization";
//
//  map<string, string> *dict = generateVectirDict(vectorsDict);
//  generate(wordslist, *dict, 50, dictPath, serializationPath);
    //maptest();
    //ofilestreamTest();
    //inFileStreamTest();
//  vector<string> *strs = NULL;
//  strs = splitTest("SDF er gda we hyr ", ' ');
//  for(unsigned int i = 0; i < strs->size(); i++)
//  {
//      cout << (*strs)[i] << endl;
//  }
//  cout << "(((((((((((((((((((((((((" << endl;
//  delete strs;
//    
//  string str= "sdfsf";
//  cout << str + str << endl;
	return 0;
}
