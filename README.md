*This project has been created as part of the 42 curriculum by sawijnbe*



**Description**

The goal of this assignment is to sort a list of numbers.
To do that, we are given several things : firstly, the list of numbers, which will be contained in a stack named *a*. Secondly, an empy *b* stack. Finally, a dozen of useable commands to be able to sort the list:
- *pa*: push the number at the top of *b* to the top of *a*;
- *pb*: push the number at the top of *a* to the top of *b*;
- *sa*: swap the first two numbers at the top of *a*;
- *sb*: swap the first two numbers at the top of *b*;
- *ss*: execute *sa* and *sb*;
- *ra*: move the top number of *a* at its bottom (rotate *a*);
- *rb*: move the top number of *b* at its bottom (rotate *b*);
- *rr*: execute *ra* and *rb*;
- *rra*: move the bottom number of *a* at its top (reverse rotate *a*);
- *rrb*: move the bottom number of *b* at its top (reverse rotate *b*);
- *rrr*: execute *rra* and *rrb*.
Our output must be the commands needed to sort the list of numbers, each one being on a new line.



**Instructions**

Run *make* in the project folder, and then execute the program with the list of numbers.
You can also set an environment variable to your list of numbers.
For example:
```
make
./push_swap 4 18 6
LIST="5 8 0 4 6"
./push_swap $LIST
```
As I will describe later on, I am also using some bruteforcing. You can specify the maximum number of commands the bruteforcing will be allowed to output by setting an environment variable called BRUTEFORCE (*make re* is necessary each time this specification is modified):
```
export BRUTEFORCE=6
make re
unset BRUTEFORCE
```



**Resources**

I did not check out external resources specifically for this project, nor did I use AI.
I did however try to use *make [number]* for the bruteforce specification, without succeeding, and ended up using an environmental variable.



**How this shit works**

Push\_swap is probably the first project I really like in this cursus. There was the piscine, now there is push\_swap.

**Parsing**

The subject is not very clear on how the input is formatted: it could either be an array of strings containing each a number, or a string containing all the numbers separated by a space. As such, I decided to accept any number of strings containing any amount of numbers separated by any number of spaces as valid inputs. Any other character or any duplicate number will result to the giving out an error.
The numbers are then stored into a chained list, where each node contains a link to the next and the previous node. The first node of the list has *prev* linking to the last node of the list, the last node of the list has *next* linking to NULL.
Each number is converted to the index it should have if the list was sorted: if the list is 0 -5 18 4, it will be converted to 1 0 3 2.

**Bruteforcing**

One could wonder how the hell it would be possible to bruteforce sorting a list. It's actually pretty straightforward: try out all the command combinations until one works. For example, in a non-optimised bruteforce, you'd try *pa*, see the list is not sorted, then *pb*, then *sa*, [...], then *rrr*, then *pa pa*, *pa pb*, *pa sa*,... until a combination sorts the list.
Originally, I was doing that by copying the original list, applying the commands the bruteforce comes with on it, checking if the list was sorted, and then deleting it. However, I figured it was less ressource-intensive to just undo the changes on the list by applying the opposing commands compared to the ones given by the bruteforce.
There are several optimisations that I am doing to speed up the whole thing:
- If there is any *pa* while *b* is empty, or if there are more *pb* than *pa* (meaning *b* wouldn't end up empty after applying the commands), respectively, the first *pa* is changed or a new *pa* is added behind the last *pb* (if not possible because of a lack of available commands, the last *pb* is changed);
- If *b* contains less than two elements when encoutering *sb*, *ss*, *rb*, *rr*, *rrb* or *rrr*, the command is changed to the next command that is not listed right before;
- If *b* contains exactly two elements when encountering *rb*, *rr*, *rrb* or *rrr*, the command is changed to the next command that is not listed right before: reasoning being that those will have the same effect as *sb* or *ss* ; as such, they are redundant and not need to be checked;
- If there are two opposite instructions one after the other, the second one gets changed: for example, *pa pb*, *sb sb* or *ra rra* results to no change; *sa ss* or *rrr rb* can be shortened to, respectively, *sb* or *rra*;
- If there are two instructions one after the other that can be shortened, the second one gets changed: for example, *sa sb* or *rb ra* can be shortened to, respectively, *ss* or *rr*;

**Algorithms**

There will be several implemented algorithms, and push\_swap will choose the best performing one. However, I am not there yet.
