#ifndef EX4_CPP_GAME_HPP
#define EX4_CPP_GAME_HPP

#include "vector"
#include "string"

namespace coup {
    class Game {
    private:
        std::vector<std::string> _currPlayers;
        size_t currPlayer = 0;
    public:

        void addPlayer(const std::string& name);

        std::vector<std::string> players();

        std::string turn();

        std::string winner();

        void passTurn();
    };
}

#endif //EX4_CPP_GAME_HPP
