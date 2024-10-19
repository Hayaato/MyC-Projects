#include <iostream>
#include <chrono>
#include <string>
#include <windows.h>

using namespace std;

string RandomArr(string words[]){
    int i = rand() % 199; 
    return words[i];
}

void Game(string words[], int score, auto start_time) { 
    string user;
    string word = RandomArr(words);
    cout << "Repeat this word: " << word << endl;
    cin >> user;
    cout << endl;

    if(user == word) {
        cout << "Perfect!" << endl;
        score++;
        cout << "Your score is: " << score << endl;
    } else {
        cout << "Pum-Pum-Pum..." << endl;
        score--;
        cout << "Your score is: " << score << endl;
    }

    if(score == 10) {
        auto end_time = chrono::steady_clock::now();
        auto elapsed_sec = chrono::duration_cast<chrono::seconds>(end_time - start_time); 
        cout << "You win in: " << elapsed_sec.count() << " seconds!" << endl; 
    }
    else{
        Game(words,score,start_time);
    }
}

int main() {
    int score = 0; 
    srand(time(NULL));
    string words[200] = {
        "Apple", "Ball", "Cat", "Dog", "Eagle", "Forest", "Grape", "House", "Igloo", "Jungle",
        "Kite", "Lion", "Mouse", "Noble", "Ocean", "Piano", "Queen", "River", "Sun", "Tree",
        "Unicorn", "Vase", "Wolf", "Xylophone", "Yellow", "Zebra", "Artist", "Brave", "Circle", 
        "Dance", "Earth", "Frost", "Giant", "Heart", "Insect", "Joker", "Knight", "Ladder", 
        "Magic", "Nectar", "Object", "Paper", "Quest", "Radar", "Shield", "Temple", "Unity", 
        "Vision", "Water", "Xenon", "Youth", "Zone", "Anchor", "Bridge", "Climb", "Dream", 
        "Energy", "Flame", "Globe", "Honor", "Island", "Jewel", "King", "Light", "Mirror", 
        "Night", "Order", "Peace", "Quote", "Raven", "Star", "Tower", "Unity", "Vivid", 
        "Whale", "Xylo", "Young", "Zeal", "Archer", "Bloom", "Craft", "Drive", "Elder", 
        "Forge", "Ghost", "Haven", "Ivory", "Judge", "Knight", "Lunar", "Meadow", "Noble", 
        "Opal", "Pulse", "Quilt", "Rhino", "Sky", "Thorn", "Unity", "Vortex", "Wander", 
        "Xpress", "Yard", "Zephyr", "Abyss", "Blade", "Crown", "Dusk", "Echo", "Flare", 
        "Glade", "Hollow", "Iron", "Jade", "Karma", "Lust", "Moon", "Nest", "Oath", "Pillar", 
        "Quiver", "Ring", "Spark", "Throne", "Urge", "Vault", "Wind", "Xeno", "Year", 
        "Zenith", "Apex", "Bold", "Crest", "Dive", "Ember", "Flow", "Grasp", "Hunt", 
        "Ivory", "Jet", "Knock", "Loom", "Maze", "Noble", "Oasis", "Poise", "Quest", 
        "Rust", "Stream", "Tide", "Urge", "Vivid", "Whisk", "Xylo", "Yield", "Zealot", 
        "Ascend", "Blend", "Craft", "Dawn", "Elm", "Frost", "Grim", "Haze", "Icon", 
        "Jewel", "Keen", "Lush", "Mirth", "Nest", "Orchid", "Pulse", "Quake", "Rope", 
        "Spire", "Tome", "Unity", "Vault", "Wisp", "Xenon", "Yield", "Zone"
    };
    SetConsoleCP(65001); 
    SetConsoleOutputCP(65001); 
    cout << "Hello, it's Word Game!" << endl;
    cout << "You need to repeat the word to win!" << endl;
    auto start_time = chrono::steady_clock::now();
    Game(words, score, start_time);
    return 0;
}
