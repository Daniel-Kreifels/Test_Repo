#ifndef WORDCOUNT_H
#define WORDCOUNT_H

#include <iostream>
#include <string>

class WordCount {
private:
	std::string word;
	int count;
public:
	WordCount(std::string);
	std::string getWord();
	void addCount();
	int getCount();
	bool operator>(WordCount& compWord)const;
	bool operator<(WordCount& compWord)const;
	bool operator==(WordCount& compWord)const;
	bool operator!=(WordCount& compWord)const;
};
#endif  // WORDCOUNT_H
