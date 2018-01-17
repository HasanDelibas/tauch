#include <iostream>
#include <windows.h>

#include <string>

#include "sayLastError.h"
#include "dateTime.h"
#include "touch.h"

int DEBUG = 0;

void printHelp(){
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
	"-------------  Touch Komutu --------------------------------",
	"Kullanimi: touch.exe file [date] ",
	"Parametreleri   ",
	"   file    dosyanin konumu ",
	"   date    YYYY.MM.DDTHH:mm:ss turunden tarih bilgisidir.", 
	"           Varsayilan olarak suanki zamani belirtir.\n",
	"     +     YYYY    yil",
	"     +     MM      ay",	
	"     +     DD      gun",
	"     +     T       tarih ile saat ayraci  (Bosluk haric her karakter) ",
	"     +     HH      saat",
	"     +     mm      dakika",
	"     +     ss      saniye",
	"-----------------------------------------------------------",
	"   --help    -h    yardimi goruntuler",
	"-----------------------------------------------------------",
	" Yazar : 121213040 - Hasan Delibas ",
	"-----------------------------------------------------------"
	);	
}

int main(int argc, char** argv) {
	
	
	
	if(argc==1){
		printHelp();
		return 0;
	}
	
	if( strcmp(argv[1] , "-h")==0 ||  strcmp(argv[1] , "--help")==0 ){
		printHelp();
		return 0;
	}else{
		ChangeTimeFile(argv[1],argv[2]);
	}
	
	return 0;
}
