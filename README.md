# ⭐ Welcome to My Language ⭐

## 📚 Tokens

Compiler source code ko ek saath nahi padhta. Sabse pehle woh source code ko chhote-chhote parts mein todta hai. In parts ko **Tokens** kaha jata hai.

### Example

```cpp
int age = 20;
```

Is statement ke tokens hain:

* `int`
* `age`
* `=`
* `20`
* `;`


## 📚 Token Type
 
Har ek token ka ek type hota hai usko  **Token Type** kaha jata hai.\

### Example
 
* `int`    **Keyword** 
* `age`    **Variable**  or **identifer**
* `20`     **value** 
* `;`      **End** 

## 📚 Enum

har ek data ka type yaad rakhna muskil hota hai iske hum **Enum class** ka use karenge jisse user kewal issi se type ka use kar sakta hai .

### Example

```cpp
enum class TokenType{
    Identifier,
    Number,
    Keyword,
    Operator,
    EndOfFile
};
```

Matlab ki user ko variable ko define karne ke liye kewal yahi 5 option hai


## 📚 Token Class

Token class ke bina compiler source code ke alag-alag parts (keywords, identifiers, numbers, operators, etc.) ko identify aur store nahi kar payega. Agar tokens hi nahi honge, to parser source code ko samajh hi nahi payega.

```cpp
 
 class token {
    public:
      Tokentype type;
      std::string value;
 }
```

## 📚 Lexer class

lexer class hamare sourceCode ko tokens me convert karti hai. aur source Code ko multiple parts me devide karti hai  imse fist word check karti hai ki keyword ko represet karti hai second word Identifer ko convert karti hai. aur last value ko represent  hai 


### Example 

```cpp
 int num = 50;
```
``` Output
  Keyword  : int
  Identifer : num
  Number value : 50
```
lexer me har ek word ka token create kiya hai.

## 📚 Parser class

 **Parser Class** code ka grammer check karta hai ki code ka structure  sahi hai yah nhi isme aur  main abhi apni language ke according grammer set karunga and keywords bhi set karna hai.
 


# 🐦‍🔥 Grammer of My language 🐦‍🔥

## variable declearation

 Is languange me variable ko declear karna bahut hi aasan hai sabse pahle hum variable ka type store karenge ki us variable me kis type ka ayega (ex. int,char,float,string etc..) uske baad variable ka ka kaam variable ka naame alphabet se start hona chahiye koi special charectors use hi hona chahiye.

 ### Example
  
#### **Int**
```my
 int num = 10;
```

#### **Float**
```my
 float num = 10.0;
```

#### **char**
```my
 char num = '5';
```

#### **String**
```my
 string num = "string";
```



## Input function
 Is languange  input lene ke liye aap ko ask() function ka use karna hoga jaha par aap ask() function ka use kar sakte hai aur aap ask function ke ander string bhi pass kar sakte hai jisse output me yah string show hogi  aur is value ko kisi  variable me store karna hoga . aap is example se samajh sakte hai.

 ### Example 
 
```my
 int num = ask("Enter num :- ");
```
