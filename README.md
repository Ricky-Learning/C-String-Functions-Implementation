# C-String-Functions-Implementation
這段 C 程式的目的是 **自行實作基本的字串處理函數**，並進行測試。程式會讓使用者輸入字串，然後使用自己寫的函數來 **計算長度、複製字串、連接字串、比較字串、搜尋子字串**，並輸出結果。  

---

## **🔹 這段程式在做什麼？**
這是一個 C 語言的字串處理工具，模仿標準函式庫的 `strlen()`, `strcpy()`, `strcat()`, `strcmp()`, `strstr()` 函數，來進行基本的字串操作。  

### **📌 程式的主要步驟**
1. **要求使用者輸入一個字串**
2. **計算字串長度 (`strlen`)**
3. **複製字串 (`strcpy`)**
4. **連接（拼接）字串 (`strcat`)**
5. **比較兩個字串 (`strcmp`)**
6. **搜尋子字串 (`strpos`)**
7. **輸出操作後的結果**

---

## **🔹 這些函數是如何運作的？**
這段程式 **不使用標準函數**，而是自己寫了一組函數來處理字串。  

### **1️⃣ `strlen()` - 計算字串長度**
```c
int strlen(char *str){ 
	int i;
	for(i=0; str[i]!='\0'; i++);  // 迴圈計算字元數，直到遇到 '\0'（字串結尾）
	return i;
}
```
📌 **原理：**  
遍歷字串，計算字元數，直到遇到 `'\0'`（字串結束符）。  

---

### **2️⃣ `strcpy()` - 複製字串**
```c
char *strcpy(char *str, char *str1){ 
	int i;
	for(i=0; str[i]!='\0'; i++){
		str1[i] = str[i];  // 逐字複製 str 到 str1
	}
	str1[i] = '\0';  // 在末尾加上 '\0'
	return str1;
}
```
📌 **原理：**  
將 `str` 的內容逐個字元複製到 `str1`，最後加上 `'\0'` 作為結束符。

---

### **3️⃣ `strcat()` - 連接字串**
```c
char *strcat(char *str, char *str1){ 
	int i;
	for(i=0; str[i]!='\0'; i++);  // 找到 str 的結尾
	for(int j=0; str1[j]!='\0'; j++){
		str[i] = str1[j];  // 把 str1 內容接在 str 後面
		i++;
	}
	str[i] = '\0';  // 加上結束符
	return str;
}
```
📌 **原理：**  
先找到 `str` 的結尾，再把 `str1` 的內容一個一個接上去，最後補上 `'\0'`。

---

### **4️⃣ `strcmp()` - 比較字串**
```c
int strcmp(char *str, char *str1){ 
	int i;
	for(i=0; str[i] == str1[i]; i++);  // 比較兩字串每個字元
	if(str[i] == '\0'){
		return 0;  // 兩字串相等
	}else if(str[i] < str1[i]){
		return -1;  // str < str1
	}else{
		return 1;   // str > str1
	}
}
```
📌 **原理：**  
從頭開始比較兩個字串的 ASCII 值：
- **回傳 `0`**：兩個字串相等
- **回傳 `-1`**：`str` 比 `str1` 小（字典順序）
- **回傳 `1`**：`str` 比 `str1` 大（字典順序）

---

### **5️⃣ `strpos()` - 搜尋子字串**
```c
char *strpos(char *str, char *str1){ 
	int i, j=0;
	if(str1[0] == '\0'){
		return NULL;  // 如果 str1 是空字串，回傳 NULL
	}else{
		for(i=0; str[i]!='\0'; i++){
			if(str[i] == str1[j]){  // 檢查字元是否匹配
				j++;
			}
		}
	}
	if(str1[j] == '\0'){
		return str1;  // 找到子字串
	}else{
		return str;  // 沒找到，回傳原字串
	}
}
```
📌 **原理：**  
搜尋 `str` 是否包含 `str1`：
- **找到子字串 → 回傳 `str1`**
- **沒找到 → 回傳 `str`**（但這個寫法有問題，應該回傳 `NULL`）

---

## **🔹 `main()` 主程式運作方式**
```c
int main(){
```
### **使用者輸入**
```c
printf("請輸入處理的字串: ");
gets(str);
```
🔴 **⚠ `gets()` 是不安全的**（容易發生緩衝區溢出），應該用 `fgets()` 代替。

---

### **測試各函數**
```c
printf("字串長度: %d\n", strlen(str));
```
👉 **計算輸入字串的長度**  

```c
printf("複製字串: \"%s\"\n", strcpy(str, str1));
```
👉 **複製字串並輸出**  

```c
printf("連接結果: \"%s\"\n", strcat(str, str1));
```
👉 **連接字串**  

```c
printf("字串比較結果: %d\n", strcmp(str, str1));
```
👉 **比較字串**（相同回傳 `0`，不同回傳 `-1` 或 `1`）  

```c
ptr = strpos(str, str1);
if ( ptr != NULL )
    printf("搜尋字串出現的位址:%p(%c)\n", ptr, *ptr);
else
    printf("搜尋字串不是子字串\n");
```
👉 **搜尋子字串的位置**（但 `strpos()` 有 bug，結果可能不正確）

---

## **🔹 我認為可以改進的地方**
1️⃣ **`strpos()` 的問題**
   - `strpos()` 只檢查了部分匹配，不能真正找到子字串
   - 建議用 **KMP 演算法** 或 **暴力搜尋** 來修正  

2️⃣ **`gets()` 會導致緩衝區溢出**
   - 應該改用 `fgets(str, sizeof(str), stdin);` 來避免安全性問題  

3️⃣ **函數名稱與標準庫函數相同**
   - 這些函數名稱 (`strlen`, `strcpy`, `strcat`...) 跟標準函數名稱相同，可能會與標準函數衝突  
   - 可以改名成，例如 `my_strlen()`, `my_strcpy()`  

