//
// Created by Eitan Kats on 25/04/2022.
//

#ifndef EX4_CPP_CAPTAIN_HPP
#define EX4_CPP_CAPTAIN_HPP

#include "Player.hpp"

namespace coup {

    class Captain : public Player {
    public:
        Captain(Game &currGame, const std::string& name);

        void steal(Player &other_player);

        void block(Player &other_player);

        std::string role() const override;

    };
}


#endif //EX4_CPP_CAPTAIN_HPP
