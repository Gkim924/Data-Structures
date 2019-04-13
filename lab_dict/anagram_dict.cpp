/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */

	ifstream words(filename);
    vector<string> out;

    string line;
    if (words.is_open()) {
        while (getline(words, line)) {
        	out.push_back(line);
        }
    }

    _make(out);


}

void AnagramDict::_make(std::vector<string> input){

	for(string x : input){
		std::string temp = x;
		std::sort(temp.begin(),temp.end());

		if(!dict.count(temp)){
			std::vector<std::string> d;
			d.push_back(x); 
			dict[temp] = d;
		}
		else {
			dict[temp].push_back(x);
		}
	}

}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    _make(words);
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
	std::string temp = word;
	std::sort(temp.begin(),temp.end());

	if(!dict.count(temp)){
		return vector<string>();
	}

    return dict.at(temp);
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
	std::vector<std::vector<std::string>> v;

	if(dict.empty()){
		return vector<vector<string>>();
	}

	for(std::pair<std::string,std::vector<std::string>> entry : dict){
		if (entry.second.size() > 1) {

			v.push_back(entry.second);
		}
		
	}

    return v;
}
