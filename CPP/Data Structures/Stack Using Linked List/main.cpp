#include <iostream>
#include <vector>
#include "ll_stack.hpp"

int main()
{
    size_t n;
    int x;
    std::cout << "How many numbers do you wanna enter?: ";
    std::cin >> n;

    List_stack<int> successors;
    std::vector<int> input;

    //Load the user input into the input vector
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << "Enter the " << i + 1 << ". number: ";
        std::cin >> x;
        input.push_back(x);
    }

    //Push the first input to the stack so we can
    //start search for his first greater successor
    successors.push(input.at(0));
    std::cout << std::endl;

    std::cout << "Largest successor: " << std::endl;

    //We pass through the input vector only once while searching for successors
    //which means that our complexity scales with the number of elements linearly.
    //The complexity is O(n).
    for (size_t i = 1; i < n; ++i)
    {
        //If after an iteration the stack is empty, we push a new element to the stack
        //because it will automatically be the smallest (only) element on the stack.
        if (successors.empty())
        {
            successors.push(input.at(i));
            continue;
        }
        //In every iteration of the for loop, we check if the i-th input element is bigger than
        //the current top of the stack. If it is, it means we found the first greater successor
        //of the top element. We also need to check if the stack is empty because inside the loop we are
        //poping elements from the stack, but before entering the while loop, the stack should never be empty.
        while (!successors.empty() && successors.top() < input.at(i))
        {
            //Print all the numbers on the stack that are lower than the i-th input element.
            //Only one per iteration of the while loop.
            std::cout << successors.top() << " ---------> " << input.at(i) << std::endl;
            //After finding the greater successor of an element, we can remove the element from the stack
            successors.pop();
        }

        //Push a new element to the stack because it is lower than the current top or the stack is empty
        successors.push(input[i]);
    }

    //If after iterating over all the input elements, there are still elements on the stack
    //that mean that those numbers don't have greater successors and we just print -1 for all of them.
    while (!successors.empty())
    {
        std::cout << successors.top() << " ---------> " << -1 << std::endl;
        successors.pop();
    }

    return 0;
}
