[![Tests](https://github.com/ChicoState/tappityplus/actions/workflows/testing.yml/badge.svg)](https://github.com/ChicoState/tappityplus/actions/workflows/testing.yml) Testing status for ChicoState/tappityplus

# Getting Started

Build the Unit Testing CPP ("gtest") container if you have not already:

`docker build -t gtest .`

Then run the container, with bound access to your repository:

`docker run --mount type=bind,source="$(pwd)",target=/usr/src -it gtest`

Or to interactively work within the container's shell:

`docker run --mount type=bind,source="$(pwd)",target=/usr/src -it gtest sh`


# TappityPlus

## Public Functions
`tappity(std::string)`

*Constructor sets the reference phrase*
___

`void entry(std::string)`

*Provides the input to be compared to the reference. Before this function is called, the input should be considered an empty string*
        
___

`int length_difference()`

*Compares the length of the reference to that of the input and returns the absolute value of the difference, or 0 if they are the same length*
        
___
`double accuracy()`

*Compares the content of the reference to that of the input and calculates the accuracy of matching characters. If the two strings are identical, accuracy should be 100. However, for each corresponding character that does not match in the same location, the percentage of corresponding characters should be returned. For example, if the reference and input have 10 letters and the input matches 8 of the corresponding reference characters, the function should return 80. When input does not have the same number of characters as the reference, the accuracy should represent the percent of matching characters between the shorter and longer strings. For example, if one string has 8 characters matching the corresponding locations in another string that has 16 characters, the accuracy is 50.*
