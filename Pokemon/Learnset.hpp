#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

// What needs to happen:
// Any number of moves attached to a level
// All TM moves
// Egg Moves

class Learnset{
    private:
    std::unordered_map<int, std::vector<const std::string_view>> level_up_moves;
    std::unordered_set<const std::string_view> tm_moves;
    std::unordered_set<const std::string_view> egg_moves;
    int insertlevel;
    public:
    Learnset();
    ~Learnset();
    std::vector<const std::string_view> getLevelMove(int level) const;
    bool canLearnTM(const std::string& move) const;
    bool canLearnEggMove(const std::string& move) const;
    void addLevelMove(int level, const std::string& move);
    void addTMMove(const std::string& move);
    void addEggMove(const std::string& move);
    void clearLevelMoves();
    void clearTMMoves();
    void clearEggMoves();
    [[nodiscard]] Learnset& operator<<(const int level);
    [[nodiscard]] Learnset& operator<<(const char egg);
    Learnset& operator<<(const std::string& move);
};