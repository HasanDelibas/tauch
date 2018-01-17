#include <windows.h>

HANDLE GetHandleFile(char *file){
	HANDLE hFile =
	CreateFile( file,
		GENERIC_READ | GENERIC_WRITE ,
		FILE_SHARE_DELETE | FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,NULL);

	if ( hFile == INVALID_HANDLE_VALUE){
		if(GetLastError() == 80){
			hFile =
			CreateFile( file,
				GENERIC_READ | GENERIC_WRITE ,
				FILE_SHARE_DELETE | FILE_SHARE_WRITE | FILE_SHARE_READ,
				NULL,
				OPEN_EXISTING,
				FILE_ATTRIBUTE_NORMAL,NULL);
			if( hFile == INVALID_HANDLE_VALUE ){
				SayLastError();
				return NULL;
			}
				
		}else{
			SayLastError();
			return NULL;
		}
	}else{
		return hFile;	
	}		
}



void ChangeTimeFile(char *file,char *time){
	HANDLE hFile = GetHandleFile(file);	
	SYSTEMTIME st;
	FILETIME ft;
	if(hFile!=NULL){
		if(time!='\0'){			
				if( GetSystemTimeFromString(time,&st) == false ){
					SayLastError();
					CloseHandle(hFile);
					return;
				}

			SystemTimeToFileTime(&st, &ft);					
			LocalFileTimeToFileTime(&ft,&ft);
		}else{
			GetSystemTime(&st);
			SystemTimeToFileTime(&st, &ft);
		}
			

			SetLastError(0);
		    SetFileTime(hFile,              
		        &ft,
		        &ft, 
		        &ft);
			if(GetLastError()!=0){
				SayLastError();
			}
		CloseHandle(hFile);
	}
	
}
