#include "dictionary.h"





BOOL InsertWord(DICT &dict, WORD word){
	/*
	adds word to dictionary , if word can't be added returns false else returns true
		*/
	
	BOOL good = 1; //BOOL the function will be returning
		
			if((dict.NumWords == 0) && (word.length()<=20)){
		//If this is first word added, want dict.Words to point to it
			
		dict.Words = new ENTRY;
		
			*(dict.Words) = {1,word,0}; //Allocate entry, {count,w,nextWord}
			
		dict.NumWords++;
				return good;
		}
		ENTRY *tmp = dict.Words; //Temp entry pointer to get to right part of list
	
		while (tmp->nextWord != 0) tmp = tmp->nextWord; //While not null move to next node

			if((dict.NumWords < dict.maxEntries) && (word.length()<=20)){
		
			//Compare number of words to MAX and check length of word purely to keep formatting nice

		tmp->nextWord = new ENTRY;
		
		*(tmp->nextWord) = {1,word,0}; //Allocate entry, {count,w,nextWord}
			
			dict.NumWords++;
			}
			else good = 0; //return BOOL will be 0
			
		return good;
		}





void DumpDictionary(DICT &dict) {
	/*
	will sort the dictionary, and display the contents
	*/
	//Sorting a linked list
	
	ENTRY *temphead = dict.Words;
	
		int tempint; //For swapping count var
	
			WORD tempword; //For swapping w var
		
			for (int j=0; j < dict.NumWords; j++){
				//Bubble sort
	
	while (temphead->nextWord != 0){
		
			//iterate through list until next is null
	
		if ((temphead->w).compare(temphead->nextWord->w) > 0){
		
		//Swapping contents of node rather than the nodes themselves
		tempint = temphead->count;
		temphead->count = temphead->nextWord->count;
		temphead->nextWord->count = tempint;
		tempword = temphead->w;
		temphead->w = temphead->nextWord->w;
		temphead->nextWord->w = tempword;
		temphead = temphead->nextWord; //increment node
			}
			
			else temphead = temphead->nextWord; //increment node
			
			}

		temphead = dict.Words; //reset temphead
			
			}

				cout << endl;
				cout << "Word Frequency" << endl;
				cout << "---------------------------" << endl;
				//Print the words and counts
				ENTRY *tmp = dict.Words;

	for(int i=0; i < dict.NumWords; i++){
	
		cout << tmp->w;

		for(int j=0; j< 20 - (tmp->w).length(); j++) cout << ' ';
				//Prints a fixed amount of spaces based off length of word
			cout << tmp->count << endl;
			
				tmp = tmp->nextWord;
		
		}
			}






WORD GetNextWord(void){
	/*
		will retrieve next word in input stream. Word is defined just as in assignment #1
		returns WORD or empty string if no more words in input stream
		*/
	WORD w;
	char ch;
	bool inword = false;
		
		while( cin.good() ){
		ch = cin.get();
			
			if ( isalpha(ch) ){ /* function test if ch is A-Z, a-z */
				
				w.push_back(ch);
					
					inword= true;
			}

			else if (inword) return w;
		}
			return w;
		/*
			char ch;
			WORD tmp;
			while( cin.good() ){
			ch = cin.get();
			if(ch == ' ') return tmp;
			if ( isalpha(ch) ) {
			// function test is ch is A-Z or a-z, then concats the chars onto word
			tmp.push_back(ch);
			}
			else break;
			}
			return tmp;
			*/
				
				}




BOOL FullDictionary(DICT &dict) {
		/*
		if dictionary is full, return true else false
			*/
		if(dict.NumWords == dict.maxEntries) return 1;
		
		//Compare number of words in dictionary to maxEntries, the total size
			
	return 0;
	}



ENTRY *LocateWord(DICT &dict, WORD word) {
			/*
			will determine if dictionary contains word. if found, returns pointer to entry else 				returns 0
				*/
		int found = 0;
		
		ENTRY *tmp = dict.Words;

		for(int i = 0; i < dict.NumWords; i++){ //Go through each element of dict

			if(tmp->w == word){ //Compare entry word and target word
			
		found = 1;
			
			break;
}
			tmp = tmp->nextWord; //Iterate node pointer
}
				if(found==0) return 0; //If not found

		return tmp; //Else return location, which is i
}

