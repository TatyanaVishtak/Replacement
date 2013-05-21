# include "C_Vishtak.h"

char *str_replace(char *search, char *replace, char *subject)
{
    char  *p = NULL , *old = NULL, *new_subject = NULL; 
    int c = 0 , search_size;
    
	//strlen возвращает длину строки с нулевым символом в конце
    search_size = strlen(search);
     
    //подсчитываем количество вхождений
    //strstr - возвращает указатель в строку subject, который является первым символом подстроки search
    for(p = strstr(subject , search) ; p != NULL ; p = strstr(p + search_size , search))
    {
        c++;
    }
     
    //К длине исходной строки добавляем разность длин той на которую заменяю и той какую заменяю, умноженную на количество вхождений
    c = ( strlen(replace) - search_size )*c + strlen(subject);
     
    //Выделение памяти найденного размера; malloc() возвращает указатель на первый байт области памяти размером c
    new_subject = malloc( c );
     
    //Заполнение строки ничем
    strcpy(new_subject , "");
     
    //Запоминаем старую строку
    old = subject;
     
	//p = strstr(p + search_size , search) будет указывать на первое вхождение search в [обрезанной строке] (например, если search = ab, то qab[cab])
    for(p = strstr(subject , search) ; p != NULL ; p = strstr(p + search_size , search))
    {
        //strncpy копирует точно p - old символов в new_subject + strlen(new_subject)
		//т.е. вставляем все неподходящее в новую строку уже после всего того что там есть
        strncpy(new_subject + strlen(new_subject) , old , p - old);
         
        //после только что вставленного неподходящего вставляем replace
        strcpy(new_subject + strlen(new_subject) , replace);
         
        //old будет указывать на начало [обрезанной строки] (например, если qab[cab], то на с)
        old = p + search_size;
    }
     
    //вставляем в новую строку весь оставшийся хвост из старой строки 
    strcpy(new_subject + strlen(new_subject) , old);

	return new_subject;
}
