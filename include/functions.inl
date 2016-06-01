bool readFile( std::string & _filename, 
                std::vector<Instruction> & inst_vec) {

    std::string line;
    std::ifstream file(_filename, std::fstream::in);
    
 
    if( ! file.is_open() )
    {
        std::cout << "Something went wrong with the read file...\n";
        return false;
    }
    
    while( !file.eof())
    {
        std::getline(file, line);
        if(!line.empty())
        {
            Instruction temporary(line);
            inst_vec.push_back(temporary);
        }
    }

    file.close();
    return true;
}

void analysis( std::vector<Instruction> inst_vec ){
    int t = 0;
    
    Queue<std::string> operators;
    
    for( auto i(0); i < inst_vec.size() ; /* Empty */ ){
        if( i == 0 ){
            std::cout << i+1 << ". [ ][ ][ ][ ][ ] - ";
            operators.enqueue( inst_vec[i].getDest() );
            inst_vec[i].print();
            i++;
            t++;
        }else{
            if( t >= 4) operators.dequeue();
            if( operators.find(inst_vec[i].getOp1()) or operators.find(inst_vec[i].getOp2()) ){
                operators.enqueue("empty");
                t++;
            }
            else{
                for (auto j (0); j < t; j++)
                    std::cout << "   ";
                std::cout << i+1 << ". [ ][ ][ ][ ][ ] - ";
                operators.enqueue( inst_vec[i].getDest() );
                inst_vec[i].print();
                i++;
                t++;
            }
        }
    }
    while(!operators.isEmpty())
    {
        operators.dequeue();
        t++;
    }

    std::cout << "Total time: " << t << std::endl;
    
}