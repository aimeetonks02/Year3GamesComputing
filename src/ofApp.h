#pragma once

#include "graphicbuttons.h"


class GameObject {
public:
    GameObject();
    ~GameObject();

    int x, y;

    void drawObject();
    void updateObject();
};

class Player : public GameObject {
public:
    Player();
    ~Player();

    ofImage hand;
    int handSize = 300;
    int area = 0;

    void drawObject(int x,int y);
};

class Button : public GameObject {
public:
    Button();
    ~Button();

    int buttonSize = 300;
    int x = 0;
    int y = 0;

    void drawObject(int x, int y, int state);
};

class Page : public GameObject {
public:
    Page();
    ~Page();

    int height;
    int width;
    int difficulty = 1;
    int random;
    int alphaRandom;
    int answersDone = 0;
    bool correct = false;
    std::vector<string> symbols{};
    string dictionary [4][15][2] =
    {
        {
            {"of","---..-."},{"to","----"},{"in","..-."},{"no","-.---"},{"is","....."},{"we",".--."},
            {"be","-...."},{"as",".-..."},{"at",".--"},{"so","...---"},{"he","....."},{"by","-...-.--"},
            {"on","----."},{"up","..-.--."},{"go","--.---"}
        },

        {
            {"and",".--.-.."},{"the","-....."},{"dark","-...-.-.-.-"},{"yes","-.--...."},
            {"ours","---..-.-...."},{"find","..-...-.-.."},{"look",".-..-------.-"},{"plane",".--..-...--.."},
            {"theirs","-........-...."},{"are",".-.-.."},{"fire","..-....-.."},{"tank","-.--.-.-"},
            {"shot",".......----"},{"light",".-....--.....-"},{"ally",".-.-...-..-.--"}
        },

        {
            {"Britain","-....-...-.-..-."},{"enemy",".-..---.--"},{"America",".---..-...-.-..-"},
            {"separated",".....--..-.-..--.-.."},{"Germany","--...-.--.--.-.--"},
            {"family","..-..---...-..-.--"},{"Japan",".---.-.--..--."},{"soldier","...---.-..-......-."},
            {"sleep","....-.....--."},{"charge","-.-......-.-.--.."},{"through","-.....-.---..---....."},
            {"detect","-...-.-.-.-"},{"doctor","-..----.-.----.-."},{"Italy","..-.-.-..-.--"},
            {"attack",".---.--.-.-.-"}
        },

        {
            {"HOLD FAST","....---.-..-....-..-...-"},{"SAVE US","....-...-...-..."},
            {"INCOMING","..-.-.-.-----..-.--."},{"RETREAT",".-..-.-...--"},{"GRENADE","--..-..-..--..."},
            {"MAN DOWN","--.--.-..---.---."},{"MEDIC","--.-....-.-."},{"GET OUT","--..----..--"},
            {"TAKE COVER","-.--.-.-.-.---...-..-."},{"LEAVE IT",".-....-...-...-"},
            {"NEW ORDERS","-...-----.-.-....-...."},{"STAY ALERT","...-.--.--.-.-....-.-"},
            {"BOMBS ABOVE","-...------....--...---...-."},
            {"REINFORCEMENTS",".-....-...-.---.-.-.-..--.-.-..."},{"EVAC NEEDED","....-.--.-.-...-...-.."}
        }
    };
    string alphabet [2][26] =
        {{"a","b","c","d","e","f","g","h","i","j","k","l","m",
          "n","o","p","q","r","s","t","u","v","w","x","y","z",},
         {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
          "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."}};
    string text = "";
    string cleanText = "";
    string word = "";
    string encryption = "";
    string correctAnswers = "Correct: 0";

    ofSoundPlayer dot;
    ofSoundPlayer dash;
    ofSoundPlayer correctSound;
    ofSoundPlayer incorrectSound;

    void drawObject(int x, int y);
    void clearPage();
    void addSymbol(std::string symbol);
    void setSymbolString();
    string getSymbols();
    string setNote();
    void generateNote(int difficulty);
    string checkEncryption();
    string getCorrect();
    void incCorrect();
};

class cheatSheet : public GameObject {
public:
    cheatSheet();
    ~cheatSheet();

    int height;
    int width;
    int state = 1;

    ofImage cheatTab;
    ofImage sheet;

    ofSoundPlayer paperSound;

    void drawObject(int state);
    void changeState();
};

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofTrueTypeFont font;
    ofTrueTypeFont smallFont;

    Player player;
    Button button;
    Page page;
    cheatSheet cheat;
    graphicButtons dot;
    graphicButtons dash;
    graphicButtons reset;

    int keys[128];

};
