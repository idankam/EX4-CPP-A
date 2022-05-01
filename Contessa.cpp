//
// Created by Eitan Kats on 25/04/2022.
//

#include "Contessa.hpp"

namespace coup {
    Contessa::Contessa(Game &currGame, const std::string& name)
            : Player{currGame, name} {}

    void Contessa::block(Player &other_player) {

    }

    std::string Contessa::role() const {
        return "Contessa";
    }
}