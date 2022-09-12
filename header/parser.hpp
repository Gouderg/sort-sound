#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class InputParser {

    public:
        
        // Constructor.
        InputParser (int &argc, char **argv);

        // Get name after options.
        const std::string& getCmdOption(const std::string &option) const;

        // Check if options exists.
        bool cmdOptionExists(const std::string &option) const;

    private:
        std::vector<std::string> tokens;
};