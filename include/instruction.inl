Instruction::Instruction( std::string inst_line ) : 
             m_name( "void" ), m_dest( "void" ), m_op1( "void" ), m_op2 ( "void" )
{
    std::string aux = "";
    std::vector<std::string> tokenized; 
    
    for(auto i (0u); i < inst_line.length(); ++i)
    {
        if(inst_line[i] == ' ')
            continue;
        else 
        {
            while(inst_line[i] != ' ' && i < inst_line.length())
            {
                aux += inst_line[i++];
            }
            tokenized.push_back(aux);
            aux = "";
        }        
    }
    
    if(tokenized[0] == "lw" or tokenized[0] == "addi" or tokenized[0] == "subi")
    {
        m_name = tokenized[0];
        m_dest = tokenized[1];
        m_op1 = tokenized[2];
    }
    else if(tokenized[0] == "sw")
    {
        m_name = tokenized[0];
        m_op1 = tokenized[1];
    }
    else
    {
        m_name = tokenized[0];
        m_dest = tokenized[1];
        m_op1 = tokenized[2];
        m_op2 = tokenized[3];
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

