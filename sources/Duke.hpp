#include "Player.hpp"

namespace coup{
    class Duke : public Player
    {
    private:
     
    public:
        using Player::Player;
        std::string role() const override;
        void tax() override;
        void block(Player &p) override;
    };
}