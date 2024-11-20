#include <iostream> 
#include <memory> 

class BaseNode{
public:
    BaseNode() {}
    virtual int evaluate(){
        std::cout <<"this should not have been called!" << std::endl;
        return -1;
    };
}; 

class ValueExpr: public BaseNode{
    int value; 
public:
    int evaluate() override{
        return value;
    }
};

class BinExpr: public BaseNode{

    std::unique_ptr<ValueExpr> LHS, RHS;
public:
    int evaluate() override{
        return 0;
    }
};

std::unique_ptr<BaseNode> LogError(const char* msg){
    std::cout << msg << std::endl; 
    return std::make_unique<BaseNode>();
}

std::unique_ptr<BaseNode> makeTree(){ 
    return std::make_unique<BaseNode>();
}

enum Token{
    BINARY_OP, 
    NUMERICAL, 
    EOF
}; 

struct TokenizerData
{
    Token token;
    int value; // if it has one!
};

class Tokenizer{
public:
    Tokenizer(const std::string& expression)
        :m_parse_string(expression), atIndex (0)
    {
        
    } 

  
    
    Token getNextToken()
    {
        // getting the next token
        std::string current_symbol = "";
        // TODO: convert this into stream instead
        while(m_parse_string.size() < atIndex && m_parse_string[atIndex] != ''){
            current_symbol += m_parse_string + m_parse_string[atIndex];
            ++atIndex;
        }


        return Token::BINARY_OP;
    }

    int getValue();
private:
    void consumeWhiteSpace(){

    }
    
    std::string m_parse_string;
    int atIndex;
};

int main(){
    std::string expression = "12 + 12*13*14 + 15";
    int expected_answer = 2211;

    std::cout << "Hello World" << std::endl; 
    return 0;
}