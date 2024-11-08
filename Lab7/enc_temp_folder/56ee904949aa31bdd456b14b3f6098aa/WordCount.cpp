#include "WordCount.h"

WordCount::WordCount(std::string newWord) {
	word = newWord;
	count = 1;
}
std::string WordCount::getWord() {
	return word;
}
void WordCount::addCount() {
	count++;
}
int WordCount::getCount() {
	return count;
}
bool WordCount::operator>(WordCount& compWord)const {
	return word > compWord.word;
}
bool WordCount::operator<(WordCount& compWord)const {
	return word < compWord.word;
}
bool WordCount::operator==(WordCount& compWord)const {
	return word == compWord.word;
}
bool WordCount::operator!=(WordCount& compWord)const {
	return word != compWord.word;
}
/*constructor – This accepts the parameter for the word to initialize the object.The default value of count is 1.
b.string getWord() const – This returns the stored word.
d. void addCount() – This increases the count by 1.
e. int getCount() – This returns the count.
f.Overloads of the > , < , == and != operators that compare the word values of two WordCount objects and return a bool indicating the result.*/