#include <stdio.h>
#include <stdlib.h>
#define LEN 16

int strlen(char *str){/* ���: �r����� */ 
	int i;
	for(i=0;str[i]!='\0';i++);
	return i;
}

char *strcpy(char *str,char *str1){/* ���: �r��ƻs */ 
	int i;
	for(i=0;str[i]!='\0';i++){
		str1[i]=str[i];
	}
	str1[i]= '\0';
	return str1;
}

char *strcat(char *str,char *str1){/* ���: �r��s�� */ 
	int i;
	for(i=0;str[i]!='\0';i++);
	for(int j=0;str1[j]!='\0';j++){
	str[i]=str1[j];
	i++;
	}
	str[i]='\0';
	return str;
}

int strcmp(char *str,char *str1){/* ���: �r���� */ 
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

char *strpos(char *str,char *str1){/* ���: �r��j�M */ 
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




/* �D�{�� */
int main(){
	printf("\n���{���� �B��e �]�p\n\n");
	printf("�Эק�� 3-5 �`���d�ҵ{���A�אּ�}�C�A���s���g�U�r��B�z��ơC\n\n");
	printf("�{���]�p���G�p�U�G\n\n");

char str[100],str1[100],*ptr;
int len;
 printf("�п�J�B�z���r��: ");
   gets(str);
   /* ��ܦr�� */ 
   printf("��l�r��: \"%s\"\n", str);
   /* ��ܦr����� */ 
   len = strlen(str);
   printf("�r��\"%s\"�����׬�: %d\n\n", str, len);
   /* �ƻs�r�� */ 
   printf("��l�r��: \"%s\"\n", str);
   printf("�ƻs�r��: \"%s\"\n\n", strcpy(str, str1));
   printf("�п�J���s�����r��: ");
   gets(str1);
   printf("���s���r��: \"%s\"\n", str1); 
   ptr=strcat(str, str1); /* �s���r�� */ 
   printf("�s�����G���r��: \"%s\"\n\n", ptr);
   printf("�п�J��������r��: ");
   gets(str1);
   printf("��������r��: \"%s\"\n", str1);
   /* �r���� */ 
   printf("�r�������G: %d\n\n", strcmp(str, str1));
   printf("�п�J�j�M�r��: ");
   gets(str1);
   printf("�j�M�r��: \"%s\"\n", str1);    
   ptr = strpos(str, str1);        /* �j�M�r�� */
   if ( ptr != NULL )
      printf("�j�M�r��X�{����}:%p(%c)\n", ptr, *ptr);
   else
      printf("�j�M�r�ꤣ�O�l�r��\n");

system("PAUSE");/* �Ȱ� */
return 0;
}

