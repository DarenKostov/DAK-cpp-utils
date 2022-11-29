//readLn- reads a line and puts it in the parsers memory

// returnCommand- itll return the command/arguments dependig on what you give it
// 0-command
// 1-arg 1
// 2-arg 2
// etc

//inpit stores the entire line
//command store each induvudual command and argment in the line

//fixCommand- fixes the command input as well as apply aliases

//commandIndex is the index of the inputed command (help is 0, features is 1, tips is 2, etc) 

class Parser{
  public:
    Parser(char AllCommands[10][10][10], char AllCommandsDescription[10][50], char allCommandArgsDef[10][10][10], char AllCommandsArgs[10][20]);
    void readLn();
    char* returnCommand(int i);
  private:
    char allCommands[10][10][10];
    char allCommandsDescription[10][50];
    char allCommandArgsDef[10][10][10];
    char allCommandsArgs[10][20];
    char input[99];
    char command[10][10];
    bool fixCommand();
    bool fixArgs();
    int commandIndex;


};