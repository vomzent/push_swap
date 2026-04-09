To do

- write function for ft_printf to print double (because benchmark will have to show the level of disorder)
- learn more about the "-- simple / -- bench etc"
- write out the algorithms based on the operations
	- chunk based sorting
	- quick sort?
- write out function to select algorithm based on disorder value
- should probably standardize all functions outside of stack operations to use just a "target" stack name rather than using A and B interchangably, because these functions can be used on both stacks

### Stack operations

> int[0] sa (swap a) = swap the first two elements at the top of stack a. do nothing if there is only one or no elements
> int[1] sb (swap b) = swap the first two elements at the top of stack b. do nothing if there is only one or no elements
> int[2] ss = sa and sb at the same time


> int[3] pa (push a) = take the first element at the top of b and put it at the top of a. do nothing if b is empty
> int[4] pb (push b) = take the first element at the top of a and put it at the top of b. do nothing if a is empty


> int[5] ra (rotate a) = shift up all elements of stack a by one. the first element becomes the last one
> int[6] rb (rotate b) = shift up all elements of stack b by one. the first element becomes the last one.
> int[7] rr = ra and rb at the same time

> int[8] rra (reverse rotate a) = shift down all elements of stack a by one. the last element becomes the first one
> int[9] rrb (reverse rotate b) = shift down all elements of stack b by one. the last element becomes the first one.
> int[10] rrr = rra and rrb at the same time


#### Data struct

to pass 'Stack *A' data->A
to pass 'Stack **A' &data->A
	(data->&A) would point to a local variable on the stack frame

### sorting strategies

4 distinct sorting strategies:
1. simple algorithm O^n
2. medium algorithm n * n^0.5
3. complex algorithm n * log n
4. custom adaptive algorithm (personal design)
	- design an adaptive strategy that selects different internal methods depending on measured disorder. you are not consrained to any specific named algorithm: internal techniques are entirely up to yoi

	for low disorder (disorder < 0.2): must run in O^n
	for medium disorder (0.2 <= disorder < 0.5): must run in n * n^0.5
	for high disorder (>= 0.5): must run in n log n

	- document rationale for thresholds in README.md, internal techniques used in each regime and brief complexity argument (upper bounds) for time and space within the push_swap model

Disorder metric (0 - 1)
If numbers are in order: 0
If numbers are in worst possible order: 1

Calculated by the following:
- each time a bigger number appears before a smaller one, that pair counts as a mistake. The more mistakes, the closer the disorder is to 1

```
function compute_disorder(stack a):
	mistakes = 0
	total_pairs = 0
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs

```

https://leetcode.fandom.com/wiki/Sort_with_two_stacks
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0


### Our program

- default strategy (int = 0) is adaptive, simple = 1, medium = 2, complex = 3