#include <iostream>
#include <string>
#include <string.h> 
#include <cctype>
#include <assert.h>
using namespace std;

void printCribMap(char* cribMap) {
	for(int i = 0; i < 26; i++) {
		cout << "Cribmap[" << i << "] : " << cribMap[i] << endl;
	}
}

void printString(const char* str, int start, int n) {
	for(int i = 0; i < n; i++) {
		cout << str[i + start];
	}
}

bool isCharValidMap(char c, char* map) {
	int count = 0;
	for(int i = 0; i < 26; i++) {
		if (map[i] == c) {
			count++;
		}
	}

	return count <= 1;
}

//ciphermap: matching crib chars onto cipher
//cribmap: matching cipher chars onto crib
bool findMapping(const char cipher[], int cipherStart, const char crib[], char* map) {
	// check if cipher even contains strlen(crib) number of characters starting at cipherStart
	if(strlen(cipher) < (cipherStart + strlen(crib))) {
		cout << "length diff" << endl;
		return false;
	}

	//set up cipher map to place matching crib chars 
	for (int i = 0; i < 26; i++){
		map[i] = '1';	
	}

	//iterate through the crib and the ciphertext 
	for (int idx = 0; idx < strlen(crib);idx++){

		//if its not alphabetical, skip it
		if (!isalpha(crib[idx])) {
			continue;
		}

		// if crib char is not valid because it has already been mapped
		if (!isCharValidMap(crib[idx], map)) {
			cout << "invalid map" << endl;
			return false;
		}

		//get positions in map 
		int charPos = tolower(cipher[cipherStart + idx]) - 'a';

		// if mapping is empty for crib's char
		if(map[charPos] == '1') {
            map[charPos] = crib[idx];
		}
		// not empty && we have disagreement
		else if(map[charPos] != crib[idx]){
			cout << map[charPos] << crib[idx] << endl;
			printCribMap(map);
			return false; 
		}
	}
	return true;
}

// returns true if cipher text starting at pos
// matches every word length in crib
// i.e. "fuck this poop", 5, "asdf bjjb" -> true;
bool lengthMatch(const char ciphertext[], int pos, const char crib[]) {


	//crib cannot have zero elements
	if (strlen(crib) <= 0){
		return false; 
	}

	// for every character in the crib
	for (int i = 0; i < strlen(crib); i++){

		// if we ever get to a newline in the cipher trying to match crib to it
		if(ciphertext[i] == '\n'){
			return false; 
		}

		// not both the same alphabetical or not alphabetical
		if (isalpha(crib[i]) && isalpha(ciphertext[pos + i])){
			return false;
		}
	}
	return true;
}


bool decrypt(const char ciphertext[], const char crib[]) {
	char map[26];
	bool foundMap = false;

	//for every word
	for(int wordBegin = 0; ciphertext[wordBegin] != '\0';) {

		// check if ciphertext and crib possibly match on length 
		// starting on current word
		if(lengthMatch(ciphertext, wordBegin, crib) && findMapping(ciphertext, wordBegin, crib, map)) {
			foundMap = true;
			break;
		} 

		// seek to next word:
		// advance wordBegin while we finish off word
		while(isalpha(ciphertext[wordBegin])) {
			wordBegin++;
		}

		while(!isalpha(ciphertext[wordBegin]) && ciphertext[wordBegin] != '\0') {
			wordBegin++;
		}
	}

	// if we weren't able to find a map
	if (!foundMap) {
		return false;
	}

	// we were able to find a map at this point
	// begin decrypting using mapping
	for(int i = 0;ciphertext[i] != '\0'; i++) {

		// is alpha and we have a mapping for it
		if(isalpha(ciphertext[i]) && map[tolower(ciphertext[i]) - 'a'] != '1') {
			cout << (char) toupper(map[tolower(ciphertext[i]) - 'a']);
		
		// is alpha and we do not have mapping
		} else if (isalpha(ciphertext[i])){
			cout << (char) tolower(ciphertext[i]);
		// is not alphabetical, just print it
		} else {
			cout << ciphertext[i];
		}
	}

	return true;
}

