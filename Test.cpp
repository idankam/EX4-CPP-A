#include "exception"

#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"

#include "Player.hpp"
#include "Game.hpp"

#include "doctest.h"

using namespace coup;

TEST_CASE ("Basic:") {

    Game game_1{};

    Duke duke{game_1, "Idan"};
    Assassin assassin{game_1, "Gabi"};
    Ambassador ambassador{game_1, "Zoe"};
    Captain captain{game_1, "Dan"};
    Contessa contessa{game_1, "Bar"};


    

    SUBCASE("players:") {
        CHECK_NOTHROW(duke.role());
        CHECK_THROWS(ambassador.coup(assassin));
        CHECK_EQ(duke.role(), "Duke");
        CHECK_EQ(duke.coins(), 0);
        CHECK_THROWS(game_1.winner());
    
        CHECK_NOTHROW(assassin.role());
        CHECK_THROWS(assassin.coup(duke));
        CHECK_EQ(assassin.role(), "Assassin");
        CHECK_EQ(assassin.coins(), 0);
        CHECK_THROWS(game_1.winner());

        CHECK_NOTHROW(ambassador.role());
        CHECK_THROWS(ambassador.coup(duke));
        CHECK_EQ(ambassador.role(), "Ambassador");
        CHECK_EQ(ambassador.coins(), 0);
        CHECK_THROWS(game_1.winner());

        CHECK_NOTHROW(captain.role());
        CHECK_THROWS(captain.coup(duke));
        CHECK_EQ(captain.role(), "Captain");
        CHECK_EQ(captain.coins(), 0);
        CHECK_THROWS(game_1.winner());

        CHECK_NOTHROW(contessa.role());
        CHECK_THROWS(contessa.coup(duke));
        CHECK_EQ(contessa.role(), "Contessa");
        CHECK_EQ(contessa.coins(), 0);
        CHECK_THROWS(game_1.winner());
    }

    SUBCASE("game:") {
        CHECK_EQ(game_1.turn(), "Idan");
        CHECK_NOTHROW(duke.income());
        CHECK_EQ(duke.coins(), 1);
        CHECK_THROWS(duke.income());
        CHECK_THROWS(game_1.winner());
    

        for (int i = 0; i <= 3; ++i) {
                    CHECK_NOTHROW(game_1.nextPlayerTurn());
        }
        CHECK_EQ(game_1.turn(), "Idan");
        CHECK_THROWS(game_1.winner());

    }
}
TEST_CASE ("Advanced:") {

    SUBCASE("coup") {

        Game game_2{};

        Duke duke{game_2, "Idan"};
        Assassin assassin{game_2, "Gabi"};

        for(int i = 0; i < 10; i++){
            CHECK_NOTHROW(duke.income());
            CHECK_NOTHROW(assassin.income());
        }
        CHECK_THROWS(duke.income());
        CHECK_THROWS(duke.income());
        CHECK_NOTHROW(duke.coup(assassin));
        CHECK_THROWS(game_2.winner());
    }

    SUBCASE("max players") {
        
        Game game_1{};

        Duke duke{game_1, "Idan"};
        Assassin assassin{game_1, "Gabi"};
        Ambassador ambassador{game_1, "Zoe"};
        Captain captain{game_1, "Dan"};
        Contessa contessa{game_1, "Bar"};
        Captain captain2{game_1, "Dani"};
        bool check = false;
        try
        {
            Contessa contessa2{game_1, "Bari"};
            check = true;
        }
        catch(const std::exception& e)
        {
            if(check){
                throw invalid_argument("bad!");
            }
        }       
    }
}