#include <windows.h>


bool TIME_SYNTAX_ERROR = false;

bool isNumericChar(char c){
	if ( c>47 && c <58 ) return true;
	return false;
}

int ConverNumericCharToInteger(int start,int length ,char *text){
	int i = start;
	int retVal = 0;
	int pow =10;
	if (strlen(text) < start ) return 0;
	while(i-start<length){
		if(isNumericChar(text[i])==false ){
			TIME_SYNTAX_ERROR = true;
			return 0;
		}
		
		retVal *= pow;
		retVal += (text[i]-48) ;
		
		i++;
	}
	return retVal;
}




bool GetSystemTimeFromString(char *text, SYSTEMTIME *st ){
	// YYYY-MM-DD HH:MM:SS
	// 0123456789012345678
	TIME_SYNTAX_ERROR = false;
	
	ZeroMemory(st,sizeof(st));
	
	st->wYear = ConverNumericCharToInteger(0,4,text);
	st->wMonth = ConverNumericCharToInteger(5,2,text);
	st->wDay = ConverNumericCharToInteger(8,2,text);	
	
	st->wHour = ConverNumericCharToInteger(11,2,text);	
	st->wMinute = ConverNumericCharToInteger(14,2,text);	
	st->wSecond = ConverNumericCharToInteger(17,2,text);	
	st->wMilliseconds = 0;
	if ( TIME_SYNTAX_ERROR == true ){
		ZeroMemory (st, sizeof(st)  );
		SetLastError(-2);
		return false;
	}
	return true;
}

void PrintSystemTime(SYSTEMTIME *st){
	printf("\n Year: %d Month: %d Day: %d -- Hour: %d Minute: %d Second: %d \n",
	st->wYear,
	st->wMonth,
	st->wDay,
	st->wHour,
	st->wMinute,
	st->wSecond
	);
}
