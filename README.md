# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

Longest word in the dictionary which we are taking as a benchmark for wordlength.

## According to its man page, what does `getrusage` do?

Outputs the resource usage according to first user input to the function and returns a struct rusge type of variable with all the values.

## Per that same man page, how many members are in a variable of type `struct rusage`?

There are 16 members in the rusage datatype.

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

The struct rusage data type is a big datatype and takes quite a bit of memory when we pass by
reference the copy of pointer is created rather than that of the entire datatype.Therefore,less memory is used and it is better efficiency wise.


## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

Variable c is initialized to read one character at a time from the file until the loop gets to the end of the file.
Firstly the program checks whether the character stored in c is an alphanumeric.In the case this is true , the program adds the character to an array of letters called word
This array acts as storage for the owrd later to be checked.In case the word is too large to be a real word,the program moves to a new word.If the letter we got
was a numerical digit,we again move to a new word.In case, the letter is not alphanumeric,the program is believed to have reached the end of a word and terminates it with '\0'.
Next,it checks if the word stored is misspelled and if it truely is misspelled, it prints the misspelled word.The program readies the array word for a new set of characters.

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

Using fscanf we cannot check one at a time whether the character is a number or a alphabet.This is crucial for implementation of the problem.
We also cannot check the length of the word and hence it can exceed the allotted memory is array word.This would cause our program to break down.


## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

Neither the word to be checked or the ones in the dictionary should be changed during our implementation.But it is pretty unlikely that we get the code exactly right in our first attempt.
We can run into issues in latter tries due to changes made by mistake in the former attempts.Hence,the paramter constant is set to avoid such a blunder.
