# touch
Linux like in windows touch comand

    |
    |--dateTime.h        -> convert "Date string" to SYSTEM_DATE
    |--touch.h           -> call handler and change file date-time
    |--sayLastError.h    -> print ERROR_CODE to English text
    |--main.cpp          -> get arguments
    
>Example    
    
    Usage:
    touch file_name [date-time default now];
    
    #Change File time "test.txt" at now,
    touch test.txt;
    
    #Change Folder time "D:\MyFiles\test" at "2002.11.22 12.20.00"
    touch "D:\MyFiles\test" 2002.11.22-12.20.00
    
    date-time seperator can be non-space any character. If you use double quete seperator can be space.
    
    2002:11:22.12.20.00   true
    2002.11.22-12.20.00   true
    2002/11/22T12.20.00   true
    
    2002 11 22 12 20 00   false
    "2002 11 22 12 20 00"   true
