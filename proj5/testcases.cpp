//test cases


//decrypt testcases 
//standard decyphering 
char Dcipher1[] = "Zqysrsuu jysqjtsgj bw zrquucwcsx cgwbytqjcbg cu xqgesybmu.
	Nrsqus ysrsqus qgo xbzmtsgju obm qzhmcys jb Icfcrsqfu.
	Xbg'j ysrsqus qgojdcge stvqyyquucge jb mu; is stvqyyquu bmyusrksu hmcjs isrr.
	zu 31 cu zdqrrsgecge!"; 
char Dcrib1[] = "classified information"; 
assert(decrypt(Dcipher1, Dcrib1)); 
cout << "Above should read:\n CARELESS TREATMENT OF CLASSIFIED INFORMATION IS DANeEROmS.
	nLEASE RELEASE ANo DOCmMENTS oOm AChmIRE TO iIfILEAfS.
	DON'T RELEASE ANoTdINe EMvARRASSINe TO mS; iE EMvARRASS OmRSELkES hmITE iELL.
	CS 31 IS CdALLENeINe!" << endl;


//crib string has no words, must return false & print nothing 
char DblankCrib[] = " ";
char DblankCrib2[] = ' '; 
char Dcrib2[] = "alsdkjflalaskdfjalkdf sdjg;alkdjg;alksdjf;alkdjsf"; 
char Dcipher2[] = "the cat in boxx";
char Dcrib3[] = "AAA"; //case of crib shouldn't matter
char Dcrib4[] = "suz";  
assert(decrypt(Dcipher1, DblankCrib) == 0); 
assert(decrypt(Dcipher2, DblankCrib2) == 0);
//no match for crib possibly 
assert(decrypt(Dcipher1, Dcrib2) == 0); //no match in length 
assert(decrypt(Dcipher2, Dcrib3) == 0); //no match in letter ratio
//two matches for crib; choose either 
cout << the two matches crib result was: << endl;
(decrypt(Dcipher2, Dcrib4);
assert(decrypt(Dcipher2, Dcrib4) == 1);
//match for crib doesn't span multiple messages (separations by newlines)
char Dcipher3[] ="bwra wmwt\nqeirtk spst\n"; 
char Dcrib4[] = "alan turing";
assert(decrypt(Dcipher3, Dcrib4) == 0);
//only part of the crib matches, 
char Dcrib5[] = "he oout";
assert(decrypt(Dcipher2, Dcrib5) == 0); 

//should return matches, and all should be printed the same way
char Mcrib[] = "hush-hush until January 20, 2017";
char Mcrib2[] = "   hush???hUSh---     --- until    JanuARY !!  ";
char Mcrib3[] = "hush hush until january"
char Mcipher[] = "DiebjiggK, zyxZYXzyx--Abca abCa    bdefg## $$hidbijk6437 wvuWVUwvu\n\n8 9\n";
cout << "The next 3 decrypted messages should be print:"<< endl;
cout << "NATURALLY, zyxzyxzyx--HUSH HUSH    UNTIL## $$JANUARY6437 wvuwvuwvu\n\n8 9\n"
assert(decrypt(Mcipher, Mcrib)); //these should all print the same thing
assert(decrypt(Mcipher, Mcrib2));
assert(decrypt(Mcipher, Mcrib3));






