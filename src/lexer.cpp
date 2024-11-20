#include <iostream>
#include <memory>

class BaseNode {
public:
  BaseNode() {}
  virtual int evaluate() {
    std::cout << "this should not have been called!" << std::endl;
    return -1;
  };
};

class ValueExpr : public BaseNode {
  int value;

public:
  int evaluate() override { return value; }
};

class BinExpr : public BaseNode {

  std::unique_ptr<ValueExpr> LHS, RHS;

public:
  int evaluate() override { return 0; }
};

std::unique_ptr<BaseNode> LogError(const char *msg) {
  std::cout << msg << std::endl;
  return std::make_unique<BaseNode>();
}

std::unique_ptr<BaseNode> makeTree() { return std::make_unique<BaseNode>(); }

enum Token { BINARY_OP, NUMERICAL, END_OF_FILE };

struct TokenizerData {
  Token token;
  int value; // if it has one!
};

std::ostream &operator<<(std::ostream &stream, const TokenizerData &data) {
  std::string token_string;
  switch (data.token) {
  case Token::BINARY_OP:
    token_string = "Binary Op";
    break;
  case Token::NUMERICAL:
    token_string = "Numerical";
    break;
  case Token::END_OF_FILE:
    token_string = "End of File";
    break;
  default:
    token_string = "unknown string";
    break;
  }
  stream << "value:" << data.value << ", token: " << token_string;
  return stream;
}

class Tokenizer {
public:
  Tokenizer(const std::string &expression)
      : m_parse_string(expression), atIndex(0) {}

  TokenizerData getNextToken() {
    // ignore white space
    consumeWhiteSpace();

    if (atIndex >= m_parse_string.size()) {
      return {Token::END_OF_FILE, -1};
    }

    // getting the next token
    std::string current_symbol = "";
    bool isNumerical = true;
    while (atIndex < m_parse_string.size() && m_parse_string[atIndex] != ' ') {
      char currentChar = m_parse_string[atIndex];
      if (!isalnum(currentChar)) {
        isNumerical = false;
      }

      current_symbol += currentChar;
      ++atIndex;
    }

    if (isNumerical) {
      int data = std::stoi(current_symbol);
      return {Token::NUMERICAL, data};
    } else {
      return {Token::BINARY_OP, -1};
    }
  }

private:
  void consumeWhiteSpace() {
    while (m_parse_string[atIndex] == ' ' && atIndex < m_parse_string.size()) {
      ++atIndex;
    }
  }

  std::string m_parse_string;
  int atIndex;
};

int main() {
  std::string expression = "12 + 12 * 13 * 14 + 15";
  std::cout << expression << std::endl;
  Tokenizer tokenizer(expression);

  TokenizerData nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;
  nextToken = tokenizer.getNextToken();
  std::cout << nextToken << std::endl;

  std::cout << "The program has ended" << std::endl;
  return 0;
}
