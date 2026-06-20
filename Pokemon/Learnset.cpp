#include "Learnset.hpp"

// Function skeletons for Learnset; implementations intentionally left empty.
// TODO: Add real implementations when ready.

Learnset::Learnset() {
    level_up_moves = std::unordered_map<int, std::vector<const std::string_view>>();
    tm_moves = std::unordered_set<const std::string_view>();
    egg_moves = std::unordered_set<const std::string_view>();
    insertlevel = -1;
}

Learnset::~Learnset() {
}

std::vector<const std::string_view> Learnset::getLevelMove(int level) const {
	return level_up_moves.at(level);
}

bool Learnset::canLearnTM(const std::string& move) const {
    bool inlvl = false;
    return tm_moves.find(move) != tm_moves.end();

}

bool Learnset::canLearnEggMove(const std::string& move) const {
	return egg_moves.find(move) != egg_moves.end();
}

void Learnset::addLevelMove(int level, const std::string& move) {
    if(level_up_moves.find(level) == level_up_moves.end()){
        level_up_moves[level] = std::vector<const std::string_view>();
    }
    level_up_moves[level].push_back(std::string_view(move));
    addTMMove(move);
}

void Learnset::addTMMove(const std::string& move) {
    tm_moves.insert(std::string_view(move));
}

void Learnset::addEggMove(const std::string& move) {
    egg_moves.insert(std::string_view(move));
}

void Learnset::clearLevelMoves() {
    level_up_moves.clear();
}

void Learnset::clearTMMoves() {
    tm_moves.clear();
}

void Learnset::clearEggMoves() {
    egg_moves.clear();
}

[[nodiscard]] Learnset& Learnset::operator<<(const int level) {
    insertlevel = level;
    return *this;
}

[[nodiscard]] Learnset& Learnset::operator<<(const char egg) {
    if(egg == 'e')
        insertlevel = -2; // -2 is the magic number for "egg move"
    else
        insertlevel = -1; // -1 is the magic number for "TM move"
    return *this;
}

Learnset& Learnset::operator<<(const std::string& move) {
    if(insertlevel == -1) addTMMove(move);
    if(insertlevel == -2) addEggMove(move);
    else addLevelMove(insertlevel, move);
    insertlevel = -1; // reset to default after insertion
    return *this;
}