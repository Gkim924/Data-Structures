/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of (string, string, string) tuples
 * Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<std::tuple<std::string, std::string, std::string>> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    vector<std::tuple<std::string, std::string, std::string>> ret;

    /* Your code goes here! */

    ifstream wordsFile(word_list_fname);
	string word;

	if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
    	while (getline(wordsFile, word)) {
        	//words need to be longer than 3 letters
        	string sbsr1 = word;
        	string sbsr2 = word;

        	sbsr1.erase(sbsr1.begin());
        	sbsr2.erase(sbsr2.begin()+1);

        	if(d.homophones(word,sbsr1) && d.homophones(word, sbsr2)){
        		ret.push_back(tuple<string,string,string>(word, sbsr1, sbsr2));
        	}
    	}
	}

    return ret;
}
