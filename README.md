# Welcome to push_swap!

This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, we will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

## Installation

Clone the repository:
```sh
git clone git@github.com:sdummett/push_swap.git
```
Make to install the push_swap and checker program:
```sh
make
```
If you want to install only push_swap:
```sh
make push_swap
```
If you want to install only the checker:
```sh
make checker
```

## Usage

### push_swap

You can run the push_swap program with a number per argument:
```sh
./push_swap 2 1 3
```
If you want to use an environment variable on zsh:
```sh
ARG="2 1 3"; ./push_swap ${=ARG}
```
On bash:
```sh
ARG="2 1 3"; ./push_swap $ARG
```

### checker
The checker program will take a list of instructions on his stdin and the list of number to be sorted as parameters.
Example:
```sh
./push_swap 2 1 3 | ./checker 2 1 3
```
Or with environment variable on zsh:
```sh
ARG="1 2 3"; ./push_swap ${=ARG} | ./checker ${=ARG}
```
On bash:
```sh
ARG="1 2 3"; ./push_swap $ARG | ./checker $ARG
```

## Author

👤 **Stone**

* Github: [@sdummett](https://github.com/sdummett)
