#include "ofApp.h"
#include <ofAppBaseWindow.h>

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("RobotoMono-VariableFont_wght.ttf", 48);
    smallFont.load("RobotoMono-VariableFont_wght.ttf", 28);
    ofSetBackgroundColor(77, 55, 26);
    player.hand.load("images/hand.png");
    cheat.cheatTab.load("images/cheatTab.png");
    cheat.sheet.load("images/cheatSheet.png");
    cheat.paperSound.load("paperMove.wav");
    page.dot.load("dot.wav");
    page.dash.load("dash.wav");
    page.correctSound.load("correct.wav");
    page.incorrectSound.load("incorrect.wav");
    dot.start();
    dash.start();
    reset.start();
    page.generateNote(1);
}

//--------------------------------------------------------------
void ofApp::update(){

    player.updateObject();
    button.updateObject();

}

//--------------------------------------------------------------
void ofApp::draw(){

    dot.draw(ofGetWidth()-800, ofGetHeight()/2, 1); //dot
    dash.draw(ofGetWidth()-400, ofGetHeight()/2, 2); //dash
    reset.draw(ofGetWidth()-600, ofGetHeight()-900, 3); //reset
    ofSetColor(219, 218, 202);//cream for the page
    page.drawObject(0,0);
    ofSetColor(60);//off-black for the text
    font.drawString("Encrypt:", 550-(font.stringWidth("Encrypt")/2), 175);
    font.drawString(page.getSymbols(),250,400);
    smallFont.drawString(page.getCorrect(), 220, 950);
    if (page.difficulty == 5){
        ofSetColor(255,0,0);//red text if using D-Day difficulty
    }
    font.drawString(page.setNote(),550-(font.stringWidth(page.setNote())/2),250);
    ofSetColor(255);//back to white
    smallFont.drawString(
                "To select difficulty, press 1(Alphabet), 2(Easy), 3(Medium), 4(Hard), or 5(D-Day)",
                         50,50);
    cheat.drawObject(cheat.state);//draws the cheat sheet either up or as a tab
    player.drawObject(ofGetMouseX(), ofGetMouseY());//draws the hand icon over the mouse
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'q'){
        OF_EXIT_APP(0);//quit button
    }
    else if (key == OF_KEY_TAB){
        page.addSymbol(".");
        page.dot.play();
        page.setSymbolString();
    }
    else if (key == OF_KEY_RETURN){
        page.addSymbol("-");
        page.dash.play();
        page.setSymbolString();
    }
    else if (key == ' '){
        page.checkEncryption();//check answer
        if (page.correct == true){
            page.correctSound.play();
            page.getSymbols();
            page.clearPage();
            page.generateNote(page.difficulty);
            page.correct = false;
        }
        else{
            page.incorrectSound.play();
            page.clearPage();
        }
    }
    else if(key == OF_KEY_BACKSPACE){
        page.clearPage();
        page.setSymbolString();
    }
    else if (key == OF_KEY_UP){
        cheat.state= 2;
        cheat.paperSound.play();
        cheat.drawObject(2);
    }
    else if (key == OF_KEY_DOWN){
        cheat.state = 1;
        cheat.paperSound.play();
        cheat.drawObject(1);
    }
    else if (key == OF_KEY_ALT){
        page.generateNote(page.difficulty);//generate new note - for development only
    }
    else if (key == '1'){
        page.difficulty = 1;
        page.generateNote(1);
    }
    else if (key == '2'){
        page.difficulty = 2;
        page.generateNote(2);
    }
    else if (key == '3'){
        page.difficulty = 3;
        page.generateNote(3);
    }
    else if (key == '4'){
        page.difficulty = 4;
        page.generateNote(4);
    }
    else if (key == '5'){
        page.difficulty = 5;
        page.generateNote(5);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}

//------------------new game code-------------------------------

GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::updateObject(){

}

void GameObject::drawObject(){

}

//-------------------player-----------------------------

Player::Player(){

}

Player::~Player(){

}

void Player::drawObject(int x,int y){
    hand.draw(x-150,y-150);
}

//-------------------buttons----------------------------

Button::Button(){

}

Button::~Button(){

}

void Button::drawObject(int x, int y, int state){

}

//-------------------pages-----------------------------

Page::Page(){

}

Page::~Page(){

}

void Page::drawObject(int x, int y){
    ofDrawRectangle(200,100,700,ofGetHeight()-200);
}

void Page::clearPage(){
    symbols.clear();
}

void Page::addSymbol(std::string symbol){
    int checkLength = symbols.size()+1;
    //checks the length of the code and adds a new line so it stays on the page
    if (checkLength %17 == 0){
        symbols.push_back("\n");
        symbols.push_back(symbol);
    }
    else{
        symbols.push_back(symbol);
    }

}

void Page::setSymbolString(){
    text = "";
    cleanText = "";
    //adds the symbol to the code
    for (string symbol:symbols) {
        text += symbol;
        if (symbol != "\n"){
            cleanText += symbol;
        }
    }
}

string Page::getSymbols(){
    return text;
}

string Page::setNote(){
    return word;
}

void Page::generateNote(int difficulty){
    alphaRandom = static_cast<int>(ofRandom(0,26));
    random = static_cast<int>(ofRandom(0,15));
    if (difficulty == 1){
        word = alphabet[0][alphaRandom];
    }
    else{
        word = dictionary[difficulty-2][random][0];
    }
}

string Page::checkEncryption(){
    if (difficulty == 1){
        encryption = alphabet[1][alphaRandom];
    }
    else{
        encryption = dictionary[difficulty-2][random][1];
    }

    if (encryption == cleanText){
        text = "CORRECT";
        correct = true;
        incCorrect();
    }
    else{
        text = "INCORRECT";
        cleanText = "";
    }

    return text;
}

string Page::getCorrect(){
    return correctAnswers;
}

void Page::incCorrect(){
    answersDone++;
    correctAnswers = "Correct: " + ofToString(answersDone);

}

//-------------------Cheat Sheet-----------------------

cheatSheet::cheatSheet(){

}

cheatSheet::~cheatSheet(){

}

void cheatSheet::drawObject(int state){
    if (state == 1){
        cheatTab.draw(ofGetWidth()-800, ofGetHeight()-100);
    }
    else if (state == 2){
        sheet.draw(ofGetWidth()-900, ofGetHeight()-600);
    }
}
