# Libtf

## ft_memset.c
```c
void	*ft_memset(void *b, int c, size_t len)
```

  **This function copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument b.**
  
  **b** − This is a pointer to the block of memory to fill.
  
  **c**− This is the value to be set. The value is passed as an int, but the function fills the block of memory using the unsigned char conversion of this value.
  
  **n** − This is the number of bytes to be set to the value.
  
  **Return value** - This function returns a pointer to the memory area b.
  ```c
  Example;
  
  char str[] = "Hello World!";
  
  memset(str,'$',7);

Standart Output -> $$$$$$$ Hello World!
``` 
## ft_memcpy.c
```c
void	*ft_memcpy(void *dest, const void *src, size_t n)
```

 **This function copies n characters from memory area src to memory area dest.**
 
 **dest** − This is pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.
 
 **src** − This is pointer to the source of data to be copied, type-casted to a pointer of type void*.
 
**n** − This is the number of bytes to be copied.

 **Return value** - This function returns a pointer to destination, which is dest.
```c
Example;

char dest[50];
char src[] = "This my source string";
memcpy(dest, src, strlen(src)+1);

Standart Output -->
Before memcpy dest = 
After memcpy dest = This my source string
```
## ft_memmove.c

```c
void	*ft_memmove(void *dst, const void *src, size_t len)
```
**This function  copies n characters from str2 to str1, but for overlapping memory blocks, memmove() is a safer approach than memcpy().**

**str1** − This is a pointer to the destination array where the content is to be copied, type-casted to a pointer of type void*.

**str2** − This is a pointer to the source of data to be copied, type-casted to a pointer of type void*.

**n** − This is the number of bytes to be copied.

**Return value** - This function returns a pointer to the destination, which is dst.
```c
Example: //If we work with two different arrays. 

int main () {
   char dest[] = "oldstring";
   const char src[]  = "newstring";

   printf("Before memmove dest = %s, src = %s\n", dest, src);
   memmove(dest, src, 9);
   printf("After memmove dest = %s, src = %s\n", dest, src);

   return(0);
}

Standart Output -->
Before memmove dest = oldstring, src = newstring
After memmove dest = newstring, src = newstring
```
```c
Example: //If we work with single array. 

int main () {
   char str[] = "abcde";
   printf("Before memmove str %s", str);
   memmove(str, str+2, 2);
   printf("After memmove str %s", str);
   return(0);
}
Standart Output -->
Before memmove str = abcde
After memmove str = cdcde
```
## ft_memcmp.c

```c
int ft_memcmp(const void *str1, const void *str2, size_t n)
```
**This function compares the first n bytes of memory area str1 and memory area str2.**

**str1** − This is the pointer to a block of memory.

**str2** − This is the pointer to a block of memory.

**n** − This is the number of bytes to be compared.

**Return Value**

if Return value < 0 then it indicates str1 is less than str2.

if Return value > 0 then it indicates str2 is less than str1.

if Return value = 0 then it indicates str1 is equal to str2.

```c
Example;

int main () {
   char str1[15];
   char str2[15];
   int comp;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   comp = memcmp(str1, str2, 5);

   if(comp > 0) {
      printf("str2 is less than str1");
   } else if(comp < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   return(0);
}

Output --> str2 is less than str1
```
## ft_memchr.c

**This C function searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument s.**

```c
void	*ft_memchr(const void *s, int c, size_t n)
```
**Parameters**

**s** − This is the pointer to the block of memory where the search is performed.

**c** − This is the value to be passed as an int, but the function performs a byte per byte search using the unsigned char conversion of this value.

**n** − This is the number of bytes to be analyzed.

**Return Value**

This function returns a pointer to the matching byte or NULL if the character does not occur in the given memory area.

```c
Example:

int main()
{
    char str[] = "My name is Dilara";
    printf("My function: %s\n", ft_memchr(str, 'a',4));
    return 0;
}

Standart Output -->
My function before memchr: = My name is Dilara
My function after memchr= ame is Dilara
```

## ft_striteri.c

```c
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
```
ft_striteri function iterates over each character of the string s and applies the function f to each character, passing its index and a pointer to the character.

## ft_lstmap.c
```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
```
This function iterates over each element of the list, applies the function 
f to the content of each element, and creates a new list with the results. 
If the memory allocation fails at any point, it deletes the newly created list and returns NULL.

lst: The beginning of the list to iterate.

f: The function to apply to each element of the list.

del: The function used to delete the content of an element if needed.

# In C, when you pass a variable to a function, you can pass it either by value or by reference.

**Passing by value:** When you pass a variable by value to a function, you are passing a copy of the variable's value. Any modifications made to the parameter inside the function will not affect the original variable.

Passing by value:
When passing by value, the function receives copies of the variables. Changes made to the copies inside the function don't affect the original variables.

```c
#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}
```

```c
Output:
Before swap: x = 5, y = 10
After swap: x = 5, y = 10
```

**Passing by reference:** When you pass a variable by reference to a function, you are passing the address of the variable. This means that any modifications made to the parameter inside the function will affect the original variable.

```c
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n", x, y);
    return 0;
}
```

```c
Output:
Before swap: x = 5, y = 10
After swap: x = 10, y = 5
```

# test
## test'
### test
#### btest

 
