#include <iostream>
#include <chrono>
#include <string>
#include <windows.h>

using namespace std;

string RandomArr(string *words[]){
    return words[rand() %3][rand()%156];
}

void Game(string *wordArrays[], int score, std::chrono::time_point<std::chrono::steady_clock> start_time) { 
    string user;
    string words = RandomArr(wordArrays);
    //string word = RandomArr(wordArrays);
    cout << "Repeat this word: " << words << endl;
    cin >> user;
    cout << endl;

    if(user == words) {
        cout << "Perfect!" << endl;
        score++;
        cout << "Your score is: " << score << endl;
    } else {
        cout << "Pum-Pum-Pum..." << endl;
        score--;
        cout << "Your score is: " << score << endl;
    }

    if(score == 10) {
        std::chrono::time_point<std::chrono::steady_clock> end_time = chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_sec = chrono::duration_cast<chrono::seconds>(end_time - start_time);
        cout << "You win in: " << elapsed_sec.count() << " seconds!" << endl; 
    }
    else{
        Game(wordArrays,score,start_time);
    }
}

int main() {
    int score = 0; 
    srand(time(NULL));
    string words_light[181] = {
    "Ant", "Bat", "Cup", "Dog", "Ear", "Fish", "Gate", "Hat", "Ice", "Jam", 
    "Key", "Leg", "Map", "Net", "Owl", "Pen", "Quill", "Rat", "Sun", "Top", 
    "Up", "Van", "Web", "Xray", "Yarn", "Zoo", "Apple", "Book", "Car", 
    "Doll", "Egg", "Fan", "Goat", "Hen", "Ink", "Jet", "Kite", "Leaf", 
    "Mud", "Nail", "Orange", "Pup", "Quiz", "Ring", "Sock", "Toy", "Umbrella", 
    "Violin", "Water", "Xylophone", "Yard", "Zip", "Antler", "Bear", "Cat", "Duck", 
    "Eggplant", "Flag", "Goose", "Hat", "Iron", "Jelly", "Kangaroo", "Lamp", "Mug", 
    "Nose", "Octopus", "Pig", "Queen", "Rose", "Stone", "Truck", "Upward", 
    "Vine", "Window", "Yoyo", "Zebra", "Alligator", "Bus", "Chair", "Desk", 
    "Elephant", "Fan", "Glass", "Hut", "Inch", "Joker", "Knot", "Lemon", "Milk", 
    "Nest", "Oven", "Pencil", "Quiet", "Road", "Soup", "Table", "Umbrella", 
    "Vase", "Wheel", "Xray", "Yolk", "Zipper", "Apple", "Bread", "Cup", "Dog", 
    "Egg", "Fire", "Grape", "Hat", "Ice", "Jacket", "Key", "Lime", "Mouse", 
    "Nut", "Orchard", "Plane", "Queen", "Ring", "Shirt", "Tree", "Umbrella", 
    "Violet", "Watch", "Xray", "Yawn", "Zebra", "Ax", "Bat", "Cake", "Drum", 
    "Ear", "Fish", "Goat", "Hat", "Ink", "Jug", "Kite", "Leaf", "Moon", 
    "Nut", "Olive", "Pot", "Quiz", "Rat", "Sun", "Tap", "Umbrella", "Vase", 
    "Window", "Xray", "Yellow", "Zoo", "Arrow", "Bread", "Cup", "Dog", 
    "Egg", "Fan", "Grape", "Hat", "Ink", "Jug", "Key", "Leaf", "Map", 
    "Net", "Orange", "Pen", "Queen", "Rat", "Sock", "Top", "Umbrella", 
    "Vase", "Water", "Xylophone", "Yarn", "Zebra"
};
    string words_medium[182] = {
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
    string words_hard[156] = {
    "Algorithm", "Binary", "Cipher", "Dystopia", "Entropy", "Fractal", "Genome", 
    "Heuristic", "Isotope", "Jargon", "Kinetics", "Lagrange", "Matrix", "Neutron", 
    "Oscillation", "Paradox", "Quantum", "Relativity", "Singularity", "Topology", 
    "Uncertainty", "Vector", "Wavelength", "Xenobiotic", "Yield", "Zygote", "Anomaly", 
    "Blockchain", "Catalyst", "Dyson", "Enigma", "Fission", "Graviton", "Hypothesis", 
    "Inertia", "Joules", "Krypton", "Lattice", "Molecule", "Neoplasm", "Oxidation", 
    "Photon", "Quasar", "Resonance", "Schrodinger", "Thermodynamics", "Ultrasonic", 
    "Voltage", "Wormhole", "Xylem", "Yottabyte", "Zero", "Amplitude", "Brane", "Chaotic", 
    "Derivative", "Ecliptic", "Fusion", "Gluon", "Harmonics", "Invariance", "Joule", 
    "Kelvin", "Lemmas", "Meson", "Nucleus", "Oscillator", "Polarization", "Quorum", 
    "Relic", "Superposition", "Transistor", "Ubiquitous", "Vortex", "Wavelength", 
    "Xenomorph", "Y-axis", "Zephyr", "Aperture", "Boson", "Curvature", "Darkmatter", 
    "Epidemic", "Flux", "G-force", "Hyperbolic", "Inductor", "Jumpgate", "Kinematic", 
    "Lorentz", "Magnetar", "Nanobot", "Omicron", "Panspermia", "Quotient", "Radioactive", 
    "Singularity", "Tachyon", "Uranium", "Virtual", "Wavefunction", "Xerox", "Yield", 
    "Zeppelin", "Angular", "Boltzmann", "Critical", "Dipole", "Exoplanet", "Fermion", 
    "Gauss", "Heliosphere", "Interstellar", "Jetstream", "Klein", "Logarithm", "Mandelbrot", 
    "Nonlinear", "Orbit", "Plasma", "Quanta", "Resistor", "String", "Tensor", "Ultraviolet", 
    "Vacuum", "Wavelength", "X-axis", "Yttrium", "Zeno", "Asteroid", "Bitrate", "Cyclotron", 
    "Diode", "Enthalpy", "Fourier", "Gigahertz", "Higgs", "Infrared", "Jacobian", 
    "Kinematics", "Lorentzian", "Mass", "Nanotube", "Oblate", "Positron", "Quantum", 
    "Radiation", "Schwarzschild", "Turing", "Ultrasound", "Volt", "Wave", "Xenon", 
    "Ytterbium", "Zeptosecond"
};
    SetConsoleCP(65001); 
    SetConsoleOutputCP(65001); 
    cout << "Hello, it's Word Game!" << endl;
    cout << "You need to repeat the word to win!" << endl;
    std::chrono::time_point<std::chrono::steady_clock> start_time = chrono::steady_clock::now();
    string *wordArrays[] = {words_light, words_medium, words_hard};
    Game(wordArrays, score, start_time);
}
