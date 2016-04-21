instructions::instructions (std::vector<std::string> instLine)
{
    name = instLine[0];
    for (int i = 1; i < 4; ++i)
    {
        operands[i - 1] = instLine [i];
    }
}

std::string instructions::getName ()
{
    return name;
}

std::vector<std::string> instructions::getOperands ()
{
    
}