#include <iostream>
#include <string>
#include <string.h> 
#include <cctype>
#include <assert.h>
using namespace std;

//FINALIZED

bool isCharValidMap(char c, char* map) {
	int count = 0;
	for(int i = 0; i < 26; i++) {
		if (map[i] == c) {
			count++;
		}
	}

	return count <= 1;
}

// returns true if cipher text starting at pos
// matches every word length in crib
// i.e. "duck this poop", 5, "asdf bjjb" -> true;
bool match(const char ciphertext[], int pos, const char crib[], char* map) {
	//crib cannot have zero elements
	if (strlen(crib) <= 0){
		return false; 
	}
	// // check if cipher even contains strlen(crib) number of characters starting at cipherStart
	// if(strlen(ciphertext) < (cipherStart + strlen(crib))) {
	// 	return false;
	// }

	//set up cipher map to place matching crib chars 
	for (int i = 0; i < 26; i++){
		map[i] = '1';	
	}

	int cribPos = 0;
	int cipherPos = pos;

	bool isCipherDone = false;

	// continuously
	for (;;){

		// seek cipherPos to alphabetical character
		while(!isalpha(ciphertext[cipherPos])) {

			// ran out of line/string
			if(ciphertext[cipherPos] == '\n' || ciphertext[cipherPos] == '\0' ) {
				break;
			}

			cipherPos++;
		}

		// seek cribPos to alphabetical character
		while(!isalpha(crib[cribPos])) {

			if(crib[cribPos] == '\0') {
				break;
			}
			cribPos++;
		}

		// if crib is done so we must've batched
		if (crib[cribPos] == '\0') {
			return true;
		}
		// we run out of ciphertext in line and we are not done with crib
		else if((ciphertext[cipherPos] == '\n' || ciphertext[cipherPos] == '\0')){
			return false; 
		}

		// while both are alphabetical things are good
		while(isalpha(crib[cribPos]) && isalpha(ciphertext[cipherPos])) {

			char cribChar = tolower(crib[cribPos]);
			char cipherChar = tolower(ciphertext[cipherPos]);

			// if crib char is not valid because it has already been mapped
			if (!isCharValidMap(cribChar, map)) {
				return false;
			}

			//get positions in map 
			int charPos = cipherChar - 'a';

			// if mapping is empty for crib's char
			if(map[charPos] == '1') {
	            map[charPos] = cribChar;
			}
			// not empty && we have disagreement
			else if(map[charPos] != cribChar){
				return false; 
			}


			cribPos++;
			cipherPos++;
		}

		// if they are not both agreeing at this point return false
		if(isalpha(crib[cribPos]) != isalpha(ciphertext[cipherPos])) {
			return false;
		}
	}
	return true;
}


