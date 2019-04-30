class QwirkleMenu {
public:

    void newGame();

    void loadGame();

    void studentInfo();

    void quit();

    bool validUserName(std::string name);

private:

    std::string player1Name;
    std::string player2Name;
};