int main()
{
	// char ciph1[] = "bubble";
	// char crib1[] = "caceto";
	// char crib2[] = "puppie";
	// char mapping[26]; 
	// assert(findMapping(ciph1, 0, crib1, mapping)==0);//return false, wrong letter ratio
	// assert(findMapping(ciph1, 0, crib2, mapping)==1); //correct, letter ratio 
	// char c[] = "zu drvtry";
	// char b[] = "my secret";
	// assert(findMapping(c, 0, b, mapping)==1); //true example with spaces 

	// char ciphertext[] = "Zqysrsuu jysqjtsgj bw zrquucwcsx cgwbytqjcbg cu xqgesybmu.\nNrsqus ysrsqus qgo xbzmtsgju obm qzhmcys jb Icfcrsqfu.\nXbg'j ysrsqus qgojdcge stvqyyquucge jb mu; is stvqyyquu bmyusrksu hmcjs isrr.\nzu 31 cu zdqrrsgecge!\0";
	// char crib[] = "classified information\0";

	// assert(decrypt("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "my secret"));

	// //lengthMatch tests 
	// char crib3[] = "asdf bjjb"; 
	// char cipher1[] = "duck this poop";
	// assert(lengthMatch(cipher1, 5, crib3)==1);
	// //length isn't a match 
	// assert(lengthMatch(cipher1, 1, crib3)==0);  


	// //decrypt testcases 
	// //standard decyphering
	// char DblankCrib[] = " ";
	// char DblankCrib2[0];
	// char Dcrib2[] = "alsdkjflalaskdfjalkdf sdjg;alkdjg;alksdjf;alkdjsf"; 
	// char Dcipher2[] = "the cat in boxx";
	// char Dcrib3[] = "AAA"; //case of crib shouldn't matter
	// char Dcrib4[] = "suz";  
	// char the[] = "the";
	// assert(!findMapping(Dcrib3, 0, Dcrib4,mapping));

	// char Dcipher1[] = "Zqysrsuu jysqjtsgj bw zrquucwcsx cgwbytqjcbg cu xqgesybmu.\nNrsqus ysrsqus qgo xbzmtsgju obm qzhmcys jb Icfcrsqfu.\nXbg'j ysrsqus qgojdcge stvqyyquucge jb mu; is stvqyyquu bmyusrksu hmcjs isrr.\nzu 31 cu zdqrrsgecge!"; 
	// char Dcrib1[] = "classified information"; 
	// // assert(decrypt(Dcipher1, Dcrib1)); 
	// // cout << "Above should read:\n CARELESS TREATMENT OF CLASSIFIED INFORMATION IS DANeEROmS.\nnLEASE RELEASE ANo DOCmMENTS oOm AChmIRE TO iIfILEAfS.\nDON'T RELEASE ANoTdINe EMvARRASSINe TO mS; iE EMvARRASS OmRSELkES hmITE iELL.\nCS 31 IS CdALLENeINe!" << endl;

	// // //TODO: ADDRESS THIS
	// // //crib string has no words, must return false & print nothing 
	// // cout<< "empty stringcrib prints:" << decrypt(Dcipher1, DblankCrib)<< endl;
	// // assert(decrypt(Dcipher2, DblankCrib) == 0); //empty string 
	// // assert(decrypt(Dcipher2, DblankCrib2) == 0);//no elements 
	// // //no match for crib possibly 
	// // assert(decrypt(Dcipher1, Dcrib2) == 0); //no match in length 
	// assert(decrypt(Dcipher2, Dcrib3) == 0); //no match in letter ratio
	// //two matches for crib; choose either 
	// //TODO: when there's two matches, a word is being deleted 
	// cout << "the two matches crib result was:" << endl;
	// decrypt(Dcipher2, Dcrib4);
	// assert(decrypt(Dcipher2, Dcrib4) == 1);

	// //TODO: FIX THIS 
	// //match for crib doesn't span multiple messages (separations by newlines)
	// char Dcipher3[] ="bwra wmwt\nqeirtk spst\n"; 
	// char Dcrib5[] = "alan turing";
	// cout << "the match doesn't span multiple messages test" << endl;
	// assert(decrypt(Dcipher3, Dcrib5) == 0);
	// //only part of the crib matches, 
	// char Dcrib6[] = "he oout";
	// assert(decrypt(Dcipher2, Dcrib6) == 0); 

	//should return matches, and all should be printed the same way
	char Mcrib[] = "hush-hush until January 20, 2017";
	char Mcrib2[] = "   hush???hUSh---     --- until    JanuARY !!  ";
	char Mcrib3[] = "hush hush until january";
	char Mcipher[] = "DiebjiggK, zyxZYXzyx--Abca abCa    bdefg## $$hidbijk6437 wvuWVUwvu\n\n8 9\n";
	cout << "The next 3 decrypted messages should be print:"<< endl;
	cout << "NATURALLY, zyxzyxzyx--HUSH HUSH    UNTIL## $$JANUARY6437 wvuwvuwvu\n\n8 9\n" << endl;
	char map[26];

	assert(findMapping(Mcipher, 22, Mcrib, map));

	cout << map << endl;
	assert(decrypt(Mcipher, Mcrib)); //these should all print the same thing
	assert(decrypt(Mcipher, Mcrib2));
	assert(decrypt(Mcipher, Mcrib3));


}