bool decrypt(const char ciphertext[], const char crib[]) {
	char map[26];
	bool foundMap = false;
	bool hasWord = false;

	for(int i = 0; crib[i] != '\0'; i++) {
		if(isalpha(crib[i])) {
			hasWord = true;
		}
	}

	if (!hasWord) {
		return false;
	}
	
	//for every word
	for(int wordBegin = 0; ciphertext[wordBegin] != '\0';) {

		// check if ciphertext and crib possibly match on length 
		// starting on current word
		if(match(ciphertext, wordBegin, crib, map)) {
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
	char ciph1[] = "bubble";
	char crib1[] = "caceto";
	char crib2[] = "puppie";
	char mapping[26]; 
	
	char c[] = "zu drvtry";
	char b[] = "my secret";


	char ciphertext[] = "Zqysrsuu jysqjtsgj bw zrquucwcsx cgwbytqjcbg cu xqgesybmu.\nNrsqus ysrsqus qgo xbzmtsgju obm qzhmcys jb Icfcrsqfu.\nXbg'j ysrsqus qgojdcge stvqyyquucge jb mu; is stvqyyquu bmyusrksu hmcjs isrr.\nzu 31 cu zdqrrsgecge!\0";
	char crib[] = "classified information\0";

	assert(decrypt("Hirdd ejsy zu drvtry od.\nO'z fodvtrry.\n", "my secret"));

	//match tests 
	char crib3[] = "asdf bjjb"; 
	char cipher1[] = "duck this poop";
	assert(match(cipher1, 5, crib3, mapping)==1);
	//length isn't a match 
	assert(match(cipher1, 1, crib3, mapping)==0);  


	//decrypt testcases 
	//standard decyphering
	char DblankCrib[] = " ";
	char DblankCrib2[0];
	char Dcrib2[] = "alsdkjflalaskdfjalkdf sdjg;alkdjg;alksdjf;alkdjsf"; 
	char Dcipher2[] = "the cat in boxx";
	char Dcrib3[] = "AAA"; //case of crib shouldn't matter
	char Dcrib4[] = "suz";  
	char the[] = "the";
	char Dcipher1[] = "Zqysrsuu jysqjtsgj bw zrquucwcsx cgwbytqjcbg cu xqgesybmu.\nNrsqus ysrsqus qgo xbzmtsgju obm qzhmcys jb Icfcrsqfu.\nXbg'j ysrsqus qgojdcge stvqyyquucge jb mu; is stvqyyquu bmyusrksu hmcjs isrr.\nzu 31 cu zdqrrsgecge!"; 
	char Dcrib1[] = "classified information"; 
	// assert(decrypt(Dcipher1, Dcrib1)); 
	// cout << "Above should read:\n CARELESS TREATMENT OF CLASSIFIED INFORMATION IS DANeEROmS.\nnLEASE RELEASE ANo DOCmMENTS oOm AChmIRE TO iIfILEAfS.\nDON'T RELEASE ANoTdINe EMvARRASSINe TO mS; iE EMvARRASS OmRSELkES hmITE iELL.\nCS 31 IS CdALLENeINe!" << endl;

	// //TODO: ADDRESS THIS
	//crib string has no words, must return false & print nothing 
	assert(decrypt(Dcipher1, DblankCrib)==0);
	assert(decrypt(Dcipher2, DblankCrib) == 0); //empty string 
	assert(decrypt(Dcipher2, DblankCrib2) == 0);//no elements 
	assert(decrypt(Dcipher2, "123213123123")==0);//no words
	//no match for crib possibly 
	assert(decrypt(Dcipher1, Dcrib2) == 0); //no match in length 
	assert(decrypt(Dcipher2, Dcrib3) == 0); //no match in letter ratio
	//two matches for crib; choose either 
	cerr << "the two matches crib result was:" << endl;
	cerr << decrypt(Dcipher2, Dcrib4) << endl;
	// assert(decrypt(Dcipher2, Dcrib4) == 1);

	char Dcipher3[] ="bwra wmwt\nqeirtk spst\n"; 
	char Dcrib5[] = "alan turing";
	cerr << "the match doesn't span multiple messages test" << endl;
	assert(decrypt(Dcipher3, Dcrib5) == 0);
	//only part of the crib matches, 
	char Dcrib6[] = "he oout";
	assert(decrypt(Dcipher2, Dcrib6) == 0); 

	//should return matches, and all should be printed the same way
	char Mcrib[] = "hush-hush until January 20, 2017";
	char Mcrib2[] = "   hush???hUSh---     --- until    JanuARY !!  ";
	char Mcrib3[] = "hush hush until january";
	char Mcipher[] = "DiebjiggK, zyxZYXzyx--Abca abCa    bdefg## $$hidbijk6437 wvuWVUwvu\n\n8 9\n";
	cerr << "The next 3 decrypted messages should be print:"<< endl;
	cerr << "NATURALLY, zyxzyxzyx--HUSH HUSH    UNTIL## $$JANUARY6437 wvuwvuwvu\n\n8 9\n" << endl;
	char map[26];

	assert(match(Mcipher, 22, Mcrib, map));
	assert(decrypt(Mcipher, Mcrib)); //these should all print the same thing
	assert(decrypt(Mcipher, Mcrib2));
	assert(decrypt(Mcipher, Mcrib3));
}
