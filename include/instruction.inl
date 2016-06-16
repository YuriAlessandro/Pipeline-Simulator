Instruction::Instruction( std::string inst_line ) : 
             m_name( "devoid" ), m_dest( "devoid" ), m_op1( "devoid" ), m_op2 ( "devoid" )
{
    std::string aux = "";
    std::vector<std::string> tokenized; 
    
    for(auto i (0u); i < inst_line.length(); ++i)
    {
        if(inst_line[i] == ' ' or inst_line[i] == ',')
            continue;
        else 
        {
            while(inst_line[i] != ' ' and inst_line[i] != ',' and i < inst_line.length())
            {
                aux += inst_line[i++];
            }
            tokenized.push_back(aux);
            aux = "";
        }        
    }
    
    if(tokenized[0] == "lw" or tokenized[0] == "addi" or tokenized[0] == "subi")
    {
        if((tokenized[0] == "lw" and tokenized.size() < 3) or 
        ((tokenized[0] == "addi" or tokenized[0] == "subi") and tokenized.size() < 4 ))
        {
            std::cout << "Invalid instruction format for " << tokenized[0] << std::endl;
        }
        else 
        {
            m_name = tokenized[0];
            m_dest = tokenized[1];
            m_op1 = tokenized[2];
        }
    }
    else if(tokenized[0] == "sw")
    {
        if(tokenized.size() < 3)
        {
            std::cout << "Invalid instruction format for " << tokenized[0] << std::endl;
        }
        else 
        {
            m_name = tokenized[0];
            m_dest = tokenized[2];
            m_op1 = tokenized[1];
        }
    }
    else if(tokenized[0] == "beq" or tokenized[0] == "bne")
    {
        if(tokenized.size() < 4)
        {
            std::cout << "Invalid instruction format for " << tokenized[0] << std::endl;
        }
        else 
        {
            m_name = tokenized[0];
            m_op1 = tokenized[1];
            m_op2 = tokenized[3];
        }
    }
    else if(tokenized[0] == "mfhi" or tokenized[0] == "mflo")
    {
        if(tokenized.size() < 2)
        {
            std::cout << "Invalid instruction format for " << tokenized[0] << std::endl;
        }
        else 
        {
            m_name = tokenized[0];
            m_dest = tokenized[1];
        }
    }
    else if(tokenized[0] == "mult" and tokenized[1] != "lo")
    {
        if(tokenized.size() < 3)
        {
            std::cout << "Invalid instruction format for " << tokenized[0] << std::endl;
        }
        else
        {
            m_name = tokenized[0];
            m_dest = "lo";
            m_op1 = tokenized[1];
            m_op2 = tokenized[2];
        }
    }
    else
    {
        if(tokenized.size() < 4)
        {
            std::cout << "Invalid instruction format for " << tokenized[0] << std::endl;
        }
        else
        {
            m_name = tokenized[0];
            m_dest = tokenized[1];
            m_op1 = tokenized[2];
            m_op2 = tokenized[3];
        }
    }
}

std::string Instruction::getName(){ return m_name; }

std::string Instruction::getDest(){ return m_dest; }

std::string Instruction::getOp1(){ return m_op1; }

std::string Instruction::getOp2(){ return m_op2; }

// Show
void Instruction::print( /*EMPTY*/ )
{
    std::cout << "[" << m_name << " " << m_dest << " " <<
                m_op1 << " " << m_op2 << "]" << std::endl;
}

