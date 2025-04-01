#include <stdio.h>
#include <stdlib.h>
#define LEN 16

int strlen(char *str){/* 函數: 字串長度 */ 
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

char *strcpy(char *str,char *str1){/* 函數: 字串複製 */ 
	int i;
	for(i=0;str[i]!='\0';i++){
		str1[i]=str[i];
	}
	str1[i]= '\0';
	return str1;
}

char *strcat(char *str,char *str1){/* 函數: 字串連接 */ 
	int i;
	for(i=0;str[i]!='\0';i++);
	for(int j=0;str1[j]!='\0';j++){
	str[i]=str1[j];
	i++;
	}
	str[i]='\0';
	return str;
}

int strcmp(char *str,char *str1){/* 函數: 字串比較 */ 
	int i;
	for(i=0;str[i]==str1[i];i++);
	if(str[i]=='\0'){
		return 0;
	}else if(str[i]<str1[i]){
		return -1;
	}else{
	return 1;
}
}

char *strpos(char *str,char *str1){/* 函數: 字串搜尋 */ 
	int i,j=0;
	if(str1[0]=='\0'){
		return NULL;
	}else{
	for(i=0;str[i]!='\0';i++){
		if(str[i]==str1[j]){
			j++;
		}
		}
	}
	if(str1[j]=='\0'){
		return str1;
		}else{
	return str;
}
}




/* 主程式 */
int main(){
	printf("\n本程式由 劉禹寬 設計\n\n");
	printf("請修改第 3-5 節的範例程式，改為陣列，重新撰寫各字串處理函數。\n\n");
	printf("程式設計結果如下：\n\n");

char str[100],str1[100],*ptr;
int len;
 printf("請輸入處理的字串: ");
   gets(str);
   /* 顯示字串 */ 
   printf("原始字串: \"%s\"\n", str);
   /* 顯示字串長度 */ 
   len = strlen(str);
   printf("字串\"%s\"的長度為: %d\n\n", str, len);
   /* 複製字串 */ 
   printf("原始字串: \"%s\"\n", str);
   printf("複製字串: \"%s\"\n\n", strcpy(str, str1));
   printf("請輸入欲連接的字串: ");
   gets(str1);
   printf("欲連接字串: \"%s\"\n", str1); 
   ptr=strcat(str, str1); /* 連接字串 */ 
   printf("連接結果的字串: \"%s\"\n\n", ptr);
   printf("請輸入欲比較的字串: ");
   gets(str1);
   printf("欲比較的字串: \"%s\"\n", str1);
   /* 字串比較 */ 
   printf("字串比較結果: %d\n\n", strcmp(str, str1));
   printf("請輸入搜尋字串: ");
   gets(str1);
   printf("搜尋字串: \"%s\"\n", str1);    
   ptr = strpos(str, str1);        /* 搜尋字串 */
   if ( ptr != NULL )
      printf("搜尋字串出現的位址:%p(%c)\n", ptr, *ptr);
   else
      printf("搜尋字串不是子字串\n");

system("PAUSE");/* 暫停 */
return 0;
}

